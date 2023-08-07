#include<stdio.h>
void insertion(int arr[],int size){
	int i,j,key;
	for (i=1;i<size;i++){
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key){
		arr[j+1]=arr[j];
		j--;
		}
		arr[j+1]=key;
	}
}
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    insertion(arr,size);
    printf("\nSorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
