#include<stdio.h>
#include<stdlib.h>

void pcm(char []);

int main(){
    int t;

    scanf("%d",&t);
    
    while(t>0){
        char str[4];
        scanf("%s",str);
        // printf("%s\n",str);
        pcm(str);
        t--;
    }

    return 0;
}

void pcm(char str[]){
    // printf("%s\n",str);
    int p=0,c=0,m=0;

    for(int i=0; i<3; i++){
        if(str[i]=='P')
            p = 1;
        else if(str[i]=='C')
            c = 1;
        else if(str[i]=='M')
            m = 1;
    }

    if(p==1 && c==1 && m==1)
        printf("YES");
    else
        printf("NO");
}