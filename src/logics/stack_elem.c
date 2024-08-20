/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:48:26 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/19 20:40:45 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*last_elem(t_stack *stack)
{
	t_stack	*cur_node;

	if (!stack)
		return (NULL);
	cur_node = stack;
	while (cur_node->next)
		cur_node = cur_node->next;
	return (cur_node);
}

t_stack	*min_elem(t_stack *stack)
{
	t_stack	*cur_node;
	t_stack	*min_node;
	int		min_val;

	if (!stack)
		return (NULL);
	min_node = stack;
	min_val = min_node->n;
	cur_node = stack;
	while (cur_node)
	{
		if (cur_node->n < min_val)
		{
			min_node = cur_node;
			min_val = min_node->n;
		}
		cur_node = cur_node->next;
	}
	return (min_node);
}

t_stack	*max_elem(t_stack *stack)
{
	t_stack	*cur_node;
	t_stack	*max_node;
	int		max_val;

	if (!stack)
		return (NULL);
	max_node = stack;
	max_val = max_node->n;
	cur_node = stack;
	while (cur_node)
	{
		if (cur_node->n > max_val)
		{
			max_node = cur_node;
			max_val = max_node->n;
		}
		cur_node = cur_node->next;
	}
	return (max_node);
}
