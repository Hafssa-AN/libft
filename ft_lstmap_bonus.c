/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:50:33 by hanebaro          #+#    #+#             */
/*   Updated: 2023/12/18 17:50:46 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*next;
	t_list	*p;
	void	*newcont;

	if (!lst)
		return (0);
	new = 0;
	p = lst;
	while (p)
	{
		newcont = f(p->content);
		next = ft_lstnew(newcont);
		if (!next)
		{
			del(newcont);
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, next);
		p = p->next;
	}
	return (new);
}
