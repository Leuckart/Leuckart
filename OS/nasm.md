
# Intel 与 AT&T 汇编语言格式

X | Intel 汇编语言格式 (BootLoader) | AT&T 汇编语言格式 (Core)
:-: | :-: | :-:
书写格式 | 关键字为大写字母 | 关键字为小写字母 |
赋值方向 | Op Dst Src, 操作方向为从右向左 | Op Src Dst, 操作方向为从左向右 |
操作数前缀 | 使用寄存器和立即数无需额外添加前缀 | 使用寄存器必须在前面添加前缀 %; 使用立即数必须在前面添加前缀 $; 对于标识符变量可以直接引用而无需添加前缀; 如果添加标识符前缀 $, 则说明正在引用该变量的地址 |
跳转和调用指令 | 远跳转指令 JMP 与远调用指令 CALL 的目标地址都由段地址和段内偏移组成 (JMP/CALL FAR SECTION：OFFSET), 远返回指令 RET 无操作数 | 远跳转指令 ljmp 和远调用指令 lcall 的目标地址由段地址和段内偏移组成 (ljmp/lcall $section:$offset), 远返回指令 lret 无操作数 |
内存间接寻址技术 | Intel 使用 [] 来表示间接寻址, 格式为 section:\[base+index*scale+displacement\], 其中 scale 可取 1 2 4 8 值 (默认为 1), section 用于指定段寄存器 | AT&T 使用 () 来表示间接寻址, 格式为 section:displacement(base, index, scale) |
指令的后缀 | 使用内存操作数时应该对操作数的位宽加以限定, 借助修饰符 PTR 可以限定操作数的位宽 (如 BYTE PTR, WORD PTR, DWORD PTR) | AT&T 语法中大部分指令在访问数据时都需要以指令后缀指明操作数的位宽 (如 b, w, l, q); 跳转指令的地址标识符也可添加后缀以表示跳转方向, f 表示向前跳转, b 表示向后跳转 |

# NASM 汇编语言格式


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

挂载
    sudo mount a.img /media/ -t vfat -o loop

拷贝
    sudo cp loader.bin /media/

同步
    sync

卸载
    sudo umount /media

161:    mov     bp,     NoLoaderMessage
720:NoLoaderMessage:    db      "ERROR:No KERNEL Found"
