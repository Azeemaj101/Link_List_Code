#include <iostream>
#include <windows.h> // use for sleep
using namespace std;

// Total 3 Linkend list 1.Voter 2.Candidate 3.(Halka)

//Start of linked list 1 => Voter
// Linkend list 1 => contain 2 classes first one is node and second one contain all functions
class Voter_Node
{
public: // becouse by-default class is private
	int id;
	string name;
	long long cnic; // long long is a data type
    int age; // equal or more then 18
    string candidate_Name;
    Voter_Node *next;
};
class voter_functions
{
public:
    Voter_Node *Head;
    voter_functions()
    {
        Head = NULL;
    }
    void InsertAtTail(int id, string name, int age, long long cnic, string candidate_Name)
    {
        Voter_Node *NewNode = new Voter_Node();
        NewNode->id = id;
        NewNode->name = name;
        NewNode->age = age;
        NewNode->cnic = cnic;
        NewNode->candidate_Name = candidate_Name;
        if (Head == NULL)
        {
            Head = NewNode;
        }
        else
        {
            Voter_Node *t = Head;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = NewNode;
        }
        NewNode->next = NULL;
    }

    void Display()
    {
        if (Head == NULL)
        {
            cout << "Voter List is Emplty\n";
        }
        else
        {
            Voter_Node *t = Head;
            while (t != NULL)
            {
                cout <<"Voter ID: " << t->id << "  Voter Name: " << t->name << "  Voter Age: "<< t->age <<"  Voter CNIC: "<<t->cnic<<"  Candidate Name: "<<t->candidate_Name<<"\n";
                t = t->next;
            }
        }
    }
};
// End of linked list 1:

//Start of linked list 2 => Candidate
// Linkend list 2 => contain 2 classes first one is node and second one contain all functions

class Candidate_Node
{
public: // becouse by-default class is private
	int id;
	string name;
	int vote_count;
    string halka_name;
	Candidate_Node *next;
};
class Candidate_functions
{
public:
    Candidate_Node *Head;
    Candidate_functions()
    {
        Head = NULL;
        InsertAtTail(1,"Ayaan","NA-1");
        InsertAtTail(2,"Faizan","NA-2");
        InsertAtTail(3,"Azeem","NA-3");
        InsertAtTail(4,"Hamza","NA-4");
        InsertAtTail(5,"Umer","NA-5");
    }
    void InsertAtTail(int id, string name, string halka_name)
    {
        Candidate_Node *NewNode = new Candidate_Node(); 
        NewNode->id = id;
        NewNode->name = name;
        NewNode->vote_count = 0; // by default voting start form 0
        NewNode->halka_name = halka_name;
        if (Head == NULL)
        {
            Head = NewNode;
        }
        else
        {
            Candidate_Node *t = Head;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = NewNode;
        }
        NewNode->next = NULL;
    }

    Candidate_Node *vote(int id)
    {
        Candidate_Node *t = Head;
        if (t == NULL)
        {
            return NULL;
        }
        else if (t->id == id)
        {
        	t->vote_count++;
            return t;
        }
        else
        {
            while (t != NULL)
            {
                if (t->next != NULL)
                {
                    if (t->next->id == id)
                    {
                    	t->next->vote_count++;
                        return t->next;
                    }
                }
                t = t->next;
            }
        }
        return NULL;
    }
	
	void Results()
	{
		Candidate_Node *t = Head;
		Candidate_Node *firstM;
        if (t == NULL)
        {
            cout<<"List is Empty\n";
        }
        else
        {
        	int max = INT_MIN, flag=0;
            while (t != NULL)
            {
                if (max<t->vote_count)
                {
                	firstM = t;
                	max = t->vote_count;
                }
                t = t->next;
            }
            t = Head;
            Candidate_Node *f;
            int same;
            while (t != NULL)
            {
            	if(t->next != NULL)
            	{
            		f = t;
            		while (f != NULL)
		            {
		            	if(f->next != NULL)
		            	{
		            		if (t->vote_count!=0&& (t->vote_count == f->next->vote_count))
			                {
			                	flag=1;
			                	same=t->vote_count;
			                }
			        	}
			        	f = f->next;
			        }
				}
                t = t->next;
            }
            if(flag && same == firstM->vote_count)
            {
            	cout<<"==============>Two or more then two Winners Please check admin panel<==============\n";
            	cout<<"************Winner in Sequence************\n";
            	cout <<"Candidate ID: " << firstM->id << "  Candidate Name: " << firstM->name << "  Candidate Votes: "<< firstM->vote_count <<"  Candidate Halka Name: "<<firstM->halka_name<<"\n";
			}
			else if(firstM!=NULL)
            {
            	cout<<"************Winner************\n";
            	cout <<"Candidate ID: " << firstM->id << "  Candidate Name: " << firstM->name << "  Candidate Votes: "<< firstM->vote_count <<"  Candidate Halka Name: "<<firstM->halka_name<<"\n";
			}
			else{
				cout<<"Vote first\n";
			}
        }
	}
	
    void Admin_Display()
    {
        if (Head == NULL)
        {
            cout << "Candidate List is Emplty\n";
        }
        else
        {
            Candidate_Node *t = Head;
            while (t != NULL)
            {
                cout <<"Candidate ID: " << t->id << "  Candidate Name: " << t->name << "  Candidate Votes: "<< t->vote_count <<"  Candidate Halka Name: "<<t->halka_name<<"\n";
                t = t->next;
            }
        }
    }
	void User_Display()
    {
        if (Head == NULL)
        {
            cout << "Candidate List is Emplty\n";
        }
        else
        {
            Candidate_Node *t = Head;
            while (t != NULL)
            {
                cout <<"Candidate ID: " << t->id << "  Candidate Name: " << t->name<<"  Candidate Halka Name: "<<t->halka_name<<"\n";
                t = t->next;
            }
        }
    }
};

// End of linked list 2:

//Start of linked list 3 => Halka
// Linkend list 3 => contain 2 classes first one is node and second one contain all functions

class Halka_Node
{
public: // becouse by-default class is private
	int id;
	string halka_name;
	int Total_vote_count;
	Halka_Node *next;
};
class Halka_functions
{
public:
    Halka_Node *Head;
    Halka_functions()
    {
        Head = NULL;
        InsertAtTail(1, "NA-1");
        InsertAtTail(2, "NA-2");
        InsertAtTail(3, "NA-3");
        InsertAtTail(4, "NA-4");
        InsertAtTail(5, "NA-5");
    }
    void InsertAtTail(int id, string halka_name)
    {
        Halka_Node *NewNode = new Halka_Node(); 
        NewNode->id = id;
        NewNode->halka_name = halka_name;
        NewNode->Total_vote_count = 0; // by default Halka voting start form 0
        if (Head == NULL)
        {
            Head = NewNode;
        }
        else
        {
            Halka_Node *t = Head;
            while (t->next != NULL)
            {
                t = t->next;
            }
            t->next = NewNode;
        }
        NewNode->next = NULL;
    }

    void halka_vote_count(int id)
    {
        Halka_Node *t = Head;
        if (t == NULL)
        {
            return;
        }
        else if (t->id == id)
        {
        	t->Total_vote_count++;
            return;
        }
        else
        {
            while (t != NULL)
            {
                if (t->next != NULL)
                {
                    if (t->next->id == id)
                    {
                    	t->next->Total_vote_count++;
                        return;
                    }
                }
                t = t->next;
            }
        }
        return;
    }

    void Display()
    {
        if (Head == NULL)
        {
            cout << "Halka List is Emplty\n";
        }
        else
        {
            Halka_Node *t = Head;
            while (t != NULL)
            {
                cout <<"Halka ID: " << t->id << "  Halka Name: " << t->halka_name << "  Halka Total Votes: "<< t->Total_vote_count<<"\n";
                t = t->next;
            }
        }
    }
};

int main()
{
	int one, id=0, CandidateID=5;
	bool login=false; //one time login only
	system("color F4");
	voter_functions voter_obj;
	Candidate_functions candidate_obj;
	Halka_functions halka_obj;
	Main: // this is a goto statement
	cout<<"**********Main Menu**********\n";
	cout<<"Press 1 for Voting\n";
	cout<<"Press 2 for Admin Panel\n";
	cout<<"Press 3 for Exit\n";
	cin>>one;
	switch(one)
	{
		case 1:
			{
				int two; // this is a local variable 
				case1:
				system("CLS");
				cout<<"***********Voting Menu***********\n";
				cout<<"Press 1 for Add Voter\n";
				cout<<"Press 2 for Results\n";
				cout<<"Press 3 for Candidate Display\n";
				cout<<"Press 4 for Main Menu\n";
				cin>>two;
				if(two == 1)
				{
					int n, age, CID;
					string name;
					long long cnic;
					cout<<"Enter the number of voters (int)\n";
					cin>>n;
					for(int i=0; i<n; i++)
					{
						cout<<"Voter ID: "<< ++id<<endl;
						cout<<"Enter Voter Name:\n";
						cin>>name;
						age:
						cout<<"Enter Voter Age\n";
						cin>>age;
						if(age <= 17)
						{
							cout<<"Age must be Greater then or equal to 18\n";
							goto age;
						}
						cout<<"Enter Voter CNIC\n";
						cin>>cnic;
						cout<<"**********Candidate Details***********\n";
						candidate_obj.User_Display();
						C_ID:
						cout<<"\n\nEnter Candidate ID (Add accurate ID)\n";
						cin>>CID;
						halka_obj.halka_vote_count(CID);
						Candidate_Node *candidate_Name = candidate_obj.vote(CID);
						if(candidate_Name == NULL)
						{
							cout<<"Wrong Candidate ID Please Try again\n";
							goto C_ID;
						}
						else
						{
							voter_obj.InsertAtTail(id, name, age, cnic, candidate_Name->name);
							cout<<"*********Done*********\n";
							system("PAUSE");
							system("CLS");	
						}
						
					}
					goto case1;
				}
				else if(two == 2)
				{
					system("CLS");
					candidate_obj.Results();
					system("PAUSE");
					goto case1;
				}
				else if(two == 3)
				{
					system("CLS");
					candidate_obj.User_Display();
					system("PAUSE");
					goto case1;
				}
				else if(two == 4)
				{
					system("CLS");
					goto Main;
				}
				else
				{
					cout<<"invalid input\n";
					system("PAUSE");
					system("CLS");
					goto case1;
				}
				break;
			}
		case 2:
			{
				string userName;
    			int userPassword, loginAttempt=0;
    			if(login)
    			{
    				goto down;
				}
				while (loginAttempt < 5)
			    {
			        cout << "Please Enter Admin name: ";
			        cin >> userName;
			        cout << "Please Enter Admin Password: ";
			        cin >> userPassword;
			        
			        int ln = userName.length();
			    	// Conversion according to ASCII values
			    	for (int i = 0; i < ln; i++) {
			        if (userName[i] >= 'A' && userName[i] <= 'Z')
			            // Convert uppercase to lowercase
			            userName[i] = userName[i] + 32;
			    	}
			    	
					cout << "Loading <";
					for (int i = 0; i <= 20; i++)
					{
						Sleep(100);
						cout << "|";
					}
					cout << ">100%\n\n";
					
			        if (userName == "azeem" && userPassword == 1234)
			        {
			            cout << "Welcome To Admin Panal!\n";
			            login = true;
			            break;
			        }
			        else if (userName == "umer" && userPassword == 1234)
			        {
			            cout << " Welcome To Admin Panal!\n";
			            login = true;
			            break;
			        }
			        else
			        {
			            cout << "Invalid login attempt. Please try again.\n\n";
			            loginAttempt++;
			            system("PAUSE");
			            system("CLS");
			        }
			    }
			    
			    // this if use for terminate code because login password is wrong
			    if (loginAttempt == 5)
			    {
			        cout << "Too many login attempts! The program will now terminate.";
					cout << "\t\t Thankyou for using program\n";
					cout << "\t\t\tAllah Hafiz\n";
					exit(0); // use for terminate code 
			    }
			    else
			    {
			    	down:
			    	int three;
			    	adminGo:
			    	cout<<"*************Admin Menu*************\n";
			    	cout<<"Press 1 Add Candidate + Halka\n";
			    	cout<<"Press 2 Display Voter\n";
			    	cout<<"Press 3 Display Candidate Results\n";
			    	cout<<"Press 4 Display (Halka)\n";
			    	cout<<"Press 5 Display All Results\n";
			    	cout<<"Press 6 Main Menu\n";
			    	cin>>three;
					if(three == 1)
					{
						int n;
						string name, halka_name;
						add_candidate:
						cout<<"Enter number of candidate you want to enter \n";
						cin>>n;
						if(n>0)
							for(int i=0; i<n; i++)
							{
								cout<<"Candidate Number: "<<++CandidateID<<endl;
								cout<<"Enter Candidate Name\n";
								cin>>name;
								cout<<"Enter Halka Name\n";
								cin>>halka_name;
								candidate_obj.InsertAtTail(CandidateID,name,halka_name);
								halka_obj.InsertAtTail(CandidateID, halka_name);
								cout<<"*********Added*********\n";
							}
						else 
						{
							cout<<"Invalid input please try again\n";
							system("PAUSE");
							goto add_candidate;
						}
						system("PAUSE");
						system("CLS");
						goto adminGo;
					}
					else if(three == 2)
					{
						cout<<"********Voters Details********\n";
						voter_obj.Display();
						system("PAUSE");
						system("CLS");
						goto adminGo;
					}
					else if(three == 3)
					{
						cout<<"********Candidates Details********\n";
						candidate_obj.Admin_Display();
						system("PAUSE");
						system("CLS");
						goto adminGo;
					}
					else if(three == 4)
					{
						cout<<"********Halka Details********\n";
						halka_obj.Display();
						system("PAUSE");
						system("CLS");
						goto adminGo;
					}
					else if(three == 5)
					{
						candidate_obj.Results();
						cout<<"********Candidates Results********\n";
						candidate_obj.Admin_Display();
						system("PAUSE");
						system("CLS");
						goto adminGo;
					}
					else if(three == 6)
					{
						system("CLS");
						goto Main;
					}
					else
					{
						cout<<"Invalid Input Please try again\n";
						system("PAUSE");
						system("CLS");
						goto adminGo;
					}
				}
				break;
			}	
		case 3:
			{
				exit(0);
				break;
			}
	}
	
}
