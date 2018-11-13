#include "myas.h"
char* reg[8]={"%eax","%ecx","%edx","%ebx","%esp","%ebp","%esi","%edi"};
char* memReg[8] = {"(%eax)","(%ecx)","(%edx)","(%ebx)","(%esp)","(%ebp)","(%esi)","(%edi)"};


int isReg(char str[]){

	int i=0;
	for(i=0;i<8;i++){
		if(!strcmp(str,reg[i]))
			return 1;
	}

	return 0;
}

int isMemReg(char str[]){
	int i=0;

	//is str can (reg) or 0x(reg)
	for(i=0;i<8;i++){
		if(strstr(str,memReg[i])!=NULL){
			if(strstr(str,"0x")!=NULL)
				return 4; 	//0x(reg)
			else
				return 1;	//(reg)
		}
	}


	//is str can mem(0x) or imm($0x)
	if(strstr(str,"0x")!=NULL){
		if(!strncmp(str,"$",1))
			return 3; //imm
		else	
			return 2; //mem
	}

	return 0;
}


int is_valid(char *op, char *args)
{
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");


	//this assembler use only "mov" instruction!!!
	if(strcmp(op,"mov"))
		return 0;


	//tokenings %s %s",data.first,data.second);
	strcpy(data.first, strtok(args,","));
	strcpy(data.second, strtok(NULL,"\n"));

	//check tokened string
	if(data.first==NULL || data.second==NULL)
		return 0;
	//check vaild	
	if(isReg(data.first)) //if data is register
		strcpy(data.fmod,"REG");
	else{
		int a = isMemReg(data.first);
		if(a==1) //if data is memory register: (reg)
			strcpy(data.fmod,"MEMREG");
		else if(a==2) //if data is memory : 0x
			strcpy(data.fmod,"MEMZX");
		else if(a==3) //if data is immediate : $0x
			strcpy(data.fmod,"IMM");
		else if(a==4) //if data is memory : 0x(reg)
			strcpy(data.fmod,"ZXMEM");
		else
			return 0;
	}
	//check vailid
	if(isReg(data.second)) //if data is register
                strcpy(data.smod,"REG");
        else{
                int a = isMemReg(data.second);
                if(a==1) //if data is memory register: (reg)
                        strcpy(data.smod,"MEMREG");
                else if(a==2) //if data is memory  : 0x
                        strcpy(data.smod,"MEMZX");
                else if(a==3) //if data is immediate : $0x
                        strcpy(data.smod,"IMM");
		else if(a==4) //if data is memory  : 0x(reg)
			strcpy(data.smod,"ZXMEM");
                else
                        return 0;
        
	}
	return 1;
}
