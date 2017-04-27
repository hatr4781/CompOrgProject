#include "MEM.h"

//Accessing memory for load/store instructions
struct Instruction* Instruction_Mem(struct Instruction* inst){
    uint32_t val;
    if(inst->name == "LB"){
        val = 0x000000ff & memory[inst->mem_address];
        if((val & 0x80)== 1){
            val = 0xffffff00 | val;
        }
        else{
            val = 0x00000000 & val;
        }
    }
    else if(inst->name == "LBU") {
        val = 0x000000ff & memory[inst->mem_address];
    }
    else if(inst->name == "LHU"){
        val = 0x0000ffff & memory[inst->mem_address];
    }
}