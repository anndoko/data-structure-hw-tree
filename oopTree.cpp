//
//  oopTree.cpp
//  Tree
//
//  Created by Yu-An Ko on 2016/6/1.
//  Copyright © 2016年 Yu-An Ko. All rights reserved.
//
#include "oopTree.hpp"

void BinaryTree::inorder() {inorder(root);}
void BinaryTree::inorder(BinaryTreeNode *CurrentNode) {
    if(CurrentNode){
        inorder(CurrentNode->LeftChild);
        cout<<CurrentNode->data<<" ";
        inorder(CurrentNode->RightChild);
    }
}

void CompleteBinaryTree::Insert(int d){tree[++n]=d;}

void CompleteBinaryTree::inorder(){
    cout<<"Inorder Traversal"<<endl;
    inorder(1);
    cout<<endl<<endl;
}
void CompleteBinaryTree::inorder(int current) {
    if(current<=n) {
        inorder(2*current);
        cout <<tree[current]<<" ";
        inorder(2*current+1);
    }
};


void MaxHeap::Insert(const int key){
    //cout << "Do void MaxHeap::Insert(const int key), insert: " << key << endl;
    int i;
    
    if(n == MaxSize){HeapFull(); return;}
    n++;
    for(i = n; 1 ;){
        if(i == 1) break;
        if(key <= heap[i/2]) break;
        heap[i] = heap[i/2];
        i=i/2;
    }
    heap[i] = key;
}

// Delete from the max heap
int* MaxHeap::DeleteMax(int& x){
    //cout << "\nDo int* MaxHeap::DeleteMax(int& x), delete: ";
    if(n==0) {HeapEmpty(); return 0;}
    x = heap[1]; int k = heap[n]; n--;
    
    int i=1, j=2;
    
    for(i;j<=n;){
        if(j<n) if(heap[j] < heap[j+1]) j++;
        if(k>heap[j])break;
        heap[i] = heap[j];
        i=j; j*=2;
    }
    heap[i]=k;
    return &x;
}

Boolean BST::Insert(const int d){
    //cout << "Do Boolean BST::Insert(const int d), insert: " << endl;
    BinaryTreeNode *p = root; BinaryTreeNode *q = 0;
    while(p){
        q=p;
        if(d == p->data) return FALSE;
        if(d < p->data) p = p->LeftChild;
        else p = p->RightChild;
    }
    p = new BinaryTreeNode;
    p->LeftChild = p->RightChild = 0; p->data = d;
    if(!root) root = p;
    else if(d < q->data) q->LeftChild = p;
    else q->RightChild =p;
    
    return TRUE;
}
