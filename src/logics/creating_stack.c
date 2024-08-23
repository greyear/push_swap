/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:30:49 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/23 15:07:21 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	is_wrong_input(char *str)
{
	int	i;

	if (!ft_issign(str[0]) && !ft_isdigit(str[0]))
		return (1);
	if (ft_issign(str[0]) && !(ft_isdigit(str[1])))
		return (1);
	i = 0;
	while (str[++i])
	{
		if (!(ft_isdigit(str[i])))
			return (1);
	}
	return (0);
}

static int	ft_custom_atoi(const char *str, int *number)
{
	long	sign;
	int		i;
	long	res;

	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]) && str[i++] == '-')
		sign = -1;
	res = 0;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i++] - '0');
		if (res * sign < (long)INT_MIN || res * sign > (long)INT_MAX)
			return (1);
	}
	*number = (int)sign * res;
	return (0);
}

static int	add_node_back(t_stack **stack, int num)
{
	t_stack	*last_node;
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (1);
	new_node->n = num;
	new_node->next = NULL;
	if (!(*stack))
	{
		*stack = new_node;
	}
	else
	{
		last_node = last_elem(*stack);
		last_node->next = new_node;
	}
	return (0);
}

void	create_stack(t_stack **stack, char **num, int clean_num)
{
	int		i;
	int		err;
	int		n;

	i = 0;
	while (num[i])
	{
		if (is_wrong_input(num[i]))
			cleanup_exit(stack, num, clean_num);
		err = ft_custom_atoi(num[i], &n);
		if (err != 0)
			cleanup_exit(stack, num, clean_num);
		if (is_in_stack(*stack, n))
			cleanup_exit(stack, num, clean_num);
		if (add_node_back(stack, n) == 1)
			cleanup_exit(stack, num, clean_num);
		i++;
	}
	if (clean_num)
		free_array(num);
}

int	moves_to_top(t_stack *stack, t_stack *required_node)
{
	t_stack	*cur_node;
	int		res;

	res = 0;
	cur_node = stack;
	while (cur_node)
	{
		if (cur_node == required_node)
			break ;
		res++;
		cur_node = cur_node->next;
	}
	return (res);
}
