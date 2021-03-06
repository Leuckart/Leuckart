
org  07c00h			; Boot 状态, Bios 将把 Boot Sector 加载到 0:7C00 处并开始执行

;================================================================================================
BaseOfStack				equ		07c00h		; 堆栈基地址(栈底, 从这个位置向低地址生长)

BaseOfLoader			equ		09000h		; LOADER.BIN 被加载到的位置 ----  段地址
OffsetOfLoader			equ		0100h		; LOADER.BIN 被加载到的位置 ---- 偏移地址
RootDirSectors			equ		14			; 根目录占用空间
SectorNoOfRootDirectory	equ		19			; Root Directory 的第一个扇区号
;================================================================================================

	jmp short LABEL_START					; Start to boot.
	nop										; 这个 nop 不可少

	; 下面是 FAT12 磁盘的头
	BS_OEMName		DB		'ForrestY'		; OEM String, 必须 8 个字节
	BPB_BytsPerSec	DW		512				; 每扇区字节数
	BPB_SecPerClus	DB		1				; 每簇多少扇区
	BPB_RsvdSecCnt	DW		1				; Boot 记录占用多少扇区
	BPB_NumFATs		DB		2				; 共有多少 FAT 表
	BPB_RootEntCnt	DW		224				; 根目录文件数最大值
	BPB_TotSec16	DW		2880			; 逻辑扇区总数
	BPB_Media		DB		0xF0			; 媒体描述符
	BPB_FATSz16		DW		9				; 每FAT扇区数
	BPB_SecPerTrk	DW		18				; 每磁道扇区数
	BPB_NumHeads	DW		2				; 磁头数(面数)
	BPB_HiddSec		DD		0				; 隐藏扇区数
	BPB_TotSec32	DD		0				; wTotalSectorCount为0时这个值记录扇区数
	BS_DrvNum		DB		0				; 中断 13 的驱动器号
	BS_Reserved1	DB		0				; 未使用
	BS_BootSig		DB		29h				; 扩展引导标记 (29h)
	BS_VolID		DD		0				; 卷序列号
	BS_VolLab		DB		'OrangeS0.02'	; 卷标, 必须 11 个字节
	BS_FileSysType	DB		'FAT12   '		; 文件系统类型, 必须 8个字节  


LABEL_START:
	mov	ax, cs
	mov	ds, ax								; 使段寄存器 DS 指向与 CS 相同的段
	mov	es, ax								; 使段寄存器 ES 指向与 CS 相同的段
	mov	ss, ax								; 使段寄存器 SS 指向与 CS 相同的段
	mov	sp, BaseOfStack

	xor	ah, ah
	xor	dl, dl								; 软驱复位
	int	13h


; 下面在 A 盘的根目录寻找 LOADER.BIN
; 遍历根目录区所有的扇区, 将每个扇区加载入内存, 然后从中寻找文件名为 loader.bin 的条目
	mov	word [wSectorNo], SectorNoOfRootDirectory

LABEL_SEARCH_IN_ROOT_DIR_BEGIN:
	cmp	word [wRootDirSizeForLoop], 0		; 判断根目录区是不是已经读完
	jz	LABEL_NO_LOADERBIN					; 如果读完表示没有找到 LOADER.BIN
	dec	word [wRootDirSizeForLoop]
	mov	ax, BaseOfLoader
	mov	es, ax								; es <- BaseOfLoader
	mov	bx, OffsetOfLoader					; bx <- OffsetOfLoader
	mov	ax, [wSectorNo]						; ax <- Root Directory 中的某 Sector 号
	mov	cl, 1
	call ReadSector

	mov	si, LoaderFileName					; ds:si -> "LOADER  BIN"
	mov	di, OffsetOfLoader					; es:di -> BaseOfLoader:0100
	cld
	mov	dx, 10h

LABEL_SEARCH_FOR_LOADERBIN:
	cmp	dx, 0								; 循环次数控制,
	jz	LABEL_GOTO_NEXT_SECTOR_IN_ROOT_DIR	; 如果已经读完了一个 Sector,
	dec	dx									; 就跳到下一个 Sector
	mov	cx, 11

LABEL_CMP_FILENAME:
	cmp	cx, 0
	jz	LABEL_FILENAME_FOUND				; 如果比较了 11 个字符都相等, 表示找到
	dec	cx
	lodsb									; ds:si -> al
	cmp	al, byte [es:di]
	jz	LABEL_GO_ON
	jmp	LABEL_DIFFERENT						; 只要发现不一样的字符就表明本 DirectoryEntry
											; 不是我们要找的 LOADER.BIN
LABEL_GO_ON:
	inc	di
	jmp	LABEL_CMP_FILENAME					; 继续循环

LABEL_DIFFERENT:
	and	di, 0FFE0h							; else `. di &= E0 为了让它指向本条目开头
	add	di, 20h								;       |
	mov	si, LoaderFileName					;       | di += 20h  下一个目录条目
	jmp	LABEL_SEARCH_FOR_LOADERBIN			;    /

LABEL_GOTO_NEXT_SECTOR_IN_ROOT_DIR:
	add	word [wSectorNo], 1
	jmp	LABEL_SEARCH_IN_ROOT_DIR_BEGIN

LABEL_NO_LOADERBIN:
	mov	dh, 2								; "No LOADER."
	call DispStr							; 显示字符串

	jmp	$									; 没有找到 LOADER.BIN, 死循环在这里

LABEL_FILENAME_FOUND:						; 找到 LOADER.BIN 后便来到这里继续
	jmp	$									; 代码暂时停在这里



;============================================================================
;变量
wRootDirSizeForLoop	dw	RootDirSectors		; Root Directory 占用的扇区数，
											; 在循环中会递减至零
wSectorNo			dw	0					; 要读取的扇区号
bOdd				db	0					; 奇数还是偶数

;字符串
LoaderFileName	db		"LOADER  BIN",	0	; LOADER.BIN 之文件名

; 为简化代码, 下面每个字符串的长度均为 MessageLength
MessageLength	equ		9
BootMessage:	db		"Booting  "			; 9字节, 不够则用空格补齐. 序号 0
Message1		db		"Ready.   "			; 9字节, 不够则用空格补齐. 序号 1
Message2		db		"No LOADER"			; 9字节, 不够则用空格补齐. 序号 2
;============================================================================


;----------------------------------------------------------------------------
; 函数名: DispStr
;----------------------------------------------------------------------------
; 作用:
;	显示一个字符串, 函数开始时 dh 中应该是字符串序号(0-based)
DispStr:
	mov	ax, MessageLength
	mul	dh
	add	ax, BootMessage
	mov	bp, ax				; ES:BP = 字符串地址
	mov	ax, ds
	mov	es, ax
	mov	cx, MessageLength	; CX = 字符串长度
	mov	ax, 01301h			; AH = 13,  AL = 01h
	mov	bx, 0007h			; 页号为0(BH = 0) 黑底白字(BL = 07h)
	mov	dl, 0
	int	10h					; 10h 号中断
	ret


;----------------------------------------------------------------------------
; 函数名: ReadSector
;----------------------------------------------------------------------------
; 作用:
;	从第 ax 个 Sector 开始, 将 cl 个 Sector 读入 es:bx 中
ReadSector:
	; -----------------------------------------------------------------------
	; 怎样由扇区号求扇区在磁盘中的位置 (扇区号 -> 柱面号, 起始扇区, 磁头号)
	; -----------------------------------------------------------------------
	; 设扇区号为 x
	;                           ┌ 柱面号 = y >> 1
	;       x           ┌ 商 y ┤
	; -------------- => ┤      └ 磁头号 = y & 1
	;  每磁道扇区数     │
	;                   └ 余 z => 起始扇区号 = z + 1
	push	bp
	mov	bp, sp
	sub	esp, 2				; 辟出两个字节的堆栈区域保存要读的扇区数: byte [bp-2]

	mov	byte [bp-2], cl
	push	bx				; 保存 bx
	mov	bl, [BPB_SecPerTrk]	; bl: 除数
	div	bl					; y 在 al 中, z 在 ah 中
	inc	ah					; z ++
	mov	cl, ah				; cl <- 起始扇区号
	mov	dh, al				; dh <- y
	shr	al, 1				; y >> 1 (y/BPB_NumHeads)
	mov	ch, al				; ch <- 柱面号
	and	dh, 1				; dh & 1 = 磁头号
	pop	bx					; 恢复 bx

	; 至此, "柱面号, 起始扇区, 磁头号" 全部得到
	mov	dl, [BS_DrvNum]		; 驱动器号 (0 表示 A 盘)

.GoOnReading:
	mov	ah, 2				; 读
	mov	al, byte [bp-2]		; 读 al 个扇区
	int	13h
	jc	.GoOnReading		; 如果读取错误 CF 会被置为 1, 
							; 这时就不停地读, 直到正确为止
	add	esp, 2
	pop	bp
	ret

times 	510-($-$$)	db	0	; 填充剩下的空间，使生成的二进制代码恰好为512字节
dw 	0xaa55					; 结束标志
