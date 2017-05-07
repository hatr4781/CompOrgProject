#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include "main.h"


int main(){
    /*
    ssize_t read;
    ssize_t len;
    char line[10];
    char* eptr;
    uint32_t inst_fetched;
    int upper[50];
     */
    //char string[] = "0x46902800";
    //inst_fetched = strtol(string, &eptr, 0);
    //uint32_t a = (inst_fetched >> 4);
    //uint16_t b = (inst_fetched >> 16);
    //printf("%d = %lu = %lu", string, inst_fetched, a);

    Initialize_Simulation_Memory();

    //Initialize sp and fp
    reg[29] = memory[0];
    reg[30] = memory[1];

    FD = malloc(sizeof(struct PIPE_FD));
    shFD = malloc(sizeof(struct PIPE_FD));

    DE = malloc(sizeof(struct PIPE_DE));
    shDE = malloc(sizeof(struct PIPE_DE));

    EM = malloc(sizeof(struct PIPE_EM));
    shEM = malloc(sizeof(struct PIPE_EM));

    MW = malloc(sizeof(struct PIPE_MW));
    shMW = malloc(sizeof(struct PIPE_MW));

    struct PIPE_FD FD_init = {memory[5], 0};
    struct PIPE_FD shFD_init = {0, 0};

    struct PIPE_DE DE_init = {0, 0, 0, 0, 0, 0, "NOP"};
    struct PIPE_DE shDE_init = {0, 0, 0, 0, 0, 0, "NOP"};

    struct PIPE_EM EM_init = {0, 0, 0, 0, 0, "NOP"};
    struct PIPE_EM shEM_init = {0, 0, 0, 0, 0, "NOP"};

    struct PIPE_MW MW_init = {0, 0, 0, "NOP"};
    struct PIPE_MW shMW_init = {0, 0, 0, "NOP"};

    FD = &FD_init;
    shFD = &shFD_init;

    DE = &DE_init;
    shDE = &shDE_init;

    EM = &EM_init;
    shEM = &shEM_init;

    MW  = &MW_init;
    shMW = &shMW_init;


    while(PC != 0){
        if(PC == 10){
            printf("COPY ARRAY\n");
        }
        if(PC == 30){
            printf("BUBBLE SORT\n");
        }
        if(PC == 70){
            printf("INSERTION SORT\n");
        }
        if(PC == 120){
            printf("CHECK RESULT\n");
        }
        printf("PC = %d, ", PC);
        clock_cycle();
        /*
        fetched_inst = Instruction_Fetch();
        decoded_inst = Instruction_Decode(fetched_inst);
        //printf("%s -> rs_val = %d, rt_val = %d, rd_val = %d, immed = %d, addr = %d\n", decoded_inst->name, decoded_inst->rs_val, decoded_inst->rt_val, decoded_inst->rd_val, decoded_inst->immed, decoded_inst->addr);
        executed_inst = Instruction_Execute(decoded_inst);
        printf("%s -> rs_val = %d, rt_val = %d, rd_val = %d, immed = %d, addr = %d\n", executed_inst->name, executed_inst->rs_val, executed_inst->rt_val, executed_inst->rd_val, executed_inst->immed, executed_inst->addr);
        memmed_inst = Instruction_Memory(executed_inst);
        Instruction_WriteBack(memmed_inst);
        printf("Read WB regs: rt_val = %d, rd_val = %d\n", reg[memmed_inst->rt], reg[memmed_inst->rd]);
         */
    }
    printf("Memory[6] = %d, Memory[7] = %d, Memory[8] = %d, Memory[9] = %d\n", memory[6], memory[7], memory[8], memory[9]);
    /*
        while(PC != 0){
        //memory[i] = *(instpointer+i);
        //upper[i] = (memory[i] >> 16);
        struct Instruction* inst = Instruction_Fetch();
        struct Instruction* decode_pointer;
        printf( "(instruction line + %d) : fetched: %08x, upper four: %d\n", PC, inst->encoded_inst, upper[PC]);
        printf("encoded: %8x\n", inst->encoded_inst);
        decode_pointer = Instruction_Decode(inst);
        printf("Name: %s\n", inst->name);
       // inst = Instruction_Execute(inst);
        printf("Inst Type:%d,function:%s,rd_val:%d,rt_val:%d,rs_val:%d,Immed:%d\n",inst->instruction_type,inst->name, inst->rd_val, inst->rt_val, inst->rs_val, inst->immed);
    }
    if(upper[11] == 0x2406){
        printf("YES\n");
    }
    else{
        printf("BOO\n");
    }
*/
}

