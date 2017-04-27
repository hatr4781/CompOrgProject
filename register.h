#define REGISTER_SET
#include <stido.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

struct register {
	char reg_name[4];
	int value;
};

extern struct register reg_file[32];

void init_reg_file();
int reg_num(char*reg_name);

