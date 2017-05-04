//
// Created by Ha on 4/27/2017.
//


#ifndef COMPORGPROJECT_MEM_H
#define COMPORGPROJECT_MEM_H

#include "main.h"

#define BYTE_0 0x000000ff
#define BYTE_1 0x0000ff00
#define BYTE_2 0x00ff0000
#define BYTE_3 0xff000000

#define HALF_0 0x0000ffff
#define HALF_1 0xffff0000

struct Instruction* Instruction_Memory(struct Instruction* inst);

#endif //COMPORGPROJECT_MEM_H
