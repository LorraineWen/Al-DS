#include<bits/stdc++.h>
using namespace std;
void bubblesort(int arr[], int n)
{
    bool finish=false;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)//j+1不能越界，所以小于n-1
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                finish=true;
            }
        }
        //如果没有发生数据交换，代表序列已经有序
        if(!finish)break;
        finish=false;
    }
}
int main()
{
    srand(time(NULL));
    int arr[10];
    int* p= new int(10);
    shared_ptr<int> ptr1(p);
    for(int i=0;i<10;i++)
    {
        arr[i]=rand()%100;
    }
    for(auto it:arr)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    bubblesort(arr,10);
    for(auto it:arr)
    {
        cout<<it<<" ";
    }
    return 0;
}