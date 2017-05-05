//
// Created by Ha on 4/27/2017.
//

#include "WB.h"
#include "string.h"
void Instruction_WriteBack(struct Instruction* inst)
{

    if(!strcmp(inst->name, "NOP")) {
        return;
    }

    if(!strcmp(inst->name, "ADD")) {
        reg[inst->rd] = inst->rd_val;
    }

    if(!strcmp(inst->name, "ADDI")) {
        reg[inst->rt] = inst->rt_val;
    }


    if(!strcmp(inst->name, "ADDIU")) {
        reg[inst->rt] = inst->rt_val;
    }

    if(!strcmp(inst->name, "ADDU")) {
        reg[inst->rd] = inst->rd_val;
    }
    if(!strcmp(inst->name, "SUB")) {
        reg[inst->rd] = inst->rd_val;
    }

    if(!strcmp(inst->name, "SUBU")) {
        reg[inst->rd] = inst->rd_val;
    }

    if(!strcmp(inst->name, "AND")) {
        reg[inst->rd_val] = inst->rd_val;
    }

    if(!strcmp(inst->name, "ANDI")) {
        reg[inst->rt] = inst->rt_val;
    }

    if(!strcmp(inst->name, "OR")) {
        reg[inst->rd] = inst->rd_val;
    }

    if(!strcmp(inst->name, "ORI")) {
        reg[inst->rt] = inst->rt_val;
    }

    if(!strcmp(inst->name, "SLT")) {
        reg[inst->rd] = inst->rd_val;
    }

    if(!strcmp(inst->name, "SLTI")) {
        reg[inst->rt] = inst->rt_val;
    }

    if(!strcmp(inst->name, "SLTIU")) {
        reg[inst->rt] = inst->rt_val;
    }

    if(!strcmp(inst->name, "SLTU")) {
        reg[inst->rd] = inst->rd_val;
    }

    if(!strcmp(inst->name, "XOR")) {
        reg[inst->rd] = inst->rd_val;
    }

    if(!strcmp(inst->name, "XORI")) {
        reg[inst->rt] = inst->rt_val;
    }

    if(!strcmp(inst->name, "NOR")) {
        reg[inst->rd] = inst->rd_val;
    }

    if(!strcmp(inst->name, "MOVZ")) {
            reg[inst->rd] = inst->rd_val;
    }

    if(!strcmp(inst->name, "MOVN")) {
            reg[inst->rd] = inst->rd_val;
    }

    if(!strcmp(inst->name, "SLL")) {
        reg[inst->rd] = inst->rd_val;
    }

    if(!strcmp(inst->name, "SRL")) {
        reg[inst->rd] = inst->rd_val;
    }
};