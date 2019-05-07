/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 14:32:14 by vmulder        #+#    #+#                */
/*   Updated: 2019/03/16 16:20:48 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "matches.h"

/*
**	if you dont give it a file you can make the map with your input.
*/

int		user_input(int *map)
{
	int		count;
	char	*kube;

	kube = NULL;
	count = 0;
	while (get_next_line(0, &kube) && kube[0] != 0)
	{
		if (!(checkinput(kube)))
			return (0);
		map[count] = ft_atoi(kube);
		free(kube);
		kube = NULL;
		count++;
	}
	return (count);
}

void	start_game(int argc, int count, int *map)
{
	if (argc > 2)
		ft_error("Usage: ./alum1 file\n");
	print_board(map, count);
	if (argc > 1)
		begin_game(map, count, 0, 0);
	else
		begin_game(map, count, 0, 1);
}

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		count;
	int		map[1000000];

	count = 0;
	if (argc == 1)
		count = user_input(map);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			ft_error("ERROR\n");
		while (get_next_line(fd, &line))
		{
			if (checkinput(line) == 0)
				ft_error("ERROR\n");
			map[count] = ft_atoi(line);
			count++;
		}
	}
	start_game(argc, count, map);
	return (0);
}
