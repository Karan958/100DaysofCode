#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}



SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
SinglyLinkedListNode *k, *temp;
k=llist;
if(k==nullptr || (llist->next==nullptr && position == 0))
return  nullptr;
else if (position == 0) {
k=k->next;
delete llist;
return k;
}
else{
    int c=0;
    while (c<position-1) {
    k=k->next;
    c++;
    }
    if(k->next->next == nullptr){
        k->next=nullptr;
    }
    else {
        temp = k->next->next;
        delete k->next;
        k->next=temp;
    }
    return llist;
}

}

int main()
