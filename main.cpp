//
//  main.cpp
//  pro1
//
//  Created by el1ven on 14-6-6.
//  Copyright (c) 2014年 el1ven. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>

/*已知前序和中序，求出后序遍历*/
/*重点思路：找到左右子树在原数组的位置，就是pos变量*/

using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

void rebuildTree(Node* &T, int preOrder[], int midOrder[]);
void postTraverse(Node* &T);

int main(){
    int lenth = 0;//输入的元素个数
    while(cin>>lenth){
        int preOrder[100] = {};//初始化前序序列
        int midOrder[100] = {};//初始化中序序列
        int postOrder[100] = {};//初始化后序序列
        for(int i = 0; i < lenth; i++){
            cin>>preOrder[i];//前序输入
        }
        for(int j = 0; j < lenth; j++){
            cin>>midOrder[j];//中序输入
        }
        
        Node *T = new Node;
        
        rebuildTree(T, preOrder, midOrder);
        
        postTraverse(T);
    }
    
    return 0;
}

void rebuildTree(Node* &T, int preOrder[], int midOrder[]){
    //初始化根节点
    int lenth = 0;
    while(preOrder[lenth]!='\0'){
        lenth++;
    }

    T = new Node;
    T->data = preOrder[0];//前序的第一个数据为根节点
    T->left = NULL;
    T->right = NULL;

    if(lenth > 1){
        //寻找根节点在中序遍历中的位置
        int pos = 0;
        for(int i = 0 ; i < lenth; i++){
            if(midOrder[i] == T->data){
                pos = i;
                break;
            }
        }
        
        //左子树重建
        int preLeft[100] = {};
        int midLeft[100] = {};
        for(int j = 1; j <= pos; j++){
            preLeft[j-1] = preOrder[j];
        }
        for(int k = 0; k <= pos; k++){
            midLeft[k] = midOrder[k];
        }
        Node *t1 = new Node;
        rebuildTree(t1, preLeft, midLeft);
        T->left = t1;
        
        //右子树重建
        int preRight[100] = {};
        int midRight[100] = {};
        for(int j = pos+1; j<lenth; j++){
            int count1 = 0;
            preRight[count1] = preOrder[j];
            count1++;
        }
        for(int k = pos+1; k<lenth; k++){
            int count2 = 0;
            midRight[count2] = midOrder[k];
            count2++;
        }
        Node *t2 = new Node;
        rebuildTree(t2, preRight, midRight);
        T->right = t2;
    }
    
}

void postTraverse(Node* &T){//后序遍历输出
    if(T->left != NULL)postTraverse(T->left);
    if(T->right != NULL)postTraverse(T->right);
    cout<<T->data<<" ";
}





