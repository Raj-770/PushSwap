/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 07:14:44 by rpambhar          #+#    #+#             */
/*   Updated: 2024/01/08 07:28:06 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_pa(t_stack *a, t_stack *b)
{
	t_list	temp;

	if (b->top != NULL)
	{
		temp = pop(b);
		push(a, temp.data, temp.index);
	}
}

void	checker_pb(t_stack *a, t_stack *b)
{
	t_list	temp;

	if (a->top != NULL)
	{
		temp = pop(a);
		push(b, temp.data, temp.index);
	}
}

void	checker_rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(*a);
	reverse_rotate(*b);
}

void	checker_rr(t_stack **a, t_stack **b)
{
	rotate(*a);
	rotate(*b);
}
