/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 09:34:47 by svoort         #+#    #+#                */
/*   Updated: 2019/03/17 10:10:23 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "matches.h"

int		remove_from_board(char number, int **map, int lines)
{
	int	nb;

	nb = number;
	if (nb <= 0)
		nb = 1;
	map[0][lines - 1] = map[0][lines - 1] - nb;
	if (map[0][lines - 1] <= 0)
		return (lines - 1);
	return (lines);
}

int		ai_move(int *map, int lines)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (map[i])
	{
		if (map[i] % 4 == 1)
			b = 1 - b;
		i++;
	}
	if (map[lines - 1] == 1)
		return (1);
	else
		return (((map[lines - 1] - 1) % 4 + b) % 4);
}

void	turn_one(int *map, int lines, int number, int first)
{
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("AI TURN: \n", 1);
	number = ai_move(map, lines);
	lines = remove_from_board(number, &map, lines);
	print_board(map, lines);
	ft_putchar_fd('\n', 1);
	begin_game(map, lines, 0, first);
}

void	end_game(int turn)
{
	if (turn == 1)
	{
		ft_putstr("YOU LOSE!\n");
		exit(0);
	}
	if (turn == 0)
	{
		ft_putstr("YOU WIN!\n");
		exit(0);
	}
}

void	begin_game(int *map, int lines, int turn, int first)
{
	char	*input;
	char	*last_input;
	int		number;
	int		i;

	number = 0;
	i = 0;
	if (turn == 1 && lines != 0)
		turn_one(map, lines, number, first);
	else if (lines != 0)
	{
		ft_putstr_fd("Pick an amount of matches to remove (1 - 3):\n", 1);
		while (get_next_line(0, &input) > 0)
		{
			if (first == 0)
			{
				last_input = ft_itoa(map[lines - 1]);
				while (last_input[i] == input[i])
					i++;
				input += i;
			}
			ft_continue_game(&number, input, map, lines);
		}
	}
	end_game(turn);
}
