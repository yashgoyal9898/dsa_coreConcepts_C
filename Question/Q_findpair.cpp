#include<stdio.h>
#include<string.h>
bool abc(){
    int a[]={2,1,3};
    int b[]={7,8,9};
    int k=10,sum=0;

    int i,j;

    for(i=0;i<5;i++) 
    {
        for(j=0;j<5;j++){  
            sum=a[i]+b[j];
            if(sum>=k);
            return true;}
    }    
    return false;    
}

int main()
{
    char s;
   printf("%s", abc());
}