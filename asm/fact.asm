    AREA FACT, CODE, READONLY

ENTRY
START
    MOV R0,#0x7
    MOV R1,R0

FACT1 SUBS R1,R1,#1
    CMP R1,#1
    BEQ STOP
    MUL R3,R0,R1
    MOV R0,R3
    BNE FACT1

STOP B STOP
    END