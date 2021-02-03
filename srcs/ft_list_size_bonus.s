# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_size_bonus.s                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 09:55:13 by clorin            #+#    #+#              #
#    Updated: 2021/02/03 09:55:29 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
;
;	C Function prototype: int ft_list_size(t_list *begin_list)
;	input		:	rdi = *begin_list	
;	output		: 	rax						
;	used registers	:	rax
;
; **************************************************************************** #

	global 		ft_list_size

	section		.text

ft_list_size:
				xor		rax, rax			; rax = 0 counter

		_loop:
				cmp 	rdi, 0				;begin_list == NULL ?
				jz		_end				; yes => _end
				inc		rax					; counter ++
				mov		rdi,	[rdi + 8]	;->next
				jmp 	_loop				; loop

		_end:	
				ret 						; return (rax = rdx)
