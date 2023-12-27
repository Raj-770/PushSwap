/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:26:15 by rpambhar          #+#    #+#             */
/*   Updated: 2023/12/27 07:03:47 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "stack.h"
# include <limits.h>

// Parsing
int		has_duplicate(t_stack *stack, int num);
int		is_number(const char *str);
void	parse_args(int argc, char **argv, t_stack *a);

// Algorithms
void	tiny_sort(t_stack *a);
void	mini_sort(t_stack *a, t_stack *b);

#endif