#include "EX.h"
#include "string.h"

struct Instruction* Instruction_Execute(struct Instruction* inst)
{
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
        reg[31] = PC+8;
        PC = inst->addr;
    }
    /*
    if(!strcmp(inst->name, "LB")) {

    }

    }
    if(!strcmp(inst->name, "LBU")) {

    }

    if(!strcmp(inst->name, "LHU")) {

    }

    if(!strcmp(inst->name, "LUI")) {

    }

    if(!strcmp(inst->name, "LW")) {

    }

    if(!strcmp(inst->name, "SB")) {

    }

    if(!strcmp(inst->name, "SH")) {

    }

    if(!strcmp(inst->name, "SW")) {

    }

    if(!strcmp(inst->name, "BEQ")) {

    }

    if(!strcmp(inst->name, "BNE")) {

    }

    if(!strcmp(inst->name, "BGTZ")) {

    }

    if(!strcmp(inst->name, "BLEZ")) {

    }
*/

    return inst;

}