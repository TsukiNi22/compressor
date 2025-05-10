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
##  main.c

File Description:
##  Main of the project
\**************************************************************/

#include "compressor.h"
#include "error.h"
#include <stdio.h>
#include <stdbool.h>

/* main of the compressor */
int main(int const argc, char const *argv[])
{
    /* initialisation of the main data struct and value return checker */
    main_data_t data = {0};
    int res = 0;

    /* function argument check */
    if (!argv)
        return KO;

    /* main execution */
    res = compressor(argc, argv, &data);

    /* check of the return of the execution */
    if (res == KO || res == FATAL_ERR) {
        if (res != FATAL_ERR)
            free_data(&data);
        if (!data.err_sys)
            fprintf(stderr, "compressor: An error has occurred, execution has been interrupted.");
        return KO;
    }
    return free_data(&data);
}
