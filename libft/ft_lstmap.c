/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaekim <yaekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:40:58 by yaekim            #+#    #+#             */
/*   Updated: 2024/04/01 12:54:21 by yaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_lst(t_list *head, t_list *new, void (*del)(void *))
{
	if (!new)
	{
		ft_lstclear(&head, del);
		return (0);
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;
	int		flag;

	flag = 1;
	head = 0;
	while (lst)
	{
		if (flag)
		{
			new = ft_lstnew(f(lst->content));
			head = new;
			flag = 0;
		}
		else
		{
			new->next = ft_lstnew(f(lst->content));
			new = new->next;
		}
		if (check_lst(head, new, del) == 0)
			return (0);
		lst = lst->next;
	}
	return (head);
}
