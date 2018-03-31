#include<iostream>
using namespace std;
typedef struct node
{
    struct node *next;
    struct node *pre;
    char data[20];
}student;
student *creatlist(int len)
{
    student *head = new student;
    student *p = head;
    for(int i = 0;i < len;i ++)
    {
        student *stu = new student;
        cout<<"please input the data of student "<<i+1<<endl;
        cin>>stu->data;
        p->next = stu;
        stu->pre = p;
        p = stu;
        p->next = NULL;
    }
    return head;
}
void insert_(student *head , int index)
{
    student *p = head;
    student *stu = new student;
    cout<<"please input the data of student"<<endl;
    cin>>stu->data;
    for(int i = 0;i < index;i ++)
    {
        p = p->next;
    }
    stu->next = p->next;
    stu->pre = p;
    p->next = stu;
    stu->next->pre = stu;
    p = stu;
}
void remove_(student *head , int index)
{
    student *p = head;
    for(int i = 0;i < index + 1;i ++)
    {
        p = p->next;
    }
    student *del = p;
    p->pre->next = p->next;
    p->next->pre = p->pre;
    delete del;
}
void display(student *head)
{
    student *p = head;
    while(p != NULL)
    {
        cout<<p->data<<endl;
        p = p->next;
    }
}int main()
{
    student *head = creatlist(5);
    display(head);
    remove_(head , 2);
    insert_(head , 0);
    display(head);
    return 0;
}
