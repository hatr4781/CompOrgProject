#include "MEM.h"

//Accessing memory for load/store instructions
struct Instruction* Instruction_Memory(struct Instruction* inst){
    uint32_t val;
    int byte_offset;
    int mem_word;
    uint32_t mem_address;

    mem_address = inst->mem_address;
    mem_word = mem_address / 4;

    int offset;
    if(inst->name == "LB"){
        offset = mem_address % 4;

        if(offset == 0){
            val = BYTE_0 & memory[mem_word];
            if(val & 0x00000080){
                val = 0xffffff00 | val;
            }
        }
        else if(offset == 1){
            val = (BYTE_1 & memory[mem_word]) >> 8;
            if(val & 0x00000080){
                val = 0xffffff00 | val;
            }
        }
        else if(offset == 2){
            val = (BYTE_2 & memory[mem_word]) >> 16;
            if(val & 0x00000080){
                val = 0xffffff00 | val;
            }
        }
        else if(offset == 3){
            val = (BYTE_3 & memory[mem_word]) >> 24;
            if(val & 0x00000080){
                val = 0xffffff00 | val;
            }
        }
        inst->rt_val = (SIGNED_WORD) val;
    }

    else if(inst->name == "LBU") {
        offset = mem_address % 4;
        if(offset == 0){
            val = BYTE_0 & memory[mem_word];
        }
        else if(offset == 1){
            val = (BYTE_1 & memory[mem_word]) >> 8;
        }
        else if(offset == 2){
            val = (BYTE_2 & memory[mem_word]) >> 16;
        }
        else if(offset == 3){
            val = (BYTE_3 & memory[mem_word]) >> 24;
        }
        inst->rt_val = (UNSIGNED_WORD) val;
    }
    else if(inst->name == "LHU"){
        offset = mem_word % 2;
        if(offset == 0){
            val = HALF_0 & memory[mem_word];
        }
        else if(offset == 1){
            val = (HALF_1 & memory[mem_word]) >> 16;
        }
        inst->rt_val = (UNSIGNED_WORD) val;
    }
    else if(inst->name == "LW"){
        val = memory[mem_word];
        inst->rt_val = (SIGNED_WORD) val;
    }

}