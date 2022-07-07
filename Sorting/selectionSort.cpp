#include<stdio.h>

//SELECTION SORT

void selectionSort(int a[], int size){
    int i,j,small;
    for(i=0;i<size;i++){
        small=i;
        for(j=i;j<size;j++) {
            if(a[j]<a[small])
            {
                small=j;
            }
        }
        int temp;
        temp=a[i];
        a[i]=a[small];
        a[small]=temp;
    }
}


int main() {
    int i,a[]={9,8,3,5,1,4,3,8,7,6,5,4,2};
    int size=sizeof(a)/sizeof(a[0]);
     
    selectionSort(a,size);
    
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    return 0;
}