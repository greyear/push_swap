/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:07:35 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/01 18:16:48 by azinchen         ###   ########.fr       */
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
		argv  = ft_split(argv[1], ' '); //nuzhen ne ft_split, a split!
	//code
	return (0);
}
