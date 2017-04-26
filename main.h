//
// Created by Ha on 4/19/2017.
//

#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H

#include <stdint.h>

struct Instruction{
    char* name;
    uint32_t encoded_inst;
    uint8_t rs;
    uint8_t rd;
    uint8_t rt;
    int16_t immed;
    int8_t shamt;
    int instruction_type;
};



#endif //PROJECT_MAIN_H
