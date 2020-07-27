/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonrise <moonrise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 22:13:00 by moonrise          #+#    #+#             */
/*   Updated: 2020/05/17 22:27:05 by moonrise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list		*p;

	if (lst && *lst)
	{
		while (*lst)
		{
			p = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = NULL;
			*lst = p;
		}
	}
	*lst = NULL;
}
