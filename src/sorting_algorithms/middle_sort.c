/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:55:15 by rpambhar          #+#    #+#             */
/*   Updated: 2024/01/05 09:50:14 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static void	calculate_and_move(t_stack *a, t_stack *b);
static void	arrange_max(t_stack *b);
static void	push_back(t_stack *a, t_stack *b);

void	middle_sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	pb(a, b);
	if (!is_sorted(a))
		pb(a, b);
	calculate_and_move(a, b);
	arrange_max(b);
	push_back(a, b);
}

static void	calculate_and_move(t_stack *a, t_stack *b)
{
	int	min_index;

	while (size(a) > 0)
	{
		min_index = get_cheapest_moves(a, b);
		do_cheapest_moves(a, b, min_index);
		pb(a, b);
	}
}

static void	push_back(t_stack *a, t_stack *b)
{
	while (b->top)
		pa(a, b);
}

static void	arrange_max(t_stack *b)
{
	int		max;
	int		i;
	t_list	*current;

	current = b->top;
	max = get_max_index(b);
	i = 0;
	while (current->index != max)
	{
		current = current->next;
		i++;
	}
	while (b->top != current)
	{
		if (i < size(b) / 2)
			rb(&b);
		else
			rrb(&b);
	}
}
