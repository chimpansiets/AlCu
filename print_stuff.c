/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_stuff.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 14:46:33 by vmulder        #+#    #+#                */
/*   Updated: 2019/03/16 09:29:02 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "matches.h"

void	print_board(int *board, int count)
{
	int	i;
	int	b;

	i = 0;
	while (i < count)
	{
		b = 0;
		while (b < board[i])
		{
			ft_putchar('|');
			b++;
		}
		ft_putchar('\n');
		i++;
	}
}
