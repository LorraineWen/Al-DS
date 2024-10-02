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
class DoubleCircleList
{
    public:
        DoubleCircleList()
        {
            head=new ListNode();
            tail=head;
            head->pre=tail;
            tail->next=head;
        }
        ~DoubleCircleList()
        {
            for(ListNode* p=head->next;p->next!=head;)
            {
                ListNode* t=p;
                p->next->pre=p->pre;
                p=p->next;
                delete t;
                t=nullptr;
            }
            delete head;
            head=nullptr;
            tail=nullptr;
        }
        //尾插法
        void push_back(int val)
        {
            ListNode* p=new ListNode(val);
            p->pre=tail;
            p->next=tail->next;
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
            while (p!=head) 
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
    DoubleCircleList doublecirclelist;
    for(int i=0;i<10;i++)
    {
        doublecirclelist.push_back(18);
    }
    doublecirclelist.erase(18);
    for(ListNode*p =doublecirclelist.gethead()->next;p!=doublecirclelist.gethead();p=p->next)
    {
        cout<<p->data<<" ";
    }
    return 0;
}