// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int a, b, c;
//     cin >> a >> b >> c;
//     cout << (a ^ b ^ c) << "\n";
//     return 0;
// }


/*
Q1. A mobile selling outlet sells various types of mobiles. However, her shop is very small and can contain only 40 items, in total.
Mobile
Count
Profit
Redme Note 9
10
20000
Samsung Galaxy M12
5
10500
OnePlus 5
26
89000
Realme Narzo 20 Pro
4000
Xiaomi Poco M3
12
23000
Present a greedy approach to solve this.
Q2. Each of the states is divided into many districts for administrative reasons. These districts have many neighbors that share their borders. If we want to colour each of the districts is such a manner that adjoint districts (districts that share border) cannot be coloured with the same colour, perform for the any map. (3 Marks)

Q3.
There are n people who want to get to the top of a building which has only one elevator. You know the weight of each person and the maximum allowed weight in the elevator. What is the minimum number of elevator rides? (4 Marks)

Input:
The first input line has two integers' n and x:
the number of people and the maximum allowed weight in the elevator. The second line has n integers w1, w2,..., wn:
the weight of each person.
Output:
Print one integer: the minimum number of rides.
Example:
Input:
4 10
4 8 6 1
Output:
2
*/

// #include <bits/stdc++.h>

// using namespace std;

// int min_elevator_rides(vector<int> weights, int max_weight)
// {
//     sort(weights.begin(), weights.end(), greater<int>());
//     int rides = 0;
//     int i = 0;
//     while (i < weights.size())
//     {
//         int curr_weight = 0;
//         while (i < weights.size() && curr_weight + weights[i] <= max_weight)
//         {
//             curr_weight += weights[i];
//             i++;
//         }
//         rides++;
//     }
//     return rides;
// }

// int main()
// {
//     int n, max_weight;
//     cin >> n >> max_weight;
//     vector<int> weights(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> weights[i];
//     }
//     int min_rides = min_elevator_rides(weights, max_weight);
//     cout << min_rides << endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int min_elevator_rides(vector<int> weights, int max_weight)
// {
//     sort(weights.begin(), weights.end());
//     int rides = 0;
//     int i = 0, j = weights.size() - 1;
//     while (i <= j)
//     {
//         if (weights[i] + weights[j] <= max_weight)
//         {
//             i++;
//         }
//         j--;
//         rides++;
//     }
//     return rides;
// }

// int main()
// {
//     int n, max_weight;
//     cin >> n >> max_weight;
//     vector<int> weights(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> weights[i];
//     }
//     int min_rides = min_elevator_rides(weights, max_weight);
//     cout << min_rides << endl;
//     return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;

// vector<string> map_coloring(vector<vector<int>> adj_list)
// {
//     int n = adj_list.size();
//     vector<string> colors = {"Red", "Green", "Blue", "Yellow", "Orange", "Purple"};
//     vector<string> colored(n);

//     for (int vertex = 0; vertex < n; vertex++)
//     {
//         if (colored[vertex].empty())
//         {
//             unordered_set<string> used_colors;
//             queue<int> q;
//             q.push(vertex);

//             while (!q.empty())
//             {
//                 int curr_vertex = q.front();
//                 q.pop();

//                 for (int adj_vertex : adj_list[curr_vertex])
//                 {
//                     if (!colored[adj_vertex].empty())
//                     {
//                         used_colors.insert(colored[adj_vertex]);
//                     }
//                     else
//                     {
//                         q.push(adj_vertex);
//                     }
//                 }

//                 for (string color : colors)
//                 {
//                     if (used_colors.find(color) == used_colors.end())
//                     {
//                         colored[curr_vertex] = color;
//                         break;
//                     }
//                 }

//                 used_colors.clear();
//             }
//         }
//     }

//     return colored;
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> adj_list(n);
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj_list[u].push_back(v);
//         adj_list[v].push_back(u);
//     }
//     vector<string> colored_map = map_coloring(adj_list);
//     for (string color : colored_map)
//     {
//         cout << color << " ";
//     }
//     cout << endl;
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// int lower_bound(vector<int> &arr, int n, int x) {
// 	int s = 0, e = n-1;
//     int mid, ans;

//     while (s <= e) {
//         mid = s+(e-s)/2;
//         if (arr[mid] == x) {
//             ans = mid;
//             s = mid+1;
//         } else if (arr[mid] < x) {
//             s = mid+1;
//         } else {
// 			e = mid-1;
// 		}
//     }
//     return ans;
// }

// vector<int> searchInTheArray(vector<int>& arr, vector<int>& queries, int n, int q)
// {
// 	// Write Your code here
// 	vector<int> prefix(arr), ans(q);
// 	for (int i = 1; i < n; i++) {
// 		prefix[i] += prefix[i-1];
// 	}

// 	for (int i = 0; i < q; i++) {
// 		int val = lower_bound(arr, n, queries[i]);
// 		ans[i] = prefix[val];
// 		cout << i << " " << val << " " << ans[i] << endl;
// 	}
// 	return ans;
// }

// int main()
// {

//     int n, q;
//     cin >> n >> q;

//     vector<int> arr(n), queries(q);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     for (int i = 0; i < q; i++)
//     {
//         cin >> queries[i];
//     }
    
//     for (auto i : arr)
//     {
//         cout << i << " ";
//     }
//     cout << endl;
//     for (auto i : queries)
//     {
//         cout << i << " ";
//     }
//     cout << endl;
//     for (auto i : searchInTheArray(arr, queries, n, q))
//     {
//         cout << i << " ";
//     }
//     cout << endl;
    
//     return 0;
// }

// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <stack>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//     int n;
//     cin >> n;

//     vector<vector<int>> v(n);
//     // vector<bool> visited(n, false);

//     for (int i = 0; i < n - 1; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         v[a - 1].push_back(b - 1);
//         v[b - 1].push_back(a - 1);
//     }

//     // for (int i = 0; i < n; i++)
//     // {
//     //     for (int j : v[i])
//     //     {
//     //         cout << j << " ";
//     //     }
//     //     cout << "\n";
//     // }

//     int ans = 0;

//     stack<pair<pair<int, int>, int>> s;

//     s.push({{0, -1}, 0});

//     while (!s.empty())
//     {
//         pair<pair<int, int>, int> t = s.top();
//         s.pop();
//         ans += t.second;
//         for (int j : v[t.first.first])
//         {
//             if (j != t.first.second)
//                 s.push({{j, t.first.first}, t.second + 1});
//         }
//     }

//     cout << ans;

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <numeric>

// using namespace std;

// bool canSchedule(vector<int> &tasks, int d, int maxDifficulty)
// {
//     int currDays = 1;
//     int currDifficulty = 0;

//     for (int task : tasks)
//     {
//         currDifficulty = max(currDifficulty, task);
//         if (currDifficulty > maxDifficulty)
//         {
//             currDays++;
//             currDifficulty = task;
//             if (currDays > d)
//             {
//                 return false;
//             }
//         }
//     }

//     return true;
// }

// int minimumDifficulty(vector<int> &tasks, int d)
// {
//     int n = tasks.size();

//     int maxDifficulty = *max_element(tasks.begin(), tasks.end());
//     int sumDifficulties = accumulate(tasks.begin(), tasks.end(), 0);

//     if (maxDifficulty > sumDifficulties)
//     {
//         return -1; // Not possible to schedule
//     }

//     int left = maxDifficulty;
//     int right = sumDifficulties;
//     int result = -1;

//     while (left <= right)
//     {
//         int mid = left + (right - left) / 2;
//         if (canSchedule(tasks, d, mid))
//         {
//             result = mid;
//             right = mid - 1;
//         }
//         else
//         {
//             left = mid + 1;
//         }
//     }

//     return result;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> tasks(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> tasks[i];
//     }

//     int d;
//     cin >> d;

//     int minDifficulty = minimumDifficulty(tasks, d);
//     cout << minDifficulty << endl;

//     return 0;
// }


/*
    ©EncryptoKnight's Code
*/

#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        
    }
    return 0;
}