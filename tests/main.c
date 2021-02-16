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
    char buff2[i];
    char large[10000];

    clear_buf(buff, i);
    clear_buf(buff2, i);

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

    printf("ft_strcpy(buffer,'%s') = |%s|\t<=>\tstrcpy(buffer,'%s') = |%s|\t\t->%s\n", p0,ft_strcpy(buff,p0), p0, strcpy(buff,p0),(strcmp(ft_strcpy(buff,p0),strcpy(buff,p0))==0)? OK:KO);
    printf("ft_strcpy(buffer,'%s') = |%s|<=>strcpy(buffer,'%s') = |%s|\t->%s\n", p1,ft_strcpy(buff,p1), p1, strcpy(buff,p1),(strcmp(ft_strcpy(buff,p1),strcpy(buff,p1))==0)? OK:KO);
    printf("ft_strcpy(buffer,'%s') = |%s|\t<=>\tstrcpy(buffer,'%s') = |%s|\t\t\t->%s\n", p3,ft_strcpy(buff,p3), p3, strcpy(buff,p3),(strcmp(ft_strcpy(buff,p3),strcpy(buff,p3))==0)? OK:KO);
    clear_buf(buff, i);
    printf("ft_strcpy('%s,%s') = |%s|\t<=>\tstrcpy('%s,%s') = |%s|\t\t->%s\n", buff,p4,ft_strcpy(buff,p4),buff, p4, strcpy(buff,p4),(strcmp(ft_strcpy(buff,p4),strcpy(buff,p4))==0)? OK:KO);

    printf("ft_strcpy('%s,%s') = |%s|\t\t<=>\tstrcpy('%s,%s') = |%s|\t\t\t->%s\n", p3,p3,ft_strcpy(p3,p3),p3, p3, strcpy(p3,p3),(strcmp(ft_strcpy(p3,p3),strcpy(p3,p3))==0)? OK:KO);
    printf("ft_strcpy('%s,%s') = |%s|\t\t<=>\tstrcpy('%s,%s') = |%s|\t\t\t->%s\n", p2,p2+3,ft_strcpy(p2,p2+3),p2, p2+3, strcpy(p2,p2+3),(strcmp(ft_strcpy(p2,p2+3),strcpy(p2,p2+3))==0)? OK:KO);
    printf("ft_strcpy('%s,%s') = |%s|\t\t<=>\tstrcpy('%s,%s') = |%s|\t\t\t->%s\n", p5,p5+3,ft_strcpy(p5,p5+3),p5, p5+3, strcpy(p5,p5+3),(strcmp(ft_strcpy(p5,p5+3),strcpy(p5,p5+3))==0)? OK:KO);
    
	printf("\n\n##################### STRCMP #####################\n\n");

    printf("ft_strcmp('%s','%s') = %d\t<=>\tstrcmp('%s','%s') = %d\t->%s\n",p0,p1,ft_strcmp(p0,p1),p0,p1,strcmp(p0,p1),(ft_strcmp(p0,p1) == strcmp(p0,p1))? OK:KO);
    printf("ft_strcmp('%s','%s') = %d\t<=>\tstrcmp('%s','%s') = %d\t\t->%s\n",p0,p0,ft_strcmp(p0,p0),p0,p0,strcmp(p0,p0),(ft_strcmp(p0,p0) == strcmp(p0,p0))? OK:KO);
    printf("ft_strcmp('%s','%s') = %d\t<=>\tstrcmp('%s','%s') = %d\t\t->%s\n",p0,p3,ft_strcmp(p0,p3),p0,p3,strcmp(p0,p3),(ft_strcmp(p0,p3) == strcmp(p0,p3))? OK:KO);
    printf("ft_strcmp('%s','%s') = %d\t\t<=>\tstrcmp('%s','%s') = %d\t\t->%s\n",p3,p3,ft_strcmp(p3,p3),p3,p3,strcmp(p3,p3),(ft_strcmp(p3,p3) == strcmp(p3,p3))? OK:KO);
    printf("ft_strcmp('%s','%s') = %d\t<=>\tstrcmp('%s','%s') = %d\t->%s\n",p4,p0,ft_strcmp(p4,p0),p4,p0,strcmp(p4,p0),(ft_strcmp(p4,p0) == strcmp(p4,p0))? OK:KO);
    printf("ft_strcmp('%s','%s') = %d\t<=>\tstrcmp('%s','%s') = %d\t\t->%s\n",p3,p2,ft_strcmp(p3,p2),p3,p2,strcmp(p3,p2),(ft_strcmp(p3,p2) == strcmp(p3,p2))? OK:KO);
    printf("ft_strcmp('%s','%s') = %d\t<=>\tstrcmp('%s','%s') = %d\t->%s\n",p0,p1,ft_strcmp(p0,p1),p0,p1,strcmp(p0,p1),(ft_strcmp(p0,p1) == strcmp(p0,p1))? OK:KO);

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
    ssize_t i1,i2;

    i1 = 0;
    i2 = 0;
    clear_buf(buff, i);
    int fd1 = open("tests/test.txt", O_RDWR);
    int fd2 = open("tests/test.txt", O_RDWR);
    printf("\033[35mwith fd = open(\"tests/test.txt\", O_RDWR)\033[0m\n");
    i1 = ft_read(-1, buff, 10);
    i2 = read(-1, buff2, 10);
    printf("ft_read(-1, buff, 10) = %zd <%s>\t<=>\tread(-1, buff, 10) = %zd <%s>\t->%s\n",i1,buff,i2,buff2,(i1==i2 && strcmp(buff,buff2)==0)?OK:KO);
	clear_buf(buff, i);
    clear_buf(buff2,i);

    i1 = ft_read(fd1, buff, 20);
    i2 = read(fd2, buff2, 20);
    printf("ft_read(fd, buff, 20) = %zd <%s>\n\033[35mcompare with\033[0m read(fd, buff, 20) = %zd <%s>\t->%s\n",i1,buff,i2,buff2,(i1==i2 && strcmp(buff,buff2)==0)?OK:KO);
    clear_buf(buff, i);
    clear_buf(buff2,i);

    i1 = ft_read(fd1, buff, 30);
    i2 = read(fd2, buff2, 30);
    printf("ft_read(fd, buff, 30) = %zd <%s>\n\033[35mcompare with\033[0m read(fd, buff, 30) = %zd <%s>\t->%s\n",i1,buff,i2,buff2,(i1==i2 && strcmp(buff,buff2)==0)?OK:KO);
    clear_buf(buff, i);
    clear_buf(buff2,i);

    i1 = ft_read(fd1, buff, 40);
    i2 = read(fd2, buff2, 40);
    printf("ft_read(fd, buff, 40) = %zd <%s>\n\033[35mcompare with\033[0m read(fd, buff, 40) = %zd <%s>\t->%s\n",i1,buff,i2,buff2,(i1==i2 && strcmp(buff,buff2)==0)?OK:KO);
    clear_buf(buff, i);
    clear_buf(buff2,i);

    i1 = ft_read(fd1, buff, 50);
    i2 = read(fd2, buff2, 50);
    printf("ft_read(fd, buff, 50) = %zd <%s>\n\033[35mcompare with\033[0m read(fd, buff, 50) = %zd <%s>\t->%s\n",i1,buff,i2,buff2,(i1==i2 && strcmp(buff,buff2)==0)?OK:KO);
    clear_buf(buff, i);
    clear_buf(buff2,i);

    i1 = ft_read(fd1, buff, 0);
    i2 = read(fd2, buff2, 0);
    printf("ft_read(fd, buff, 0) = %zd <%s>\n\033[35mcompare with\033[0m read(fd, buff, 0) = %zd <%s>\t->%s\n",i1,buff,i2,buff2,(i1==i2 && strcmp(buff,buff2)==0)?OK:KO);
    clear_buf(buff, i);
    clear_buf(buff2,i);

    close(fd1);
    close(fd2);

    printf("\n##################### READ STDIN #####################\n\n");

    i1 = ft_read(0, buff, 100);
    printf("\nft_read(0,buff,100) = %zd <%s>\n", i1, buff);
 
    printf("\n##################### READ ERROR #####################\n\n");
    clear_buf(buff, i);
    int     error1, error2;

    fd1 = open("tests/test.txt", O_RDWR);
    fd2 = open("tests/test.txt", O_RDWR);
    
    i2 = read(-5, buff2, 10);
    error2 = errno;
    i1 = ft_read(-5, buff, 10);
    error1 = errno;
    printf("\nft_read(-5, buff, 10) = %zd <%s>\n\033[35mcompare with\033[0m read(-5, buff, 10) = %zd <%s>\n",i1,buff,i2,buff2);
    printf("errno of ft_read() = %d\t<=>\terrno of read() = %d\t->%s\n", error1,error2,(error1==error2)?OK:KO);
    perror("");

    i2 = read(fd2, buff2, -10);
    error2 = errno;
    i1 = ft_read(fd1, buff, -10);
    error1 = errno;
    printf("\nft_read(fd, buff, -10) = %zd <%s>\n\033[35mcompare with\033[0m read(fd, buff, -10) = %zd <%s>\n",i1,buff,i2,buff2);
    printf("errno of ft_read() = %d\t<=>\terrno of read() = %d\t->%s\n", error1,error2,(error1==error2)?OK:KO);
    perror("");

    i2 = read(fd2, NULL, 10);
    error2 = errno;
    i1 = ft_read(fd1, NULL, 10);
    error1 = errno;
    printf("\nft_read(fd, NULL, 10) = %zd <%s>\n\033[35mcompare with\033[0m read(fd, NULL, 10) = %zd <%s>\n",i1,buff,i2,buff2);
    printf("errno of ft_read() = %d\t<=>\terrno of read() = %d\t->%s\n", error1,error2,(error1==error2)?OK:KO);
    perror("");

    close(fd1);
    close(fd2);
    printf("\n\n##################### WRITE #####################\n\n");

    i1 = ft_write(1, "Oh chilele\n", 11);
    i2 = write(1, "Oh chilele\n", 11);
    printf("ft_write(1, \"Oh chilele\\n\", 11) = %zd\t<=>\twrite(1, \"Oh chilele\\n\", 11) = %zd\t->%s\n",i1,i2,(i1==i2)?OK:KO);

    i1 = ft_write(1, "\n", 2);
    i2 = write(1, "\n", 2);
    printf("\nft_write(\"\\n\") = %zd\t\t\t<=>\twrite(\"\\n\") = %zd\t\t\t->%s\n",i1,i2,(i1==i2)?OK:KO);

    i1 = ft_write(1, "Bombo\n", 0);
    i2 = write(1, "Bombo\n", 0);
    printf("\nft_write(1, \"Bombo\\n\", 0) = %zd\t\t<=>\twrite(1, \"Bombo\\n\", 0) = %zd\t->%s\n",i1,i2,(i1==i2)?OK:KO);

    i1 = ft_write(1, "", 2);
    i2 = write(1, "", 2);
    printf("\nft_write(1, \"\", 2) = %zd\t\t\t<=>\twrite(1, \"\", 2) = %zd\t\t->%s\n",i1,i2,(i1==i2)?OK:KO);

    i1 = ft_write(1, "test\n", 4);
    i2 = write(1, "test\n", 4);
    printf("\nft_write(1, \"test\\n\", 4) = %zd\t\t<=>\twrite(1, \"test\\n\", 4) = %zd\t->%s\n",i1,i2,(i1==i2)?OK:KO);

    i1 = ft_write(1, "test\n", 2);
    i2 = write(1, "test\n", 2);
    printf("\nft_write(1, \"test\\n\", 2) = %zd\t\t<=>\twrite(1, \"test\\n\", 2) = %zd\t->%s\n",i1,i2,(i1==i2)?OK:KO);

    i1 = ft_write(1, NULL, 2);
    i2 = write(1, NULL, 2);
    printf("\nft_write(1, NULL, 2) = %zd\t\t<=>\twrite(1, NULL, 2) = %zd\t\t->%s\n",i1,i2,(i1==i2)?OK:KO);

    printf("\n##################### WRITE ERROR #####################\n\n");

    i2 = write(1, NULL, 2);
    i1 = ft_write(1, NULL, 2);
    printf("ft_write(1, NULL, 2) = %zd\t<=>\twrite(1, NULL, 2) = %zd\t\t->%s\n", i1, i2,(i1==i2)?OK:KO);
    perror("");

    i2 = write(-1, buff, 2);
    i1 = ft_write(-1, buff2, 2);
    printf("\nft_write(-1, buff, 2) = %zd\t<=>\twrite(-1, buff, 2) = %zd\t\t->%s\n", i1, i2,(i1==i2)?OK:KO);
    perror("");

    i2 = write(1, buff, -122);
    i1 = ft_write(1, buff2, -122);
    printf("\nft_write(1, buff, -122) = %zd\t<=>\twrite(1, buff, -122) = %zd\t->%s\n", i1, i2,(i1==i2)?OK:KO);
    perror("");

printf("\n##################### END #####################\n");

    return (0);
}
