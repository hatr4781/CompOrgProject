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

    struct PIPE_DE DE_init = {0, 0, 0, 0, 0, 0, 0, 0, "NOP"};
    struct PIPE_DE shDE_init = {0, 0, 0, 0, 0, 0, 0, 0, "NOP"};

    struct PIPE_EM EM_init = {0, 0, 0, 0, 0, "NOP"};
    struct PIPE_EM shEM_init = {0, 0, 0, 0, 0, "NOP"};

    struct PIPE_MW MW_init = {0, 0, 0, 0, "NOP"};
    struct PIPE_MW shMW_init = {0, 0, 0, 0, "NOP"};

    FD = &FD_init;
    shFD = &shFD_init;

    DE = &DE_init;
    shDE = &shDE_init;

    EM = &EM_init;
    shEM = &shEM_init;

    MW  = &MW_init;
    shMW = &shMW_init;

    branched = 0;
    control_hazard = 0;

    while(FD->PC != 0){
        if(FD->PC == 10){
            printf("COPY ARRAY\n");
        }
        if(FD->PC == 30){
            printf("BUBBLE SORT\n");
        }
        if(FD->PC == 70){
            printf("INSERTION SORT\n");
        }
        if(FD->PC == 120){
            printf("CHECK RESULT\n");
        }
        //printf("PC = %d, ", FD->PC);
        clock_cycle();
    }
    printf("Memory[6] = %d, Memory[7] = %d, Memory[8] = %d, Memory[9] = %d\n", memory[6], memory[7], memory[8], memory[9]);
}

