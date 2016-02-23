
title Binary Form

.model small

.stack 0x100

.data

	intro db 'Binary displayer for Little Endian CPUs', 10, 13, 'Press any key... $'
	reply db 10, 13, 'Bits: $'
	endl db 10, 13, 0x24
	key db ?

.code

	main proc

		; init(@data)
		mov AX, @data
		mov DS, AX

		; write(intro)
		lea DX, intro
		mov AH, 9
		int 0x21

		; key = getch()
		mov AH, 1
		int 0x21
		mov key, AL

		; write(reply)
		lea DX, reply
		mov AH, 9
		int 0x21

		; write(bin(key))
		mov AH, 2
		mov CL, 1000000b
		begin_loop:
		mov CH, key
		and CH, CL
		cmp CH, 0
		je write_zero
		mov DL, '1'
		jmp exec_write_char
		write_zero:
		mov DL, '0'
		exec_write_char:
		int 0x21
		cmp CL, 0
		je end_loop
		shr CL, 1
		jmp begin_loop
		end_loop:

		; newline()
		lea DX, endl
		mov AH, 9
		int 0x21

		; getch()
		mov AH, 1
		int 0x21

		; exit()
		mov AH, 0x4C
		int 0x21

	main endp

		end main
