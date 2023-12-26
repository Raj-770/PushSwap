/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:42:36 by rpambhar          #+#    #+#             */
/*   Updated: 2023/12/26 22:49:32 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stdio.h>
# include "../lib/ft_printf/ft_printf.h"

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_stack
{
	t_list	*top;
	t_list	*bottom;
} t_stack;

// Basic Operations
t_stack	*initialize_stack(void);
void	push(t_stack *stack, int number);
int		pop(t_stack *stack);
void	free_stack(t_stack *stack);

// Swap
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// Push
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// Rotate
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// Reverse Rotate
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif