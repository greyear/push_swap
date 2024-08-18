/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:07:35 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/15 18:01:28 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_stack_node    *a;
	t_stack_node    *b;
	char			**numbers;

	a = NULL;
	b = NULL;
	if (argc == 1) 
		return (0);
	if (argc == 2 && !argv[1][0]) //second argument is what exactly? \0?
		error_and_exit(); // can be -1? //WHAT SHOULD BE HERE IF 0 ARGs???
	numbers = argv + 1;
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	if (numbers == NULL)
		error_and_exit(); //WHAT should be with "" and what with " "???
	create_stack(&a, numbers, argc == 2);
	/*int i = 0;
	t_stack_node *cur = a;
	while (cur != NULL)
	{
		printf("%d - %d\n", i, cur->n);
		cur = cur->next;
		i++;
	}*/
	sort_all(&a, &b);
	free_stack(&a);
	//why shouldn't we free b?
	//free_stack(&b);
	return (0);
}
