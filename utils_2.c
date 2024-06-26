/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:54:07 by brulutaj          #+#    #+#             */
/*   Updated: 2024/05/02 17:37:33 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_rotate(t_dll **stack_a, t_dll **stack_b, t_bestmoves moves)
{
	while (moves.rot_a > 0)
	{
		rotate(stack_a, stack_b, MOVE_A);
		moves.rot_a--;
	}
	while (moves.rot_b > 0)
	{
		rotate(stack_a, stack_b, MOVE_B);
		moves.rot_b--;
	}
	while (moves.rot_both > 0)
	{
		rotate(stack_a, stack_b, MOVE_BOTH);
		moves.rot_both--;
	}
}

void	get_r_rotate(t_dll **stack_a, t_dll **stack_b, t_bestmoves moves)
{
	while (moves.r_rot_a > 0)
	{
		r_rotate(stack_a, stack_b, MOVE_A);
		moves.r_rot_a--;
	}
	while (moves.r_rot_b > 0)
	{
		r_rotate(stack_a, stack_b, MOVE_B);
		moves.r_rot_b--;
	}
	while (moves.r_rot_both > 0)
	{
		r_rotate(stack_a, stack_b, MOVE_BOTH);
		moves.r_rot_both--;
	}
}

void	solver(t_dll **stack_a)
{
	t_dll	*stack_b;
	int		len;

	stack_b = NULL;
	len = dll_size(*stack_a);
	if (len <= 5)
	{
		minisort(stack_a, &stack_b);
		return ;
	}
	stack_b = get_stack_lis(stack_a);
	if (!stack_b)
		return ;
	solve_all(stack_a, &stack_b);
}
