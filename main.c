#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
#include <ctype.h>
#include "main.h"

void main() // Quick run with Ctrl + Alt + N
{
    printf("Code start \n\n");

    //Puzzel_dag1();
    //Puzzel_dag2_part1();
    //Puzzel_dag2_part2();
    
    //Puzzel_dag3_part1();
    //Puzzel_dag3_part2();
    
    //Puzzel_dag4_part1();
    Puzzel_dag4_part2();
}

void Puzzel_dag4_part2(void)
{
    char filename[] = "C:/test/Input/Dag 4.txt";
    char line [1000];
    int totalScore = 0;
    int start1 = 0, eind1 = 0, start2 = 0, eind2 = 0;

    printf("----[ PUZZEL DAG 4 - Part 2 ]---- \n");

    FILE *file = fopen ( filename, "r" );
    while ((fscanf(file, "%d-%d,%d-%d%[^\n]",&start1, &eind1, &start2, &eind2, line))!= EOF)
    {
        int count = 0;
        bool firstValueFound = false;
        bool commaFound = false;
        int array1[150] = {0};
        int array2[150] = {0};
        int lettersLinks = 0;
        int lettersRechts = 0;

        fgetc(file);

        // ALLE START EN STOP WAARDEN ZIJN NU GEVONDEN
        printf("start1 = %d - eind1 = %d , start2 = %d - eind2 = %d \n", start1, eind1, start2, eind2);

        // Mark all numbers as 1
        for(int i=start1; i<=eind1; i++)
        {
            array1[i] = 1;
            lettersLinks++;
        }
        for(int i=start2; i<=eind2; i++)
        {
            array2[i] = 1;
            lettersRechts++;
        }

        bool found = false;
        for(int i=0; i<=100; i++)
        {
            if((array1[i] == 1) || (array2[i] == 1))
            {
                if(array1[i] == array2[i])
                {
                    found = true;
                    if(array1[i] == 1) lettersLinks--;
                    if(array2[i] == 1) lettersRechts--;
                }
                else
                {
                    if(found == true)
                    {
                        if((lettersLinks != 0) && (lettersRechts != 0))
                        {
                            found = false;
                            i = 150;
                        }
                    }
                }
            }
        }

        if(found)
        {
            totalScore++;
        }
    }
    
    fclose(file);
    printf("totalScore : %d \n", totalScore);  
}