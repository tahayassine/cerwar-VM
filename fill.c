/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 21:50:40 by tyassine          #+#    #+#             */
/*   Updated: 2017/04/27 21:50:45 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "op.h"
#include "tyassine.h"

void						ft_fill_name(t_env *env, char *buf, int fd)
{
	int						i;
	int						n;

	i = 0;
	n = read(fd, buf, PROG_NAME_LENGTH);
	(n <= 0) ? ft_exit_error("Le nom non valide", 2) : 42;
	buf[n] = 0;
	while (buf[i] != 0)
	{
		if (buf[i] >= 32 && buf[i] <= '~')
			env->players[env->no].header.prog_name[i] = buf[i];
		else
			ft_exit_error("Le nom non valide", 2);
		++i;
	}
	if (ft_strlen(env->players[env->no].header.prog_name) == 0)
		ft_exit_error("Le nom non valide", 2);
	env->players[env->no].header.prog_name[i] = 0;
}

void						ft_fill_comment(t_env *env, char *buf, int fd)
{
	int						i;
	int						n;

	i = 0;
	n = read(fd, buf, COMMENT_LENGTH);
	(n <= 0) ? ft_exit_error("Le commentaire non valide", 2) : 42;
	buf[n] = 0;
	while (buf[i] != 0)
	{
		if (buf[i] >= 32 && buf[i] <= '~')
			env->players[env->no].header.comment[i] = buf[i];
		else
			ft_exit_error("commentaire non valide", 2);
		++i;
	}
	if (ft_strlen(env->players[env->no].header.comment) == 0)
		ft_exit_error("commentaire non valide", 2);
	env->players[env->no].header.comment[i] = 0;
}

void						ft_fill_memsize(t_env *env, char *buf, int fd)
{
	int						i;
	int						n;

	i = 0;
	n = read(fd, buf, 8);
	env->players[env->no].mem_size = 0;
	while (i < 8)
	{
		if (i == 6)
			env->players[env->no].mem_size += ((unsigned int)buf[i]) << 8;
		else
			env->players[env->no].mem_size += (unsigned int)buf[i];
		++i;
	}
	if (env->players[env->no].mem_size > CHAMP_MAX_SIZE)
		ft_exit_error("Taile du chompion incorrect : Tros grand", 2);
	env->players[env->no].header.prog_size = env->players[env->no].mem_size;
}

int							ft_pos_arena(int nb_players, t_env *env)
{
	if (env->no == 0)
		return (0);
	if (nb_players == 2)
		return (MEM_SIZE / 2);
	if (nb_players == 3 && env->no == 1)
		return (MEM_SIZE / 3);
	if (nb_players == 3 && env->no == 2)
		return (MEM_SIZE / 3 * 2);
	if (nb_players == 4 && env->no == 1)
		return (MEM_SIZE / 4);
	if (nb_players == 4 && env->no == 2)
		return (MEM_SIZE / 4 * 2);
	if (nb_players == 4 && env->no == 3)
		return (MEM_SIZE / 4 * 3);
	return (0);
}

void						ft_fill_arena(t_env *env, char *buf, int fd)
{
	unsigned int	i;
	unsigned int	start;

	start = ft_pos_arena(env->players[env->no].nb_players, env);
	i = 0;
	lseek(fd, 4, SEEK_CUR);
	while (i < env->players[env->no].mem_size)
	{
		if (read(fd, buf, 1))
			env->players[env->no].arena[start + i] = buf[0];
		else
			ft_exit_error("Taile du chompion incorrect", 2);
		++i;
	}
	env->players[env->no].reg[0] = env->no + 1;
	i = 1;
	while (i < REG_NUMBER)
		env->players[env->no].reg[i++] = 0;
	env->players[env->no].pc = start;
	env->players[env->no].carry = 0;
}
