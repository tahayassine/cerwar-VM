
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "tyassine.h"
#include "debug.h"

void	ft_print_champion(t_env *env)
{
	ft_putstr("Champion ");
	ft_putnbr(env->players[env->no].reg[0]);
	ft_putstr(" : ");
	ft_putstr(env->players[env->no].header.prog_name);
	ft_putstr("\nComment : ");
	ft_putstr(env->players[env->no].header.comment);
	ft_printf("\n%s : %d\n", "taile:" ,env->players[env->no].mem_size); // tmp !!!!!!!!!!
	ft_putstr("\n\n");
}

int		ft_access(char *str)
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

void	ft_add_player(t_env *env, int fd, char arena[], int nb_players)
{
	// static int		env->no = 0;
	int				n;
	char			*buf;
	int				i;

	i = 0;
	env->players[env->no].nb_players = nb_players;
	buf = (char *) malloc(sizeof(char) * 4097);
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

	printf("avant \n");
	ft_fill_arena(env, buf, fd);
	(DEBUG == 1) ? ft_print_champion(env) : 42;
	++env->no;
}

void	ft_init_players(t_env *env, int argc, char *argv[], char arena[])
{
	int		i;
	int		fd;
	int		nb;

	i = 1;
	nb = 0;
	// ft_init_options();
	while (i < argc)
	{
		if (argv[i][0] != '-')
		{
			if (nb == 0)
				nb = argc - i;
			fd = ft_access(argv[i]);
			ft_add_player(env, fd, arena, nb);
			close(fd);
		}
		// else
		// {
		// 	if (argv[i][1] != 'n' && argv[i][2] != '/0')
		// 	{
		// 		42;
		// 			// if(ft_atoi(argv[i + 1]))
		// 	}
		// 	// option
		// }
		++i;
	}
}
