/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:55:15 by rpambhar          #+#    #+#             */
/*   Updated: 2023/12/29 16:08:14 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	middle_sort(t_stack *a, t_stack *b)
{
	t_sort	s;

	init(&s);
	s.size_a = size(a);
	set_range(&s);
	if (!is_sorted(a))
	{
		while (a->top)
		{
			set_hold_first(a, &s);
			set_hold_second(a, &s);
			if (!s.hold_first && !s.hold_second && s.min < s.size_a)
			{
				change_range(&s);
				continue ;
			}
			if (s.moves_h1 <= s.moves_h2)
				push_h1(a, b, &s);
			else
				push_h2(a, b, &s);
		}
		push_back(a, b, &s);
	}
}
