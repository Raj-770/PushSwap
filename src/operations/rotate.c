/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:57:36 by rpambhar          #+#    #+#             */
/*   Updated: 2023/12/26 22:45:00 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

static void	rotate(t_stack *stack)
{
	t_list	*first;
	t_list	*last;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		first = stack->top;
		last = stack->bottom;
		stack->top = first->next;
		first->next = NULL;
		stack->top->prev = NULL;
		last->next = first;
		first->prev = last;
		stack->bottom = first;
	}
}

void	ra(t_stack **a)
{
	rotate(*a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(*b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(*a);
	rotate(*b);
	ft_printf("rr\n");
}
