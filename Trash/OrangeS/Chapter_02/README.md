
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

反汇编 :
    u 0x7c00 0x7c1e

退出 :
    q


    sreg
    r

# bochs 备注

h|help - show list of debugger commands
h|help command - show short command description
-*- Debugger control -*-
    help, q|quit|exit, set, instrument, show, trace, trace-reg,
    trace-mem, u|disasm, ldsym, slist
-*- Execution control -*-
    c|cont|continue, s|step, p|n|next, modebp, vmexitbp
-*- Breakpoint management -*-
    vb|vbreak, lb|lbreak, pb|pbreak|b|break, sb, sba, blist,
    bpe, bpd, d|del|delete, watch, unwatch
-*- CPU and memory contents -*-
    x, xp, setpmem, writemem, crc, info,
    r|reg|regs|registers, fp|fpu, mmx, sse, sreg, dreg, creg,
    page, set, ptime, print-stack, ?|calc
-*- Working with bochs param tree -*-
    show "param", restore

b addr: 在对应地址设置断点。例：b 0x7c00

info break: 显示当前所以断点信息。例：info break

c: 继续下执行，直到遇到断点。例：c

s: 单步执行。例：s

n: 单步执行，遇到函数跳过。例：n

info cpu: 查看寄存器信息。例：info cpu

r: 查看寄存器信息。例：r

fp: 查看寄存器信息。例：fp

sreg: 查看寄存器信息。例：sreg

creg: 查看寄存器信息。例：creg

print-stack: 查看堆栈。例：print-stack

xp /nuf addr: 查看内存物理地址内容。例：xp /64bx 0x7c00

x /nuf addr: 查看线性地址内容。例：x /64bx 0x7c00

u start end: 反汇编一段内存。例：u 0x7c00 0x7c0d

trace-on: 反汇编执行的每一条指令。例：trace-on

trace-reg: 每执行一条指令就显示cpu信息。例：trace-reg
