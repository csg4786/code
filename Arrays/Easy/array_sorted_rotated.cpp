#include <bits/stdc++.h>
using namespace std;

bool arraySortedRotated(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;

    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            count++;
        }
    }
    if (nums[n-1] > nums[0])
    {
        count++;
    }
    return count <= 1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    (arraySortedRotated(nums)) ? cout << "True" << endl : cout << "False" << endl;

    return 0;
}
