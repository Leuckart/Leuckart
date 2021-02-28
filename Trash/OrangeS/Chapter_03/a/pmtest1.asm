; ==========================================
; pmtest1.asm
; 编译方法：nasm pmtest1.asm -o pmtest1.bin
; ==========================================

%include	"pm.inc"	; 常量, 宏, 以及一些说明


org	0100h
	jmp	LABEL_BEGIN


[SECTION .gdt]
; GDT 定义于 pm.inc, 大小为 8 字节
;									段基址			段界限				属性
LABEL_GDT:			Descriptor		0,			0,					0					; 空描述符
LABEL_DESC_CODE32:	Descriptor		0,			SegCode32Len - 1,	DA_C + DA_32		; 非一致代码段
LABEL_DESC_VIDEO:	Descriptor		0B8000h,	0ffffh,				DA_DRW				; 显存首地址


GdtLen		equ		$ - LABEL_GDT		; GDT 的长度
GdtPtr		dw		GdtLen - 1			; GDT 的界限
			dd		0					; GDT 的基地址

; GDT 选择子
SelectorCode32		equ		LABEL_DESC_CODE32	- LABEL_GDT
SelectorVideo		equ		LABEL_DESC_VIDEO	- LABEL_GDT
; END of [SECTION .gdt]


[SECTION .s16]
[BITS	16]				; 指明这是 16 位代码段
LABEL_BEGIN:
	mov	ax, cs
	mov	ds, ax			; 使段寄存器 DS 指向与 CS 相同的段
	mov	es, ax			; 使段寄存器 ES 指向与 CS 相同的段
	mov	ss, ax			; 使段寄存器 SS 指向与 CS 相同的段
	mov	sp, 0100h

	; 初始化 32 位代码段描述符
	xor	eax, eax
	mov	ax, cs
	shl	eax, 4
	add	eax, LABEL_SEG_CODE32				; 将 LABEL_SEG_CODE32 的物理地址赋给 eax
	mov	word [LABEL_DESC_CODE32 + 2], ax	; 初始化 LABEL_DESC_CODE32 的段基址
	shr	eax, 16
	mov	byte [LABEL_DESC_CODE32 + 4], al	; 初始化 LABEL_DESC_CODE32 的段基址
	mov	byte [LABEL_DESC_CODE32 + 7], ah	; 初始化 LABEL_DESC_CODE32 的段基址

	; 为加载 GDTR 作准备, 将 GDT 的物理地址填充到 GdtPtr 中
	xor	eax, eax
	mov	ax, ds
	shl	eax, 4
	add	eax, LABEL_GDT				; eax <- gdt 基地址
	mov	dword [GdtPtr + 2], eax		; [GdtPtr + 2] <- gdt 基地址

	lgdt [GdtPtr]					; 加载 GDTR

	cli								; 关中断

	; 为了访问所有内存, 打开地址线 A20
	in	al, 92h
	or	al, 00000010b
	out	92h, al

	; 将 cr0 的第 0 位 PE 置为 1, 准备进入保护模式
	mov	eax, cr0
	or	eax, 1
	mov	cr0, eax

	; 真正进入保护模式
	jmp		dword	SelectorCode32:0	; 执行这一句会把 SelectorCode32 装入 cs,
										; 并跳转到 Code32Selector:0  处
; END of [SECTION .s16]


[SECTION .s32]		; 32 位代码段. 由实模式跳入.
[BITS	32]

LABEL_SEG_CODE32:
	mov	ax, SelectorVideo
	mov	gs, ax						; 使 gs 为选择子 SelectorVideo, 指向显存描述符 DESC_VIDEO

	mov	edi, (80 * 11 + 79) * 2		; 屏幕第 11 行, 第 79 列。
	mov	ah, 0Ch						; 0000: 黑底    1100: 红字
	mov	al, 'P'
	mov	[gs:edi], ax

	jmp	$							; 无限循环

SegCode32Len	equ		$ - LABEL_SEG_CODE32
; END of [SECTION .s32]
