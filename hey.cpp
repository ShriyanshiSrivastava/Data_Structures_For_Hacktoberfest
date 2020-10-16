#include<iostream>

#include<conio.h>
#include<windows.h>

using namespace std;

void gotoxy(short x, short y)           //definition of gotoxy function//
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
    gotoxy(50,0);
    cout<<"my new branch code \n";


        gotoxy(45,1);
     cout<<"my new line in my branch code";
    return 0;
}
