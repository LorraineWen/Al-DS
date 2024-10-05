#include<bits/stdc++.h>
using namespace std;
int binarysearch(vector<int>& v,int val,int left,int right)
{
    if(right<left)return -1;
    int mid=(left+right)/2;
    if(v[mid]==val)return mid;
    else if(v[mid]>val)return binarysearch(v,val,left,mid-1);
    else return binarysearch(v,val,mid+1,right); 
}
int  main()
{
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    cout<<binarysearch(v,5,0,v.size()-1);
    return 0;
}