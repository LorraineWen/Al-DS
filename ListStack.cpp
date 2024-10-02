#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
using name=struct NodeList
{
    int data;
    struct NodeList* next;
    NodeList(int data=0):data(data),next(nullptr)
    {}
};
class ListStack
{
    public:
        ListStack()
        {
            head=new NodeList();
        }
        ~ListStack()
        {
            while(head!=nullptr)
            {
                NodeList* p=head;
                head=head->next;
                delete p;
            }
        }
        void push(int val)
        {
            NodeList* p=new NodeList(val);
            p->next=head->next;
            head->next=p;
        }
        void pop()
        {
            if(head->next==nullptr)throw "stack is empty";
            NodeList* p=head->next;
            head->next=head->next->next;
            delete p;
            p=nullptr;
        }
        int gettop()
        {
            if(head->next==nullptr)throw "stack is empty";
            return head->next->data;
        }
        bool empty()
        {
            return head->next==nullptr;
        }
    private:
        NodeList* head;
};
int  main()
{
    srand(time(NULL));
    ListStack stack;
    for(int i=0;i<20;i++)
    {
        stack.push(i);
    }
    while(!stack.empty())
    {
        cout<<stack.gettop()<<" ";
        stack.pop();
    }
    return 0;
}