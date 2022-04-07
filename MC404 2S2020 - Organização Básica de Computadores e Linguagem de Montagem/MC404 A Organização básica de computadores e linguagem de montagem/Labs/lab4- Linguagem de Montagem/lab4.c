//lab 04

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



------------------------------------------------------

.org 0x000   
LOAD M(0x3FD)
STOR M(tam)
LOAD M(0x3FF)
ADD M(i)
STA M(0x003,8:19)
JUMP M(0x003,0:19)
LOAD MQ, M(0x000)
LOAD M(0x3FE)
ADD M(i)
STA M(0x005,8:19)
MUL M(0x000)
LOAD MQ
ADD M(total)
STOR M(total)
LOAD M(i)
ADD M(um)
STOR M(i)
LOAD M(tam)
SUB M(i)
SUB M(um)
JUMP+ M(0x001,0:19)
LOAD M(total)
JUMP M(0x400,0:19)



.org 0x015
tam:
.org 0x016
i:
.org 0x017
um:
.word 0000000001
total:
