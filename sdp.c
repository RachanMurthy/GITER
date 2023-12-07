#include <stdio.h>

int main(){
    int per;

    printf("enter percentage : ");
    scanf("%d", &per);

    if(per>75){
        printf("\n1ST");
    }
    else if(per>=60){
        printf("\n2ND");
    }
    else if(per>=30){
        printf("\n3RD");
    }
    else{
        printf("\nFAIL");
    }
}