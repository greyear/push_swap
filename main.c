/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:07:35 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/22 16:59:38 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" //folders needed?

int main(int argc, char *argv[])
{
    t_stack_node    *a;
    t_stack_node    *b;

    a = NULL;
    b = NULL;
    
    if (argc == 1 || (argc == 2 && !argv[1][0])) //second argument is empty line like ""?
        return (1); //error message code? can be -1?
    else if (argc == 2)
        argv  = ft_split(argv[1], ' ');
    

    return (0);
}
