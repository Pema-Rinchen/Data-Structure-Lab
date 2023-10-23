#include<stdio.h>
//binary search with recursion
int binarysearch(int array[],int l,int h,int  key){
	while(l<=h)
	{
		int mid=(l+h)/2;
		if(array[mid]==key)
			return mid;
		 else if(array[mid]>key)
		 	return binarysearch(array, 0, mid-1,key);
		else 
		 	return binarysearch(array, mid+1, h,key);
		 
	}
	return -1;
}
int main()
{
	int array[5]={3,4,10,12,40};
    int n = 3;
    int key = 10;
    int result=binarysearch(array, 0, 4,key);
    if (result==-1)
    	printf("key is not found");
    else
    	printf("%d is in %d index",key,result);
    return 0; 
}
