#include <stdio.h>
#define size_array 50


void shift_element(int* arr, int i);

void insertion_sort(int* arr , int len);

int main()
{
    int sortedArray[size_array] = {0};
    for(int i=0;i<size_array;i++)
    {
        int number=scanf("%d", &number);
        *(sortedArray+i)=number;
    }
    insertion_sort(sortedArray,size_array);

    for(int i=0;i<size_array;i++)
    {
        printf("%d%c",*(sortedArray+i),(i == size_array-1 ? '\n':','));
    }
}

void shift_element(int* arr, int i){
    for(int j=i; j>0; j--){
        *(arr+j) = *(arr+(j-1));
    }
}

void insertion_sort(int* arr , int len){
    for(int i=1; i<len; i++)
    {
        int currVal= *(arr+i);
        int counter =0;
        int j = i-1;
        while ((currVal < (*(arr+j))) && (j>=0)){
             counter++;
             j--;
        }
        shift_element((arr+(i-counter)),counter);
        *(arr+(i-counter)) = currVal;
      }
}






