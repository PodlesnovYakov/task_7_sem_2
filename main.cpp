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
    double ob1 = 0; // время обработки ОА1
    double ob2 = 0; // время обработки ОА2
    int t;
    double a1 = 0;
    double a2 = 6;
    double b1 = 1;
    double b2 = 8;
    double tt = 0;
    double mozh1 = -1; //максимальное ожидание 1 заявки
    double mozh2 = -1; //  максимальное ожидание 2 заявки
    double msred1 = -1; // среднее время ожидание в очереди заявки 1
    double msred2 = -1; // среднее время ожидание в очереди заявки 2
    int mnum = -1; //номер с максимальным ожиданием
    int mnum1 = -1; //номер с максимальным ожиданием 1 заявки
    int mnum2 = -1; //номер с максимальным ожиданием 2 заявки
    double count = 0; //общее время моделирования+
    double k = 0; //переменная,отвечающая за то,на каком моменте обрабатывается заявка в ОА2
    int lenoch1 = 1000; // длина очереди 1+
    int lenoch2 = 0; //длина очереди 2+
    int prinzayav1 = 0; // количество принятых заявок в очереди один+
    int prinzayav2 = 0; // количество принятых заявок в очереди два+
    double prostoi1 = 0; // простой 1 +
    double prostoi2 = 0; // простой 2 +

    for(int i = 1; i < 1001; i++) //заполнение 1 очереди
    {
        push(head1,tail1,i);
        tail1->prix = 0;
        tail1->vix = 0;
        tail1->ozh = 0;
    }

    while(prinzayav2 < 1000)  //ОА1
    {
        /*cout<<"1 очередь" << endl;
                print(head1);
                cout <<"2 очередь" << endl;
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
                    cout <<"Количество принятых заявок 1 очереди = " << prinzayav1 << endl
                         <<"Количество принятых заявок 2 очереди = " << prinzayav2 << endl
                         <<"Длина 1 очереди = " << lenoch1 << endl <<"Длина 2 очереди = " << lenoch2 << endl
                         << "Номер заявки с максимальным временем ожидания = " << mnum << endl
                         <<"Максимальное время ожидания в очереди 1 = " << mozh1 << endl
                         <<"Максимальное время ожидания в очереди 2 = " << mozh2 << endl
                         <<"Среднее время ожидания в очереди 1 = "<< msred1 / (lenoch2+prinzayav2) << endl
                         <<"Среднее время ожидания в очереди 2 = " << msred2 / prinzayav2 << endl << endl;

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
                    cout <<"Количество принятых заявок 1 очереди = " << prinzayav1 << endl
                         <<"Количество принятых заявок 2 очереди = " << prinzayav2 << endl
                         <<"Длина 1 очереди = " << lenoch1 << endl <<"Длина 2 очереди = " << lenoch2 << endl
                         << "Номер заявки с максимальным временем ожидания = " << mnum << endl
                         <<"Максимальное время ожидания в очереди 1 = " << mozh1 << endl
                         <<"Максимальное время ожидания в очереди 2 = " << mozh2 << endl
                         <<"Среднее время ожидания в очереди 1 = "<< msred1 / (lenoch2+prinzayav2) << endl
                         <<"Среднее время ожидания в очереди 2 = "<< msred2 / prinzayav2 << endl << endl;

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
                cout <<"Количество принятых заявок 1 очереди = " << prinzayav1 << endl
                     <<"Количество принятых заявок 2 очереди = " << prinzayav2 << endl
                     <<"Длина 1 очереди = " << lenoch1 << endl <<"Длина 2 очереди = " << lenoch2 << endl
                     << "Номер заявки с максимальным временем ожидания = " << mnum << endl
                     <<"Максимальное время ожидания в очереди 1 = " << mozh1 << endl
                     <<"Максимальное время ожидания в очереди 2 = " << mozh2 << endl
                     <<"Среднее время ожидания в очереди 1 = "<< msred1 / (lenoch2+prinzayav2) << endl
                     <<"Среднее время ожидания в очереди 2 = "<< msred2 / prinzayav2 << endl << endl;

            }

        }

    }
    cout <<"Общее время моделирования = " << count << endl
         <<"Время простоя 1 = " << prostoi1 << endl
         <<"Время простоя 2 = " << prostoi2 << endl
         <<"Количество прошедших заявок через ОА1 = " << prinzayav1 << endl
         <<"Количество прошедших заявок через ОА2 = " << prinzayav2 << endl;

    return 0;

}

