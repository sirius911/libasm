# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 09:54:10 by clorin            #+#    #+#              #
#    Updated: 2021/02/03 09:54:26 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
;
;	C Function prototype: ssize_t read(int fd, void *buf, size_t count)
;	input		:	rdi = fd rsi = *buf rdx = count	
;	output		: 	rax						
;	used registers	:	rax
;
; **************************************************************************** #

extern __errno_location

	global	ft_read 

	section .text

ft_read:
		xor		rax,	rax			;rax = 0
		syscall						;call read
		cmp		rax,	0			; rax < 0 ?
		jl		_err 				; yes => error
		ret 						; ok

	_err:
		neg 	rax					; rax = -rax
		mov		rdi,	rax			; save errno 
		call	__errno_location	; return pointer to errno in rax
		mov		[rax],	rdi			; Value of errno in rax address
		mov		rax, -1				; return fail
		ret
