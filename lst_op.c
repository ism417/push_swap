/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 11:11:58 by eismail           #+#    #+#             */
/*   Updated: 2024/04/03 17:28:56 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_last(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst); 
}

t_node	*ft_new(char *str)
{
	t_node	*temp;

	temp = (t_node *)malloc(sizeof(t_node));
	if (!temp)
		return (NULL);
	if (((ft_atoi(str) > 2147483647) || (ft_atoi(str) < -2147483648)))
	{
		write (1, "Error\n", 6);
		free(temp);
		return (NULL);
	}
	temp->nbr = ft_atoi(str);
	temp->next = NULL ;
	return (temp);
}

void	ft_add(t_node **head, t_node *new)
{
	t_node	*last;

	if (!*head)
	{
		*head = new;
		return ;
	}
	last = ft_last(*head);
	last->next = new;
}

int	ft_creat(t_node **head, char *str)
{
	t_node	*temp;
	char	**numbers;
	int		i;

	i = 0;
	numbers = ft_split(str, ' ');
	if (!numbers)
		return (free_list(head), exit(1), 0);
	while (numbers[i] != NULL)
	{
		temp = ft_new(numbers[i]);
		if (temp == NULL)
		{
			free(temp);
			free_list(head);
			free_split(numbers);
			exit(1);
		}
		ft_add(head, temp);
		i++;
	}
	free_split(numbers);
	return (i);
}

int	ft_stacksize(t_node *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
