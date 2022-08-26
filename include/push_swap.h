/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:03:48 by danicn            #+#    #+#             */
/*   Updated: 2022/08/26 15:09:13 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
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




#endif