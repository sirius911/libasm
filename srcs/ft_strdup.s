# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 09:53:45 by clorin            #+#    #+#              #
#    Updated: 2021/02/03 09:54:00 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
;
;	C Function prototype: char	*ft_strdup(const char *s)
;	input		:	rdi = *s	
;	output		: 	rax						
;	used registers	:	rax
;
; **************************************************************************** #

extern malloc
extern ft_strlen
extern ft_strcpy

	global		ft_strdup

	section		.text

ft_strdup:
			push	rdi					; save rdi (*s)
			call	ft_strlen			; rax = ft_strlen(*s)
			mov		rdi,		rax		; rdi = len(s*)
			call	malloc				; malloc(rdi) -> rax
			cmp		rax,		0		; rax = 0 ?
			je		_end				; yes => _end
			mov		rdi, 		rax		; rax -> rdi
			pop 	rsi 				; old rdi -> rsi
			call 	ft_strcpy			; strcpy(rdi, rsi)->rax
	_end:	ret
				
