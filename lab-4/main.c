#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void p1 () {
  int j, p = 1;

  for (j = 1; j <= 4; j++) {
    p = p * (j + 3);
    printf("\nj = %d => p = %d", j, p);
  }
  puts("");
}

void p2 () {
  float x, a, Q;

  puts("\nIntroduceti valoarea lui a:");
  scanf("%f", &a);

  for (x = 0.7; x <= 2; x += 0.1) {
    if (x < 1.4) {
      Q = M_PI * pow(x, 2) - 7 / pow(x, 2);
    }
    else if (x > 1.4) {
      Q = log(x + 7 * sqrt(abs(x+a)));
    }
    else {
      Q = a * pow(x, 2) + 7 * sqrt(x);
    }

    printf("\nx = %0.1f => Q = %0.2f", x, Q);
  }
  puts("");
}

void p3 () {
  int u, y, z;

  do {
    puts("\3nIntroduceti o cifră de la 2 la 9:");
    scanf("%d", &z);
  } while (z < 2 || z > 9);

  puts("");
  for (y = 0; y < z; y++) {
    for (u = 0; u <= y; u++) {
      printf("%d", z - y);
    }
    puts("");
  }
}

int main() {
  int optiune;

  puts("Introduceti numarul de indice al unei din urmatoarele optiuni:");
  puts("1. Produs în ciclu");
  puts("2. Calcul după formulă în ciclu");
  puts("3. Triunghi în ciclu\n");

  scanf("%d", &optiune);

  switch (optiune) {
    case 1:
      p1();
      break;
    case 2:
      p2();
      break;
    case 3:
      p3();
      break;
    default:
      puts("Nu ati ales o optiune valida.");
  }

  return 0;
}
