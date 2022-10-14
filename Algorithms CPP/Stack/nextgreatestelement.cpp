#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int q[] = {7, 4, 3, 5, 9, 4, 3, 6};
    int n = sizeof(q) / sizeof(int);
    stack<int> s;
    vector<int> ng(n);
    for (int i = 0; i < n; i++)
    {
        if (s.empty() or q[i] < q[s.top()])
            s.push(i);
        else if (q[i] > q[s.top()])
        {
            int a = q[i];
            while (!s.empty() and a > q[s.top()])
            {
                ng[s.top()] = a;
                s.pop();
            }
            s.push(i);
        }
    }
    while (!s.empty())
    {
        ng[s.top()] = -1;
        s.pop();
    }
    for (int i = 0; i < ng.size(); i++)
    {
        cout << ng[i] << " ";
    }
    cout << endl;
    return 0;
}
