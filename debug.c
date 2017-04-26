#include "tyassine.h"
#include "debug.h"

void ft_print_arena(char arena[])
{
	int i;

	i = 0;
	while (i < MEM_SIZE) {
		ft_printf("%02x ", (unsigned int)arena[i] );
		if ((i % 24) == 0 && i != 0) {
			ft_printf("\n");
		}
		i++;
	}
	ft_printf("\n");
}

// void	ft_print_champion(t_proc players)
// {
// 	ft_putstr("Champion ");
// 	ft_putnbr(players.reg[0]);
// 	ft_putstr(" : ");
// 	ft_putstr(players.header.prog_name);
// 	ft_putstr("\nComment : ");
// 	ft_putstr(players.header.comment);
// 	ft_printf("\n%s : %d\n", "taile:" ,players.mem_size);
// 	ft_putstr("\n\n");
// }
void ft_exit_error(char *msg, char nb_error)
{
	ft_putstr("Error : ");
	ft_putstr(msg);
	ft_putstr("\n");
	exit(nb_error);
}
