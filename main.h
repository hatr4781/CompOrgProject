//
// Created by Ha on 4/19/2017.
//

#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H

#include <stdint.h>

struct Instruction{
    char* name;
    uint32_t encoded_inst;
    int rs;
    int rd;
    int rt;
    int immed;
    int shamt;
    int instruction_type;
};



#endif //PROJECT_MAIN_H
