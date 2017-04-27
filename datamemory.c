#include "datamemory.h"
#include "main.h"

void store_mem(int position, struct data_memory *dm, char * input_name, int input_value)
{
	if(position >= 1024)
	{
		printf("Need more space for memory");
		exit(2);
	}

    strcpy(dm->memory[position].element_name, input_name);
    dm->memory[position].value = input_value;
    return;
}

int get_memory_location(char * input_name, struct data_memory *dm)
{
    int i;
    for(i=0; i<1024; i++)
    {
        if(!strcmp(input_name, dm->memory[i].element_name))
            return i;
    }
}
