#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include "main.h"


int main(){
    ssize_t read;
    ssize_t len;
    char line[10];
    char* eptr;
    uint32_t inst_fetched;
    int upper[50];
    //char string[] = "0x46902800";
    //inst_fetched = strtol(string, &eptr, 0);
    //uint32_t a = (inst_fetched >> 4);
    //uint16_t b = (inst_fetched >> 16);
    //printf("%d = %lu = %lu", string, inst_fetched, a);


    for (PC=10; PC < 75; PC++) {
        //memory[i] = *(instpointer+i);
        //upper[i] = (memory[i] >> 16);
        struct Instruction* inst = Instruction_Fetch();
        struct Instruction* decode_pointer;
        printf( "(instruction line + %d) : fetched: %08x, upper four: %d\n", PC, inst->encoded_inst, upper[PC]);
        printf("encoded: %8x\n", inst->encoded_inst);
        decode_pointer = Instruction_Decode(inst);
        printf("Name: %s\n", inst->name);
       // inst = Instruction_Execute(inst);
        printf("Inst Type:%d,rd_val:%d,rt_val:%d,rs_val:%d,Immed:%d\n\n",inst->instruction_type,inst->rd_val, inst->rt_val, inst->rs_val, inst->immed);
    }
    if(upper[11] == 0x2406){
        printf("YES\n");
    }
    else{
        printf("BOO\n");
    }

}

