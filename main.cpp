#include <iostream>
#include "queue.h"
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <locale.h>
using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    queue *head1 = NULL;
    queue *tail1 = NULL;
    queue *head2 = NULL;
    queue *tail2 = NULL;
    srand(time(NULL));
    double ob1 = 0; // ����� ��������� ��1
    double ob2 = 0; // ����� ��������� ��2
    int t;
    double a1 = 0;
    double a2 = 6;
    double b1 = 1;
    double b2 = 8;
    double tt = 0;
    double mozh1 = -1; //������������ �������� 1 ������
    double mozh2 = -1; //  ������������ �������� 2 ������
    double msred1 = -1; // ������� ����� �������� � ������� ������ 1
    double msred2 = -1; // ������� ����� �������� � ������� ������ 2
    int mnum = -1; //����� � ������������ ���������
    int mnum1 = -1; //����� � ������������ ��������� 1 ������
    int mnum2 = -1; //����� � ������������ ��������� 2 ������
    double count = 0; //����� ����� �������������+
    double k = 0; //����������,���������� �� ��,�� ����� ������� �������������� ������ � ��2
    int lenoch1 = 1000; // ����� ������� 1+
    int lenoch2 = 0; //����� ������� 2+
    int prinzayav1 = 0; // ���������� �������� ������ � ������� ����+
    int prinzayav2 = 0; // ���������� �������� ������ � ������� ���+
    double prostoi1 = 0; // ������� 1 +
    double prostoi2 = 0; // ������� 2 +

    for(int i = 1; i < 1001; i++) //���������� 1 �������
    {
        push(head1,tail1,i);
        tail1->prix = 0;
        tail1->vix = 0;
        tail1->ozh = 0;
    }

    while(prinzayav2 < 1000)  //��1
    {
        /*cout<<"1 �������" << endl;
                print(head1);
                cout <<"2 �������" << endl;
                print(head2);*/
        if(!queue_is_empty(head1))
        {


            t = rand() % 10;
            if(t < 7)
            {
                tt = (double) rand() / RAND_MAX;
                ob1 = (a2-a1)*tt + a1;
                count += ob1;
                prinzayav1++;
                head1->prix = count;
                queue *qst = pop(head1);
                if(head1 == NULL)
                {
                    tail1 = NULL;
                }
                push(head1,tail1,qst->id);
                tail1->prix = qst->prix;
                tail1->vix = 0;
                tail1->ozh = 0;
                delete(qst);
            }
            else
            {
                head1->ozh = count - head1->prix;
                if(head1->ozh > mozh1)
                {
                    mozh1 = head1->ozh;
                    mnum1 = head1->id;
                }
                msred1 += head1->ozh;
                tt = (double) rand() / RAND_MAX;
                ob1 = (a2-a1)*tt + a1;
                count += ob1;
                prinzayav1++;
                head1->vix = count;
                queue *lst = pop(head1);
                lenoch1--;
                push(head2,tail2,lst->id);
                lenoch2++;
                tail2->prix = lst->vix;
                tail2->vix = lst->vix;
                delete(lst);

            if(prinzayav2 == 0 && k == 0 && !queue_is_empty(head2))
            {
                tt = (double) rand() / RAND_MAX;
                ob2 = (b2-b1)*tt + b1;
                prostoi2 += head2->prix - k;
                k = count + ob2;
                queue *ast = pop(head2);
                lenoch2--;
                delete(ast);
                prinzayav2++;
                head2 = tail2 = NULL;

            }
            }
            if(count >= k && head2 == tail2 && head2!= NULL && tail2 != NULL)
            {
                tt = (double) rand() / RAND_MAX;
                ob2 = (b2-b1)*tt + b1;
                prostoi2 += head2->prix - k;
                k = count + ob2;
                queue *pst = pop(head2);
                lenoch2--;
                delete(pst);
                prinzayav2++;
                if(prinzayav2 % 100 == 0)
                {
                    if(mozh1 > mozh2)
                    {
                        mnum = mnum1;
                    }
                    else if(mozh2 > mozh1)
                    {
                        mnum = mnum2;
                    }
                    cout <<"���������� �������� ������ 1 ������� = " << prinzayav1 << endl
                         <<"���������� �������� ������ 2 ������� = " << prinzayav2 << endl
                         <<"����� 1 ������� = " << lenoch1 << endl <<"����� 2 ������� = " << lenoch2 << endl
                         << "����� ������ � ������������ �������� �������� = " << mnum << endl
                         <<"������������ ����� �������� � ������� 1 = " << mozh1 << endl
                         <<"������������ ����� �������� � ������� 2 = " << mozh2 << endl
                         <<"������� ����� �������� � ������� 1 = "<< msred1 / (lenoch2+prinzayav2) << endl
                         <<"������� ����� �������� � ������� 2 = " << msred2 / prinzayav2 << endl << endl;

                }

                head2 = tail2 = NULL;
            }
            if(count >= k && !queue_is_empty(head2))
            {
                head2->ozh = count - head2->prix;
                if(head2->ozh > mozh2)
                {
                    mozh2 = head2->ozh;
                    mnum2 = head2->id;
                }
                msred2 += head2->ozh;
                queue *sst = pop(head2);
                lenoch2--;
                tt = (double) rand() / RAND_MAX;
                ob2 = (b2-b1)*tt + b1;
                k += ob2;
                delete(sst);
                prinzayav2++;
                if(prinzayav2 % 100 == 0)
                {
                    if(mozh1 > mozh2)
                    {
                        mnum = mnum1;
                    }
                    else if(mozh2 > mozh1)
                    {
                        mnum = mnum2;
                    }
                    cout <<"���������� �������� ������ 1 ������� = " << prinzayav1 << endl
                         <<"���������� �������� ������ 2 ������� = " << prinzayav2 << endl
                         <<"����� 1 ������� = " << lenoch1 << endl <<"����� 2 ������� = " << lenoch2 << endl
                         << "����� ������ � ������������ �������� �������� = " << mnum << endl
                         <<"������������ ����� �������� � ������� 1 = " << mozh1 << endl
                         <<"������������ ����� �������� � ������� 2 = " << mozh2 << endl
                         <<"������� ����� �������� � ������� 1 = "<< msred1 / (lenoch2+prinzayav2) << endl
                         <<"������� ����� �������� � ������� 2 = "<< msred2 / prinzayav2 << endl << endl;

                }


            }


        }
        else
        {
            head2->ozh = count - head2->prix;
            if(head2->ozh > mozh2)
            {
                mozh2 = head2->ozh;
                mnum2 = head2->id;
            }
            queue *zst = pop(head2);
            lenoch2--;
            count  = k;
            tt = (double) rand() / RAND_MAX;
            ob2 = (b2-b1)*tt + b1;
            count += ob2;
            k = count;
            delete(zst);
            prinzayav2++;
            if(prinzayav2 % 100 == 0)
            {
                if(mozh1 > mozh2)
                {
                    mnum = mnum1;
                }
                else if(mozh2 > mozh1)
                {
                    mnum = mnum2;
                }
                cout <<"���������� �������� ������ 1 ������� = " << prinzayav1 << endl
                     <<"���������� �������� ������ 2 ������� = " << prinzayav2 << endl
                     <<"����� 1 ������� = " << lenoch1 << endl <<"����� 2 ������� = " << lenoch2 << endl
                     << "����� ������ � ������������ �������� �������� = " << mnum << endl
                     <<"������������ ����� �������� � ������� 1 = " << mozh1 << endl
                     <<"������������ ����� �������� � ������� 2 = " << mozh2 << endl
                     <<"������� ����� �������� � ������� 1 = "<< msred1 / (lenoch2+prinzayav2) << endl
                     <<"������� ����� �������� � ������� 2 = "<< msred2 / prinzayav2 << endl << endl;

            }

        }

    }
    cout <<"����� ����� ������������� = " << count << endl
         <<"����� ������� 1 = " << prostoi1 << endl
         <<"����� ������� 2 = " << prostoi2 << endl
         <<"���������� ��������� ������ ����� ��1 = " << prinzayav1 << endl
         <<"���������� ��������� ������ ����� ��2 = " << prinzayav2 << endl;

    return 0;

}

