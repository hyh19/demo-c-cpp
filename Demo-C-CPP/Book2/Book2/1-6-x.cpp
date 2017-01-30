#include <stdio.h>
#include "Stack.hpp"

int main() {
    const int size = 6;
    Stack<int> s = Stack<int>(size);
    for (int i=1; i<=size; i++) {
        s.push(i*100);
    }
    s.print();
    
    int ele = s.pop();
    cout << "ele: " << ele << endl;
    s.print();
    return 0;
}
