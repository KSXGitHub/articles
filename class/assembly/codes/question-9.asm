
title 3 Characters

.model small

.stack 100h

.data

	ask db 'Nhap 3 ky tu: $'
	CLRF_1 db 10, 13
	ch1 db ?
	CLRF_2 db 10, 13
	ch2 db ?
	CLRF_3 db 10, 13
	ch3 db ?       
	CLRF_4 db 10, 13
	_end db 24h

.code

	main proc

		; Khoi tao
		mov AX, @data
		mov DS, AX

		; write(ask)
		lea DX, ask
		mov AH, 9
		int 21h

		; [ch1, ch2, ch3] = [getch(), getch(), getch()]
		mov AH, 1
		int 21h
		mov ch1, AL
		int 21h
		mov ch2, AL
		int 21h
		mov ch3, AL

		; write(CLRF_1...)
		lea DX, CLRF_1
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
