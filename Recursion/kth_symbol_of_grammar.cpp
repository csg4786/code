// #include <bits/stdc++.h>
// using namespace std;

// int kthGrammar(int n, int k) {
//     if (n == 1 or k == 1){
//         // cout << n-1 << " " << ceil(n/2) << " " << 0 << "\n";
//         return 0;
//     }
//     else {
//         int temp = kthGrammar(n-1, ceil(k/2.0));
//         // cout << n-1 << " " << ceil(n/2.0) << " " << temp << "\n";
//         return (temp == (k%2)) ? 1 : 0;
//     }
// }

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= pow(2,i-1); j++)
//         {
//             cout << kthGrammar(i, j) << " ";
//             // cout << "i : " << i << " j : " << j << " = " << kthGrammar(i, j) << " ";
//         }
//         cout << endl;
//     }

//     cout << kthGrammar(n,k) << "\n" ;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);     

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}