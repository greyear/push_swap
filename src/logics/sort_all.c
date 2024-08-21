/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:41:41 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/21 17:32:19 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push_cheapest_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	t_stack	*target;

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

static void	push_cheapest_to_a(t_stack **a, t_stack **b)
{
	t_stack	*target;

	target = (*b)->target;
	make_top_a(a, target);
	pa(a, b);
}

static void	min_first(t_stack **stack)
{
	t_stack	*min;
	int		median;

	median = stack_len(*stack) / 2;
	min = min_elem(*stack);
	while (*stack != min)
	{
		if (min->index <= median)
			ra(stack);
		else
			rra(stack);
	}
}

static void	sort_more(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(*a);
	if (!is_sorted(*a) && len-- > 3)
		pb(a, b);
	if (!is_sorted(*a) && len-- > 3)
		pb(a, b);
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

void	sort_all(t_stack **a, t_stack **b)
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
