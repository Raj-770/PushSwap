/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 06:09:05 by rpambhar          #+#    #+#             */
/*   Updated: 2023/12/27 07:45:42 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	mini_sort(t_stack *a, t_stack *b)
{
	int	top;
	int	bottom;

	pb(a, b);
	pb(a, b);
	tiny_sort(a);
	pa(a, b);
	top = a->top->data;
	bottom = a->bottom->data;
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
	pa(a, b);
	top = a->top->data;
	bottom = a->bottom->data;
	if (top > bottom)
		ra(&a);
	else if (top > a->top->next->data && top < a->top->next->next->data)
		sa(&a);
	else if (top > a->top->next->data && top > a->top->next->next->data && top < a->bottom->prev->data)
	{
		rra(&a);
		sa(&a);
		rra(&a);
		sa(&a);
		rra(&a);
		sa(&a);
	}
	else if (top > a->top->next->data && top > a->top->next->next->data && top > a->bottom->prev->data)
	{
		rra(&a);
		sa(&a);
		rra(&a);
		rra(&a);
		rra(&a);
	}
}