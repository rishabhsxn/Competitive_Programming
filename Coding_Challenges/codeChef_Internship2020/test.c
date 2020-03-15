#include<stdio.h>

void main(){
    int n[] = {10, 3 ,1, 5 , 9 , 2 , 8};
    int N = 7;
    int firstMaxNutri = n[0], secondMaxNutri = 0;

    for(int i=1; i<N; i++){
        if(n[i]>firstMaxNutri){
            secondMaxNutri = firstMaxNutri;
            firstMaxNutri = n[i];
        }
        else if(n[i] > secondMaxNutri){
            secondMaxNutri = n[i];
        }
    }

    printf("1st: %d\n", firstMaxNutri);
    printf("2nd: %d\n",secondMaxNutri);
}