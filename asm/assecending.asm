	AREA ASSCENDING,CODE,READONLY
ENTRY
START
	MOV R8,#4
	LDR R2,=CVALUE
	LDR R3,=CVALUE

LOOP0
	LDR R1,[R2],#4
	STR R1,[R3],#4

	SUBS R8,R8,#1
	CMP R8,#0
	BNE LOOP0

START1 MOV R5,#4
	MOV R7,#0
	LDR R1,=DVALUE

LOOP LDR R2,[R1],#4
	LDR R3,[R1]
	CMP R2,R3
	BLT LOOP2
	STR R2,[R1],#-4
	STR R3,[R1]
	MOV R7,#1
	ADD R1,#4

LOOP2
	SUBS R5,R5,#1
	CMP R5,#0
	BNE LOOP

	CMP R7,#0
	BNE START1
	NOP 
	NOP 
	NOP
CVALUE
	DCD 0x44444444
	DCD 0x11111111
	DCD 0x33333333
	DCD 0x22222222
	AREA DATA1,DATA,READWRITE

DVALUE
	DCD 0x00000000
	END