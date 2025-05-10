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
##  init_data.c

File Description:
##  Init the main data
\**************************************************************/

#include "compressor.h"
#include "error.h"
#include <stddef.h>

/* init the main struct with default value */
int init_data(main_data_t *data)
{
    /* function argument check */
    if (!data)
        return KO;

    /* initialisation of the boolean */
    data->calculate = false;
    data->undo = false;
    data->help = false;
    data->err_sys = false;

    /* init the main struct with default value */
    data->precision = 17;
    data->round = -1;
    data->max = 0;
    data->redution_size = INT_BITS_SIZE + data->precision + ZERO_NB_SIZE + OVERFLOW_SIZE;
    
    /* set to 0 the global var */
    data->file = NULL;
    data->compressed_file = NULL;
    data->round_nb = 0;
    return OK;
}
