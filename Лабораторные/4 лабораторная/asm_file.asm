PUBLIC func1		; позволяет сделать функцию "func1" в этом файле доступной для вызова в С или С++
EXTRN c_func:PROC	; добавление внешней функции из C или С++

.data
	z real8 0.0
	n dd 0
	x dd 0
	k dd 0
	a real8 0.0

.code 

	func1 PROC

		sub rsp, 80
		mov n, ecx
		mov x, edx
		xor eax, eax
		xor ebx, ebx
		add n, 1
		mov ecx, n

		finit

		shift_loop:
			
			mov R11, rcx
			mov ecx, x
			mov edx, k
			call c_func
			movsd qword ptr [a], xmm0
			mov rcx, R11
				
			movsd xmm1, qword ptr [z]
			addsd xmm1, qword ptr [a]
			movsd qword ptr [z], xmm1
			inc k
		loop shift_loop

		movsd xmm0, qword ptr [z]
		add rsp, 80
		ret
	func1 ENDP

END