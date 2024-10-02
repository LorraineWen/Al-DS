#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
class SeqStack
{
    public:
        SeqStack(int size=10):top(0),capacity(size)
        {
            realstack=new int[size];
        }
        ~SeqStack()
        {
            delete []realstack;
        }
        void push(int val)
        {
            if(top==capacity)expand(2*capacity);
            realstack[top++]=val;
        }
        void pop()
        {
            if(top==0)throw "stack is empty";
            top--;
        }
        int gettop()
        {
            return realstack[top-1];
        }
        int size()
        {
            return top;
        }
        bool empty()
        {
            return top==0;
        }
    private:
        void expand(int newsize)
        {
            int* p=new int[newsize];
            memcpy(p,realstack,sizeof(int)*newsize);
            delete []realstack;
            realstack=p;
        }
        int* realstack;
        int top;
        int capacity;
};
int  main()
{
    srand(time(NULL));
    SeqStack stack;
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