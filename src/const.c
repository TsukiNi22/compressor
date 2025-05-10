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
##  const.c

File Description:
##  Global const
\**************************************************************/

#include "compressor.h"

/* char for the flag with '-' */
char const flags[] = {
    'h',
    'u',
    'p',
    'r',
    'c'
};

/* full flag with '--' */
char const *full_flags[] = {
    "--help",
    "--undo",
    "--precision",
    "--round",
    "--calculate"
};

/* number of argument needed by a flag */
int const flags_argc[] = {
    -1,  // h
    -1,  // u
    1,   // p
    1,   // r
    -1   // c
};

/* flag functions */
int (* const flag_functions[])(main_data_t *, int const, char const *[]) = {
    &flag_null,         // h
    &flag_undo,         // u
    &flag_precision,    // p
    &flag_round,        // r
    &flag_calculate     // c
};
