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
void choicesort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min_element=arr[i];
        int min_index=i;
        for(int j=i;j<n;j++)//用于找到数组中第i个元素到第n个元素间的最小值下标
        {
            if(arr[j]<min_element)
            {
                min_index=j;
                min_element=arr[j];
            }
        }
        swap(arr[i],arr[min_index]);//将队首元素i与最小值元素交换
    }
}
void insertsort(int arr[],int n)
{
    //外层循环从第二个元素开始
    for(int i=1;i<n;i++)
    {
        int val=arr[i];
        int j=i-1;
        //内层循环用于在当前元素的前面的有序序列中找到小于等于当前元素的元素，让后将当前元素插入到这个元素的后面
        for(;j>=0;j--)
        {
            arr[j+1]=arr[j];
            if(arr[j]<=val)break;
        }
        arr[j+1]=val;
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
    choicesort(arr,10);
    for(auto it:arr)
    {
        cout<<it<<" ";
    }
    return 0;
}