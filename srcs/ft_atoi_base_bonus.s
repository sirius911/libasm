# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_atoi_base_bonus.s                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 14:34:06 by clorin            #+#    #+#              #
#    Updated: 2021/02/03 14:34:13 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

; prototype : int	ft_atoi_base(char *str, char *base);
; input : rdi = *str	rsi = *base
; output:   rax
; used registers : r8-r12, rdx, rcx, rbx
; **************************************************************************** #

extern ft_strlen

section     	.data
	whitespaces:    db 9, 10, 11, 12, 13, 32   	; whitespaces
	%define STR 	r8 							; *str
	%define BASE  	r9 							; *base
	%define LEN 	r10 						; size of base
	%define SIGN 	r11							; sign of result
	%define RESULT	rax							; result to return
	%define i 		rbx							; index
	%define j 		rdx							; index
	%define CHAR    r12b						; char 8 bytes

	section		.text
			global ft_atoi_base

ft_atoi_base:
				push 		rbx 				; save pile
				push		r12 				; save pile
				mov STR, 	rdi					; save str
				mov BASE,	rsi 				; save base
				xor r12,	r12 				; char = 0
				cmp STR, 	0
				je 			error
				jmp			valid_base
	_continue:
				xor i,		i 					; i = 0
				xor j,		j 					; j = 0

	_loop_whitspace:
				mov al, 	byte [STR + i]		; str[i] -> al (to scasb)
				mov CHAR,	byte [STR + i]		; str[i] -> char
				cmp CHAR,	0					; end of str?
				jz 			error				; return 0
				inc	i 							; i++
				mov rcx,	6					; nb elem whitespaces
				mov rdi,	whitespaces 		; whitespaces->rdi
				repnz		scasb 				; scan al & whitespaces
				je			_loop_whitspace 	; if is whitespaces => loop
# prepar to parsing value
				dec i 							; to sync i with CHAR = [STR + i]
				mov SIGN,	1
				
	_signe:		
				cmp CHAR,	'+'					; '+' ?
				je 		_next_sign 				; yes => next char
				cmp CHAR,	'-'					; '-' ?
				jne 	_pars_int				; no => parsing
				neg 	SIGN 					; yes => sign = -sign
	_next_sign:	inc i 							; i++
				mov CHAR,	byte [STR + i]		; str[i] -> char
				jmp 	_signe					; loop

	_pars_int:
				cmp CHAR,		0
				je 		error
				xor	RESULT,	RESULT 				;result = 0 

	_loop_int:	
				jmp		find_pos_base			; find positionnnnn in base =>return j
	_return_j:	push	j 						; saving rdx before mul (j)
				mul  LEN 						; result *= len(base)
				pop 	j						; restore rdx (j)
				add	RESULT,	j 					; result += j (pos in base)
				inc		i   					; next char in str
				mov CHAR,	byte [STR + i]
				cmp CHAR,	0					; end of str ?
				je 		return_int 				; yes => return int
				jmp 	_loop_int 				; continue parsing

find_pos_base:
				xor j,	j 						; j = 0
	_loop_j:	cmp CHAR, byte [BASE + j]		; char in Base ? 
				je 		_return_j				; yes ===> j is pos in base
				inc 	j 						; no => j++
				cmp j, LEN 						; end of base ?
				je 		return_int				; yes => end of parsing => return int
				jmp 	_loop_j					; no continue search


return_int:
				push	rdx
				mul		SIGN 					; RESULT *= SIGN -> rax
				pop 	rdx
				pop 	r12
				pop 	rbx
				ret

valid_base:
				cmp BASE,	0
				je 		error
				mov rdi,	BASE
				call	ft_strlen
				mov LEN,	rax
				cmp LEN,	1					; size(base) > 1?
				jle		error
				mov j, 	LEN 					; j = counter from 
				xor rax,	rax
  _loop_valid:
				dec j							; base[len - 1] .../
				mov CHAR,	byte [BASE + j]	;
				cmp CHAR,	byte '+'			; = '+' ?
				je 		error
				cmp CHAR,	byte '-'			; = '-' ?
				je 		error

				mov rcx,	6					; nb elem whitespaces
				mov rdi,	whitespaces	
				mov al,		CHAR		
				repnz	scasb					; scan al in whitespaces 
				je 		error					; ZF if whitespace found
				cmp j,	0
				je		_continue				; /...to  BASE[0]
												;count nb occur
				mov i,	j						; i = counter of occur
  _loop_count:	dec i							; i-- 
				cmp CHAR, byte [BASE + i]			; scan base from j - 1 .../
				je 		error					; 	if double =>error
				cmp i,	0						; /... to 0
				jnz		_loop_count
				jmp		_loop_valid

error:
				xor rax,	rax					; return (0)
				pop 	r12
				pop 	rbx
				ret