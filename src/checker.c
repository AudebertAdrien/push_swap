/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:07:15 by aaudeber          #+#    #+#             */
/*   Updated: 2023/06/14 19:05:17 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		bytes_read;
	char	*buf;

	(void)argc;
	(void)argv;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = read(STDIN_FILENO, buf, BUFFER_SIZE);
	buf[bytes_read] = '\0';
	printf("%s\n", buf);
	return (0);
}
