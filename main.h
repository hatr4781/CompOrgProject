//
// Created by Ha on 4/19/2017.
//

#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H

#include "IF.h"
#include "ID.h"
#include "EX.h"
#include "MEM.h"
#include "WB.h"

#define MEM_LENGTH 200
#define R_INST 0
#define I_INST 1
#define J_INST 2

#include <stdint.h>

uint32_t reg[32];
uint32_t memory[MEM_LENGTH];
uint32_t PC;

struct Instruction* Instruction_Fetch();
struct Instruction* Instruction_Decode(struct Instruction* inst);

struct Instruction{
    char* name;
    uint32_t encoded_inst;
    uint8_t rs;
    uint32_t rs_val;
    uint8_t rd;
    uint32_t rd_val;
    uint8_t rt;
    uint32_t rt_val;
    uint16_t immed;
    uint8_t shamt;
    uint32_t addr;
    uint32_t mem_address;

    int instruction_type;
};



#endif //PROJECT_MAIN_H
