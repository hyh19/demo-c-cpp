#include "CommonHeaders.hpp"

template <typename DataType> class BST;

template <typename DataType>
class BSTNode {
    BSTNode<DataType> *lChild, *rChild, *parent;
    DataType data;
    friend class BST<DataType>;
    
public:
    BSTNode() {
        lChild = rChild = parent = nullptr;
    }
    BSTNode(DataType data) {
        lChild = rChild = parent = nullptr;
        this->data = data;
    }
    
    DataType getData() {
        return data;
    }
};

template <typename DataType>
class BST {
    BSTNode<DataType> *root;
public:
    BST() {
        root = nullptr;
    }
    BST(DataType data) {
        root = new BSTNode<DataType>(data);
    }
    
    BSTNode<DataType>* getRoot() {
        return root;
    }
    
    bool insert(DataType newData);
    
    void inSort();
    
    BSTNode<DataType>* search(DataType key);
    
    void search(BSTNode<DataType> *rootNode, DataType key, BSTNode<DataType> **node);
    
    void deleteNode(BSTNode<DataType> *node);
    
private:
    void __inSort(BSTNode<DataType> *node);
};


/**
 插入新结点

 @param newData 新插入结点的值
 @return 成功返回true，失败返回false。
 */
template <typename DataType>
bool BST<DataType>::insert(DataType newData) {
    
    BSTNode<DataType> *newNode = new BSTNode<DataType>(newData);
    
    if (root == nullptr) { // 二叉树为空
        root = newNode;
        return true;
    }
    
    // 查找新结点要插入的位置，实际上就是找到它的双亲。
    BSTNode<DataType> *current = root, *parent = nullptr;
    while (current) {
        parent = current;
        if (newData < current->data) {
            current = current->lChild; // 继续遍历左子树
        } else if (newData > current->data) {
            current = current->rChild; // 继续遍历右子树
        } else {
            cout << "结点已存在，插入失败。/n";
            return false;
        }
    }
    // 建立新结点与其双亲的亲子关系
    newNode->parent = parent;
    if (newData < parent->data) {
        parent->lChild = newNode;
    } else {
        parent->rChild = newNode;
    }
    return true;
}

/**
 中序遍历
 */
template <typename DataType>
void BST<DataType>::inSort() {
    cout << "---- 中序遍历开始 ----\n";
    __inSort(root);
    cout << "\n---- 中序遍历结束 ----\n";
}

/**
 中序遍历

 @param rootNode 子树的根结点
 */
template <typename DataType>
void BST<DataType>::__inSort(BSTNode<DataType> *rootNode) {
    if (rootNode) {
        __inSort(rootNode->lChild);
        cout << rootNode->data << "  ";
        __inSort(rootNode->rChild);
    }
}

/**
 用while循环查找

 @param key 要查找的值
 @return 找到的结点，没有找到返回nullptr。
 */
template <typename DataType>
BSTNode<DataType>* BST<DataType>::search(DataType key) {
    BSTNode<DataType> *current = root;
    while (current) {
        if (key < current->data) {
            current = current->lChild; // 没有找到，遍历左子树。
        } else if (key > current->data) {
            current = current->rChild; // 没有找到，遍历右子树。
        } else {
            break; // 找到了
        }
    }
    return current;
}


/**
 用递归方式查找

 @param rootNode 子树的根结点
 @param key 要查找的值
 @param resultNode 找到的结点，没有找到返回nullptr。
 */
template <typename DataType>
void BST<DataType>::search(BSTNode<DataType> *rootNode, DataType key, BSTNode<DataType> **resultNode) {
    if (rootNode == nullptr) {
        *resultNode = nullptr; // 没有找到
    } else if (key == rootNode->data) {
        *resultNode = rootNode; // 找到了
    } else if (key < rootNode->data) {
        search(rootNode->lChild, key, resultNode); // 没有找到，继续遍历左子树。
    } else {
        search(rootNode->rChild, key, resultNode); // 没有找到，继续遍历右子树。
    }
}

/**
 删除结点

 @param deleteNode 要删除的结点
 */
template <typename DataType>
void BST<DataType>::deleteNode(BSTNode<DataType> *deleteNode) {
    BSTNode<DataType> *parentOfDeleteNode = deleteNode->parent;
    if (deleteNode->lChild == nullptr && deleteNode->rChild == nullptr) { // 被删除结点是叶子结点
        // 断开被删除结点与其双亲的亲子关系
        if (parentOfDeleteNode->lChild == deleteNode) {
            parentOfDeleteNode->lChild = nullptr; // 被删除结点是左孩子
        } else {
            parentOfDeleteNode->rChild = nullptr; // 被删除结点是右孩子
        }
        delete deleteNode;
    } else if (deleteNode->lChild == nullptr && deleteNode->rChild != nullptr) { // 被删除结点只有右子树
        if (nullptr == parentOfDeleteNode) { // 被删除结点是根结点
            root = deleteNode->rChild; // 被删除结点的右孩子继承为新的根结点
        } else {
            // 断开被删除结点与其右子树的亲子关系
            // 重新建立被删除结点右子树与被删除结点双亲的亲子关系
            deleteNode->rChild->parent = parentOfDeleteNode;
            if (parentOfDeleteNode->lChild == deleteNode) {
                parentOfDeleteNode->lChild = deleteNode->rChild; // 被删除结点是左孩子
            } else {
                parentOfDeleteNode->rChild = deleteNode->rChild; // 被删除结点是右孩子
            }
            delete deleteNode;
        }
    } else if (deleteNode->lChild != nullptr && deleteNode->rChild == nullptr) {
        if (nullptr == parentOfDeleteNode) { // 被删除结点是根结点
            root = deleteNode->lChild; // 被删除结点的左孩子继承为新的根结点
        } else {
            // 断开被删除结点与其左子树的亲子关系
            // 重新建立被删除结点左子树与被删除结点双亲的亲子关系
            deleteNode->lChild->parent = parentOfDeleteNode;
            if (parentOfDeleteNode->lChild == deleteNode) {
                parentOfDeleteNode->lChild = deleteNode->lChild;
            } else {
                parentOfDeleteNode->rChild = deleteNode->lChild;
            }
            delete deleteNode;
        }
    } else {
        // 步骤一：找出被删除结点的直接后继
        BSTNode<DataType> *current = deleteNode->rChild; // 游标指针，用来遍历右孩子的所有左子树，找出直接后继。
        BSTNode<DataType> *next = nullptr; // 用来保存直接后继。
        while (current) {
            next = current;
            current = current->lChild;
        }
        
        // 步骤二：断开直接后继与其双亲的关系
        if (nullptr == next->rChild) { // 直接后继是叶子结点（注意：next->lChild是nullptr）
            if (next->parent->lChild == next) {
                next->parent->lChild = nullptr; // 直接后继是左孩子
            } else {
                next->parent->rChild = nullptr; // 直接后继是右孩子
            }
        } else {
            next->parent->lChild = next->rChild; // 直接后继有右子树
        }
        
        // 步骤三：重新建立新的关系
        // 重接建立直接后继与被删除结点双亲的亲子关系
        next->parent = parentOfDeleteNode;
        // 重新建立直接后继与被删除结点孩子的亲子关系
        next->lChild = deleteNode->lChild;
        next->rChild = deleteNode->rChild;
        
        // 步骤四：直接后继替换删除结点
        // 重接建立直接后继与被删除结点双亲的亲子关系
        if (parentOfDeleteNode->lChild == deleteNode) {
            parentOfDeleteNode->lChild = next; // 被删除结点是左孩子
        } else {
            parentOfDeleteNode->rChild = next; // 被删除结点是右孩子
        }
        
        // 步骤五：把结点删除
        delete deleteNode;
    }
}

/**
 被删除结点：
 - 是叶子结点
 - 是左结点或右结点
 */
void testDelete1() {
    int a[] = {62, 58, 88, 48, 73, 99, 35, 51, 93, 29, 37, 49, 56, 36, 50};
    int n = sizeof(a)/sizeof(a[0]);
    printArray(a, n);
    
    BST<int> *bst = new BST<int>();
    for (int i=0; i<n; ++i) {
        bst->insert(a[i]);
    }
    bst->inSort();
    
//    BSTNode<int> *node = bst->search(29); // 是左结点
    BSTNode<int> *node = bst->search(50); // 是右结点
    bst->deleteNode(node);
    
    cout << "\n---- 删除操作完成后 ----\n\n";
    bst->inSort();
}

/**
 被删除结点：
 - 只有右子树
 - 是根结点
 */
void testDelete2() {
    int a[] = {62, 88, 73, 99};
    int n = sizeof(a)/sizeof(a[0]);
    printArray(a, n);
    
    BST<int> *bst = new BST<int>();
    for (int i=0; i<n; ++i) {
        bst->insert(a[i]);
    }
    cout << "\n---- 插入操作完成后 ----\n\n";
    bst->inSort();
    
    BSTNode<int> *node = bst->search(62);
    bst->deleteNode(node);
    cout << "\n---- 删除操作完成后 ----\n\n";
    bst->inSort();
}

/**
 被删除结点：
 - 只有右子树
 - 不是根结点
 - 是左结点或右结点
 */
void testDelete3() {
    int a[] = {62, 58, 88, 48, 73, 99, 35, 51, 93, 29, 37, 49, 56, 36, 50, 57};
    int n = sizeof(a)/sizeof(a[0]);
    printArray(a, n);
    
    BST<int> *bst = new BST<int>();
    for (int i=0; i<n; ++i) {
        bst->insert(a[i]);
    }
    cout << "\n---- 插入操作完成后 ----\n\n";
    bst->inSort();
    
//    BSTNode<int> *node = bst->search(56); // 是右结点
    BSTNode<int> *node = bst->search(49); // 是左结点
    bst->deleteNode(node);
    
    cout << "\n---- 删除操作完成后 ----\n\n";
    bst->inSort();
}

/**
 被删除结点：
 - 只有左子树
 - 是根结点
 */
void testDelete4() {
    int a[] = {62, 58, 48, 35, 51};
    int n = sizeof(a)/sizeof(a[0]);
    printArray(a, n);
    
    BST<int> *bst = new BST<int>();
    for (int i=0; i<n; ++i) {
        bst->insert(a[i]);
    }
    cout << "\n---- 插入操作完成后 ----\n\n";
    bst->inSort();
    
    BSTNode<int> *node = bst->search(62);
    bst->deleteNode(node);
    
    cout << "\n---- 删除操作完成后 ----\n\n";
    bst->inSort();
}

/**
 被删除结点：
 - 只有左子树
 - 不是根结点
 - 是左结点或右结点
 */
void testDelete5() {
    int a[] = {62, 58, 88, 48, 73, 99, 35, 51, 93, 29, 37, 49, 56, 27, 36, 50, 57};
    int n = sizeof(a)/sizeof(a[0]);
    printArray(a, n);
    
    BST<int> *bst = new BST<int>();
    for (int i=0; i<n; ++i) {
        bst->insert(a[i]);
    }
    cout << "\n---- 插入操作完成后 ----\n\n";
    bst->inSort();
    
    BSTNode<int> *node = bst->search(29); // 是左结点
//    BSTNode<int> *node = bst->search(37); // 是右结点
    bst->deleteNode(node);
    
    cout << "\n---- 删除操作完成后 ----\n\n";
    bst->inSort();
}

/**
 被删除结点：
 - 既有左子树，又有右子树。
 - 直接后继是叶子结点或有右子树
 - 是左孩子或右孩子
 */
void testDelete6() {
    int a[] = {62, 58, 88, 47, 73, 99, 35, 51, 93, 29, 37, 49, 56, 36, 48, 50, 94};
    int n = sizeof(a)/sizeof(a[0]);
    printArray(a, n);
    
    BST<int> *bst = new BST<int>();
    for (int i=0; i<n; ++i) {
        bst->insert(a[i]);
    }
    cout << "\n---- 插入操作完成后 ----\n\n";
    bst->inSort();
    
//    BSTNode<int> *node = bst->search(47); // 直接后继是叶子结点，并且是左孩子。
//    BSTNode<int> *node = bst->search(51); // 直接后继是叶子结点，并且是右孩子
    BSTNode<int> *node = bst->search(88); // 直接后继有右子树
    bst->deleteNode(node);
    
    cout << "\n---- 删除操作完成后 ----\n\n";
    bst->inSort();
}
