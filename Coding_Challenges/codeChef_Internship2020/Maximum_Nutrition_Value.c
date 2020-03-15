#include<stdio.h>
#include<stdio.h>

int max(int, int);
void maxNutrition(int, int [], int [], int);


int main() 
{ 
    int t;
    scanf("%d",&t);


    while(t>0){
        int N, W, X, Y;
        scanf("%d",&N);scanf("%d",&W);scanf("%d",&X);scanf("%d",&Y);

        int w[N];
        int n[N];

        for(int i=0; i<N; i++)
            scanf("%d",&w[i]);

        for(int i=0; i<N; i++)
            scanf("%d",&n[i]);

        int firstMaxNutri = n[0], secondMaxNutri = 0;
        int fIndex = 0, sIndex;

        for(int i=1; i<N; i++){
            if(n[i]>firstMaxNutri){
                secondMaxNutri = firstMaxNutri;
                sIndex = fIndex;
                firstMaxNutri = n[i];
                fIndex = i;
            }
            else if(n[i] > secondMaxNutri){
                secondMaxNutri = n[i];
                sIndex = i;
            }
        }

        // printf("highest index: %d\n", fIndex);
        // printf("second highest index: %d\n", sIndex);

        if(X>Y){
            // printf("X is greater\n");
            n[fIndex] *= X;
            n[sIndex] *= Y;
        }
        else{
            // printf("Y is greater\n");
            n[fIndex] *= Y;
            n[sIndex] *= X;
        }

        maxNutrition(W, w, n, N);

        t--;
    }
    
    return 0; 
}


int max(int a, int b){ 
    return (a > b)? a : b; 
} 


void maxNutrition(int W, int w[], int n[], int N) 
{ 
   int i; 
   int K[N+1][W+1]; 
  
   for (i = 0; i <= N; i++) 
   { 
       for (int j = 0; j <= W; j++) 
       { 
            if (i==0 || j==0) 
                K[i][j] = 0; 
            else if (w[i-1] <= j) 
                K[i][j] = max(n[i-1] + K[i-1][j-w[i-1]],  K[i-1][j]); 
            else
                K[i][j] = K[i-1][j]; 
       } 
   } 
  
   printf("%d\n",K[N][W]); 
} 