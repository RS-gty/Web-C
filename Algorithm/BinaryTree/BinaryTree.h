//
// Created by ADMIN on 25-7-24.
//

#ifndef WEB_BINARYTREE_H
#define WEB_BINARYTREE_H

#include <string>
#include <vector>

using namespace std;


typedef struct node {
    string data;
    node *left, *right;
    bool is_deleted = false;
    bool newly = true;
} *BinaryTree, BinaryNode;

void CreateBinaryTree(BinaryTree &Tree, string data);
void GrowBinaryTree(BinaryTree &Tree, string data);
void PreOrderTraverse(BinaryTree Tree);
void Find(BinaryTree Tree, const string &data);
void DeleteData(BinaryTree Tree, const string &data);

BinaryTree SetBinaryTree(vector<string> v_data);
int FindAddress(BinaryTree Tree, const string &data);

#endif//WEB_BINARYTREE_H
