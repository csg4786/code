#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int value, weight;
    double ratio;
};

bool cmp(Item a, Item b)
{
    return a.ratio > b.ratio;
}

int n, W, best_value = 0;
vector<Item> items;

int upper_bound(int i, int value, int weight)
{
    int remain = W - weight;
    int bound = value;
    while (i < n && remain >= items[i].weight)
    {
        remain -= items[i].weight;
        bound += items[i].value;
        i++;
    }
    if (i < n)
    {
        bound += (double)remain * items[i].ratio;
    }
    return bound;
}

void branch_and_bound(int i, int value, int weight)
{
    if (weight > W)
        return;
    if (value + upper_bound(i, 0, weight) <= best_value)
        return;
    if (i == n)
    {
        best_value = value;
        return;
    }
    branch_and_bound(i + 1, value, weight);
    branch_and_bound(i + 1, value + items[i].value, weight + items[i].weight);
}

int main()
{
    cin >> n >> W;
    items.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].value >> items[i].weight;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
    sort(items.begin(), items.end(), cmp);
    branch_and_bound(0, 0, 0);
    cout << "Best Value: " << best_value << "\n";
    return 0;
}
