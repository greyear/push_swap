/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:52:03 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/19 19:47:28 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	sort_three_checks(t_stack **stack, int a, int b, int c)
{
	if (a < b && a < c && b < c)
		return ;
	else if (a < b && a < c && b > c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a > b && a < c && b < c)
		sa(stack);
	else if (a < b && a > c && b > c)
		rra(stack);
	else if (a > b && a > c && b < c)
		ra(stack);
	else if (a > b && a > c && b > c)
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->n;
	b = (*stack)->next->n;
	c = (*stack)->next->next->n;
	sort_three_checks(stack, a, b, c);
}
