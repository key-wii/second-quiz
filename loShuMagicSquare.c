#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void shuffle(int array[3][3])
{
    int ran, ran2, temp;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp =  array[i][j];
            ran = rand() % 3;
            ran2 = rand() % 3;
            array[i][j] =  array[ran][j];
            array[ran][j] = temp;
            
            temp =  array[i][j];
            ran = rand() % 3;
            ran2 = rand() % 3;
            array[i][j] =  array[i][ran];
            array[i][ran] = temp;
        }
    }
}

bool isMagic(int array[3][3]) {
    int sumRow0 = 0; int sumRow1 = 0; int sumRow2 = 0;
    int sumCol0 = 0; int sumCol1 = 0; int sumCol2 = 0;
    int sumDiaDown = 0; int sumDiaUp = 0;
    for (int i = 0; i < 3; i++) {
        sumRow0 += array[0][i];
        sumRow1 += array[1][i];
        sumRow2 += array[2][i];
        sumCol0 += array[i][0];
        sumCol1 += array[i][1];
        sumCol2 += array[i][2];
        sumDiaDown += array[i][i];
        sumDiaUp += array[2 - i][i];
    }
    if (sumRow0 != 15 || sumRow1 != 15 || sumRow2 != 15 ||
        sumCol0 != 15 || sumCol1 != 15 || sumCol2 != 15 ||
        sumDiaDown != 15 || sumDiaUp != 15) return false;
    return true;
}

void print2dArray(int array[3][3]) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (j == 0) printf("[");
        printf("%d", array[i][j]);
        if (j != 3 - 1) printf(" ");
        if (j == 3 - 1) printf("]\n");
      }
   }
}

int main() {
    time_t t;
    srand((unsigned) time(&t));
    int count = -1;
    int magicSquare[3][3];

    do {
        //Fill square then shuffle its contents
        int num = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                magicSquare[i][j] = num;
                num++;
            }
        }
        shuffle(magicSquare);
        count++;
    } while (!isMagic(magicSquare));
   
    printf("%d", count);
    printf(" tries before success\n");
    print2dArray(magicSquare);

   return 0;
}