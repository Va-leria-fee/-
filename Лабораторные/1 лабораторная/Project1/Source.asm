.686
.model flat,stdcall
.stack 100h

.data

	X dw 100
	Y dw 21
	Z dw 4

.code
ExitProcess PROTO STDCALL :DWORD

Start:

;M = (X*3+Y) OR Z

	XOR EAX,EAX ;обнуление регистров
	XOR EBX,EBX

	ROR X,3 ;циклический сдвиг вправо
	ROR Y,3
	ROR Z,3

	MOV AX,X ;пересылка
	MOV BX,3
	MUL BX ;умножение
	ADD AX,Y ;сложение
	OR AX,Z

exit:
Invoke ExitProcess,1
End Start
