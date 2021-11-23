#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <locale.h>
#include <iostream>
using namespace std;
struct queue
{
    int id;
    double prix;
    double vix;
    double ozh;
    queue *prev;
    queue *next;
};

void push(queue*&head,queue*&tail, int num)
{
    queue*tmp = new queue;
    if(!head)
    {
        tmp->next = head;
        tmp->prev = tail;
        head = tmp;
        tail = tmp;
    }
    else
    {
        tmp->prev = tail->prev;
        tmp->next = tail;
        tail->prev = tmp;
        tail = tmp;
    }
    tmp->id = num;
}

void print(queue* head)
{
    while(head)
    {
        cout<<"Номер заявки = " << head->id<<endl
        <<"Время прихода заявки = " << head->prix<<endl
        <<"Время выхода заявки = " << head->vix<<endl
        <<"Время ожидания заявки  = " << head->ozh<<endl;
        head=head->prev;
    }
}

queue* pop(queue*&head)
{
    queue *tmp = head;
    head = head->prev;
    return tmp;
}
int top(queue*head)
{
    return head->id;
}
int queue_is_empty(queue *head)
{
    return !head;
}
#endif // QUEUE_H_INCLUDED
