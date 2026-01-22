#ifndef DIRECTORY_TREE_H
#define DIRECTORY_TREE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Node;

// Cấu trúc DSLK để lưu danh sách các thư mục con
struct ChildNode {
    Node* data;
    ChildNode* next;
    ChildNode(Node* d) : data(d), next(nullptr) {}
};

// Cấu trúc một thư mục (Node)
struct Node {
    string name;
    Node* parent;
    ChildNode* childrenHead; // Đầu DSLK các con

    Node(string n, Node* p = nullptr) : name(n), parent(p), childrenHead(nullptr) {}
};

// --- Khai báo các hàm của 6 thành viên ---
void addChild(Node* parent, string name);            // Người 2
void saveTree(Node* root, string filename);          // Người 2
void removeChild(Node* parent, string name);         // Người 3
void renameDirectory(Node* node, string newName);    // Người 3
void printChildren(Node* parent);                    // Người 4
void printAllFromFile(string filename);              // Người 4
void printPath(Node* node);                          // Người 5
Node* findDirectory(Node* root, string name);        // Người 6

#endif