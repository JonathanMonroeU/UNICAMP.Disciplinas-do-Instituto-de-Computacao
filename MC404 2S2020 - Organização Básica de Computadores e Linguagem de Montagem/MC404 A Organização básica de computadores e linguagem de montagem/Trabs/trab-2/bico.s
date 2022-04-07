# [BICO] Biblioteca de Controle
.globl set_motor
.globl set_handbreak
.globl read_sensors
.globl read_sensor_distance
.globl get_time
.globl get_position
.globl get_rotation

# Implemente aqui as funções da API_CAR.
# As funções devem checar os parametros e fazer as chamadas de sistema que serão
#   tratadas na camada SoCa

set_motor:
    li t5, 3 #debug

    li t0, -1
    blt a0, t0, erro1
    li t0, 2
    bge a0, t0, erro1
    li t0, -127
    blt a1, t0, erro1
    li t0, 128
    //bge a1, t0, erro1
    
    li a7, 10 #syscall set_motor
    ecall

    li t5,4 #debug

    j ret1

    erro1:
        li a0, -1

    ret1:
        
        ret

set_handbreak:
    li a7, 11 #syscall set_handbreak
    ecall
    ret

read_sensors:
    li a7, 12 #syscall set_handbreak
    ecall
    ret

read_sensor_distance:
    li a7, 13 #syscall set_handbreak
    ecall
    ret

get_position:
    li a7, 15 #syscall set_handbreak
    ecall
    ret

get_rotation:
    li a7, 16 #syscall set_handbreak
    ecall
    ret

get_time:
    li t5, 12 #debug
    li a7, 14 #syscall set_handbreak
    ecall
    ret
