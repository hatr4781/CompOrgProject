#include "EX.h"
#include "string.h"

struct Instruction* Instruction_Execute(struct Instruction* inst)
{
    if(!strcmp(inst->name, "NOP")) {
        return inst;
    }

    if(!strcmp(inst->name, "ADD")) {
        inst->rd_val = (inst->rs_val) + (inst->rt_val);
    }

    if(!strcmp(inst->name, "ADDI")) {
        inst->rt_val = (inst->rs_val) + (inst->immed);
    }

    if(!strcmp(inst->name, "ADDIU")) {
        inst->rt_val = (inst->rs_val) + (inst->immed);
    }

    if(!strcmp(inst->name, "ADDU")) {
        inst->rd_val = inst->rs_val + inst->rt_val;
    }
    if(!strcmp(inst->name, "SUB")) {
        inst->rd_val = (inst->rs_val) - (inst->rt_val);
    }

    if(!strcmp(inst->name, "SUBU")) {
        inst->rd_val = (inst->rs_val) - (inst->rt_val);
    }

    if(!strcmp(inst->name, "AND")) {
        inst->rd_val = (inst->rs_val) & (inst->rt_val);
    }

    if(!strcmp(inst->name, "ANDI")) {
        inst->rt_val = (inst->rs_val) & (inst->immed);
    }

    if(!strcmp(inst->name, "OR")) {
        inst->rd_val = (inst->rs_val) | (inst->rt_val);
    }

    if(!strcmp(inst->name, "ORI")) {
        inst->rt_val = (inst->rs_val)|(inst->immed);
    }

    if(!strcmp(inst->name, "SLT")) {
        inst->rd_val = ((inst->rs_val)<(inst->rt_val))?1:0;
    }

    if(!strcmp(inst->name, "SLTI")) {
        inst->rt_val =((inst->rs_val)<(inst->immed))?1:0;
    }

    if(!strcmp(inst->name, "SLTIU")) {
        inst->rt_val =((inst->rs_val)<(inst->immed))?1:0;
    }

    if(!strcmp(inst->name, "SLTU")) {
        inst->rd_val = ((inst->rs_val)<(inst->rt_val))?1:0;
    }

    if(!strcmp(inst->name, "XOR")) {
        inst->rd_val = ((inst->rs_val)^(inst->rt_val));
    }

    if(!strcmp(inst->name, "XORI")) {
        inst->rt_val = (inst->rs_val)^(inst->immed);
    }

    if(!strcmp(inst->name, "NOR")) {
        inst->rd_val = ~((inst->rs_val)|(inst->rt_val));
    }

    if(!strcmp(inst->name, "JR")) {
        PC = inst->rs_val;
    }

    if(!strcmp(inst->name, "MOVZ")) {
        if(inst->rt_val == 0) {
            inst->rd_val = inst->rs_val;
        }
    }

    if(!strcmp(inst->name, "MOVN")) {
        if(inst->rt_val != 0) {
            inst->rd_val = inst->rs_val;
        }
    }

    if(!strcmp(inst->name, "SLL")) {
        inst->rd_val = inst->rt_val << inst->shamt;
    }

    if(!strcmp(inst->name, "SRL")) {
        inst->rd_val = inst->rt_val >> inst->shamt;
    }

    if(!strcmp(inst->name, "J")) {
        PC = inst->addr;
    }

    if(!strcmp(inst->name, "JAL")) {
        reg[31] = PC+2;
        PC = inst->addr;
    }

    if(!strcmp(inst->name, "LB")) {
        inst->addr = inst->rs_val+inst->immed;
    }

    if(!strcmp(inst->name, "LBU")) {
        inst->addr = inst->rs_val+inst->immed;
    }

    if(!strcmp(inst->name, "LHU")) {
        inst->addr = inst->rs_val+inst->immed;
    }

    if(!strcmp(inst->name, "LUI")) {
        inst->addr = inst->immed;
    }

    if(!strcmp(inst->name, "LW")) {
        inst->addr = inst->rs_val+inst->immed;
    }

    if(!strcmp(inst->name, "SB")) {
        inst->addr = inst->rs_val+inst->immed;
    }

    if(!strcmp(inst->name, "SH")) {
        inst->addr = inst->rs_val+inst->immed;
    }

    if(!strcmp(inst->name, "SW")) {
        inst->addr = inst->rs_val+inst->immed;
    }

    if(!strcmp(inst->name, "BEQ")) {
        if(inst->rs_val==inst->rt_val) {
            PC = PC + 4 + ((inst->immed) << 2);
        }
    }

    if(!strcmp(inst->name, "BNE")) {
        if(inst->rs_val!=inst->rt_val) {
            PC = PC + 4 + ((inst->immed) << 2);
        }
    }

    if(!strcmp(inst->name, "BGTZ")) {
        if(inst->rs_val > 0) {
            PC = PC + ((inst->immed) << 2);
        }
    }

    if(!strcmp(inst->name, "BLEZ")) {
        if(inst->rs_val <= 0) {
            PC = PC + ((inst->immed) << 2);
        }
    }


    return inst;

}