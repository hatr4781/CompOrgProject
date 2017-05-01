#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include "main.h"


int main(){
    ssize_t read;
    ssize_t len;
    int i;
    char line[10];
    char* eptr;
    uint32_t inst_fetched;
    int upper[50];

    //char string[] = "0x46902800";
    //inst_fetched = strtol(string, &eptr, 0);
    //uint32_t a = (inst_fetched >> 4);
    //uint16_t b = (inst_fetched >> 16);
    //printf("%d = %lu = %lu", string, inst_fetched, a);



    for (i=9; i < 20; i++) {
        //memory[i] = *(instpointer+i);
        //upper[i] = (memory[i] >> 16);
        struct Instruction * inst = Instruction_Fetch();
        printf( "(instruction line + %d) : fetched: %08x, upper four: %d\n", i, inst->encoded_inst, upper[i]);
        printf("encoded: %08x\n", inst->encoded_inst);
        inst = Instruction_Decode(inst);
       // inst = Instruction_Execute(inst);
        printf("Inst Type:%d, function:%s,rd_val:%d,rt_val:%d,rs_val:%d,Immed:%d\n",inst->instruction_type,inst->name, inst->rd_val, inst->rt_val, inst->rs_val, inst->immed);
    }
    if(upper[11] == 0x2406){
        printf("YES\n");
    }
    else{
        printf("BOO\n");
    }

}

