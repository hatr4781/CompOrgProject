#include "ID.h"
#include "main.h"
#include <stdio.h>
//decode current instruction by instruction type and instruction fields
struct Instruction* Instruction_Decode(struct Instruction* inst){
    uint8_t  opcode;
    uint8_t func;
    uint8_t Rs;
    uint8_t Rt;
    uint8_t Rd;
    uint8_t  Shamt;
    int32_t Immed;

    opcode = (inst->encoded_inst) >> 26;
    printf("opcode = %d = %8x\n", opcode, opcode);
    if(inst->encoded_inst == 0x00000000){
        inst->name = "NOP";
    }

    else if(opcode == 0x00) {
        inst->instruction_type = R_INST;

        func = 0x0000003f & inst->encoded_inst;
        printf("func = %8x\n", func);
        Rs = ((inst->encoded_inst) >> 21) & 0x001f;
        Rt = ((inst->encoded_inst) >> 16) & 0x001f;
        Rd = ((inst->encoded_inst) >> 11) & 0x001f;
        Shamt = ((inst->encoded_inst) >> 6) & 0x001f;

        inst->rs = Rs;
        inst->rd = Rd;
        inst->rt = Rt;
        inst->shamt = Shamt;

        inst->rs_val = reg[Rs];
        inst->rt_val = reg[Rt];
        switch(func){
            case 0x20:
                inst->name = "ADD";
                break;
            case 0x21:
                inst->name = "ADDU";
                break;
            case 0x24:
                inst->name = "AND";
                break;
            case 0x08:
                inst->name = "JR";
                PC = (inst->rs_val)/4;
                break;
            case 0x27:
                inst->name = "NOR";
                break;
            case 0x25:
                inst->name = "OR";
                break;
            case 0x0b:
                inst->name = "MOVN";
                break;
            case 0x0a:
                inst->name = "MOVZ";
                break;
            case 0x2a:
                inst->name = "SLT";
                break;
            case 0x2b:
                inst->name = "SLTU";
                break;
            case 0x00:
                inst->name = "SLL";
                break;
            case 0x02:
                inst->name = "SRL";
                break;
            case 0x22:
                inst->name = "SUB";
                break;
            case 0x23:
                inst->name = "SUBU";
                break;
            case 0x26:
                inst->name = "XOR";
                break;
            default:
                inst->name = "ERR";
                break;
        }

    }
    else if(opcode == 0x01){
        inst->instruction_type = I_INST;

        Immed = 0x0000ffff & inst->encoded_inst;
        Rs = ((inst->encoded_inst) >> 21) & 0x001f;
        Rt = ((inst->encoded_inst)>> 16) & 0x001f;

        inst->name = "BLTZ";
        inst->immed = Immed;
        inst->rs = Rs;
        inst->rt = Rt;

        inst->rs_val = reg[Rs];

    }

    else if(opcode < 0x04 ){
        inst->instruction_type = J_INST;

        uint32_t Addr;
        Addr = (inst->encoded_inst) & 0x03ffffff;

        //format jump address
        //Addr = (Addr << 2) ;
        inst->addr = Addr;

        switch(opcode){
            case 0x02:
                inst->name = "J";
                PC = (inst->addr);
                break;
            case 0x03:
                inst->name = "JAL";
                reg[31] = PC + 1;
                PC = (inst->addr);
                break;
            default:
                inst->name = "ERR";
                break;
        }
    }

    else {
        inst->instruction_type = I_INST;

        Immed = 0x0000ffff & inst->encoded_inst;
        Rs = ((inst->encoded_inst) >> 21) & 0x001f;
        Rt = ((inst->encoded_inst) >> 16) & 0x001f;

        inst->rt = Rt;
        inst->rs = Rs;

        inst->rs_val = reg[Rs];
        inst->rt_val = reg[Rt];
        //inst->immed = Immed;

        switch (opcode) {
            case 0x20:
                inst->name = "LB";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                inst->immed = Immed;
                break;
            case 0x24:
                inst->name = "LBU";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                inst->immed = Immed;
                break;
            case 0x25:
                inst->name = "LHU";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                break;
            case 0x0f:
                inst->name = "LUI";
                Immed = (Immed << 16) & 0xffff0000;
                break;
            case 0x23:
                inst->name = "LW";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                break;
            case 0x0d:
                inst->name = "ORI";
                //Immed = Immed & 0x0000ffff;
                break;
            case 0x0a:
                inst->name = "SLTI";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                break;
            case 0x0b:
                inst->name = "SLTIU";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                inst->rs_val = (UNSIGNED_WORD) reg[Rs]; //might be wrong
                break;
            case 0x28:
                inst->name = "SB";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                break;
            case 0x29:
                inst->name = "SH";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                break;
            case 0x2b:
                inst->name = "SW";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                break;
            case 0x08:
                inst->name = "ADDI";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                break;
            case 0x09:
                inst->name = "ADDIU";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                break;
            case 0x0c:
                inst->name = "ANDI";
                break;
            case 0x0e:
                inst->name = "XORI";
                break;
            case 0x04:
                inst->name = "BEQ";
                if (inst->rs_val == inst->rt_val) {
                    if (Immed & 0x00008000) {
                        Immed = Immed | 0xffff0000;
                    }
                    Immed = (Immed << 2);
                    inst->immed = Immed;
                    PC = PC + Immed;
                }
                break;
            case 0x05:
                inst->name = "BNE";
                if (inst->rs_val != inst->rt_val) {
                    if (Immed & 0x00008000) {
                        Immed = Immed | 0xffff0000;
                    }
                    //Immed = (Immed << 2);
                    inst->immed = Immed;
                    PC = PC + Immed;
                }
                break;
            case 0x07:
                inst->name = "BGTZ";
                if (inst->rs_val > 0) {
                    if (Immed & 0x00008000) {
                        Immed = Immed | 0xffff0000;
                    }
                    //Immed = (Immed << 2);
                    inst->immed = Immed;
                    PC = PC + Immed;
                }
                break;
            case 0x06:
                inst->name = "BLEZ";
                if (inst->rs_val <= 0) {
                    if (Immed & 0x00008000) {
                        Immed = Immed | 0xffff0000;
                    }
                    //Immed = (Immed << 2);
                    inst->immed = Immed;
                    PC = PC + Immed;
                }
                break;
            default:
                inst->name = "ERR";
                break;
        }
        inst->immed = Immed;
    }
/*
    else if(opcode == 0x01f){
        inst->instruction_type = R_INST;

        func = 0x0000003f & inst->encoded_inst;
        Rs = ((inst->encoded_inst) >> 21) & 0x001f;
        Rt = ((inst->encoded_inst) >> 16) & 0x001f;
        Rd = ((inst->encoded_inst) >> 11) & 0x001f;
        Shamt = ((inst->encoded_inst) >> 6) & 0x001f;

        inst->rs = Rs;
        inst->rt = Rt;
        inst->rd = Rd;

        inst->name = "SEB";
        inst->rs_val = Rs;
        inst->rt_val = Rt;
    }
*/
    printf("Decoded\n");
    return inst;
}