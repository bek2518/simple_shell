#include "main.h"

/**
 * free_data - frees data structure
 * @datash: data structure
 */
void free_data(data_shell *datash)
{
	unsigned int i;

	for (i = 0; datash->_environ[i]; i++)
	{
		free(datash->_environ[i]);
	}
	free(datash->_environ);
	free(datash->pid);
}

/**
 * set_data - initialize data structure
 * @datash: data structure
 * @argv: argument vector
 */
void set_data(data_shell *datash, char **argv)
{
	unsigned int i;

	datash->argv = argv;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (i = 0; environ[i]; i++)
		;
	datash->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		datash->_environ[i] = _strdup(environ[i]);
	}
	datash->_environ[i] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * main - main
 * @ac: argument count
 * @argv: argument vecotr
 * Return: 0
 */
int main(int ac, char **argv)
{
	data_shell datash;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, argv);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
