#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CUL_STD "\x1B[0m" // culoarea normala
#define CUL_ROSU "\x1B[31m" // culoarea rosie
#define CUL_GALB "\x1B[33m" // culoarea galbena

int main() {

  int option, n_min = 5, n_max = 50, n, r;
  time_t t;

  do { // intrebam valoarea lui n atat timp cat ea nu e valida
    printf("\nIntroduceți valoarea lui n (%d <= n <= %d): ", n_min, n_max);
    scanf("%d", &n);
  } while (n < n_min || n > n_max); // validare: daca n < n_min sau n > n_max, mai intrebam o data

  int array[n]; // cand avem valoarea lui n, initializam array-ul

  printf("\nSe generează %d valori numerice aleatorii...\n", n);

  puts("\nLista generată:");

  for (int i = 0; i < n; i++) {
    r = rand() % 100; // generam valoare aleatorie de la 0 la 100
    array[i] = rand() % 50 < 25 ? r : r * -1; // generam pozitivitate aleatorie

    printf("%d", array[i]);

    if (i + 1 < n) printf(", ");
    if (i + 1 == n) puts("");
  }

  do {
    puts("\nIntroduceți una din opțiuni pentru a evidenția numerele:");
    puts("1: divizibile cu 5");
    puts("2: impare și negative");
    puts("3: care satisfac condiția: |Ai| < i^2");
    scanf("%d", &option);
  } while (option != 1 && option != 2 && option != 3);

  switch(option) {
    case 1: {
      printf("\n%s%s%s\n", CUL_GALB, "Numerele divizibile cu 5 (cu roșu):", CUL_STD);
      for (int i = 0; i < n; i++) {
        printf("%s%d", array[i] % 5 == 0 ? CUL_ROSU : CUL_STD, array[i]);

        if (i + 1 < n) printf("%s, ", CUL_STD);
      }
      break;
    }
    case 2: {
      printf("\n%s%s%s\n", CUL_GALB, "Numerele impare și negative (cu roșu):", CUL_STD);

      for (int i = 0; i < n; i++) {
        printf("%s%d", array[i] < 0 && array[i] % 2 != 0 ? CUL_ROSU : CUL_STD, array[i]);

        if (i + 1 < n) printf("%s, ", CUL_STD);
      }
      break;
    }
    case 3: {
      printf("\n%s%s%s\n", CUL_GALB, "Numerele care satisfac condiția: |Ai| < i^2 (cu roșu):", CUL_STD);

      for (int i = 0; i < n; i++) {
        printf("%s%d", abs(array[i]) < i * i ? CUL_ROSU : CUL_STD, array[i]);

        if (i + 1 < n) printf("%s, ", CUL_STD);
      }
      break;
    }
    default: break;
  }

  return 0;
}
