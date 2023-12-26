/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:12:02 by rpambhar          #+#    #+#             */
/*   Updated: 2023/12/26 22:50:35 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	main(void)
{
	t_stack	*a;
	t_list	*current;

	a = initialize_stack();
	push(a, 10);
	push(a, 20);
	push(a, 30);
	printf("Stack A before shift:\n");
	current = a->top;
	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
	sa(&a);
	rra(&a);
	printf("\nStack A after shift:\n");
	current = a->top;
	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
	free_stack(a);
	return (0);
}
