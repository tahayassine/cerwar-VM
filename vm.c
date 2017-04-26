
#include "tyassine.h"
#include "libft.h"

void	ft_init(char arena[], t_env *env, int argc, char *argv[])
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
		arena[i++] = 0;
	ft_init_players(env, argc, argv, arena);
}

int		main(int argc, char *argv[])
{
	t_env		env;
	char		arena[MEM_SIZE];

	env.debug = 1;
	env.dump = 0;
	env.vision = 0;
	env.no = 0;

	if (argc > 1)
		ft_init(arena, &env, argc, argv);
	(env.debug == 2) ? ft_print_arena(arena) : 42;
	return (0);
}
