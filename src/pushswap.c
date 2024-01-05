/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:12:02 by rpambhar          #+#    #+#             */
/*   Updated: 2024/01/05 10:04:25 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		a_size;

	if (argc >= 2)
	{
		parse_args(argc, argv, &a);
		set_index(&a);
		a_size = size(&a);
		if (a_size == 3 || a_size == 2)
			tiny_sort(&a);
		else if (a_size == 5 || a_size == 4)
			mini_sort(&a, &b);
		else
			middle_sort(&a, &b);
	}
	return (0);
}
