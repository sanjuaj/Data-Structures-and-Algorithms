#include<stdio.h>

//Insertion Sort

void main(){
    int len, a[100];
    printf("Enter the number of elements to be sorted (less than 100) :-");
    scanf("%d",&len);
    for (int i=0; i<len; i++){
        printf("Enter the element:-");
        scanf("%d",&a[i]);
    }
    if (len>1){
        int i,key;
        for(int j=1; j<len; j++){
            key=a[j];
            i=j-1;
            while (!(i<0) && a[i]>key){
                a[i+1]=a[i];
                i--;
            }
            a[i+1]=key;
        }
    }
    for (int i=0; i<len; i++){
        printf("%d \n",a[i]);
    }
}
