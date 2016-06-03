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
        cout << CurrentNode->data << " ";
        inorder(CurrentNode->RightChild);
    }
}

void CompleteBinaryTree::Insert(int d){tree[++n] = d;}
void CompleteBinaryTree::inorder(){
    cout << "Inorder Traversal" <<endl;
    inorder(1);
    cout<<endl<<endl;
}
void CompleteBinaryTree::inorder(int current) {
    if(current <= n) {
        inorder(2*current);
        cout <<tree[current]<<" ";
        inorder(2*current+1);
    }
};

Boolean BST::Insert(const int d){   // insert int d into the BST
    
    /* this line is for testing purpose
    cout << "Do Boolean BST::Insert(const int d), insert: " << endl;
    */
    
    BinaryTreeNode *p = root;   // q is parent of p
    BinaryTreeNode *q = 0;
    
    while(p){
        q = p;
        
        if(d == p->data) return FALSE;  // d is already existing
        
        if(d < p->data) p = p->LeftChild;
        else p = p->RightChild;
    }
    
    //  perform insertion
    p = new BinaryTreeNode;
    p->LeftChild = p->RightChild = 0;
    p->data = d;
    if(!root) root = p;
    else if(d < q->data) q->LeftChild = p;
    else q->RightChild =p;
    
    return TRUE;
}

void MaxHeap::Insert(const int key){    // insert int key into the max heap
    
    /* this line is for testing purpose
    cout << "Do void MaxHeap::Insert(const int key), insert: " << key << endl;
    */
    
    int i;
    
    if(n == MaxSize){
        HeapFull();
        return;
    }
    
    n++;
    
    for(i = n; 1 ;){
        if(i == 1) break;   // at root
        if(key <= heap[i/2]) break;
        heap[i] = heap[i/2];    // move from parent to i
        i = i/2;
    }
    heap[i] = key;
}

int* MaxHeap::DeleteMax(int& x){ // remove x from the max heap
    
    /* this line is for testing purpose
    cout << "\nDo int* MaxHeap::DeleteMax(int& x), delete: ";
    */
    
    if(n == 0) {
        HeapEmpty();
        return 0;
    }
    
    x = heap[1]; int k = heap[n]; n--;
    
    int i = 1;  // i: vacant position
    int j = 2;  // j: larger child
    
    for(i; j <= n;){
        if(j < n) if(heap[j] < heap[j+1]) j++;
        if(k > heap[j]) break;
        heap[i] = heap[j]; // move the child up
        i=j; j*=2; // move i and j downward
    }
    heap[i]=k;
    return &x;
}


