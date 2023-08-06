#include <bits/stdc++.h>

using namespace std;

class Node {

    public:
        int data;
        Node *next;

        Node (int data) {
            this->data = data;
            this->next = NULL;
        }
};

class LList {


    public:
        Node *head, *tail;

        LList() {
            this->head = NULL;
            this->tail = NULL;
        };

        bool isEmpty() {
            return (this->head == NULL);
        }

        int size() {
            int count = 0;
            Node *ptr = this->head;
            while (ptr != NULL) {
                count++;
                ptr = ptr->next;
            }
            return count;
        }

        void print_list() {
            cout << endl << "List : ";
            if (this->isEmpty()) {

                cout << "Empty" << endl << endl;
                return;
            }
            Node *ptr = this->head;
            while (ptr->next != NULL) {
                cout << ptr->data << " -> ";
                ptr = ptr->next;
            }
            cout << ptr->data << endl << endl;
        }

        void push_front(int d) {
            Node *add = new Node(d);
            add->next = this->head;
            this->head=add;
            cout << endl << "Inserted " << d << " at head." << endl;
        }

        void push_back(int d) {
            Node *add = new Node(d);
            if (this->isEmpty()) {
                this->head = add;
            } else {
                Node *ptr = this->head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = add;
            }

            cout << endl << "Inserted " << d << " at tail." << endl;
        }


};

int main()
{
    LList l1;

    l1.push_back(100);
    l1.push_front(200);

    cout << "List Size : " << l1.size() << endl;

    l1.print_list();

    return 0;
}

// 40 0 893 166 16 729 551 296 361 478 304 301 920 676 675 828 324 888 959 409 548 785 377 317 824 121 596 677 779 863 929 433 206 555 906 705 184 749 47 417 415 683
