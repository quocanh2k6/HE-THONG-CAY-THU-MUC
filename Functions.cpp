#include "DirectoryTree.h"

// Người 2: Tạo thư mục và Lưu file
void addChild(Node* parent, string name) {
    if (!parent) return;
    Node* newNode = new Node(name, parent);
    ChildNode* newChild = new ChildNode(newNode);
    if (!parent->childrenHead) parent->childrenHead = newChild;
    else {
        ChildNode* temp = parent->childrenHead;
        while (temp->next) temp = temp->next;
        temp->next = newChild;
    }
}

void saveToFileRecursive(Node* node, ofstream& file, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; i++) file << "  ";
    file << node->name << endl;
    ChildNode* temp = node->childrenHead;
    while (temp) {
        saveToFileRecursive(temp->data, file, depth + 1);
        temp = temp->next;
    }
}

void saveTree(Node* root, string filename) {
    ofstream file(filename);
    if (file.is_open()) { saveToFileRecursive(root, file, 0); file.close(); }
}

// Người 3: Xóa và Đổi tên
void deleteNodeRecursive(Node* node) {
    if (!node) return;
    ChildNode* curr = node->childrenHead;
    while (curr) {
        ChildNode* next = curr->next;
        deleteNodeRecursive(curr->data);
        delete curr;
        curr = next;
    }
    delete node;
}

void removeChild(Node* parent, string name) {
    if (!parent || !parent->childrenHead) return;
    ChildNode *curr = parent->childrenHead, *prev = nullptr;
    while (curr && curr->data->name != name) { prev = curr; curr = curr->next; }
    if (curr) {
        if (prev) prev->next = curr->next;
        else parent->childrenHead = curr->next;
        deleteNodeRecursive(curr->data);
        delete curr;
    }
}

void renameDirectory(Node* node, string newName) { if (node) node->name = newName; }

// Người 4: In danh sách con & Đọc file
void printChildren(Node* parent) {
    if (!parent || !parent->childrenHead) { cout << "Thu muc rong.\n"; return; }
    ChildNode* temp = parent->childrenHead;
    while (temp) { cout << "- " << temp->data->name << "\n"; temp = temp->next; }
}

void printAllFromFile(string filename) {
    ifstream file(filename); string line;
    while (getline(file, line)) cout << line << endl;
}

// Người 5: Truy ngược đường dẫn về Root
void printPath(Node* node) {
    if (!node) return;
    vector<string> path;
    Node* temp = node;
    while (temp) { path.push_back(temp->name); temp = temp->parent; }
    reverse(path.begin(), path.end());
    for (size_t i = 0; i < path.size(); i++) cout << path[i] << (i == path.size() - 1 ? "" : " / ");
    cout << endl;
}

// Người 6: Tìm kiếm thư mục
Node* findDirectory(Node* root, string name) {
    if (!root) return nullptr;
    if (root->name == name) return root;
    ChildNode* temp = root->childrenHead;
    while (temp) {
        Node* found = findDirectory(temp->data, name);
        if (found) return found;
        temp = temp->next;
    }
    return nullptr;
}