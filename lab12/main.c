#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Se considera tabloul A[1..n,1..m] de numere intregi, unde n, m <= 20.
// Sa se scrie un program care determina elementul minim si pozitia lui.

int main() {
  int length[2], min[3], r;
  time_t t;

  for (int i = 0; i < 2; i++) {
    do {
      printf("Introduceti numarul de %s ale tabloului (de la 1 la 20): ", i == 0 ? "randuri" : "coloane");
      scanf("%d", &length[i]);
    } while (length[i] < 1 || length[i] > 20);
  }

  int array[length[0]][length[1]];

  srand((unsigned) time(&t));

  for (int i = 0; i < length[0]; i++) {
    for (int j = 0; j < length[1]; j++) {

      r = rand() % 100;

      array[i][j] = rand() % 50 < 25 ? r : r * -1;

      if ((i == 0 && j == 0) || min[0] > array[i][j]) {
        min[0] = array[i][j];
        min[1] = i;
        min[2] = j;
      }
    }
  }

  printf("\nTabloul cu %d randuri si %d coloane\n", length[0], length[1]);
  puts("de numere intregi aleatorii generate");
  puts("de la -100 la 100:\n");

  for (int i = 0; i < length[0]; i++) {
    for (int j = 0; j < length[1]; j++) {
      printf("%4d", array[i][j]);
    }
    puts("");
  }

  puts("\nNumarul minim generat:");
  printf("%10s: %4d\n", "valoarea", min[0]);
  printf("%10s: %4d\n", "randul", min[1] + 1);
  printf("%10s: %4d\n", "coloana", min[2] + 1);

  return 0;
}
