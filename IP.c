#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int choice ;
    do{
    printf("enter you're choice:\n");
    printf("1: converting binary to decimal\n");
    printf ("2: directly enter a decimal number\n");
    printf ("3: enter an hexadecimal number\n");
    scanf ("%d",&choice);
    getchar();  //remove the \n when pressing the enter key
    }while(choice < 1 || choice > 3);

    if (choice == 2)
    {
        int head1, head2, head3, head4;
        printf("Enter the first Byte of the IP:");
        scanf("%d",&head1);
        getchar();

        printf("Enter the second Byte of the IP:");
        scanf("%d",&head2);
        getchar();

        printf("Enter the third Byte of the IP:");
        scanf("%d",&head3);
        getchar();

        printf("Enter the fourth Byte of the IP:");
        scanf("%d",&head4);
        getchar();

        if ( head1 > 255 || head2 > 255 || head3 > 255 || head4 > 255)
                printf("The adreses IP :%d.%d.%d.%d is not a valable IP\n",head1, head2,head3, head4);
        else
        {
            if ( head1 >= 0 && head1 < 128)
                printf("The adreses IP :%d.%d.%d.%d is valable and is class A\n",head1, head2,head3, head4);
            if ( head1 >= 128 && head1 < 192)
                printf("The adreses IP :%d.%d.%d.%d is valable and is class B\n",head1, head2,head3, head4);
            if ( head1 >= 192 && head1 < 224)
                printf("The adreses IP :%d.%d.%d.%d is valable and is class C\n",head1, head2,head3, head4);
            if ( head1 >= 224 && head1 < 240)
                printf("The adreses IP :%d.%d.%d.%d is valable and is class D\n",head1, head2,head3, head4);
            if ( head1 >= 240 && head1 < 256)
                printf("The adreses IP :%d.%d.%d.%d is valable and is class A\ns",head1, head2,head3, head4);
            
        } 
            

    }   
    if (choice == 1)
    {
        int i, j, k;
        int l;
        long fstByte, scdByte, thrByte, frthByte;
        char* byte1 = (char*) malloc (16 * sizeof(char));
        char* byte2 = (char*) malloc (16 * sizeof(char));
        char* byte3 = (char*) malloc (16 * sizeof(char));
        char* byte4 = (char*) malloc (16 * sizeof(char));

        do 
        {
            printf("Enter the first 8 BINARY of the IP:");
            scanf("%s",byte1);
            getchar();
        }while (strlen(byte1) > 9 || strlen(byte1) < 8);

        do 
        {
            printf("Enter the second 8 BINARY of the IP:");
            scanf("%s",byte2);
            getchar();
        }while (strlen(byte2) > 9 || strlen(byte2) < 8);

        do 
        {
            printf("Enter the third 8 BINARY of the IP:");
            scanf("%s",byte3);
            getchar();
        }while (strlen(byte3) > 9 || strlen(byte3) < 8);

        do 
        {
            printf("Enter the fourth 8 BINARY of the IP:");
            scanf("%s",byte4);
            getchar();
        }while (strlen(byte4) > 9 || strlen(byte4) < 8);

        if (strlen(byte1) > 9 || strlen(byte2) > 9 ||
            strlen(byte3) > 9 || strlen(byte4) > 9 )
            printf("there's a binary that surpass 8 charactere\n");
        
        fstByte = strtol (byte1, NULL, 2);
        scdByte = strtol (byte2, NULL, 2);
        thrByte = strtol (byte3, NULL, 2);
        frthByte = strtol (byte4, NULL, 2);
        printf("%ld.%ld.%ld.%ld\n", fstByte, scdByte, thrByte, frthByte);

    } 
    if (choice == 3)
    {
        int i, j, k;
        int l,m;
        long head1, head2, head3, head4;
        char* byte1 = (char*) malloc (16 * sizeof(char));
        char* byte2 = (char*) malloc (16 * sizeof(char));
        char* byte3 = (char*) malloc (16 * sizeof(char));
        char* byte4 = (char*) malloc (16 * sizeof(char));

        do 
        {
            printf("Enter the first value of the IP(hexadecima):");
            scanf("%s",byte1);
            getchar();
        }while (strlen(byte1) > 3 || strlen(byte1) < 2);

        do 
        {
            printf("Enter the second value of the IP(hexadecima):");
            scanf("%s",byte2);
            getchar();
        }while (strlen(byte2) > 3|| strlen(byte2) < 2);

        do 
        {
            printf("Enter the third value of the IP(hexadecima):");
            scanf("%s",byte3);
            getchar();
        }while (strlen(byte3) > 3 || strlen(byte3) < 2);

        do 
        {
            printf("Enter the fourth value of the IP(hexadecima):");
            scanf("%s",byte4);
            getchar();
        }while (strlen(byte4) > 3 || strlen(byte4) < 2);

        if (strlen(byte1) > 9 || strlen(byte2) > 9 ||
            strlen(byte3) > 9 || strlen(byte4) > 9 )
        {
            printf("there's a binary that surpass 8 charactere\n");
        }
        for (i = 0; i < (strlen(byte1)); i++)
        {
            if (byte1[i] >='a' && (byte1[i] <='f'))
                byte1[i] = toupper(byte1[i]);


            if (byte2[i] >='a' && (byte2[i] <='f'))
                byte2[i] = toupper(byte2[i]);


            if (byte3[i] >='a' && (byte3[i] <='f'))
                byte3[i] = toupper(byte3[i]);


            if (byte4[i] >='a' && (byte4[i] <='f'))
                byte4[i] = toupper(byte4[i]);
        }
        for ( j = 0; j < strlen(byte1); j++)
        {
            if (byte1[j] <= 'z' && (byte1[j] >= 'g') || (byte1[j] < '0') && (byte1[j] >'9'))
                printf("%s is not an hexadecimal\n",byte1);
            break;
        }
        for ( k = 0; k < strlen(byte1); k++)
        {
            if (byte2[k] <= 'z' && (byte2[k] >= 'g') || (byte2[k] < '0') && (byte2[k] >'9'))
                printf("%s is not an hexadecimal\n",byte2);
            break;
        }
        for ( l = 0; l < strlen(byte1); l++)
        {
            if (byte3[l] <= 'z' && (byte1[l] >= 'g') || (byte3[l] < '0') && (byte3[l] >'9')) 
                printf("%s is not an hexadecimal\n",byte3);
            break;
        }
        for ( m = 0; m < strlen(byte1); m++)
        {
            if (byte4[m] <= 'z' && (byte4[m] >= 'g') || (byte4[m] <'0') && (byte4[m] >'9'))
                printf("%s is not an hexadecimal\n",byte4);
            break;
        }

        head1 = strtol (byte1, NULL, 16);
        head2 = strtol (byte2, NULL, 16);
        head3 = strtol (byte3, NULL, 16);
        head4 = strtol (byte4, NULL, 16);
        if ( head1 > 255 || head2 > 255 || head3 > 255 || head4 > 255)
                printf("The adreses IP :%ld.%ld.%ld.%ld is not a valable IP\n",head1, head2,head3, head4);
        else
        {
            if ( head1 >= 0 && head1 < 128)
                printf("The adreses IP :%ld.%ld.%ld.%ld is valable and is class A\n",head1, head2,head3, head4);
            if ( head1 >= 128 && head1 < 192)
                printf("The adreses IP :%ld.%ld.%ld.%ld is valable and is class B\n",head1, head2,head3, head4);
            if ( head1 >= 192 && head1 < 224)
                printf("The adreses IP :%ld.%ld.%ld.%ld is valable and is class C\n",head1, head2,head3, head4);
            if ( head1 >= 224 && head1 < 240)
                printf("The adreses IP :%ld.%ld.%ld.%ld is valable and is class D\n",head1, head2,head3, head4);
            if ( head1 >= 240 && head1 < 256)
                printf("The adreses IP :%ld.%ld.%ld.%ld is valable and is class A\ns",head1, head2,head3, head4);
            
        }
    }

    return (0);
}