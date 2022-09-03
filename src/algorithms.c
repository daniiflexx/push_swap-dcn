/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:46:35 by danicn            #+#    #+#             */
/*   Updated: 2022/08/30 18:47:10 by danicn           ###   ########.fr       */
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
}

int	four_or_five_nums(t_list **s1, t_list **s2)
{
	if ((*s1)->next->next->next->next != NULL)
		push_b(s1, s2);
	push_b(s1, s2);
	if ()
}