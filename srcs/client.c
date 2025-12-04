#include "../minitalk.h"

int main(int argc, char **argv)
{
	pid_t server_pid;
	(void)argv;
	if (argc != 3)
	{
		ft_putstr("Error: Invalid arguments! Use ./client <server_pid> <string>\n");
		return (1);
	}
	server_pid = (pid_t)ft_atoi(argv[1]);
	return (0);
}
