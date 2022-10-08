/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:59:45 by dcruz-na          #+#    #+#             */
/*   Updated: 2022/10/04 19:01:48 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_rr(t_list **s1, t_list **s2)
{
	if (rotate(s1) == -1)
		return (-1);
	if (rotate(s2) == -1)
		return (-1);
	write(1, "rr\n", 3);
	return (0);
}

int	rrotate_a(t_list **s1)
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

int	rrotate_b(t_list **s1)
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

int	rrotate(t_list **s1)
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