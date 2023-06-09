/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppimchan <ppimchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:45:31 by ppimchan          #+#    #+#             */
/*   Updated: 2023/05/12 15:35:12 by ppimchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int try_to_fill_arg(Stack *A, char *each_arg)
{
	char **words;
	int j;

	words = ft_split(each_arg, ' ');
	j = 0;
	while (words[j])
		j++;
	j--;
	while (j >= 0)
	{
		if (!verify_string(A, words[j]))
		{
			free(words[j]);
			free(words);
			free_stack(A);
			return 0;
		}
		else
			push_with_rank(A, ft_atoi(words[j]), -1);
		free(words[j]);
		j--;
	}
	free(words);
	return (1);
}


Stack *fill_stack(int argc, char **argv)
{
	int success_fill;
	Stack *A;
	// char *temp;
	// char *res;

	A = create_stack("a");
	success_fill = 0;
	// res = ft_strjoin("","");
	// // new sol
	// while(argc > 1)
	// {
	// 	temp = ft_strdup("", argv[argc-1]);
	// 	res = ft_strjoin(res,temp);
	// 	free(temp);
	// 	argc--;
	// }

	while (argc > 1)
	{
		if (ft_strlen(argv[argc - 1]) == 0)
			return 0;
		success_fill = try_to_fill_arg(A, argv[argc - 1]);
		if (!success_fill)
			return NULL;
		argc--;
	}
	return A;
}