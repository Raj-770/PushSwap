/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort_utils_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:31:41 by rpambhar          #+#    #+#             */
/*   Updated: 2024/01/05 09:51:26 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static t_sort	find_cheapest_moves(t_stack *a, t_stack *b, int index);

int	get_cheapest_moves(t_stack *a, t_stack *b)
{
	int		min_moves;
	int		min_index;
	t_list	*current;
	t_sort	info;

	current = a->top;
	info = find_cheapest_moves(a, b, current->index);
	min_moves = info.moves;
	min_index = current->index;
	current = current->next;
	while (current)
	{
		info = find_cheapest_moves(a, b, current->index);
		if (info.moves < min_moves)
		{
			min_moves = info.moves;
			min_index = current->index;
		}
		current = current->next;
	}
	return (min_index);
}

static t_sort	find_cheapest_moves(t_stack *a, t_stack *b, int index)
{
	t_sort	info;
	int		moves;

	info.moves = check_ra_rb(a, b, index);
	info.operation = 1;
	moves = check_rra_rrb(a, b, index);
	if (moves < info.moves)
	{
		info.moves = moves;
		info.operation = 2;
	}
	moves = check_ra_rrb(a, b, index);
	if (moves < info.moves)
	{
		info.moves = moves;
		info.operation = 3;
	}
	moves = check_rra_rb(a, b, index);
	if (moves < info.moves)
	{
		info.moves = moves;
		info.operation = 4;
	}
	return (info);
}

void	do_cheapest_moves(t_stack *a, t_stack *b, int min_index)
{
	t_sort	info;

	info = find_cheapest_moves(a, b, min_index);
	if (info.operation == 1)
		do_ra_rb(a, b, min_index);
	if (info.operation == 2)
		do_rra_rrb(a, b, min_index);
	if (info.operation == 3)
		do_ra_rrb(a, b, min_index);
	if (info.operation == 4)
		do_rra_rb(a, b, min_index);
}
