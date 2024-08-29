#include <stdio.h>
#include <time.h>
#include <math.h>

#define DEG_TO_RAD(A) (A / 57.296)
#define ITERATIONS 1000000


int main()
{
  clock_t t1, t2;
  unsigned i, a;
  double val;
  double sin_values[360];

  for (a = 0; a < 360; ++a)
  {
	  sin_values[a] = sin(DEG_TO_RAD(a));
  }
  
  t1 = clock();
  for (i = 0; i < ITERATIONS; ++i)
    {
      for (a = 0; a < 360; ++a)
	{
	  val = sin_values[a];
	}
    }
  t2 = clock();
  printf("%.1fs\n", (t2 - t1) / (float)CLOCKS_PER_SEC);
  printf("Kuinka paljon enemmän muistia optimoitu versio kuluttaa: (Double = 8 bytes) 360 * 8 bytes = 2880 bytea tai 2.88 KB enemmän. Muisti tallennetaan stackiin.\n");
  printf("Kuinka paljon nopeammin optimoitu versio toimii: Noin 10 kertaa nopeammin, (original: 6,1-6,2 sec / optimized: 0,6 sec)\n");

  return 0;
}
