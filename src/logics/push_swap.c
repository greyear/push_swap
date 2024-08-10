/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:07:35 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/10 19:22:36 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int main(int argc, char *argv[])
{
	t_stack_node    *a;
	t_stack_node    *b;

	a = NULL;
	b = NULL;
	
	if (argc == 1 || (argc == 2 && !argv[1][0])) //second argument is what exactly? \0?
		return (1); //error message code? can be -1?
	else if (argc == 2)
		argv  = custom_split(argv[1], ' '); //nuzhen ne ft_split, a split!
	create_stack(&a, argv + 1); //I don't understand why +1 WHEN WE HAVE 2 ARGUMENTS
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_more(&a, &b);
	}
	free_stack(&a);
	//why shouldn't we free b?
	//free_stack(&b);
	return (0);
}
