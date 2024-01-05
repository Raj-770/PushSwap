/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort_utils_4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 07:41:11 by rpambhar          #+#    #+#             */
/*   Updated: 2024/01/05 09:55:44 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	get_position_in_b(t_stack *b, int index)
{
	int		pos;
	t_list	*top;
	t_list	*bottom;

	pos = 1;
	top = b->top;
	bottom = b->bottom;
	if (index > top->index && index < bottom->index)
		pos = 0;
	else if (index > get_max_index(b) || index < get_min_index(b))
	{
		pos = get_position(b, get_max_index(b));
	}
	else
	{
		while (top != NULL && top->next != NULL)
		{
			if (index < top->index && index > top->next->index)
				break ;
			pos++;
			top = top->next;
		}
	}
	return (pos);
}

int	get_min_index(t_stack *stack)
{
	t_list	*current;
	int		min_index;

	min_index = INT_MAX;
	current = stack->top;
	while (current)
	{
		if (current->index < min_index)
			min_index = current->index;
		current = current->next;
	}
	return (min_index);
}

int	get_max_index(t_stack *stack)
{
	t_list	*current;
	int		max_index;

	max_index = -1;
	current = stack->top;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}

int	get_position(t_stack	*stack, int index)
{
	int		pos;
	t_list	*current;

	current = stack->top;
	pos = 0;
	while (current)
	{
		if (current->index == index)
			return (pos);
		current = current->next;
		pos++;
	}
	return (pos);
}
