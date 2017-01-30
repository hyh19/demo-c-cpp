#include <iostream>
#include "HashTable.hpp"
using namespace std;

int main()
{
    HashTable<int> hashtable = HashTable<int>(13);  //构建散列表
    //依次插入元素
    hashtable.insertHash(66);
    hashtable.insertHash(79);


    //输出元素
    cout<<"表中的元素为：";
    for(int i = 1;i<=13;i++)
        cout<<hashtable.getData(i)<<" ";
    cout<<endl;
    //查找元素55
    cout<<"元素55的位置："<<hashtable.searchHash(55)<<endl;
    return 0;
}
