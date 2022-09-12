/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:51:31 by danicn            #+#    #+#             */
/*   Updated: 2022/09/12 22:34:44 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	int_free(void *num)
{
	free(num);
}

int	init_stacks(t_list **stack1, t_list **stack2, char **argv, int argc)
{
	int		*num;
	t_list	*list;

	num = (int *) malloc(sizeof(int));
	if (!num)
		return (1);
	*num = ft_atoi(argv[argc - 1]);
	*stack1 = ft_lstnew(num);
	if (!*stack1)
		return (1);
	*stack2 = NULL;
	argc--;
	while (--argc >= 1)
	{
		num = (int *) malloc(sizeof(int));
		if (num == NULL) 
			return (1);
		*num = ft_atoi(argv[argc]);
		list = ft_lstnew(num);
		if (!list)
			return (1);
		ft_lstadd_back(stack1, list);
	}
	return (0);
}

int	less_than_six(t_list **s1, t_list **s2, int argc)
{
	if (argc == 3)
	{
		if (*(int *)(*s1)->content < *(int *)(*s1)->next->content)
			swap_a(s1);
	}
	if (argc == 4)
		three_nums(s1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*stack1;
	t_list	*stack2;

	if (argc < 2)
	{		
		write(2, "Error\n", 6);
		return (1);		
	}
	if (init_stacks(&stack1, &stack2, argv, argc) > 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc < 7)
		less_than_six(&stack1, &stack2, argc);
	ft_lstclear(&stack1, int_free);
	ft_lstclear(&stack2, int_free);
}