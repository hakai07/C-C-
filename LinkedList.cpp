#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class LinkedList
{
private:
    struct node *head;
    int listSize;

    void printLinkedList(struct node *ptr)
    {
        if (ptr == NULL)
            return;
        cout << endl
             << ptr->data;
        printLinkedList(ptr->next);
    }

    struct node *findNode(struct node *ptr, int number, struct node *prevNode)
    {
        if (ptr == NULL)
            return NULL;
        if (ptr->data == number)
            return prevNode;
        return findNode(ptr->next, number, ptr);
    }

    struct node *addLast(int number, struct node *ptr)
    {
        if (ptr->next == NULL)
        {
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = number;
            newNode->next = NULL;
            ptr->next = newNode;
            return ptr;
        }
        return addLast(number, ptr->next);
    }

    int removeLast(struct node *ptr, struct node *prevNode)
    {
        if (ptr->next == NULL)
        {
            int value = ptr->data;
            prevNode->next = NULL;
            free(ptr);
            return value;
        }
        return removeLast(ptr->next, ptr);
    }

public:
    LinkedList()
    {
        head = NULL;
        listSize = 0;
    }

    int addFirst(int number)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = number;
        newNode->next = head;
        head = newNode;
        listSize++;
        return number;
    }

    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }

    int add(int number)
    {
        struct node *ptr = head;
        if (isEmpty())
            addFirst(number);
        else
        {
            listSize++;
            addLast(number, ptr);
        }
        return number;
    }

    int size()
    {
        return listSize;
    }

    void printAll()
    {
        printLinkedList(head);
    }

    int removeFirst()
    {
        if (isEmpty())
            return -1;
        int number = head->data;
        struct node *temp = head;
        head = head->next;
        listSize--;
        free(temp);
        return number;
    }

    bool contains(int number)
    {
        if (isEmpty())
            return false;
        if (head->data == number)
            return true;
        if (findNode(head->next, number, head) == NULL)
            return false;
        return true;
    }

    int pop()
    {
        if (isEmpty())
            return -1;
        if (head->next == NULL)
            return removeFirst();
        listSize--;
        return removeLast(head->next, head);
    }
};
int main()
{
    cout << "This is linked list program";
    LinkedList list;
    list.add(10);
    list.add(29);
    list.add(49);
    list.add(39);
    list.printAll();
    list.pop();
    list.removeFirst();
    cout << "\nAfter poppping and removing first element";
    list.printAll();
    list.addFirst(35);
    cout << "\nAfter adding first";
    list.printAll();
    cout << "\nContais 10 => " << list.contains(10);
    cout << "\n Size of the list is => " << list.size();
    return 1;
}