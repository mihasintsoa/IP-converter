#include "headers.h"

void start()
{
    int byte1, byte2, byte3, byte4;
    int net1, net2, net3, net4;
    int check;
    int subNet1,subNet2,subNet3,subNet4;
    int broadCast1, broadCast2, broadCast3, broadCast4;
    int zeroCount;

    char ipClass;

    enterIP(&byte1, &byte2, &byte3, &byte4);
    enterNetMask(&net1, &net2, &net3, &net4);
    ipClass = checkIpClass(byte1, byte2, byte3, byte4);
    check = if_ValableNetMask(net1, net2, net3, net4);
    
    if (check == 0)
    {
        subNet1 = byte1 & net1;
        subNet2 = byte2 & net2;
        subNet3 = byte3 & net3;
        subNet4 = byte4 & net4;
        printf("The netWork address of IP:%d.%d.%d.%d with\n",byte1, byte2, byte3, byte4);
        printf("\tsubnet value of :%d.%d.%d.%d is\n",net1, net2, net3, net4);
        printf("\t%d.%d.%d.%d\n", subNet1, subNet2, subNet3, subNet4);

        zeroCount = countConsecutiveZero(net1);
        broadCast1 = changeBits(zeroCount, subNet1);
            zeroCount = countConsecutiveZero(net2);
            broadCast2 = changeBits(zeroCount, subNet2);
                zeroCount = countConsecutiveZero(net3);
                broadCast3 = changeBits(zeroCount, subNet3);
                        zeroCount = countConsecutiveZero(net4);
                        broadCast4 = changeBits(zeroCount, subNet4);

        switch (ipClass)
        {
        case 'A':   if (broadCast2 == 0) broadCast2 = 255;
                    if (broadCast3 == 0) broadCast3 = 255;
                    if (broadCast4 == 0) broadCast4 = 255;
            break;
        case 'B':   if (broadCast2 == 0) broadCast2 = 255;
                    if (broadCast3 == 0) broadCast3 = 255;
                    if (broadCast4 == 0) broadCast4 = 255;
            break;
        case 'C':   if (broadCast2 == 0) broadCast2 = 255;
                    if (broadCast3 == 0) broadCast3 = 255;
                    if (broadCast4 == 0) broadCast4 = 255;
            break;
        
        default:
            break;
        }
        printf("The broadCast Address is: %d.%d.%d.%d\n", broadCast1, broadCast2,broadCast3, broadCast4);

    }

}
char checkIpClass(int b1, int b2, int b3, int b4)
{
    char class;
    if ( b1 > 255 || b2 > 255 || b3 > 255 || b4 > 255)
            printf("The address IP :%d.%d.%d.%d is not a valable IP\n",b1, b2,b3, b4);
    else
    {
        if ( b1 >= 0 && b1 < 128)
        {
            printf("The address IP :%d.%d.%d.%d is valable and is class A\n",b1, b2,b3, b4);
            class = 'A';
        }
        if ( b1 >= 128 && b1 < 192)
        {
            printf("The address IP :%d.%d.%d.%d is valable and is class B\n",b1, b2,b3, b4);
            class = 'B';
        }
        if ( b1 >= 192 && b1 < 224)
        {
            printf("The address IP :%d.%d.%d.%d is valable and is class C\n",b1, b2,b3, b4);
            class = 'C';
        }
        if ( b1 >= 224 && b1 < 240)
        {
            printf("The address IP :%d.%d.%d.%d is valable and is class D\n",b1, b2,b3, b4);
            class = 'D';
        }
        if ( b1 >= 240 && b1 < 256)
        {
            printf("The address IP :%d.%d.%d.%d is valable and is class E\n",b1, b2,b3, b4);
            class = 'E';
        }
    }
    return (class);
}
int countConsecutiveZero (int byte)
{
    int streak ;
    streak = 0;
    while ( (byte & 1) == 0 && byte != 0)
    {
        streak++;
        byte >>= 1;
    }
    return (streak);
}
int changeBits(int consecutiveZero, int goal) 
{
    unsigned int final;
    unsigned int mask = (1u << consecutiveZero) - 1;
    final = goal | mask;
   
    return (final);
}
int toDecimal(char* byte)
{
    return (strtol(byte, NULL, 10));
}
int if_ValableNetMask(int net1, int net2, int net3, int net4)
{
    int check ;
    check = -1;

    switch (net1)
    {
        case 128:
        case 192:
        case 224:
        case 240:
        case 248:
        case 252:
        case 254:   if (net2 != 0)
                    {
                        check = -1;
                        printf("%d.%d.%d.%d is ",net1, net2, net3, net4);
                        printf("an Invalid netmask\n");
                    }
                    else check = 0;
            break;
        case 255: switch(net2)
                    {   case 0:
                        case 128:
                        case 192:
                        case 224:
                        case 240:
                        case 248:
                        case 252:
                        case 254:   if (net3 != 0)
                                    {
                                        check = -1;
                                        printf("%d.%d.%d.%d is ",net1, net2, net3, net4);
                                        printf("an Invalid netmask\n");
                                    }
                                    else check = 0;
                            break;
                        case 255: switch(net3)
                                    {
                                        case 0:
                                        case 128:
                                        case 192:
                                        case 224:
                                        case 240:
                                        case 248:
                                        case 252:
                                        case 254:   if (net4 != 0)
                                                    {
                                                        check = -1;
                                                        printf("%d.%d.%d.%d is ",net1, net2, net3, net4);
                                                        printf("an Invalid netmask\n");
                                                    }
                                                    else check = 0;
                                            break;
                                        case 255: if (net4 == 128 || net4 == 192 || net4 == 224 || net4 == 240 ||
                                                      net4 == 252 || net4 == 254) 
                                                            check = 0;
                                                else 
                                                {
                                                    printf("%d.%d.%d.%d is ",net1, net2, net3, net4);
                                                    printf("an Invalid netmask\n");
                                                    check = -1;
                                                }
                                        break;
                                        default:check = -1;
                                                printf("%d.%d.%d.%d is ",net1, net2, net3, net4);
                                                printf("an Invalid netmask\n");
                                            break;
                                    }
                            break;

                        default:check = -1;
                                printf("%d.%d.%d.%d is ",net1, net2, net3, net4);
                                printf("an Invalid netmask\n");
                            break;
                    }
            break;

        default:check = -1;
                printf("%d.%d.%d.%d is ",net1, net2, net3, net4);
                printf("an Invalid netmask\n");
        break;


    }

    return (check);
}
void enterIP(int* b1, int* b2, int* b3, int* b4)
{
    char* ip = (char*) malloc (256 * sizeof(char));
    char* byte1, *byte2, *byte3, *byte4;
    byte1 = (char*) malloc (256 * sizeof(char));
    byte2 = (char*) malloc (256 * sizeof(char));
    byte3 = (char*) malloc (256 * sizeof(char));
    byte4 = (char*) malloc (256 * sizeof(char));
    printf("Enter the IP address(X.X.X.X):");
    scanf("%s",ip);
    getchar();
    sscanf(ip, "%[^.].%[^.].%[^.].%[^.]", byte1, byte2, byte3, byte4);
    *b1 = toDecimal(byte1);
    *b2 = toDecimal(byte2);
    *b3 = toDecimal(byte3);
    *b4 = toDecimal(byte4);
    
}
void enterNetMask(int* net1, int* net2, int* net3, int* net4)
{
    char* net = (char*) malloc (256 * sizeof(char));
    char* byte1, *byte2, *byte3, *byte4;
    byte1 = (char*) malloc (256 * sizeof(char));
    byte2 = (char*) malloc (256 * sizeof(char));
    byte3 = (char*) malloc (256 * sizeof(char));
    byte4 = (char*) malloc (256 * sizeof(char));
    printf("Enter the netMask address (X.X.X.X):");
    scanf("%s",net);
    getchar();
    sscanf(net, "%[^.].%[^.].%[^.].%[^.]", byte1, byte2, byte3, byte4);
    *net1 = toDecimal(byte1);
    *net2 = toDecimal(byte2);
    *net3 = toDecimal(byte3);
    *net4 = toDecimal(byte4);

}