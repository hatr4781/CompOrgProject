//
// Created by Ha on 4/19/2017.
//

#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H

#include <stdint.h>

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
