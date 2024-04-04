/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:03:51 by eismail           #+#    #+#             */
/*   Updated: 2024/04/03 22:38:44 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		neg_flg;
	long	res;

	i = 0;
	neg_flg = 1;
	res = 0;
	while ((str[i] == ' ') || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg_flg *= -1;
		i++;
	}
	while (str[i])
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
			res = (res * 10) + (str[i++] - '0');
		else
			return (print_error());
	}
	return (res * neg_flg);
}
