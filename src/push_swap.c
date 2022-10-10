/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:51:31 by danicn            #+#    #+#             */
/*   Updated: 2022/10/10 22:14:13 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

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
	if (argc == 5)
		four_nums(s1, s2);
	if (argc == 6)
		five_nums(s1, s2);
	return (0);
}

void	args_err(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_strlen(argv[i]) > 11)
			exit_error();
		j = 0;
		while (argv[i][j] != 0)
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
				exit_error();
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack1;
	t_list	*stack2;

	if (argc < 2)
		return (1);
	args_err(argv);
	if (init_stacks(&stack1, &stack2, argv, argc) > 0)
		exit_error();
	if (lst_isOrdered(stack1) == 0)
	{
		if (argc < 7)
			less_than_six(&stack1, &stack2, argc);
		else
		{
			radix_sort(stack1, stack2);
			return (0);
		}
	}
	ft_lstclear(&stack1, int_free);
	ft_lstclear(&stack2, int_free);
}
