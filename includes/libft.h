/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.21.ru>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 22:55:39 by moonrise          #+#    #+#             */
/*   Updated: 2020/07/22 21:34:35 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *str);
int					ft_isalpha(int ch);
int					ft_isdigit(int ch);
int					ft_isalnum(int ch);
int					ft_isascii(int ch);
int					ft_isprint(int ch);
int					ft_toupper(int ch);
int					ft_tolower(int ch);
void				*ft_memcpy(void *dest, const void *src, size_t count);
void				*ft_memccpy(void *dest, const void *source, int ch,
					size_t count);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
void				*ft_memmove(void *dest, const void *src, size_t num);
void				*ft_memchr (const void *arr, int c, size_t n);
int					ft_memcmp(const void *buf1, const void *buf2, size_t count);
void				*ft_memset(void *dest, int c, size_t n);
int					ft_atoi(const char *str);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *str);
size_t				ft_strlcat(char *dest, const char *src,
					size_t size);
int					ft_strncmp(const char *string1, const char *string2,
					size_t num);
char				*ft_strnstr (const char *s1, const char *s2, size_t len);
char				*ft_strrchr(const char *str, int ch);
void				*ft_calloc(size_t num, size_t size);
void				ft_bzero(void *s, size_t n);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *nw);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *nw);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
#endif
