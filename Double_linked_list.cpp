#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(Node* n, Node* p, int d) : next(n), prev(p), data(d) { }

};

bool first = true;

class List {
public:
    Node* head = NULL;
    Node* tail = NULL;
    Node* front = NULL;
    Node* back = NULL;
    bool isEmpty = true;

    void add_end(int data) {
        Node* new_node = new Node(NULL, NULL, data);

        if (!head) {
            head = tail = new_node;
            tail->next = head;
            head->prev = tail;
        }
        else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
            tail->next = head;
            head->prev = tail;
        }
    }
    void add_beg(int data) {
        Node* new_node = new Node(NULL, NULL, data);
        if (!head) {
            head = tail = new_node;
            tail->next = head;
            head->prev = tail;
        }
        else {
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
            tail->next = head;
            head->prev = tail;
        }
    }
    void push(int data) {
        Node* new_node = new Node(NULL, NULL, data);

        if (!head) {
            head = tail = new_node;
            front = back = head;
        }
        else if (head && !front) {
            if (size() != count()) {
                tail->data = data;
                front = back = tail;
            }
            else {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
                front = back = head;
            }
        }
        else {
            if (size() != count()) {
                if (back != head && front != tail && back->prev == front) {
                    Node* tmp = back->prev;
                    tmp->next = new_node;
                    back->prev = new_node;
                    new_node->next = back;
                    new_node->prev = tmp;
                    back = new_node;

                    back->prev = front;
                }
                else {
                    back->prev->data = data;
                    back = back->prev;
                }
            }
            else {
                if (back != head && front!=tail && back->prev == front) {
                    Node* tmp = back->prev;
                    tmp->next = new_node;
                    back->prev = new_node;
                    new_node->next = back;
                    new_node->prev = tmp;
                    back = new_node;
                   
                    back->prev = front;
                }
                else {
                    head->prev = NULL;
                    head->prev = new_node;
                    new_node->next = head;
                    head = new_node;
                    tail->next = head;
                    head->prev = tail;

                    back = new_node;
                    back->prev = front;
                }
            }
        }
    }
    int size() {
        if (!head) {
            return 0;
        }
        Node* tmp = head;
        int ile = 1;
        if (tmp == tail) {
            return ile;
        }
        else {
            while (tmp->next != tail) {
                tmp = tmp->next;
                ile++;
            }
            ile++;
            return ile;
        }
    }
    int count() {
        if (!front) {
            return 0;
        }     
        Node* tmp = front;
        int ile = 1;
        if (tmp == back) {
            return ile;
        }
        else {
            while (tmp->prev != back) {
                tmp = tmp->prev;
                ile++;
            }
            ile++;
            return ile;
        }
    }
    void print_for() {
        if (head) {
            Node* tmp = head;
            while (tmp != tail) {
                printf("%d ", tmp->data);
                tmp = tmp->next;
            }
            printf("%d\n", tail->data);

        }
        else
            printf("NULL\n");

    }
    void print_back() {
        if (tail) {
            Node* tmp = tail;
            while (tmp != head) {
                printf("%d ", tmp->data);
                tmp = tmp->prev;
            }
            printf("%d\n", tmp->data);

        }
        else
            printf("NULL\n");

    }
    void print_queue() {
        if (front) {
            Node* tmp = front;
            while (tmp != back) {
                printf("%d ", tmp->data);
                tmp = tmp->prev;
            }
            printf("%d\n", back->data);

        }
        else
            printf("NULL\n");
    }
    void pop() {
        if (front) {
            if (front == back) {
                printf("%d\n", front->data);
                front = back = NULL;
                isEmpty = true;
            }
            else {
                printf("%d\n", front->data);
                front = front->prev;
            }
        }
        else
            printf("NULL\n");
    }
    void del_end() {
        if (tail) {
            if (tail != back) {
                Node* tmp = tail;
                if (head == tail) {
                    head = NULL;
                    tail = NULL;
                }
                else
                    tail = tail->prev;
                free(tmp);
                tail->next = head;
                head->prev = tail;
            }
            else {
                Node* tmp = tail;
                Node* temp = front;
                if (head == tail) {
                    head = front = NULL;
                    tail = back = NULL;
                }
                else {
                    tail = tail->prev;
                    while(temp->prev!=back)
                    temp = temp->prev;
                    back = temp;
                }
                free(tmp);
                tail->next = head;
                head->prev = tail;
                back->prev = front;
            }
        }
    }
    void del_beg() {
        if (head) {
            if (head != front) {
                Node* tmp = head;
                
                if (head == tail) {
                    head = back = NULL;
                    tail = tail = NULL;
                }
                else if (head == back) {
                    head = head->next;
                    Node* temp = front;
                    while (temp->prev != back)
                        temp = temp->prev;
                    back = temp;
                }
                else
                    head = head->next;
                free(tmp);
                head->prev = tail;
                tail->next = head;
                back->prev = front;
            }
        }
    }
    
    void garbage_soft() {
        if (head) {
            if (front) {
                Node* tmp = front->next;
                while (tmp->next != back->next) {
                    tmp->data = 0;
                    tmp = tmp->next;
                }
            }
            else {
                Node* tmp = head;
                while (tmp->next != tail) {
                    tmp->data = 0;
                    tmp = tmp->next;
                }
                    tmp->data = 0;
            }
            
        }
    }
    void garbage_hard() {
        if (head) {
            if (front) {
                
                Node* tmp = front->next;
                Node* temp = front->next;
                Node* actual = front;
                if (head == tail) {
                    if (head == front)
                        return;
                    else {
                        head = NULL;
                        tail = NULL;
                        free(temp);
                        return;
                    }
                }
                else {

                    while (tmp->next != back->next) {
                        temp = tmp;
                        tmp = tmp->next;
                        if (temp == tail)
                            tail = tail->prev;
                        else if (temp == head)
                            head = head->next;
                        free(temp);
                    }
                    actual->next = tmp;
                }            
            }
            else {
                Node* tmp = head;
                Node* temp = head;
                if (head == tail) {
                    head = NULL;
                    tail = NULL;
                    free(temp);
                    return;
                }
                while (tmp->next != tail) {
                    temp = tmp;
                    tmp = tmp->next;
                    if (temp == tail)
                        tail = tail->prev;
                    else if (temp == head)
                        head = head->next;
                    free(temp);
                }
                tmp->data = 0;
            }

        }
    }
};

int main()
{

    List list;
    char cmd[20];
    int number = 0;

    while (scanf("%s", &cmd) > 0) {

        if (strcmp(cmd, "ADD_BEG") == 0) {
            scanf("%d", &number);
            list.add_beg(number);
        }
        else if (strcmp(cmd, "ADD_END") == 0) {
            scanf("%d", &number);
            list.add_end(number);
        }
        else if (strcmp(cmd, "PRINT_FORWARD") == 0) {
            list.print_for();
        }
        else if (strcmp(cmd, "PRINT_BACKWARD") == 0) {
            list.print_back();
        }
        else if (strcmp(cmd, "SIZE") == 0) {
            printf("%d\n",list.size());
        }
        else if (strcmp(cmd, "DEL_BEG") == 0)

            list.del_beg();
        else if (strcmp(cmd, "DEL_END") == 0)
            list.del_end();
        else if (strcmp(cmd, "PUSH") == 0) {
            scanf("%d", &number);
            list.push(number);
        }
        else if (strcmp(cmd, "POP") == 0) {
            list.pop();
        }
        else if (strcmp(cmd, "COUNT") == 0)
           printf("%d\n", list.count());
        else if (strcmp(cmd, "PRINT_QUEUE") == 0) {
            list.print_queue();
        }
        else if (strcmp(cmd, "GARBAGE_SOFT") == 0)
            list.garbage_soft();
        else if (strcmp(cmd, "GARBAGE_HARD") == 0)
            list.garbage_hard();
    }

    return 0;

}