/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:47:27 by brulutaj          #+#    #+#             */
/*   Updated: 2024/04/30 19:43:42 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_dll	*stack_a;

	stack_a = parse_input(ac, av);
	if (!stack_a)
		return (0);
	solver(&stack_a);
	dll_clear(&stack_a);
	return (0);
}
