# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 09:52:03 by clorin            #+#    #+#              #
#    Updated: 2021/02/03 09:52:48 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
;
;	C Function prototype: char		*ft_strcpy(char *dest, const char *src)
;	input		:	rdi = *dest		rsi = *src	
;	output		: 	rax						
;	used registers	:	rax rdx rcx
;
; **************************************************************************** #

	global 		ft_strcpy

	section 	.text

ft_strcpy:
				xor		rax,	rax							; rax = 0
				xor		rdx,	rdx							; rdx = 0

	_loop:		
				cmp		byte[rsi + rdx],	al				; src[rdx] = 0 ?
				jz		_end								; Yes -> _end
				mov		cl,					byte[rsi + rdx]	; cl = src[rdx]
				mov		byte[rdi + rdx],	cl 				; dest[rdx] = cl
				inc		rdx									; rdx++
				jmp		_loop								; loop
		
	_end:		
				mov		byte [rdi + rdx],	al				; dest[rdx] = 0
				mov		rax,	rdi							; prepare value of

				ret 										; return (dest)
