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
char** split_string(char*);

/* Calculate the maximum height to jump from given heights
   if the natural height Dan can jump is greater than or equal to max height
   then the min. no. of doses of potion = 0
   otherwise, subtract the natural height from max height */

   
int hurdleRace(int k, int height_count, int* height)
{
   int max_height=0;
   for(int i=0;i<height_count;i++)
   {
     if( *(height+i) > max_height )
        max_height = *(height+i);
   }

   if( k >= max_height)
      return 0;
   else
   {
     return ( max_height - k);
   }
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nk = split_string(readline());

    char* n_endptr;
    char* n_str = nk[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* k_endptr;
    char* k_str = nk[1];
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

    char** height_temp = split_string(readline());

    int* height = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* height_item_endptr;
        char* height_item_str = *(height_temp + i);
        int height_item = strtol(height_item_str, &height_item_endptr, 10);

        if (height_item_endptr == height_item_str || *height_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(height + i) = height_item;
    }

    int height_count = n;

    int result = hurdleRace(k, height_count, height);

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

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
