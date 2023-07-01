/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:54:48 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/01 15:36:26 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstswap(char *cmd, t_list **lst, t_list *s1, t_list *s2)
{
	*lst = s2;
	s1->next = s2->next;
	s2->next = s1;
	ft_printf("%s\n", cmd);
	return (1);
}

int	ft_lstpush(char *cmd, t_list **t1,  t_list **t2)
{
	t_list	*tmp;
	int		cmd_l;

	cmd_l = ft_strlen(cmd);
	//if (!ft_strncmp(cmd, "pa\n", cmd_l))
	//	ft_printf("HEL\n");
	tmp = *t2;
	*t2 = *t1;
	*t1 = (*t1)->next;
	(*t2)->next = tmp;

	ft_printf("%s\n", cmd);
	return (1);
}

int	ft_lstrotate(char *cmd, t_list **lst, t_list *s1, t_list *s2)
{
	if (!s2)
		return (0);
	*lst = s2;
	s1->next = NULL;
	ft_lstadd_back(lst, s1);
	ft_printf("%s\n", cmd);
	return (1);
}

int	ft_lstrotate_reversed(char *cmd, t_list **lst, t_list *last, int size)
{
	int	i;
	t_list	*tmp;

	i = 0;
	tmp = *lst;
	while (i < size - 2)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	ft_lstadd_front(lst, last);
	ft_printf("%s\n", cmd);
	return (1);
}
