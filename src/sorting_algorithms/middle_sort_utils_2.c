/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:59:28 by rpambhar          #+#    #+#             */
/*   Updated: 2024/01/05 09:54:18 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	do_ra_rb(t_stack *a, t_stack *b, int min_index)
{
	while (a->top->index != min_index && get_position_in_b(b, min_index) > 0)
		rr(&a, &b);
	while (a->top->index != min_index)
		ra(&a);
	while (get_position_in_b(b, min_index) > 0)
		rb(&b);
}

void	do_rra_rrb(t_stack *a, t_stack *b, int min_index)
{
	int	i;
	int	j;

	j = get_position_in_b(b, min_index);
	i = size(b);
	while (j != 0 && a->top->index != min_index
		&& i - get_position_in_b(b, min_index) > 0)
	{
		rrr(&a, &b);
		j = get_position_in_b(b, min_index);
	}
	while (a->top->index != min_index)
	{
		rra(&a);
	}
	while (i - get_position_in_b(b, min_index))
	{
		if (get_position_in_b(b, min_index) == 0)
			break ;
		rrb(&b);
	}
}

void	do_ra_rrb(t_stack *a, t_stack *b, int min_index)
{
	int	i;

	i = size(b);
	while (a->top->index != min_index)
		ra(&a);
	while (i - get_position_in_b(b, min_index) > 0)
	{
		if (get_position_in_b(b, min_index) == 0)
			break ;
		rrb(&b);
	}
}

void	do_rra_rb(t_stack *a, t_stack *b, int min_index)
{
	while (a->top->index != min_index)
		rra(&a);
	while (get_position_in_b(b, min_index) > 0)
		rb(&b);
}
