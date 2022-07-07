#include <stdio.h>  
  
//COUNT SORT 

//RETURN MAXIMUM ELEMENT from ARRAY
int getMax(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max;   
}  
  
void countSort(int a[], int n) {  

   int output[n];  
   int max = getMax(a, n);  
   int count[max]; //create count array with size [max+1]  
  
   //Initialize COUNT ARRay With 0
   for (int i = 0; i <= max; ++i) {
      count[i] = 0; // 
  }  
    
   // Store the count of each element  
   for (int i = 0; i < n; i++) {  
      count[a[i]]++;  
  }  

   //find cumulative frequency
   for(int i = 1; i<=max; i++)   
      count[i] += count[i-1];   
  
   //PLACE elements in ouptput ARRAY  
   for (int i = n - 1; i >= 0; i--)   
      output[--count[a[i]]] = a[i];    
  
   //store the sorted elements into main array
   //a=output
   for(int i = 0; i<n; i++) {  
      a[i] = output[i];   
   }  
}  
  
  
  
int main() {  
    int i,a[]={9,8,3,5,1,4,3,8,7,6,5,4,2};
    int size=sizeof(a)/sizeof(a[0]);  

    printf("Before sorting array elements are - \n");  
     for (i = 0; i < size; i++)  
        printf("%d ",a[i]);  

    countSort(a, size);  

    printf("\nAfter sorting array elements are - \n");  
    for (i = 0; i < size; i++)  
        printf("%d ",a[i]);  

    return 0;  
}  