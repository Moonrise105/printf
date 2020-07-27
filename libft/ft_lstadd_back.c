/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonrise <moonrise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:55:29 by moonrise          #+#    #+#             */
/*   Updated: 2020/05/17 22:04:40 by moonrise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *nw)
{
	t_list		*p;

	if (lst && *lst)
	{
		p = *lst;
		while (p->next)
			p = p->next;
		p->next = nw;
	}
	else if (lst)
		*lst = nw;
}
