/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:26:15 by rpambhar          #+#    #+#             */
/*   Updated: 2023/12/29 16:04:00 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "stack.h"
# include <limits.h>

typedef struct s_sort
{
	t_list	*hold_first;
	t_list	*hold_second;
	int		size_a;
	int		change_r;
	int		moves_h1;
	int		moves_h2;
	int		rmoves;
	int		min;
	int		max;
}	t_sort;

// Parsing
int		has_duplicate(t_stack *stack, int num);
int		is_number(const char *str);
void	parse_args(int argc, char **argv, t_stack *a);

// Algorithms
void	tiny_sort(t_stack *a);
void	mini_sort(t_stack *a, t_stack *b);
void	middle_sort(t_stack *a, t_stack *b);

// Middle Sort Utils
void	init(t_sort *sort);
void	set_hold_first(t_stack *a, t_sort *s);
void	set_hold_second(t_stack *a, t_sort *s);
void	change_range(t_sort *s);
void	set_range(t_sort *s);
void	push_h1(t_stack *a, t_stack *b, t_sort *s);
void	push_h2(t_stack	*a, t_stack *b, t_sort	*s);
void	push_back(t_stack *a, t_stack *b, t_sort *s);
int		find_rmoves(t_stack *b, t_list *max);
void	push_max_element(t_stack *a, t_stack *b, t_sort *s);

// Set Index
void	set_index(t_stack *stack);

#endif