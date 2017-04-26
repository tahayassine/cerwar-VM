#ifndef TYASSINE_H
# define TYASSINE_H
# include "libft.h"
# include "debug.h"
# include "op.h"

# define CEM					COREWAR_EXEC_MAGIC
# define CEM_1					(char)(CEM >> 16)
# define CEM_2					(char)((CEM & 65280) >> 8)
# define CEM_3					(char)(CEM & 255)

# define DEBUG					env->debug

typedef char		t_arg_type;

/*
** op
*/

typedef struct		s_op
{
	char			*name;
	int				nb_params;
	int				param_types[4];
	int				opcode;
	int				nb_cycles;
	char			*description;
	int				has_pcode;
	int				has_idx;
	int				lab_size;
}					t_op;

typedef struct		s_proc
{
	t_header		header;
	unsigned int	mem_size;
	int				reg[REG_NUMBER];
	char			carry;
	char			pc;
	char			*arena;
	int				nb_players;
	t_list			*proc_list;
}					t_proc;

typedef struct		s_env
{
	char							debug;
	unsigned int			dump;
	char							vision;
	t_proc						players[MAX_PLAYERS];
	int 							no;
} t_env;

void	ft_fill_name(t_env *env, char *buf, int fd);
void	ft_fill_comment(t_env *env, char *buf, int fd);
void	ft_fill_memsize(t_env *env, char *buf, int fd);
void	ft_fill_arena(t_env *env, char *buf, int fd);
void	ft_init_players(t_env *env, int argc, char *argv[], char aren[]);

#endif
