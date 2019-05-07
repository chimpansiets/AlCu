/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   matches.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: svoort <svoort@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 14:22:16 by vmulder        #+#    #+#                */
/*   Updated: 2019/03/17 09:52:35 by svoort        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATCHES_H
# define MATCHES_H
# define BUFF_SIZE 1

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_gnl
{
	char			buf[BUFF_SIZE + 1];
	char			*locationnl;
	char			*buf_leftover;
	char			*free1;
	int				i;
}					t_gnl;

void				print_board(int *board, int count);
int					main(int argc, char **argv);
int					checkinput(char *s);
void				begin_game(int *map, int lines, int turn, int first);
void				ft_error(char *str);
int					remove_from_board(char number, int **map, int lines);
int					ft_check(int number, char *input, int *map, int lines);
int					rand_bin(void);
int					ai_move(int *map, int lines);
void				ft_continue_game(int *number, char *input, int *map, \
					int lines);

/*
**	GNL
*/

int					get_next_line(const int fd, char **line);

#endif
