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

#include "../includes/libasm_bonus.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

static void        ft_print_list(t_list **beg_list)
{
    t_list  *list;
    int     i;
    int     j;

    list = *beg_list;
    i = 0;
    if (!list)
        printf("Empty list\n");
    else
    {

        while (list)
        {
            j = 1;
            while (j <= i)
            {
                printf("\t");
                j++;
            }
            if (i > 0)
                printf("|_ ");
            printf("%s\n", list->data);
            list = list->next;
            i++;
        }
        j = 1;
        while (j <= i)
        {
            printf("\t");
            j++;
        }  
        printf("|_ %s\n", NULL);     
    }
}

void		clear_buf(char *buf, int size)
{
	int 	i;

	i = 0;
    while (i < size)
		buf[i++] = 0;
}

void    ft_myfree(void *ptr)
{
    free(ptr);
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


    printf("##################### STRLEN #####################\n\n");

    printf("My res: |%lu|%lu|%lu|%lu|%lu|\n", ft_strlen(p0), ft_strlen(p1), ft_strlen(p3), ft_strlen("1"), ft_strlen(""));
    printf("Lib C : |%lu|%lu|%lu|%lu|%lu|\n", strlen(p0), strlen(p1), strlen(p3), strlen("1"), strlen(""));

    printf("\n\n##################### STRCPY #####################\n\n");

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

	printf("\n\n##################### STRCMP #####################\n\n");

    printf("My res: |%d|%d|%d|%d|%d|%d|%d|\n", ft_strcmp(p0, p1), ft_strcmp(p0, p0), ft_strcmp(p1, p0), ft_strcmp(p0, p3), ft_strcmp(p3, p3), ft_strcmp(p4, p0), ft_strcmp(p3, p2));
    printf("Lib C : |%d|%d|%d|%d|%d|%d|%d|\n", strcmp(p0, p1), strcmp(p0, p0), strcmp(p1, p0), strcmp(p0, p3), strcmp(p3, p3), strcmp(p4, p0), strcmp(p3, p2));



	printf("\n\n##################### STRDUP #####################\n\n");

    char dup0[] = "Bonjour les amis.";
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
    printf("My dup ft_strdup('Bla bla \\0bla... \\n vous nous fatiguez'): %s\n", s);
    free(s);
    s = strdup(dup2);
    printf("Lib C  ft_strdup('Bla bla \\0bla... \\n vous nous fatiguez'): %s\n", s);
    free(s);
    s = ft_strdup(dup3);
    printf("My dup: ft_strdup('')<%s>\n", s);
    free(s);
    s = strdup(dup3);
    printf("Lib C : ft_strdup('')<%s>\n", s);
    free(s);

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

	printf("\n\noOoOoOoOoOoOoOoOoOoOoOo BONUS oOoOoOoOoOoOoOoOoOoOoOo\n");
    printf("\n##################### ft_list_push_front() #####################\n");
    t_list  *beg_list = NULL;

    ft_list_push_front(&beg_list, "Cyrille");
    ft_list_push_front(&beg_list, "Maxime");


    printf("\033[32mBefore push:\033[0mv \n");
    ft_print_list(&beg_list);
    ft_list_push_front(&beg_list, "Marc");
    ft_list_push_front(&beg_list, "Manon");
    ft_list_push_front(&beg_list, "Julia");
    ft_list_push_front(&beg_list, "Therese");
    ft_list_push_front(&beg_list, "Margaux");
    printf("\033[32mAfter push\033[0m\n");
    ft_print_list(&beg_list);

    printf("\n##################### ft_list_size() #####################\n");
    printf("List size: |%d|%d|%d|%d|\n", ft_list_size(beg_list), ft_list_size(beg_list->next), ft_list_size(beg_list->next->next), ft_list_size(NULL));


    printf("\n##################### ft_list_sort() #####################\n");
    ft_list_sort(&beg_list, &ft_strcmp);
    ft_print_list(&beg_list);


    printf("\t\033[32mempty_list\033[0m\nft_list_size(NULL) = %d\n",ft_list_size(NULL));
    printf("\tft_list_sort(NULL) >>>");
    ft_list_sort(NULL, &ft_strcmp);
    printf(" ok\n");

    t_list      *one_list = NULL;
    ft_list_push_front(&one_list, "Element One");
    ft_print_list(&one_list);
    printf("\n\t\033[32mAfter sort a list with One Element:\033[0m\n");
    ft_list_sort(&one_list, &ft_strcmp);
    ft_print_list(&one_list);

    printf("\n\t\033[32mft_list_sort(&list, NULL) : \033[0m");
    ft_list_sort(&beg_list, NULL);
    printf("ok\n");

    printf("\n");
    t_list *tripl_list = NULL;
    ft_list_push_front(&tripl_list, "milk");
    ft_list_push_front(&tripl_list, "milk");
    ft_list_push_front(&tripl_list, "milk");
    printf("\t\033[32mSorting with multiple elements :\n\tBefore\033[0m\n");
    ft_print_list(&tripl_list);
    ft_list_sort(&tripl_list, &ft_strcmp);
    printf("\t\033[32mAfter\033[0m\n");
    ft_print_list(&tripl_list);
    printf("\n\n##################### ft_list_remove_if() #####################\n");
    printf("\n\033[32mBefor ft_list_remove_if()\033[0m\n");
    ft_print_list(&beg_list);

    ft_list_remove_if(&beg_list, "Margaux", &ft_strcmp, &ft_myfree);
    printf("\t\033[32mAfter ft_list_remove_if(Margaux)\033[0m\n");
    ft_print_list(&beg_list);
    ft_list_remove_if(&beg_list, "Cyrille", &ft_strcmp, &ft_myfree);
    printf("\t\033[32mAfter ft_list_remove_if(Cyrille)\033[0m\n");
    ft_print_list(&beg_list);
    ft_list_remove_if(&beg_list, "Therese", &ft_strcmp, &ft_myfree);
    printf("\t\033[32mAfter ft_list_remove_if(Therese)\033[0m\n");
    ft_print_list(&beg_list);
    ft_list_remove_if(&beg_list, NULL, &ft_strcmp, &ft_myfree);
    printf("\t\033[32mAfter ft_list_remove_if(NULL)\033[0m\n");
    ft_print_list(&beg_list);

    printf("\t\033[32mList with only one Element\033[0m\n");
    ft_list_remove_if(&one_list, "", &ft_strcmp, &ft_myfree);
    ft_print_list(&one_list);
    
    ft_list_remove_if(&one_list, "Element One", &ft_strcmp, &ft_myfree);
    printf("\t-> \n");
    ft_print_list(&one_list);


    printf("\n\t\033[32mtest multiple : \n\tBefor\033[0m\n");
    ft_print_list(&tripl_list);
    ft_list_remove_if(&tripl_list, "milk", &ft_strcmp, &ft_myfree);
    printf("\t\033[32mAfter\033[0m\n");
    ft_print_list(&tripl_list);


printf("\n\n##################### ATOI_BASE #####################\n\n");

    char str0[] = "Enchat";

    printf("ft_atoi_base(\"1\", \"0123456789\") = %d\n", ft_atoi_base("1", "0123456789"));
    printf("Atoi_base: %d\n", ft_atoi_base("0", "0123456789"));
    printf("Atoi_base: %d\n", ft_atoi_base("1000", "0123456789"));
    printf("Atoi_base: %d\n", ft_atoi_base("1234", "0123456789"));
    printf("Atoi_base: %d\n", ft_atoi_base("9876", "0123456789"));
    printf("Atoi_base: %d\n", ft_atoi_base("8877", "0123456789"));

    printf("\nAtoi_base: %d\n", ft_atoi_base("ff", "0123456789abcdef"));
    printf("Atoi_base: %d\n", ft_atoi_base("ffff", "0123456789abcdef"));
    printf("Atoi_base: %d\n", ft_atoi_base("ffffff", "0123456789abcdef"));
    printf("Atoi_base: %d\n", ft_atoi_base("7fffffff", "0123456789abcdef"));
    printf("Atoi_base: %d\n", ft_atoi_base("ffffffff", "0123456789abcdef"));

    printf("\nAtoi_base: %d\n", ft_atoi_base("-ff", "0123456789abcdef"));
    printf("Atoi_base: %d\n", ft_atoi_base("-+-ffff", "0123456789abcdef"));
    printf("Atoi_base: %d\n", ft_atoi_base("---ffffff", "0123456789abcdef"));
    printf("Atoi_base: %d\n", ft_atoi_base("ba", "abcdefghij"));
    printf("Atoi_base: %d\n", ft_atoi_base("bcd", "abcdefghij"));

    printf("\nExpected alternate -1/1\n\n");
    printf("Str_checks: %d\n", ft_atoi_base("\n-a", "1a234"));
    printf("Str_checks: %d\n", ft_atoi_base("+a", "1a234"));
    printf("Str_checks: %d\n", ft_atoi_base("---a", "1a234"));
    printf("Str_checks: %d\n", ft_atoi_base("--a", "1a234"));
    printf("Str_checks: %d\n", ft_atoi_base("-+--a", "1a234"));
    printf("Str_checks: %d\n", ft_atoi_base("+--+a", "1a234"));
    printf("Str_checks: %d\n", ft_atoi_base("\n-a", "1a234"));
    printf("Str_checks: %d\n", ft_atoi_base("\n\f\r\t \n  \v+++a", "1a234"));
    printf("Str_checks: %d\n", ft_atoi_base("-4\n", "1423"));

    printf("\nCheck bad strs : expected 0\n");
    printf("Str_check: %d\n", ft_atoi_base("\n ", "1423"));
    printf("Str_checks: %d\n", ft_atoi_base("       \n", "1423"));
    printf("\nExpected base errors = 0\n\n");

    // printf("Base_checks: %d\n", ft_atoi_base(str0, "    afas.dfk     jhaelkgh12abc"));
    // printf("Base_checks: %d\n", ft_atoi_base(str0, "12345678901"));
    printf("Base_checks: %d\n", ft_atoi_base("", ""));
    printf("Base_checks: %d\n", ft_atoi_base("1", "1"));
    printf("Base_checks: %d\n", ft_atoi_base("1", "123 "));
    printf("Base_checks: %d\n", ft_atoi_base("1", "     1"));
    printf("Base_checks: %d\n", ft_atoi_base("1", "1  "));
    printf("Base_checks: %d\n", ft_atoi_base("1", "2\n1"));
    printf("Base_checks: %d\n", ft_atoi_base(str0, "112"));
    printf("Base_checks: %d\n", ft_atoi_base(str0, "1232"));
    printf("Base_checks: %d\n", ft_atoi_base(str0, "000000000"));
    printf("Base_checks: %d\n", ft_atoi_base(str0, "121234+"));
    printf("Base_checks: %d\n", ft_atoi_base(str0, "12abcdefg-"));
    printf("Base_checks: %d\n", ft_atoi_base(str0, "12abc-+"));
    printf("Base_checks: %d\n", ft_atoi_base(str0, "12abc--"));
    printf("Base_checks: %d\n", ft_atoi_base(str0, "12abcdefw    +"));
    printf("Base_checks: %d\n", ft_atoi_base(str0, "12+abc"));
    printf("Base_checks: %d\n", ft_atoi_base(str0, "+++12abc"));
    printf("Base_checks: %d\n", ft_atoi_base(str0, "+-+12abc"));
    printf("Base_checks: %d\n", ft_atoi_base(str0, "+as.dfkjhaelkgh12abc"));
    printf("Base_checks: %d\n", ft_atoi_base(str0, "-    afas.dfk     jhaelkgh12abc"));

    printf("ft_atoi_base(NULL,'0123456789') = %d\n", ft_atoi_base(NULL,"0123456789"));
    char    *max = "\399";
    printf("ft_atoi_base(\\501,NULL) = %d\n", ft_atoi_base(max,NULL));

printf("\n##################### END #####################\n");

    return (0);
}
