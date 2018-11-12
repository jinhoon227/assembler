#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// complete this header file

//data Field
typedef struct {
	char fmod[20]; //modR/M (first)
	char smod[20]; //modR/M (second)
	char first[20]; //before "," in args
	char second[20]; // after "," in args
}Data;

//this is valuable for instruction
Data data;
