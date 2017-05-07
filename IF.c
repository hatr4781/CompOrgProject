#include <stdlib.h>
#include "IF.h"
#include "Load_Program.h"


//fetch next instruction and set instruction struct to it
void Instruction_Fetch(){

    if(branched){

    }

    shFD->inst_fetched = memory[shFD->PC];

    printf("PC = %d\n FETCHED INSTRUCTION: %8x\n", shFD->PC, shFD->inst_fetched);
    shFD->PC = shFD->PC + 1;

    return;
}