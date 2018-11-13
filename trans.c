#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{

	// check syntax 
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}


	strcpy(mcode, "AB CD EF");

	//is_vaild give args information to data
	//1. register to register	
	if(!(strcmp(data.fmod,"REG")) && !(strcmp(data.smod,"REG")))
		strcpy(mcode,"89");
	//2. mem to reg(addressing w.o/disp.)
	else if(!(strcmp(data.fmod,"MEMREG"))&&!(strcmp(data.smod,"REG")))
		strcpy(mcode,"8b");
	//3.mem to reg(addressing w/disp.)
	else if(!(strcmp(data.fmod,"ZXMEM"))&&!(strcmp(data.smod,"REG")))
		strcpy(mcode,"8b");
	//4. mem to reg(eax)
	else if(!(strcmp(data.fmod,"MEMZX"))&&!(strcmp(data.second,"%eax")))
		strcpy(mcode,"a1");
	//5. reg(eax) to mem
	else if(!(strcmp(data.first,"%eax"))&&!(strcmp(data.smod,"MEMZX")))
		strcpy(mcode,"a3");
	//6, immediate to reg
	else if(!(strcmp(data.fmod,"IMM"))&&!(strcmp(data.smod,"REG")))
		if(!(strcmp(data.second,"%eax")))
			strcpy(mcode,"b8");
		else if(!(strcmp(data.second,"%ecx")))
			strcpy(mcode,"b9");
		else if(!(strcmp(data.second,"%edx")))
			strcpy(mcode,"ba");
		else if(!(strcmp(data.second,"%ebx")))
			strcpy(mcode,"bb");
		else if(!(strcmp(data.second,"%esp")))
			strcpy(mcode,"bc");
		else if(!(strcmp(data.second,"%ebp")))
			strcpy(mcode,"bd");
		else if(!(strcmp(data.second,"%esi")))
			strcpy(mcode,"be");
		else if(!(strcmp(data.second,"%edi")))
			strcpy(mcode,"ef");
	else{
		strcpy(mcode,"error");
		return 0;
		}
	return 1;	
}
