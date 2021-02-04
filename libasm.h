/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:08:46 by clorin            #+#    #+#             */
/*   Updated: 2021/01/28 18:10:19 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdlib.h>
# include <errno.h>
# include <stddef.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s);
ssize_t				ft_read(int fd, void *buf, size_t count);
ssize_t				ft_write(int fd, void *buf, size_t count);
int					ft_list_size(t_list *begin_list);
void				ft_list_push_front(t_list **begin_list, void *data);
void				ft_list_sort(t_list **begin_list, int (*cmp)());
void				ft_list_remove_if(t_list **begin_list, void *data,
					int (*cmp)(), void (*free_f)(void *));
int					ft_atoi_base(char *str, char *base);

#endif
