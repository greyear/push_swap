/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:07:35 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/19 18:34:54 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
//check error codes in functions!

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**numbers;

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
	sort_all(&a, &b);
	free_stack(&a);
	//free_stack(&b);
	return (0);
}
