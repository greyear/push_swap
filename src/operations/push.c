/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:05:45 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/19 18:23:14 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*buf;

	if (!*src)
		return ;
	buf = *src;
	*src = (*src)->next;
	if (!*dst)
	{
		*dst = buf;
		(*dst)->next = NULL;
	}
	else
	{
		buf->next = *dst;
		*dst = buf;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pb\n");
}
