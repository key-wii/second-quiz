#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//const int SIZE = 3;

void shuffle(int array[3][3], size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < 3 - 1; i++) 
        {
            for(int j = 0; j < 3; j++) {
                size_t k = i + rand() / (RAND_MAX / (3 * 3));
                int t = array[i][j];
                array[i][k] = array[i][i];
                array[i][i] = t;
            }
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
         printf("%d ", magicSquare[i][j]);
         if (j == 3 - 1) {
            printf("\n");
         }
      }
   }

   return 0;
}