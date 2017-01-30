#include <iostream>
#include "AvlTree.h"
using namespace std;

int main() {
    AvlTree<int> t;
    t.insert(3);
    t.insert(2);
    t.insert(1);
    t.insert(4);
    t.printTree();
    return 0;
}
