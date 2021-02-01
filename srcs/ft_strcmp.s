; **************************************************************************** #
;                                                                              #
;                                                         :::      ::::::::    #
;    ft_strcmp.s                                        :+:      :+:    :+:    #
;                                                     +:+ +:+         +:+      #
;    By: clorin <clorin@42.fr>                      +#+  +:+       +#+         #
;                                                 +#+#+#+#+#+   +#+            #
;    Created: 2021/01/29 11:29:31 by clorin            #+#    #+#              #
;    Updated: 2021/01/29 11:31:15 by clorin           ###   ########.fr        #
;                                                                              #
;	---------------------------------------------------------------------------#
;
;	C Function prototype: int	ft_strcmp(const char *s1, const char *s2)
;	input		:	rdi = *s1		rsi = *s2	
;	output		: 	eax						
;	used registers	:	rax rdx rcx
;
; **************************************************************************** #

	global		ft_strcmp

	section		.text

ft_strcmp:
				xor		rax,	rax					; rax = 0
				xor		rdx,	rdx					; rdx = 0
				xor		rcx,	rcx					; rcx = 0

	_loop:		mov		al,		byte [rdi + rdx]	; al = s1[rdx]
				cmp		al,		byte [rsi + rdx]	; al - s2[rdx] ?
				jnz		_return						; s1* != s2*
				cmp		ah,		al					; s1* == 0 ?
				jz 		_end						; s1* == 0 ?
				inc		rdx;						; rdx++
				jmp		_loop						; loop

	_return:
				mov cl, byte [rsi + rdx]			; cl = s2*
				sub eax, ecx						; rax -= cl
				jmp _end

	_end:		ret