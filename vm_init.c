/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 21:51:02 by tyassine          #+#    #+#             */
/*   Updated: 2017/04/27 21:51:05 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "tyassine.h"

int			ft_init_options(t_env *env, char *argv[], int i)
{
	if (argv[i][1] == 'n' && argv[i][2] == '\0')
		env->ncurses = 1;
	else if (argv[i][1] == 'd' && argv[i][2] == '\0')
		env->debug = 1;
	else if (argv[i][1] == 'a' && argv[i][2] == '\0')
		env->ncurses = 1;
	else if (argv[i][1] == 'd' && argv[i][1] == 'u'
	&& argv[i][1] == 'm' && argv[i][1] == 'p' && argv[i][2] == '\0')
	{
		if (ft_atoi(argv[(i + 1)]) > 0)
		{
			env->dump = ft_atoi(argv[(i + 1)]);
			i++;
		}
	}
	return (i);
}

int			ft_access(char *str)
{
	int		fd;

	if ((fd = open(str, O_RDONLY)) < 0)
	{
		ft_putstr(str);
		ft_putendl(": Couldn't open that file. Stopping.");
		exit(1);
	}
	return (fd);
}

void		ft_add_player(t_env *env, int fd, char arena[], int nb_players)
{
	int		n;
	char	buf[MEM_SIZE];
	int		i;

	i = 0;
	env->players[env->no].nb_players = nb_players;
	n = read(fd, buf, 4);
	buf[n] = 0;
	if (buf[1] != CEM_1 || buf[2] != CEM_2 || buf[3] != CEM_3)
	{
		ft_putendl("Error : Incorrect magic number.");
		exit(2);
	}
	ft_fill_name(env, buf, fd);
	ft_fill_memsize(env, buf, fd);
	ft_fill_comment(env, buf, fd);
	env->players[env->no].arena = arena;
	ft_fill_arena(env, buf, fd);
	(DEBUG == 1) ? ft_print_champion(env) : 42;
	++env->no;
}

void		ft_init_players(t_env *env, int argc, char *argv[], char arena[])
{
	int		i;
	int		fd;
	int		nb;

	i = 1;
	nb = 0;
	while (i < argc)
	{
		if (argv[i][0] != '-')
		{
			if (nb == 0)
				nb = argc - i;
			if (nb > MAX_PLAYERS)
				ft_exit_error("Error : Exceeded the number of players.", 3);
			fd = ft_access(argv[i]);
			ft_add_player(env, fd, arena, nb);
			close(fd);
		}
		else
		{
			i = ft_init_options(env, argv, i);
		}
		++i;
	}
}
