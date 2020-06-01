#include "func.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

void bubbleSort(int* arr, char* arr2, char** arr3, int sizeArr)
{
    int temp;
    char temp1;
    char* temp2;

    for (int i = 0; i < sizeArr - 1; ++i) {
        for (int j = sizeArr - 1; j > i; j--) {
            if ((arr[j - 1] > arr[j])) {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;

                temp1 = arr2[j - 1];
                arr2[j - 1] = arr2[j];
                arr2[j] = temp1;

                temp2 = arr3[j - 1];
                arr3[j - 1] = arr3[j];
                arr3[j] = temp2;
            }
        }
    }
}

void func(int num, char** word, int* wc, char* is)
{
    for (int i = 0; i < num; i++) {
        wc[i]++;
        for (int j = 0; j < num; j++) {
            if (i != j && scmp(word[i], word[j]) == 0) {
                if (wc[i]++ == 1 && i < j)
                    is[i] = 1;
            }
        }
    }
}

void error_mem(char* buf)
{
    if (buf == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(-1);
    }
}

void error_words(char** word)
{
    if (word == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(-1);
    }
}

void error_int(int* buf)
{
    if (buf == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(-1);
    }
}

void print_in_file(FILE* file, int num_word, int* f_wcnt, char* f_is_first, char** f_words)
{
    for (int i = num_word; i > 0; i--) {
        if ((f_wcnt[i] > 1 && f_is_first[i]))
            fprintf(file, "%s = %d\n", f_words[i], f_wcnt[i]);
    }
}

int get_sym(FILE* fi, int symb)
{
    while (fgetwc(fi) != WEOF) {
        symb++;
    }
    return symb;
}






