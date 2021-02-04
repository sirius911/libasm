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
		push	rbp
		mov		rbp,	rsp
		xor		rax,	rax			;rax = 0
		syscall						;call read
		cmp		rax,	0			; rax < 0 ?
		jl		_err 				; yes => error
		mov		rsp,	rbp
		pop 	rbp
		ret 						; ok

	_err:
		push	rbx
		mov		rbx,	rax			
		call 	__errno_location wrt ..plt
		neg		rbx
		mov		[rax],	rbx
		pop 	rbx
		mov		rax,	-1
		mov		rsp,	rbp
		pop 	rbp
		ret