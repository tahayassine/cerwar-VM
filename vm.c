/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 21:50:51 by tyassine          #+#    #+#             */
/*   Updated: 2017/04/27 21:50:54 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyassine.h"
#include "libft.h"

void		ft_init(char arena[], t_env *env, int argc, char *argv[])
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
		arena[i++] = 0;
	ft_init_players(env, argc, argv, arena);
}

void		ft_init_env(t_env *env)
{
	env->debug = 0;
	env->dump = 0;
	env->vision = 0;
	env->no = 0;
	env->ncurses = 0;
}

int			main(int argc, char *argv[])
{
	t_env		env;
	char		arena[MEM_SIZE];

	ft_init_env(&env);
	if (argc > 1)
		ft_init(arena, &env, argc, argv);
	(env.ncurses == 1) ? ft_print_arena(arena) : 42;
	return (0);
}
