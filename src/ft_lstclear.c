/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:06:25 by aaudeber          #+#    #+#             */
/*   Updated: 2023/06/08 16:45:59 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_lstclear(t_list **lst)
{
	t_list	*start;
	t_list	*tmp;

	if (!lst)
		return ;
	start = *lst;
	while (start)
	{
		tmp = start->next;
		free(start);
		start = tmp;
	}	
	*lst = NULL;
}
