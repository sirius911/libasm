; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_list_push_front_bonus                           :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: clorin <clorin@42.fr>                      +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2021/02/01 15:17:25 by clorin            #+#    #+#              #
;    Updated: 2021/02/01 15:17:30 by clorin           ###   ########.fr        #
;                                                                              #
;	---------------------------------------------------------------------------#
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
					xor		rax,		rax		; rax = 0
					push 	rdi					; save **begin_list
					push 	rsi 				; save *data
					mov		rdi,		16		; size t_list
					call	malloc				; call malloc
					cmp		rax,		0		; return NULL ?
					jz		_end				; yes -> _end
					pop 	qword[rax]			; restore *data in rax[0-7]
					pop 	rdi					; restore **begin_list
					mov		rdx,		[rdi]	; pointer begin_list->rdx
					mov		[rax + 8],	rdx		; ->next = rdx [8-15]
					mov		[rdi], 		rax		; new data at begin_list

		_end:	
				ret