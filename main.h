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
#include <stdio.h>
//#include "Load_Program.h"

#define MEM_LENGTH 1200
#define R_INST 0
#define I_INST 1
#define J_INST 2

/*
#define SP reg[29]
#define FP reg[30]
*/

#include <stdint.h>

typedef int8_t SIGNED_BYTE;
typedef uint8_t UNSIGNED_BYTE;

typedef int16_t SIGNED_HALFWORD;
typedef uint16_t UNSIGNED_HALFWORD;

typedef int32_t SIGNED_WORD;
typedef uint32_t UNSIGNED_WORD;

int32_t reg[32];
uint32_t memory[MEM_LENGTH];

int32_t PC;

/*
struct Instruction* Instruction_Fetch();
struct Instruction* Instruction_Decode(Instruction* inst);
*/

void Initialize_Simulation_Memory();
struct Instruction{
    char* name;
    uint32_t encoded_inst;
    uint8_t rs;
    int32_t rs_val;
    uint8_t rd;
    int32_t rd_val;
    uint8_t rt;
    int32_t rt_val;
    int32_t immed;
    uint8_t shamt;
    uint32_t addr;
//    uint32_t mem_address;

    int instruction_type;
};

/*
typedef struct {
    Instruction* ID;
    Instruction* IF;
    Instruction* EX;
    Instruction* MEM;
    Instruction* WB;
} Shadow;
*/


/*
struct Instruction* IF_inst;
struct Instruction* ID_inst;
struct Instruction* _inst;
struct Instruction*
*/


#endif //PROJECT_MAIN_H
