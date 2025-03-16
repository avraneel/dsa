#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(2);
    s.insert(2);
    s.insert(3);

    for(auto x : s)
    {
        cout << x << " ";
    }
    return 0;
}