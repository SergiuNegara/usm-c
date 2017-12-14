#include <stdio.h>

// Se citeste de la tastatura un sir de n numere intregi.
// Sa se afiseze maximul dintre elementele pare ale sirului.

int main() {
  int length;
  int max = 0;

  do {
    puts("Introduceti lungimea tabloului (de la 2 la 10):");
    scanf("%d", &length);
  } while (length < 2 || length > 10);

  int numbers[length];

  for (int i = 1; i < length + 1; i++) {
    printf("\nIntroduceti numarul natural #%d: ", i);
    scanf("%d", &numbers[i-1]);
  }

  printf("\nMarimea tabloului introdus: %d", length);

  puts("\n\nContinutul tabloului:");

  for (int i = 0; i < length; i++) {
    printf("\n%d: %d", i, numbers[i]);

    if (numbers[i] % 2 == 0) {
      if (numbers[i] > max) {
        max = numbers[i];
      }
    }
  }

  if (max == 0) {
    puts("\n\nNu au fost introduse numere pare.");
  } else {
    printf("\n\nNumarul par maxim: %d\n", max);
  }

  return 0;
}
