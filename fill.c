

#include <unistd.h>
#include "libft.h"
#include "op.h"

void	ft_fill_name(t_proc players[], char *buf, int no, int fd)
{
	int		i;
	int		n;

	i = 0;
	n = read(fd, buf, PROG_NAME_LENGTH);
	buf[n] = 0;
	while (buf[i] != 0)
	{
		players[no].header.prog_name[i] = buf[i];
		++i;
	}
	players[no].header.prog_name[i] = 0;
}

void	ft_fill_comment(t_proc players[], char *buf, int no, int fd)
{
	int		i;
	int		n;

	i = 0;
	n = read(fd, buf, COMMENT_LENGTH);
	buf[n] = 0;
	while (buf[i] != 0)
	{
		players[no].header.comment[i] = buf[i];
		++i;
	}
	players[no].header.comment[i] = 0;
}

void	ft_fill_memsize(t_proc players[], char *buf, int no, int fd)
{
	int		i;
	int		n;

	i = 0;
	n = read(fd, buf, 8);
	players[no].mem_size = 0;
	while (i < 8)
	{
		if (i == 6)
			players[no].mem_size += ((unsigned int) buf[i]) << 8;
		else
			players[no].mem_size += (unsigned int) buf[i];
		++i;
	}
}

int		ft_pos_arena(int nb_players, int no)
{
	if (no == 0)
		return (0);
	if (nb_players == 2)
		return (MEM_SIZE / 2);
	if (nb_players == 3 && no == 1)
		return (MEM_SIZE / 3);
	if (nb_players == 3 && no == 2)
		return (MEM_SIZE / 3 * 2);
	if (nb_players == 4 && no == 1)
		return (MEM_SIZE / 4);
	if (nb_players == 4 && no == 2)
		return (MEM_SIZE / 4 * 2);
	if (nb_players == 4 && no == 3)
		return (MEM_SIZE / 4 * 3);
	return (0);
}

void	ft_fill_arena(t_proc players[], char *buf, int no, int fd)
{
	unsigned int	i;
	unsigned int	start;

	start = ft_pos_arena(players[no].nb_players, no);
	i = 0;
	lseek(fd, 4, SEEK_CUR);
	while (i < players[no].mem_size)
	{
		read(fd, buf, 1);
		players[no].arena[start + i] = buf[0];
		++i;
	}
	players[no].reg[0] = no + 1;
	i = 1;
	while (i < REG_NUMBER)
	   players[no].reg[i++] = 0;
	players[no].pc = start;
	players[no].carry = 0;
}
