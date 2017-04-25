#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include "main.h"

#define MEM_LENGTH 200
#define R_INST 0
#define I_INST 1
#define J_INST 2

int dataMem[200];
uint32_t instMem[MEM_LENGTH];
int PC = 0;

struct Instruction* Instruction_Fetch(){
    uint32_t inst_fetched;
    inst_fetched = instMem[PC];

    struct Instruction *new_inst;
    new_inst = malloc(sizeof(struct Instruction));
    new_inst->encoded_inst = inst_fetched;
    PC = PC +4;
    return new_inst;

}

struct Instruction* Instruction_Decode(struct Instruction* inst){
    uint8_t  opcode = (inst->encoded_inst) >> 26;
    if(opcode == 0x00) {
        inst->instruction_type = R_INST;

        uint8_t func = 0x003f & inst->encoded_inst;
        uint8_t Rs = ((inst->encoded_inst) >> 21) & 0x001f;
        uint8_t Rt = ((inst->encoded_inst) >> 16) & 0x001f;
        uint8_t Rd = ((inst->encoded_inst) >> 11) & 0x001f;
        uint8_t  Shamt = ((inst->encoded_inst) >> 6) & 0x001f;

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
        inst->name = "BLTZ";
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
    char line[10];
    char* eptr;
    uint32_t inst_fetched;

    char string[] = "0x46902800";
    inst_fetched = strtol(string, &eptr, 0);
    //uint32_t a = (inst_fetched >> 4);
    uint16_t b = (inst_fetched >> 16);
    //printf("%s = %lu = %lu", string, inst_fetched, a);
    printf("%s = %lu = %lu", string, inst_fetched, b);
    if(b == 0x4690){
        printf("YES");
    }
    else{
        printf("BOO");
    }
    /*
    FILE* file = fopen("testfile.txt", "r");
    if(file == NULL){
        exit(EXIT_FAILURE);
    }
    */
    /*
    if((read = getline(&line, &len, file)) != -1){
        printf("%s\n", line);
        inst_fetched = strtol(line, eptr, 0);
    }
*/
//    Instruction_Fetch(file);
}

