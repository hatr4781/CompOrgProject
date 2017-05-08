#include <mem.h>
#include "MEM.h"

//Accessing memory for load/store instructions
void Instruction_Memory(){
/*
    if(MEM_inst->name != ("LB"|| "LBU"|| "LHU"|| "LW"|| "SB"|| "SH"||"SW")){
        return;
    }
*/
    int32_t val = 0;
    int mem_word;
    int32_t mem_address;
    int32_t temp = 0;
    int offset;

    mem_address = EM->ALURes;
    mem_word = mem_address/4;

    shMW->name = EM->name;
    shMW->RegDst = EM->RegDst;
    shMW->type = EM->type;

    if(!strcmp(EM->name, "LW")){
        val = memory[mem_word];
        shMW->Mem_Data_Read = val;
    }

    else if(!strcmp(EM->name, "LB")){
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
        shMW->Mem_Data_Read = val;
    }

    else if(!strcmp(EM->name, "LBU")) {
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
        shMW->Mem_Data_Read = val;
    }

    else if(!strcmp(EM->name, "LHU")){
        offset = mem_word % 2;
        if(offset == 0){
            val = HALF_0 & memory[mem_word];
        }
        else if(offset == 1){
            val = (HALF_1 & memory[mem_word]) >> 16;
        }
        shMW->Mem_Data_Read = val;
    }

    else if(!strcmp(EM->name, "SB")){
        offset = mem_word % 4;
        //take least significant byte of rt
        val = BYTE_0 & EM->ReadData2;
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

    else if(!strcmp(EM->name, "SH")){
        offset = mem_word % 2;
        val = HALF_0 & EM->ReadData2;
        if(offset == 0){
            temp = 0xffff0000 & memory[mem_word];
        }
        else if(offset == 1){
            temp = 0x0000ffff & memory[mem_word];
            val = val << 16;
        }
        memory[mem_word] = temp | val;
    }

    else if(!strcmp(EM->name, "SW")){
        memory[mem_word] = EM->ReadData2;
    }

    else{
        shMW->ALURes = EM->ALURes;
        shMW->Mem_Data_Read = 0;
    }

    //printf("Memory[%d] = %d\n", mem_word, memory[mem_word]);
   // printf("MEM_STAGE: %s \nALURes = %d\nMem_Data_Read = %d\nRegDst = %d,",
   //     shMW->name, shMW->ALURes, shMW->Mem_Data_Read, shMW->RegDst);
    return;
}