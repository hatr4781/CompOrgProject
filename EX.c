#include "EX.h"
#include "string.h"

void Instruction_Execute()
{

    shEM->name = DE->name;
    shEM->type = DE->type;
    if(!strcmp(DE->name, "NOP")) {
        shEM->RegDst = 0;
        shEM->ALURes = 0;
        return;
    }

    else if(!strcmp(DE->name, "ADD")) {
        shEM->RegDst = DE->RegRd;
        shEM->ALURes = (DE->ReadData1) + (DE->ReadData2);
    }

    else if(!strcmp(DE->name, "ADDI")) {
        shEM->RegDst = DE->RegRt;
        shEM->ALURes = (DE->ReadData1) + (DE->Immed);
    }

    else if(!strcmp(DE->name, "ADDIU")) {
        shEM->RegDst = DE->RegRt;
        shEM->ALURes = (DE->ReadData1) + (DE->Immed);
    }

    else if(!strcmp(DE->name, "ADDU")) {
        shEM->RegDst = DE->RegRd;
        shEM->ALURes = (DE->ReadData1) + (DE->ReadData2);
    }

    else if(!strcmp(DE->name, "SUB")) {
        shEM->RegDst = DE->RegRd;
        shEM->ALURes = (DE->ReadData1) - (DE->ReadData2);
    }

    else if(!strcmp(DE->name, "SUBU")) {
        shEM->RegDst = DE->RegRd;
        shEM->ALURes = (DE->ReadData1) - (DE->ReadData2);
    }

    else if(!strcmp(DE->name, "AND")) {
        shEM->RegDst = DE->RegRd;
        shEM->ALURes = (DE->ReadData1) & (DE->ReadData2);
    }

    else if(!strcmp(DE->name, "ANDI")) {
        shEM->RegDst = DE->RegRt;
        shEM->ALURes = (DE->ReadData1) & (DE->Immed);
    }

    else if(!strcmp(DE->name, "OR")) {
        shEM->RegDst = DE->RegRd;
        shEM->ALURes = (DE->ReadData1) | (DE->ReadData2);
    }

    else if(!strcmp(DE->name, "ORI")) {
        shEM->RegDst = DE->RegRt;
        shEM->ALURes = (DE->ReadData1) | (DE->Immed);
    }

    else if(!strcmp(DE->name, "SLT")) {
        shEM->RegDst = DE->RegRd;
        shEM->ALURes = ((DE->ReadData1) < (DE->ReadData2)) ?1:0;
    }

    else if(!strcmp(DE->name, "SLTI")) {
        shEM->RegDst = DE->RegRt;
        shEM->ALURes = ((DE->ReadData1) < (DE->Immed)) ?1:0;
    }

    else if(!strcmp(DE->name, "SLTIU")) {
        shEM->RegDst = DE->RegRt;
        shEM->ALURes = ((DE->ReadData1) < (DE->Immed)) ?1:0;
    }

    else if(!strcmp(DE->name, "SLTU")) {
        shEM->RegDst = DE->RegRd;
        shEM->ALURes = ((DE->ReadData1) < (DE->ReadData2)) ?1:0;
    }

    else if(!strcmp(DE->name, "XOR")) {
        shEM->RegDst = DE->RegRd;
        shEM->ALURes = DE->ReadData1 ^ DE->ReadData2;
    }

    else if(!strcmp(DE->name, "XORI")) {
        shEM->RegDst = DE->RegRt;
        shEM->ALURes = DE->ReadData1 ^ DE->Immed;
    }

    else if(!strcmp(DE->name, "NOR")) {
        shEM->RegDst = DE->RegRd;
        shEM->ALURes = ~((DE->ReadData1)|(DE->ReadData2));
    }

    else if(!strcmp(DE->name, "JR")) {
        shEM->RegDst = 0;
        shEM->ALURes = 0;
    }

    else if(!strcmp(DE->name, "MOVZ")) {
        shEM->RegDst = DE->RegRd;
        shEM->ALURes = 0;
        if(DE->ReadData2 == 0) {
            shEM->ALURes = DE->ReadData1;
        }

    }

    else if(!strcmp(DE->name, "MOVN")) {
        shEM->RegDst = DE->RegRd;
        shEM->ALURes = 0;
        if(DE->ReadData2 != 0) {
            shEM->ALURes = DE->ReadData1;
        }
    }

    else if(!strcmp(DE->name, "SLL")) {
        shEM->RegDst = DE->RegRd;
        shEM->ALURes = DE->ReadData2 << DE->ReadData1;
    }

    else if(!strcmp(DE->name, "SRL")) {
        shEM->RegDst = DE->RegRd;
        shEM->ALURes = DE->ReadData2 >> DE->ReadData1;
    }

    else if(!strcmp(DE->name, "J")) {
        shEM->RegDst = 0;
        shEM->ALURes = 0;
    }

    else if(!strcmp(DE->name, "JAL")) {
        shEM->RegDst = 0;
        shEM->ALURes = 0;
    }

    //Memory Functions
    else if(!strcmp(DE->name, "LB")) {
        shEM->ALURes = DE->ReadData1 + DE->Immed;
        shEM->RegDst = DE->RegRt;
    }

    else if(!strcmp(DE->name, "LBU")) {
        shEM->ALURes = DE->ReadData1 + DE->Immed;
        shEM->RegDst = DE->RegRt;
    }

    else if(!strcmp(DE->name, "LHU")) {
        shEM->ALURes = DE->ReadData1 + DE->Immed;
        shEM->RegDst = DE->RegRt;
    }

    else if(!strcmp(DE->name, "LUI")) {
        shEM->ALURes = DE->Immed << 16;
        shEM->RegDst = DE->RegRt;
    }

    else if(!strcmp(DE->name, "LW")) {
        shEM->RegDst = DE->RegRt;
        shEM->ALURes = DE->ReadData1 + DE->Immed;
    }

    else if(!strcmp(DE->name, "SB")) {
        shEM->RegDst = 0;
        shEM->ALURes = DE->ReadData1 + DE->Immed;
        shEM->ReadData2 = DE->ReadData2;
    }

    else if(!strcmp(DE->name, "SH")) {
        shEM->RegDst = 0;
        shEM->ALURes = DE->ReadData1 + DE->Immed;
        shEM->ReadData2 = DE->ReadData2;
    }

    else if(!strcmp(DE->name, "SW")) {
        shEM->RegDst = 0;
        shEM->ALURes = DE->ReadData1 + DE->Immed;
        shEM->ReadData2 = DE->ReadData2;
    }

    else if(!strcmp(DE->name, "BEQ")) {
        shEM->RegDst = 0;
        shEM->ALURes = 0;
    }

    else if(!strcmp(DE->name, "BNE")) {
        shEM->RegDst = 0;
        shEM->ALURes = 0;
    }

    else if(!strcmp(DE->name, "BGTZ")) {
        shEM->RegDst = 0;
        shEM->ALURes = 0;
    }

    else if(!strcmp(DE->name, "BLEZ")) {
        shEM->RegDst = 0;
        shEM->ALURes = 0;
    }
    else{
        printf("Instruction Execute Error");
    }

    /*
    printf("EXECUTE: %s \nRegDst = %d\n ReadData2 = %d\nALURes = %d\n",
           shEM->name, shEM->RegDst, shEM->ReadData2, shEM->ALURes);
    */
    return;

}