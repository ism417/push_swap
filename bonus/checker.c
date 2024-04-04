/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:19:07 by eismail           #+#    #+#             */
/*   Updated: 2024/04/04 11:51:38 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	right_move(char *s)
{
	int	len;

	len = ft_strlen(s) - 1;
	if (ft_strncmp(s, "sa", len) == 0 || ft_strncmp(s, "ra", len) == 0 
		|| ft_strncmp(s, "rra", len) == 0 || ft_strncmp(s, "pa", len) == 0)
		return (1);
	else if (ft_strncmp(s, "sb", len) == 0 || ft_strncmp(s, "rb", len) == 0 
		|| ft_strncmp(s, "rrb", len) == 0 || ft_strncmp(s, "pb", len) == 0)
		return (1);
	else if (ft_strncmp(s, "ss", len) == 0 || ft_strncmp(s, "rr", len) == 0 
		|| ft_strncmp(s, "rrr", len) == 0)
		return (1);
	else
	{
		write(2, "Error\n", 6);
		return (0);
	}
}

void	act(char *s, t_node **a, t_node **b)
{
	if (ft_strlen(s) == 3)
	{
		if (ft_strncmp(s, "sa", 2) == 0 || ft_strncmp(s, "ss", 2) == 0)
			sa(a);
		if (ft_strncmp(s, "sb", 2) == 0 || ft_strncmp(s, "ss", 2) == 0)
			sb(b);
		if (ft_strncmp(s, "ra", 2) == 0 || ft_strncmp(s, "rr", 2) == 0)
			ra(a);
		if (ft_strncmp(s, "rb", 2) == 0 || ft_strncmp(s, "rr", 2) == 0)
			rb(b);
		if (ft_strncmp(s, "pa", 2) == 0)
			pa(a, b);
		if (ft_strncmp(s, "pb", 2) == 0)
			pb(a, b);
	}
	if (ft_strlen(s) == 4)
	{
		if (ft_strncmp(s, "rra", 3) == 0 || ft_strncmp(s, "rrr", 3) == 0)
			rra(a);
		if (ft_strncmp(s, "rrb", 3) == 0 || ft_strncmp(s, "rrr", 3) == 0)
			rrb(b);
	}
}

void	ft_read(t_node **a, t_node **b)
{
	char	*moves;

	if (dep_check(*a) == 1)
	{
		free_list(a);
		exit(1);
	}
	while (1)
	{
		moves = get_next_line(1);
		if (moves == NULL)
			break ;
		if (moves[0] == '\n')
			break ;
		if (right_move(moves) == 0)
		{
			free(moves);
			exit(1);
		}
		act(moves, a, b);
		free(moves);
	}
}

void	ft_sorted(t_node **a, t_node **b)
{
	if (check_sort(*a) == 0 && ft_stacksize(*b) == 0)
	{
		write(1, "OK\n", 4);
		free_list(a);
		free_list(b);
		exit(0);
	}
	else
	{
		write(1, "KO\n", 4);
		free_list(a);
		free_list(b);
		exit(1);
	}
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
	if (argc < 2)
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
	ft_read(&stack_a, &stack_b);
	ft_sorted(&stack_a, &stack_b);
}
