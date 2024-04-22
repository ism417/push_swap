/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:36:52 by eismail           #+#    #+#             */
/*   Updated: 2024/04/04 22:02:05 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_sort(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (temp != NULL)
	{
		if (temp->next != NULL && temp->nbr > (temp->next)->nbr) 
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	dep_check(t_node *stack)
{
	t_node	*temp;
	t_node	*lemp;
	int		count;

	temp = stack;
	lemp = stack;
	count = 0;
	while (temp != NULL)
	{
		count = 0;
		lemp = stack;
		while (lemp != NULL)
		{
			if (temp->nbr == lemp->nbr)
				count++;
			lemp = lemp->next;
		}
		if (count > 1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}
