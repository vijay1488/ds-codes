#include<stdio.h>

int main()
{
    //BUBBLE SORT
    int a[10] = {11,4,22,3,44,66,21,9,34,12};
    int n=10,temp,i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>=a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
