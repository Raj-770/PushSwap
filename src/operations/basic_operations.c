/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:46:13 by rpambhar          #+#    #+#             */
/*   Updated: 2024/01/05 09:47:12 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	push(t_stack *stack, int number, int index)
{
	t_list	*new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (new_element == NULL)
		exit(EXIT_FAILURE);
	new_element->index = index;
	new_element->data = number;
	new_element->next = stack->top;
	new_element->prev = NULL;
	if (stack->top != NULL)
		stack->top->prev = new_element;
	stack->top = new_element;
	if (stack->bottom == NULL)
		stack->bottom = new_element;
}

t_list	pop(t_stack *stack)
{
	t_list	*temp;
	t_list	temp2;

	if (stack->top == NULL)
		exit(EXIT_FAILURE);
	temp = stack->top;
	temp2 = *temp;
	stack->top = stack->top->next;
	if (stack->top != NULL)
		stack->top->prev = NULL;
	if (stack->top == NULL)
		stack->bottom = NULL;
	free(temp);
	return (temp2);
}

int	size(t_stack *stack)
{
	t_list	*current;
	int		i;

	i = 0;
	current = stack->top;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int	is_sorted(t_stack *a)
{
	t_list	*current;

	current = a->top;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

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
