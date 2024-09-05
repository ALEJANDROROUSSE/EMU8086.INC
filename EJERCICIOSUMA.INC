include "emu8086.inc"

org 100h

.data

msg1 db "¡Hola soy rousse! Bienvenido a la realizacion de suma.", 10, 13, 0
msg2 db "Ingrese el primer valor: ", 0
msg3 db 10,13, "Ingrese el segundo valor: ", 0

num1 dw ?
resultado dw ?
DEFINE_SCAN_NUM
DEFINE_PRINT_STRING
DEFINE_PRINT_NUM
DEFINE_PRINT_NUM_UNS
DEFINE_PTHIS

.code

    MOV AX, @data
    MOV DS, AX
                    
    LEA SI, msg1
    CALL print_string
    
    LEA SI, msg2
    CALL print_string
    
    CALL scan_num
    MOV num1,CX
    
    LEA SI, msg3
    CALL print_string
    
    CALL scan_num
    MOV AX,CX
    
    ADD AX, num1  
    
    CALL pthis
    db 13,10, "La suma de los valores es: ", 0
    CALL print_num   

ret

END