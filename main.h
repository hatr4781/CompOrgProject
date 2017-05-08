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
#include "clock_cycle.h"
#include <stdio.h>
//#include "Load_Program.h"

#define MEM_LENGTH 1200

#define R_TYPE 0
#define I_TYPE 1
#define STORE_TYPE 2
#define LOAD_TYPE 3
#define BR_TYPE 4


/*
#define SP reg[29]
#define FP reg[30]
*/

#include <stdint.h>
//#include <rpcndr.h>

typedef int8_t SIGNED_BYTE;
typedef uint8_t UNSIGNED_BYTE;

typedef int16_t SIGNED_HALFWORD;
typedef uint16_t UNSIGNED_HALFWORD;

typedef int32_t SIGNED_WORD;
typedef uint32_t UNSIGNED_WORD;

int32_t reg[32];
uint32_t memory[MEM_LENGTH];

//int32_t PC;
//int32_t bubbled_s;
//int32_t bubbled_b;d


int32_t target_branch;
int branched;
int control_hazard;

/*
struct Instruction* Instruction_Fetch();
struct Instruction* Instruction_Decode(Instruction* inst);
*/

void Initialize_Simulation_Memory();
/*
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
    int32_t addr;
//    uint32_t mem_address;

    int instruction_type;
    int type;
};
*/

/*
struct Shadow{
    struct Instruction* ID;
    struct Instruction* IF;
    struct Instruction* EX;
    struct Instruction* MEM;
    struct Instruction* WB;
};
*/

struct PIPE_FD{
    int32_t PC;
    uint32_t inst_fetched;
};

struct PIPE_DE{
    int32_t RegRt;
    int32_t RegRd;
    int32_t RegRs;
    int32_t Immed;
    int32_t ReadData1;
    int32_t ReadData2;
    int32_t type;
    int32_t target_branch;
    char* name;
};

struct PIPE_EM{
    int32_t RegDst;
    int32_t RegRt;
    int32_t ReadData2;
    int32_t ALURes;
    int32_t type;
    char* name;
};

struct PIPE_MW{
    int32_t ALURes;
    int32_t Mem_Data_Read;
    int32_t RegDst;
    int32_t type;
    char* name;
};

struct PIPE_FD* FD;
struct PIPE_FD* shFD;
struct PIPE_DE* DE;
struct PIPE_DE* shDE;
struct PIPE_EM* EM;
struct PIPE_EM* shEM;
struct PIPE_MW* MW;
struct PIPE_MW* shMW;

#endif //PROJECT_MAIN_H
