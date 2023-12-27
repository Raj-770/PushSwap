/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 06:09:05 by rpambhar          #+#    #+#             */
/*   Updated: 2023/12/27 08:49:28 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

static void	set_fourth_element(t_stack *a, int top, int bottom)
{
	if (top > bottom)
		ra(&a);
	else if (top > a->top->next->data && top < a->top->next->next->data)
		sa(&a);
	else if (top > a->top->next->data && top > a->top->next->next->data)
	{
		sa(&a);
		ra(&a);
		sa(&a);
		rra(&a);
	}
}

static void	set_fifth_element(t_stack *a, int top, int bottom)
{
	if (top > bottom)
		ra(&a);
	else if (top > a->top->next->data && top < a->top->next->next->data)
		sa(&a);
	else if (top > a->top->next->data && top > a->top->next->next->data && \
	top < a->bottom->prev->data)
	{
		rra(&a);
		sa(&a);
		rra(&a);
		sa(&a);
		rra(&a);
		sa(&a);
	}
	else if (top > a->top->next->data && top > a->top->next->next->data && \
	top > a->bottom->prev->data)
	{
		rra(&a);
		sa(&a);
		rra(&a);
		rra(&a);
		rra(&a);
	}
}

void	mini_sort(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
	tiny_sort(a);
	pa(a, b);
	set_fourth_element(a, a->top->data, a->bottom->data);
	pa(a, b);
	set_fifth_element(a, a->top->data, a->bottom->data);
}
