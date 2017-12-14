#include <stdio.h>

void triunghi1(int latura) {
  int i = 0, sum = 0, cols = latura;

  while (i < latura) {
    int num = i + 1;
    int col = 0;

    while (col < cols) {
      printf("%d", num);
      sum += num;
      col++;
    }

    puts("");
    cols--;
    i++;
  }

  printf("\nSuma: %d\n", sum);
}

void triunghi2(int latura) {
  int i = 0, sum = 0, cols = latura;

  while (i < latura) {
    int num = 1;
    int col = 0;

    while (col < cols) {
      printf("%d", num);
      sum += num;
      col++;
      num++;
    }

    puts("");
    cols--;
    i++;
  }

  printf("\nSuma: %d\n", sum);
}

void triunghi3(int latura) {
  int sum = 0;

  for (int i = 0; i < latura; i++) {
    for (int j = 0; j <= i; j++) {
      printf("%d", latura - i);
      sum += latura - i;
    }
    puts("");
  }

  printf("\nSuma: %d\n", sum);
}

int main() {
  int optiune, latura;

  do {
    printf("Introduceti tipul triunghiulul (1, 2 sau 3): ");
    scanf("%d", &optiune);
  } while (optiune < 1 || optiune > 3);

  do {
    printf("Introduceti latura triunghiului (2..9): ");
    scanf("%d", &latura);
  } while (latura < 2 || latura > 9);

  printf("Ati ales triunghiul %d\n\n", optiune);

  switch(optiune) {
    case 1:
      triunghi1(latura);
      break;
    case 2:
      triunghi2(latura);
      break;
    case 3:
      triunghi3(latura);
      break;
    default:
      puts("Nu ati ales un tip valid al triunghiului.");
  }

  return 0;
}
