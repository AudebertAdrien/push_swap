/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:40:47 by aaudeber          #+#    #+#             */
/*   Updated: 2023/05/09 20:27:02 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


typedef struct s_toto
{
	int	nb;
	struct s_toto *next;
}	t_toto;

void	print_lst(t_list *lst)
{
	while (lst)
	{
		ft_printf("nb : %d\n", lst->content);
		lst = lst->next;
	}
}

t_toto	*ft_lstnew2(int nb)
{
	t_toto	*new;

	new = (t_toto *)malloc(sizeof(t_toto));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}


int	main(int argc, char **argv)
{
	int		i;
	int		nb;
	t_list	*lst;
	t_toto	*elem;

	i = 1;

	nb = 6;

	elem = ft_lstnew2(nb);
	ft_printf("\n%d\n", elem->nb);
	/*
	if (argc > 2)
	{
		while (argv[i])
		{
			nb = ft_atoi(argv[i]);
			ft_printf("nb1 : %d\n", nb);
			new = ft_lstnew(&nb);
			ft_printf("nb : %d\n", new->content);
			//ft_lstadd_back(&lst, new);
			i++;
		}
		new = ft_lstnew(NULL);
		//ft_lstadd_back(&lst, new);
	}

	//print_lst(lst);
	ft_printf("\n");
	*/
	return (0);
}
