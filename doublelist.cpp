#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
typedef struct ListNode
{
    int data;
    struct ListNode* next;
    struct ListNode* pre;
    ListNode(int data=0):data(data),next(nullptr),pre(nullptr)
    {}
}ListNode;
class DoubleList
{
    public:
        DoubleList()
        {
            head=new ListNode();
            tail=head;
        }
        ~DoubleList()
        {
            for(ListNode* p=head;p!=nullptr;)
            {
                ListNode* t=p;
                p=p->next;
                delete t;
                t=nullptr;
            }
            head=nullptr;
            tail=nullptr;
        }
        //尾插法
        void push_back(int val)
        {
            ListNode* p=new ListNode(val);
            p->pre=tail;
            tail->next=p;
            tail=p;
        }
        //头插法
        void push_front(int val)
        {
            ListNode* p=new ListNode(val);
            p->next=head->next;
            p->pre=head;
            if(head->next!=nullptr)head->next->pre=p;
            head->next=p;
        }
        void erase(int val) 
        {
            ListNode* p = head->next;
            while (p!=nullptr) 
            {
                if (p->data == val) 
                {
                    ListNode* t = p;
                    if(p->next!=nullptr) p->next->pre=p->pre;
                    p->pre->next = p->next;
                    p=p->next;
                    delete t;
                    t=nullptr;
                }
                else
                {
                    p = p->next;
                } 
            }
        }
        ListNode* find(int val)
        {
            ListNode* p=head->next;
            while(p!=head)
            {
                if(p->data==val)return p;
                p=p->next;
            }
            return head;
        }
        ListNode* gethead()
        {
            return head;
        }
    private:
        ListNode* head;
        ListNode* tail;
};
int  main()
{
    srand(time(NULL));
    DoubleList doublelist;
    for(int i=0;i<10;i++)
    {
        doublelist.push_front(18);
    }
    doublelist.erase(18);
    for(ListNode*p =doublelist.gethead()->next;p!=nullptr;p=p->next)
    {
        cout<<p->data<<" ";
    }
    return 0;
}