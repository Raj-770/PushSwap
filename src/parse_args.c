/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:03:49 by rpambhar          #+#    #+#             */
/*   Updated: 2023/12/29 15:54:17 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static int	num_count(char *str)
{
	int	i;
	int	nc;

	i = 0;
	nc = 0;
	while (str[i])
	{
		if (str[i] != '-' && !ft_isdigit(str[i]))
		{
			ft_printf("Error");
			exit(EXIT_FAILURE);
		}
		if (str[i] == '-' && str[i + 1] != '-')
			i++;
		if (ft_isdigit(str[i]))
			nc++;
		while (ft_isdigit(str[i]) == 1)
			i++;
		if (str[i] == ' ' || str[i] == '\t')
			i++;
	}
	return (nc);
}

static void	handel_character_inputs(char *arg, t_stack *a)
{
	int	num;

	if (!is_number(arg))
	{
		ft_printf("Error C");
		exit(EXIT_FAILURE);
	}
	num = ft_atoi(arg);
	if (has_duplicate(a, num))
	{
		ft_printf("Error D");
		exit(EXIT_FAILURE);
	}
	if (num > INT_MAX)
	{
		ft_printf("Error E");
		exit(EXIT_FAILURE);
	}
	push(a, num);
}

static void	handel_string_inputs(char *arg, t_stack *a)
{
	char	**nums;
	int		i;

	nums = ft_split(arg, ' ');
	i = 0;
	while (nums[i])
		i++;
	i--;
	if (nums == NULL)
	{
		ft_printf("Error A");
		exit(EXIT_FAILURE);
	}
	while (i >= 0)
	{
		handel_character_inputs(nums[i], a);
		free(nums[i]);
		i--;
	}
	free(nums);
}

void	parse_args(int argc, char **argv, t_stack *a)
{
	int		i;
	int		nc;

	i = argc - 1;
	while (i > 0)
	{
		nc = num_count(argv[i]);
		if (num_count(argv[i]) == 0)
		{
			ft_printf("Error B");
			exit(EXIT_FAILURE);
		}
		else if (num_count(argv[i]) == 1)
			handel_character_inputs(argv[i], a);
		else
			handel_string_inputs(argv[i], a);
		i--;
	}
}
