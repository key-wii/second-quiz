#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//const int SIZE = 3;

void shuffle(int array[3][3], size_t n)
{
    int ran, ran2;
    for (int i=0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ran = rand() % 3;
            ran2 = rand() % 3;
            int temp =  array[i][j];
            array[i][j] =  array[ran][j];
            array[ran][j] = temp;
        }
    }
}

int main() {
    time_t t;
    srand((unsigned) time(&t));

    int num = 1;
    int magicSquare[3][3];

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
          magicSquare[i][j] = num;
          num++;
      }
   }
   shuffle(magicSquare, 9);
   
   printf("Two Dimensional array elements:\n");
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (j == 0) printf("[");
        printf("%d", magicSquare[i][j]);
        if (j != 3 - 1) printf(" ");
        if (j == 3 - 1) printf("]\n");
      }
   }

   return 0;
}