
#ifndef OP_H
# define OP_H
# include "libft.h"
# include "debug.h"

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3
# define CEM					COREWAR_EXEC_MAGIC
# define CEM_1					(char)(CEM >> 16)
# define CEM_2					(char)((CEM & 65280) >> 8)
# define CEM_3					(char)(CEM & 255)
# define DEBUG					true

typedef char		t_arg_type;

typedef struct		s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					t_header;

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

void	ft_fill_name(t_proc players[], char *buf, int no, int fd);
void	ft_fill_comment(t_proc players[], char *buf, int no, int fd);
void	ft_fill_memsize(t_proc players[], char *buf, int no, int fd);
void	ft_fill_arena(t_proc players[], char *buf, int no, int fd);
void	ft_init_players(t_proc players[], int argc, char *argv[], char aren[]);
t_op	op_tab[17];

#endif
