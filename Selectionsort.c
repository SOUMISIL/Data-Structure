#include <stdio.h>
#include<stdlib.h>

void SelectionSort(int *A,int n)
{
    int m,temp,i,j;
    for (i=0;i<n;i++)
    {
        m=i;
        for (j=i+1;j<n;j++)
        {
            if(A[j]<A[m])
            {
                m=j;
            }
        }
        temp=A[i];
        A[i]=A[m];
        A[m]=temp;
    }
}

int main() 
{
    int* A;
    int n,i;
    printf("Enter the number of numbers you want to insert: ");
    scanf("%d",&n);
    A=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("\n enter the %d th number: ",i+1);
        scanf("%d",&A[i]);
    }
   
        printf("After sorting: \n");
        SelectionSort(A,n);
        for(i=0;i<n;i++)
        {
            printf("%d\n",A[i]);
        }
    return(0);
}
