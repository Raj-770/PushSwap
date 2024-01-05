/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort_utils_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:02:46 by rpambhar          #+#    #+#             */
/*   Updated: 2024/01/05 09:55:05 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	check_ra_rb(t_stack *a, t_stack *b, int index)
{
	int	i;

	i = get_position_in_b(b, index);
	if (i < get_position(a, index))
		i = get_position(a, index);
	return (i);
}

int	check_rra_rrb(t_stack *a, t_stack *b, int index)
{
	int	i;

	i = size(b) - get_position_in_b(b, index);
	if (i < size(a) - get_position(a, index))
		i = size(a) - get_position(a, index);
	return (i);
}

int	check_ra_rrb(t_stack *a, t_stack *b, int index)
{
	int	i;

	i = size(b) - get_position_in_b(b, index);
	i = get_position(a, index) + i;
	return (i);
}

int	check_rra_rb(t_stack *a, t_stack *b, int index)
{
	int	i;

	i = get_position_in_b(b, index);
	i = size(a) - get_position(a, index) + i;
	return (i);
}
