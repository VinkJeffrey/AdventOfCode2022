#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

void Puzzel_dag4_part1(void)
{
    char filename[] = "C:/test/Input/Dag 4.txt";
    char line [1000];
    int totalScore = 0;
    int start1 = 0, eind1 = 0, start2 = 0, eind2 = 0;

    printf("----[ PUZZEL DAG 4 - Part 1 ]---- \n");

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

int count_nonspace(const char* str)
{
 int count = 0;
 while(*str)
 {
  if(!isspace(*str++))
   count++;
 }
 return count;
}

void Puzzel_dag3_part2(void)
{
    char filename[] = "C:/test/Input/Dag 3.txt";
    char line [1000];
    int totalScore = 0;

    int punten = 0;
    int count = 0;
    int line1size = 0;
    int line2size = 0;
    int line3size = 0;
    char line1 [500];
    char line2 [500];
    char line3 [500];
    char test[500];
    char result[5];
    int z = 0;

    char puntenArray[54] = {'0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    printf("----[ PUZZEL DAG 3 - Part 2 ]---- \n");

    FILE *file = fopen ( filename, "r" );

    while(fgets(line,sizeof line,file)!= NULL) /* read a line from a file */
    {
        count++;
        if(count > 3) {
            count = 1;
            z = 0;
        }

        switch(count)
        {
            case 1:
            line1size = count_nonspace(line);
            strncpy(line1, line, line1size);
            break;

            case 2:
            line2size = count_nonspace(line);
            strncpy(line2, line, line2size);
            break;

            case 3:
            line3size = count_nonspace(line);
            strncpy(line3, line, line3size);
            break;

            default:
            printf("FOUT - MAG NIET GEBEUREN \n\n\n");
            break;
        }
        
        if(count == 3)
        {
            // Eerst zoeken welke gelijk zijn bij 1 en 2
            for(int i=0; i<line1size; i++)
            {
                for(int j=0; j<line2size; j++)
                {
                    if(line2[j] == line1[i])
                    {
                        test[z++] = line1[i];
                        j = line2size;
                    }
                }
            }

            // En dan bij 3
            for(int h=0; h<z; h++)
            {
                for(int k=0; k<line3size; k++)
                {
                    if(line3[k] == test[h])
                    {
                        for(int l=0; l<54; l++)
                        {
                            if(test[h] == puntenArray[l])
                            {
                                punten = l;
                                l = 100;
                            }
                        }

                        k = line3size;
                        h = z;
                        totalScore += punten;
                    }
                }
            }
        }
    }

    printf("Total score = %d points \n\n", totalScore);
}

void Puzzel_dag3_part1(void)
{
    char filename[] = "C:/test/Input/Dag 3.txt";
    char line [1000];
    int totalScore = 0;
    int aantalregels = 0;

    char puntenArray[54] = {'0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    printf("----[ PUZZEL DAG 3 - Part 1 ]---- \n");

    FILE *file = fopen ( filename, "r" );

    while(fgets(line,sizeof line,file)!= NULL) /* read a line from a file */
    {
        int count = 0;
        int punten = 0;
        int halfwayPoint = 0;
        bool foundit = false;

        aantalregels++;

        // Aantal letters vinden
        count = count_nonspace(line);  
        halfwayPoint = count / 2;

        for(int i=0; i<halfwayPoint; i++)
        {
            for(int j=halfwayPoint; j<count; j++)
            {
                if(line[j] == line[i])
                {
                    for(int k=0; k<54; k++)
                    {
                        if(line[j] == puntenArray[k])
                        {
                            punten = k;
                            k = 100;
                        }
                    }

                    // Gevonden, dus stoppen
                    i = count;
                    j = halfwayPoint;
                    totalScore += punten;
                }
            }
        }
    }

    printf("Total score = %d points \n\n", totalScore);
}

void Puzzel_dag2_part2(void)
{
    char filename[] = "C:/test/Input/Dag 2.txt";
    char line [1000];
    int totalScore = 0;

    printf("----[ PUZZEL DAG 2 - Part 2 ]---- \n");

    FILE *file = fopen ( filename, "r" );

    while(fgets(line,sizeof line,file)!= NULL) /* read a line from a file */
    {
        char value1, value2;
        int singleRoundPoints = 0;

        sscanf(line, "%c %c", &value1, &value2);

        // First find the type
        if(value1 == 'A')
        {
            printf("Found A (rock)(1) -> ");
            // Add points for loss, draw or win
            if(value2 == 'X')
            {
                printf("Found X (lose) \n");
                // Lose means 0 + scissors(3)
                singleRoundPoints = 3;
            } else if(value2 == 'Y') {
                printf("Found Y (draw) \n");
                // draw means 3 + rock(1)
                singleRoundPoints = 4;
            } else {
                printf("Found Z (win) \n");
                // win means 6 + paper(2)
                singleRoundPoints = 8;
            }

        } else if(value1 == 'B') {
            printf("Found B (paper)(2) -> ");            
            // Add points for loss, draw or win
            if(value2 == 'X')
            {
                printf("Found X (lose) \n");
                // Lose means 0 + rock(1)
                singleRoundPoints = 1;
            } else if(value2 == 'Y') {
                printf("Found Y (draw) \n");
                // draw means 3 + paper(2)
                singleRoundPoints = 5;
            } else {
                printf("Found Z (win) \n");
                // win means 6 + scissors(3)
                singleRoundPoints = 9;
            }
        }
        else {
            printf("Found C (Scissors)(3) -> ");
            // Add points for loss, draw or win
            if(value2 == 'X')
            {
                printf("Found X (lose) \n");
                // Lose means 0 + paper(2)
                singleRoundPoints = 2;
            } else if(value2 == 'Y') {
                printf("Found Y (draw) \n");
                // draw means 3 + scissors(3)
                singleRoundPoints = 6;
            } else {
                printf("Found Z (win) \n");
                // win means 6 + rock(1)
                singleRoundPoints = 7;
            }
        }        

        totalScore += singleRoundPoints;
        printf("Result = %d points \n\n", singleRoundPoints);
    }

    printf("Total score = %d points \n\n", totalScore);
}

void Puzzel_dag2_part1(void)
{
    char filename[] = "C:/test/Input/Dag 2.txt";
    char line [1000];
    int totalScore = 0;

    printf("----[ PUZZEL DAG 2 - Part 1 ]---- \n");

    FILE *file = fopen ( filename, "r" );

    while(fgets(line,sizeof line,file)!= NULL) /* read a line from a file */
    {
        char value1, value2;
        int singleRoundPoints = 0;

        sscanf(line, "%c %c", &value1, &value2);

        // First find the type for the left side of the table
        if(value1 == 'A')
        {
            printf("Found A (rock) -> ");

            if(value2 == 'X')
            {
                printf("Found X (rock). Result is a DRAW \n");
                singleRoundPoints = 4;
            } else if(value2 == 'Y') {
                printf("Found Y (paper). Result is a WIN \n");
                singleRoundPoints = 8;
            } else {
                printf("Found Z (Scissors). Result is a LOSS \n");
                singleRoundPoints = 3;
            }
        } else if(value1 == 'B') {
            printf("Found B (paper) -> ");

            if(value2 == 'X')
            {
                printf("Found X (rock). Result is a LOSS \n");
                singleRoundPoints = 1;
            } else if(value2 == 'Y') {
                printf("Found Y (paper). Result is a DRAW \n");
                singleRoundPoints = 5;
            } else {
                printf("Found Z (Scissors). Result is a WIN \n");
                singleRoundPoints = 9;
            }
        }
        else {
            printf("Found C (Scissors) -> ");

            if(value2 == 'X')
            {
                printf("Found X (rock). Result is a WIN \n");
                singleRoundPoints = 7;
            } else if(value2 == 'Y') {
                printf("Found Y (paper). Result is a LOSS \n");
                singleRoundPoints = 2;
            } else {
                printf("Found Z (Scissors). Result is a DRAW \n");
                singleRoundPoints = 6;
            }
        }

        totalScore += singleRoundPoints;
        printf("Result = %d points \n\n", singleRoundPoints);
    }

    printf("Total score = %d points \n\n", totalScore);
}

void Puzzel_dag1(void)
{
    char filename[] = "C:/test/Input/Dag 1.txt";

    int largestValue1 = 0;
    int largestValue2 = 0;
    int largestValue3 = 0;
    int largestValueTotal = 0;
    int sumOfValue = 0;
    char line [1000];

    printf("----[ PUZZEL DAG 1 ]---- \n");

    for(int i=0; i<2; i++)
    {        
        FILE *file = fopen ( filename, "r" );
        while(fgets(line,sizeof line,file)!= NULL) /* read a line from a file */
        {
            int value = 0;

            sscanf(line, "%d", &value);

            // Increase the sum
            sumOfValue += value;

            if(strcmp(line, "\n") == 0 || strcmp(line,"\r\n") == 0) 
            {
                if(sumOfValue >= largestValue1) {
                    largestValue1 = sumOfValue;
                }
                else if(sumOfValue >= largestValue2) {                        
                    largestValue2 = sumOfValue;
                }
                else if(sumOfValue >= largestValue3) {
                    largestValue3 = sumOfValue;
                }

                // clear the count
                sumOfValue = 0;
            }
        }

        // Run one more time with the last value
        if(sumOfValue >= largestValue1) {
            largestValue1 = sumOfValue;
        }
        else if(sumOfValue >= largestValue2) {                        
            largestValue2 = sumOfValue;
        }
        else if(sumOfValue >= largestValue3) {
            largestValue3 = sumOfValue;
        }

        // clear the count
        sumOfValue = 0;

        fclose(file);
    }

    largestValueTotal = largestValue1 + largestValue2 + largestValue3;

    // print the largest values
    printf("largestValue1 : %d \n", largestValue1); 
    printf("largestValue2 : %d \n", largestValue2); 
    printf("largestValue3 : %d \n", largestValue3);
    printf("largestValueTotal : %d \n", largestValueTotal);  
}