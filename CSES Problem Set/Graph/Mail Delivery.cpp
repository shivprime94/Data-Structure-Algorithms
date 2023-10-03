/* Author : G Pala Venki Reddy */

/* Problem Description */

/*

    Your task is to deliver mail to the inhabitants of a city. 
    For this reason, you want to find a route whose starting and ending point are the post office, 
    and that goes through every street exactly once.

*/

/*
    Input:
    The first input line has two integers n and m: the number of crossings and streets. 
    The crossings are numbered 1,2,…,n, and the post office is located at crossing 1.

    After that, there are m lines describing the streets. Each line has two integers a and b: there is a street between crossings a and b. 
    All streets are two-way streets.

    Every street is between two different crossings, and there is at most one street between two crossings.

    Output:
    Print all the crossings on the route in the order you will visit them. You can print any valid solution.
    If there are no solutions, print "IMPOSSIBLE".

    Constraints:
    2 ≤ n ≤ 105 
    1 ≤ m ≤ 2.105
    1 ≤ a, b ≤ n

*/

/*
    Example Test Case:

    Sample Input:
    6 8
    1 2
    1 3
    2 3
    2 4
    2 6
    3 5
    3 6
    4 5

    Sample Output:
    1 2 6 3 2 4 5 3 1

*/

/* -------------------------- Solution -------------------------- */

#include <bits/stdc++.h>
 
using namespace std;
 
set<int> adj[100005];
 
int main()
{
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
 
    /* check if Eulerian circuit is possible */
    /* all nodes must have even degree */
    bool isValid = true;
    for(int i = 1; i <= n; i++)
    {
        if(adj[i].size() % 2 != 0)
        {
            cout << "IMPOSSIBLE" << endl;
            isValid = false;
            break;
        }
    }
 
    if(isValid)
    {
        /* now find euler circuit using dfs starting from any node */
        stack<int> s;
        s.push(1);
        vector<int> path;
        while(!s.empty())
        {
            int curr = s.top();
            if(adj[curr].empty() == true)
            {
                /* curr node is processed , add the node to path */
                path.push_back(curr);
                s.pop();
            }
            else
            {
                /* pick unvisited node adjacent to it */
                int temp = *adj[curr].begin();
                /* remove the present visited node from thier respective adj lists of edge nodes */
                adj[curr].erase(temp);
                adj[temp].erase(curr);
                s.push(temp);
            }
        }
 
        /* now print the Euler circuit path */
        /* check no of nodes visited is equal to no of edges plus one */
        if((int)path.size() == m + 1)
        {
            for(auto x: path)
            {
                cout << x << " ";
            }
        }
        else
        {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}