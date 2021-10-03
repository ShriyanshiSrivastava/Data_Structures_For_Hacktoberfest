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
    cout<<"Hello World";
     gotoxy(48,1);
    cout<<"new line added";
    return 0;
}
