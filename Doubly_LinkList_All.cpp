#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

class Link_List
{
public:
    Node *head = NULL;
    void insertLast(int newdata)
    {
        Node *NewNode, *t;
        NewNode = (Node *)malloc(sizeof(Node));
        NewNode->data = newdata;
        NewNode->next = NULL;
        if (head == NULL)
        {
            NewNode->prev = NULL;
            head = NewNode;
        }
        else
        {
            t = head;
            while (t->next != NULL)
            {
                t = t->next;
            }
            NewNode->prev = t;
            t->next = NewNode;
        }
    }
    void insertStart(int newdata)
    {
        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->data = newdata;
        newnode->prev = NULL;
        newnode->next = head;
        if (head != NULL)
        {
            head->prev = newnode;
        }
        head = newnode;
    }
    void insertAfter(Node *ptr, int data)
    {
        Node *p;
        if (ptr == NULL)
        {
            cout << ptr->data << " is not in List\n";
        }
        else
        {
            p = (Node *)malloc(sizeof(Node));
            p->prev = ptr;
            p->next = ptr->next;
            p->data = data;
            if (ptr->next != NULL)
            {
                ptr->next->prev = p;
            }
            ptr->next = p;
        }
    }
    void insertBefore(Node *ptr, int data)
    {
        Node *p;
        if (ptr == NULL)
        {
            cout << ptr->data << " is not in List\n";
        }
        else
        {
            p = (Node *)malloc(sizeof(Node));
            p->next = ptr;
            p->prev = ptr->prev;
            p->data = data;
            if (ptr->prev != NULL)
            {
                ptr->prev->next = p;
            }
            else
            {
                head = p;
            }
            ptr->prev = p;
        }
    }
    void DeleteNode(Node *ptr)
    {
        if (ptr == NULL)
        {
            cout << "Not Valid\n";
        }
        else if (ptr->prev != NULL && ptr->next != NULL)
        {
            ptr->prev->next = ptr->next->prev;
            ptr->next->prev = ptr->prev->next;
        }
        else if (ptr->prev == NULL)
        {
            cout << "dsf";
            head = ptr->next;
        }
        else if (ptr->next == NULL)
        {
            ptr->prev->next = ptr->next;
        }
        free(ptr);
    }
    void DeleteFirst()
    {
        Node *t;
        t = head;
        if (t->next != NULL)
        {
            head = head->next;
            head->prev = t->prev;
            cout << "Delete First Node\n";
        }
        else
        {
            cout << "Delete First Node (Only 1 Node in the list)\n";
            head = NULL;
        }
        free(t);
    }
    void DeleteLast()
    {
        Node *t;
        t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        if (t->prev != NULL)
        {
            cout << "Delete Last Node\n";
            t->prev->next = NULL;
        }
        else
        {
            cout << "Delete Last Node (Only 1 Node in the list)\n";
            head = NULL;
        }
        free(t);
    }
    void display()
    {
        Node *ptr;
        ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    int FirstDisplay()
    {
        if (head == NULL)
        {
            cout << "List is Empty\n";
            return -1;
        }
        return head->data;
    }
    int LastDisplay()
    {
        Node *p;
        p = head;
        if (head == NULL)
        {
            cout << "List is Empty\n";
            return NULL;
        }
        else
        {
            while (p->next != NULL)
            {
                p = p->next;
            }
            return p->data;
        }
    }
    Node *Search(int Data)
    {
        if (head == NULL)
        {
            return NULL;
        }
        else
        {
            Node *ptr;
            ptr = head;
            while (ptr != NULL)
            {
                if (ptr->data == Data)
                {
                    return ptr;
                }
                ptr = ptr->next;
            }
            return NULL;
        }
    }
};

int main()
{
    system("color 04");
    Link_List Obj;
    bool Goto = true;
    while (Goto == true)
    {
        system("CLS");
        int val;
        cout << "Press 1  For Insert First\n";
        cout << "Press 2  For Insert Last\n";
        cout << "Press 3  For Insert After  Node\n";
        cout << "Press 4  For Insert Before Node\n";
        cout << "Press 5  For View   First\n";
        cout << "Press 6  For View   Last\n";
        cout << "Press 7  For View   All\n";
        cout << "Press 8  For Search Data\n";
        cout << "Press 9  For Delete First\n";
        cout << "Press 10 For Delete Last\n";
        cout << "Press 11 For Delete Node\n";
        cout << "Press 12 For Exit\n";
        cout << "Input = ";
        cin >> val;
        switch (val)
        {
        case 1:
        {
            int DF;
            cout << "Enter int Data\n";
            cin >> DF;
            Obj.insertStart(DF);
            system("PAUSE");
            break;
        }
        case 2:
        {
            int DL;
            cout << "Enter int Data\n";
            cin >> DL;
            Obj.insertLast(DL);
            system("PAUSE");
            break;
        }
        case 3:
        {
            int DA, serA;
            cout << "All Doubly Link List is = ";
            Obj.display();
            cout << "\nWhich Do you want to insert After(Enter Particular Node Data) \n";
            cin >> serA;
            Node *p = Obj.Search(serA);
            cout << "Enter Data For New Node\n";
            cin >> DA;
            Obj.insertAfter(p, DA);
            system("PAUSE");
            break;
        }
        case 4:
        {
            int DA, serA;
            cout << "All Doubly Link List is = ";
            Obj.display();
            cout << "\nWhich Do you want to insert Before(Enter Particular Node Data) \n";
            cin >> serA;
            Node *p = Obj.Search(serA);
            cout << "Enter Data For New Node\n";
            cin >> DA;
            Obj.insertBefore(p, DA);
            system("PAUSE");
            break;
        }
        case 5:
        {
            cout << "First ID in Doubly Link List = " << Obj.FirstDisplay() << endl;
            system("PAUSE");
            break;
        }
        case 6:
        {
            cout << "Last ID in Doubly Link List = " << Obj.LastDisplay() << endl;
            system("PAUSE");
            break;
        }
        case 7:
        {
            cout << "All Doubly Link List is = ";
            Obj.display();
            cout << endl;
            system("PAUSE");
            break;
        }
        case 8:
        {
            int a;
            cout << "Enter ID For Search\n";
            cin >> a;
            Node *p = Obj.Search(a);
            if (p == NULL)
            {
                cout << "\nNot Found\n";
            }
            else
            {
                cout << "\n"
                     << p->data << " is Find in The List\n";
            }
            system("PAUSE");
            break;
        }
        case 9:
        {
            Obj.DeleteFirst();
            system("PAUSE");
            break;
        }
        case 10:
        {
            Obj.DeleteLast();
            system("PAUSE");
            break;
        }
        case 11:
        {
            int serA;
            cout << "Enter ID For Delete \n";
            cin >> serA;
            Node *p = Obj.Search(serA);
            Obj.DeleteNode(p);
            system("PAUSE");
            break;
        }
        case 12:
        {
            Goto = false;
        }
        default:
            break;
        }
    }
}