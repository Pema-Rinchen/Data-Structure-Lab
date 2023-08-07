#include<stdio.h>
//iterative way
int binarySearch(int array[], int l, int h, int x)
{
    while (l <= h) {
        int m = l + (h - l) / 2;
        if (array[m] == x)
            return m;
        if (array[m] < x)
            l = m + 1;
        else
            h = m - 1;
    }
    return -1;
}
int main(){
	int array[5]={1,4,7,9,20};
    int n = sizeof(array) / sizeof(array[0]);
    int x = 4;
    int result=binarySearch(array, 0, n-1,x);
    printf("%d",result);
}
