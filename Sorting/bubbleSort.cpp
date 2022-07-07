#include<stdio.h>
#include<conio.h>

//BUBBLE SORT

void bubbleSort(int a[], int size) {
    int i,j,temp;
    for(i=0;i<size-1;i++) {
        for(j=0;j<size-i-1;j++) {
            if(a[j]>a[j+1]) {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}


int main() {
    int i,a[]={9,8,3,5,1,4,3,8,7,6,5,4,2};
    int size=sizeof(a)/sizeof(a[0]);
    
    bubbleSort(a,size);
    
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    return 0;
}