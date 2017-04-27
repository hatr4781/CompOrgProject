#include "register.h"

struct register reg_file[32];

//Initializing registers r[0-31]
void init_reg_file() {

    strcpy(reg_file[0].reg_name,"zero");
    strcpy(reg_file[1].reg_name,"at");
    strcpy(reg_file[2].reg_name,"v0");
    strcpy(reg_file[3].reg_name,"v1");
    strcpy(reg_file[4].reg_name,"a0");
    strcpy(reg_file[5].reg_name,"a1");
    strcpy(reg_file[6].reg_name,"a2");
    strcpy(reg_file[7].reg_name,"a3");
    strcpy(reg_file[8].reg_name,"t0");
    strcpy(reg_file[9].reg_name,"t1");
    strcpy(reg_file[10].reg_name,"t2");
    strcpy(reg_file[11].reg_name,"t3");
    strcpy(reg_file[12].reg_name,"t4");
    strcpy(reg_file[13].reg_name,"t5");
    strcpy(reg_file[14].reg_name,"t6");
    strcpy(reg_file[15].reg_name,"t7");
    strcpy(reg_file[16].reg_name,"s0");
    strcpy(reg_file[17].reg_name,"s1");
    strcpy(reg_file[18].reg_name,"s2");
    strcpy(reg_file[19].reg_name,"s3");
    strcpy(reg_file[20].reg_name,"s4");
    strcpy(reg_file[21].reg_name,"s5");
    strcpy(reg_file[22].reg_name,"s6");
    strcpy(reg_file[23].reg_name,"s7");
    strcpy(reg_file[24].reg_name,"t8");
    strcpy(reg_file[25].reg_name,"t9");
    strcpy(reg_file[26].reg_name,"k0");
    strcpy(reg_file[27].reg_name,"k1");
    strcpy(reg_file[28].reg_name,"gp");
    strcpy(reg_file[29].reg_name,"sp");
    strcpy(reg_file[30].reg_name,"fp");
    strcpy(reg_file[31].reg_name,"ra");
 
    return;
}

int reg_num(char*reg_name) {
    int i;
    //if input string is register # or register_name
    j = strlen(reg_name);
    if (i==1)
        return reg_name[0] - '0';
    //if it is register_name, continue to find register number for chosen register_name
    for(i=0; i<32; i++)
    {
            if(!strcmp(reg_file[i].reg_name, reg_name))
                break;
    }
    
    else if(i != 32)
        return i;
    else
    {
        printf("No register such as %s", reg_name);
    }
}
