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

    uint8_t opcode;
    uint8_t func;
    int32_t rs;
    int32_t rs_val;
    int32_t rt;
    int32_t rt_val;
    int32_t rd;
    int32_t rd_val;
    int32_t shamt;
    int32_t immed;
    int32_t type;

    opcode = (FD->inst_fetched) >> 26;
    func = 0x0000003f & FD->inst_fetched;
    rs = ((FD->inst_fetched) >> 21) & 0x001f;
    rt = ((FD->inst_fetched) >> 16) & 0x001f;
    rd = ((FD->inst_fetched) >> 11) & 0x001f;
    shamt = ((FD->inst_fetched) >> 6) & 0x001f;
    immed = 0x0000ffff & FD->inst_fetched;

    //printf("opcode = %d = %8x\n", opcode, opcode);
    if(FD->inst_fetched == 0x00000000){
        shDE->name = "NOP";
    }

    else if(opcode == 0x00) {
        type = R_TYPE;
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
                shDE->name = "JR";
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
                break;

            case 0x02:
                shDE->name = "SRL";
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
        type = BR_TYPE;

        shDE->name = "BLTZ";
        shDE->Immed = immed << 2;
        ID_inst->rs_val = reg[Rs];

    }

    else if(opcode < 0x04 ){
        ID_inst->instruction_type = J_INST;

        uint32_t Addr;
        Addr = (ID_inst->encoded_inst) & 0x03ffffff;

        //format jump address
        //Addr = (Addr << 2) ;
        ID_inst->addr = Addr;

        switch(opcode){
            case 0x02:
                ID_inst->name = "J";
                PC = (ID_inst->addr);
                break;
            case 0x03:
                ID_inst->name = "JAL";
                reg[31] = PC + 1;
                PC = (ID_inst->addr);
                break;
            default:
                ID_inst->name = "ERR";
                break;
        }
    }

    else {
        ID_inst->instruction_type = I_INST;

        Immed = 0x0000ffff & ID_inst->encoded_inst;
        Rs = ((ID_inst->encoded_inst) >> 21) & 0x001f;
        Rt = ((ID_inst->encoded_inst) >> 16) & 0x001f;

        ID_inst->rt = Rt;
        ID_inst->rs = Rs;

        ID_inst->rs_val = reg[Rs];
        ID_inst->rt_val = reg[Rt];
        //ID_inst->immed = Immed;

        switch (opcode) {
            case 0x20:
                ID_inst->name = "LB";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                ID_inst->immed = Immed;
                ID_inst->type = LOAD_TYPE;

                break;
            case 0x24:
                ID_inst->name = "LBU";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                ID_inst->immed = Immed;
                ID_inst->type = LOAD_TYPE;

                break;
            case 0x25:
                ID_inst->name = "LHU";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                ID_inst->type = LOAD_TYPE;

                break;
            case 0x0f:
                ID_inst->name = "LUI";
                Immed = (Immed << 16) & 0xffff0000;
                ID_inst->type = LOAD_TYPE;

                break;
            case 0x23:
                ID_inst->name = "LW";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                ID_inst->type = LOAD_TYPE;

                break;
            case 0x0d:
                ID_inst->name = "ORI";
                ID_inst->type = ALU_TYPE;

                break;
            case 0x0a:
                ID_inst->name = "SLTI";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                ID_inst->type = ALU_TYPE;

                break;
            case 0x0b:
                ID_inst->name = "SLTIU";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                ID_inst->type = ALU_TYPE;
                break;
            case 0x28:
                ID_inst->name = "SB";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                ID_inst->type = STORE_TYPE;

                break;
            case 0x29:
                ID_inst->name = "SH";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                ID_inst->type = STORE_TYPE;

                break;
            case 0x2b:
                ID_inst->name = "SW";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                ID_inst->type = STORE_TYPE;

                break;
            case 0x08:
                ID_inst->name = "ADDI";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                ID_inst->type = ALU_TYPE;

                break;
            case 0x09:
                ID_inst->name = "ADDIU";
                if (Immed & 0x00008000) {
                    Immed = Immed | 0xffff0000;
                }
                ID_inst->type = ALU_TYPE;

                break;
            case 0x0c:
                ID_inst->name = "ANDI";
                ID_inst->type = ALU_TYPE;

                break;
            case 0x0e:
                ID_inst->name = "XORI";
                ID_inst->type = ALU_TYPE;

                break;
            case 0x04:
                ID_inst->name = "BEQ";
                ID_inst->type = ALU_TYPE;
                break;
            case 0x05:
                ID_inst->name = "BNE";
                ID_inst->type = ALU_TYPE;
                break;
            case 0x07:
                ID_inst->name = "BGTZ";
                ID_inst->type = ALU_TYPE;
                break;
            case 0x06:
                ID_inst->name = "BLEZ";
                ID_inst->type = ALU_TYPE;
                break;
            default:
                ID_inst->name = "ERR";
                break;
        }
        ID_inst->immed = Immed;
    }
    if((EX_inst || MEM_inst) == NULL){
        return;
    }

    /*
    if(!strcmp("SW", ID_inst->name)&& (bubbled_s == 1)){
        bubbled_s = 0;
        ID_inst->rt_val = reg[ID_inst->rt];
        return;
    }
*/
    /*
    if(!strcmp("BNE", ID_inst->name) && (bubbled_b == 1)){
        bubbled_b = 0;
        ID_inst->rt_val = reg[ID_inst->rt];
    }
    */
    else{
        Hazard_Forwarding();
    }

    if(!strcmp(ID_inst->name, "BEQ")){
        if (ID_inst->rs_val == ID_inst->rt_val) {
            if (Immed & 0x00008000) {
                Immed = Immed | 0xffff0000;
            }
            Immed = (Immed << 2);
            ID_inst->immed = Immed;

            PC = PC + Immed -1;
        }
    }

    if(!strcmp(ID_inst->name, "BNE")){
        if (ID_inst->rs_val != ID_inst->rt_val) {
            if (Immed & 0x00008000) {
                Immed = Immed | 0xffff0000;
            }
            //Immed = (Immed << 2);
            ID_inst->immed = Immed;
            PC = PC + Immed -1;
        }
    }

    if(!strcmp(ID_inst->name, "BGTZ")){
        if (ID_inst->rs_val > 0) {
            if (Immed & 0x00008000) {
                Immed = Immed | 0xffff0000;
            }
            //Immed = (Immed << 2);
            ID_inst->immed = Immed;
            PC = PC + Immed -1;
        }
    }

    if(!strcmp(ID_inst->name, "BLTZ")){
        if(ID_inst->rs_val < 0){
            if (Immed & 0x00008000) {
                Immed = Immed | 0xffff0000;
            }
            //Immed = (Immed << 2);
            ID_inst->immed = Immed;
            PC = PC + Immed;
        }
    }

    if(!strcmp(ID_inst->name, "BLEZ")){
        if (ID_inst->rs_val <= 0) {
            if (Immed & 0x00008000) {
                Immed = Immed | 0xffff0000;
            }
            //Immed = (Immed << 2);
            ID_inst->immed = Immed;
            PC = PC + Immed -1;
        }
    }
    printf("DECODE: %s \nrs_val = %d\nrt_val = %d\nrd_val = %d\nimmed = %d\naddr = %d\n",
           ID_inst->name, ID_inst->rs_val, ID_inst->rt_val, ID_inst->rd_val, ID_inst->immed, ID_inst->addr);

}
/*  NEED TO INCLUDE SOMEWHERE
    else if(opcode == 0x01f){
        ID_inst->instruction_type = R_INST;

        func = 0x0000003f & ID_inst->encoded_inst;
        Rs = ((ID_inst->encoded_inst) >> 21) & 0x001f;
        Rt = ((ID_inst->encoded_inst) >> 16) & 0x001f;
        Rd = ((ID_inst->encoded_inst) >> 11) & 0x001f;
        Shamt = ((ID_inst->encoded_inst) >> 6) & 0x001f;

        ID_inst->rs = Rs;
        ID_inst->rt = Rt;
        ID_inst->rd = Rd;

        ID_inst->name = "SEB";
        ID_inst->rs_val = Rs;
        ID_inst->rt_val = Rt;
    }
*/
/*
*/
/*
    int x_type;
    int m_type;
    if(EX_inst == NULL){
        return;
    }
    else{
        x_type = EX_inst->instruction_type;
    }

    if(MEM_inst != NULL) {
        m_type = MEM_inst->instruction_type;
    }
    /*
    if(ID_inst->name == "NOP"){
        return;
    }
*/
/*
    if(ID_inst->instruction_type == I_INST){
        if(m_type == I_INST ){
            if(ID_inst->rs == MEM_inst->rt){
                printf("ID->rs = MEM->rt\n");
                make_nop();
                //PC = PC - 1;
            }
        }
        else if(m_type == R_INST){
            if(ID_inst->rs == MEM_inst->rd){
                printf("ID->rs = MEM->rd\n");
                make_nop();
                //PC = PC - 1;
            }
        }
        else if(x_type == I_INST ){
            if(ID_inst->rs == EX_inst->rt){
                //make_nop();
                printf("ID->rs = EX->rt\n");
                make_nop();
                //PC = PC - 1;
            }
        }
        else if(x_type == R_INST){
            if(ID_inst->rs == EX_inst->rd){
                printf("ID->rs = EX->rd\n");
                make_nop();
                //PC = PC - 1;
            }
        }
        printf("MAKENOP:  %s \nrs_val = %d\nrt_val = %d\nrd_val = %d\nimmed = %d\naddr = %d\n",
               ID_inst->name, ID_inst->rs_val, ID_inst->rt_val, ID_inst->rd_val, ID_inst->immed, ID_inst->addr);
    }
    else if(ID_inst->instruction_type == R_INST){
        if(m_type == I_INST ){
            if((ID_inst->rs || ID_inst->rt)== MEM_inst->rt){
                printf("ID->rs || ID->rt = MEM->rt\n");
                make_nop();
                //PC = PC - 1;
            }
        }
        else if(m_type == R_INST){
            if((ID_inst->rs|| ID_inst->rt) == MEM_inst->rd){
                printf("ID->rs || ID->rt = MEM->rt\n");
                make_nop();
                //PC = PC - 1;
            }
        }
        else if(x_type == I_INST ){
            if((ID_inst->rs || ID_inst->rt) == EX_inst->rt){
                printf("ID->rs || ID->rt = EX->rt\n");
                make_nop();
                //PC = PC - 1;
            }
        }
        else if(x_type == R_INST)
            if((ID_inst->rs || ID_inst->rt) == EX_inst->rd){
                printf("ID->rs || ID->rt = EX->rd\n");
                make_nop();
                //PC = PC - 1;
            }
        }
    */
//        printf("MAKENOP: %s \nrs_val = %d\nrt_val = %d\nrd_val = %d\nimmed = %d\naddr = %d\n",
//               ID_inst->name, ID_inst->rs_val, ID_inst->rt_val, ID_inst->rd_val, ID_inst->immed, ID_inst->addr);