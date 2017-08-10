// 该程序实现了二叉查找树的基本操作，包括搜索、插入和删除操作
// 没有去实现avl树，所以效率可能不会很高
// 另外为了验证算法，还写了一个递归的中序遍历

#include <iostream>
using namespace std;

typedef struct BSTNode {
    int data;
    BSTNode *lchild, *rchild;
}BSTNode;

bool SearchBST(BSTNode *root, int key, BSTNode *father, BSTNode **point) {
    if (!root) {
        *point = father;
        return false;
    }
    else if( key == root->data ) {
        *point = root;
        return true;
    }
    else if( key < root->data ) {
        return SearchBST(root->lchild, key, root, point);
    }
    else {
        return SearchBST(root->rchild, key, root, point);
    }
}

bool InsertBST(BSTNode **root, int key) {
    BSTNode *point;
    BSTNode *insert;
    if (!SearchBST(*root, key, NULL, &point)) {
        insert = new BSTNode;
        insert->data = key;
        insert->lchild = insert->rchild = NULL;
        if (!point)
            *root = insert;
        else if(key < point->data)
            point->lchild = insert;
        else
            point->rchild = insert;
        return true;
    }
    else
        return false;

}


bool DeletePoint(BSTNode **point) {
    BSTNode *q;
    BSTNode *s;
    if ((*point)->rchild == NULL)   // 第一种情况是没有右孩子，左孩子接替位置
    {
        q = *point;
        *point = (*point)->lchild;
        delete(q);
    }
    else if( (*point)->lchild == NULL) // 第二种情况是没有左孩子，右孩子接替位置
    {
        q = *point;
        *point = (*point)->rchild;
        delete(q);
    }
    else    // 左右子树都不为空，找直接前驱接替位置
    {
        q = *point;
        s = (*point)->lchild;
        while (s->rchild)   // 先找左孩子，然后一直找左孩子的右孩子，直到尽头
        {
            q = s;
            s = s->rchild;
        }
        (*point)->data = s->data;   // 这个找到的孩子就是直接前驱，将直接前驱替代原来的位置
        if (q != *point)    // 如果当初被删除节点的左孩子有右孩子，就将直接前驱的左孩子作为直接前驱父节点的右孩子
            q->rchild = s->lchild;
        else
            q->lchild = s->lchild;
        delete(s);
    }
    return true;
}

bool DeleteBST(BSTNode **root, int key) {
    if (!*root) {
        return false;
    }
    else {
        if (key == (*root)->data)
            return DeletePoint(root);
        else if(key < (*root)->data)
            return DeleteBST(&((*root)->lchild), key);
        else if(key > (*root)->data)
            return DeleteBST(&((*root)->rchild), key);
    }
}

void ConstructBST(int* list, int length, BSTNode **root) {
    if (list == NULL || length <= 0) {
        *root = NULL;
        return;
    }

    for (int i = 0; i < length; i++) {
        InsertBST(root, list[i]);
    }
}

void InOrderTraverse(BSTNode *root)
{
    if (root == NULL)
        return;
    InOrderTraverse(root->lchild);
    cout << " " << root->data;
    InOrderTraverse(root->rchild);
}

int main() {
    int list[] = {12, 56, 34, 76, 45, 77, 91, 36};
    int length = sizeof(list) / sizeof(int);
    BSTNode * rootOfTree = NULL;
    ConstructBST(list, length, &rootOfTree);
    InOrderTraverse(rootOfTree);
    cout << endl;
    DeleteBST(&rootOfTree, 36);
    InOrderTraverse(rootOfTree);
    return 0;
}