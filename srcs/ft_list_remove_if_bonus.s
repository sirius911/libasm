# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_remove_if_bonus.s                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 10:15:28 by clorin            #+#    #+#              #
#    Updated: 2021/02/03 10:45:48 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; prototype : void	ft_list_remove_if(t_list **begin_list, void *data, int (*cmp)(), void (*free_f)(void *))
; input	:rdi = *begin_list rsi = *data rdx = *cmp rcx = *free_f
; output: r/a
; used registers : r8 - r10, r12 - r15
;
; **************************************************************************** #

extern	ft_list_size
extern	ft_strlen

section.data:
	%define ACTUEL_NODE	r12
	%define FUNC_CMP	r13
	%define BEGIN		r14
	%define NODE_NEXT 	r15
	%define DATA		r8
	%define FUNC_FREE	r9
	%define FIRST_NODE	r10

section.text:
	global ft_list_remove_if

ft_list_remove_if:
			push	r12
			push	r13
			push	r14
			push	r15

			jmp	_valid_input
	_main:
			mov rdi, [ACTUEL_NODE]
			mov rsi, DATA
			call FUNC_CMP						;  cmp(actuel->data,data)
			cmp rax, 0							; egal ?
			jnz	_next							; no => next
			mov NODE_NEXT, [ACTUEL_NODE + 8]
			cmp [BEGIN], ACTUEL_NODE			; begin elem ?
			je	_del_begin
			mov [FIRST_NODE + 8], NODE_NEXT		; first= actuel->next
			mov rdi, ACTUEL_NODE
			call FUNC_FREE						; free_f(actuel)

    _next:	mov FIRST_NODE, ACTUEL_NODE			; first=actuel
    		mov ACTUEL_NODE, [ACTUEL_NODE + 8]	; actuel=actuel->next
    		cmp ACTUEL_NODE, 0					; if !actuel => end
    		jz ret
			jmp	_main

	_del_begin:
			mov rdi, ACTUEL_NODE
			call FUNC_FREE						; free_f(actuel)
			mov [BEGIN], NODE_NEXT				; begin = actuel->next
			mov ACTUEL_NODE, NODE_NEXT			; actuel=actuel->next
			cmp NODE_NEXT, 0					; if !actuel => end
			jz 	ret
			jmp	_next

	_valid_input:
			cmp	rdi, 0
			jz	ret
			cmp	rsi, 0
			jz	ret
			cmp	rdx, 0
			jz	ret
			cmp	rcx, 0
			jz	ret
			
			mov	BEGIN, rdi						; load vars
			mov	ACTUEL_NODE, [BEGIN]
			mov	DATA, rsi
			mov	FUNC_CMP, rdx
			mov	FUNC_FREE, rcx
			mov	rdi, ACTUEL_NODE
			call	ft_list_size				; if size of list = 0
			cmp	rax, 0
			jz	ret 							; yes => end
			mov FIRST_NODE, ACTUEL_NODE			; first = actuel = *begin_list
			jmp		_main
		
	ret:		
			pop	r15
			pop	r14
			pop	r13
			pop	r12
			ret	
