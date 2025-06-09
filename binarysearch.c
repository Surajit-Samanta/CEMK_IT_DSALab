#include<stdio.h>

int binarysearch(int arr[],int high, int low,int key)
{
	if(high>=low)
	{
		int mid = low+(high-low)/2;

		if (arr[mid]==key)
			return mid;

		if(arr[mid]>key)
			return binarysearch(arr,low, mid-1,key);
		return binarysearch(arr, mid+1,high,key);
	}
	return -1;
}

int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38};
	int n=sizeof(arr)/sizeof(arr[0]);
	int key =8;
	int result = binarysearch(arr,0,n-1,key);
	(result == -1)? printf("Element is not present in array\n"): printf("Element is present at index %d",result);
	return 0;
}
