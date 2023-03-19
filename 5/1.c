/*Alice is given an array arr[] of N integers, she is assigned the task to find count of triplets, which have a product less than 0. Write a program to help her achieve this.*/

#include<stdio.h>

int factorial(int n)
{
    int fact = 1;
    for(int i=1; i<=n; i++)
    {
        fact = fact*i;
    }
    return fact;
}

int findTriplets(int* arr, int N)
{
	int negative = 0;
    if(N<3)
        return 0;
    else
    {
        for(int i=0; i<N; i++)
        {
            if(arr[i]<0)
            {
                negative++;
            }
        }

        int positive = N - negative;
        int count = 0;
        count = negative*(factorial(positive)/2*factorial(positive-2));
        count += (negative>=3) ? negative*(negative-1)*(negative-2) : 0;
        return count;
    }
}

// Driver Code
int main()
{
    int arr[100];
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    // Function call
    printf("%d", findTriplets(arr, n));

    return 0;
}

// using for loops and no permutations
/*int findTriplets(int* arr, int N)
{
    int count = 0;
    for(int i=0; i<N-2; i++)
    {
        for(int j=i+1; j<N-1; j++)
        {
            for(int k=j+1; k<N; k++)
            {
                if(arr[i]*arr[j]*arr[k]<0)
                    count++;
            }
        }
    }
    return count;
}*/