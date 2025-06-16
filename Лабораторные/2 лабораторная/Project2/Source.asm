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

;X=87A3 Y=5322 Z=07F1 (��������� � ������ ���� �� ������)
;� ����� �������� ���������� ������ ����� X, Y, Z �� 3 ������� ������ (��������� X',Y',Z')
;��������� �=X'-Z'+Y', M>0 ������� � �/� 1 (R=M+5), M<=0 ������� � �/� 2 (R=-M)
;���� R>007D, �� ������� � ���1 (R/2), ����� ������� � ���2 (R or 17D1) {R ����� �� ������}

	xor eax, eax
	xor ebx, ebx
	mov ecx, 3		;�������
	mov esi, offset X

	shift_loop:
		mov ax, [esi]
		ror ax, 3
		push ax		;���������� ���������� � ����
		add esi, 2		;��������� �����
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
		cmp eax, 007Dh		;��������� R
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