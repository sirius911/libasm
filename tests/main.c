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

#include "../includes/libasm.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

# define OK "\033[32mOK\033[0m"
# define KO "\033[31mKO\033[0m"

static void		clear_buf(char *buf, int size)
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
    int j = 0;
    char buff[i];
    char large[10000];

    clear_buf(buff, i);


    printf("##################### STRLEN #####################\n\n");
    printf("ft_strlen('%s') = %lu \t<=>\tstrlen('%s') = %lu\t\t->%s\n",p0,ft_strlen(p0),p0,strlen(p0),(ft_strlen(p0) == strlen(p0))? OK:KO);
    printf("ft_strlen('%s') = %lu <=>\tstrlen('%s') = %lu\t\t->%s\n",p1,ft_strlen(p1),p0,strlen(p1),(ft_strlen(p1) == strlen(p1))? OK:KO);
    printf("ft_strlen('%s') = %lu \t<=>\tstrlen('%s') = %lu\t\t->%s\n",p3,ft_strlen(p3),p0,strlen(p3),(ft_strlen(p3) == strlen(p3))? OK:KO);
    printf("ft_strlen('%s') = %lu \t<=>\tstrlen('%s') = %lu\t\t->%s\n","1",ft_strlen("1"),p0,strlen("1"),(ft_strlen("1") == strlen("1"))? OK:KO);
    printf("ft_strlen('%s') = %lu \t<=>\tstrlen('%s') = %lu\t\t\t->%s\n","",ft_strlen(""),"",strlen(""),(ft_strlen("") == strlen(""))? OK:KO);

    clear_buf(large,10000);
    while (j <= 9999)
        large[j++] = 'c';

    printf("ft_strlen(LARGE) = %lu <=>\tstrlen(LARGE) = %lu\t\t->%s\n",ft_strlen(large),strlen(large),(ft_strlen(large) == strlen(large))? OK:KO);

    printf("\n\n##################### STRCPY #####################\n\n");

    printf("ft_strcpy(buffer,'%s') = |%s|\tstrcpy(buffer,'%s') = |%s|\t\t\t ->%s\n", p0,ft_strcpy(buff,p0), p0, strcpy(buff,p0),(strcmp(ft_strcpy(buff,p0),strcpy(buff,p0))==0)? OK:KO);
    printf("ft_strcpy(buffer,'%s') = |%s|\tstrcpy(buffer,'%s') = |%s|\t ->%s\n", p1,ft_strcpy(buff,p1), p1, strcpy(buff,p1),(strcmp(ft_strcpy(buff,p1),strcpy(buff,p1))==0)? OK:KO);
    printf("ft_strcpy(buffer,'%s') = |%s|\tstrcpy(buffer,'%s') = |%s|\t\t\t\t ->%s\n", p3,ft_strcpy(buff,p3), p3, strcpy(buff,p3),(strcmp(ft_strcpy(buff,p3),strcpy(buff,p3))==0)? OK:KO);
    clear_buf(buff, i);
    printf("ft_strcpy('%s,%s') = |%s|\tstrcpy('%s,%s') = |%s|\t\t\t ->%s\n", buff,p4,ft_strcpy(buff,p4),buff, p4, strcpy(buff,p4),(strcmp(ft_strcpy(buff,p4),strcpy(buff,p4))==0)? OK:KO);

    printf("ft_strcpy('%s,%s') = |%s|\tstrcpy('%s,%s') = |%s|\t\t\t\t ->%s\n", p3,p3,ft_strcpy(p3,p3),p3, p3, strcpy(p3,p3),(strcmp(ft_strcpy(p3,p3),strcpy(p3,p3))==0)? OK:KO);
    printf("ft_strcpy('%s,%s') = |%s|\tstrcpy('%s,%s') = |%s|\t\t\t\t ->%s\n", p2,p2+3,ft_strcpy(p2,p2+3),p2, p2+3, strcpy(p2,p2+3),(strcmp(ft_strcpy(p2,p2+3),strcpy(p2,p2+3))==0)? OK:KO);
    printf("ft_strcpy('%s,%s') = |%s|\tstrcpy('%s,%s') = |%s|\t\t\t\t ->%s\n", p5,p5+3,ft_strcpy(p5,p5+3),p5, p5+3, strcpy(p5,p5+3),(strcmp(ft_strcpy(p5,p5+3),strcpy(p5,p5+3))==0)? OK:KO);
    
	printf("\n\n##################### STRCMP #####################\n\n");

    printf("ft_strcmp('%s','%s') = %d\tstrcmp('%s','%s') = %d\t->%s\n",p0,p1,ft_strcmp(p0,p1),p0,p1,strcmp(p0,p1),(ft_strcmp(p0,p1) == strcmp(p0,p1))? OK:KO);
    printf("ft_strcmp('%s','%s') = %d\tstrcmp('%s','%s') = %d\t\t->%s\n",p0,p0,ft_strcmp(p0,p0),p0,p0,strcmp(p0,p0),(ft_strcmp(p0,p0) == strcmp(p0,p0))? OK:KO);
    printf("ft_strcmp('%s','%s') = %d\tstrcmp('%s','%s') = %d\t\t->%s\n",p0,p3,ft_strcmp(p0,p3),p0,p3,strcmp(p0,p3),(ft_strcmp(p0,p3) == strcmp(p0,p3))? OK:KO);
    printf("ft_strcmp('%s','%s') = %d\tstrcmp('%s','%s') = %d\t\t->%s\n",p3,p3,ft_strcmp(p3,p3),p0,p1,strcmp(p3,p3),(ft_strcmp(p3,p3) == strcmp(p3,p3))? OK:KO);
    printf("ft_strcmp('%s','%s') = %d\tstrcmp('%s','%s') = %d\t->%s\n",p4,p0,ft_strcmp(p4,p0),p4,p0,strcmp(p4,p0),(ft_strcmp(p4,p0) == strcmp(p4,p0))? OK:KO);
    printf("ft_strcmp('%s','%s') = %d\tstrcmp('%s','%s') = %d\t\t->%s\n",p3,p2,ft_strcmp(p3,p2),p3,p2,strcmp(p3,p2),(ft_strcmp(p3,p2) == strcmp(p3,p2))? OK:KO);
    printf("ft_strcmp('%s','%s') = %d\tstrcmp('%s','%s') = %d\t->%s\n",p0,p1,ft_strcmp(p0,p1),p0,p1,strcmp(p0,p1),(ft_strcmp(p0,p1) == strcmp(p0,p1))? OK:KO);

	printf("\n\n##################### STRDUP #####################\n\n");

    char dup0[] = "Bonjour les amis.";
    char dup1[] = "Le langage assembleur, souvent appellé asm, est un langage de bas niveau pour ordinateur - ou autre machine programmable - qui possède une très forte correspondance\nentre le langage et l’architecture de la machine.\n";
    char dup2[] = "Bla bla \0bla... \n vous nous fatiguez";
    char dup3[] = "";

    char *s;
    char *s2;

    s = ft_strdup(dup0);
    printf("ft_strdup('%s') = %s\t->%s\n", dup0,s,(strcmp(dup0,s) == 0)? OK:KO);
    free(s);
    s = ft_strdup(dup1);
    printf("ft_strdup(LARGE) \t->%s\n", (strcmp(dup1,s) == 0)? OK:KO);
    free(s);
    s = ft_strdup(dup2);
    s2 = strdup(dup2);
    printf("ft_strdup('Bla bla \\0bla... \\n vous nous fatiguez') = %s\n", s);
    printf("\033[35mcompare with\033[0m strdup() = %s\t->%s\n", s2, (strcmp(s,s2) == 0)?OK:KO);

    s = ft_strdup(dup3);
    s2 = strdup(dup3);
    printf("ft_strdup('') = <%s>\tstrdup('') = <%s>\t->%s\n", s,s2,(strcmp(s,s2)==0)?OK:KO);
    free(s);
    free(s2);

    printf("\n\n##################### READ #####################\n\n");

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
    printf("Lib C:   |%zd|\n", read(fd1, buff, 10));
    printf("Lib C:   |%s|\n", buff);
    clear_buf(buff, i);
    printf("Lib C:   |%zd|\n", read(fd1, buff, 20));
    printf("Lib C:   |%s|\n", buff);
    clear_buf(buff, i);
    printf("Lib C:   |%zd|\n", read(fd1, buff, 30));
    printf("Lib C:   |%s|\n", buff);
    clear_buf(buff, i);
    printf("Lib C:   |%zd|\n", read(fd1, buff, 40));
    printf("Lib C:   |%s|\n", buff);
    clear_buf(buff, i);
    printf("Lib C:   |%zd|\n", read(fd1, buff, 50));
    printf("Lib C:   |%s|\n", buff);
    clear_buf(buff, i);
    printf("Lib C:   |%zd|\n", read(fd1, buff, 0));
    printf("Lib C:   |%s|\n", buff);
    close(fd1);


    printf("\n##################### READ STDIN #####################\n\n");

    clear_buf(buff, i);
    printf("My read: %zd\n", ft_read(0, buff, 100));
    printf("My read: %s\n", buff);
    clear_buf(buff, i);
    printf("C read : %zd\n", read(0, buff, 100));
    printf("C read : %s\n", buff);

    printf("\n##################### READ ERROR #####################\n\n");
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

    printf("\n\n##################### WRITE #####################\n\n");

    printf("My write: |%zd|\n", ft_write(1, "Oh chilele\n", 11));
    printf("My write: |%zd|\n", ft_write(1, "\n", 2));
    printf("My write: |%zd|\n", ft_write(1, "Bombo\n", 0));
    printf("My write: |%zd|\n", ft_write(1, "", 2));
    printf("My write: |%zd|\n", ft_write(1, "test", 4));
    printf("My write: |%zd|\n", ft_write(1, "test", 2));
    printf("My write: |%zd|\n", ft_write(1, NULL, 2));
    printf("**\n");
    printf("Unistd: |%zd|\n", write(1, "Oh chilele\n", 11));
    printf("Unistd: |%zd|\n", write(1, "\n", 2));
    printf("Unistd: |%zd|\n", write(1, "Bombo\n", 0));
    printf("Unistd: |%zd|\n", write(1, "", 2));
    printf("Unistd: |%zd|\n", write(1, "test", 4));
    printf("Unistd: |%zd|\n", write(1, "test", 2));
    printf("Unistd: |%zd|\n", write(1, NULL, 2));

    printf("\n##################### WRITE ERROR #####################\n\n");
    printf("My res: |%zd|\n", ft_write(1, NULL, 2));
    printf("Errno: %d\n", errno);
    perror("Error in read:");
    printf("My res: |%zd|\n", ft_write(-1, buff, 2));
    printf("Errno: %d\n", errno);
    perror("Error in read:");
    printf("My res: |%zd|\n", ft_write(1, buff, -122));
    printf("Errno: %d\n", errno);
    perror("Error in read:");

    printf("Unistd: |%zd|\n", write(1, NULL, 2));
    printf("Errno: %d\n", errno);
    perror("Error in read:");
    printf("Unistd: |%zd|\n", write(-1, buff, 2));
    printf("Errno: %d\n", errno);
    perror("Error in read:");
    printf("Unistd: |%zd|\n", write(1, buff, -122));
    printf("Errno: %d\n", errno);
    perror("Error in read:");

printf("\n##################### END #####################\n");

    return (0);
}
