/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:48:48 by danicn            #+#    #+#             */
/*   Updated: 2022/10/04 19:04:01 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **list)
{
	t_list	*iter;
	t_list	*aux;

	if (!list || (*list)->next == NULL)
		return (-1);
	if ((*list)->next->next == NULL)
	{
		aux = (*list);
		*list = (*list)->next;
		(*list)->next = aux;
		aux->next = NULL;
	}
	else
	{
		iter = *list;
		while (iter->next->next->next != NULL)
			iter = iter->next;
		aux = iter->next;
		iter->next = iter->next->next;
		iter->next->next = aux;
		aux->next = NULL;
	}
	return (0);
}

int	swap_a(t_list **list)
{
	t_list	*iter;
	t_list	*aux;

	if (!list || (*list)->next == NULL)
		return (-1);
	if ((*list)->next->next == NULL)
	{
		aux = (*list);
		*list = (*list)->next;
		(*list)->next = aux;
		aux->next = NULL;
	}
	else
	{
		iter = *list;
		while (iter->next->next->next != NULL)
			iter = iter->next;
		aux = iter->next;
		iter->next = iter->next->next;
		iter->next->next = aux;
		aux->next = NULL;
	}
	write(1, "sa\n", 3);
	return (0);
}

int	swap_b(t_list **list)
{
	t_list	*iter;
	t_list	*aux;

	if (!list || (*list)->next == NULL)
		return (-1);
	if ((*list)->next->next == NULL)
	{
		aux = (*list);
		*list = (*list)->next;
		(*list)->next = aux;
		aux->next = NULL;
	}
	else
	{
		iter = *list;
		while (iter->next->next->next != NULL)
			iter = iter->next;
		aux = iter->next;
		iter->next = iter->next->next;
		iter->next->next = aux;
		aux->next = NULL;
	}
	write(1, "sb\n", 3);
	return (0);
}

int	swap_ab(t_list **list, t_list **list2)
{
	if (swap(list) < 0)
		return (-1);
	if (swap(list2) < 0)
		return (-1);
	write(1, "ss\n", 3);
	return (0);
}

int	push_a(t_list **s1, t_list **s2)
{
	t_list	*last;
	t_list	*lst;

	last = ft_lstlast(*s2);
	if (!last)
		return (-1);
	if ((*s2)->next == NULL)
		*s2 = NULL;
	else
	{
		lst = *s2;
		while (lst->next->next != NULL)
			lst = lst->next;
		lst->next = NULL;
	}
	ft_lstadd_back(s1, last);
	write(1, "pa\n", 3);
	return (0);
}
