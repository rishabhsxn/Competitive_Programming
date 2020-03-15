#include<stdio.h>
#include<stdlib.h>

void sieve(int, int []);
int isPrime(int);

int main(){
    int t;

    scanf("%d",&t);

    while(t>0){
        int size;
        scanf("%d",&size);
        int A[size];
        for(int i=0; i<size; i++)
            scanf("%d",&A[i]);

        sieve(size, A);
        t--;
    }

    // printf("%d\n",isPrime(t));

    return 0;
}


void sieve(int size, int A[]){

    int goodCount = 0;

    for(int i=0 ; i<size-1; i++){
        // printf("%d\n",A[i]);
        for(int j=i+1; j<size; j++){
            if(isPrime(A[i]+A[j]))
                goodCount++;
        }
    }

    printf("%d\n",goodCount);

}


int isPrime(int n){
    int result = 1;
    // int factorCount = 0;
    for(int i=2; i<=n/2; i++){
        if(n%i==0){
            result = 0;
            break;
        }
    }

    return result;
}