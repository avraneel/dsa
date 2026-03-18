#include <bits/stdc++.h>
using namespace std;

void display(vector<int> window, int sum)
{
    cout << "Window = [ ";
    for (int item : window)
        cout
            << item << " ";
    cout << "], Sum = " << sum << "\n";
}

int vectorSum(vector<int> v)
{
    int sum = 0;
    for (auto &item : v)
        sum += item;
    return sum;
}

/**
 * Given a sliding window of size n, runs it through the entire array and
 * prints out the sum each time
 *
 * @param n size of sliding window
 */
void slidingWindowSum(vector<int> v, int n)
{
    int left = 0;
    int right = n - 1;

    while (right < v.size())
    {
        vector<int> window(v.begin() + left, v.begin() + right + 1);
        int sum = vectorSum(window);
        display(window, sum);
        left++;
        right++;
    }
}

int main()
{
    slidingWindowSum({1, 2, 3, 4, 5, 6, 7, 8, 9}, 3);
    return 0;
}