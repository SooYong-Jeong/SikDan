#include <iostream>
#include "DB.h"
#include "Function.h"
using namespace std;
void main()
{
    string D_F_Name[255];
    double D_F[7][255][6] = { 0 };
    int f_num = 0;
    int F_num = 51;
    int k, day, food, n;
    double car, pro, fat, sug, na, cal;
    string name = "";
    int sex = 0;
    int age = 0;
    double weight = 0;
    double height = 0;
    double basal = 0;
start:
    title();
    cout << "�̸� :\t\t\t";
    cin >> name;
    system("cls");
    title();
    cout << "����(1.�� 2.��) :\t";
    cin >> sex;
    system("cls");
    title();
    cout << "���� : \t\t\t";
    cin >> age;
    system("cls");
    title();
    cout << "������ :\t\t";
    cin >> weight;
    system("cls");
    title();
    cout << "Ű :\t\t\t";
    cin >> height;
    system("cls");
    basal = basal_metabolism(sex, age, weight, height);
    title();
    mainscreen(name, sex, age, weight, height, basal);

    while (1)
    {
        cout << "1. �����Է�  2. Į�θ� ��ȸ(�ְ�) 3. ���� �� ��ȸ 4. ó������ " << endl;
        cin >> k;
        system("cls");
        if (k == 1)
        {
            cout << "Day :";
            cin >> day;
            while (1)
            {
                printlist(F_num, F_Name, F);
                cout << "���Ĺ�ȣ : (��� �Է��Ͽ��ٸ� 0):";
                cin >> food;
                if (food == 0)
                    break;
                else if (food == 1)
                {
                    system("cls");
                    F_num++;
                    cout << "�����̸� :\t";
                    cin >> name;
                    F_Name[F_num] = name;
                    cout << "ź��ȭ�� :\t";
                    cin >> car;
                    F[F_num][0] = car;
                    cout << "�ܹ��� :\t";
                    cin >> pro;
                    F[F_num][1] = pro;
                    cout << "���� :  \t";
                    cin >> fat;
                    F[F_num][2] = fat;
                    cout << "��� :  \t";
                    cin >> sug;
                    F[F_num][3] = sug;
                    cout << "��Ʈ�� :\t";
                    cin >> na;
                    F[F_num][4] = na;
                    cout << "Į�θ� :\t";
                    cin >> cal;
                    F[F_num][5] = cal;

                    cout << "��� :";
                    cin >> n;
                    system("cls");
                    for (int i = 0; i < 6; i++)
                        D_F[day - 1][f_num][i] = n * F[F_num][i];
                    f_num++;
                }
                else
                {
                    cout << "��� :";
                    cin >> n;
                    system("cls");
                    for (int i = 0; i < 6; i++)
                        D_F[day - 1][f_num][i] = n * F[food][i];
                    f_num++;
                }
            }
        }
        else if (k == 2)
            printday(D_F_Name, D_F, basal);
        else if (k == 3)
            printall(F_num, F_Name, F);
        else if (k == 4)
            goto start;
    }
}