/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:46:35 by danicn            #+#    #+#             */
/*   Updated: 2022/09/22 21:27:32 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	three_nums(t_list **s1)
{
	if (*(int *)(*s1)->content > *(int *)(*s1)->next->content
	&& *(int *)(*s1)->next->content < *(int *)(*s1)->next->next->content
	&& *(int *)(*s1)->content > *(int *)(*s1)->next->next->content)
		swap_a(s1);
	else if (*(int *)(*s1)->content > *(int *)(*s1)->next->content
	&& *(int *)(*s1)->next->content < *(int *)(*s1)->next->next->content
	&& *(int *)(*s1)->content < *(int *)(*s1)->next->next->content)
		rotate_a(s1);
	else if (*(int *)(*s1)->content < *(int *)(*s1)->next->content
	&& *(int *)(*s1)->next->content < *(int *)(*s1)->next->next->content)
	{
		swap_a(s1);
		rrotate_a(s1);
	}
	else if (*(int *)(*s1)->content < *(int *)(*s1)->next->content
	&& *(int *)(*s1)->next->content > *(int *)(*s1)->next->next->content
	&& *(int *)(*s1)->content < *(int *)(*s1)->next->next->content)
		rrotate_a(s1);
	else if (*(int *)(*s1)->content < *(int *)(*s1)->next->content
	&& *(int *)(*s1)->next->content > *(int *)(*s1)->next->next->content
	&& *(int *)(*s1)->content > *(int *)(*s1)->next->next->content)
	{
		rrotate_a(s1);
		swap_a(s1);	
	}
	return (0);
}

int	four_nums(t_list **s1, t_list **s2)
{
	push_b(s1, s2);
	three_nums(s1);
	if (*(int *)(*s1)->content < *(int *)ft_lstlast(*s2)->content)
	{
		push_a(s1, s2);
		rotate_a(s1);
	}
	else if (*(int *)(*s1)->next->content < *(int *)ft_lstlast(*s2)->content)
	{
		rrotate_a(s1);
		push_a(s1, s2);
		rotate_a(s1);
		rotate_a(s1);
	}
	else if (*(int *)(*s1)->next->next->content <
	*(int *)ft_lstlast(*s2)->content)
	{
		push_a(s1, s2);
		swap_a(s1);
	}
	else
		push_a(s1, s2);
	return (0);
}

int	five_nums(t_list **s1, t_list **s2)
{
	push_b(s1, s2);
	four_nums(s1, s2);
	if (*(int *)(*s1)->content < *(int *)ft_lstlast(*s2)->content)
	{
		push_a(s1, s2);
		rotate_a(s1);
	}
	else if (*(int *)(*s1)->next->content < *(int *)ft_lstlast(*s2)->content)
	{
		rrotate_a(s1);
		push_a(s1, s2);
		rotate_a(s1);
		rotate_a(s1);
	}
	else if (*(int *)(*s1)->next->next->content <
	*(int *)ft_lstlast(*s2)->content)
	{
		rotate_a(s1);
		rotate_a(s1);
		push_a(s1, s2);
		rrotate_a(s1);
		rrotate_a(s1);
	}
	else if (*(int *)(*s1)->next->next->next->content <
	*(int *)ft_lstlast(*s2)->content)
	{
		push_a(s1, s2);
		swap_a(s1);
	}
	else
		push_a(s1, s2);
	return (0);
}
int	*sort(t_list *lst)
{
	t_list	*aux;
	int		*d;

	if (ft_lstsize(lst) != 2)
	{
		aux
		while (lst != NULL)
		{
			aux = lst;
			if (lst == aux)
		}
	}
}
int *radix_sort(t_list *s1, t_list *s2)
{
	sort(s1);
}
