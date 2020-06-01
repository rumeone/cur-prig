#include "func.h"
#include "string.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "func.h"
#include <wchar.h>

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Неверное число аргументов\n");
        return 0;
    }
    /*if ((argc == 3) && (!(scmp(argv[1], srtcat) == 0))) {
        printf("Введите первый аргумент как Input.txt\n");
        return 0;
    } else if ((argc == 3) && (!(scmp(argv[2], "Output.txt") == 0))) {
        printf("Введите второй аргумент как Output.txt\n");
        return 0;
    }*/
    printf("Для просмотра файла используете команду cat 'название файла'\n");
    setlocale(LC_ALL, "ru_RU.UTF-8");
    char** words = NULL; // указатель на слова
    int num_words = 0; // кол во слов
    char* delim = " \t\n,.!?:";
    int size_file = 0; //размер файла

    FILE* fp = fopen(argv[1], "r+");
    if (!fp) {
        printf("Error %s\n", argv[1]);
        return -1;
    }

    FILE* f = fopen(argv[2], "wb");;
    if (!f) {
        printf("Error %s\n", argv[2]);
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    size_file = ftell(fp); //находим размер файла
    char* buffer = calloc(size_file + 1, sizeof(char)); //буфер
    error_mem(buffer);
    int num_sym = 0;
    fseek(fp, 0, SEEK_SET);
    fread(buffer, 1, size_file, fp);

    fprintf(f, "%s\n", buffer);
    fclose(fp);
    char* istr = stok(buffer, delim);
    error_mem(istr);
    while (istr) {
        words = realloc(words, (num_words + 1) * sizeof(char*));
        words[num_words++] = istr;
        istr = stok(NULL, delim);
    }
    fp = fopen(argv[1], "r+");
    num_sym = get_sym(fp, num_sym);
    fclose(fp);
    
    fprintf(f, "\nКоличество символов в файле :%d\n", num_sym);
    fprintf(f, "Количество слов в файле :%d\n\n", num_words);

    int* wcnt = calloc(num_words, sizeof(int));
    error_int(wcnt);
    char* is_first = calloc(num_words, sizeof(char));
    error_mem(is_first);
    func(num_words, words, wcnt, is_first);

    bubbleSort(wcnt, is_first, words, num_words);
    print_in_file(f, num_words, wcnt, is_first, words);
    fclose(f);
    fclose(fp);
    free(buffer);
    free(words);
    free(wcnt);
    free(is_first);
    return 0;
}