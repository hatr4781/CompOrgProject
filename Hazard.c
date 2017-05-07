//
// Created by Ha on 5/5/2017.
//

#include <mem.h>
#include "Hazard.h"

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

void Hazard_Forwarding(){

    if(ID_inst->encoded_inst == EX_inst->encoded_inst){
        return;
    }

    if(ID_inst->encoded_inst == MEM_inst->encoded_inst){
        return;
    }

    switch(ID_inst->type) {
        case ALU_TYPE:
            if (ID_inst->instruction_type == R_INST) {
                //check load/R
                if ((EX_inst->type == LOAD_TYPE) || (MEM_inst->type == LOAD_TYPE)) {
                    if (EX_inst->type == LOAD_TYPE) {
                        if (EX_inst->rt == ID_inst->rs || ID_inst->rt) {
                            PC = PC - 2; //insert nop
                            IF_inst->encoded_inst = 0x00000000;
                            makeIDtoNOP();
                        }
                    } else if (MEM_inst->type == LOAD_TYPE) {
                        if (MEM_inst->rt == (ID_inst->rs || ID_inst->rt)) {
                            if (MEM_inst->rt == ID_inst->rs) {
                                ID_inst->rs_val = MEM_inst->rt_val;
                            }
                            if (MEM_inst->rt == ID_inst->rt) {
                                ID_inst->rt_val = MEM_inst->rt_val;
                            }
                        }
                    }
                }
                //check R-R
                if ((EX_inst->instruction_type == R_INST) || (MEM_inst->instruction_type == R_INST)) {
                    if (EX_inst->rd == ID_inst->rs) {
                        ID_inst->rs_val = EX_inst->rd_val;
                    } else if (MEM_inst->rd == ID_inst->rs) {
                        ID_inst->rs_val = MEM_inst->rd_val;
                    }
                    if (EX_inst->rd == ID_inst->rt) {
                        ID_inst->rt_val = EX_inst->rd_val;
                    } else if (MEM_inst->rd == ID_inst->rt) {
                        ID_inst->rt_val = MEM_inst->rd_val;
                    }
                }
                //check I-R
                if ((EX_inst->instruction_type == I_INST) || (MEM_inst->instruction_type == I_INST)) {
                    if (EX_inst->rt == ID_inst->rs) {
                        ID_inst->rs_val = EX_inst->rt_val;
                    } else if (MEM_inst->rt == ID_inst->rs) {
                        ID_inst->rs_val = MEM_inst->rt_val;
                    }
                    if (EX_inst->rt == ID_inst->rt) {
                        ID_inst->rt_val = EX_inst->rt_val;
                    } else if (MEM_inst->rt == ID_inst->rt) {
                        ID_inst->rt_val = MEM_inst->rt_val;
                    }
                }
            }
            if (ID_inst->instruction_type == I_INST) {
                //check load-I
                if ((EX_inst->type == LOAD_TYPE) || (MEM_inst->type == LOAD_TYPE)) {
                    if (EX_inst->type == LOAD_TYPE) {
                        if (EX_inst->rt == ID_inst->rs) {
                            PC = PC - 2; //insert nop
                            IF_inst->encoded_inst = 0x00000000;
                            makeIDtoNOP();
                        }
                    } else if (MEM_inst->type == LOAD_TYPE) {
                        if (MEM_inst->rt == ID_inst->rs) {
                            if (MEM_inst->rt == ID_inst->rs) {
                                ID_inst->rs_val = MEM_inst->rt_val;
                            }
                            if (MEM_inst->rt == ID_inst->rt) {
                                ID_inst->rt_val = MEM_inst->rt_val;
                            }
                        }
                    }
                }
                //check R-I
                if ((EX_inst->instruction_type == R_INST) || (MEM_inst->instruction_type == R_INST)) {
                    if (EX_inst->rd == ID_inst->rs) {
                        ID_inst->rs_val = EX_inst->rd_val;
                    } else if (MEM_inst->rd == ID_inst->rs) {
                        ID_inst->rs_val = MEM_inst->rd_val;
                    }
                }
                //check I-I
                if ((EX_inst->instruction_type == I_INST) || (MEM_inst->instruction_type == I_INST)) {
                    if (EX_inst->rt == ID_inst->rs) {
                        ID_inst->rs_val = EX_inst->rt_val;
                    } else if (MEM_inst->rt == ID_inst->rs) {
                        ID_inst->rs_val = MEM_inst->rt_val;
                    }
                }
            }
            break;
        case STORE_TYPE:
            if ((EX_inst->instruction_type == R_INST) || (MEM_inst->instruction_type == R_INST)) {
                //R-store
                if (EX_inst->rd == ID_inst->rs) {
                    ID_inst->rs_val = EX_inst->rd_val;
                } else if (MEM_inst->rd == ID_inst->rs) {
                    ID_inst->rs_val = MEM_inst->rd_val;
                }
                if (EX_inst->rd == ID_inst->rt) {
                    ID_inst->rt_val = EX_inst->rd_val;
                } else if (MEM_inst->rd == ID_inst->rt) {
                    ID_inst->rt_val = EX_inst->rd_val;
                }
            }
            if ((EX_inst->instruction_type == I_INST) || (MEM_inst->instruction_type == I_INST)) {
                //I-store
                if (EX_inst->rt == ID_inst->rs) {
                    ID_inst->rs_val = EX_inst->rt_val;
                }
                else if (MEM_inst->rt == ID_inst->rs) {
                    ID_inst->rs_val = MEM_inst->rt_val;
                }
                if (EX_inst->rt == ID_inst->rt) {
                    ID_inst->rt_val = EX_inst->rt_val;
                }
                else if (MEM_inst->rt == ID_inst->rt) {
                    ID_inst->rt_val = MEM_inst->rt_val;
                }
            }
            //load-store
            if((EX_inst->type == LOAD_TYPE) || (MEM_inst->type == LOAD_TYPE)){
                if(EX_inst->type == LOAD_TYPE){
                    if(EX_inst->rt == ID_inst->rt){
                        PC = PC - 2; //insert nop
                        IF_inst->encoded_inst = 0x00000000;
                        makeIDtoNOP();
                    }
                }
                else if((MEM_inst->type == LOAD_TYPE) && (EX_inst->rt != ID_inst->rt)){
                    if(MEM_inst->rt == ID_inst->rt){
                        ID_inst->rt_val = MEM_inst->rt_val;
                    }
                }
            }
            break;
        case LOAD_TYPE:
            //int load_address = ID_inst->rs_val + ID_inst->immed;
            //load-load
            if((EX_inst->type == LOAD_TYPE || MEM_inst->type == LOAD_TYPE)){
                if(EX_inst->type == LOAD_TYPE){
                    if(EX_inst->rt == ID_inst->rs){
                        PC = PC- 2;
                        IF_inst->encoded_inst = 0x00000000;
                        makeIDtoNOP();
                    }
                }
                if((MEM_inst->type == LOAD_TYPE) && (EX_inst->rt != ID_inst->rs)){
                    if(MEM_inst->rt == ID_inst->rs){
                        ID_inst->rs_val = MEM_inst->rt;
                    }
                }
            }
            //R-load
            if((EX_inst->instruction_type == R_INST) || (MEM_inst->instruction_type == R_INST)){
                if (EX_inst->rd == ID_inst->rs) {
                    ID_inst->rs_val = EX_inst->rd_val;
                }
                else if(MEM_inst-> rd == ID_inst->rs){
                    ID_inst->rs_val = MEM_inst->rd_val;
                }
            }
            //I-load
            if((EX_inst->instruction_type == I_INST) || (MEM_inst->instruction_type == I_INST)){
                if (EX_inst->rt == ID_inst->rs) {
                    ID_inst->rs_val = EX_inst->rt_val;
                }
                else if(MEM_inst-> rt == ID_inst->rs){
                    ID_inst->rs_val = MEM_inst->rt_val;
                }
            }
            break;


    }
}