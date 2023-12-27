/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 05:39:19 by rpambhar          #+#    #+#             */
/*   Updated: 2023/12/27 07:15:33 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	tiny_sort(t_stack *a)
{
	int	f;
	int	s;
	int	t;

	f = a->top->data;
	s = a->top->next->data;
	t = a->bottom->data;
	if (f > s && t > s && f < t)
		sa(&a);
	else if (f > s && s > t)
	{
		sa(&a);
		rra(&a);
	}
	else if (f > s && t > s && f > t)
		ra(&a);
	else if (f < s && s > t && t > f)
	{
		sa(&a);
		ra(&a);
	}
	else if (f < s && s > t && t < f)
		rra(&a);
}
