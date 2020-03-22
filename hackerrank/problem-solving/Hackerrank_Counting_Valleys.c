#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
/* Take a variable to represent height initially 0, traverse the array, if you
   encounter U, perform height+1, if you encounter D, perform height-1
   Take a variable 'flag' that will indicate whether we are above ground or
   below ground, if height>0..flag=1, if height<0, flag=-1.
   We know we have climbed a valley always when flaag=-1 and height becomes 0
   therefore putting this condition, update the value of count of valleys */
   
int countingValleys(int n, char* s)
{
  int val_count=0,height=0,flag=0;

  for(int i=0; i<n; i++)
  {
    if(*(s+i)=='D')
      height=height-1;
    if(*(s+i)=='U')
      height=height+1;

    if(height>0)
       flag=1;

    else if(height<0)
       flag=-1;

    else if(height==0 && flag==-1)
      val_count++;
  }
  printf("count = %d\n",val_count );

  return val_count;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* s = readline();

    int result = countingValleys(n, s);

    fprintf(fptr, "%d\n", result);

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
