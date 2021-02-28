
	org	0x7c00				; 告诉编译器程序加载到 7c00 处

BaseOfStack	equ	0x7c00

Label_Start:

	mov	ax,	cs
	mov	ds,	ax				; 使段寄存器 DS 指向与 CS 相同的段
	mov	es,	ax				; 使段寄存器 ES 指向与 CS 相同的段
	mov	ss,	ax				; 使段寄存器 SS 指向与 CS 相同的段
	mov	sp,	BaseOfStack

;=======	clear screen

	mov	ax,	0600h			; int10 主功能号 AH=06h 实现按指定范围滚动窗口的功能, 也具备清屏功能
	mov	bx,	0700h			; 设置字体闪烁
	mov	cx,	0				; 滚动范围的左上角坐标为 (行 0, 列 0)
	mov	dx,	0184fh			; 滚动范围的右上角坐标为 (行 4f, 列 18)
	int	10h

;=======	set focus

	mov	ax,	0200h			; int10 主功能号 AH=02h 实现屏幕光标位置的设置功能
	mov	bx,	0000h			; 设置页号为 0
	mov	dx,	0000h			; 设置游标行号为 0, 列号为 0
	int	10h

;=======	display on screen : Start Booting......

	mov	ax,	1301h				; int10 主功能号 AH=13h 实现字符串的显示功能, AL=01h 设置光标位于字符串尾端
	mov	bx,	000Ch				; 页号为 0 (BH = 0), 黑底红字 (BL = 0Ch)
	mov	dx,	0000h				; 设置游标行号为 0, 列号为 0 
	mov	cx,	10					; CX = 字符串长度

	push	ax
	mov	ax,	ds
	mov	es,	ax
	pop	ax

	mov	bp,	StartBootMessage	; ES:BP = 字符串地址
	int	10h						; 10h 号中断

;=======	reset floppy

	xor	ah,	ah
	xor	dl,	dl
	int	13h						; int10 主功能号 AH=00h 实现重置磁盘驱动功能, 为下一次读写软盘做准备

	jmp	$

StartBootMessage:	db	"Start Boot"
; MsgLen: equ $-StartBootMessage

;=======	fill zero until whole sector

	times	510-($-$$)	db	0	; 使用 0 填充剩余空间, 使生成的二进制程序恰好为 512 字节
	dw		0xaa55				; 结束标志
