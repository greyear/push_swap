/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:40:32 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/01 18:08:33 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int is_sorted(t_stack_node *stack)
{
	t_stack_node    *cur_node;
	
	if (!stack)
		return (1); //what should I return if there's no stack?
	cur_node = stack;
	while (cur_node->next)
	{
		if (cur_node->n > cur_node->next->n)
			return (0);
		cur_node = cur_node->next;
	}
	return (1);
}

t_stack_node    *last_elem(t_stack_node *stack)
{
	t_stack_node    *cur_node;
	
	if (!stack)
		return (NULL);
	cur_node = stack;
	while (cur_node->next)
		cur_node = cur_node->next;
	return (cur_node);
}

t_stack_node    *min_elem(t_stack_node *stack)
{
	t_stack_node    *cur_node;
	t_stack_node    *min_node;
	int min_val; //in repo long is used here, dk for what, cz for empty list we anyway return NULL
	
	if (!stack)
		return (NULL);
	min_node = stack;
	min_val = min_node->n;
	cur_node = stack;
	while (cur_node->next)
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

t_stack_node    *max_elem(t_stack_node *stack)
{
	t_stack_node    *cur_node;
	t_stack_node    *max_node;
	int max_val;
	
	if (!stack)
		return (NULL);
	max_node = stack;
	max_val = max_node->n;
	cur_node = stack;
	while (cur_node->next)
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

int stack_len(t_stack_node *stack)
{
	int len;
	t_stack_node    *cur_node;

	if (!stack)
		return (0);
	len = 0;
	cur_node = stack;
	while(cur_node)
	{
		cur_node = cur_node->next;
		len++;
	}
	return (len);
}
