
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "op.h"

void	ft_print_champion(t_proc players)
{
	ft_putstr("Champion ");
	ft_putnbr(players.reg[0]);
	ft_putstr(" : ");
	ft_putstr(players.header.prog_name);
	ft_putstr("\nComment : ");
	ft_putstr(players.header.comment);
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

void	ft_add_player(t_proc players[], int fd, char arena[], int nb_players)
{
	static int		no = 0;
	int				n;
	char			*buf;
	int				i;

	i = 0;
	players[no].nb_players = nb_players;
	buf = (char *) malloc(sizeof(char) * 4097);
	n = read(fd, buf, 4);
	buf[n] = 0;
	if (buf[1] != CEM_1 || buf[2] != CEM_2 || buf[3] != CEM_3)
	{
		ft_putendl(": incorrect magic number, stopping. D:");
		exit(2);
	}
	ft_fill_name(players, buf, (int)no, fd);
	ft_fill_memsize(players, buf, (int)no, fd);
	ft_fill_comment(players, buf, (int)no, fd);
	players[no].arena = arena;
	ft_fill_arena(players, buf, (int)no, fd);
	ft_print_champion(players[no]);
	++no;
}

void	ft_init_players(t_proc players[], int argc, char *argv[], char arena[])
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
			fd = ft_access(argv[i]);
			ft_add_player(players, fd, arena, nb);
			close(fd);
		}
		++i;
	}
}
