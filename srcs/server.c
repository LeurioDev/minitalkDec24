#include "../minitalk.h"

void handle_msm(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("Receive SIGUSR1 from client\n");
	else if (sig == SIGUSR2)
		ft_putstr("Receive SIGUSR2 from client\n");
}


int main()
{
	int pid;

	pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');

	while (1)
	{
		pause();
	}
	return (0);
}