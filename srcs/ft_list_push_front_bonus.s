# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_push_front_bonus.s                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 09:55:40 by clorin            #+#    #+#              #
#    Updated: 2021/02/03 09:55:56 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
;
;	C Function prototype: void ft_list_push_front(t_list **begin_list, void *data)
;	input		:	rdi = **begin_list	rsi = *data
;	output		: 							
;	used registers	:	rax, rdx
;
; **************************************************************************** #

extern malloc

	global 		ft_list_push_front

	section		.text

ft_list_push_front:
					push 	rsp				
					xor		rax,		rax		; rax = 0
					push 	rdi					; save **begin_list
					push 	rsi 				; save *data
					mov		rdi,		16		; size t_list
					call	malloc wrt ..plt	; call malloc
					cmp		rax,		0		; return NULL ?
					jz		_end				; yes -> _end
					pop 	qword[rax]			; restore *data in rax[0-8]
					pop 	rdi					; restore **begin_list
					mov		rdx,		[rdi]	; pointer begin_list->rdx
					mov		[rax + 8],	rdx		; ->next = rdx [8-15]
					mov		[rdi], 		rax		; new data at begin_list

			_end:	
					pop 	rsp
					ret
