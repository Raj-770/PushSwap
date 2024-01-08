/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 07:19:00 by rpambhar          #+#    #+#             */
/*   Updated: 2024/01/08 07:28:00 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../includes/stack.h"
# include "../includes/pushswap.h"

void	checker_pa(t_stack *a, t_stack *b);
void	checker_pb(t_stack *a, t_stack *b);
void	checker_rrr(t_stack **a, t_stack **b);
void	checker_rr(t_stack **a, t_stack **b);

#endif