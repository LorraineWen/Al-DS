#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
using name=struct NodeList
{
    int data;
    struct NodeList* next;
    struct NodeList* pre;
    NodeList(int data=0):data(data),next(nullptr)
    {}
};
class ListQueue
{
    public:
        ListQueue(int size=10):capacity(size),size(0)
        {
            head=new NodeList();
            head->next=head;
            head->pre=head;
        }
        ~ListQueue()
        {
            for(NodeList* p=head->next;p!=head;)
            {
                NodeList* t=p;
                p=p->next;
                delete t;
                t=nullptr;
            }
            delete head;
            head=nullptr;
        }
        void push(int val)
        {
            NodeList* p=new NodeList(val);
            p->next=head->pre->next;
            p->pre=head->pre;
            head->pre->next=p;
            head->pre=p;
            size++;
        }
        void pop()
        {
            if(head->next==head)throw "queque is empty";
            NodeList* t=head->next;
            t->next->pre=head;
            head->next=t->next;
            delete t;
            size--;
        }
        int front()
        {
            if(head->next==head)throw "queque is empty";
            return head->next->data;
        }
        int back()
        {
            if(head->next==head)throw "queque is empty";
            return head->pre->data;
        }
        bool empty()
        {
            return head->next==head;
        }
        int getsize()
        {
            return size;
        }
    private:
        NodeList* head;
        int capacity;
        int size;
};
int  main()
{
    srand(time(NULL));
    ListQueue que;
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