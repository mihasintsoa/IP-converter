#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* convertNetMask(int);
char checkIpClass(int, int, int, int);

int toDecimal(char*, int);
int countConsecutiveZero (int);
int changeBits(int , int);
int detNumOfMaxPC (int b1, int b2, int b3, int b4, int sub1, int sub2, int sub3, int sub4);

void start();
void enterCIDR(int* ,int*, int*, int*, int*);
void netMaskToAddress(char*, int*, int*, int*, int*);
void divide(int byte1, int byte2, int byte3,int byte4, int netMask);