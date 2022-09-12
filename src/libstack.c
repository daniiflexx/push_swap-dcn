/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:48:48 by danicn            #+#    #+#             */
/*   Updated: 2022/09/12 21:49:00 by dcruz-na         ###   ########.fr       */
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

int	push_b(t_list **s1, t_list **s2)
{
	t_list	*last;
	t_list	*lst;

	last = ft_lstlast(*s1);
	if (!last)
		return (-1);
	if ((*s1)->next == NULL)
		*s1 = NULL;
	else
	{
		lst = *s1;
		while (lst->next->next != NULL)
			lst = lst->next;
		lst->next = NULL;
	}
	ft_lstadd_back(s2, last);
	write(1, "pb\n", 3);
	return (0);
}

int rotate_a(t_list **s1)
{
	t_list	*lst;
	t_list	*last;

	if (ft_lstsize(*s1) < 2)
		return -1;
	lst = *s1;
	while (lst->next->next != NULL)
		lst = lst->next;
	last = lst->next;
	lst->next = NULL;
	lst = *s1;
	*s1 = last;
	last->next = lst;
	write(1, "ra\n", 3);
	return (0);
}

int rotate_b(t_list **s1)
{
	t_list	*lst;
	t_list	*last;

	if (ft_lstsize(*s1) < 2)
		return -1;
	lst = *s1;
	while (lst->next->next != NULL)
		lst = lst->next;
	last = lst->next;
	lst->next = NULL;
	lst = *s1;
	*s1 = last;
	last->next = lst;
	write(1, "rb\n", 3);
	return (0);
}
int rotate(t_list **s1)
{
	t_list	*lst;
	t_list	*last;

	if (ft_lstsize(*s1) < 2)
		return -1;
	lst = *s1;
	while (lst->next->next != NULL)
		lst = lst->next;
	last = lst->next;
	lst->next = NULL;
	lst = *s1;
	*s1 = last;
	last->next = lst;
	return (0);
}

int rotate_rr(t_list **s1, t_list **s2)
{
	if (rotate(s1) == -1)
		return (-1);
	if (rotate(s2) == -1)
		return (-1);
	write(1, "rr\n", 3);
	return (0);
}

int rrotate_a(t_list **s1)
{
	t_list	*last;
	t_list	*lst;

	if (ft_lstsize(*s1) < 2)
		return (-1);
	last = ft_lstlast(*s1);
	last->next = *s1;
	lst = (*s1)->next;
	(*s1)->next = NULL;
	*s1 = lst;
	write(1, "rra\n", 4);
	return (0);
}

int rrotate_b(t_list **s1)
{
	t_list	*last;
	t_list	*lst;

	if (ft_lstsize(*s1) < 2)
		return (-1);
	last = ft_lstlast(*s1);
	last->next = *s1;
	lst = (*s1)->next;
	(*s1)->next = NULL;
	*s1 = lst;
	write(1, "rrb\n", 4);
	return (0);
}

int rrotate(t_list **s1)
{
	t_list	*last;
	t_list	*lst;

	if (ft_lstsize(*s1) < 2)
		return (-1);
	last = ft_lstlast(*s1);
	last->next = *s1;
	lst = (*s1)->next;
	(*s1)->next = NULL;
	*s1 = lst;
	return (0);
}

int	rrotate_rr(t_list **s1, t_list **s2)
{
	if (rrotate(s1) == -1)
		return (-1);
	if (rrotate(s2) == -1)
		return (-1);
	write(1, "rrr\n", 4);
	return (0);
}