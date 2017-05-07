//
// Created by Ha on 5/5/2017.
//

#include "clock_cycle.h"

void clock_cycle(){
    Instruction_Fetch();
    Instruction_WriteBack();
    Instruction_Decode();
    Instruction_Execute();
    Instruction_Memory();
    Hazard_Forwarding();
    Shadow_to_Pipeline();
}