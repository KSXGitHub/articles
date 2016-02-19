
title LOWERCASE

.model small

.stack 100h

.data

	ask db 'Nhap mot ky tu hoa: ', 24h ; 24h chinh la ky tu '$'
	
	reply db 10, 13, 'Ky tu thuong: '
	
	result db ?
	
	endreply db 24h
	
.code

	main proc
		
		; KHOI TAO
		mov AX, @data
		mov DS, AX
		
		; write(ask)
		lea DX, ask
		mov AH, 9
		int 21h
		
		; result = getch() // nhap mot ky tu
		mov AH, 1
		int 21h
		mov result, AL
		
		; result += 32 // doi hoa thanh thuong
		add result, 32
		
		; write(reply + result)
		lea DX, reply
		mov AH, 9
		int 21h     
		
		; getch() // dung lai xem ket qua (nhan phim bat ki de ket thuc)
		mov AH, 1
		int 21h
		
		; exit()
		mov AH, 4Ch
		int 21h
		
	main endp
	
		end main
