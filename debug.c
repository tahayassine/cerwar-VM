#include "op.h"
#include "libft.h"
# include "debug.h"

void ft_print_arena(char arena[]) {
	int i;

	i = 0;
	while (i < MEM_SIZE) {
		printf("%02x ", (unsigned int)arena[i] );
		if ((i % 16) == 0 && i != 0) {
			printf("\n");
		}
		i++;
	}
	printf("\n");
}
