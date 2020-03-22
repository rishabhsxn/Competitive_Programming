#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
  To convert int to char use:
     int a=8;
     char c=a+'0';
     printf("%c",c);       //prints 8

  To Convert char to int use:
     char c='5';
     int a=c-'0';
     printf("%d",a);        //prints 5
 */

/*
 * Please either make the string static or allocate on the heap. For example,
 * static char str[] = "hello world";
 * return str;
 *
 * OR
 *
 * char* str = "hello world";
 * return str;
 *
 */
char* timeConversion(char* s)
{
  static char str[8];
  for(int i=2; i<=7; i++)
     str[i] = *(s+i);

  int x = 10*(*(s+0)-'0') + (*(s+1)-'0');
  //printf("x= %d\n",x);
  if(*(s+8)=='P')
  {
    if(x!=12)
      x=x+12;
  }
  else
  {
    if(x==12)
      x=0;
  }

  str[1]=(x%10) + '0';
  str[0]=(x/10) + '0';

  printf("%s\n",str);

  return str;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
