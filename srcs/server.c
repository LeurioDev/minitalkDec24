#include "../minitalk.h"
#include <signal.h>
#include <unistd.h>

char binary_to_char(char *binary) {
  char c;
  int i;

  c = 0;
  i = 0;
  while (i < 8) {
    c = (c << 1);
    if (binary[i] == '1')
      c = c | 1;
    i++;
  }
  return (c);
}

void handle_msm(int sig, siginfo_t *info, void *context) {
  // static unsigned char *binary;
  // static int i;
  static unsigned char c = 0;
  static int bit = 0;

  (void)info;
  (void)context;
  // c = 0;
  // bit = 0;
  c = c << 1;
  if (sig == SIGUSR2)
    c = c | 1;
  if (sig == SIGINT)
    bit = 0;
  bit++;
  if (bit == 8) {
    if (c == '\0')
      write(1, "\n", 1);
    else
      write(1, &c, 1);
    c = 0;
    bit = 0;
  }
  /*
  if (!binary) {
    binary = malloc(sizeof(char) * 9);
    i = 0;
  }
  if (sig == SIGUSR1)
    binary[i] = '0';
  else if (sig == SIGUSR2)
    binary[i] = '1';
  i++;
  if (i == 8) {
    binary[i] = '\0';
    if (binary_to_char(binary) == '\0') {
      ft_putchar('\n');
      free(binary);
      binary = NULL;
      i = 0;
      return;
    }
    ft_putchar(binary_to_char(binary));
    // i = 0;
    free(binary);
    binary = malloc(sizeof(char) * 9);
    if (!binary)
      exit(1);
    i = 0;
  }
  */
}

void print_pid(pid_t pid) {
  ft_putstr("Server PID: ");
  ft_putnbr(pid);
  ft_putchar('\n');
}

int main() {
  struct sigaction sa;

  ft_memset(&sa, 0, sizeof(sa));
  sa.sa_sigaction = handle_msm;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &sa, NULL);
  sigaction(SIGUSR2, &sa, NULL);
  print_pid(getpid());

  while (1) {
    pause();
  }
  return (SUCCESS);
}