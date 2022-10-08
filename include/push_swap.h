/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:03:48 by danicn            #+#    #+#             */
/*   Updated: 2022/10/04 19:15:48 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		init_stacks(t_list **stack1, t_list **stack2, char **argv, int argc);
int		swap_a(t_list **list);
void	int_free(void *num);
int		swap_b(t_list **list);
int		swap_ab(t_list **list, t_list **list2);
int		swap(t_list **list);
int		push_a(t_list **s1, t_list **s2);
int		push_b(t_list **s1, t_list **s2);
int     rotate_a(t_list **s1);
int     rotate_b(t_list **s1);
int     rotate(t_list **s1);
int     rotate_rr(t_list **s1, t_list **s2);
int     rrotate_a(t_list **s1);
int     rrotate_b(t_list **s1);
int     rrotate_rr(t_list **s1, t_list **s2);
int     rrotate_a(t_list **s1);
int     rrotate_(t_list **s1);
int     less_than_six(t_list **s1, t_list **s2, int argc);
void    three_nums(t_list **s1);
void     four_nums(t_list **s1, t_list **s2);
void     five_nums(t_list **s1, t_list **s2);
int     radix_sort(t_list *s1, t_list *s2);
int     lst_isOrdered(t_list *s1);
void	insertion_sort(int arr[], int n);

#endif