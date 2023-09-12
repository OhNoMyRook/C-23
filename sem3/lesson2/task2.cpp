#include <iostream>
#include <algorithm>
using namespace std;

bool comparator(const pair<int, int>& a, const pair<int, int>& b)
{
return (a.first * a.second) < (b.first * b.second);
}

int main()
{
pair<int, int> arr[] =
{
{2, 3},
{1, 5},
{4, 7},
{6, 9},
{8, 2}
};

cout << "Unsorted array:\n";
for(int i=0; i<5; i++)
    cout << arr[i].first << " " << arr[i].second << endl;

sort(&arr[0], &arr[5], comparator);

cout << "Sorted array:\n";
for(int i=0; i<5; i++)
    cout << arr[i].first << " " << arr[i].second << endl;
}