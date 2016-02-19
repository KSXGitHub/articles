
title HIEU

.model small

.stack 100h

.data

	intro db 'Nhap hai so nguyen a, b trong khoang 0-9 (a >= b): '
	ask1 db 10, 13, ' * a = $'
	ask2 db 10, 13, ' * b = $'
	reply db 10, 13, '--> a - b = '
	num1 db ?
	_mid1 db ' - '
	num2 db ?
	_mid2 db ' = '
	result db ?
	_endreply db 24h

.code

	main proc

		; Khoi tao
		mov AX, @data
		mov DS, AX

		; write(intro, ask1)
		lea DX, intro
		mov AH, 9
		int 21h

		; num1 = getch()
		mov AH, 1
		int 21h
		mov num1, AL

		; write(ask2)
		lea DX, ask2
		mov AH, 9
		int 21h

		; num2 = getch()
		mov AH, 1
		int 21h
		mov num2, AL

		; result = num1 - num2 + '0'
		mov CL, num1
		sub CL, num2
		add CL, '0'
		mov result, CL

		; write(reply...)
		lea DX, reply
		mov AH, 9
		int 21h  
		
		; getch()
		mov AH, 1
		int 21h

		; exit()
		mov AH, 4Ch
		int 21h

	main endp

		end main
