/*
** EPITECH PROJECT, 2025
** help.c
** File description:
** Display help
*/

#include "write.h"

int flag_help(void)
{
    return my_printf("DESCRIPTION:\n"
    "\tA file compressor with a littel bit of loss (depend of the precision)\n"
    "\tThe ouput file extension is \'.crped\'\n\n"
    "USAGE:\n"
    "\t./compressor file_name1 [file_name2 ...] [-p precision] [-r round]\n"
    "\t./compressor file_name1 [file_name2 ...] -c [-p precision] [-r round]\n"
    "\t./compressor -h\n\n"
    "INFORMATION:\n"
    "\t- The precision will be the number of bits used to store some data and change the rapidity of the compression.\n"
    "\t  (min: 1; recommended: 17; max: 25)\n"
    "\t  default: 17\n"
    "\t- The round is for the number of time 64 bits will be compressed in \'39 + precision\', that will change the compression percentage.\n"
    "\t  (min: 0; max: limited by the size of your file;)\n"
    "\t  default: until 50%% of compression\n"
    "\t- You can use the \'-c\' or \'--calculate\' to know the compression percentage with the actual input\n");
}
