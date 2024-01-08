/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 05:42:52 by rpambhar          #+#    #+#             */
/*   Updated: 2024/01/08 07:12:11 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	is_number(const char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	has_duplicate(t_stack *stack, int num)
{
	t_list	*current;

	current = stack->top;
	while (current != NULL)
	{
		if (current->data == num)
			return (1);
		current = current->next;
	}
	return (0);
}

int	free_stack(t_stack	*stack)
{
	t_list	*temp;

	while (stack->top != NULL)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
	return (0);
}
