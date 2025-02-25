/*
** EPITECH PROJECT, 2025
** edit_ouput.c
** File description:
** Edit ouput functions
*/

#include "define.h"
#include "write.h"
#include "error.h"

int reset_ouput(int fd)
{
    return my_printf("%O%c[0m", fd, ESC);
}

int set_strong(int fd)
{
    return my_printf("%O%c[1m", fd, ESC);
}

int set_color(int fd, color_t color)
{
    return my_printf("%O%c[%dm", fd, ESC, color);
}

int set_back_color(int fd, back_color_t back)
{
    return my_printf("%O%c[%dm", fd, ESC, back);
}

int set_color_rgb(int fd, unsigned char r,
    unsigned char g, unsigned char b)
{
    return my_printf("%O%c[38;2;%d;%d;%dm", fd, ESC, r, g, b);
}
