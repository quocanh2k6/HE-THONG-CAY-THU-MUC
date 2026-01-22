#include "DirectoryTree.h"

int main() {
    Node* root = new Node("root"); // Luôn bắt đầu từ thư mục gốc tên "root"
    int choice;
    string name, subName, newName;
    Node* foundNode = nullptr;

    do {
        cout << "\n--- HE THONG CAY THU MUC (NHOM 11) ---\n";
        cout << "1. Them thu muc con (Add)\n";
        cout << "2. Xoa thu muc (Delete)\n";
        cout << "3. Doi ten (Rename)\n";
        cout << "4. Tim kiem & In duong dan (Find Path)\n";
        cout << "5. Xem cac con (Print Children)\n";
        cout << "6. Luu & Xem file txt (Save)\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
            case 1: // Them
                cout << "Nhap ten thu muc Cha: "; cin >> name;
                foundNode = findDirectory(root, name);
                if (foundNode) {
                    cout << "Ten thu muc con moi: "; cin >> subName;
                    addChild(foundNode, subName);
                    cout << "-> Da them '" << subName << "' vao '" << name << "'.\n";
                } else cout << "-> Loi: Khong tim thay thu muc cha!\n";
                break;

            case 2: // Xoa (Cần nhập cha và tên con cần xóa)
                cout << "Nhap ten thu muc Cha: "; cin >> name;
                foundNode = findDirectory(root, name);
                if (foundNode) {
                    cout << "Nhap ten thu muc can xoa: "; cin >> subName;
                    removeChild(foundNode, subName);
                    cout << "-> Da thuc hien lenh xoa.\n";
                } else cout << "-> Loi: Khong tim thay thu muc cha!\n";
                break;

            case 3: // Doi ten
                cout << "Nhap ten thu muc can doi: "; cin >> name;
                foundNode = findDirectory(root, name);
                if (foundNode) {
                    cout << "Nhap ten moi: "; cin >> newName;
                    renameDirectory(foundNode, newName);
                    cout << "-> Da doi ten thanh cong.\n";
                } else cout << "-> Loi: Khong tim thay thu muc!\n";
                break;

            case 4: // Tim duong dan
                cout << "Tim thu muc: "; cin >> name;
                foundNode = findDirectory(root, name);
                if (foundNode) {
                    cout << "Duong dan: "; 
                    printPath(foundNode);
                } else cout << "-> Khong tim thay!\n";
                break;

            case 5: // Xem con
                cout << "Xem con cua thu muc: "; cin >> name;
                foundNode = findDirectory(root, name);
                if (foundNode) {
                    cout << "Danh sach con cua '" << name << "':\n";
                    printChildren(foundNode);
                } else cout << "-> Loi: Khong tim thay thu muc!\n";
                break;

            case 6: // Luu file
                saveTree(root, "CayThuMuc.txt");
                cout << "-> Da luu vao CayThuMuc.txt. Noi dung file:\n";
                printAllFromFile("CayThuMuc.txt");
                break;

            case 0:
                cout << "Ket thuc chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    return 0;
}