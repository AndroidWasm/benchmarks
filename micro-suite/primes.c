#include <stdio.h>
#include <math.h>
#define CHECK 1
int main(int argc, char **argv) {
  int arg = argc > 1 ? argv[1][0] - '0' : 3;
  switch(arg) {
    case 0: return 0; break;
    case 1: arg = 33000; break;
    case 2: arg = 130000; break;
    case 3: arg = 220000; break;
    case 4: arg = 610000; break;
    case 5: arg = 1010000; break;
    default:
#ifdef CHECK
      printf("error: %d\\n", arg);
#endif
      return -1;
  }

  int primes = 0, curri = 2;
  while (primes < arg) {
    int ok = 1;
    for (int j = 2; j < sqrtf(curri); j++) {
      if (curri % j == 0) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      primes++;
    }
    curri++;
  }
#ifdef CHECK
  printf("lastprime: %d.\n", curri-1);
#endif
  return 0;
}
