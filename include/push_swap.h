/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:43:40 by aaudeber          #+#    #+#             */
/*   Updated: 2023/05/19 19:29:10 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>

# include "../libft/libft.h"
# include "../printf/ft_printf.h"

typedef struct s_list
{
	int				nb;
	struct s_list	*next;
}			t_list;

//int		ft_lstswap(char *cmd, t_list **lst);
int		ft_lstswap(char *cmd, t_list **lst, t_list *s1, t_list *s2);
int		ft_lstrotate(char *cmd, t_list **lst, t_list *s1, t_list *s2);
char	*ft_lstrotate_reversed(char *cmd, t_list **lst, t_list *last, int size);
char	*ft_lstpush(char *cmd, t_list **t1, t_list **t2);
void	ft_sort(t_list **t1, t_list **t2);

t_list	*ft_lstnew(int nb);	
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);	
t_list	*ft_lstlast(t_list *lst);

/*
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstclear(t_list **lst, void (*del)(int));
void	ft_lstiter(t_list *lst, void (*f)(int));
t_list	*ft_lstmap(t_list *lst, void *(*f)(int), void (*del)(int));
*/
#endif
