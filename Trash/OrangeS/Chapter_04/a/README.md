
# 创建虚拟软盘映像

输入命令 bximage

选择 1.Create new floppy or hard disk image

输入 fd

其余选项均为默认, 即可创建虚拟软盘映像 a.img


# 配置 bochsrc

romimage : 真实机器的 BIOS

vgaromimage : 真实机器的 VGA BIOS

floppya : 指定虚拟软盘映像文件


# 运行程序

进行编译, 得到 512 字节的 boot.bin :
    nasm boot.asm -o boot.bin

使用软盘绝对扇区读写工具, 将引导扇区写入虚拟软盘的第一个扇区, 其中 conv=notrunc 参数阻止软盘映像文件 a.img 被截断 :
    dd if=boot.bin of=a.img bs=512 count=1 conv=notrunc

启动 bochs 并选择 6.Begin simulation
    bochs -f bochsrc

清理
    rm a.img bochsout.txt boot.bin


# bochs 命令

设置断点 :
    b 0x7c00

继续执行 :
    c

下一步 :
    n
