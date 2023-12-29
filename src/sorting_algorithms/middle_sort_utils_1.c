/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort_utils_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:31:41 by rpambhar          #+#    #+#             */
/*   Updated: 2023/12/29 16:08:05 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	init(t_sort *sort)
{
	sort->hold_first = NULL;
	sort->hold_second = NULL;
	sort->size_a = 0;
	sort->moves_h1 = 0;
	sort->moves_h2 = 0;
	sort->rmoves = 0;
	sort->min = 0;
	sort->max = 0;
}

void	set_hold_first(t_stack *a, t_sort *s)
{
	t_list	*current;

	current = a->top;
	s->moves_h1 = 0;
	while (current)
	{
		if (current->index >= s->min && current->index < s->max)
		{
			s->hold_first = current;
			return ;
		}
		s->moves_h1 = s->moves_h1 + 1;
		current = current->next;
	}
	s->hold_first = NULL;
}

void	set_hold_second(t_stack *a, t_sort *s)
{
	t_list	*current;

	current = a->bottom;
	s->moves_h2 = 0;
	while (current)
	{
		if (current->index >= s->min && current->index < s->max)
		{
			s->hold_second = current;
			return ;
		}
		s->moves_h2 = s->moves_h2 + 1;
		current = current->prev;
	}
	s->hold_second = NULL;
}

void	set_range(t_sort *s)
{
	int	temp;

	temp = s->size_a;
	s->min = 0;
	if (temp % 5 != 0)
		temp = temp + temp % 5;
	if (s->size_a <= 10)
		s->max = 10;
	else
	{
		s->max = temp / 5;
	}
}

void	change_range(t_sort *s)
{
	int	temp;

	temp = s->size_a;
	if (temp % 5 != 0)
		temp = temp - temp % 5;
	s->min = s->min + temp / 5;
	s->max = s->max + temp / 5;
}
