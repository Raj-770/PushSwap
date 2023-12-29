/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:59:28 by rpambhar          #+#    #+#             */
/*   Updated: 2023/12/29 16:07:41 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	push_h1(t_stack *a, t_stack *b, t_sort *s)
{
	int	i;

	i = 0;
	while (i < s->moves_h1)
	{
		ra(&a);
		i++;
	}
	pb(a, b);
}

void	push_h2(t_stack	*a, t_stack *b, t_sort	*s)
{
	int	i;

	i = 0;
	while (i < s->moves_h2)
	{
		rra(&a);
		i++;
	}
	rra(&a);
	pb(a, b);
}

void	push_back(t_stack *a, t_stack *b, t_sort *s)
{
	t_list	*max;

	while (b->top)
	{
		max = find_max_element(b);
		s->rmoves = find_rmoves(b, max);
		push_max_element(a, b, s);
	}
}

int	find_rmoves(t_stack *b, t_list *max)
{
	t_list	*current;
	int		ret;

	ret = 0;
	current = b->top;
	while (current->data != max->data)
	{
		ret++;
		current = current->next;
	}
	return (ret);
}

void	push_max_element(t_stack *a, t_stack *b, t_sort *s)
{
	int	i;

	i = 0;
	while (i < s->rmoves)
	{
		rb(&b);
		i++;
	}
	pa(a, b);
}
