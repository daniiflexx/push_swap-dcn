/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:46:35 by danicn            #+#    #+#             */
/*   Updated: 2022/10/04 19:56:30 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_nums(t_list **s1)
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

void	four_nums(t_list **s1, t_list **s2)
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
}

void	five_nums(t_list **s1, t_list **s2)
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
}

void	insertion_sort(int arr[], int n)
{
	int	i;
	int	key;
	int	j;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] < key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		i++;
	}
}

t_list	*sort(t_list *lst)
{
	int		*arr;
	int		i;
	int		size;
	t_list	*l;

	size = ft_lstsize(lst);
	arr = (int *) malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	l = lst;
	while (i < size)
	{
		arr[i] = *(int *)lst->content;
		i++;
		lst = lst->next;
	}
	insertion_sort(arr, size);
	i = 0;
	lst = l;
	while (lst != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == *(int *)lst->content)
			{
				*(int *)lst->content = size - i - 1;
				break ;
			}
			i++;
		}
		lst = lst->next;
	}
	free(arr);
	return (l);
}
int		lst_isOrdered(t_list *s1)
{
	while (s1->next != NULL)
	{
		if (*(int *)s1->content < *(int *)s1->next->content)
			return (0);
		s1 = s1->next;
	}
	return (1);
}
int radix_sort(t_list *s1, t_list *s2)
{
	t_list *lst, *l;
	int size;
	int	i;
	int	j;

	if (lst_isOrdered(s1) == 0)
	{
		lst = sort(s1);
		size = ft_lstsize(lst);
		j = 1;
		while (lst_isOrdered(lst) == 0)
		{	
			i = 0;
			while (i < size && lst_isOrdered(lst) == 0)
			{
				if (*(int *)ft_lstlast(lst)->content & j)
					rotate_a(&lst);
				else
					push_b(&lst, &s2);
				i++;
			}
			while (ft_lstsize(s2))
				push_a(&lst, &s2);
			j = j << 1;
		}
		l = lst;
		while (l != NULL)
		{
			free(l->content);
			lst = l->next;
			free(l);
			l = lst;
		}
	}
	return (0);
}
