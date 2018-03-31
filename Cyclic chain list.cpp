#include<iostream>
using namespace std;
typedef struct node
{
    char data[20];
    struct node* line;
}node;
node *creatlist(int len)
{
    node *head = new node;
    head->line = head;
    node *p = head;
    for(int i = 0;i < len;i ++)
    {
        node *anode = new node;
        cout<<"please input the data"<<i+1<<endl;
        cin>>anode->data;
        p->line = anode;
        p = anode;
        p->line = head;
    }
    return head;
}
void display(node *head)
{
    while(head == NULL)
        cout<<"this list no data"<<endl;
    node *p = head;
    cout<<p->data<<endl;
    p = p->line;
    while(p != head)
    {
        cout<<p->data<<endl;
        p = p->line;
    }
}
void insert_(node *head , int index)
{
    node *p = head;
    node *newnode = new node;
    cout<<"please input the data"<<endl;
    cin>>newnode->data;
    for(int i = 0;i < index;i ++)
    {
        p = p->line;
    }
    if(p->line == head)
    {
        newnode->line = head;
        p->line = newnode;
    }
    else
    {
        newnode->line= p->line;
        p->line = newnode;
    }
}
void remove_(node *head , int index)
{
    node *p = head;
    for(int i = 0;i < index;i ++)
    {
        p = p->line;
    }
    if(p->line->line == head)
    {
        node *del = p->line;
        p->line = head;
        delete del;
    }
    else
    {
        node *del = p->line;
        p->line = p->line->line;
        delete del;
    }
}
int main()
{
    cout<<"     data sing in     "<<endl;
    cout<<"----------------------"<<endl;
    node *alldata = creatlist(5);
    cout<<"     display data      "<<endl;
    cout<<"-----------------------"<<endl;
    display(alldata);
    cout<<"      insert data      "<<endl;
    cout<<"-----------------------"<<endl;
    insert_(alldata , 5);
    cout<<"     display data      "<<endl;
    cout<<"-----------------------"<<endl;
    display(alldata);
    cout<<"     remove data       "<<endl;
    cout<<"-----------------------"<<endl;
    remove_(alldata , 5);
    cout<<"     display data      "<<endl;
    cout<<"-----------------------"<<endl;
    display(alldata);
return 0;
}
