#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b) {
        int t = *a;
        *a = *b;
        *b = t;
    }
    int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }
    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

void main()
{
	int n,i,j,arr[30];
	printf("\n Enter the number of element\n");
	scanf("%d",&n);

	printf("\n Enter the elements \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n The elements are \n");
        for(i=0;i<n;i++)
	{
                printf("%d\t",arr[i]);
	}
	quickSort(arr,0,n-1);
	printf("\n The elements after sorting is \n");
	for(i=0;i<n;i++)
	{
                printf("%d\t",arr[i]);
	}
}

