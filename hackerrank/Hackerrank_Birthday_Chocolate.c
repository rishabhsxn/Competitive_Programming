#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);
int birthday(int, int*, int, int);

// Complete the birthday function below.
// the squares need to be consecutive.
int birthday(int s_count, int* s, int d, int m)
{
  int count =0, sum=0;
  if(m > s_count)
    return 0;

  else if(m == s_count)
  {
    for(int i=0; i<s_count; i++)
       sum += *(s+i);
    //printf("inside else if\nsum = %d\n",sum);

    if(sum == d)
       return 1;
    else
       return 0;
  }

  else
  {
  //  printf("sum = %d\n",sum);
    //printf("Inside else\n");
    for(int i=0; i<= s_count - m ; i++)
    {
      sum=*(s+i);
      for(int k=1 ; k<m; k++)
        sum += *(s+i+k);
    //  printf("Out of inner loop\nsum = %d\n",sum);
      if(sum == d)
        count++;
    }
    //printf("out of outer loop\ncount = %d\n",count);

    return count;
  }


}

int main()
{
    char* n_endptr;
    char* n_str = ltrim(rtrim(readline()));
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** s_temp = split_string(rtrim(readline()));

    int* s = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* s_item_endptr;
        char* s_item_str = *(s_temp + i);
        int s_item = strtol(s_item_str, &s_item_endptr, 10);

        if (s_item_endptr == s_item_str || *s_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(s + i) = s_item;
    }

    int s_count = n;

    char** dm = split_string(rtrim(readline()));

    char* d_endptr;
    char* d_str = dm[0];
    int d = strtol(d_str, &d_endptr, 10);

    if (d_endptr == d_str || *d_endptr != '\0') { exit(EXIT_FAILURE); }

    char* m_endptr;
    char* m_str = dm[1];
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    int result = birthday(s_count, s, d, m);

    printf("%d\n", result);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
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
