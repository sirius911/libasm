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
    push rbp                                ; prologue
    mov  rbp, rsp
    push r12
    push r13
    push r14
    push r15

    cmp rdi, 0                              ; if begin_list == Null
    je ret                                  ; or (*cmp) == Null
    cmp rsi, 0                              ; => end
    je ret

    mov BEGIN, rdi								; *actuel_node = *begin
    
    mov ACTUEL_NODE, [BEGIN]
    mov 	rdi, ACTUEL_NODE
    call 	ft_list_size
    cmp 	rax, 1								; ft_list_size <=  1?
    jle		ret 								; end
    mov ACTUEL_NODE_next, [ACTUEL_NODE + 8]		; *actuel_node->next = begin->next
    mov FUNC, rsi

	while:								;while (actuel_node->next != NULL)
			mov rdi, [ACTUEL_NODE]
			mov rsi, [ACTUEL_NODE_next]
			call	FUNC 				;if ((*cmp)(actuel_node->data, actuel_node->next->data) > 0)
			cmp	al, 0
			jg 	swap 				; swap(actuel_node->data, actuel_node->next->data)
													;else
			mov ACTUEL_NODE, ACTUEL_NODE_next  		
			mov ACTUEL_NODE_next, [ACTUEL_NODE + 8] ;	actuel_node = actuel_node->next
end_while:	cmp ACTUEL_NODE_next, 0		; while (actuel_node->next)
			jz	ret
			jmp	while

	swap:
			mov rdi, [ACTUEL_NODE]
			mov rsi, [ACTUEL_NODE_next]
			mov [ACTUEL_NODE_next], rdi
			mov [ACTUEL_NODE], rsi
			mov ACTUEL_NODE, [BEGIN]			;	actuel_node = *begin_list
			mov ACTUEL_NODE_next, [ACTUEL_NODE + 8]
			jmp end_while

ret:
    pop r15
    pop r14
    pop r13
    pop r12
    leave       ;epilogue
    ret
