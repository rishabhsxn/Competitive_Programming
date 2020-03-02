#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);


char* dayOfProgrammer(int year) {
    int dayToFind = 256;

    int daysInFeb;
    char *result = (char *) malloc(50*sizeof(char));
    int daysOtherThanFeb = 31 + 31 + 30 + 31 + 30 + 31 + 31; // 215
    int daysBeforeSeptember;

    char monthString[] = ".09."; // answer will always be in September
    char yearString[10];
    sprintf(yearString, "%d", year);

    if(year==1918){
        // printf("inside year==1918\n");
        // days in feb = 15
        daysInFeb = 15;
    }
    else if(year<1918){
        // printf("inside year<1918\n");
        // leap year = divisible by 4
        if(year%4 == 0)
            daysInFeb = 29;
        else
            daysInFeb = 28;
    }
    else{
        // leap year = divisible by 400 or (divisible by 4 but not by 100)
        // printf("inside year>1918\n");
        if(year%400 == 0 || (year%4==0 && year%100 != 0))
            daysInFeb = 29;
        else
            daysInFeb = 28;
    }

    // printf("Days(int) in Feb: %d\n", daysInFeb);

    daysBeforeSeptember = daysInFeb + daysOtherThanFeb;

    // printf("Days before sept(int): %d\n",daysBeforeSeptember);
    int daysInSeptember = dayToFind - daysBeforeSeptember;

    char dayOfSept[10];
    sprintf(dayOfSept, "%d", daysInSeptember);
    // printf("day of sept in String: %s\n",dayOfSept);

    result = strcat(dayOfSept,monthString);

    strcat(result, yearString);

    // printf("Result: %s\n",result);
    
    return result;

}

int main()
{
    int year = 2016;

    char* result = dayOfProgrammer(year);


    printf("Result: %s\n",result);

    return 0;
}