#include<iostream>
using namespace std;

void insertSort(int *arr, int len)
{
    for(int i = 0; i < len-1; i++)
    {
        for(int j = i+1; j < len; j++)
        {
            if(arr[i] < arr[j])
            {
                arr[i] ^= arr[j];
                arr[j] ^= arr[i];
                arr[i] ^= arr[j];
            }
        }
    }
    for(int k = 0; k < len; k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {3, 2, 4, 1, 5};
    insertSort(arr, 5);

    return 0;
}