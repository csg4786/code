class Node {

    int data;
    Node *next;

    public:

        int getData() {
            return this->data;
        }

        void setData(int data) {
            this->data = data;
        }

        Node* getNext() {
            return this->next;
        }

        void setNext(Node *next) {
            this->next = next;
        }

        Node (int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class List {

    Node *head, *tail;
    
    public:

        Node* begin() {
            return this->head;
        }

        Node* end() {
            return this->tail;
        }

        List() {
            this->head = nullptr;
            this->tail = nullptr;
        };

        int size() {
            int count = 0;
            Node *ptr = this->head;
            while (ptr->getNext() != nullptr) {
                count++;
                ptr = ptr->getNext();
            }
            return count;
        }

};