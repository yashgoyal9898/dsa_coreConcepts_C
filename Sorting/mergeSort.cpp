#include<stdio.h>

//MERGE SORT

void merging(int a[],int start, int mid, int end) {
    
    int Ls, Rs, k;
	int n1 = mid - start + 1;
	int n2 = end - mid;
   
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (Ls = 0; Ls < n1; Ls++)
		L[Ls] = a[start + Ls];
	for (Rs = 0; Rs < n2; Rs++)
		R[Rs] = a[mid + 1 + Rs];
    
    Ls=0, Rs=0, k=start;

    while (Ls < n1 && Rs < n2) {
		if (L[Ls] <= R[Rs]) {
			a[k] = L[Ls];
			Ls++;
		}
		else {
			a[k] = R[Rs];
			Rs++;
		}
		k++;
	}
   
   /* Copy the remaining elements of L[], if there
	are any */
   while (Ls < n1) {
		a[k] = L[Ls];
		Ls++;
		k++;
	}

    /* Copy the remaining elements of R[], if there
	are any */
	while (Ls < n2) {
		a[k] = R[Rs];
		Rs++;
		k++;
	}

}

void mergeSort(int a[], int start, int end) {
   int mid;
   
   if(start < end) {
      mid = (start + end) / 2;
      mergeSort(a,start, mid);
      mergeSort(a,mid+1, end);
      merging(a,start, mid, end);
   }  
}

int main() {
    int i,a[]={9,8,3,5,1,4,3,8,7,6,5,4,2};
    int size=sizeof(a)/sizeof(a[0]);
   
    mergeSort(a,0,size-1);

    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    return 0;
}