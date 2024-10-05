#include<bits/stdc++.h>
using namespace std;
int binarysearch(vector<int>& v,int val)
{
    int left=0;
    int right=v.size()-1;
    int mid=(left+right)/2;
    while(left<=right)//必须小于等于，当left和right相等时，那个数可能刚好就是val
    {
        if(v[mid]==val)return mid;
        else if(v[mid]>val)right=mid-1;
        else if(v[mid]<val)left=mid+1;
        mid=(left+right)/2;
    }
    return -1;
}
int  main()
{
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    cout<<binary_search(v.begin(),v.end(),5);
    return 0;
}