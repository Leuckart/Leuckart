
# 运行程序

进行编译, 得到 512 字节的 boot.bin :
    nasm boot.asm -o boot.bin

使用软盘绝对扇区读写工具, 将 boot.bin 写入空白软盘的第一个扇区 :
    dd if=boot.bin of=/dev/sdc bs=512 count=1

重启计算机

将boot.bin进行反汇编 :
    ndisasm -o 0x7c00 boot.bin >> disboot.asm

清理 :
    rm boot.bin disboot.asm


# NASM 的注意事项

**在 NASM 中, 任何不被方括号 [] 括起来的标签或变量名都被看作地址, 访问标签中的内容必须使用 [].**

**$ 表示当前行被汇编后的地址, $$ 表示一个 section 的开始处被汇编后的地址, $-$$ 表示当前行与当前 section 开始处的相对距离.**
