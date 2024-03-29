#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, character **av)
{
	information_t information[] = { information_INIT };
	int fielddes = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fielddes)
		: "r" (fielddes));

	if (ac == 2)
	{
		fielddes = open(av[1], O_RDONLY);
		if (fielddes == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		information->readfielddes = fielddes;
	}
	populate_env_list(information);
	read_history(information);
	hsh(information, av);
	return (EXIT_SUCCESS);
}
