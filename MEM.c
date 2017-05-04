#include "MEM.h"

//Accessing memory for load/store instructions
struct Instruction* Instruction_Memory(struct Instruction* inst){
    uint32_t val = 0;
    int byte_offset;
    int mem_word;
    uint32_t mem_address;
    uint32_t temp = 0;

    mem_address = inst->addr;
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
        inst->rt_val = val;
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

    else if(inst->name == "SB"){
        offset = mem_word % 4;
        val = BYTE_0 & (UNSIGNED_WORD)inst->rt_val;
        if (offset == 0){
            temp = 0xffffff00 & memory[mem_word];
        }
        else if(offset == 1){
            temp = 0xffff00ff & memory[mem_word];
            val = val << 8;
        }
        else if(offset == 2){
            temp = 0xff00ffff & memory[mem_word];
            val = val << 16;
        }
        else if(offset == 3){
            temp = 0x00ffffff & memory[mem_word];
            val = val << 24;
        }
        memory[mem_word] = temp | val;
    }

    else if(inst->name == "SH"){
        offset = mem_word % 2;
        val = HALF_0 & (UNSIGNED_WORD) inst->rt_val;
        if(offset == 0){
            temp = 0xffff0000 & memory[mem_word];
        }
        else if(offset == 1){
            temp = 0x0000ffff & memory[mem_word];
            val = val << 16;
        }
        memory[mem_word] = temp | val;
    }
    return inst;
}