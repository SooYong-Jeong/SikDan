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
    cout << "이름 :\t\t\t";
    cin >> name;
    system("cls");
    title();
    cout << "성별(1.남 2.여) :\t";
    cin >> sex;
    system("cls");
    title();
    cout << "나이 : \t\t\t";
    cin >> age;
    system("cls");
    title();
    cout << "몸무게 :\t\t";
    cin >> weight;
    system("cls");
    title();
    cout << "키 :\t\t\t";
    cin >> height;
    system("cls");
    basal = basal_metabolism(sex, age, weight, height);
    title();
    mainscreen(name, sex, age, weight, height, basal);

    while (1)
    {
        cout << "1. 음식입력  2. 칼로리 조회(주간) 3. 음식 상세 조회 4. 처음으로 " << endl;
        cin >> k;
        system("cls");
        if (k == 1)
        {
            cout << "Day :";
            cin >> day;
            while (1)
            {
                printlist(F_num, F_Name, F);
                cout << "음식번호 : (모두 입력하였다면 0):";
                cin >> food;
                if (food == 0)
                    break;
                else if (food == 1)
                {
                    system("cls");
                    F_num++;
                    cout << "음식이름 :\t";
                    cin >> name;
                    F_Name[F_num] = name;
                    cout << "탄수화물 :\t";
                    cin >> car;
                    F[F_num][0] = car;
                    cout << "단백질 :\t";
                    cin >> pro;
                    F[F_num][1] = pro;
                    cout << "지방 :  \t";
                    cin >> fat;
                    F[F_num][2] = fat;
                    cout << "당류 :  \t";
                    cin >> sug;
                    F[F_num][3] = sug;
                    cout << "나트륨 :\t";
                    cin >> na;
                    F[F_num][4] = na;
                    cout << "칼로리 :\t";
                    cin >> cal;
                    F[F_num][5] = cal;

                    cout << "배수 :";
                    cin >> n;
                    system("cls");
                    for (int i = 0; i < 6; i++)
                        D_F[day - 1][f_num][i] = n * F[F_num][i];
                    f_num++;
                }
                else
                {
                    cout << "배수 :";
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