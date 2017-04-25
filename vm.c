
#include "op.h"
#include "libft.h"
#include "debug.h"

void ft_print_arena(char arena[]) {
	int i;

	i = 0;
	while (i < MEM_SIZE) {
		printf("%02x ", (unsigned char)arena[i] );
		if ((i % 24) == 0) {
			printf("\n");
		}
		i++;
	}
	printf("\n");
}

void	ft_init(char arena[], t_proc players[], int argc, char *argv[])
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
		arena[i++] = 0;
	ft_init_players(players, argc, argv, arena);
}

int		main(int argc, char *argv[])
{
	char	arena[MEM_SIZE];
	t_proc	players[MAX_PLAYERS];
	// printf("%s\n", op_tab[0].name);

	if (argc > 1)
		ft_init(arena, players, argc, argv);
		ft_print_arena(arena);
	return (0);
}
