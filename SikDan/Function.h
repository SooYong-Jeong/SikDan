#include <iostream>
using namespace std;
double basal_metabolism(int s, int a, double w, double h)
{
    if (s == 1)
        return 66.47 + (13.75 * w) + (5 * h) - (6.76 * a);
    else return 655.1 + (9.56 * w) + (1.85 * h) - (4.88 * a);
}
double Day_sum(int d, int n, double(*D_F)[255][6])
{
    double sum = 0;
    for (int i = 0; i < 255; i++)
        sum += D_F[d][i][n];
    return sum;
}
void print_emoji(int d, int n, double b, double(*D_F)[255][6])
{
    if (n == 0) {
        if (Day_sum(d, n, D_F) < 200)
            cout << ":)";
        else if (Day_sum(d, n, D_F) > 200)
            cout << ":(↑";
    }
    else if (n == 1)
    {
        if (Day_sum(d, n, D_F) < 70)
            cout << ":(↓";
        else if (Day_sum(d, n, D_F) > 70)
            cout << ":)";
    }
    else if (n == 2)
    {
        if (Day_sum(d, n, D_F) < b * 1.2 * 0.3 / 9)
            cout << ":(↓";
        else if (Day_sum(d, n, D_F) > b * 1.2 * 0.5 / 9)
            cout << ":(↑";
        else
            cout << ":)";
    }
    else if (n == 3)
    {
        if (Day_sum(d, n, D_F) < 25)
            cout << ":)";
        else if (Day_sum(d, n, D_F) > 25)
            cout << ":(↑";
    }
    else if (n == 4)
    {
        if (Day_sum(d, n, D_F) < 1500)
            cout << ":(↓";
        else if (Day_sum(d, n, D_F) > 3000)
            cout << ":(↑";
        else
            cout << ":)";
    }
    else if (n == 5)
    {
        cout << "   ";
    }
    else cout << "error";
}
void title()
{
    cout << "┌───────────────────────────────┐" << endl;
    cout << "│\t식단관리 프로그램\t│" << endl;
    cout << "└───────────────────────────────┘" << endl;
}
void mainscreen(string n, int s, int a, double w, double h, double b)
{
    cout << "┌───────────────────────────────┐" << endl;
    cout << "│이름:\t\t" << n << "\t\t│" << endl;
    if (s == 1)
        cout << "│성별:\t\t남\t\t│" << endl;
    else cout << "│성별:\t\t여\t\t│" << endl;
    cout << "│나이:\t\t" << a << "\t\t│" << endl;
    cout << "│키:\t\t" << h << "cm\t\t│" << endl;
    cout << "│몸무게:\t" << w << "Kg\t\t│" << endl;
    cout << "│기초대사량:\t" << b << "Kcal\t│" << endl;
    cout << "└───────────────────────────────┘" << endl;
}
void printday(string D_F_Name[], double(*D_F)[255][6], double b)
{
    cout << "\t\tDay1\t\tDay2\t\tDay3\t\tDay4\t\tDay5\t\tDay6\t\tDay7\t\t" << endl;
    for (int i = 0; i < 6; i++)
    {
        switch (i)
        {
        case 0: cout << "탄수화물"; break;
        case 1: cout << "단백질\t"; break;
        case 2: cout << "지방\t"; break;
        case 3: cout << "당류\t"; break;
        case 4: cout << "나트륨\t"; break;
        case 5: cout << "칼로리\t"; break;
        }
        for (int j = 0; j < 7; j++)
        {
            cout << "\t" << Day_sum(j, i, D_F) << "\t"; print_emoji(j, i, b, D_F);
            if (j == 6)
                cout << endl;
        }
    }
    cout << "\n\n탄수화물 200g이상 경고\t\t\t\t\t\t:)   : 적당\n\n단백질 70g 이하 경고\t\t\t\t\t\t:(↑ : 높음\n\n지방 ((기초대사량 + 활동대사량)*0.3/9)g이하 경고\t\t:(↓ : 낮음\n\n     ((기초대사량 + 활동대사량)*0.5/9)g이상 경고\t\t기초대사량 + 활동대사량 : " << b * 1.2 << "kcal\n\n당류 25g이상 경고\n\n나트륨 1500mg이하, 3000mg이상 경고\n" << endl;
}

void printlist(int a, string F_Name[], double(*F)[6])
{
    cout << "\t음식이름\t\t\t\t칼로리(kcal)\t" << "음식이름\t\t\t\t칼로리(kcal)" << endl;
    cout << "│ " << "1.\t 임의입력\t\t\t\t\t";
    for (int i = 0; i < a + 1; i++)
    {
        cout << "│ " << i + 2 << ".\t" << F_Name[i] << "\t" << F[i][5] << "\t";
        if ((i) % 2 == 0)
            cout << endl;
    }
    cout << endl;

}
void printall(int a, string F_Name[], double(*F)[6])
{
    cout << "\t\t\t\t" << "탄수화물\t단백질\t지방\t당류\t나트륨\t칼로리" << endl;
    cout << "1. 임의입력" << endl;
    for (int i = 0; i < a + 1; i++)
    {
        cout << i + 2 << ". ";
        cout << F_Name[i] << endl;
        cout << "\t\t\t\t" << F[i][0] << "g\t\t" << F[i][1] << "g\t" << F[i][2] << "g\t" << F[i][3] << "g\t" << F[i][4] << "mg\t  " << F[i][5] << "Kcal" << endl;
    }
}