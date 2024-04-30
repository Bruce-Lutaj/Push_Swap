/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:44:30 by brulutaj          #+#    #+#             */
/*   Updated: 2024/04/30 18:17:52 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/Headers/libft.h"

typedef enum e_moves
{
	STAY,
	MOVE_A,
	MOVE_B,
	MOVE_BOTH,
	PUSH,
	ROTATE,
	R_ROTATE,
	SWAP
}	t_moves;

typedef struct s_bestmoves
{
	int	rot_a;
	int	rot_b;
	int	rot_both;
	int	r_rot_a;
	int	r_rot_b;
	int	r_rot_both;
	int	tot_moves;
}		t_bestmoves;

/* Utils */

int			check_duplicates(char **mtx);
int			is_sorted(t_dll *pStack);
int			mtx_check(char **mtx);
t_bestmoves	bestmoves_cpy(t_bestmoves moves);
t_bestmoves	bestmoves_operations(t_bestmoves moves, int flag_move);
void		get_rotate(t_dll **stack_a, t_dll **stack_b, t_bestmoves moves);
void		get_r_rotate(t_dll **stack_a, t_dll **stack_b, t_bestmoves moves);
void		solver(t_dll **stack_a);

/* Moves */

void		swap_op(t_dll **node1);
void		swap(t_dll **stack_a, t_dll **stack_b, int flag);
void		rotate_op(t_dll **stack);
void		rotate(t_dll **stack_a, t_dll **stack_b, int flag);
void		r_rotate_op(t_dll **stack);
void		r_rotate(t_dll **stack_a, t_dll **stack_b, int flag);
void		pa(t_dll **stack_a, t_dll **stack_b);
void		pb(t_dll **stack_b, t_dll **stack_a);

/* Parsing */

t_dll		*get_list_head(char **mtx);
t_dll		*parse_input_string(int ac, char *av);
t_dll		*parse_input_args(int ac, char **av);
t_dll		*parse_input(int ac, char **av);

/* Move Calculation */

t_bestmoves	check_moves_b(t_dll *stack_b, int value_b, t_bestmoves moves);
t_bestmoves	check_moves_a(t_dll *stack_a, int value_b, t_bestmoves moves);
t_bestmoves	organize_moves(t_bestmoves moves);
t_bestmoves	get_moves(t_dll *stack_a, t_dll *stack_b, int value_b);
t_bestmoves	get_best_moves(t_dll *stack_a, t_dll *stack_b);

/* 2/3/4/5 Sorting Algorithm */

int			find_move(t_dll *stack_a);
void		sort_3(t_dll **stack_a);
void		sort_4(t_dll **stack_a, t_dll **stack_b);
void		sort_5(t_dll **stack_a, t_dll **stack_b);
void		minisort(t_dll **stack_a, t_dll **stack_b);

/* Main Algorithm */

int			*lis_algo(t_dll *head, int *n);
t_dll		*handling_lis(t_dll **stack_a, int *index_a, int lis_size);
t_dll		*get_stack_lis(t_dll **stack_a);
void		final_sorting(t_dll **stack_a);
void		do_moves(t_dll **stack_a, t_dll **stack_b);
void		solve_all(t_dll **stack_a, t_dll **stack_b);

#endif