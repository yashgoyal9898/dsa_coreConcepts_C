#include<stdio.h>
#include<conio.h>
#include<limits.h>

// int subarray(int a[]){
//     int sumTillNow=0,maxSum=INT_MIN;
//     for(int i=0;i<5;i++){
//         sumTillNow=sumTillNow+a[i];
//         if(sumTillNow>maxSum){
//             maxSum=sumTillNow;
//         }
//         if(sumTillNow<0){
//             sumTillNow=0;
//         }
//     }
//     return maxSum;
// }

//contains duplicate
// bool checkDuplicatesWithinK(int arr[], int n, int k)
// {
 
//     // traversing the input array
//     for (int i = 0; i < 5; i++) {
//         int j = i + 1;
//         int range = k;
//         // searching in next k-1 elements if its duplicate
//         // is present or not
//         while (range > 0 && j < 5) {
//             if (arr[i] == arr[j])
//                 return true;
//             j++;
//             range--;
//         }
//     }
//     return false;
// }
void bubbleSort(int *a, int size) {
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
void chochalateDistribution(int *a, int m, int size){
    int i,min=__INT_MAX__;
    for(i=0 ; i+m-1<size ; i++) {

        int diff=a[i+m-1]-a[i];
        
        if(diff<min){
            min=diff;
        }

    }
    printf("\nDifference %d",min);
}

void main() {
    int i,a[]={3,4,1,9,56,7,9,12};
    int size=sizeof(a)/sizeof(a[0]);
    
    bubbleSort(a,size);

    //sort(a.begin(),a.end());  //sort in gfg

    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    chochalateDistribution(a,5,size);
}