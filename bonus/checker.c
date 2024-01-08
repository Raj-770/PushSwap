/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:46:46 by rpambhar          #+#    #+#             */
/*   Updated: 2024/01/08 07:27:41 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	do_cmd(t_stack *a, t_stack *b, char *cmd);

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*cmd;

	if (argc < 2)
		exit(EXIT_FAILURE);
	parse_args(argc, argv, &a);
	cmd = get_next_line(STDIN_FILENO);
	while (cmd)
	{
		do_cmd(&a, &b, cmd);
		free(cmd);
		cmd = get_next_line(0);
	}
	if (size(&a) != 0 && is_sorted(&a) && size(&b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}

static void	do_cmd(t_stack *a, t_stack *b, char *cmd)
{
	if (ft_strncmp(cmd, "pa\n", 3) == 0)
		checker_pa(a, b);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		checker_pb(a, b);
	else if (ft_strncmp(cmd, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		ss(&a, &b);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rotate(b);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		checker_rr(&a, &b);
	else if (ft_strncmp(cmd, "rra\n", 3) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(cmd, "rbb\n", 3) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(cmd, "rrr\n", 3) == 0)
		checker_rrr(&a, &b);
	else
		exit(free_stack(a) + free_stack(b) + EXIT_FAILURE);
}
