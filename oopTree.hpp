//
//  oopTree.hpp
//  Tree
//
//  Created by Yu-An Ko on 2016/6/1.
//  Copyright © 2016年 Yu-An Ko. All rights reserved.
//
#ifndef oopTree_hpp
#define oopTree_hpp
#include <stdio.h>
#include <iostream>
using namespace std;
enum Boolean {FALSE,TRUE};
const int DefaultSize=20;

class MaxPQ{
public:
    virtual void Insert(const int) = 0;// pure virtual function
    virtual int *DeleteMax(int&) = 0;
};

class SearchStruct{
public:
    virtual Boolean Insert(const int) = 0; // pure virtual functions
    virtual int* Delete(int &) = 0;
    virtual Boolean Search(const int) = 0;
};

class BinaryTree {
public:
    virtual void inorder(); // driver
    BinaryTree(){root = 0;} // constructor
protected:
    class BinaryTreeNode{ // nested class
    public:
        int data;
        BinaryTreeNode *LeftChild;
        BinaryTreeNode *RightChild;
    };
    BinaryTreeNode *root;
    virtual void inorder(BinaryTreeNode *);
};

class BST:public SearchStruct, public BinaryTree{
    //multiple inheritance
public:
    BST() {root = 0;};
    Boolean Insert(const int);
    int* Delete(int&){return 0;};
    Boolean Search(const int) {return TRUE;};
};

class CompleteBinaryTree:public BinaryTree{
public:
    virtual void inorder(); // driver
    CompleteBinaryTree(int sz=DefaultSize):MaxSize(sz), n(0){
        tree = new int[MaxSize+1];
        cout <<"Complete Binary Tree"<<endl;
    };
    void Insert(int);
protected:
    int *tree, MaxSize, n;
    virtual void inorder(int); // hides BinaryTree::inorder(BinaryTreeNode*)
};

class MaxHeap:public MaxPQ, public CompleteBinaryTree{
    // multiple inheritance
public:
    MaxHeap(int sz=DefaultSize):CompleteBinaryTree(sz+1){
        heap=tree;
        cout <<"MaxHeap"<<endl;
    };
    virtual void Insert(const int);
    virtual int *DeleteMax(int&) ;
    int *heap;
    void HeapEmpty(){cout <<"The heap is empty"<<endl;}
    void HeapFull(){cout <<"The heap is full"<<endl;}; // heap is full
};

class WinnerTree:public CompleteBinaryTree{
public:
    WinnerTree(int sz=DefaultSize):CompleteBinaryTree(sz){};
};

#endif /* oopTree_hpp */
