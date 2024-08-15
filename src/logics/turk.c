/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:41:41 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/15 17:54:20 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rr_and_refresh(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rr(a, b);
	put_index(*a);
	put_index(*b);
}

static void	rrr_and_refresh(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rrr(a, b);
	put_index(*a);
	put_index(*b);
}

static void	push_cheapest_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;
	t_stack_node	*target;

	cheapest = cheapest_node(*a);
	target = cheapest->target;
	if (above_median(*a, cheapest) && above_median(*b, target))
		rr_and_refresh(a, b, cheapest);
	else if (!above_median(*a, cheapest) && !above_median(*b, target))
		rrr_and_refresh(a, b, cheapest);
	make_top_a(a, cheapest);
	make_top_b(b, target);
	pb(a, b);
}

static void	push_cheapest_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*target;

	target = (*b)->target;
	make_top_a(a, target);
	pa(a, b);
}
//how to apply above_median function?
static void	min_first(t_stack_node **stack)
{
	t_stack_node	*min;
	int				median;

	median = stack_len(*stack) / 2;
	min = min_elem(*stack);
	while (*stack != min)
	{
		if ((min)->index <= median)
			ra(stack);
		else
			rra(stack);
	}
}

static void	sort_more(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = stack_len(*a);
	//Need more explanations about if-if-while with same condition
	if (!is_sorted(*a) && len-- > 3)
		pb(a, b);
	if (!is_sorted(*a) && len-- > 3)
		pb(a, b); //How not to double code??
	while (!is_sorted(*a) && len-- > 3)
	{
		put_fields_a(*a, *b);
		push_cheapest_to_b(a, b);
	}
	sort_three(a);
	while (*b != NULL)
	{
		put_fields_b(*a, *b);
		push_cheapest_to_a(a, b);
	}
	put_index(*a);
	min_first(a);
}

void	sort_all(t_stack_node **a, t_stack_node **b)
{
	if (!is_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			sort_more(a, b);
	}
}
