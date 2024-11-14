#include<vector>
#include<algorithm>
#include<list>
#include<deque>
#include<iostream>
class ListHashTable
{
    public:
        ListHashTable(int size=primes[0],double loadfactor=0.75):loadfactor(loadfactor),primeindex(0),used_num(0)
        {
            if(size!=primes[0])
            {
                for(;primeindex!=PRIME_SIZE;primeindex++)
                {
                    if(primes[primeindex]>size)
                    {
                        break;
                    }
                }
            }
            if(primeindex==size)//用户传入的size比最大素数还大
            {
                primeindex--;//调整为最大的素数
            }
            realhashtable.resize(primes[primeindex]);//不能使用reserve，必须使用resize开辟空间并构造对象list
        }
        ~ListHashTable()
        {}
        void insert(int val)
        {
            double lf=used_num*1.0/realhashtable.size();
            if(lf>loadfactor)expand();
            int hashval=val%realhashtable.size();
            if(realhashtable[hashval].empty())//如果桶为空，那么使用过的桶数就加1并且在该桶链表中插入元素。
            {
                used_num++;
            }
            realhashtable[hashval].emplace_front(val);
        }
        void erase(int val)
        {
            int hashval=val%realhashtable.size();
            realhashtable[hashval].remove(val);
            if(realhashtable[hashval].empty())used_num--;
        }
        bool find(int val)
        {
            int hashval=val%realhashtable.size();
            auto it=std::find(realhashtable[hashval].begin(),realhashtable[hashval].end(),val);
            return it!=realhashtable[hashval].end();
        }
    private:
        std::vector<std::list<int>>realhashtable;
        int used_num;//使用了的桶的个数
        double loadfactor;
        static const int PRIME_SIZE=10;
        static int primes[PRIME_SIZE];
        int primeindex;//当前使用的素数的下标
        void expand()
        {
            if(primeindex+1==PATH_MAX)
            {
                throw "hashtable can not expand anymore";
            }
            primeindex++;
            std::vector<std::list<int>>oldtable;
            oldtable.swap(realhashtable);
            realhashtable.resize(primes[primeindex]);
            //当哈希表扩容后，要进行元素再次哈希，并且哈希后已经使用的桶数也会变化
            used_num=0;
            for(auto it:oldtable)
            {
                for(auto val:it)
                {
                    int hashval=val%realhashtable.size();
                    if(realhashtable[hashval].empty())used_num++;
                    realhashtable[hashval].emplace_front(val);
                }
            }
        }
};
int main()
{
    ListHashTable hashtable;
    hashtable.insert(21);
    hashtable.insert(32);
    hashtable.insert(14);
    hashtable.insert(15);
    hashtable.insert(22);
    std::cout<<hashtable.find(15)<<std::endl;
    hashtable.erase(14);
    std::cout<<hashtable.find(14)<<std::endl;
    return 0;
}