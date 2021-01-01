#include<iostream>
using namespace std;

class Node
{
    public:
    int Data;
    Node *Next;
};

class Node_Fun
{
    public:
    Node *Head;
    Node_Fun()
    {
        Head = NULL;
    }
    void Insert_Last(int data)
    {
        Node *carry = nullptr;
        Node *t = Head;
        Node *NewNode = new Node();
        NewNode->Data = data;
        NewNode->Next = NULL;
        while(t != NULL)
        {
            if (data >= t->Data)
            {
                carry = t;
            }
            t = t->Next;
        }
        if(Head == NULL)
        {
            Head = NewNode;
        }
        else if(carry == NULL)
        {
            NewNode->Next = Head;
            Head = NewNode;
        }
        else if (carry->Next == NULL)
        {
            carry->Next = NewNode;
        }
        else if(carry->Next != NULL)
        {
            NewNode->Next = carry->Next;
            carry->Next = NewNode;
        }
        
    }
        void display()
    {
        Node *ptr;
        ptr = Head;
        while (ptr != NULL)
        {
            cout << ptr->Data << " ";
            ptr = ptr->Next;
        }
    }
};

int main()
{
    Node_Fun Obj;
    Obj.Insert_Last(-119);
    Obj.Insert_Last(0);
    Obj.Insert_Last(-1);
    Obj.Insert_Last(16);
    Obj.Insert_Last(1);
    Obj.display();
}