
title TINH_TONG

.model small

.stack 100h

.data

	intro db 'Nhap hai so nguyen trong khoang 0-9 '
	ask1 db 10, 13, '  Nhap so thu 1: $'
	ask2 db 10, 13, '  Nhap so thu 2: $'
	reply db 10, 13, '=> Tong cua '
	num1 db ?
	_mid1 db ' va '
	num2 db ? 
	_mid2 db ' la: '
	sum db ?
	_endreply db 24h
	
.code

	main proc
		
		; Khoi tao
		mov AX, @data
		mov DS, AX
		
		; write(intro + ask1)
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
		
		; num2 = AL = getch()
		mov AH, 1  
		int 21h
		mov num2, AL
		
		; sum = num1 + AL - '0' // tuc la sum = num1 + num2 - '0'
		mov BL, num1     
		sub BL, '0'
		add BL, AL
		mov sum, BL     
		
		; write(reply + num1 + _mid1 + num2 + _mid2 + sum)  
		lea DX, reply
		mov AH, 9    
		int 21h   
		
		; getch() // tam dung cho ket qua
		mov AH, 1
		int 21h
		
		; exit()
		mov AH, 4Ch
		int 21h
		
	main endp
	
		end main