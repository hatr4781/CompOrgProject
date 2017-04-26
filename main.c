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

//int dataMem[200];
//uint32_t instMem[MEM_LENGTH];
//int PC = 0;

uint32_t reg[32];

struct Instruction* Instruction_Fetch(){
    /*
    uint32_t inst_fetched;
    inst_fetched = instMem[PC];

    struct Instruction *new_inst;
    new_inst = malloc(sizeof(struct Instruction));
    new_inst->encoded_inst = inst_fetched;
    PC = PC +4;
    return new_inst;
    */


}

struct Instruction* Instruction_Decode(struct Instruction* inst){
    uint8_t  opcode;
    uint8_t func;
    uint8_t Rs;
    uint8_t Rt;
    uint8_t Rd;
    uint8_t  Shamt;
    uint16_t Immed;

    opcode = (inst->encoded_inst) >> 26;

    if(opcode == 0x00) {
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
    }
    else if(opcode < 0x04 ){
        inst->instruction_type = J_INST;
        switch(opcode){
            case 0x02:
                inst->name = "J";
            case 0x03:
                inst->name = "JAL";
        }
    }
    else if(opcode < 0x1f){
        inst->instruction_type = I_INST;
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
        inst->name = "SEB";
    }


}


int main(){
    ssize_t read;
    ssize_t len;
    int i;
    char line[10];
    int instarray[50];
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

