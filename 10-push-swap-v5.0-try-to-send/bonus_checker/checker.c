/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:56:39 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/13 03:41:41 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void error_and_exit(char *word, t_stack *A, t_stack *B)
{
	if (A)
		free_stack(A);
	if (B)
		free_stack(B);
	write(2, word, ft_strlen(word));
	exit(1);
}

void execute_action(t_stack *A, t_stack *B, char *action)
{
	// printf("execute %s\n", action);
	if (ft_strncmp(action, "sa\n", 4) == 0)
		s_swap_top(A, 0);
	else if (ft_strncmp(action, "sb\n", 4) == 0)
		s_swap_top(B, 0);
	else if (ft_strncmp(action, "ss\n", 4) == 0)
		s_swap_both(A, B, 1);
	else if (ft_strncmp(action, "pa\n", 4) == 0)
		p_move_top(B, A, 0);
	else if (ft_strncmp(action, "pb\n", 4) == 0)
		p_move_top(A, B, 0);
	else if (ft_strncmp(action, "ra\n", 4) == 0)
		r_shift_up(A, NULL, 0);
	else if (ft_strncmp(action, "rb\n", 4) == 0)
		r_shift_up(B, NULL, 0);
	else if (ft_strncmp(action, "rr\n", 4) == 0)
		r_shift_up(A, B, 0);
	else if (ft_strncmp(action, "rra\n", 5) == 0)
		rr_shift_down(A, NULL, 0);
	else if (ft_strncmp(action, "rrb\n", 5) == 0)
		rr_shift_down(B, NULL, 0);
	else if (ft_strncmp(action, "rrr\n", 5) == 0)
		rr_shift_down(A, B, 0);
	else
		error_and_exit("Error\n", A, B);
}

// void	checker(t_stack *A, t_stack *B)
// {
// 	char	action[1000];
// 	char	buff[1];
// 	int		read_size;
// 	int		i;

// 	i = 0;
// 	read_size = -1;
// 	while(read_size && action[i] != '\n')
// 	{
// 		read_size = read(STDIN_FILENO, buff, 1);
// 		action[i] = buff[0];
// 		i++;
// 	}
// 	action[i] = 0;
// 	// printf("action = %s", action);
// 	// while (read_size > 0 || !is_sorted(A))
// 	// {
// 	// 	execute_action(A, B, action);
// 	// 	while(read_size && action[i] != '\n')
// 	// 	{
// 	// 		read_size = read(STDIN_FILENO, action, 1);
// 	// 		action[i] = buff[0];
// 	// 		i++;
// 	// 	}
// 	// 	action[i] = 0;
// 	// }
// 	if (is_sorted(A) && B->size == 0)
// 		ft_putstr_fd("OK\n", STDOUT_FILENO);
// 	else
// 		ft_putstr_fd("KO\n", STDOUT_FILENO);
// }

void checker(t_stack *A, t_stack *B)
{
	char *action;

	action = get_next_line(STDIN_FILENO);

	while (action)
	{
		// printf("address = %p\n", action);
		execute_action(A, B, action);
		free(action);
		action = get_next_line(STDIN_FILENO);
		// printf("action = %s", action);
		// printf("action.len = %zu", ft_strlen(action));
		// if(!action)
		// 	break ;
	}
	free(action);
	if (is_sorted(A) && B->size == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
}

int main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;

	a = fill_stack(argc, argv);
	b = create_stack("b");
	if (!a)
		error_and_exit("Error\n", a, b);
	label_rank(a);
	checker(a, b);
	// print_stack(a);
	free_stack(a);
	free_stack(b);
	return (0);
}