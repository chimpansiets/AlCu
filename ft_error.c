/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 09:26:10 by svoort         #+#    #+#                */
/*   Updated: 2019/03/17 10:11:15 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "matches.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

int		ft_check(int number, char *input, int *map, int lines)
{
	if (!(number >= 1 && number <= 3) || ft_strlen(input) != 1)
	{
		ft_putnbr(number);
		ft_putchar('\n');
		ft_putstr_fd("Wrong number of matches or invalid character.\n", 2);
		return (1);
	}
	else if (map[lines - 1] < number)
	{
		ft_putstr_fd("There are not that many matches on the line.\n", 2);
		return (1);
	}
	return (0);
}

void	ft_continue_game(int *number, char *input, int *map, int lines)
{
	ft_putstr_fd("\nYOUR TURN: \n", 1);
	*number = ft_atoi(input);
	if (!(ft_check(*number, input, map, lines)))
	{
		lines = remove_from_board(*number, &map, lines);
		print_board(map, lines);
		begin_game(map, lines, 1, 1);
	}
}
