/*
** EPITECH PROJECT, 2021
** B-PSU-100-PAR-1-1-myls-axel.humeau
** File description:
** sort
*/

#include "my_ls.h"

int search_min_time(int i, info_file_t *file)
{
    int index_min = i;

    for (int j = i; file[j].name != NULL; j++) {
        if (file[j].time > file[index_min].time)
            index_min = j;
    }
    return (index_min);
}

void time_sort(info_file_t *file)
{
    info_file_t tmp;
    int index_min;

    for (int i = 0; file[i].name != NULL; i++) {
        index_min = search_min_time(i, file);
        tmp = file[i];
        file[i] = file[index_min];
        file[index_min] = tmp;
    }
}

int search_min_alpha(int i, info_file_t *file)
{
    int index_min = i;

    for (int j = i; file[j].name != NULL; j++) {
        if (my_strcmp(file[j].name, file[index_min].name) < 0)
            index_min = j;
    }
    return (index_min);
}

void alpha_sort(info_file_t *file)
{
    info_file_t tmp;
    int index_min;

    for (int i = 0; file[i].name != NULL; i++) {
        index_min = search_min_alpha(i, file);
        tmp = file[i];
        file[i] = file[index_min];
        file[index_min] = tmp;
    }
}

void reverse_sort(info_file_t *file)
{
    info_file_t tmp;
    int size = 0;

    for (; file[size].name != NULL; size++);
    for (int i = 0; i < size / 2; i++) {
        tmp = file[i];
        file[i] = file[size - 1 - i];
        file[size - 1 - i] = tmp;
    }
}
