#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int Data;
    Node *Next;
};

class LinkedList
{
private:
    Node *Tail;

public:
    LinkedList()
    {
        Tail = NULL;
    }
    void insert_First(int Data)
    {
        Node *NewNode = new Node();
        NewNode->Data = Data;
        if (Tail == NULL)
        {
            Tail = NewNode;
            NewNode->Next = Tail;
            NewNode->prev = Tail;
        }
        else
        {
            NewNode->Next = Tail->Next;
            NewNode->prev = Tail;
            Tail->Next->prev = NewNode;
            Tail->Next = NewNode;
        }
    }
    void insert_Last(int Data)
    {
        Node *NewNode = new Node();
        NewNode->Data = Data;
        if (Tail == NULL)
        {
            Tail = NewNode;
            NewNode->Next = Tail;
            NewNode->prev = Tail;
        }
        else
        {
            NewNode->Next = Tail->Next;
            NewNode->prev = Tail;
            Tail->Next->prev = NewNode;
            Tail->Next = NewNode;
            Tail = NewNode;
        }
    }
    void insert_After(int Data, Node *Find)
    {
        Node *NewNode = new Node();
        NewNode->Data = Data;
        if (Find == NULL)
        {
            cout << "Empty List or Not Found\n";
        }
        else if (Find == Tail)
        {
            NewNode->Next = Tail->Next;
            NewNode->prev = Tail;
            Tail->Next->prev = NewNode;
            Tail->Next = NewNode;
            Tail = NewNode;
        }
        else
        {
            NewNode->Next = Find->Next;
            NewNode->prev = Find;
            Find->Next->prev = NewNode;
            Find->Next = NewNode;
        }
    }
    void insert_Before(int Data, Node *Find)
    {
        Node *NewNode = new Node();
        NewNode->Data = Data;
        if (Find == NULL)
        {
            cout << "Empty List or Not Found\n";
        }
        else
        {
            NewNode->Next = Find;
            NewNode->prev = Find->prev;
            Find->prev->Next = NewNode;
            Find->prev = NewNode;
        }
    }
    int Delete_First()
    {
        if (Tail == NULL)
        {
            cout << "List is Empty\n";
            return 0;
        }
        else
        {
            Node *temp = Tail->Next;
            if (temp == Tail)
            {
                delete (temp);
                Tail = NULL;
            }
            else
            {
                Tail->Next = temp->Next;
                temp->Next->prev = Tail;
                delete (temp);
            }
            return 1;
        }
    }
    int Delete_Last()
    {
        if (Tail == NULL)
        {
            cout << "List is Empty\n";
            return 0;
        }
        else
        {
            Node *temp = Tail;
            if (temp == temp->Next)
            {
                delete (temp);
                Tail = NULL;
            }
            else
            {
                Tail->prev->Next = Tail->Next;
                Tail->Next->prev = Tail->prev;
                Tail = Tail->prev;
                delete (temp);
            }
            return 1;
        }
    }
    void DeleteNode(Node *Find)
    {
        if (Find == NULL)
        {
            cout << "Not Found Or Empty\n";
        }
        else
        {
            Node *temp = Tail;
            if (Find == Find->Next)
            {
                delete (Find);
                Tail = NULL;
            }
            else if (Find == Tail)
            {
                Tail->prev->Next = Tail->Next;
                Tail->Next->prev = Tail->prev;
                Tail = Tail->prev;
                delete (temp);
            }
            else
            {
                Find->prev->Next = Find->Next;
                Find->Next->prev = Find->prev;
                delete (Find);
            }
        }
    }
    Node *Find(int Data)
    {
        if (Tail == NULL)
        {
            return NULL;
        }
        else
        {
            Node *t = Tail->Next;
            do
            {
                if (t->Data == Data)
                {
                    return t;
                }
                t = t->Next;
            } while (t != Tail->Next);
        }
        return NULL;
    }
    void Display()
    {
        if (Tail == NULL)
        {
            cout << "List is Empty\n";
        }
        else
        {
            Node *t;
            t = Tail->Next;
            do
            {
                cout << t->Data << " ";
                t = t->Next;
            } while (t != Tail->Next);
        }
    }
    int FirstDisplay()
    {
        if (Tail == NULL)
        {
            return 2765;
        }
        else
        {
            return Tail->Next->Data;
        }
    }
    int LastDisplay()
    {
        if (Tail == NULL)
        {
            return 2765;
        }
        else
        {
            return Tail->Data;
        }
    }
};

int main()
{
    system("color A");
    LinkedList Obj;
    bool Goto = true;
    int count = 0;
    while (Goto == true)
    {
        system("CLS");
        int val;
        cout << "*********"
             << "Total Size is Unlimited "
             << "& Current Size is " << count << " *********\n";
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
            Obj.insert_First(DF);
            count++;
            system("PAUSE");
            break;
        }
        case 2:
        {
            int DL;
            cout << "Enter int Data\n";
            cin >> DL;
            Obj.insert_Last(DL);
            count++;
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
            Node *p = Obj.Find(serA);
            cout << "Enter Data For New Node\n";
            cin >> DA;
            Obj.insert_After(DA, p);
            if (p != NULL)
            {
                count++;
            }
            system("PAUSE");
            break;
        }
        case 4:
        {
            int DA, serA;
            cout << "All Doubly Link List is = ";
            Obj.Display();
            cout << "\nWhich Do you want to insert Before(Enter Particular Node Data) \n";
            cin >> serA;
            Node *p = Obj.Find(serA);
            cout << "Enter Data For New Node\n";
            cin >> DA;
            Obj.insert_Before(DA, p);
            if (p != NULL)
            {
                count++;
            }
            system("PAUSE");
            break;
        }
        case 5:
        {
            if (Obj.FirstDisplay() == 2765)
            {
                cout << "\nEmpty List\n";
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
            if (Obj.LastDisplay() == 2765)
            {
                cout << "\nEmpty List\n";
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
            cout << "All Doubly Link List is = ";
            Obj.Display();
            cout << endl;
            system("PAUSE");
            break;
        }
        case 8:
        {
            int a;
            cout << "Enter ID For Search\n";
            cin >> a;
            Node *p = Obj.Find(a);
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
        case 9:
        {
            int a = Obj.Delete_First();
            if (a == 1)
            {
                count--;
            }

            system("PAUSE");
            break;
        }
        case 10:
        {
            int a = Obj.Delete_Last();
            if (a == 1)
            {
                count--;
            }
            system("PAUSE");
            break;
        }
        case 11:
        {
            int serA;
            cout << "All Doubly Link List is = ";
            Obj.Display();
            cout << endl;
            cout << "Enter Value For Delete \n";
            cin >> serA;
            Node *p = Obj.Find(serA);
            Obj.DeleteNode(p);
            if (p != NULL)
            {
                count++;
            }
            system("PAUSE");
            break;
        }
        case 12:
        {
            Goto = false;
        }
        default:
        {
            break;
        }
        }
    }
}
