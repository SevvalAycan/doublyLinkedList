#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

class DLinkedList {

public:
    DLinkedList();
    ~DLinkedList();
    void addFront(int);
    void addTail(int);
    void addSecond(int);
    void removeFront();
    void removeTail();
    void removeAll();
    int getFront();
    int getTail();

private:
    Node* head;
    Node* tail;

};

DLinkedList::~DLinkedList() {

    head = NULL;
    tail = NULL;

}

void DLinkedList::addFront(int value) {

    Node* node = new Node();
    node->data = value;
    node->prev = NULL;

    if (head == NULL) {

        node->next = NULL;
        head = node;

    }
    else {

        node->next = head;
        head->prev = node;
        head = node;

    }

}

void DLinkedList::addTail(int value) {

    Node* node = new Node();
    node->data = value;
    node->next = NULL;

    if (head == NULL) {

        node->prev = NULL;
        tail = node;

    }
    else {

        node->prev = tail;
        tail->next = node;
        tail = node;

    }
}

void DLinkedList::addSecond(int value) {

    Node* node = new Node();
    node->data = value;
    if (head == NULL) {

        node->next = NULL;
        node->prev = NULL;
        head = node;
    }
    node = head;
    for (int i = 1; i <= 1; i++) {
        if (node != NULL) {
            node = node->next;
        }
    }
}
void DLinkedList::removeFront() {

    if (head == NULL) {

        cout << "This List is Empty!" << endl;

    }
    else {
        Node* temp = head;
        if (temp->prev == temp->next) {

            head = NULL;
            free(temp);

        }
        else {

            head = temp->next;
            head->prev = NULL;
            temp->next = NULL;

            free(temp);

        }

    }

}
void DLinkedList::removeTail() {

    if (head == NULL) {

        cout << "This List is Empty!" << endl;

    }
    else {
        Node* temp = head;
        if (temp->prev == temp->next) {

            head = NULL;
            free(temp);

        }
        else {
            while (temp->next != NULL) {

                temp = temp->next;
                temp->prev->next = NULL;
                free(temp);

            }

        }

    }
}

void DLinkedList::removeAll() {

    if (head == NULL) {

        cout << "This List has been empty already!" << endl;

    }
    else {
        Node* temp = head;
        if (temp->prev == temp->next) {

            head = NULL;
            free(temp);

        }
        while (head != NULL) {
            temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);

        }

    }

}

int DLinkedList::getFront() {


    int a = head->data;


    return a;

}

int DLinkedList::getTail() {

    int a = tail->data;


    return a;


}


int main() {

    DLinkedList* newList = new DLinkedList();
    newList->addFront(10);
    newList->addFront(20);
    newList->addFront(30);
    newList->addFront(40);
    newList->addFront(50);

    int choice, n;

    cout << "1-Add data front of the list \n" <<
        "2-Add data end of the list \n" <<
        "3-Add data second position of the list \n" <<
        "4-Remove data front of the list \n" <<
        "5-Remove data end of the list \n" <<
        "6-Remove all datas of the list \n" <<
        "7-Get the first data of the list \n" <<
        "8-Get the last data of the list \n" <<
        "Please enter your choice :";

    cin >> choice;

    switch (choice) {

    case 1:

        cout << "Enter data :";
        cin >> n;
        newList->addFront(n);
        cout << "Data was added!";
        break;

    case 2:

        cout << "Enter data :";
        cin >> n;
        newList->addTail(n);
        cout << "Data was added!";
        break;

    case 3:
        cout << "Enter data :";
        cin >> n;
        newList->addSecond(n);
        cout << "Data was added!";
        break;

    case 4:

        newList->removeFront();
        cout << "Data was removed!";
        break;

    case 5:

        newList->removeTail();
        cout << "Data was removed!";
        break;

    case 6:

        newList->removeAll();
        cout << "All datas were removed!";
        break;

    case 7:
        newList->getFront();
        cout << "The first data ";
        break;

    case 8:
        newList->getTail();
        cout << "The last data ";
        break;

    default:
        cout << "THIS CHOICE DOES NOT DECLARED!";
        break;
    }
    return 0;
}