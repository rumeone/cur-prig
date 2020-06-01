#include <stdio.h>
#include <wchar.h>

void bubbleSort(int* arr, char* arr2, char** arr3, int sizeArr);
void func(int num, char** word, int* wc, char* is);
void error_mem(char* buf);
void error_words(char** word);
void error_int(int* buf);
void print_in_file(FILE* file, int num_word, int* f_wcnt, char* f_is_first, char** f_words);
int get_sym(FILE* fi, int symb);
