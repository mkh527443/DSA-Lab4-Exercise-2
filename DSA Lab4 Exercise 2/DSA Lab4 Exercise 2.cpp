#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CList {
private:
    Node* head;

public:
    CList() {
        head = NULL;
    }

    void Insert_Begin(int Value) {
        Node* temp = new Node;
        temp->data = Value;

        if (head == NULL) {
            head = temp;
            temp->next = head;
        }
        else {
            Node* p = head;
            while (p->next != head) {
                p = p->next;
            }
            p->next = temp;
            temp->next = head;
            head = temp;
        }
    }

    void Insert_End(int Value) {
        Node* temp = new Node;
        temp->data = Value;

        if (head == NULL) {
            head = temp;
            temp->next = head;
        }
        else {
            Node* p = head;
            while (p->next != head) {
                p = p->next;
            }
            p->next = temp;
            temp->next = head;
        }
    }

    void Insert_After(int pos, int value) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        do {
            if (temp->data == pos) {
                Node* newNode = new Node;
                newNode->data = value;
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Node not found!" << endl;
    }

    void Delete_Node(int pos)
    {
        Node* temp = head, * t = NULL;
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
        }
        else {
            if (head->data == pos)
            {
                do {
                    t = temp;
                    temp = temp->next;
                } while (temp != head);
                head = head->next;
                delete temp;
                t->next = head;
            }
            else {
                do {
                    t = temp;
                    temp = temp->next;
                } while (temp->data != pos && temp != head);
                if (temp != head) {
                    t->next = temp->next;
                    delete temp;
                }
                else {
                    cout << "Node not found!" << endl;
                }
            }
        }

    }

    void Delete_Begin() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        if (temp->next == head) {
            delete head;
            head = NULL;
        }
        else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
            delete temp;
        }
    }

    void Delete_End() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        if (temp->next == head) {
            delete head;
            head = NULL;
        }
        else {
            Node* prev = NULL;
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            delete temp;
        }
    }

    void traverse() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        cout << "List is: " << endl;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CList li;
    li.Insert_Begin(10);
    li.Insert_Begin(20);
    li.Insert_Begin(30);
    li.Insert_Begin(40);
    li.Insert_End(50);
    li.Insert_End(60);
    li.Insert_After(50, 70);
    li.traverse();
    li.Delete_Begin();
    li.traverse();
    li.Delete_End();
    li.traverse();

    return 0;
}
