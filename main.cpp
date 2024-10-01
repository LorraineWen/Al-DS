#include<iostream>
#include<time.h>
using namespace std;
class Array
{
    public:
        Array(int size=10):capacity(size),curnum(0)
        {
            realarray=new int[size];
        }
        ~Array()
        {
            delete []realarray;
        }
        void push_back(int val)
        {
            if(curnum==capacity)expand(2*capacity);
            realarray[curnum++]=val;
        }
        void pop_back()
        {
            if(curnum)curnum--;
        }
        void insert(int pos,int val)
        {
            if(pos<0||pos>curnum)return;
            if(curnum==capacity)expand(2*capacity);
            for(int i=curnum;i>=pos;i--)
            {
                realarray[i]=realarray[i-1];
            }
            realarray[pos]=val;
            curnum++;
        }
        void erase(int pos)
        {
            if(pos<0||pos>=curnum)return;
            for(int i=pos;i<curnum-1;i++)
            {
                realarray[i]=realarray[i+1];
            }
            curnum--;
        }
        int find(int val)
        {
            int res=-1;
            for(int i=0;i<curnum;i++)
            {
                if(realarray[i]==val)i=res;
            }
            return -1;
        }
        int size()
        {
            return curnum;
        }
        void show()
        {
            for(int i=0;i<curnum;i++)
            {
                std::cout<<realarray[i]<<" ";
            }
            std::cout<<std::endl;
        }
    private:
        int* realarray;
        int capacity;
        int curnum;
        void expand(int newcapacity)
        {
            int* p=new int[newcapacity];
            memcpy(p,realarray,curnum*sizeof(int));
            delete []realarray;
            realarray=p;
            capacity=newcapacity;
        }
};
int  main()
{
    Array array(10);
    srand(time(NULL));
    for(int i=0;i<20;i++)
    {
        array.push_back(rand()%100);
    }
    array.show();
    array.insert(2,10);
    array.show();
    array.erase(1);
    array.show();
    return 0;
}