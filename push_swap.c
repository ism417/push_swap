/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:54:23 by eismail           #+#    #+#             */
/*   Updated: 2024/04/04 11:51:32 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node **head)
{
	t_node	*temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		temp = NULL;
	}
}

void	chose_algo(t_node **a, t_node **b, int count)
{
	if (check_sort(*a) == 0 || dep_check(*a) == 1)
		return (free_list(a));
	if (count == 5)
		ft_five(a, b);
	else if (count == 2)
		ft_two(a);
	else if (count == 3)
		ft_three(a);
	else if (count == 4)
		ft_four(a, b);
	else if (count <= 100)
		else_sort(a, b, 15);
	else
		else_sort(a, b, 30);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		j;
	int		count;

	stack_a = NULL;
	stack_b = NULL;
	j = 1;
	count = 0;
	if (argc < 1)
		return (0);
	while (argv[j] != NULL)
	{
		if (num_check(argv[j]) == 0)
		{
			free_list(&stack_a);
			exit(1);
		}
		count += ft_creat(&stack_a, argv[j]);
		j++;
	}
	chose_algo(&stack_a, &stack_b, count);
	free_list(&stack_a);
}
