#include<iostream>
using namespace std;
enum Status
{
    STAT_USING,
    STAT_UNUSE,
    STAT_DEL
};
using Bucket=struct Bucket
{
    int value;
    Status stat;
    Bucket(int data=0):value(data),stat(STAT_UNUSE)
    {}
};
class HashTable
{
    public:
        HashTable(int size=primes[0],double loadfactor=0.75):num(0),
        loadfactor(loadfactor),
        primeindex(0)
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
            capacity=primes[primeindex];
            realhashtable=new Bucket[capacity];
        }
        ~HashTable()
        {
            delete []realhashtable;
            realhashtable=nullptr;
        }
        bool insert(int val)
        {
            double lf=num*1.0/capacity;
            if(lf>loadfactor)expand();
            int hashval=val%capacity;//除留余数法
            int i=hashval;
            do
            {
                if(realhashtable[i].stat!=STAT_USING)
                {
                    realhashtable[i].stat=STAT_USING;
                    realhashtable[i].value=val;
                    num++;
                    return true;
                }
                i=(i+1)%capacity;
            } while (i!=hashval);//判断是否已经遍历完毕整个环形哈希表
            return false;
        }
        void erase(int val)
        {
            int hashval=val%capacity;
            int i=hashval;
            do
            {
                if(realhashtable[i].stat==STAT_USING&&realhashtable[i].value==val)
                {
                    realhashtable[i].stat=STAT_DEL;
                    num--;
                }
                i=(i+1)%capacity;
            } while (realhashtable[i].stat!=STAT_UNUSE&&i!=hashval);//遇到UNUSE状态就不需要往后遍历了
        }
        int find(int val)
        {
            int hashval=val%capacity;
            int i=hashval;
            do
            {
                if(realhashtable[i].stat==STAT_USING&&realhashtable[i].value==val)
                {
                    return i;
                }
                i=(i+1)%capacity;
            } while (realhashtable[i].stat!=STAT_UNUSE&&i!=hashval);
            return -1;
        }
    private:
        Bucket* realhashtable;
        int capacity;
        int num;
        double loadfactor;
        static const int PRIME_SIZE=10;
        static int primes[PRIME_SIZE];
        int primeindex;//当前使用的素数的下标
        void expand()
        {
            primeindex++;
            if(primeindex==PRIME_SIZE)
            {
                throw "primetable is full";
            }
            Bucket* p=new Bucket[primes[primeindex]];
            for(int i=0;i<capacity;i++)
            {
                if(realhashtable[i].stat==STAT_USING)
                {
                    int hashval=realhashtable[i].value%primes[primeindex];
                    int k=hashval;
                    do
                    {
                        if(p[k].stat!=STAT_USING)
                        {
                            p[k].stat=STAT_USING;
                            p[k].value=realhashtable[i].value;
                            break;
                        }
                        k=(k+1)%primes[primeindex];
                    } while (k!=hashval);
                }
            }
            delete[]realhashtable;
            realhashtable=p;
            capacity=primes[primeindex];
        }
};
int HashTable::primes[PRIME_SIZE]={3,7,23,47,97,251,443,911,1471,42773};
int  main()
{
    HashTable hashtable;
    hashtable.insert(21);
    hashtable.insert(32);
    hashtable.insert(14);
    hashtable.insert(15);
    hashtable.insert(22);
    cout<<hashtable.find(15)<<endl;
    hashtable.erase(14);
    cout<<hashtable.find(14)<<endl;
    return 0;
}