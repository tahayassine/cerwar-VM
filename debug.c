/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 21:50:32 by tyassine          #+#    #+#             */
/*   Updated: 2017/04/27 21:50:36 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tyassine.h"

void		ft_print_arena(char arena[])
{
	unsigned int i;

	i = 0;
	ft_printf("0x%04x : ", i);
	while (i < MEM_SIZE)
	{
		ft_printf("%02x ", (unsigned char)arena[i]);
		if (((i + 1) % 64) == 0 && i != 0 && (i + 1) != MEM_SIZE)
		{
			ft_printf("\n");
			ft_printf("0x%04x : ", (i + 1));
		}
		i++;
	}
	ft_printf("\n");
}

void		ft_print_champion(t_env *env)
{
	ft_printf("* player %d, ", (env->no + 1));
	ft_printf("weighing %d bytes, ", env->players[env->no].mem_size);
	ft_printf("\"%s\" ", env->players[env->no].header.prog_name);
	ft_printf("(%s) !", env->players[env->no].header.comment);
	ft_putstr("\n");
}

void		ft_exit_error(char *msg, char nb_error)
{
	ft_putstr("Error : ");
	ft_putstr(msg);
	ft_putstr("\n");
	exit(nb_error);
}
