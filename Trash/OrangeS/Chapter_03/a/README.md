
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
    nasm pmtest1.asm -o pmtest1.bin

使用软盘绝对扇区读写工具, 将引导扇区写入虚拟软盘的第一个扇区, 其中 conv=notrunc 参数阻止软盘映像文件 a.img 被截断 :
    dd if=pmtest1.bin of=a.img bs=512 count=1 conv=notrunc

需要使用 hexedit 更改 512 字节处的内容为 AA55

启动 bochs 并选择 6.Begin simulation
    bochs -f bochsrc

清理
    rm a.img bochsout.txt pmtest1.bin

# 进入保护模式的步骤

**准备 GDT**

**用 lgdt 加载 gdtr**

**打开 A20**

**置 cr0 的 PE 位**

**jmp 进入保护模式**
