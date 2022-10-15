/* Author : G Pala Venki Reddy */

/* Problem Description */

/*
    Consider a network consisting of n computers and m connections. 
    Each connection specifies how fast a computer can send data to another computer.

    Kotivalo wants to download some data from a server. 
    What is the maximum speed he can do this, using the connections in the network?

*/

/*
    Input:
    The first input line has two integers n and m: the number of computers and connections. 
    The computers are numbered 1,2,…,n. Computer 1 is the server and computer n is Kotivalo's computer.

    After this, there are m lines describing the connections. 
    Each line has three integers a, b and c: computer a can send data to computer b at speed c.

    Output:
    Print one integer: the maximum speed Kotivalo can download data.

    Constraints:
    1 <= n <= 500
    1 <= m <= 1000
    1 <= a,b <= n
    1 <= c <= 10^9
*/

/*
    Example test case:

    Sample Input:
    4 5
    1 2 3
    2 4 2
    1 3 4
    3 4 5
    4 1 3

    Sample Output:
    6

*/

/* ------------------- Solution ------------------- */

#include <bits/stdc++.h>
 
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define lli long long int
 
lli capacity[505][505];
int n, m;
vector<bool> visited(505);
vector<int> parent(505);
 
bool reachable()
{
    /* mark all nodes as unvisited */
    visited.assign(505, false);
    /* we will perform BFS from source */
    /* here source is node 1 */
    queue<int> q;
    q.push(1);
    visited[1] = true;
 
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int i = 1; i <= n; i++)
        {
            /* check if edge between curr node and node i has residual capacity > 0 and node i is unvisited */
            if(capacity[curr][i] > 0 && visited[i] == false)
            {
                visited[i] = true;
                /* to know we arrived at node i from curr node , so we can easily get augmented path from it */
                parent[i] = curr;
                q.push(i);
            }
        }
    }
 
    /* check if last node is visited or not */
    return visited[n];
}
 
 
int main()
{
    fastio();
 
    cin >> n >> m;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            capacity[i][j] = 0;
        }
    }
 
    int u, v;
    lli c;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        capacity[u][v] += c;
    }
 
    lli MaxFlow = 0;
 
    /* we will find augmenting paths using Dinic's maxflow algorithm */
    while(reachable())
    {
        /* first check that are we able to reach sink from src */
        /* if it possible, then we are able to find a augmented path from src to sink */
        /* we can get augmented path using parent array from sink to src */
        /* find the bottleneck capacity among all edges in aug path */
        lli flow = 1e18;
        for(int i = n; i != 1; i = parent[i])
        {
            u = parent[i];
            flow = min(flow, capacity[u][i]);
        }
 
        /* now augment the flow */
        /* increase the maxflow */
        MaxFlow += flow;
        /* update the edges capacities in the augmented path */
        for(int i = n; i != 1; i = parent[i])
        {
            u = parent[i];
            /* decrease the forward edge with flow & increase the residual capacity of backward edge */
            capacity[u][i] -= flow;
            capacity[i][u] += flow;
        }
    }
 
    cout << MaxFlow << endl;
    return 0;
}