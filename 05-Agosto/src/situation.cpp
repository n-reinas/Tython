#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void swap(uint64_t *a, uint64_t *b)
{
    uint64_t t = *a;
    *a = *b;
    *b = t;
}

int partition(uint64_t arr[], int low, int high)
{
    uint64_t pivot = arr[high];
    int i = (low - 1);
    for(int j = low; j <= high-1; j++)
    {
        if(arr[j] >= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return(i + 1);
}

void quickSort(uint64_t arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int combinar(uint64_t arr[], uint64_t data[], int start, int end, int index)
{
    if(index == 3)
    {
        if(data[0] + data[1] > data[2])
        {
            if(data[1] + data[2] > data[0])
            {
                if(data[2] + data[0] > data[1])
                {
                    return 1;
                }
            }
        }
    }

    for(int i=start; i<=end && end-i+1 >= 3-index; i++)
    {
        data[index] = arr[i];
        if(combinar(arr, data, i+1, end, index+1))
        {
            return 1;
            break;
        }
        while(arr[i] == arr[i+1])
        {
            i++;
        }
    }
    return 0;
}

int main()
{
    int n;
    uint64_t sticks[20001];
    uint64_t data[3];

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%"SCNu64, &sticks[i]);
    }

    // organizo el array
    quickSort(sticks, 0, n-1);
    if(combinar(sticks, data, 0, n-1, 0))
    {
        printf("possible");
    }
    else
    {
        printf("impossible");
    }
}