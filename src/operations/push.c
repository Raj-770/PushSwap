/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:37:37 by rpambhar          #+#    #+#             */
/*   Updated: 2024/01/05 09:48:36 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	pa(t_stack *a, t_stack *b)
{
	t_list	temp;

	if (b->top != NULL)
	{
		temp = pop(b);
		push(a, temp.data, temp.index);
	}
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	t_list	temp;

	if (a->top != NULL)
	{
		temp = pop(a);
		push(b, temp.data, temp.index);
	}
	ft_printf("pb\n");
}
