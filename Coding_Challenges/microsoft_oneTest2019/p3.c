#include<stdio.h>
#include<math.h>
#include<string.h>

void main(){
  int nodes;
  printf("Enter node: ");
  scanf("%d",&nodes);

  double result = log(nodes+1)/log(2);
  int intResult = (int)result;
  printf("min depth: %d\n\n",intResult);

}