
	org 07c00h				; 告诉编译器程序加载到 7c00 处

	mov ax, cs
	mov ds, ax				; 使段寄存器 DS 指向与 CS 相同的段
	mov es,	ax				; 使段寄存器 ES 指向与 CS 相同的段

	call DispStr			; 调用显示字符串例程
	jmp	$					; 无限循环

DispStr:
	mov ax, BootMessage
	mov bp, ax				; ES:BP = 字符串地址
	mov cx, 16				; CX = 字符串长度
	mov ax, 01301h			; AH = 13,  AL = 01h
	mov bx, 000ch			; 页号为 0 (BH = 0), 黑底红字 (BL = 0Ch)
	mov dl, 0
	int 10h					; 10h 号中断
	ret

BootMessage: db "Hello， OS World!"

times 510-($-$$) db 0		; 使用 0 填充剩余空间, 使生成的二进制程序恰好为 512 字节
dw 0xaa55					; 结束标志
