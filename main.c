/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:10:35 by clorin            #+#    #+#             */
/*   Updated: 2021/01/28 18:14:52 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <string.h>

void		clear_buf(char *buf, int size)
{
	int 	i;

	i = 0;
    while (i < size)
		buf[i++] = 0;
}

int		main(void)
{
	char p0[] = "abc";
    char p1[] = "abcabc";
    char p2[] = "abcdefg";
    char p3[] = "";
	//char p4[] = "ab\xff";
	char p5[] = "abcdefg";
    int i = 100;
    char buff[i];

    clear_buf(buff, i);


    printf("### STRLEN ###\n\n");

    printf("My res: |%lu|%lu|%lu|%lu|%lu|\n", ft_strlen(p0), ft_strlen(p1), ft_strlen(p3), ft_strlen("1"), ft_strlen(""));
    printf("Lib C : |%lu|%lu|%lu|%lu|%lu|\n", strlen(p0), strlen(p1), strlen(p3), strlen("1"), strlen(""));

    printf("\n\n### STRCPY ###\n\n");

    printf("My res: (%s, %s) |%s|\n", buff, p0, ft_strcpy(buff, p0));
    printf("Lib C : (%s, %s) |%s|\n", buff, p0, strcpy(buff, p0));
    printf("My res: (%s, %s) |%s|\n", buff, p1, ft_strcpy(buff, p1));
    printf("Lib C : (%s, %s) |%s|\n", buff, p1, strcpy(buff, p1));
    printf("My res: (%s, %s) |%s|\n", buff, p3, ft_strcpy(buff, p3));
    printf("Lib C : (%s, %s) |%s|\n", buff, p3, strcpy(buff, p3));
    printf("My res: (%s, %s) |%s|\n", p3, p3, ft_strcpy(p3, p3));
    printf("Lib C : (%s, %s) |%s|\n", p3, p3, strcpy(p3, p3));
    printf("My res: (%s, %s) |%s|\n", p2, p2 + 3, ft_strcpy(p2, p2 + 3));
	printf("Lib C : (%s, %s) |%s|\n", p5, p5 + 3, strcpy(p5, p5 + 3));
	return (0);
}
