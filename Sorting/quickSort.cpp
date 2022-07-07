#include<stdio.h>

//QUICK SORT

int partition(int a[], int start, int end) {
    int pivot=a[end];
    int i=start-1;
    int temp;
    for(int j=start;j<end;j++) {
        if(a[j]<pivot) {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }

    temp=a[i+1];
    a[i+1]=a[end];
    a[end]=temp;
    return i+1;
}

void quickSort(int a[], int start, int end){
    if(start<end) {
        int pi=partition(a,start,end);

        quickSort(a,start,pi-1);
        quickSort(a,pi+1,end);
    }
}

int main() {
    int i,a[]={9,8,3,5,1,4,3,8,7,6,5,4,2};
    int size=sizeof(a)/sizeof(a[0]);

    quickSort(a,0,size-1);

    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    return 0;
}