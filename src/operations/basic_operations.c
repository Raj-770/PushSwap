/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:46:13 by rpambhar          #+#    #+#             */
/*   Updated: 2023/12/29 16:05:35 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	push(t_stack *stack, int number)
{
	t_list	*new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (new_element == NULL)
		exit(EXIT_FAILURE);
	new_element->index = 0;
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

// void	print_stack(t_stack *stack)
// {
// 	t_list	*current;

// 	current = stack->top;
// 	while (current)
// 	{
// 		printf("%d ", current->data);
// 		current = current->next;
// 	}
// 	printf("\n");
// }

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

t_list	*find_max_element(t_stack *b)
{
	t_list	*current;
	t_list	*max_element;

	current = b->top;
	max_element = current;
	while (current)
	{
		if (current->data > max_element->data)
		{
			max_element = current;
		}
		current = current->next;
	}
	return (max_element);
}
