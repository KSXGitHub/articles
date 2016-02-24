
.model small

.stack 0x100

.data

	ask db 'Nhap mot chuoi: $'

	reply db 10, 13, 'Chuoi vua nhap: $',

	strbuf db 32 ; Do dai toi da cua chuoi la 32
	db ? ; So ki tu vua nhap se duoc luu o day
	str db 32 dup('$') ; Chuoi vua nhap se duoc luu o day

.code

	main proc

		; init
		mov AX, @data
		mov DS, AX

		; write(ask)
		lea DX, ask
		mov AH, 9
		int 0x21

		; strbuf = getstr()
		lea DX, strbuf
		mov AH, 10 ; ham nhap chuoi
		int 0x21

		; write(reply, str)
		mov AH, 9
		lea DX, reply
		int 0x21
		lea DX, str
		int 0x21

		; exit()
		mov AH, 0x4C
		int 0x21

	main endp

		end main
