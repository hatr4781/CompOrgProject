//
// Created by Ha on 5/5/2017.
//

#include <mem.h>
#include "Hazard.h"

/*
void makeIDtoNOP(){
    ID_inst->rt_val = 0;
    ID_inst->rt = 0;
    ID_inst->rs_val = 0;
    ID_inst->rs = 0;
    ID_inst->rd_val = 0;
    ID_inst->rd = 0;
    ID_inst->addr = 0;
    ID_inst->shamt = 0;
    ID_inst->name = "NOP";
}
*/

void Hazard_Forwarding(){

    switch(shDE->type) {
        case R_TYPE | STORE_TYPE:
            if ((shDE->RegRs == shMW->RegDst) && (shMW->RegDst != 0) && (shDE->RegRs != 0)) {
                if (shMW->type == LOAD_TYPE) {
                    shDE->ReadData1 = shMW->Mem_Data_Read;
                }
                shDE->ReadData1 = shMW->ALURes;
            }
            if ((shDE->RegRt == shMW->RegDst) && (shMW->RegDst != 0) && (shDE->RegRt != 0)) {
                if (shMW->type == LOAD_TYPE) {
                    shDE->ReadData2 = shMW->Mem_Data_Read;
                }
                shDE->ReadData2 = shMW->ALURes;
            }

            if ((shDE->RegRs == shEM->RegDst) && (shEM->RegDst != 0) && (shDE->RegRs != 0)) {
                if (shEM->type == LOAD_TYPE) {
                    shFD->inst_fetched = 0x00000000;
                    shFD->PC = shFD->PC - 2;
                    return;
                }
                shDE->ReadData1 = shEM->ALURes;
            }
            if ((shDE->RegRt == shEM->RegDst) && (shEM->RegDst != 0) && (shDE->RegRt != 0)) {
                if (shEM->type == LOAD_TYPE) {
                    shFD->inst_fetched = 0x00000000;
                    shFD->PC = shFD->PC - 2;
                    return;
                }
                shDE->ReadData2 = shEM->ALURes;
            }
            break;

        case I_TYPE:
            if ((shDE->RegRs == shMW->RegDst) && (shMW->RegDst != 0) && (shDE->RegRs != 0)) {
                if (shMW->type == LOAD_TYPE) {
                    shDE->ReadData1 = shMW->Mem_Data_Read;
                }
                shDE->ReadData1 = shMW->ALURes;
            }
            if ((shDE->RegRs == shEM->RegDst) && (shEM->RegDst != 0) && (shDE->RegRs != 0)) {
                if (shEM->type == LOAD_TYPE) {
                    shFD->inst_fetched = 0x00000000;
                    shFD->PC = shFD->PC - 2;
                }
                shDE->ReadData1 = shEM->ALURes;
            }
            break;

        case BR_TYPE:
            if ((shDE->RegRs == shMW->RegDst) && (((shMW->RegDst != 0) && (shDE->RegRs != 0)) || (!strcmp(shDE->name, "JR")))){
                if (shMW->type == LOAD_TYPE) {
                    shDE->ReadData1 = shMW->Mem_Data_Read;
                }
                else {
                    shDE->ReadData1 = shMW->ALURes;
                }
                if(!strcmp(shDE->name, "JR")){
                    shDE->target_branch = shDE->ReadData1;
                }
            }

            if ((shDE->RegRt == shMW->RegDst) && (shMW->RegDst != 0) && (shDE->RegRt != 0) && (shDE->RegRt != 0)) {
                if (shMW->type == LOAD_TYPE) {
                    shDE->ReadData2 = shMW->Mem_Data_Read;
                }
                shDE->ReadData2 = shMW->ALURes;
            }

            if ((shDE->RegRs == shEM->RegDst) && (((shEM->RegDst != 0) && (shDE->RegRs != 0)) || (!strcmp(shDE->name, "JR")))) {
                if (shEM->type == LOAD_TYPE) {
                    shFD->inst_fetched = 0x00000000;
                    shFD->PC = shFD->PC - 2;
                    control_hazard = 1;
                    return;
                }
                shDE->ReadData1 = shEM->ALURes;
                if(!strcmp(shDE->name, "JR")){
                    shDE->target_branch = shDE->ReadData1;
                }
            }
            if ((shDE->RegRt == shEM->RegDst) && (shEM->RegDst != 0) && (shDE->RegRt != 0) && (shDE->RegRt != 0)) {
                if (shEM->type == LOAD_TYPE) {
                    shFD->inst_fetched = 0x00000000;
                    shFD->PC = shFD->PC - 2;
                    control_hazard = 1;
                    return;
                }
                shDE->ReadData2 = shEM->ALURes;
            }

            if(!control_hazard){
                if(strcmp(shDE->name, "BLTZ")){
                    if(shDE->ReadData1 < 0){
                        branched = 1;
                    }
                }
                else if(!strcmp(shDE->name, "BEQ")){
                    if(shDE->ReadData1 == shDE->ReadData2){
                        branched = 1;
                    }
                }
                else if(!strcmp(shDE->name, "BNE")){
                    if(shDE->ReadData1 != shDE-> ReadData2){
                        branched = 1;
                    }
                }
                else if(!strcmp(shDE->name, "BGTZ")){
                    if(shDE->ReadData1 > 0){
                        branched = 1;
                    }
                }
                else if(!strcmp(shDE->name, "BLEZ")){
                    if(shDE->ReadData1 <= 0){
                        branched = 1;
                    }
                }
                else if(!strcmp(shDE->name, "JR")){
                    branched = 1;
                    shDE->target_branch = (shDE->target_branch)/4;
                }
                if(branched){
                    branched = 0;
                    if(!strcmp(shDE->name, "JR")){
                        shFD->PC = shDE->target_branch;
                    }
                    else{
                        shFD->PC = shFD->PC + shDE->target_branch;
                    }
                }
            }
            control_hazard = 0;
            break;
        default:
            //printf("Bypass hazard check\n");
            break;
    }

    //printf("Hazard_Forwarding: %s\nPC = %d\n", shDE->name, shFD->PC);
}