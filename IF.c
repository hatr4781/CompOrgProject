#include <stdlib.h>
#include "IF.h"
#include "Load_Program.h"


//fetch next instruction and set instruction struct to it
void Instruction_Fetch(){
    shFD->inst_fetched = memory[FD->PC];
    //printf("PC = %d\n FETCHED INSTRUCTION: %8x\n", FD->PC, shFD->inst_fetched);
    shFD->PC = FD->PC + 1;
    return;
}