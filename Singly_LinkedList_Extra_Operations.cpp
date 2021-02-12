#include <iostream>
using namespace std;
class Node
{
public:
    int Data;
    Node *next;
};
class Code_Node
{
public:
    Node *Head;
    Code_Node()
    {
        Head = NULL;
    }
    void InsertAtTail(int X)
    {
        Node *NewNode = new Node();
        NewNode->Data = X;
        if (Head == NULL)
        {
            Head = NewNode;
        }
        else
        {
            Node *t = Head;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = NewNode;
        }
        NewNode->next = NULL;
    }
    void InsertAtFront(int X)
    {
        Node *NewNode = new Node();
        NewNode->Data = X;
        NewNode->next = Head;
        Head = NewNode;
    }
    void InsertAfter(int X, Node *Search)
    {
        if (Search == NULL)
        {
            cout << "Not Found\n";
        }
        else
        {
            Node *NewNode = new Node();
            NewNode->Data = X;
            if (Head == Search)
            {
                NewNode->next = Search->next;
                Search->next = NewNode;
            }
            else
            {
                NewNode->next = Search->next->next;
                Search->next->next = NewNode;
            }
        }
    }
    void InsertBefore(int X, Node *Search)
    {
        if (Search == NULL)
        {
            cout << "Not Found\n";
        }
        else
        {
            Node *NewNode = new Node();
            NewNode->Data = X;
            if (Head == Search)
            {
                NewNode->next = Search;
                Head = NewNode;
            }
            else
            {
                NewNode->next = Search->next;
                Search->next = NewNode;
            }
        }
    }
    void DeleteFront()
    {
        if (Head == NULL)
        {
            cout << "List is Empty\n";
        }
        else
        {
            Node *Temp = Head;
            Head = Head->next;
            delete Temp;
        }
    }
    void DeleteTail()
    {
        if (Head == NULL)
        {
            cout << "This is Empty\n";
        }
        else if (Head->next == NULL)
        {
            Node *Temp = Head;
            Head = NULL;
            delete Temp;
        }
        else
        {
            Node *t = Head;
            while (t->next->next != NULL)
            {
                t = t->next;
            }
            Node *temp = t->next;
            t->next = NULL;
            delete temp;
        }
    }
    void DeleteNode(Node *F)
    {
        if (Head == NULL)
        {
            cout << "List is Empty\n";
        }
        else if (F == NULL)
        {
            cout << "Not Found\n";
        }
        else if (Head->next == NULL)
        {
            Node *Temp = Head;
            Head = NULL;
            delete Temp;
        }
        else if (F->Data == Head->Data)
        {
            Node *Temp = Head;
            Head = Head->next;
            delete Temp;
        }
        else if (F != Head && F->next->next == NULL)
        {
            Node *temp = F->next;
            F->next = NULL;
            delete temp;
        }
        else
        {
            Node *temp = F->next;
            F->next = F->next->next;
            delete temp;
        }
    }
    void Duplicate_DeleteNode()
    {
        Node *t = Head;
        Node *t1 = Head;
        while (t != NULL)
        {
            
            while (t1->next != NULL)
            {
                if (t->Data == t1->next->Data)
                {
                    DeleteNode(t1);
                    cout << "Deleted....\n";
                    return;
                }
                t1 = t1->next;
            }
            if (t->next != NULL)
            {
                t1 = t->next;
            }
            t = t->next;
        }
        cout << "Not Found\n";
    }
    void Middle_Node()
    {
        Node *slow_ptr = Head;
        Node *fast_ptr = Head;
        if (Head != NULL)
        {
            while (fast_ptr != NULL && fast_ptr->next != NULL)
            {
                fast_ptr = fast_ptr->next->next;
                slow_ptr = slow_ptr->next;
            }
            Node *t = Search(slow_ptr->Data);
            DeleteNode(t);
            cout << "Deleted...\n";
        }
        else
        {
            cout << "Empty List\n";
        }
    }
    void reverse()
    {
        if (Head != NULL)
        {
            Node *t1 = NULL, *t2 = NULL;
            while (Head != NULL)
            {
                t2 = Head->next;
                Head->next = t1;
                t1 = Head;
                Head = t2;
            }
            Head = t1;
            cout << "Done\n";
        }
        else
        {
            cout << "Empty\n";
        }
    }
    void bubble_sort()
    {
        if (Head == NULL)
        {
            cout << "Empty\n";
        }
        else
        {
            int swapped;
            Node *lPtr;        // left pointer will always point to the start of the list
            Node *rPrt = NULL; // right pointer will always point to the end of the list
            do
            {
                swapped = 0;
                lPtr = Head;
                while (lPtr->next != rPrt)
                {
                    if (lPtr->Data > lPtr->next->Data)
                    {
                        int Temp;
                        Temp = lPtr->Data;
                        lPtr->Data = lPtr->next->Data;
                        lPtr->next->Data = Temp;
                        swapped = 1;
                    }
                    lPtr = lPtr->next;
                }
                //as the largest element is at the end of the list, assign that to rPtr as there is no need to
                //check already sorted list
                rPrt = lPtr;

            } while (swapped);
        }
    }
    Node *Search(int FV)
    {
        Node *t = Head;
        if (t == NULL)
        {
            return NULL;
        }
        else if (t->Data == FV)
        {
            return t;
        }
        else
        {
            while (t != NULL)
            {
                if (t->next != NULL)
                {
                    if (t->next->Data == FV)
                    {
                        return t;
                    }
                }
                t = t->next;
            }
        }
        return NULL;
    }
    bool IsEmpty()
    {
        if (Head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Node *GetFront()
    {
        if (Head == NULL)
        {
            return NULL;
        }
        else
        {
            return Head;
        }
    }
    Node *GetTail()
    {
        if (Head == NULL)
        {
            return NULL;
        }
        else
        {
            Node *n = Head;
            while (n->next != NULL)
            {
                n = n->next;
            }
            return n;
        }
    }
    void Display()
    {
        if (Head == NULL)
        {
            cout << "List is Emplty\n";
        }
        else
        {
            Node *t = Head;
            while (t != NULL)
            {
                cout << t->Data << " ";
                t = t->next;
            }
        }
    }
};

int main()
{
    system("color A");
    Code_Node Obj;
    bool Goto = true;
    while (Goto == true)
    {
        system("CLS");
        int val;
        cout << "Press 1  For Insert  Front\n";
        cout << "Press 2  For Insert  Tail\n";
        cout << "Press 3  For Insert  After  Node\n";
        cout << "Press 4  For Insert  Before Node\n";
        cout << "Press 5  For View    Front\n";
        cout << "Press 6  For View    Tail\n";
        cout << "Press 7  For View    All\n";
        cout << "Press 8  For View    IsEmpty?\n";
        cout << "Press 9  For Search  Data\n";
        cout << "Press 10  For Bubble  Sort\n";
        cout << "Press 11 For Delete  Front\n";
        cout << "Press 12 For Delete  Tail\n";
        cout << "Press 13 For Delete  Node\n";
        cout << "Press 14 For Delete  Duplicate Node\n";
        cout << "Press 15 For Delete  Middle Node\n";
        cout << "Press 16 For Reverse LinkedList\n";
        cout << "Press 17 For Exit\n";
        cout << "Input = ";
        cin >> val;
        switch (val)
        {
        case 1:
        {
            int DF;
            cout << "Enter int Data\n";
            cin >> DF;
            Obj.InsertAtFront(DF);
            system("PAUSE");
            break;
        }
        case 2:
        {
            int DL;
            cout << "Enter int Data\n";
            cin >> DL;
            Obj.InsertAtTail(DL);
            system("PAUSE");
            break;
        }
        case 3:
        {
            int DA, serA;
            cout << "All Singly Link List is = ";
            Obj.Display();
            cout << "\nWhich Do you want to insert After(Enter Particular Node Data) \n";
            cin >> serA;
            Node *p = Obj.Search(serA);
            cout << "Enter Data For New Node\n";
            cin >> DA;
            Obj.InsertAfter(DA, p);
            system("PAUSE");
            break;
        }
        case 4:
        {
            int DA, serA;
            cout << "All Singly Link List is = ";
            Obj.Display();
            cout << "\nWhich Do you want to insert Before(Enter Particular Node Data) \n";
            cin >> serA;
            Node *p = Obj.Search(serA);
            cout << "Enter Data For New Node\n";
            cin >> DA;
            Obj.InsertBefore(DA, p);
            system("PAUSE");
            break;
        }
        case 5:
        {
            cout << "First ID in Singly Link List = " << Obj.GetFront()->Data << endl;
            system("PAUSE");
            break;
        }
        case 6:
        {
            cout << "Last ID in Singly Link List = " << Obj.GetTail()->Data << endl;
            system("PAUSE");
            break;
        }
        case 7:
        {
            cout << "All Singly Link List is = ";
            Obj.Display();
            cout << endl;
            system("PAUSE");
            break;
        }
        case 8:
        {
            bool DA;
            DA = Obj.IsEmpty();
            if (DA == true)
            {
                cout << "Linked List is Empty\n";
            }
            else
            {
                cout << "Linked List is Not Empty\n";
            }
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
                     << p->next->Data << " is Find in The List\n";
            }
            system("PAUSE");
            break;
        }
        case 10:
        {
            Obj.bubble_sort();
            cout << "DONE...\n";
            system("PAUSE");
            break;
        }
        case 11:
        {
            Obj.DeleteFront();
            cout << "DONE...\n";
            system("PAUSE");
            break;
        }
        case 12:
        {
            Obj.DeleteTail();
            cout << "DONE...\n";
            system("PAUSE");
            break;
        }
        case 13:
        {
            int serA;
            cout << "All Singly Link List is = ";
            Obj.Display();
            cout << "\nEnter ID For Delete \n";
            cin >> serA;
            Node *p = Obj.Search(serA);
            Obj.DeleteNode(p);
            system("PAUSE");
            break;
        }
        case 14:
        {
            Obj.Duplicate_DeleteNode();
            system("PAUSE");
            break;
        }
        case 15:
        {
            Obj.Middle_Node();
            system("PAUSE");
            break;
        }
        case 16:
        {
            Obj.reverse();
            system("PAUSE");
            break;
        }
        case 17:
        {
            Goto = false;
            break;
        }
        default:
            system("PAUSE");
            break;
        }
    }
}