#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char checkIpClass(int, int, int, int);

int if_ValableNetMask(int, int, int, int);  //return 0 if true
int toDecimal(char* );
int countConsecutiveZero (int);
int changeBits(int , int);

void start();
void enterNetMask(int*, int*, int*, int*);
void enterIP(int*, int*, int*, int*);