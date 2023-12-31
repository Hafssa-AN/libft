/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:17:41 by hanebaro          #+#    #+#             */
/*   Updated: 2023/12/18 13:17:44 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;
	t_list	*nnext;

	if (!*lst)
		return ;
	p = *lst;
	while (p)
	{
		nnext = p -> next;
		ft_lstdelone(p, del);
		p = nnext;
	}
	*lst = 0;
}
