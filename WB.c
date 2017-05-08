//
// Created by Ha on 4/27/2017.
//

#include <stdlib.h>
#include "WB.h"
#include "string.h"
void Instruction_WriteBack()
{
    if(!strcmp(MW->name, "NOP")) {
        return;
    }

    else if(!strcmp(MW->name, "ADD")) {
        reg[MW->RegDst] = MW->ALURes;
    }

    else if(!strcmp(MW->name, "ADDI")) {
        reg[MW->RegDst] = MW->ALURes;
    }


    else if(!strcmp(MW->name, "ADDIU")) {
        reg[MW->RegDst] = MW->ALURes;
    }

    else if(!strcmp(MW->name, "ADDU")) {
        reg[MW->RegDst] = MW->ALURes;
    }
    else if(!strcmp(MW->name, "SUB")) {
        reg[MW->RegDst] = MW->ALURes;
    }

    else if(!strcmp(MW->name, "SUBU")) {
        reg[MW->RegDst] = MW->ALURes;
    }

    else if(!strcmp(MW->name, "AND")) {
        reg[MW->RegDst] = MW->ALURes;
    }

    else if(!strcmp(MW->name, "ANDI")) {
        reg[MW->RegDst] = MW->ALURes;
    }

    else if(!strcmp(MW->name, "OR")) {
        reg[MW->RegDst] = MW->ALURes;
    }

    else if(!strcmp(MW->name, "ORI")) {
        reg[MW->RegDst] = MW->ALURes;
    }

    else if(!strcmp(MW->name, "SLT")) {
        reg[MW->RegDst] = MW->ALURes;
    }

    else if(!strcmp(MW->name, "SLTI")) {
        reg[MW->RegDst] = MW->ALURes;
    }

    else if(!strcmp(MW->name, "SLTIU")) {
        reg[MW->RegDst] = MW->ALURes;
    }

    else if(!strcmp(MW->name, "SLTU")) {
        reg[MW->RegDst] = MW->ALURes;
    }

    else if(!strcmp(MW->name, "XOR")) {
        reg[MW->RegDst] = MW->ALURes;
    }

    else if(!strcmp(MW->name, "XORI")) {
        reg[MW->RegDst] = MW->ALURes;
    }

    else if(!strcmp(MW->name, "NOR")) {
        reg[MW->RegDst] = MW->ALURes;
    }

    else if(!strcmp(MW->name, "MOVZ")) {
            reg[MW->RegDst] = MW->ALURes;
    }

    else if(!strcmp(MW->name, "MOVN")) {
            reg[MW->RegDst] = MW->ALURes;
    }

    else if(!strcmp(MW->name, "SLL")) {
        reg[MW->RegDst] = MW->ALURes;
    }

    else if(!strcmp(MW->name, "SRL")) {
        reg[MW->RegDst] = MW->ALURes;
    }
    else if(!strcmp(MW->name, "LW")) {
        reg[MW->RegDst] = MW->Mem_Data_Read;
    }
    else if(!strcmp(MW->name, "LB")) {
        reg[MW->RegDst] = MW->Mem_Data_Read;
    }
    else if(!strcmp(MW->name, "LBU")) {
        reg[MW->RegDst] = MW->Mem_Data_Read;
    }
    else if(!strcmp(MW->name, "LHU")) {
        reg[MW->RegDst] = MW->Mem_Data_Read;
    }
    else if(!strcmp(MW->name, "LUI")) {
        reg[MW->RegDst] = MW->Mem_Data_Read;
    }
};