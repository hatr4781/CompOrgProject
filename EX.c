#include "EX.h"
#include "string.h"

void Instruction_Execute()
{
    if(EX_inst == NULL){
        return;
    }

    if(!strcmp(EX_inst->name, "NOP")) {
        return;
    }

    else if(!strcmp(EX_inst->name, "ADD")) {
        EX_inst->rd_val = (EX_inst->rs_val) + (EX_inst->rt_val);
    }

    else if(!strcmp(EX_inst->name, "ADDI")) {
        EX_inst->rt_val = (EX_inst->rs_val) + (EX_inst->immed);
    }

    else if(!strcmp(EX_inst->name, "ADDIU")) {
        EX_inst->rt_val = (EX_inst->rs_val) + (EX_inst->immed);
    }

    else if(!strcmp(EX_inst->name, "ADDU")) {
        EX_inst->rd_val = EX_inst->rs_val + EX_inst->rt_val;
    }

    else if(!strcmp(EX_inst->name, "SUB")) {
        EX_inst->rd_val = (EX_inst->rs_val) - (EX_inst->rt_val);
    }

    else if(!strcmp(EX_inst->name, "SUBU")) {
        EX_inst->rd_val = (EX_inst->rs_val) - (EX_inst->rt_val);
    }

    else if(!strcmp(EX_inst->name, "AND")) {
        EX_inst->rd_val = (EX_inst->rs_val) & (EX_inst->rt_val);
    }

    else if(!strcmp(EX_inst->name, "ANDI")) {
        EX_inst->rt_val = (EX_inst->rs_val) & (EX_inst->immed);
    }

    else if(!strcmp(EX_inst->name, "OR")) {
        EX_inst->rd_val = (EX_inst->rs_val) | (EX_inst->rt_val);
    }

    else if(!strcmp(EX_inst->name, "ORI")) {
        EX_inst->rt_val = (EX_inst->rs_val)|(EX_inst->immed);
    }

    else if(!strcmp(EX_inst->name, "SLT")) {
        EX_inst->rd_val = ((EX_inst->rs_val)<(EX_inst->rt_val))?1:0;
    }

    else if(!strcmp(EX_inst->name, "SLTI")) {
        EX_inst->rt_val =((EX_inst->rs_val)<(EX_inst->immed))?1:0;
    }

    else if(!strcmp(EX_inst->name, "SLTIU")) {
        EX_inst->rt_val =((EX_inst->rs_val)<(EX_inst->immed))?1:0;
    }

    else if(!strcmp(EX_inst->name, "SLTU")) {
        EX_inst->rd_val = ((EX_inst->rs_val)<(EX_inst->rt_val))?1:0;
    }

    else if(!strcmp(EX_inst->name, "XOR")) {
        EX_inst->rd_val = ((EX_inst->rs_val)^(EX_inst->rt_val));
    }

    else if(!strcmp(EX_inst->name, "XORI")) {
        EX_inst->rt_val = (EX_inst->rs_val)^(EX_inst->immed);
    }

    else if(!strcmp(EX_inst->name, "NOR")) {
        EX_inst->rd_val = ~((EX_inst->rs_val)|(EX_inst->rt_val));
    }

    else if(!strcmp(EX_inst->name, "JR")) {
        PC = EX_inst->rs_val;
    }

    else if(!strcmp(EX_inst->name, "MOVZ")) {
        if(EX_inst->rt_val == 0) {
            EX_inst->rd_val = EX_inst->rs_val;
        }
    }

    else if(!strcmp(EX_inst->name, "MOVN")) {
        if(EX_inst->rt_val != 0) {
            EX_inst->rd_val = EX_inst->rs_val;
        }
    }

    else if(!strcmp(EX_inst->name, "SLL")) {
        EX_inst->rd_val = EX_inst->rt_val << EX_inst->shamt;
    }

    else if(!strcmp(EX_inst->name, "SRL")) {
        EX_inst->rd_val = EX_inst->rt_val >> EX_inst->shamt;
    }

    else if(!strcmp(EX_inst->name, "J")) {
        PC = EX_inst->addr;
    }

    else if(!strcmp(EX_inst->name, "JAL")) {
        reg[31] = PC+2;
        PC = EX_inst->addr;
    }

    //Memory Functions
    else if(!strcmp(EX_inst->name, "LB")) {
        EX_inst->addr = EX_inst->rs_val+EX_inst->immed;
    }

    else if(!strcmp(EX_inst->name, "LBU")) {
        EX_inst->addr = EX_inst->rs_val+EX_inst->immed;
    }

    else if(!strcmp(EX_inst->name, "LHU")) {
        EX_inst->addr = EX_inst->rs_val+EX_inst->immed;
    }

    else if(!strcmp(EX_inst->name, "LUI")) {
        EX_inst->rt_val = (EX_inst->immed) << 16;
    }

    else if(!strcmp(EX_inst->name, "LW")) {
        EX_inst->addr = EX_inst->rs_val+EX_inst->immed;
    }

    else if(!strcmp(EX_inst->name, "SB")) {
        EX_inst->addr = EX_inst->rs_val+EX_inst->immed;
    }

    else if(!strcmp(EX_inst->name, "SH")) {
        EX_inst->addr = EX_inst->rs_val+EX_inst->immed;
    }

    else if(!strcmp(EX_inst->name, "SW")) {
        EX_inst->addr = EX_inst->rs_val+EX_inst->immed;
    }

    else if(!strcmp(EX_inst->name, "BEQ")) {

    }

    else if(!strcmp(EX_inst->name, "BNE")) {
    }

    else if(!strcmp(EX_inst->name, "BGTZ")) {
    }

    else if(!strcmp(EX_inst->name, "BLEZ")) {
    }
    else{
        printf("Instruction Execute Error");
    }
    printf("EXECUTE: %s \nrs_val = %d\nrt_val = %d\nrd_val = %d\nimmed = %d\naddr = %d\n",
           EX_inst->name, EX_inst->rs_val, EX_inst->rt_val, EX_inst->rd_val, EX_inst->immed, EX_inst->addr);
    return;

}