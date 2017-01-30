#include <stdio.h>
#include "Queue.hpp"
#include <iostream>
using namespace std;

int main() {
    int size = 10;
    Queue<int> q = Queue<int>(size);
    for (int i=1; i<=50; i++) {
        q.enqueue(i*100);
    }
    cout << "length: " << q.getLength() << endl;
    q.print();
    
    return 0;
}
