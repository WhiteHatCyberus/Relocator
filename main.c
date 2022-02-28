#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char bitmask[12];
char bit[13];

void convert(char h[12])
{
	int i, l;
	strcpy(bit,"");
	l = strlen(h);
	for (i = 0; i < l; i++)
	{
		switch (h[i])
		{
			case '0':
				strcat(bit, "0000");
				break;
			case '1':
				strcat(bit, "0001");
				break;
			case '2':
				strcat(bit, "0010");
				break;
			case '3':
				strcat(bit, "0011");
				break;
			case '4':
				strcat(bit, "0100");
				break;
			case '5':
				strcat(bit, "0101");
				break;
			case '6':
				strcat(bit, "0110");
				break;
			case '7':
				strcat(bit, "0111");
				break;
			case '8':
				strcat(bit, "1000");
				break;
			case '9':
				strcat(bit, "1001");
				break;
			case 'A':
				strcat(bit, "1010");
				break;
			case 'B':
				strcat(bit, "1011");
				break;
			case 'C':
				strcat(bit, "1100");
				break;
			case 'D':
				strcat(bit, "1101");
				break;
			case 'E':
				strcat(bit, "1110");
				break;
			case 'F':
				strcat(bit, "1111");
				break;
		}
	}
}

void main()
{
	printf("Sleety\n");
	char add[6], length[10], input[10], binary[12], addr[10], relocbit, ch, pn[5];
	int flag, start, inp, len, i, address, opcode, actualadd, tlen;
	long int addhex;
    FILE *fp;
	printf("Enter the actual starting address : ");
	scanf("%x", &start);
    printf("\n-------------------------------------------------");
	fp = fopen("input2.txt", "r");
	fscanf(fp, "%s", input);
	while (strcmp(input, "E") != 0)
	{
		if (strcmp(input, "H") == 0)
		{
			fscanf(fp, "%s", pn);
			fscanf(fp, "%x", &add);
			fscanf(fp, "%x", &length);
			fscanf(fp, "%s", input);
		}

		if (strcmp(input, "T") == 0)
		{
			fscanf(fp, "%x", &address);
			fscanf(fp, "%x", &tlen);
			fscanf(fp, "%s", bitmask);
			address += start;
			convert(bitmask);
            flag=0;
			for (i = 0; i < 10; i++)
			{
				fscanf(fp, "%x", &opcode);
				fscanf(fp, "%s", &addr);
                if(addr[strlen(addr)-1]=='$')
                {
                    memcpy(addr,&addr[0],strlen(addr)-1);
                    flag=1;
                }
                addhex = strtol(addr, NULL, 16);
				if (bit[i] == '0')
					actualadd = addhex;
				else
					actualadd = addhex + start;
				printf("\n%x\t%x%x", address, opcode, actualadd);
				address += 3;
                if(flag==1)
                    break;
			}
			fscanf(fp, "%s", input);
		}
	}
fclose(fp);
}
