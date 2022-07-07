#include<stdio.h>

//INSERTION SORT

void insertionSort(int a[], int size){
    int i,temp,j;
    for(i=1;i<size;i++){
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}


int main() {
    int i,a[]={9,8,3,5,1,4,3,8,7,6,5,4,2};
    int size=sizeof(a)/sizeof(a[0]);
    
    insertionSort(a,size);

    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    return 0;
}