#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Menambah data baru
void insertNode(Node*& head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Mencetak data
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " "; 
        current = current->next;
    }
    cout << endl; 
}

// Menghapus data
void delNode(Node*& head, int targetHapus) {
    if (head == nullptr) {
        return; // Menandakan linked list kosong
    }
    if (head->data == targetHapus) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* current = head;
    while (current->next != nullptr && current->next->data != targetHapus) {
        current = current->next;
    }
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    int menu, data;

    do {
        cout << "Menu:" << endl; 
        cout << "1. Masukkan Data" << endl; 
        cout << "2. Hapus Data" << endl; 
        cout << "3. Cetak Data" << endl; 
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                insertNode(head, data);
                break;
            case 2:
                cout << "Masukkan nilai data yang ingin dihapus: ";
                cin >> data;
                delNode(head, data);
                break;
            case 3:
                cout << "Linked List: ";
                printList(head);
                break;
            case 4:
                cout << "Program selesai." << endl; 
                break;
            default:
                cout << "Pilihan menu adalah 1-4." << endl; 
                break;
        }
    } while (menu != 4);

    // Membersihkan memori
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
