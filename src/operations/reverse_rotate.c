/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:25:28 by rpambhar          #+#    #+#             */
/*   Updated: 2024/01/08 07:23:13 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	reverse_rotate(t_stack *stack)
{
	t_list	*last;
	t_list	*first;
	t_list	*temp;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		last = stack->bottom;
		first = stack->top;
		last->prev->next = NULL;
		temp = last->prev;
		last->next = first;
		last->prev = NULL;
		first->prev = last;
		stack->top = last;
		stack->bottom = temp;
	}
}

void	rra(t_stack **a)
{
	reverse_rotate(*a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(*b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(*a);
	reverse_rotate(*b);
	ft_printf("rrr\n");
}
