#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include "main.h"
#include "Load_Program.h"

#define MEM_LENGTH 200
#define R_INST 0
#define I_INST 1
#define J_INST 2


//uint32_t instMem[MEM_LENGTH];
//int PC = 0;

uint32_t reg[32];
uint32_t instarray[50];
uint32_t PC;
uint32_t dataMem[200];

//fetch next instruction and set instruction struct to it
struct Instruction* Instruction_Fetch(){

    uint32_t inst_fetched;
    inst_fetched = instarray[PC];

    struct Instruction *new_inst;
    new_inst = malloc(sizeof(struct Instruction));
    new_inst->encoded_inst = inst_fetched;
    PC = PC + 1;
    return new_inst;
}

//decode current instruction by instruction type and instruction fields
struct Instruction* Instruction_Decode(struct Instruction* inst){
    uint8_t  opcode;
    uint8_t func;
    uint8_t Rs;
    uint8_t Rt;
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

        inst->rs_val = Rs;
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

        inst->rs_val = Rs;
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

struct Instruction* Instruction_Execute(struct Instruction* inst){

}

//Accessing memory for load/store instructions
struct Instruction* Instruction_Mem(struct Instruction* inst){
    uint32_t val;
    if(inst->name == "LB"){
        val = 0x000000ff & dataMem[inst->mem_address];
        if((val & 0x80)== 1){
            val = 0xffffff00 | val;
        }
        else{
            val = 0x00000000 & val;
        }
    }
    else if(inst->name == "LBU") {
        val = 0x000000ff & dataMem[inst->mem_address];
    }
    else if(inst->name == "LHU"){
        val = 0x0000ffff & dataMem[inst->mem_address];
    }
}


int main(){
    ssize_t read;
    ssize_t len;
    int i;
    char line[10];
    char* eptr;
    int * instpointer;
    uint32_t inst_fetched;
    int upper[50];
    
    //char string[] = "0x46902800";
    //char string[] = "0x24060064";
    //inst_fetched = strtol(string, &eptr, 0);
    //uint32_t a = (inst_fetched >> 4);
    //uint16_t b = (inst_fetched >> 16);
    //printf("%d = %lu = %lu", string, inst_fetched, a);
    //printf("%s = %lu = %lu\n", string, inst_fetched, b);

    instpointer = Initialize_Simulation_Memory();

    for (i=0; i < 20; i++) {
        instarray[i] = *(instpointer+i);
        upper[i] = (instarray[i] >> 16);
        printf( "(instruction line + %d) : fetched: %d, upper four: %d\n", i, instarray[i], upper[i]);
    }
    if(upper[11] == 0x2406){
        printf("YES\n");
    }
    else{
        printf("BOO\n");
    }
}

