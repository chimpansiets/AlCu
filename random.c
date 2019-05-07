/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   random.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 11:13:34 by svoort         #+#    #+#                */
/*   Updated: 2019/03/16 15:24:28 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "matches.h"

int	rand_bin(void)
{
	int		fd;
	char	ch;

	fd = open("/dev/urandom", O_RDONLY);
	read(fd, &ch, 1);
	return ((unsigned int)ch % 2);
}
