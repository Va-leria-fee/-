.686
.model flat,stdcall

.stack 100h

.data

	mass dw 1, 1, 5, 5, -3, -3
	result dw 0		;1 - треугольник, 0 - не треугольник

.code
ExitProcess PROTO STDCALL :DWORD
Start:

	;(x2-x1)*(y3-y1) - (y2-y1)*(x3-x1)
	
	finit
	xor eax,eax 
	
	fild word ptr [mass]
	fild word ptr [mass+4]
	fsub st(0),st(1)
	
	fild word ptr [mass+2]
	fild word ptr [mass+10]
	fsub st(0),st(1)

	fmul st(0),st(2)
	
	fild word ptr [mass+2]
	fild word ptr [mass+6]
	fsub st(0),st(1)
	
	fild word ptr [mass]
	fild word ptr [mass+8]
	fsub st(0),st(1)

	fmul st(0),st(2)

	fsub st(0), st(4)

	fist word ptr [result]

	mov ax, result 
	cmp eax, 0
	jne end1
	jmp  end2
	end1:
	mov result, 1
	end2:

exit:
Invoke ExitProcess,1
End Start