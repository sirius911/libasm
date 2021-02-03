# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 09:50:41 by clorin            #+#    #+#              #
#    Updated: 2021/02/03 09:53:29 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
;
;	C Function prototype: size_t ft_strlen(char *s)
;	input		:	rdi = s	
;	output		: 	rax						
;	used registers	:	rax, rdx
;
; **************************************************************************** #

	global 		ft_strlen

	section		.text

ft_strlen:
				xor		rax, rax			; rax = 0
				xor		rdx, rdx			; rdx = 0

		_loop:
				mov		al, [rdi + rdx]		; s[rdx] -> al
				cmp		al, 0 				; al = 0
				jz		_end				; yes- >jump _end
				inc		rdx					; rdx++;
				jmp		_loop				; loop

		_end	mov 	rax, rdx			; prepare value of
				ret 						; return (rax = rdx)
