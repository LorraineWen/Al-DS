#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
class CircleQueue
{
    public:
        CircleQueue(int size=10):capacity(size),size(0),rear(0),first(0)
        {
            realqueque=new int[capacity];
        }
        ~CircleQueue()
        {
            delete []realqueque;
        }
        void push(int val)
        {
            if((rear+1)%capacity==first)expand(2*capacity);
            realqueque[rear]=val;
            rear=(rear+1)%capacity;
            size++;
        }
        void pop()
        {
            if(rear==first)throw "queque is empty";
            first=(first+1)%capacity;
            size--;
        }
        int front()
        {
            int val=realqueque[first];
            return val;
        }
        int back()
        {
            int val=realqueque[(rear-1)%capacity];
            return val;
        }
        bool empty()
        {
            return rear==first;
        }
        int getsize()
        {
            return size;
        }
    private:
        void expand(int newsize)
        {
            int* p=new int[newsize];
            int i=0,j=first;
            for(;j!=rear;i++,j=(j+1)%capacity)
            {
                p[i]=realqueque[j];
            }
            delete []realqueque;
            realqueque=p;
            first=0;
            rear=i;
            capacity=newsize;
        }
        int first;
        int rear;
        int capacity;
        int* realqueque;
        int size;
};
int  main()
{
    srand(time(NULL));
    CircleQueue que;
    for(int i=0;i<20;i++)
    {
        que.push(i);
    }
    while(!que.empty())
    {
        cout<<que.front()<<" ";
        que.pop();
        cout<<"size:"<<que.getsize()<<endl;;
    }
    return 0;
}