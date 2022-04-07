.org 0x000   
LOAD MQ,M(entrada)
MUL M(0x00C)
LOAD MQ
STOR M(0x00C)
RSH
STOR M(k)
LOAD M(0x00C)
DIV M(k)
LOAD MQ
ADD M(k)
RSH
STOR M(k)
LOAD M(iter)
SUB M(um)
STOR M(iter)
JUMP+ M(0x003,0:19)
LOAD M(k)
JUMP M(0x400,0:19)


.org 0x00A
iter:
.word 0000000009
um:
.word 0000000001
.word 0000000010 
k:
.word 0000000000
y_sobre_k:
.word 0000000000

.org 0x110
entrada: