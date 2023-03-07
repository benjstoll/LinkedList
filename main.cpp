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


// Reverse a linked list my creating a new one from an already existing list.
Node* reverse_list(Node* node) {
    Node* new_head = new Node(node->data);

    while (node->next != NULL) {
        push_node(node->next->data, &new_head);
        node = node->next;
    }

    return new_head;
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

    cout << "### Regular Traversal ###" << endl;
    traverse_list(head);


    // Reverse a linked list
    cout << endl << "### Reversed Traversal ###" << endl;
    Node* reversed_head = reverse_list(head);
    traverse_list(reversed_head);

    return 0;
}


