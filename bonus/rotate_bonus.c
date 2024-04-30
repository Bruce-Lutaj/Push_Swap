/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:09:19 by brulutaj          #+#    #+#             */
/*   Updated: 2024/04/30 21:11:18 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_rotate_op(t_dll **stack)
{
	t_dll	*head;
	t_dll	*last;
	t_dll	*second;

	if (dll_size(*stack) == 1)
		return ;
	head = *stack;
	last = dll_last(head);
	second = head->next;
	head->prev = last;
	head->next = NULL;
	last->next = head;
	second->prev = NULL;
	*stack = second;
	set_index(stack);
}

void	checker_rotate(t_dll **stack_a, t_dll **stack_b, int flag)
{
	if (flag == MOVE_A)
	{
		checker_rotate_op(stack_a);
		return ;
	}
	else if (flag == MOVE_B)
	{
		checker_rotate_op(stack_b);
		return ;
	}
	else if (flag == MOVE_BOTH)
	{
		checker_rotate_op(stack_a);
		checker_rotate_op(stack_b);
	}
}