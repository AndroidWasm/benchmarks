#include <stdio.h>
#include <math.h>
#include <stdint.h>
#define short(x) ((short)(x))
int main(int argc, char **argv) {
  int64_t N, M;
  int arg = argc > 1 ? argv[1][0] - '0' : 3;
  switch(arg) {
    case 0: return 0; break;
    case 1: N = 8000; M = 550; break;
    case 2: N = 8000; M = 3500; break;
    case 3: N = 8000; M = 7000; break;
    case 4: N = 8000; M = 5*7000; break;
    case 5: N = 8000; M = 10*7000; break;
    default: printf("error: %d\\n", arg); return -1;
  }

  uint64_t f = 0;
  uint32_t s = 0;
  for (int64_t t = 0; t < M; t++) {
    for (int64_t i = 0; i < N; i++) {
      f += i / ((t % 5)+1);
      if (f > 1000) f /= (t % 3)+1;
      if (i % 4 == 0) f += i * (i % 8 == 0 ? 1 : -1);
      s += (short(f)*short(f)) % 256;
    }
  }
  printf("final: %lld:%d.\n", (long long)f, s);
  return 0;
}
