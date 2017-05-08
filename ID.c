#include "ID.h"
#include "main.h"
#include <stdio.h>
#include <mem.h>
//decode current instruction by instruction type and instruction fields

/*
void make_nop(){
    ID_inst->encoded_inst = 0x00000000;
    Instruction_Decode();
    IF_inst->encoded_inst = 0x00000000;
    PC = PC - 2;
    //Instruction_Fetch();
}
*/

void Instruction_Decode(){

    uint32_t opcode;
    uint32_t func;
    int32_t rs;
    int32_t rs_val;
    int32_t rt;
    int32_t rt_val;
    int32_t rd;
    int32_t rd_val;
    int32_t shamt;
    int32_t immed;

    opcode = (FD->inst_fetched) >> 26;
    func = 0x0000003f & FD->inst_fetched;
    shDE->RegRs = ((FD->inst_fetched) >> 21) & 0x001f;
    shDE->RegRt = ((FD->inst_fetched) >> 16) & 0x001f;
    shDE->RegRd = ((FD->inst_fetched) >> 11) & 0x001f;
    shDE->Immed = 0x0000ffff & FD->inst_fetched;
    shamt = ((FD->inst_fetched) >> 6) & 0x001f;
    shDE->target_branch = 0;
    shDE->ReadData1 = 0;
    shDE->ReadData2 = 0;

    //printf("opcode = %d = %8x\n", opcode, opcode);
    if(FD->inst_fetched == 0x00000000){
        shDE->type = 0;
        shDE->name = "NOP";
        shDE->RegRt = 0;
        shDE->RegRd = 0;
        shDE->Immed = 0;
        shDE->ReadData1 = 0;
        shDE->ReadData2 = 0;
    }

    else if(opcode == 0x00) {
        shDE->type = R_TYPE;
        shDE->ReadData1 = reg[shDE->RegRs];
        shDE->ReadData2 = reg[shDE->RegRt];
        //decode as R_inst
        switch(func){
            case 0x20:
                shDE->name = "ADD";
                break;

            case 0x21:
                shDE->name = "ADDU";
                break;

            case 0x24:
                shDE->name = "AND";
                break;

            case 0x08:
                shDE->type = BR_TYPE;
                shDE->name = "JR";
                shDE->ReadData2 = 0;
                shDE->RegRt = 0;
                shDE->RegRd = 0;
                shDE->target_branch = shDE->ReadData1;
                //treat as branch or r-type?
                //PC = (ID_inst->rs_val)/4;
                break;

            case 0x27:
                shDE->name = "NOR";
                break;

            case 0x25:
                shDE->name = "OR";
                break;

            case 0x0b:
                shDE->name = "MOVN";
                break;

            case 0x0a:
                shDE->name = "MOVZ";
                break;

            case 0x2a:
                shDE->name = "SLT";
                break;

            case 0x2b:
                shDE->name = "SLTU";
                break;

            case 0x00:
                shDE->name = "SLL";
                shDE->ReadData1 = shamt;
                break;

            case 0x02:
                shDE->name = "SRL";
                shDE->ReadData1 = shamt;
                break;

            case 0x22:
                shDE->name = "SUB";
                break;

            case 0x23:
                shDE->name = "SUBU";
                break;

            case 0x26:
                shDE->name = "XOR";
                break;

            default:
                shDE->name = "ERR";
                break;
        }
    }

    else if(opcode == 0x01){
        shDE->ReadData1 = reg[shDE->RegRs];
        shDE->ReadData2 = 0;
        shDE->RegRt = 0;
        shDE->type = BR_TYPE;
        shDE->name = "BLTZ";
        if((shDE->Immed) & 0x00008000){
            shDE->Immed = shDE->Immed | 0xffff0000;
        }
        shDE->target_branch = shDE->Immed;
    }

    else if(opcode < 0x04 ){
        //type = BR_TYPE;
        shDE->type = -1;
        shDE->target_branch = shDE->Immed;
        switch(opcode){
            case 0x02:
                shDE->name = "J";
                shFD->PC = shDE->target_branch;
                break;

            case 0x03:
                shDE->name = "JAL";
                reg[31] = shFD->PC + 1;
                shFD->PC = shDE->target_branch;
                printf("JAL-> PC = %d", shFD->PC);
                break;

            default:
                shDE->name = "ERR";
                break;
        }
    }

    else {
        shDE->ReadData1 = reg[shDE->RegRs];
        shDE->ReadData2 = reg[shDE->RegRt];
        switch (opcode) {
            case 0x20:
                shDE->type = LOAD_TYPE;
                shDE->name = "LB";

                if (shDE->Immed & 0x00008000) {
                    shDE->Immed = shDE->Immed | 0xffff0000;
                }
                break;

            case 0x24:
                shDE->type = LOAD_TYPE;
                shDE->name = "LBU";

                if (shDE->Immed & 0x00008000) {
                    shDE->Immed = shDE->Immed | 0xffff0000;
                }
                break;

            case 0x25:
                shDE->type = LOAD_TYPE;
                shDE->name = "LHU";
                if (shDE->Immed & 0x00008000) {
                    shDE->Immed = shDE->Immed | 0xffff0000;
                }
                break;
            case 0x0f:
                shDE->type = I_TYPE;
                shDE->name = "LUI";
                shDE->Immed = (shDE->Immed << 16) & 0xffff0000;
                break;
            case 0x23:
                shDE->type = LOAD_TYPE;
                shDE->name = "LW";
                if (shDE->Immed & 0x00008000) {
                    shDE->Immed = shDE->Immed | 0xffff0000;
                }
                break;

            case 0x0d:
                shDE->type = I_TYPE;
                shDE->name = "ORI";
                break;

            case 0x0a:
                shDE->type = I_TYPE;
                shDE->name = "SLTI";
                if (shDE->Immed & 0x00008000) {
                    shDE->Immed = shDE->Immed | 0xffff0000;
                }
                break;

            case 0x0b:
                shDE->type = I_TYPE;
                shDE->name = "SLTIU";
                if (shDE->Immed & 0x00008000) {
                    shDE->Immed = shDE->Immed | 0xffff0000;
                }
                break;

            case 0x28:
                shDE->type = STORE_TYPE;
                shDE->name = "SB";
                if (shDE->Immed & 0x00008000) {
                    shDE->Immed = shDE->Immed | 0xffff0000;
                }
                break;

            case 0x29:
                shDE->type = STORE_TYPE;
                shDE->name = "SH";
                if (shDE->Immed & 0x00008000) {
                    shDE->Immed = shDE->Immed| 0xffff0000;
                }
                break;

            case 0x2b:
                shDE->type = STORE_TYPE;
                shDE->name = "SW";
                if (shDE->Immed& 0x00008000) {
                    shDE->Immed = shDE->Immed | 0xffff0000;
                }
                break;

            case 0x08:
                shDE->type = I_TYPE;
                shDE->name = "ADDI";
                if (shDE->Immed & 0x00008000) {
                    shDE->Immed = shDE->Immed| 0xffff0000;
                }
                break;

            case 0x09:
                shDE->type = I_TYPE;
                shDE->name = "ADDIU";
                if (shDE->Immed & 0x00008000) {
                    shDE->Immed = shDE->Immed | 0xffff0000;
                }
                break;

            case 0x0c:
                shDE->type = I_TYPE;
                shDE->name = "ANDI";
                break;

            case 0x0e:
                shDE->type = I_TYPE;
                shDE->name = "XORI";
                break;

            case 0x04:
                shDE->type = BR_TYPE;
                shDE->name = "BEQ";
                if (shDE->Immed & 0x0000800) {
                    shDE->Immed = shDE->Immed | 0xffff0000;
                }
                shDE->target_branch = shDE->Immed;
                break;

            case 0x05:
                shDE->name = "BNE";
                shDE->type = BR_TYPE;
                if((shDE->Immed) & 0x00008000){
                    shDE->Immed = shDE->Immed | 0xffff0000;
                }
                shDE->target_branch = shDE->Immed;
                break;

            case 0x07:
                shDE->name = "BGTZ";
                shDE->type = BR_TYPE;
                shDE->RegRt = 0;
                shDE->ReadData2 = 0;
                if((shDE->Immed) & 0x00008000){
                    shDE->Immed = shDE->Immed | 0xffff0000;
                }
                shDE->target_branch = shDE->Immed;
                break;

            case 0x06:
                shDE->name = "BLEZ";
                shDE->type = BR_TYPE;
                shDE->ReadData2 = 0;
                shDE->RegRt = 0;
                if((shDE->Immed) & 0x00008000){
                    shDE->Immed = shDE->Immed | 0xffff0000;
                }
                shDE->target_branch = shDE->Immed;
                break;

            default:
                shDE->name = "ERR";
                break;
        }
    }
    /*
    printf("DECODE: %s \nReadData1 = %d\nReadData2 = %d\nRs = %d\nRd = %d\nRt = %d\nImmed = %d\n",
           shDE->name, shDE->ReadData1, shDE->ReadData2, shDE->RegRs, shDE->RegRd, shDE->RegRt, shDE->Immed);
           */
}


