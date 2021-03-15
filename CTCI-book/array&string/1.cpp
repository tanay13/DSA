//method to find whether one string is permutation of other

#include<bits/stdc++.h>
using namespace std;

bool isPermute(string s1,string s2)
{
    unordered_map<char,int> s1map,s2map;

    for(auto x: s1)
    {
        if(s1map.find(x)==s1map.end())
        s1map[x] = 1;
        else
        s1map[x]++;
    }

    for(auto x: s2)
    {
        if(s2map.find(x)==s2map.end())
        s2map[x] = 1;
        else
        s2map[x]++;
    }

    if(s1.length()!=s2.length())
    {
        return false;
    }
    else
    {
        for(auto x : s1)
        {
            if(s1map[x]==s2map[x])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
}

int main()
{
    string s1,s2;
    cout<<"enter the first string\n";
    cin>>s1;
    cout<<"enter the second string\n";
    cin>>s2;

    cout<<isPermute(s1,s2);
    return 0;


}