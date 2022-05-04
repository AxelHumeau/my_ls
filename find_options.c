/*
** EPITECH PROJECT, 2021
** B-PSU-100-PAR-1-1-myls-axel.humeau
** File description:
** find_options
*/

#include "my_ls.h"

void invalid_option(char i_o)
{
    my_puterror("my_ls: invalid option -- ");
    my_puterror(&i_o);
    my_puterror("\n");
    exit(84);
}

void find_options_switch2(char *str, option_presence_t *options, int i)
{
    switch(str[i]) {
    case 'a' :
        options->a = 1;
        break;
    default :
        invalid_option(str[i]);
    }
}

void find_options_switch(char *str, option_presence_t *options, int i)
{
    switch (str[i]) {
    case 'l' :
        options->l = 1;
        break;
    case 'r' :
        options->r = 1;
        break;
    case 'R' :
        options->R = 1;
        break;
    case 'd' :
        options->d = 1;
        break;
    case 't' :
        options->t = 1;
        break;
    default :
        find_options_switch2(str, options, i);
    }
}

void find_options(char *str, option_presence_t *options)
{
    for (int i = 1; str[i] != '\0'; i++)
        find_options_switch(str, options, i);
}
