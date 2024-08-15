/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_costs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   cur_by: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:05:03 cur_by azinchen          #+#    #+#             */
/*   Updated: 2024/08/06 14:33:07 cur_by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//more than 5 functions here!

static int	moves_to_top(t_stack_node *stack, t_stack_node *required_node)
//Is it necessary to have **stack here? Cause we don't change anything in it
{
	t_stack_node	*cur_node;
	int				res;
	//protections? !stack, !required_node. what to return, -1?
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

void make_top_a(t_stack_node **stack, t_stack_node *future_top)//static?
{
	//protections? !stack, !(*stack), !future_top
	int				size;
	int				moves_up;
	int				moves_down;

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
void make_top_b(t_stack_node **stack, t_stack_node *future_top)//static?
{
	//protections? !stack, !(*stack), !future_top
	int				size;
	int				moves_up;
	int				moves_down;

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

static void	target_in_b(t_stack_node *a, t_stack_node *b)
{
	long			closest_smaller;
	t_stack_node	*target;
	t_stack_node	*cur_b;
	
	while (a)
	{
		closest_smaller = LONG_MIN;
		cur_b = b;
		while (cur_b)
		{
			if (cur_b->n < a->n && cur_b->n > closest_smaller)
			{
				closest_smaller = cur_b->n;
				target = cur_b;
			}
			cur_b = cur_b->next;
		}
		if 	(closest_smaller == LONG_MIN)
			a->target = max_elem(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	target_in_a(t_stack_node *a, t_stack_node *b)
{
	long			closest_bigger;
	t_stack_node	*target;
	t_stack_node	*cur_a;
	
	while (b)
	{
		closest_bigger = LONG_MAX;
		cur_a = a;
		while (cur_a)
		{
			if (cur_a->n > b->n && cur_a->n < closest_bigger)
			{
				closest_bigger = cur_a->n;
				target = cur_a;
			}
			cur_a = cur_a->next;
		}
		if 	(closest_bigger == LONG_MAX)
			b->target = min_elem(a);
		else
			b->target = target;
		b = b->next;
	}
}

static int	push_cost_one(t_stack_node *stack, t_stack_node *required_node)
{
	int	size;
	int	moves_up;

	if (!stack || !required_node)
		return (-1); //-1?
	size = stack_len(stack);
	moves_up = moves_to_top(stack, required_node);
	if (moves_up == 0)
		return (0);
	else if (moves_up <= (size / 2))
		return (moves_up);
	//Do we need else?
	return (size - moves_up);
}

void	push_cost_both(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cur_a;

	if (!a || !b)
		return ; //-1 and int output?
	cur_a = a;
	while (cur_a)
	{
		cur_a->cost = push_cost_one(a, cur_a);
		//Do we need any check for a->target? What if it doesn't exist?
		cur_a->cost += push_cost_one(b, cur_a->target);
		cur_a = cur_a->next;
	}
}

t_stack_node *cheapest_node(t_stack_node *stack)
//I united 2 functions in one and I don't have bool member cheapest in struct
{
	long	min_cost;
	t_stack_node *res;

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

void	put_fields_a(t_stack_node *a, t_stack_node *b)
{
	put_index(a);
	put_index(b);
	target_in_b(a, b);
	push_cost_both(a, b);
}

void	put_fields_b(t_stack_node *a, t_stack_node *b)
{
	put_index(a);
	put_index(b);
	target_in_a(a, b);
}
