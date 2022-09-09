#include "main.h"

/**
* get_builtin - Matches a command with a corresponding builtin function.
* @command: The command to match
* Return: A function pointer to the corresponding builtin.
*/
int (*get_builtin(char *command))(char **args, char **front)
{
	builtin_t funcs[] = {
		{ "exit", shellby_exit },
		{ "env", shellby_env },
		{ "setenv", shellby_setenv },
		{ "unsetenv", shellby_unsetenv },
		{ "cd", shellby_cd },
		{ "alias", shellby_alias },
		{ "help", shellby_help },
		{ NULL, NULL }
		};
	int i;

	for (i = 0; funcs[i].name; i++)
	{
		if (_strcmp(funcs[i].name, command) == 0)
			break;
	}
	return (funcs[i].f);
}

/**
* exit_builtin - Causes normal process termination
* @args: An array of arguments containing the exit value.
* @front: A double pointer to the beginning of args.
* Return: If there are no arguments - -3.
* If the given exit value is invalid - 2.
*/
int exit_builtin(char **args, char **front)
{
	int i, len_of_int = 10;
	unsigned int num = 0, max = 1 << (sizeof(int) * 8 - 1);

	if (args[0])
	{
		if (args[0][0] == '+')
		{
			i = 1;
			len_of_int++;
		}
		for (; args[0][i]; i++)
		{
			if (i <= len_of_int && args[0][i] >= '0' && args[0][i] <= '9')
			{
				num = (num * 10) + (args[0][i] - '0');
			}
			else
			{
				return (create_error(--args, 2));
			}
		}
	}
	else
	{
		return (-3);
	}
	if (num > max - 1)
	{
		return (create_error(--args, 2));
	}
	args -= 1;
	free_args(args, front);
	free_env();
	free_alias_list(aliases);
	exit(num);
}
