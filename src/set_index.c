/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:09:31 by rpambhar          #+#    #+#             */
/*   Updated: 2023/12/29 16:05:14 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	set_index(t_stack *stack)
{
	t_list	*current_i;
	t_list	*current_j;

	current_i = stack->top;
	while (current_i)
	{
		current_j = stack->top;
		while (current_j)
		{
			if (current_i->data > current_j->data)
				current_i->index++;
			current_j = current_j->next;
		}
		current_i = current_i->next;
	}
}
