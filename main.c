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
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

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
	char p4[] = "ab\xff";
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

	printf("\n\n### STRCMP ###\n\n");

    printf("My res: |%d|%d|%d|%d|%d|%d|%d|\n", ft_strcmp(p0, p1), ft_strcmp(p0, p0), ft_strcmp(p1, p0), ft_strcmp(p0, p3), ft_strcmp(p3, p3), ft_strcmp(p4, p0), ft_strcmp(p3, p2));
    printf("Lib C : |%d|%d|%d|%d|%d|%d|%d|\n", strcmp(p0, p1), strcmp(p0, p0), strcmp(p1, p0), strcmp(p0, p3), strcmp(p3, p3), strcmp(p4, p0), strcmp(p3, p2));

	printf("\n\n** STRDUP **\n\n");

    char dup0[] = "bonjour les amis.";
    char dup1[] = "Le langage assembleur, souvent appellé asm, est un langage de bas niveau pour ordinateur - ou autre machine programmable - qui possède une très forte correspondance\nentre le langage et l’architecture de la machine.\n";
    char dup2[] = "Bla bla \0bla... \n vous nous fatiguez";
    char dup3[] = "";

    char *s = ft_strdup(dup0);
    printf("My dup: %s\n", s);
    free(s);
    s = ft_strdup(dup1);
    printf("My dup: %s\n", s);
    free(s);
    s = ft_strdup(dup2);
    printf("My dup: %s\n", s);
    free(s);
    s = strdup(dup2);
    printf("Lib C : %s\n", s);
    free(s);
    s = ft_strdup(dup3);
    printf("My dup: <%s>\n", s);
    free(s);

    printf("\n\n### READ ###\n\n");

    clear_buf(buff, i);
    int fd1 = open("test.txt", O_RDWR);
    printf("My read: |%zd|\n", ft_read(-1, buff, 10));
    printf("My read: |%s|\n", buff);
	clear_buf(buff, i);
    printf("My read: |%zd|\n", ft_read(fd1, buff, 20));
    printf("My read: |%s|\n", buff);
    clear_buf(buff, i);
    printf("My read: |%zd|\n", ft_read(fd1, buff, 30));
    printf("My read: |%s|\n", buff);
    clear_buf(buff, i);
    printf("My read: |%zd|\n", ft_read(fd1, buff, 40));
    printf("My read: |%s|\n", buff);
    clear_buf(buff, i);
    printf("My read: |%zd|\n", ft_read(fd1, buff, 50));
    printf("My read: |%s|\n", buff);
    clear_buf(buff, i);
    printf("My read: |%zd|\n", ft_read(fd1, buff, 0));
    printf("My read: |%s|\n", buff);
    close(fd1);

    fd1 = open("read_test.txt", O_RDWR);
    printf("Lib C: |%zd|\n", read(fd1, buff, 10));
    printf("Lib C: |%s|\n", buff);
    clear_buf(buff, i);
    printf("Lib C: |%zd|\n", read(fd1, buff, 20));
    printf("Lib C: |%s|\n", buff);
    clear_buf(buff, i);
    printf("Lib C: |%zd|\n", read(fd1, buff, 30));
    printf("Lib C: |%s|\n", buff);
    clear_buf(buff, i);
    printf("Lib C: |%zd|\n", read(fd1, buff, 40));
    printf("Lib C: |%s|\n", buff);
    clear_buf(buff, i);
    printf("Lib C: |%zd|\n", read(fd1, buff, 50));
    printf("Lib C: |%s|\n", buff);
    clear_buf(buff, i);
    printf("Lib C: |%zd|\n", read(fd1, buff, 0));
    printf("Lib C: |%s|\n", buff);
    close(fd1);


    printf("\n** READ STDIN **\n\n");

    clear_buf(buff, i);
    printf("My read: %zd\n", ft_read(0, buff, 10));
    printf("My read: %s\n", buff);
    clear_buf(buff, i);
    printf("C read : %zd\n", read(0, buff, 10));
    printf("C read : %s\n", buff);

    printf("\n** READ ERROR **\n\n");
    clear_buf(buff, i);
    fd1 = open("test.txt", O_RDWR);
    printf("My read: |%zd|\n", ft_read(-5, buff, 10));
    printf("My read: |%s|\n", buff);
    printf("Errno: %d\n", errno);
    perror("ft_read(-5, buff, 10) => Error in read:");

    printf("My read: |%zd|\n", ft_read(fd1, buff, -10));
    printf("My read: |%s|\n", buff);
    printf("Errno: %d\n", errno);
    perror("ft_read(fd1, buff, -10) => Error in read:");

    printf("My read: |%zd|\n", ft_read(fd1, NULL, 10));
    printf("My read: |%s|\n", buff);
    printf("Errno: %d\n", errno);
    perror("ft_read(fd1, NULL, 10) => Error in read:");

    printf("C read: |%zd|\n", read(-5, buff, 10));
    printf("C Char read: |%s|\n", buff);
    printf("Errno: %d\n", errno);
    perror("read(-5, buff, 10) => Error in read:");
    printf("C read: |%zd|\n", read(fd1, buff, -10));
    printf("C Char read: |%s|\n", buff);
    printf("Errno: %d\n", errno);
    perror("read(fd1, buff, -10) => Error in read:");
    printf("C read: |%zd|\n", read(fd1, NULL, 10));
    printf("C Char read: |%s|\n", buff);
    printf("Errno: %d\n", errno);
    perror("read(fd1, NULL, 10) => Error in read:");
    close(fd1);

	return (0);
}
