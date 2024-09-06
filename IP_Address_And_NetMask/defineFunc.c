#include "headers.h"

void start()
{
    int byte1, byte2, byte3, byte4;
    int net1, net2, net3, net4;
    char ipClass;
    char* netMask1 = (char*) malloc (256 * sizeof(char));
    int check;
    int subNet1,subNet2,subNet3,subNet4;
    int broadCast1, broadCast2, broadCast3, broadCast4;
    int netMask0;
    int zeroCount, number_PC;

    enterCIDR(&byte1, &byte2, &byte3, &byte4, &netMask0);
    netMask1 = convertNetMask(netMask0);
    netMaskToAddress(netMask1, &net1, &net2, &net3, &net4);
    printf("The netMask address is :%d.%d.%d.%d\n", net1, net2, net3, net4);
    ipClass = checkIpClass(byte1, byte2, byte3, byte4);
        subNet1 = byte1 & net1;
        subNet2 = byte2 & net2;
        subNet3 = byte3 & net3;
        subNet4 = byte4 & net4;
        printf("The netWork address of IP:%d.%d.%d.%d with\n",byte1, byte2, byte3, byte4);
        printf("\tsubnet value of :%d.%d.%d.%d \n",net1, net2, net3, net4);
        printf("\t\tis %d.%d.%d.%d\n", subNet1, subNet2, subNet3, subNet4);

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
        printf("The broadCast Address is:%d.%d.%d.%d\n", broadCast1, broadCast2,broadCast3, broadCast4);


        // we re-use the netMaskToAddress in the detNumOfMaxPC
       number_PC = detNumOfMaxPC(broadCast1,broadCast2, broadCast3, broadCast4, subNet1 ,subNet2, subNet3, subNet4);
       printf("The number of max PC for each subNet(sous-rÃ©seau) is %d\n\n", number_PC);


       divide(byte1, byte2, byte3, byte4, netMask0);
}
char* convertNetMask(int netMask)
{
    int i;

    char* tmpNetMask = (char*) malloc (256 * sizeof(char));
    
    
    for (i = 0; i < netMask; i++)
    {
        tmpNetMask[i] = '1';
    }
    for (; i < 32; i++)             //no initialisation cause the value of i is the value 
    {                               //from the above code
        tmpNetMask[i] = '0';
    }

    return (tmpNetMask);
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
    }
    return (class);
}
int toDecimal(char* byte, int base)
{
    return (strtol(byte, NULL, base));
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
int detNumOfMaxPC (int b1, int b2, int b3, int b4, int sub1, int sub2, int sub3, int sub4)
{
    int number_PC;
    int mult1, mult2, mult3, mult4;

    int net1, net2, net3, net4;
    net1 = b1 - sub1;               //you can just the formula : 
    net2 = b2 - sub2;                       //2^(32 - num of netmask[the value after "/"]) - 2
    net3 = b3 - sub3;
    net4 = b4 - sub4;

    mult1 = net1 + 1;
    mult2 = net2 + 1;
    mult3 = net3 + 1;
    mult4 = net4 + 1;
    number_PC = (mult1 * mult2 * mult3 * mult4) - 2;  
    return (number_PC);
}
void enterCIDR(int* b1, int* b2, int* b3, int* b4, int* number_of_1_bit)
{
    char* ip = (char*) malloc (256 * sizeof(char));
    char* byte1, *byte2, *byte3, *byte4;
    char* tmp_of_1_bit;

    byte1 = (char*) malloc (256 * sizeof(char));
    byte2 = (char*) malloc (256 * sizeof(char));
    byte3 = (char*) malloc (256 * sizeof(char));
    byte4 = (char*) malloc (256 * sizeof(char));
    tmp_of_1_bit = (char*) malloc (256 * sizeof(char));

    printf("Enter the IP address and the number of bit s one:\n");
    printf("Example: 192.29.168.230/25:\n\t:");
    scanf("%s",ip);
    getchar();
    sscanf(ip, "%[^.].%[^.].%[^.].%[^/]/%[^.]", byte1, byte2, byte3, byte4, tmp_of_1_bit);
    *b1 = toDecimal(byte1, 10);
    *b2 = toDecimal(byte2, 10);
    *b3 = toDecimal(byte3, 10);
    *b4 = toDecimal(byte4, 10);
    *number_of_1_bit = toDecimal(tmp_of_1_bit, 10);

}
void netMaskToAddress(char* tmpNetMask,int* b1, int* b2, int* b3, int* b4)
{
    char* byte1, *byte2, *byte3, *byte4;
    byte1 = (char*) malloc (256 * sizeof(char));
    byte2 = (char*) malloc (256 * sizeof(char));
    byte3 = (char*) malloc (256 * sizeof(char));
    byte4 = (char*) malloc (256 * sizeof(char));

    strncpy (byte1, tmpNetMask, 8);         //copy from 0 to 7th character
    strncpy (byte2, tmpNetMask + 8, 8);     //copy from 8th to (8 + 8) - 1
    strncpy (byte3, tmpNetMask + 16, 8);    // copy from 16th to (16 + 8) - 1
    strncpy (byte4, tmpNetMask + 24, 8);
    *b1 = toDecimal(byte1,2);
    *b2 = toDecimal(byte2,2);
    *b3 = toDecimal(byte3,2);
    *b4 = toDecimal(byte4,2);
}
void divide(int byte1, int byte2, int byte3,int byte4, int netMask)
{
    int i,n, newNetMask;
    int net1, net2, net3, net4;
    char ipClass;
    int check, numOfSubNet;
    int subNet1,subNet2,subNet3,subNet4;
    int broadCast1, broadCast2, broadCast3, broadCast4;
    int zeroCount, number_PC, temp_num_PC;
    int remainder, binaryCount;
    int number_of_subNet, nTh_Subnet;
    do
    {
        printf("How far  are you going to divide? Make sure that the netMask");
        printf(" doesn't surpass 32\n\t--->");
        scanf("%d",&n);
        getchar();
        newNetMask = netMask + n;
    } while (newNetMask > 33);

    char* tmpNetMask = (char*) malloc (256 * sizeof(char));
    tmpNetMask = convertNetMask(newNetMask);
    netMaskToAddress(tmpNetMask, &net1, &net2, &net3, &net4);
    
    printf("The netMask address is :%d.%d.%d.%d\n", net1, net2, net3, net4);
    ipClass = checkIpClass(byte1, byte2, byte3, byte4);
        subNet1 = byte1 & net1;
        subNet2 = byte2 & net2;
        subNet3 = byte3 & net3;
        subNet4 = byte4 & net4;
        printf("The netWork address of IP:%d.%d.%d.%d with\n",byte1, byte2, byte3, byte4);
        printf("\tsubnet value of: %d.%d.%d.%d ",net1, net2, net3, net4);
        printf("\n\t\tis %d.%d.%d.%d\n", subNet1, subNet2, subNet3, subNet4);

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
        printf("\nThe broadCast Address is:%d.%d.%d.%d\n", broadCast1, broadCast2,broadCast3, broadCast4);


    switch (ipClass)
    {
        case 'A':  switch (net1)
        {
                        case 128:
                                numOfSubNet = 1 + n;
                            break;
                        case 192:
                                numOfSubNet = 2 + n;
                            break;
                        case 224: 
                                numOfSubNet = 3 + n;
                            break;
                        case 240:
                                numOfSubNet = 4 + n;
                            break;
                        case 248:
                                numOfSubNet = 5 + n;
                            break;
                        case 252:
                                numOfSubNet = 6 + n;
                            break;
                        case 254:
                                numOfSubNet = 7 + n;
                            break;
                        case 255:
                                numOfSubNet = 8 + n;
                            break;

                        default:    numOfSubNet = 0;
                            break;
        }
            break;
        case 'B':  switch (net2)
        {
                        case 128:
                                numOfSubNet = 1 + n + 8;
                            break;
                        case 192:
                                numOfSubNet = 2 + n + 8;
                            break;
                        case 224: 
                                numOfSubNet = 3 + n + 8;
                            break;
                        case 240:
                                numOfSubNet = 4 + n + 8;
                            break;
                        case 248:
                                numOfSubNet = 5 + n + 8;
                            break;
                        case 252:
                                numOfSubNet = 6 + n + 8;
                            break;
                        case 254:
                                numOfSubNet = 7 + n + 8;
                            break;
                        case 255:
                                numOfSubNet = 8 + n + 8;
                            break;

                        default:    numOfSubNet = 0;
                            break;
        }
            break;
        case 'C':   switch (net3)
        {
                        case 128:
                                numOfSubNet = 1 + n + 16;
                            break;
                        case 192:
                                numOfSubNet = 2 + n + 16;
                            break;
                        case 224: 
                                numOfSubNet = 3 + n + 16;
                            break;
                        case 240:
                                numOfSubNet = 4 + n + 16;
                            break;
                        case 248:
                                numOfSubNet = 5 + n + 16;
                            break;
                        case 252:
                                numOfSubNet = 6 + n + 16;
                            break;
                        case 254:
                                numOfSubNet = 7 + n + 16;
                            break;
                        case 255:
                                numOfSubNet = 8 + n + 16;
                            break;

                        default:    numOfSubNet = 0;
                            break;
        }
            break;
        default:    numOfSubNet = 0;
            break;
    }
    binaryCount = 0;
    while (numOfSubNet != 0)
    {
        remainder = numOfSubNet % 2;
        binaryCount++;
        numOfSubNet /= 2;
    }
    number_of_subNet = 1;

    for (i = 0; i < binaryCount ; i++)
    {
        number_of_subNet = number_of_subNet * 2;
    }

    number_PC = detNumOfMaxPC(broadCast1,broadCast2, broadCast3, broadCast4, subNet1 ,subNet2, subNet3, subNet4);

    printf("\n The IP address %d.%d.%d.%d\n",byte1, byte2, byte3, byte4);
    printf("will be divide further by %d \n",n);
    printf("\t\t\tthen the number of subNet(sous-rÃ©seau) is %d\n",number_of_subNet);
    printf("with %d as maximum PC for each subNet\n",number_PC);

    nTh_Subnet = 0;
    temp_num_PC = number_PC;
    printf("All interval of each subnet:\n");
    printf ("\t[%d.%d.%d.%d] -->\t", subNet1, subNet2, subNet3, subNet4);
    while ( nTh_Subnet < number_of_subNet)
    {
        if (nTh_Subnet >= 1)
            printf ("\t[%d.%d.%d.%d] -->\t", subNet1, subNet2, subNet3, subNet4);
        subNet4 += temp_num_PC;
        while (subNet4 >= 255)
        {
            subNet3++;
            subNet4 -= 256;
        }
        while (subNet3 >= 255)
        {
            subNet2++;
            subNet3 -= 256;
        }
        while (subNet2 >= 255)
        {
            subNet1++;
            subNet2 -= 256;
        }
        nTh_Subnet++;
        subNet4++;
        printf("[%d.%d.%d.%d]\n", subNet1, subNet2, subNet3, subNet4);
        subNet4++;
    }
}
