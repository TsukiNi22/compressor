/**************************************************************\

 ██╗  ██╗ █████╗ ██████╗ ████████╗ █████╗ ███╗   ██╗██╗ █████╗ 
 ╚██╗██╔╝██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║██║██╔══██╗
  ╚███╔╝ ███████║██████╔╝   ██║   ███████║██╔██╗ ██║██║███████║
  ██╔██╗ ██╔══██║██╔══██╗   ██║   ██╔══██║██║╚██╗██║██║██╔══██║
 ██╔╝ ██╗██║  ██║██║  ██║   ██║   ██║  ██║██║ ╚████║██║██║  ██║
 ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝

Edition:
##  11/05/2025 by Tsukini

File Name:
##  help.c

File Description:
##  Display help
\**************************************************************/

#include "error.h"
#include <stdio.h>

/* display the help for the flags '-h' and '--help' */
int flag_help(void)
{
    int res = OK;

    /* display the help */
    res = printf("DESCRIPTION:\n"
    "\tA file compressor with a littel bit of loss (depend of the precision)\n"
    "\tThe ouput file extension is \'.crped\'\n\n"
    "USAGE:\n"
    "\t./compressor file_name1 [file_name2 ...] -u\n"
    "\t./compressor file_name1 [file_name2 ...] [-p precision] [-r round]\n"
    "\t./compressor file_name1 [file_name2 ...] -c [-p precision] [-r round]\n"
    "\t./compressor -h\n\n"
    "FLAG:\n"
    "\t- \'-h\' or \'--help\'\n"
    "\t\tDisplay this help\n"
    "\t- \'-u\' or \'--undo\'\n"
    "\t\tDecompress the given files (default: compression mode)\n"
    "\t- \'-c\' or \'--calculate\'\n"
    "\t\tGive the compression percentage with the given parameters\n"
    "\t- \'-p precision\' or \'--precision precision\'\n"
    "\t\tChange the precision used (default: 17)\n"
    "\t- \'-r round\' or \'--round round\'\n"
    "\t\tChange the number of round used to compresse the files (default: auto (~50%% compression))\n\n"
    "INFORMATION:\n"
    "\t- Files name always before the flag, else there will be ignored.\n"
    "\t- The precision will be the number of bits used to store some data and change the rapidity of the compression.\n"
    "\t  (min: 1; recommended: 17; max: 25)\n"
    "\t  default: 17\n"
    "\t- The round is for the number of time 64 bits will be compressed in \'39 + precision\', that will change the compression percentage.\n"
    "\t  (min: 0; max: limited by the size of your file;)\n"
    "\t  default: until 50%% of compression\n"
    "\t- You can use the \'-c\' or \'--calculate\' to know the compression percentage with the actual input\n");
    if (res < 0)
        return KO;
    return OK;
}
