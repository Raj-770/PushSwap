/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:26:15 by rpambhar          #+#    #+#             */
/*   Updated: 2024/01/08 07:28:14 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "stack.h"
# include <limits.h>

typedef struct s_sort
{
	int	moves;
	int	operation;
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
int		get_cheapest_moves(t_stack *a, t_stack *b);
void	do_cheapest_moves(t_stack *a, t_stack *b, int min_index);

void	do_ra_rb(t_stack *a, t_stack *b, int min_index);
void	do_rra_rrb(t_stack *a, t_stack *b, int min_index);
void	do_ra_rrb(t_stack *a, t_stack *b, int min_index);
void	do_rra_rb(t_stack *a, t_stack *b, int min_index);

int		check_ra_rb(t_stack *a, t_stack *b, int index);
int		check_rra_rrb(t_stack *a, t_stack *b, int index);
int		check_ra_rrb(t_stack *a, t_stack *b, int index);
int		check_rra_rb(t_stack *a, t_stack *b, int index);

int		get_position_in_b(t_stack *b, int index);
int		get_position(t_stack	*stack, int index);
int		get_min_index(t_stack *stack);
int		get_max_index(t_stack *stack);

// Freeing stack
int		free_stack(t_stack	*stack);

#endif