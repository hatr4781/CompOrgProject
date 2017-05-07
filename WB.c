//
// Created by Ha on 4/27/2017.
//

#include <stdlib.h>
#include "WB.h"
#include "string.h"
void Instruction_WriteBack()
{
    if(WB_inst == NULL){
        return;
    }
    if(!strcmp(WB_inst->name, "NOP")) {
        return;
    }

    else if(!strcmp(WB_inst->name, "ADD")) {
        reg[WB_inst->rd] = WB_inst->rd_val;
    }

    else if(!strcmp(WB_inst->name, "ADDI")) {
        reg[WB_inst->rt] = WB_inst->rt_val;
    }


    else if(!strcmp(WB_inst->name, "ADDIU")) {
        reg[WB_inst->rt] = WB_inst->rt_val;
    }

    else if(!strcmp(WB_inst->name, "ADDU")) {
        reg[WB_inst->rd] = WB_inst->rd_val;
    }
    else if(!strcmp(WB_inst->name, "SUB")) {
        reg[WB_inst->rd] = WB_inst->rd_val;
    }

    else if(!strcmp(WB_inst->name, "SUBU")) {
        reg[WB_inst->rd] = WB_inst->rd_val;
    }

    else if(!strcmp(WB_inst->name, "AND")) {
        reg[WB_inst->rd_val] = WB_inst->rd_val;
    }

    else if(!strcmp(WB_inst->name, "ANDI")) {
        reg[WB_inst->rt] = WB_inst->rt_val;
    }

    else if(!strcmp(WB_inst->name, "OR")) {
        reg[WB_inst->rd] = WB_inst->rd_val;
    }

    else if(!strcmp(WB_inst->name, "ORI")) {
        reg[WB_inst->rt] = WB_inst->rt_val;
    }

    else if(!strcmp(WB_inst->name, "SLT")) {
        reg[WB_inst->rd] = WB_inst->rd_val;
    }

    else if(!strcmp(WB_inst->name, "SLTI")) {
        reg[WB_inst->rt] = WB_inst->rt_val;
    }

    else if(!strcmp(WB_inst->name, "SLTIU")) {
        reg[WB_inst->rt] = WB_inst->rt_val;
    }

    else if(!strcmp(WB_inst->name, "SLTU")) {
        reg[WB_inst->rd] = WB_inst->rd_val;
    }

    else if(!strcmp(WB_inst->name, "XOR")) {
        reg[WB_inst->rd] = WB_inst->rd_val;
    }

    else if(!strcmp(WB_inst->name, "XORI")) {
        reg[WB_inst->rt] = WB_inst->rt_val;
    }

    else if(!strcmp(WB_inst->name, "NOR")) {
        reg[WB_inst->rd] = WB_inst->rd_val;
    }

    else if(!strcmp(WB_inst->name, "MOVZ")) {
            reg[WB_inst->rd] = WB_inst->rd_val;
    }

    else if(!strcmp(WB_inst->name, "MOVN")) {
            reg[WB_inst->rd] = WB_inst->rd_val;
    }

    else if(!strcmp(WB_inst->name, "SLL")) {
        reg[WB_inst->rd] = WB_inst->rd_val;
    }

    else if(!strcmp(WB_inst->name, "SRL")) {
        reg[WB_inst->rd] = WB_inst->rd_val;
    }
    else if(!strcmp(WB_inst->name, "LW")) {
        reg[WB_inst->rt] = WB_inst->rt_val;
    }
    else if(!strcmp(WB_inst->name, "LB")) {
        reg[WB_inst->rt] = WB_inst->rt_val;
    }
    else if(!strcmp(WB_inst->name, "LBU")) {
        reg[WB_inst->rt] = WB_inst->rt_val;
    }
    else if(!strcmp(WB_inst->name, "LHU")) {
        reg[WB_inst->rt] = WB_inst->rt_val;
    }
    else if(!strcmp(WB_inst->name, "LUI")) {
        reg[WB_inst->rt] = WB_inst->rt_val;
    }
    free(WB_inst);
};