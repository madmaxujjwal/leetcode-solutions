// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

void sort012(int a[], int n)
{
    int z=0;int o=0;int t=0;
    for(int i=0;i<n;i++){
        if(a[i]==0)
        z++;
        else if(a[i]==1)
        o++;
        else
        t++;
    }
    for(int i=0;i<z;i++){
        a[i]=0;
    }
    for(int i=z;i<z+o;i++)
       a[i]=1;
    for(int i=z+o;i<z+o+t;i++)
      a[i]=2;
      
}

// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends