/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:40:32 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/19 20:14:28 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*cur_node;

	if (!stack)
		return (1);
	cur_node = stack;
	while (cur_node->next)
	{
		if (cur_node->n > cur_node->next->n)
			return (0);
		cur_node = cur_node->next;
	}
	return (1);
}

int	stack_len(t_stack *stack)
{
	int		len;
	t_stack	*cur_node;

	if (!stack)
		return (0);
	len = 0;
	cur_node = stack;
	while (cur_node)
	{
		cur_node = cur_node->next;
		len++;
	}
	return (len);
}

int	above_median(t_stack *stack, t_stack *checked_node)
{
	int	median;

	median = stack_len(stack) / 2;
	if (checked_node->index <= median)
		return (1);
	return (0);
}
