/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:01:50 by hanebaro          #+#    #+#             */
/*   Updated: 2023/12/18 12:02:00 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*p;

	if (!lst)
		return (0);
	if (ft_lstsize(lst) == 1)
		return (lst);
	p = lst;
	while (p -> next)
	{
		if (!(p -> next)-> next)
			break ;
		p = p -> next;
	}
	return (p -> next);
}
