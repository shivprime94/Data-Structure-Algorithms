/*
C++ program to find the the smallest possible weight of the left stone
Link-- https://leetcode.com/problems/last-stone-weight/

Input: stones = [2,7,4,1,8,1]
Output: 1

Input: stones = [1]
Output: 1
*/

#include<bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int>& stones)
{
    sort(stones.begin(), stones.end());
    while (stones.size() != 1)
    {
        int n = stones.size();
        int y = stones[n - 1];
        int x = stones[n - 2];
        stones.erase(stones.begin() + (n - 1));
        stones.erase(stones.begin() + (n - 2));
        stones.push_back(y - x);
        sort(stones.begin(), stones.end());
    }
    return stones[0];
}

int main(){
    vector<int> stones;
    int n,s,result;
    cout<<"Enter number of stones: "<<endl;
    cin>>n;
    for (int i = 0; i<n; i++){
        cin>>s;
        stones.push_back(s);
    }

    result=lastStoneWeight(stones);
    cout<<"The smallest possible weight of the left stone is "<<result<<endl;
    return 0;
}
