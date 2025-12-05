#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define FAILURE -1
#define SUCCESS 0

void ft_putstr(char *str);
void ft_putnbr(int nbr);
void ft_putchar(char c);
int ft_atoi(const char *nptr);
char *char_to_binary(char c);
void *ft_memset(void *s, int c, size_t n);

#endif