#include <iostream>
using namespace std;

class Array
{
private:
    int arr[100];
    int size;

public:
    void insert()
    {
        cout << "Enter The size of List\n";
        cin >> size;
        cout << "\n\n";
        for (int i = 0; i < size; i++)
        {
            cout << "Insert in Array " << i + 1 << endl;
            cin >> arr[i];
        }
    }
    void traversing()
    {
        cout << "Your List is =";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    void Search(int ser)
    {
        cout << "Searching...\n\n";
        int count = 0;
        for (int i = 0; i < size; i++) //iterative or linear search
        {
            if (arr[i] == ser)
            {
                cout << arr[i] << " Find in index " << i << endl;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "Not Found\n";
        }
    }

    void Delete()
    {
        int del;
        int count = 0;
        cout << "Enter element to be delete : ";
        cin >> del;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == del)
            {
                for (int j = i; j < (size - 1); j++)
                {
                    arr[j] = arr[j + 1];
                }
                count++;
                break;
            }
        }
        if (count == 0)
        {
            cout << "Element not found..!!";
        }
        else
        {
            cout << "Element deleted successfully..!!\n";
            cout << "Now the new array is :\n";
            for (int i = 0; i < (size - 1); i++)
            {
                cout << arr[i] << "\n";
            }
        }
        size = size - 1;
    }
};
int main()
{
    int a;
    Array Obj;

    bool b = true;
    while (b == true)
    {
        system("CLS");
        cout << "press 1 for  Insert\n";
        cout << "Press 2 for  Traversing\n";
        cout << "press 3 for  Search \n";
        cout << "press 4 for  Delete \n";
        cout << "press 5 for  Exit\n";
        cin >> a;
        if (a == 1)
        {
            Obj.insert();
            cout << "\n";
        }
        else if (a == 2)
        {
            Obj.traversing();
            cout << "\n";
            system("PAUSE");
        }
        else if (a == 3)
        {
            int ser;
            cout << "Enter Value For Search\n";
            cin >> ser;
            Obj.Search(ser);
            cout << "\n";
            system("PAUSE");
        }
        else if (a == 4)
        {

            Obj.Delete();
            cout << "\n";
            system("PAUSE");
        }
        else if (a == 5)
        {
            b = false;
        }
        else
        {
            cout << "invalid input\n";
        }
    }
}