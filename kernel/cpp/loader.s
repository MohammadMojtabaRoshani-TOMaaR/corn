#   kernel specefic hexdecimal
.set MAGIC, 0x1badb002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot 
     .long MAGIC
     .long FLAGS
     .long CHECKSUM


.section .text
.extern kernelMain
.global loader

loader:
    mov $kernel_stack , %esp
    #   begin: pass there data to kernelManin function in kernel.cpp
    push %eax
    push %ebx
    call kernelMain

#   inolder to not come out of infinit loop
_stop:
    cli
    hlt
    jmp _stop



.section .bss
#   make 2MB inolder to not overwrite on past ram data
.space 2*1024*1024

kernel_stack:
