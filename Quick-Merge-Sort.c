#include<stdio.h>
#include<stdlib.h>

void Swap(int *x, int *y);
void quickSort(int a[], int first, int last);
void merge(int arr[], int beg, int mid, int end);
void merge_sort(int arr[], int beg, int end);

int main() 
{
  int a[100], number, i, ch;
  printf("\n Enter the total Number of Elements  :  ");
  scanf("%d", &number);
  printf("\n Enter the Array Elements  :  ");
  for(i = 0; i < number; i++)
    scanf("%d", &a[i]);
  printf("Enter Your Choice : \n 1. Quick Sort \n 2. Merge Sort : \n ");
  scanf("%d", &ch);
  switch(ch)
  {
    case 1:
    quickSort(a, 0, number - 1);
    case 2:
    merge_sort(a, 0, number - 1);
  }
  printf("\n Your Sort Result : ");
  for(i = 0; i < number; i++)  
  {
    printf(" %d ", a[i]);
  }
  printf("\n");
  return 0;
}
// Quick Sort
void Swap(int *x, int *y) 
{
  int Temp;
  Temp = *x;
  *x = *y;
  *y = Temp;
}
void quickSort(int a[], int first, int last) 
{
  int pivot, i, j;
  if(first < last) 
  {
    pivot = first;
    i = first;
    j = last;
    while (i < j) 
    {
      while(a[i] <= a[pivot] && i < last)
        i++;
      while(a[j] > a[pivot])
        j--;
       if(i < j) 
       {
          Swap(&a[i], &a[j]);
       }
    }
    Swap(&a[pivot], &a[j]);
    quickSort(a, first, j - 1);
    quickSort(a, j + 1, last);
  }
}
// Merge Sort
void merge(int arr[], int beg, int mid, int end) 
{
  int i = beg, j = mid + 1, index = beg, temp[100], k;
  while ((i <= mid) && (j <= end)) 
  {
    if (arr[i] < arr[j]) 
    {
      temp[index] = arr[i];
      i++;
    } else 
    {
      temp[index] = arr[j];
      j++;
    }
    index++;
  }
  if (i > mid) 
  {
    while (j <= end) 
    {
      temp[index] = arr[j];
      j++;
      index++;
    }
  } else 
  {
    while (i <= mid) 
    {
      temp[index] = arr[i];
      i++;
      index++;
    }
  }
  for (k = beg; k < index; k++)
    arr[k] = temp[k];
}
void merge_sort(int arr[], int beg, int end) 
{
  int mid;
  if (beg < end) 
  {
    mid = (beg + end) / 2;
    merge_sort(arr, beg, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, beg, mid, end);
  }
}