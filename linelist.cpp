#include<iostream>
using namespace std;
typedef struct node{
    struct node *next;
    char data[20];
}student;
student *creatlist(int n)
{
    student *head = new student;
    student *p = head;
    for(int i = 0;i < n;i ++)
    {
        student *stu = new student;
        cout<<"please input the data of student"<<i+1<<endl;
        cin>>stu->data;
        p->next = stu;
        p = stu;
        p->next = NULL;
    }
    return head;
}
void display(student *head)
{
    student *p = head->next;
    while(p != NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}
void insertlist(student* head , int index)
{
    student *p = head;
    for(int i = 0;i < index;i ++)
    {
        p = p->next;
    }
    student *stu = new student;
    cout<<"please input the data of new student"<<endl;
    cin>>stu->data;
    stu->next = p->next;
    p->next = stu;
}
void removelist(student *head , int index)
{
    student *p = head;
    for(int i = 0;i < index;i ++)
    {
        p = p->next;
    }
    student *del = new student;
    del = p->next;
    p->next = p->next->next;
    delete del;
}
int main()
{
    student *head = creatlist(5);
    display(head);
    insertlist(head , 1);
    removelist(head , 2);
    display(head);
    return 0;
}
