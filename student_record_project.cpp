#include <iostream>
//#include <conio.h>
//#include <cstdlib>
#include <string>
using namespace std;

struct Data                                             // we have declared variable here so that we will not need to declare variables again and agian 
{
    string name , section , mail ;
    string id , phone , cgpa ;
};

struct Node 
{
    Data data;
    Node* next;
};

Data inputStudent()
{
       string  name , section , mail ;                     // declared some variables for student info
       string phone , id, cgpa ;
       Data S;

       cout << " \n\t\tEnter Student name : ";
       cin.ignore ();                                      // we want to clear unwanted buffer
       getline (cin,name);                                 // to read string or a input line from input string...we want to keep reading input until new line comes

       cout<< " \n\t\tEnter student id number : ";
       getline (cin , id);

       cout<< " \n\t\tEnter section : ";
       getline (cin , section);

       cout<< " \n\t\tEnter phone no. : ";
       getline ( cin , phone );

       cout<<" \n\t\tEnter mail : ";
       getline (cin , mail);

       cout<<" \n\t\tEnter CGPA : ";
       getline (cin , cgpa);

       S.name = name;                                   // we are storing data taken from user in the variables which we have declared in our structure
       S.id = id;
       S.section = section;
       S.phone = phone;
       S.mail = mail;
       S.cgpa = cgpa;

       clog << "\n\nYour record has successfully added.." << endl;

       return S;
}

Node* append(Node* head, Data data) 
{

    Node* temp = new Node;                                       // we have created a new node with name temp 

    temp->data = data;                                            // we are storing data in temp node passed by user  
    temp->next = NULL;                                           // new student will add at last of node so till then we are keeping it as null

    if (head == NULL)                                            // this is condition when we are adding info of first student 
    {
        head = temp;                                             // we are making temp as a head 
        return head;                                             // if this codition will be true then after return the control will again go to switch statement from where it got call
    }

    Node* last = head;                                            // when if condition will not true then ...we have created a last pointer and we have copied address of head into it 

    while (last->next != NULL)                                    // here by running while loop we want to find location of last node so that we can insert new node after that
    {
        last = last->next;
    }

    last->next = temp;

    return head;

}

Node* delElement( Node* head , string nameDelete )
{
    Node* temp = new Node ;                                       // we have make one new node
    temp = head ;

    if (head == NULL)
    {
         cout << "\nNo students in record.";
         return NULL;
    }

    if ( head -> data.name == nameDelete )
    {
       free(head);
       head = head -> next;
       return head;
    }
    Node *curr = head-> next ;
    while ( curr != NULL )
    {
       if ( curr -> data.name == nameDelete)
        {
            free(curr);
            cout << "\n"  << nameDelete <<" is deleted from record successfully..";
            return head;
        }
        else
        curr = curr -> next;
    }
    cout << "\n No such student present in record..";
    return head;

}


Node* searchList (Node * head, string name)
{
    if ( head == NULL )
    {
        cout << " \nNo students in record.";
        return NULL;
    }
    
    int l=1;
    Node *curr = head;
    while (curr -> data.name != name)
    {
       if (curr -> next == NULL)
       {
           cout << " \nNo such record found..";
           return head;
       }
       l++;
       curr = curr ->next ;

    }
    cout << "\n student is present at No. : "<< l ;
    
    return head;

}

Node* changeName(Node * head, string oldData)
{
    if ( head == NULL )
    {
        cout << " /n No students in record";
        return NULL;
    }

    Node *curr=head;
    while( curr != NULL)
    {
        if ( curr -> data.name == oldData)
        {   
            string newData;
            cout <<" \nEnter student's new name : ";
            cin>> newData;
            curr -> data.name = newData;
            cout << " \nName updated successfully..";
            return head;
        }
        else
          curr = curr -> next;
    }
    cout <<" \nNo such student found in record..";
    return head;
    
}

Node* deleteAllRecords(Node *head)
{   
    if (head == NULL)
    {
        cout <<" \nAlready 0 students in records !!";
    }
    Node *current = head;

    while( current != NULL)
    {
      free(current);
      current=current->next;    
    } 
    cout << " \nAll records has been deleted... ";
    head = NULL;
    return head;
}


Node* printAllRecord(Node *head)
{
    if (head == NULL)
    {
        cout << "\nNo students in record.";
        return NULL;
    }
    
    int count=1;
    while ( head  != NULL)
    {
        
        
        cout << count << ".  Name      : " << head -> data.name << "\n    Id        : " << head -> data.id ;
        cout << " \n    Section   : " <<head -> data.section << "\n    Phone No. : " << head -> data.phone;
        cout << " \n    Mail      : " <<head -> data.mail << "\n    CGPA      : " << head -> data.cgpa;
        count++;
        cout<<"\n\n";

        head = head -> next ;
    }
    return head;
}


int main()
{
    Node* head = NULL;                                                // Here we haven't initialize any value to head node
    Data student;                                                     // student variable is of type structure 
    string oldName , newName , nameToSearch , nameToDelete;

    int pickChoices;                                                 // created one vaiable to pick choices
    cout<<"\n\t\t\t\t\t\t\t\t\t\tStudent Information System";
    cout << "\n\n\t\t\t\t\t Main Menu ";
    cout << "\n\n";
    cout << "\t\t\t\t\t 1. Add record";
    cout << "\n\t\t\t\t\t 2. Edit record";
    cout << "\n\t\t\t\t\t 3. Search record";
    cout << "\n\t\t\t\t\t 4. Delete specific record";
    cout << "\n\t\t\t\t\t 5. Delete all records";
    cout << "\n\t\t\t\t\t 6. Display all records";
    cout << "\n\t\t\t\t\t 7. EXIT\n";
    cout << "\n\t\t\t\t\t Choose Number :  ";

    while ( cin >> pickChoices)                                  // this loop will run till user will continue choosing number except EXIT
    {
        switch ( pickChoices )                                   // so that only that case will run which user want 
        {
              case 1 :
                  cout << "\n\n Enter student's detail below :=\n";
                  student = inputStudent();                    // we will go to function inputStudents and store everything in variable student
                  head = append(head, student);                // we are calling append and passing head which we have assigned with NULL 
                  break;

              case 2 :
                  cin.ignore();                                 // used to 
                  cout << "\n\nEnter student's old name : ";
                  getline(cin, oldName);

                  changeName(head, oldName);
                  break;  

              case 3 :
                  cout << "Enter name to search patient: ";            
                  cin.ignore();

                  getline(cin, nameToSearch);                    // we are taking name from user which user want to serch
                  searchList(head, nameToSearch);

                  break;  

              case 4 :
                  cout << "\nEnter student's name which you want to delete : ";
                  cin >> nameToDelete;
                  delElement(head, nameToDelete);

                  break;

              case 5 :
                  deleteAllRecords(head);
                  break;

              case 6 :
                  printAllRecord(head);
                  break;

              case 7 :
                  exit(0);    

              default:
                  cout<< " \n\t\t\t\t\t\t Choose any valid number from above options..."  ;
                         
            return 0 ;

        }
            cout << "\n\t\t\t\t\t Continue..";
            cout << "\n\n\t\t\t\t\t Main Menu ";
            cout << "\n\n";
            cout << "\t\t\t\t\t 1. Add record";
            cout << "\n\t\t\t\t\t 2. Edit record";
            cout << "\n\t\t\t\t\t 3. Search record";
            cout << "\n\t\t\t\t\t 4. Delete specific record";
            cout << "\n\t\t\t\t\t 5. Delete all records";
            cout << "\n\t\t\t\t\t 6. Display all records";
            cout << "\n\t\t\t\t\t 7. EXIT\n";
            cout << "\n\t\t\t\t\t Choose Number :  ";
            

        
    }
}