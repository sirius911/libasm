# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_sort_bonus.s                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 20:44:48 by clorin            #+#    #+#              #
#    Updated: 2021/02/02 20:44:54 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

;
;	C Function prototype: void ft_list_sort(t_list **begin_list, int (*cmp)())
;	input		:	rdi = *begin_list	rsi = *cmp()
;	output		: 							
;	used registers	:	rax, r12, r13, r14, r15, 
;
; **************************************************************************** #



extern		ft_list_size

section.data:
    %define ACTUEL_NODE r12
    %define FUNC r13
    %define BEGIN r14
    %define ACTUEL_NODE_next r15

section.text:
    global ft_list_sort

ft_list_sort:
    push r12
    push r13
    push r14
    push r15

    cmp rdi, 0
    je ret
    cmp rsi, 0
    je ret

    mov BEGIN, rdi								; *actuel_node = *begin
    
    mov ACTUEL_NODE, [BEGIN]
    mov 	rdi, ACTUEL_NODE
    call 	ft_list_size
    cmp 	rax, 1								; ft_list_size <=  1?
    jle		ret 								; end
    ; *actuel_node->next = begin->next
    mov ACTUEL_NODE_next, [ACTUEL_NODE + 8]
    mov FUNC, rsi

;while (actuel_node->next != NULL)
	while:
			;if ((*cmp)(actuel_node->data, actuel_node->next->data) > 0)
			mov rdi, [ACTUEL_NODE]
			mov rsi, [ACTUEL_NODE_next]
			call FUNC
			cmp	 al, 0
			;	swap(actuel_node->data, actuel_node->next->data)
			jns 	swap

			;	actuel_node = *begin_list
			;else
			;	actuel_node = actuel_node->next
			mov ACTUEL_NODE, ACTUEL_NODE_next
			mov ACTUEL_NODE_next, [ACTUEL_NODE + 8]
end_while:	cmp ACTUEL_NODE_next, 0
			jz	ret
			jmp	while

	swap:
			mov rdi, [ACTUEL_NODE]
			mov rsi, [ACTUEL_NODE_next]
			mov [ACTUEL_NODE_next], rdi
			mov [ACTUEL_NODE], rsi
			mov ACTUEL_NODE, [BEGIN]
			mov ACTUEL_NODE_next, [ACTUEL_NODE + 8]
			jmp end_while

ret:
    pop r15
    pop r14
    pop r13
    pop r12
    ret









# ft_list_sort:
# 				push	rbx						; save rbx
# 				push	r12						; save r12
# 				cmp		rdi,		0			; begin == NULL ?
# 				jz		_end
# 				mov		r12,		[rdi]		; r12 = *begin

# 				cmp		rsi,		0			; cmp == NULL ?
# 				jz		_return

# 	_main:
# 				cmp		qword [rdi], 0			; *begin == NULL ?
# 				jz		_return
# 				mov		rcx,		[rdi]
# 				mov		rbx,		[rcx + 8]	; current = *begin->next
# 				cmp		rbx,		0			; current == NULL?
# 				jz		_next
				
# 	_cmp:		push	rdi						; save rdi
# 				push	rsi						; save rsi
# 				mov		rax,		rsi
# 				mov		rcx,		[rdi]
# 				mov		rdi,		[rcx]		; rdi = (*begin)->data
# 				mov		rsi,		[rbx]		; rsi = current->data
# 				call	rax						; (*cmp)(rdi,rsi)
# 				pop		rsi 					; restore rsi
# 				pop		rdi						; restore rdi
# 				cmp		rax,		0			; cmp > 0 ?
# 				jg		_swap					; yes => swap

# 				mov		rcx, 		[rbx + 8]	; no => next
# 				mov		rbx,		rcx			; current = current.next

# 				cmp		rbx,		0
# 				jz		_next
# 				jmp		_cmp


# 	_next:		mov		rcx,		[rdi]		; |
# 				mov		rbx,		[rcx + 8]	; | *begin = (*begin)->next
# 				mov		[rdi],		rbx			; |
# 				jmp		_main

# 	_swap:		
# 				mov		r8,			[rdi]
# 				mov		rcx,		[r8]		; rcx = (*begin)->data
# 				mov		rax,		[rbx]		; rax = current->data
# 				mov		[r8],		rax			; *begin->data = current->data
# 				mov		[rbx],		rcx			; current->data = *begin->data
# 				mov		rcx,		[rbx + 8]
# 				mov		rbx,		rcx			; current= current.next
# 				cmp		rbx,		0
# 				jz		_next
# 				jmp 	_cmp

# _return:		mov		[rdi],		r12			;a enlever si on inverse le debut

# _end:	
# 				pop 	r12
# 				pop		rbx
# 				ret
