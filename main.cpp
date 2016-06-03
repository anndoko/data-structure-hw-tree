//
//  main.cpp
//  Tree
//
//  Created by Yu-An Ko on 2016/6/1.
//  Copyright © 2016年 Yu-An Ko. All rights reserved.
//
#include "oopTree.hpp"
#include <iostream>

int main() {
    
    int i;
    
    //  30% credit
    CompleteBinaryTree cbt(8);
    for(i=0;i<8;i++){
        cbt.Insert(i);
    }
    cbt.inorder();
    
    // 30% credit
    int d[8]={3, 7, 11, 6, 37, 28, 1, 4};
    BST bst;
    for (i=0;i<8;i++) bst.Insert(d[i]);
    bst.inorder();
    
    // 40% credit
    MaxHeap mh(8); int x;
    for(i=0;i<8;i++) mh.Insert(i);
    mh.inorder();
    
    cout << "MaxHeap DeleteMax" <<endl;
    for(int i=0;i<8;i++)  cout<< *mh.DeleteMax(x) <<" ";
    
    //  10% other tree you can implement from the lecture notes

    return 0;
}
