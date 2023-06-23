/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:32:45 by aaudeber          #+#    #+#             */
/*   Updated: 2023/06/23 15:40:51 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *s)
{
	ft_putstr_fd(s, 1);
	ft_putchar_fd('\n', 1);
	exit(EXIT_FAILURE);	
}

int	is_valid_number(char *s)
{
	int	i;

	i = 0;
 	if (s[0] == '-')
		i++;
	while (s[i])
	{
		if (!(ft_isdigit(s[i])))
			return (1);
		i++;
	}
	return (0);
}

int	is_overflow(long nb)
{
	if (nb > INT_MAX)
		return (1);
	if (nb < INT_MIN)
		return (1);
	return (0);
}

int	is_duplicate(t_list **lst)
{
	t_list *l1;
	t_list *l2;

	l1 = *lst;
	while (l1)
	{
		l2 = l1->next;
		while (l2)
		{
			if (l1->nb == l2->nb)
				return (1);
			l2 = l2->next;
		}
		l1 = l1->next;
	}
	return (0);
}

int	is_already_sorted(t_list **lst)
{
	t_list *l1;

	l1 = *lst;
	while (l1->next)
	{
		if (l1->nb > l1->next->nb)
			return (0);
		l1 = l1->next;
	}
	return (1);
}
