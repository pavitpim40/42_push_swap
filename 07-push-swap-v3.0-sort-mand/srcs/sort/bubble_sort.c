/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:06:40 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/09 00:45:57 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void do_bubble(Stack *stack_a, Stack *stack_b)
{
	if (stack_a->top->prev == stack_a->bottom)
		s_swap_top(stack_a);
	else
	{
		s_swap_top(stack_a);
		p_move_top(stack_a, stack_b);
	}
}

void bubble_sort(Stack *stack_a, Stack *stack_b)
{
	Node *element_1;
	Node *element_2;
	int count_inner;
	int count;
	int size;

	size = stack_a->size;
	// printf("hi bubble size = %d\n", size);
	count = 0;

	while (count++ < size - 1)
	{

		element_1 = stack_a->top;
		element_2 = element_1->prev;
		// printf("el_1=%d el2=%d\n", element_1->data, element_2->data);
		count_inner = 0;
		while (count_inner++ < size - count)
		{
			// printf("inner\n");
			if (element_1->data > element_2->data)
				do_bubble(stack_a, stack_b);
			else
				p_move_top(stack_a, stack_b);
			element_1 = stack_a->top;
			element_2 = element_1->prev;
		}
		while (stack_a->size < size)
			p_move_top(stack_b, stack_a);
	}
}
