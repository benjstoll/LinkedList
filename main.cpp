#include <iostream>
using namespace std;


// Node data structure.
struct Node {
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};


// Traverse through a list and print the data value of each node.
void traverse_list(Node* node) {
    cout << "Current Node: " << node->data << endl;
    // cout << "Next Node: " << node->next->data << endl;

    if (node->next != NULL) {
        traverse_list(node->next);
    }
}


// Append node at the end of the list.
void append_node(int data, Node** head) {
    Node* last = *head;
    while (last->next != NULL) { last = last->next; }

    Node* new_node = new Node(data);
    last->next = new_node;
}


// push node into the front of the list.
void push_node(int data, Node** head) {
    Node* new_node = new Node(data);

    new_node->next = *head;
    *head = new_node;
}


int main() {
    // Create initial head for list
    Node* head = new Node(1);

    //Test push function
    push_node(5, &head);
    push_node(10, &head);
    push_node(9, &head);


    // Test append function
    append_node(25, &head);
    append_node(4, &head);
    append_node(25, &head);
    append_node(4, &head);

    traverse_list(head);

    return 0;
}


