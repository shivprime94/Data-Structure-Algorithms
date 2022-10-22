#include<bits/stdc++.h>
using namespace std;
void checkSpell(vector<string>s1,vector<string>s2, vector<string>s3){
    map<string,int>mp1;
    map<string,int>mp2;
    map<string,int>mp3;
   
    for(int i=0;i<s1.size();i++){
    mp1[s1[i]]++;
    }
    for(int i=0;i<s2.size();i++){
         mp2[s2[i]]++;
    }
    for(int i=0;i<s3.size();i++){
         mp3[s3[i]]++;
    }
    int p1=0,p2=0,p3=0;
  for(int i=0;i<s1.size();i++){
    if (mp2[s1[i]]>=1 && mp3[s1[i]]>=1)
continue;
    else if(mp2[s1[i]] >= 1 || mp3[s1[i]] >=1)
    p1++;
    else
    p1 +=3;
  }
    for(int i=0;i<s3.size();i++){
     if (mp1[s3[i]]>=1 && mp2[s3[i]]>=1)
      continue;
      else if(mp1[s3[i]] >= 1 || mp2[s3[i]] >=1)
    p3++;
    else
    p3 +=3; 
    }

    for(int i=0;i<s2.size();i++){
          if (mp1[s2[i]]>=1 && mp3[s2[i]]>=1)
continue;
    else if(mp1[s2[i]] >= 1 || mp3[s2[i]] >=1)
    p2++;
    else
    p2 +=3;
    }
    cout<<p1<<" "<<p2<<" "<<p3<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string>s1(n),s2(n),s3(n);
        for(int i=0;i<n;i++)
        cin>>s1[i];
        for(int i=0;i<n;i++)
        cin>>s2[i];
        for(int i=0;i<n;i++)
        cin>>s3[i];
        checkSpell(s1,s2,s3);
    }
}
