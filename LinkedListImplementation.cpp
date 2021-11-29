#include <iostream>
using namespace std;
template <typename T>
class DAS
{
private:
    // A linked list node
    struct Node
    {
        T data;
        struct Node *next;
    };

public:
    struct Node *head;
    void DAS_init()
    {
        struct Node *head = NULL;
    }
    //append an element to the existing container from the front
    void push(struct Node **head, T val) //insert at the beginning
    {
        struct Node *newNode = new Node; //create and allocate node
        newNode->data = val;
        newNode->next = (*head);
        (*head) = newNode;
        cout << "value added at the begining is " << val << endl;
    }
    //remove the element from the front of the containe
    void pop(struct Node **head)
    {
        (*head) = (*head)->next; //go to the next node
        cout << "remember to free up the first node memory later" << endl;
    }

    void print_data(struct Node *node)
    {
        //traverse the list to display each node
        while (node != NULL)
        {
            cout << node->data << "-->";
            node = node->next;
        }
        cout << "NULL" << endl;
    }

    void rear_pointer(struct Node *node)
    {
        while (node != NULL)
            node = node->next;

        cout << "rear pointer is:  " << node << endl;
    }
};

int main()
{
    int x[] = {1, 2, 3, 4, 5};
    //Using template as int
    DAS<int> obj1;
    obj1.head = NULL;

    //using template as float
    DAS<float> obj2;
    obj2.head = NULL;

    //append an element to the existing container from the front
    obj1.push(&obj1.head, 1);
    obj1.print_data(obj1.head);

    obj1.push(&obj1.head, 2);
    obj1.print_data(obj1.head);

    //push float value
    obj2.push(&obj2.head, 3.5);
    obj2.print_data(obj2.head);

    obj2.push(&obj2.head, 4.5);
    obj2.print_data(obj2.head);

    //remove the element from the front of the container
    obj1.pop(&obj1.head);
    obj1.print_data(obj1.head);

    obj1.pop(&obj1.head);
    obj1.print_data(obj1.head);

    //return a pointer to the element at the front of the container
    //int *front = obj1.head;
    cout << "Front pointer is  " << obj1.head << endl;

    //return a pointer to the element at the back of the container
    obj1.rear_pointer(obj1.head);

    return 0;
}