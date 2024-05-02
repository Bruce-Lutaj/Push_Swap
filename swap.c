/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:04:04 by brulutaj          #+#    #+#             */
/*   Updated: 2024/05/02 17:38:23 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_op(t_dll **node1)
{
	t_dll	*head;
	int		tmp_value;

	if (dll_size(*node1) == 1)
		return ;
	head = *node1;
	tmp_value = head->value;
	head->value = head->next->value;
	head->next->value = tmp_value;
}

void	swap(t_dll **stack_a, t_dll **stack_b, int flag)
{
	if (flag == MOVE_A)
	{
		swap_op(stack_a);
		write(1, "sa\n", 3);
	}
	else if (flag == MOVE_B)
	{
		swap_op(stack_b);
		write(1, "sb\n", 3);
	}
	else if (flag == MOVE_BOTH)
	{
		swap_op(stack_a);
		swap_op(stack_b);
		write(1, "ss\n", 3);
	}
}
