#include <stdio.h>

int getTotalX(int, int *, int, int *);


int main()
{
    int a_count=0, b_count=0;

    scanf("%d %d",&a_count,&b_count);

    int a[a_count], b[b_count];
    for(int i =0;i<a_count;i++)
       scanf("%d",&a[i]);

    for(int i=0; i<b_count;i++)
       scanf("%d",&b[i]);

    int total = getTotalX (a_count, a, b_count, b);

    printf("%d\n", total);
    return 0;
}


int getTotalX(int a_count, int* a, int b_count, int* b)
{
  int lb = *(a + a_count - 1);
  int ub = *(b+0);
  int count =0,flag1=0,flag2=0;

  for(int i = lb ; i<=ub ; i++)
  {
    flag1=0;
    flag2=0;
    for(int j =0; j<a_count ; j++)
    {
      if(i % *(a+j) != 0)
      {
        flag1=1;
        break;
      }
    }

    for(int k =0; k< b_count ; k++)
    {
      if(*(b+k) % i != 0)
      {
        flag2 = 1;
        break;
      }
    }

    if(flag1==0 && flag2==0)
      count++;
  }
  return count;

}
