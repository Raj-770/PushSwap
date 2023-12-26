/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:46:13 by rpambhar          #+#    #+#             */
/*   Updated: 2023/12/26 21:39:50 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

t_stack	*initialize_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit(EXIT_FAILURE);
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

void	push(t_stack *stack, int number)
{
	t_list	*new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (new_element == NULL)
		exit(EXIT_FAILURE);
	new_element->data = number;
	new_element->next = stack->top;
	new_element->prev = NULL;
	if (stack->top != NULL)
		stack->top->prev = new_element;
	stack->top = new_element;
	if (stack->bottom == NULL)
		stack->bottom = new_element;
}

int	pop(t_stack *stack)
{
	int		popped_data;
	t_list	*temp;

	if (stack->top == NULL)
		exit(EXIT_FAILURE);
	popped_data = stack->top->data;
	temp = stack->top;
	stack->top = stack->top->next;
	if (stack->top != NULL)
		stack->top->prev = NULL;
	if (stack->top == NULL)
		stack->bottom = NULL;
	free(temp);
	return (popped_data);
}

void	free_stack(t_stack *stack)
{
	t_list	*temp;

	while (stack->top != NULL)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
}
