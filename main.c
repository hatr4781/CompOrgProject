#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include "main.h"
#include "Load_Program.h"

int main(){
    ssize_t read;
    ssize_t len;
    int i;
    char line[10];
    char* eptr;
    int * instpointer;
    uint32_t inst_fetched;
    int upper[50];
    
    //char string[] = "0x46902800";
    //inst_fetched = strtol(string, &eptr, 0);
    //uint32_t a = (inst_fetched >> 4);
    //uint16_t b = (inst_fetched >> 16);
    //printf("%d = %lu = %lu", string, inst_fetched, a);

    instpointer = Initialize_Simulation_Memory();

    for (i=11; i < 50; i++) {
        memory[i] = *(instpointer+i);
        upper[i] = (memory[i] >> 16);
        printf( "(instruction line + %d) : fetched: %d, upper four: %d\n", i, memory[i], upper[i]);
        struct Instruction * inst = Instruction_Fetch();
        inst = Instruction_Decode(inst);
       // inst = Instruction_Execute(inst);
        printf("function:%s,rd_val:%d,rt_val:%d,rs_val:%d,Immed:%d\n",inst->name, inst->rd_val, inst->rt_val, inst->rs_val, inst->immed);
    }
    if(upper[11] == 0x2406){
        printf("YES\n");
    }
    else{
        printf("BOO\n");
    }

}

