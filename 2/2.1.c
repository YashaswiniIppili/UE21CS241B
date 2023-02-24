/*
Given an array of N integers where each value represents the number of chocolates in a
packet. Each packet can have a variable number of chocolates. There are m students, the
task is to distribute chocolate packets such that:
1. Each student gets one packet.
2. The difference between the number of chocolates in the packet with maximum
chocolates and the packet with minimum chocolates given to the students is
minimal.
Example 1:
Input: arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3
Output: Minimum Difference is 2
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
// arr[0..n-1] represents sizes of packets
// m is number of students.
// Returns minimum difference between maximum
// and minimum values of distribution.
int findMinDiff(int arr[], int n, int m)
{
    if(n>m)
    {
		int i,j,temp; 
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(arr[i]>arr[j])
				{
					temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}
		}
    
		int k=arr[m-1]-arr[0];
    
		for(i=0;i<=(n-m);i++)
    	{
       		int difference = arr[i+m-1]-arr[i];
       		if(difference<k)
    			k = difference;
    	}
    	return k;
    }
	
    else
        return -1;
}

int main()
{
    int a[1000],i,n,m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d",&m);
    printf("Minimum Difference is %d", findMinDiff(a, n, m));
    return 0;
}