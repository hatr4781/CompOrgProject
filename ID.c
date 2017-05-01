#include "ID.h"

//decode current instruction by instruction type and instruction fields
struct Instruction* Instruction_Decode(struct Instruction* inst){
    uint8_t  opcode;
    uint8_t func;
    int8_t Rs;
    int8_t Rt;
    uint8_t Rd;
    uint8_t  Shamt;
    uint16_t Immed;

    opcode = (inst->encoded_inst) >> 26;

    if(inst->encoded_inst == 0x00000000){
        inst->name = "NOP";
    }

    else if(opcode == 0x00) {
        inst->instruction_type = R_INST;

        func = 0x0000003f & inst->encoded_inst;
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
            case 0x21:
                inst->name = "ADDU";
            case 0x24:
                inst->name = "AND";
            case 0x08:
                inst->name = "JR";
            case 0x27:
                inst->name = "NOR";
            case 0x25:
                inst->name = "OR";
            case 0x0b:
                inst->name = "MOVN";
            case 0x0a:
                inst->name = "MOVZ";
            case 0x2a:
                inst->name = "SLT";
            case 0x2b:
                inst->name = "SLTU";
            case 0x00:
                inst->name = "SLL";
            case 0x02:
                inst->name = "SRL";
            case 0x22:
                inst->name = "SUB";
            case 0x23:
                inst->name = "SUBU";
            case 0x26:
                inst->name = "XOR";
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
        inst->addr = Addr;

        switch(opcode){
            case 0x02:
                inst->name = "J";
            case 0x03:
                inst->name = "JAL";
        }
    }

    else if(opcode < 0x1f){
        inst->instruction_type = I_INST;

        Immed = 0x0000ffff & inst->encoded_inst;
        Rs = ((inst->encoded_inst) >> 21) & 0x001f;
        Rt = ((inst->encoded_inst)>> 16) & 0x001f;

        inst->rs_val = reg[Rs];
        inst->rt = Rt;

        switch(opcode){
            case 0x20:
                inst->name = "LB";
            case 0x24:
                inst->name = "LBU";
            case 0x25:
                inst->name = "LHU";
            case 0x0f:
                inst->name = "LUI";
            case 0x23:
                inst->name = "LW";
            case 0x0d:
                inst->name = "ORI";
            case 0x0a:
                inst->name = "SLTI";
            case 0x0b:
                inst->name = "SLTIU";
            case 0x28:
                inst->name = "SB";
            case 0x29:
                inst->name = "SH";
            case 0x2b:
                inst->name = "SW";
            case 0x08:
                inst->name = "ADDI";
            case 0x09:
                inst->name = "ADDIU";
            case 0x0c:
                inst->name = "ANDI";
            case 0x0e:
                inst->name = "XORI";
            case 0x04:
                inst->name = "BEQ";
            case 0x05:
                inst->name = "BNE";
            case 0x07:
                inst->name = "BGTZ";
            case 0x06:
                inst->name = "BLEZ";
        }
    }
    else if(opcode == 0x1f){
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
    return inst;
}