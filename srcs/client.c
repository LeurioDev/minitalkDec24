#include "../minitalk.h"

int send_signal(pid_t pid, int signal_to_send) {
  if (kill(pid, signal_to_send) == -1)
    return (FAILURE);
  return (SUCCESS);
}

void send_bit(pid_t pid, char bit) {
  // char *binary;
  int i;

  i = 7;
  while (i >= 0) {
    if ((bit >> i) & 1)
      send_signal(pid, SIGUSR2);
    else
      send_signal(pid, SIGUSR1);
    usleep(1000);
    i--;
  }
  /*binary = char_to_binary(bit);
  if (!binary)
    return;
  i = 0;
  while (i < 8) {
    if (binary[i] == '0')
      send_signal(pid, SIGUSR1);
    else if (binary[i] == '1')
      send_signal(pid, SIGUSR2);
    usleep(1000);
    i++;
  }
  free(binary);*/
}

int main(int argc, char **argv) {
  pid_t server_pid;
  char *sms;
  int i;

  if (argc != 3) {
    ft_putstr("Error: Invalid arguments! Use ./client <server_pid> <string>\n");
    return (FAILURE);
  }
  server_pid = (pid_t)ft_atoi(argv[1]);
  sms = argv[2];
  i = 0;
  while (sms[i]) {
    send_bit(server_pid, sms[i]);
    usleep(1500);
    i++;
  }
  send_bit(server_pid, '\0');
  return (SUCCESS);
}
