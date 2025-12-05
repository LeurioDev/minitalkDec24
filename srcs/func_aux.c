#include "../minitalk.h"

void ft_putchar(char c) { write(1, &c, 1); }

void ft_putstr(char *str) {
  while (*str)
    ft_putchar(*str++);
}

void ft_putnbr(int nbr) {
  if (nbr < 0) {
    write(1, "-", 1);
    nbr = -nbr;
  }
  if (nbr > 9)
    ft_putnbr(nbr / 10);
  ft_putchar((nbr % 10) + '0');
}

int ft_atoi(const char *nptr) {
  unsigned char *ptr;
  int sign;
  long long rsl;

  ptr = (unsigned char *)nptr;
  if (!nptr)
    return (0);
  sign = 1;
  rsl = 0;
  while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
    ptr++;
  if (*ptr == '-') {
    sign = -1;
    ptr++;
  } else if (*ptr == '+')
    ptr++;
  while (*ptr >= '0' && *ptr <= '9') {
    rsl = ((rsl * 10) + (*ptr - '0'));
    ptr++;
  }
  return (rsl * sign);
}

char *char_to_binary(char c) {
  char *binary;
  int i;

  binary = malloc(sizeof(char) * 9);
  if (!binary)
    return (NULL);
  i = 7;
  while (i >= 0) {
    binary[i] = (c % 2) + '0';
    c /= 2;
    i--;
  }
  binary[8] = '\0';
  return (binary);
}