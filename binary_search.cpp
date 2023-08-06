#include <bits/stdc++.h>
using namespace std;

int bin_search(vector<int> v, int target)
{

    int start = 0;
    int end = v.size() - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (v[mid] == target){
            return mid;
        }
        else if (v[mid] < target){
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }
    return -1;
}

int upper_bound(vector<int> &arr, int n, int k){
    int s = 0, e = n-1;

    int mid, ans;
    while (s <= e) {
      mid = s + (e - s) / 2;

      if (arr[mid] == k){
          ans = mid;
          s = mid+1;
      } else if (arr[mid] < k){
          s = mid+1;
      } else {
          e = mid-1;
      }
    }

    return ans;
}

int lower_bound(vector<int> &arr, int n, int k){
    int s = 0, e = n-1;

    int mid, ans;
    while (s <= e) {
      mid = s + (e - s) / 2;

      if (arr[mid] == k){
          ans = mid;
          e = mid-1;
      } else if (arr[mid] > k){
          e = mid-1;
      } else {
          s = mid+1;
      }
    }

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (bin_search(v, k) != -1)
        cout << "Index of " << k << " in vector : " << bin_search(v, k) <<"\n";
    else
        cout << "Element not present in vector." << "\n";
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, ans;
//     cin >> n;
//     // ans = (n%4)? ans : ans++;
//     for (int i = 0; i < n + 1; i++)
//     {
//         ans = i - (i / 5);
//         /* code */
//         cout << ans << " ";
//     }

//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// // int bin_sch(int arr[], int start, int end, int k){
// //     while (start <= end)
// //     {
// //         int mid = (end + start)/2;
// //         if (arr[mid] < k){
// //             return bin_sch(arr, mid+1, end, k);
// //         }
// //         if (arr[mid] > k){
// //             return bin_sch(arr, start, mid-1, k);
// //         }
// //         else {
// //             return mid;
// //         }
// //     }
// //     return -1;
// // }

// // int bin_sch(int arr[], int start, int end, int k){
// //     while (start <= end)
// //     {
// //         int mid = (end + start)/2;
// //         if (arr[mid] < k){
// //             return bin_sch(arr, mid+1, end, k);
// //         }
// //         // if (arr[mid] > k){
// //         //     return bin_sch(arr, start, mid-1, k);
// //         // }
// //         else {
// //             return mid;
// //         }
// //     }
// //     return -1;
// // }

// int bin_sch1(int arr[], int start, int end, int k){
//     while (start <= end)
//     {
//         int mid = (end + start)/2;
//         if (arr[mid] >= k){
//             return bin_sch1(arr, start, mid-1, k);
//         }
//         // if (arr[mid] > k){
//         //     return bin_sch(arr, start, mid-1, k);
//         // }
//         else {
//             return mid;
//         }
//     }
//     return -1;
// }

// int bin_sch2(int arr[], int start, int end, int k){
//     while (start <= end)
//     {
//         int mid = (end + start)/2;
//         if (arr[mid] <= k){
//             return bin_sch2(arr, mid+1, end, k);
//         }
//         // if (arr[mid] > k){
//         //     return bin_sch(arr, start, mid-1, k);
//         // }
//         else {
//             return mid;
//         }
//     }
//     return -1;
// }

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     int arr[n];

//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
    
//     cout << arr[bin_sch1(arr, 0, n-1, k)] << " ";
//     cout << arr[bin_sch2(arr, 0, n-1, k)];

//     return 0;
// }