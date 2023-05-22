/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:55:24 by aaudeber          #+#    #+#             */
/*   Updated: 2023/03/24 12:12:18 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/*
void	print_bits(unsigned char octet)
{
		int	i;
		int mask = 0b00001000;

		i = 7;
		while (i >= 0)
		{
			unsigned char bit = octet & mask;
			bit >>= 7;
			printf("%hhd", bit);
			octet <<= 1;
			i--;
		}
}
*/

/*
void	print_bits(unsigned char num)
{
		int	i;
		unsigned char bit;
		
		i = 0;
		while (i < 8)
		{
			bit = num & 1;
			printf("%hhd\n", bit);
			num = num >> 1;
			i++;
		}
}
*/
/*
void	print_bits(unsigned char num)
{
		int	i;
		unsigned char bit;
		
		i = 8;
		while (i > 0)
		{
			bit = num & 128;
			printf("%hhd\n", bit >> 7);
			num = num << 1;
			i--;
		}
}
*/

/*
void	print_bits(unsigned char num)
{
		int	i;
		unsigned char bit;
		
		i = 0;
		while (i < 8)
		{
			if (num & 128)
				printf("1");
			else
				printf("0");
			num = num << 1;
			i++;
		}
}
*/

void	print_bits(char num)
{
		int	i;
		int	mask;

		mask = 128;
		//mask = 0b10000000;
		i = 0;
		while (i < 8)
		{
			if (num << i & mask)
				printf("1");
			else
				printf("0");
			i++;
		}
}

int	main(void)
{
	print_bits(-2);
	return (0);
}
//000000000 000000000 000000000 100000000
//000000000 000000000 000000000 00000000
/*
00000010
10000000
=00000000
*/

/*
00000010
00000001
=00000000


00000001
00000001
=00000001
*/
