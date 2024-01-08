/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:37:42 by rpambhar          #+#    #+#             */
/*   Updated: 2024/01/08 07:23:02 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		first = stack->top;
		second = stack->top->next;
		first->next = second->next;
		if (second->next != NULL)
			second->next->prev = first;
		second->next = first;
		second->prev = NULL;
		first->prev = second;
		stack->top = second;
	}
}

void	sa(t_stack **a)
{
	swap(*a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(*b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
	ft_printf("ss\n");
}
