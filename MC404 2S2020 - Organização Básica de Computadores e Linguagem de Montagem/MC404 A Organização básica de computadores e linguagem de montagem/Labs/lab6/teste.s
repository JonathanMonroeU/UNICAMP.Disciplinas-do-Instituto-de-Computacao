.globl _start

_start:
    li a0, 0
    li t5, 10
    li t3, '8'
    sb t3, 0(a0) 
    sb t5, 1(a0)

    li t1, 3
    fcvt.s.w f0, t1
    li t1, 5
    fcvt.s.w f1, t1

    fle.s t2, f1, f0

    li a0, 1 # file descriptor = 1 (stdout)
    li a1, 0#  buffer
    li a2, 2 # size
    li a7, 64 # syscall write (64)
    ecall

    li a0, 0 # exit code
    li a7, 93 # syscall exit
    ecall


