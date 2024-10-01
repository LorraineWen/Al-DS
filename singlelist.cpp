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
class SingleList
{
    public:
    SingleList()
    {
        head=new ListNode();
        tail=head;
    }
    ~SingleList()
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
        tail->next=p;
        tail=p;
    }
    //头插法
    void push_front(int val)
    {
        ListNode* p=new ListNode(val);
        p->next=head->next;
        head->next=p;
    }
    void erase(int val) 
    {
        ListNode* p = head;//要从头节点开始
        while (p != nullptr && p->next != nullptr) 
        {
            if (p->next->data == val) 
            {
                ListNode* t = p->next;
                p->next = p->next->next;
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
        ListNode*p=head->next;
        while(p!=nullptr)
        {
            if(p->data==val)return p;
            p=p->next;
        }
        return nullptr;
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
    SingleList list;
    for(int i=0;i<20;i++)
    {
        list.push_back(rand()%100);
    }
    for(ListNode* p=list.gethead()->next;p!=nullptr;p=p->next)
    {
        cout<<p->data<<" ";
    }
    cout<<endl;
    for(ListNode* p=list.gethead()->next;p!=nullptr;p=p->next)
    {
        cout<<p->data<<" ";
    }
    cout<<endl;
    return 0;
}