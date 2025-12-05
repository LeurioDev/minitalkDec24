#include "../minitalk.h"

void *ft_memset(void *s, int c, size_t n) {
  unsigned char *ptr;

  if (!s)
    return (NULL);
  if (n == 0)
    return (s);
  if (c < 0 || c > 255)
    c = 0;
  if (n > SIZE_MAX)
    return (NULL);
  if (n > (SIZE_MAX - 1))
    return (NULL);
  if (n == 0)
    return (s);
  ptr = s;
  while (n-- > 0) {
    *ptr++ = c;
  }
  return (s);
}