#define DATA_MEMORY
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct data_memory 
{
    struct data_memory_element
    {
        char element_name[30];
        int value;
    };
};

void store_mem(int position,struct data_memory *dm,char * input_name,int input_value);

int get_mem_location(char * input_name,struct data_memory *dm);
