#include <iostream>
using namespace std;

class Node
{
public:
    int Data;
    Node *next;
};

class Circular_LinkList
{
public:
    Node *Last;
    Circular_LinkList()
    {
        Last = NULL;
    }
    void insert_First(int Data)
    {
        Node *NewNode;
        NewNode = new Node;
        NewNode->Data = Data;
        if (Last == NULL)
        {
            Last = NewNode;
        }
        else
        {
            NewNode->next = Last->next;
        }
        Last->next = NewNode;
    }
    void insert_Last(int Data)
    {
        Node *NewNode;
        NewNode = new Node;
        NewNode->Data = Data;
        if (Last == NULL)
        {
            Last = NewNode;
            Last->next = NewNode;
        }
        else
        {
            NewNode->next = Last->next;
            Last->next = NewNode;
            Last = NewNode;
        }
    }
    void insert_After(Node *ptr, int Data)
    {
        Node *NewNode;
        NewNode = new Node;
        NewNode->Data = Data;
        if (ptr == NULL)
        {
            cout << "List is Empty\n";
        }
        else
        {
            NewNode->next = ptr->next;
            ptr->next = NewNode;
            if (ptr == Last)
            {
                Last = NewNode;
            }
        }
    }
    // void insert_Before(Node *ptr, int Data)
    // {
    //     Node *NewNode;
    //     NewNode = (Node*)malloc(sizeof(Node));
    //     NewNode->Data = Data;
    //     if(ptr == NULL)
    //     {
    //         cout<<"List is Empty\n";
    //     }
    //     else
    //     {
    //         Node *p =ptr-1;
    //         NewNode->next = p->next;
    //         p->next = NewNode;
    //         if(ptr == Last)
    //         {
    //             Last = NewNode;
    //         }
    //     }
    // }
    Node *Search(int Data)
    {
        Node *p;
        p = Last->next;
        do
        {
            if (p->Data == Data)
            {
                return p;
            }
            p = p->next;
        } while (p != Last->next);

        return NULL;
    }
    void DeleteFirst()
    {
        Node *t;
        t = Last->next;
        if (t == Last)
        {
            Last = NULL;
        }
        else
        {
            Last->next = t->next;
        }
        delete(t);
    }
    void DeleteLast()
    {
        Node *p, *t;
        if (Last == NULL)
        {
            cout << "List is Empty\n";
        }
        else
        {
            t = Last;
            if (t->next == Last)
            {
                Last = NULL;
            }
            else
            {
                p = Last->next;
                while (p->next != Last)
                {
                    p = p->next;
                }
                p->next = Last->next;
                Last = p;
            }
                delete(t);
        }
    }
    void DeleteNode(Node *ptr)
    {
        Node *t;
        if (ptr == NULL)
        {
            cout<<"Invalid\n";
        }
        else if (ptr == ptr->next)
        {
            Last = NULL;
        }
        else if (ptr != Last && ptr != Last->next)
        {
            t = ptr;
            while (t->next != ptr)
            {
                t = t->next;
            }
            t->next = ptr->next;
        }
        else if (ptr == Last)
        {
            Node *p;
            p = ptr;
            while (p->next != ptr)
            {
                p = p->next;
            }
            p->next = ptr->next;
            Last = p;
        }
        else if (ptr == Last->next)
        {
            Last->next = Last->next->next;
        }
        delete(ptr);
    }
    void Display()
    {
        Node *t;
        if (Last == NULL)
        {
            cout << "Empty List\n";
        }
        else
        {
            t = Last->next;
            do
            {
                cout << t->Data << " ";
                t = t->next;
            } while (t != Last->next);
        }
    }
    void Reverse_Display()
    {
        if (Last != NULL)
        {
            Node *t1 = NULL, *t2 = NULL;
            while (Last != NULL)
            {
                t2 = Last->next;
                Last->next = t1;
                t1 = Last;
                Last = t2;
            }
            Last = t1;
            int t3 = Last->Data;
            DeleteLast();
            insert_First(t3);
            cout << "Done\n";
        }
        else
        {
            cout << "Empty\n";
        }
    }
    int FirstDisplay()
    {
        if (Last == NULL)
        {
            return -1;
        }
        else
        {
            return Last->next->Data;
        }
    }
    int LastDisplay()
    {
        if (Last == NULL)
        {
            return -1;
        }
        else
        {
            return Last->Data;
        }
    }
};
int main()
{
    system("color 01");
    Circular_LinkList Obj;
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
        cout << "Press 8  For Reverse Order\n";
        cout << "Press 9  For Search Data\n";
        cout << "Press 10  For Delete First\n";
        cout << "Press 11 For Delete Last\n";
        cout << "Press 12 For Delete Node\n";
        cout << "Press 13 For Exit\n";
        cout << "Input = ";
        cin >> val;
        switch (val)
        {
        case 1:
        {
            int DF;
            cout << "Enter int Data\n";
            cin >> DF;
            Obj.insert_First(DF);
            system("PAUSE");
            break;
        }
        case 2:
        {
            int DL;
            cout << "Enter int Data\n";
            cin >> DL;
            Obj.insert_Last(DL);
            system("PAUSE");
            break;
        }
        case 3:
        {
            int DA, serA;
            cout << "All Doubly Link List is = ";
            Obj.Display();
            cout << "\nWhich Do you want to insert After(Enter Particular Node Data) \n";
            cin >> serA;
            Node *p = Obj.Search(serA);
            cout << "Enter Data For New Node\n";
            cin >> DA;
            Obj.insert_After(p, DA);
            system("PAUSE");
            break;
        }
        case 4:
        {
            // int DA, serA;
            // cout << "All Doubly Link List is = ";
            // Obj.display();
            // cout << "\nWhich Do you want to insert Before(Enter Particular Node Data) \n";
            // cin >> serA;
            // Node *p = Obj.Search(serA);
            // cout << "Enter Data For New Node\n";
            // cin >> DA;
            // Obj.insertBefore(p, DA);
            // system("PAUSE");
            // break;
        }
        case 5:
        {
            if (Obj.FirstDisplay() == -1)
            {
                cout<<"\nEmpty List\n";
            }
            else
            {
            cout << "First ID in Doubly Link List = " << Obj.FirstDisplay() << endl;
            }
            system("PAUSE");
            break;
        }
        case 6:
        {
            if (Obj.LastDisplay() == -1)
            {
                cout<<"\nEmpty List\n";
            }
            else
            {
            cout << "Last ID in Circular Link List = " << Obj.LastDisplay() << endl;
            }
            system("PAUSE");
            break;
        }
        case 7:
        {
            cout << "All Cicular Link List is = ";
            Obj.Display();
            cout << endl;
            system("PAUSE");
            break;
        }
        case 8:
        {
            cout << "All Circular Link List is  Reverse = ";
            Obj.Reverse_Display();
            Obj.Display();
            cout << endl;
            system("PAUSE");
            break;
        }
        case 9:
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
                     << p->Data << " is Find in The List\n";
            }
            system("PAUSE");
            break;
        }
        case 10:
        {
            Obj.DeleteFirst();
            system("PAUSE");
            break;
        }
        case 11:
        {
            Obj.DeleteLast();
            system("PAUSE");
            break;
        }
        case 12:
        {
            int serA;
            cout << "Enter ID For Delete \n";
            cin >> serA;
            Node *p = Obj.Search(serA);
            Obj.DeleteNode(p);
            system("PAUSE");
            break;
        }
        case 13:
        {
            Goto = false;
        }
        default:
            break;
        }
    }
}
