#include <stdlib.h>
#include "IF.h"
#include "Load_Program.h"


//fetch next instruction and set instruction struct to it
struct Instruction* Instruction_Fetch(){
    uint32_t inst_fetched;
    Initialize_Simulation_Memory();
    inst_fetched = (UNSIGNED_WORD) memory[PC];
    struct Instruction *new_inst;
    new_inst = malloc(sizeof(struct Instruction));
    new_inst->encoded_inst = inst_fetched;
    //PC = PC + 1;
    return new_inst;
}