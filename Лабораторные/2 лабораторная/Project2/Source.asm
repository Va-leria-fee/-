.686
.model flat,stdcall

.stack 100h

.data

	X dw 87A3h
	Y dw 5322h
	Z dw 0
	R dd 0

.code
ExitProcess PROTO STDCALL :DWORD

Start:

;X=87A3 Y=5322 Z=07F1 (размещены в памяти один за другим)
;В цикле сдвинуть циклически каждое число X, Y, Z на 3 разряда вправо (результат X',Y',Z')
;Вычислить М=X'-Z'+Y', M>0 переход к п/п 1 (R=M+5), M<=0 переход к п/п 2 (R=-M)
;Если R>007D, то переход к АДР1 (R/2), иначе переход к АДР2 (R or 17D1) {R число со знаком}

	xor eax, eax
	xor ebx, ebx
	mov ecx, 3		;счётчик
	mov esi, offset X

	shift_loop:
		mov ax, [esi]
		ror ax, 3
		push ax		;сохранение результата в стек
		add esi, 2		;следующее слово
		loop shift_loop

	mov ax, [esp+4]	;X'-Z'+Y'
	add ax, [esp+2]
	mov bx, [esp]

	cmp eax, ebx
	jg more
	jle less

	more:		; M>0
		sub ax, [esp]
		add ax, 5
		jmp check

	less:		; M<=0
		mov bx, ax
		mov ax, [esp]
		sub ax, bx

	check:
		cmp eax, 007Dh		;сравнение R
		jg addr1
		call pr2
		jmp result

	addr1:
		call pr1
		jmp result		

	pr1 proc		;R>007D
		shr ax, 1
		ret
	pr1 endp

	pr2 proc		;R<=007D
		or eax, 17D1h
		ret
	pr2 endp

	result:
		mov R, eax

exit:
Invoke ExitProcess,1
End Start