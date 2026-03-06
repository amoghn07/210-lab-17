#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void addNode(Node *&, Node *, int);
void deleteNode(Node*&, Node *&, Node *, int);
void insertNode(Node*&, Node *&, Node *&, int);
void deleteList(Node *&, Node *&);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        addNode(head, newVal, tmp_val);
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion
    deleteNode(head, current, prev, entry);
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    insertNode(head, current, prev, entry);
    output(head);

    // deleting the linked list
    deleteList(head, current);

    return 0;
}

void insertNode(Node*& head, Node *& current, Node *& prev, int entry){
    current = head;
    prev = nullptr;  // reset prev to nullptr for same reason

    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr) {
        // inserting before the head
        head = newnode;
    } else {
        prev->next = newnode;
    }
}

void deleteList(Node *& head, Node *& current){
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);
}

void deleteNode(Node *& head, Node *& current, Node *prev, int entry){

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
    }

    // at this point, delete current and reroute pointers
    if (current) {
        if (prev == nullptr) {
            // deleting the head node
            head = current->next;
        } 
        else {
            prev->next = current->next;
        }

        delete current;
        current = nullptr;
    }
}

void addNode(Node *&hd, Node *nw, int val){
    if (!hd) {
        hd = nw;
        nw->next = nullptr;
        nw->value = val;
    }
    else {
        nw->next = hd;
        nw->value = val;
        hd = nw;
    }
}

void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}