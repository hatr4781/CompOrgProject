#include <mem.h>
#include "MEM.h"

//Accessing memory for load/store instructions
void Instruction_Memory(){

    if(MEM_inst == NULL){
        return;
    }

/*
    if(MEM_inst->name != ("LB"|| "LBU"|| "LHU"|| "LW"|| "SB"|| "SH"||"SW")){
        return;
    }
*/
    int32_t val = 0;
    //int byte_offset;
    int mem_word;
    int32_t mem_address;
    int32_t temp = 0;

    mem_address = MEM_inst->addr;
    mem_word = mem_address / 4;
    printf("Memory[%d] = %d\n", mem_word, memory[mem_word]);
    int offset;

    if(!strcmp(MEM_inst->name, "LW")){
        val = memory[mem_word];
        MEM_inst->rt_val = val;
    }
    else if(!strcmp(MEM_inst->name, "LB")){
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
        MEM_inst->rt_val = val;
    }

    else if(!strcmp(MEM_inst->name, "LBU")) {
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
        MEM_inst->rt_val = val;
    }

    else if(!strcmp(MEM_inst->name, "LHU")){
        offset = mem_word % 2;
        if(offset == 0){
            val = HALF_0 & memory[mem_word];
        }
        else if(offset == 1){
            val = (HALF_1 & memory[mem_word]) >> 16;
        }
        MEM_inst->rt_val = val;
    }


    else if(!strcmp(MEM_inst->name, "SB")){
        offset = mem_word % 4;
        //take least significant byte of rt
        val = BYTE_0 & MEM_inst->rt_val;
        //zero out byte in memory to be replaced
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

    else if(!strcmp(MEM_inst->name, "SH")){
        offset = mem_word % 2;
        val = HALF_0 & MEM_inst->rt_val;
        if(offset == 0){
            temp = 0xffff0000 & memory[mem_word];
        }
        else if(offset == 1){
            temp = 0x0000ffff & memory[mem_word];
            val = val << 16;
        }
        memory[mem_word] = temp | val;
    }
    else if(!strcmp(MEM_inst->name, "SW")){
        memory[mem_word] = MEM_inst->rt_val;
    }
    printf("Memory[%d] = %d\n", mem_word, memory[mem_word]);
    printf("MEM_STAGE: %s \nrs_val = %d\nrt_val = %d\nrd_val = %d\nimmed = %d\naddr = %d\n",
           MEM_inst->name, MEM_inst->rs_val, MEM_inst->rt_val, MEM_inst->rd_val, MEM_inst->immed, MEM_inst->addr);
    return;
}