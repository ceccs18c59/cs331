#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
    char add[6], length[10], input[10], binary[12], bitmask[12], relocbit;
    int start, inp, len, i, address, opcode, addr, actualadd;
    FILE *file_input, *file_output;
    printf("Enter the actual starting address : ");
    scanf("%d", &start);
    file_input = fopen("relinput.dat", "r");
    file_output = fopen("reloutput.dat", "w");
    fscanf(file_input, "%s", input);
    while (strcmp(input, "E") != 0)
    {
        if (strcmp(input, "H") == 0)
        {
            fscanf(file_input, "%s", add);
            fscanf(file_input, "%s", length);
            fscanf(file_input, "%s", input);
        }
        if (strcmp(input, "T") == 0)
        {
            fscanf(file_input, "%d", &address);
            fscanf(file_input, "%s", bitmask);
            address += start;
            len = strlen(bitmask);
            for (i = 0; i < len; i++)
            {
                fscanf(file_input, "%d", &opcode);
                fscanf(file_input, "%d", &addr);
                relocbit = bitmask[i];
                if (relocbit == '0')
                    actualadd = addr;
                else
                    actualadd = addr + start;
                fprintf(file_output, "%d\t%d%d\n", address, opcode, actualadd);
                address += 3;
            }
            fscanf(file_input, "%s", input);
        }
    }
    fclose(file_input);
    fclose(file_output);
    printf("\n Finished! ");
    getch();
}