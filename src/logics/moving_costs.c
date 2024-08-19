/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_costs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:02:40 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/19 20:41:54 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	make_top_a(t_stack **stack, t_stack *future_top)//static?
{
	int	size;
	int	moves_up;
	int	moves_down;

	//protections? !stack, !(*stack), !future_top
	size = stack_len(*stack);
	moves_up = moves_to_top(*stack, future_top);
	moves_down = size - moves_up;
	if (moves_up == 0)
		return ;
	if (moves_up <= (size / 2))
	{
		while (moves_up--)
			ra(stack);
	}
	else
	{
		while (moves_down--)
			rra(stack);
	}
}

//can I combine these 2 functions without using damn extra field above_median? 
void	make_top_b(t_stack **stack, t_stack *future_top)//static?
{
	int	size;
	int	moves_up;
	int	moves_down;

	//protections? !stack, !(*stack), !future_top
	size = stack_len(*stack);
	moves_up = moves_to_top(*stack, future_top);
	moves_down = size - moves_up;
	if (moves_up == 0)
		return ;
	if (moves_up <= (size / 2))
	{
		while (moves_up--)
			rb(stack);
	}
	else
	{
		while (moves_down--)
			rrb(stack);
	}
}

static int	push_cost_one(t_stack *stack, t_stack *required_node)
{
	int	size;
	int	moves_up;

	if (!stack || !required_node)
		return (-1); //?
	size = stack_len(stack);
	moves_up = moves_to_top(stack, required_node);
	if (moves_up == 0)
		return (0);
	if (moves_up <= (size / 2))
		return (moves_up);
	return (size - moves_up);
}

void	push_cost_both(t_stack *a, t_stack *b)//-1 and int output?
{
	t_stack	*cur_a;

	if (!a || !b)
		return ;
	cur_a = a;
	while (cur_a)
	{
		cur_a->cost = push_cost_one(a, cur_a);
		//Do we need any check for a->target? What if it doesn't exist?
		cur_a->cost += push_cost_one(b, cur_a->target);
		cur_a = cur_a->next;
	}
}

t_stack	*cheapest_node(t_stack *stack)
{
	long	min_cost;
	t_stack	*res;

	if (!stack)
		return (NULL);
	min_cost = LONG_MAX;
	while (stack)
	{
		if (stack->cost < min_cost)
		{
			res = stack;
			min_cost = stack->cost;
		}
		stack = stack->next;
	}
	return (res);
}
