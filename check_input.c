/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: vmulder <vmulder@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 16:28:31 by vmulder        #+#    #+#                */
/*   Updated: 2019/03/16 14:37:18 by vmulder       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "matches.h"

int		checkchars(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' || (s[i] >= '0' && s[i] <= '9'))
			i++;
		else
		{
			ft_error("ERROR\n");
			return (0);
		}
	}
	return (1);
}

int		is_int(char *s)
{
	if (ft_strlen(s) > 10)
	{
		ft_error("ERROR\n");
		return (0);
	}
	if (ft_strlen(s) == 10)
	{
		if (s[0] == '2' && s[1] == '1' && s[2] == '4'
			&& s[3] == '7' && s[4] == '4' && s[5] == '8'
			&& s[6] == '3' && s[7] == '6' && s[8] == '4' && s[9] == '7')
			return (1);
		if (s[0] >= '2' && s[1] >= '1' && s[2] >= '4'
			&& s[3] >= '7' && s[4] >= '4' && s[5] >= '8'
			&& s[6] >= '3' && s[7] >= '6' && s[8] >= '4' && s[9] >= '7')
		{
			ft_error("ERROR\n");
			return (0);
		}
	}
	return (1);
}

int		is_correct(char *s)
{
	int b;

	if (is_int(s) == 0)
		return (0);
	b = ft_atoi(s);
	if (b < 1 || b > 10000)
		return (0);
	else
		return (1);
}

int		checknbr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (is_correct(s) == 0)
		{
			ft_error("ERROR\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int		checkinput(char *s)
{
	if (checkchars(s) == 0 || checknbr(s) == 0 || ft_strlen(s) == 0)
		return (0);
	else
		return (1);
}
