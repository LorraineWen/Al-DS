#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
typedef struct ListNode
{
    int data;
    struct ListNode* next;
    ListNode(int data=0):data(data),next(nullptr)
    {}
}ListNode;
class CircleList
{
    public:
        CircleList()
        {
            head=new ListNode();
            tail=head;
            tail->next=head;
        }
        ~CircleList()
        {
            for(ListNode* p=head->next;p!=head;)
            {
                ListNode* t=p;
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
            p->next=tail->next;
            tail->next=p;
            tail=p;
        }
        //头插法
        void push_front(int val)
        {
            ListNode* p=new ListNode(val);
            p->next=head->next;
            head->next=p;
            if(p->next==head)
            {
                tail=p;
            }
        }
        void erase(int val) 
        {
            ListNode* p = head;//要从头节点开始
            while (p->next != head) 
            {
                if (p->next->data == val) 
                {
                    ListNode* t = p->next;
                    p->next = p->next->next;
                    if(p->next==head)tail=p;
                    delete t;
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
    CircleList circlelist;
    for(int i=0;i<20;i++)
    {
        circlelist.push_front(18);
    }
    circlelist.erase(18);
    ListNode* q=circlelist.find(18);
    cout<<q->data;
    for(ListNode*p =circlelist.gethead()->next;p!=circlelist.gethead();p=p->next)
    {
        cout<<p->data<<" ";
    }
    return 0;
}