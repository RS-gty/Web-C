//
// Created by ADMIN on 25-7-24.
//

#include "BinaryTree.h"

#include <iostream>
#include <utility>

void CreateBinaryTree(BinaryTree &Tree, string data) {
    Tree = new BinaryNode;
    Tree->data = std::move(data);
};
void GrowBinaryTree(BinaryTree &Tree, string data) {
    if (Tree->data < data and !(Tree->right)) {
        CreateBinaryTree(Tree->right, data);
    } else if (Tree->data > data and !(Tree->left)) {
        CreateBinaryTree(Tree->left, data);
    } else {
        if (Tree->data < data) {
            GrowBinaryTree(Tree->right, data);
        } else {
            GrowBinaryTree(Tree->left, data);
        }
    }
}
void AppendBinaryTree(BinaryTree &Tree, string data) {
    if (Tree->newly) {
        CreateBinaryTree(Tree, data);
        Tree->newly = false;
    } else {
        GrowBinaryTree(Tree, data);
    }
}
void PreOrderTraverse(BinaryTree Tree) {
    if (Tree) {
        cout << Tree->data << endl;
        PreOrderTraverse(Tree->left);
        PreOrderTraverse(Tree->right);
    }
}
void Find(BinaryTree Tree, const string &data) {
    if (Tree) {
        if (Tree->data == data) {
            if (Tree->is_deleted) {
                cout << "deleted" << endl;
            } else {
                cout << "found" << endl;
            }
        } else {
            if (Tree->left and data < Tree->data) {
                Find(Tree->left, data);
            } else if (Tree->right and data > Tree->data) {
                Find(Tree->right, data);
            } else {
            }
        }
    }
}

void DeleteData(BinaryTree Tree, const string &data) {
    if (Tree) {
        if (Tree->data == data) {
            Tree->is_deleted = true;
        } else {
            if (Tree->left and data < Tree->data) {
                DeleteData(Tree->left, data);
            } else if (Tree->right and data > Tree->data) {
                DeleteData(Tree->right, data);
            } else {
            }
        }
    }
}

BinaryTree SetBinaryTree(vector<string> v_data) {
    BinaryTree Tree = new BinaryNode();
    bool trigger = true;
    for (vector<string>::iterator iter = v_data.begin(); iter != v_data.end(); iter++) {
        AppendBinaryTree(Tree, *iter);
    }
    return Tree;
}

int FindAddress(BinaryTree Tree, const string &data) { return 0; }
