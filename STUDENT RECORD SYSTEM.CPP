#include<bits/stdc++.h>

using namespace std;

typedef struct node{

    int roll;  // Declaring For Student ID
    char name[40]; // Declaring For Student Name
    char sec;      // Declaring For Student Section
    char dep[10];  // Declaring For Student Department
    long long cell; // Declaring For Student Phone Number
    node *next;

}node;

node *head=NULL;

void Insert() //Entering Student Data In This Function
{

    node *curr=(node*)malloc(sizeof(node));

    if(head == NULL){

        head=curr;
        cout<<"Enter ID Number : ";
        cin>>head->roll;
        getchar();
        cout<<"Enter Name : ";
        gets(head->name);
        cout<<"Enter Section : ";
        cin>>head->sec;
        getchar();
        cout<<"Enter Department Name : ";
        gets(head->dep);
        cout<<"Enter Phone Number : ";
        cin>>head->cell;
        head->next=NULL;
        getchar();

        return;

    }

        cout<<"Enter ID Number : ";
        cin>>curr->roll;
        getchar();
        cout<<"Enter Name : ";
        gets(curr->name);
        cout<<"Enter Section : ";
        cin>>curr->sec;
        getchar();
        cout<<"Enter Department Name : ";
        gets(curr->dep);
        cout<<"Enter Phone Number : ";
        cin>>curr->cell;

        curr->next=head;
        head=curr;
        getchar();

}

void del(int n) //This Function Is For Deleting Student Data
{
    node *curr=head,*prev=NULL;
    int flag = 0;

    while(curr!=NULL)
    {
        if(curr->roll==n)
        {
            if(prev==NULL) head = curr->next;

            else prev->next=curr->next;

            flag=1;
            free(curr);
            break;
        }

        prev=curr;
        curr=curr->next;
    }

    if(flag==1) cout<<"Data of ID : "<<n<<" Is Deleted"<<endl;

}

void Search(int n) //This Function Is For Searching Student Data
{

    node *curr=head;

    while(curr != NULL){

        if(curr->roll == n){

            cout<<"                     ============================================="<<endl;
            cout<<"Name : "<<curr->name<<endl;
            cout<<"ID : "<<curr->roll<<endl;
            cout<<"Section : "<<curr->sec<<endl;
            cout<<"Department : "<<curr->dep<<endl;
            cout<<"Phone : "<<curr->cell<<endl;
            cout<<"                     ============================================="<<endl;

        }

        curr=curr->next;

    }

}

void Print() //This Function Is For Printing All Student's Data
{

    node *curr=head;

    cout<<"                     ============================================="<<endl;

    while(curr != NULL){

        cout<<"Name : "<<curr->name<<endl;
        cout<<"ID : "<<curr->roll<<endl;
        cout<<"Section : "<<curr->sec<<endl;
        cout<<"Department : "<<curr->dep<<endl;
        cout<<"Phone : "<<curr->cell<<endl;

        curr=curr->next;

    }

    cout<<"                     ============================================="<<endl;

}

int main(){

    int x,n;

    cout<<"                     ============================================="<<endl;
    cout<<"                                 Student Record System            "<<endl;
    cout<<"                     ============================================="<<endl<<endl;

    while(1){

        cout<<"                     -------------------- Menu -------------------"<<endl<<endl;
        cout<<"                                 1.Insert Student Data."<<endl;
        cout<<"                                 2.Delete Data."<<endl;
        cout<<"                                 3.Print Student Data."<<endl;
        cout<<"                                 4.Search."<<endl;
        cout<<"                                 5.Exit."<<endl;

        cout<<endl<<"                                 Enter Any Key-word : ";
        cin>>x;
        cout<<endl;

        if(x == 1) Insert(); //Inserting Student Data

        else if(x == 2){    //Deleting  Student Data

            cout<<"                                 Enter ID : ";
            cin>>n;
            del(n);

        }

        else if(x == 3) Print();  //Printing Student Data

        else if(x == 4) {        //Searching Student Data

            cout<<"                                 Enter ID : ";
            cin>>n;
            Search(n);

        }

        else if(x == 5) break;

        else cout<<"                                Enter A Valid Key........"<<endl;

        cout<<endl;

    }

    return 0;

}
