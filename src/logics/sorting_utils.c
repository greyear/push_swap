/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:40:50 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/01 18:08:20 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void sort_three_checks(t_stack_node **stack, int a, int b, int c)
{
	if (a < b && a < c && b < c) //123
		return ;
	else if (a < b && a < c && b > c) //132
	{
		sa(*stack);
		ra(*stack);
	}
	else if (a > b && a < c && b < c) //213
		sa(*stack);
	else if (a < b && a > c && b > c) //231
		rra(*stack);
	else if (a > b && a > c && b < c) //312
		ra(*stack);
	else if (a > b && a > c && b > c) //321
	{
		sa(*stack);
		rra(*stack);
	}   
}

void    sort_three(t_stack_node **stack)
{
	int a;
	int b;
	int c;

	a = (*stack)->n;
	b = (*stack)->next->n;
	c = (*stack)->next->next->n;
	sort_three_checks(stack, a, b, c);
}
