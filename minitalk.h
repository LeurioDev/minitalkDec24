#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

void ft_putstr(char *str);
void ft_putnbr(int nbr);
void ft_putchar(char c);
int ft_atoi(const char *nptr);

#endif