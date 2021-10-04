#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int XOBoard[3][3];                                                                    /*global variable board */
class Player                                                                        /*Class of Players*/
{
public:
      int win;
      int win_counter;                                                              /*Variable to find out whether Player has won with the current move*/
      int ny;                                                                       /*Variable to input whether user wants to play again or not*/
      int tie_chk;
      Player()                                                                      /*Constructor to preset the game board*/
      {
              win=0;         
              for (int column=0;column<3;column++)
                  {
                       for (int row=0;row<3;row++)
                       {
                           XOBoard[column][row] = 0;
                       }
                   }
      }
 	char Playername[25];
    	void get_player_name()
     	{
         cout << "\n\t\t    Please enter your name : ";
        		cin.getline(Playername,25);
         }

      void Draw()                                                                   /*Function of Player class to draw the game board  */
      {
           
           cout<<"\n\n\n\n\n";
           cout<<"\t\t\t            Top        ";
           cout<<"\n\t\t\t***************************\n";
           cout<<"\t\t\t*  .  1       2       3   *\n\t\t\t*.........................*\n";
           if ( XOBoard[0][0] == 0 )                                                  /*If else condition to draw the game board */
           {
              cout<<"\t\t\t* 1.     |";
           }
           else if ( XOBoard[0][0] == 1) 
           {
                cout<<"\t\t\t* 1.  X  |";
                }
           else if ( XOBoard[0][0] == -1) {
                cout<<"\t\t\t* 1.  O  |";
                }
           if ( XOBoard[1][0] == 0) {
                cout<<"        |";
                }
           else if ( XOBoard[1][0] == 1) {
                cout<<"    X   |";
                }
           else if ( XOBoard[1][0] == -1) {
                cout<<"    O   |";
                }
           if ( XOBoard[2][0] == 0) {
                cout<<"       *";
                }
           else if ( XOBoard[2][0] == 1) {
                cout<<"   X   *";
           }
           else if ( XOBoard[2][0] == -1) {
                cout<<"   O   *";
                }
           cout<<"\n\t\t\t*  .----------------------*\n";
           if ( XOBoard[0][1] == 0) {
              cout<<"\t\t  Side  * 2.     |";
              }
           else if ( XOBoard[0][1] == 1) {
                cout<<"\t\t  Side  * 2.  X  |";
                }
           else if ( XOBoard[0][1] == -1) {
                cout<<"\t\t  Side  * 2.  O  |";
                }
           if ( XOBoard[1][1] == 0) {
                cout<<"        |";
                }
           else if ( XOBoard[1][1] == 1) {
                cout<<"    X   |";
                }
           else if ( XOBoard[1][1] == -1) {
                cout<<"    O   |";
                }
           if ( XOBoard[2][1] == 0) {
                cout<<"       *";
                }
           else if ( XOBoard[2][1] == 1) {
                cout<<"   X   *";
                }
           else if ( XOBoard[2][1] == -1) {
                cout<<"   O   *";
                }
           cout<<"\n\t\t\t*  .----------------------*\n";
           if ( XOBoard[0][2] == 0) {
              cout<<"\t\t\t* 3.     |";
              }
           else if ( XOBoard[0][2] == 1) {
                cout<<"\t\t\t* 3.  X  |";
                }
           else if ( XOBoard[0][2] == -1) {
                cout<<"\t\t\t* 3.  O  |";
                }
           if ( XOBoard[1][2] == 0) {
                cout<<"        |";
                }
           else if ( XOBoard[1][2] == 1) {
                cout<<"    X   |";
                }
           else if ( XOBoard[1][2] == -1) {
                cout<<"    O   |";
                }
           if ( XOBoard[2][2] == 0) {
                cout<<"       *";
                }
           else if ( XOBoard[2][2] == 1) {
                cout<<"   X   *";
                }
           else if ( XOBoard[2][2] == -1) {
                cout<<"   O   *";
                }
           cout<<"\n\t\t\t***************************\n";
           }

      int Human_win()                                                                    /*function of class Player to output when user has won*/
      {
         
         Draw();
         cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t   You beat me to it!!!!";
         cin.get();
         win=1;   
         Draw();     
         return win;                                                             /*return 1 when user has won the game*/
      }
      int Computer_win()                                                                    /*function of class Player to output when computer has won*/
      {
           
           Draw();
           cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tI, the computer has won possesion of the entire land!!!!";
           cin.get();
           win=1;
           Draw();
           return win;                                                             /*return 1 when computer has won the game*/
      }
      int chkwinner()                                                               /*function of class Player to check if either Player has won the game*/
      {
	win=0;
           if ( XOBoard[0][0] == 1 && XOBoard[1][0] == 1 && XOBoard[2][0] == 1 ) {
           Human_win();
           }
           else if ( XOBoard[0][1] == 1 && XOBoard[1][1] == 1 && XOBoard[2][1] == 1 ) {
           Human_win();
           }
           else if ( XOBoard[0][2] == 1 && XOBoard[1][2] == 1 && XOBoard[2][2] == 1 ) {
           Human_win();
           }
      
           else if ( XOBoard[0][0] == 1 && XOBoard[0][1] == 1 && XOBoard[0][2] == 1 ) {
           Human_win();
           }
           else if ( XOBoard[1][0] == 1 && XOBoard[1][1] == 1 && XOBoard[1][2] == 1 ) {
           Human_win();
           }
           else if ( XOBoard[2][0] == 1 && XOBoard[2][1] == 1 && XOBoard[2][2] == 1 ) {
           Human_win();
           }
      
           else if ( XOBoard[0][0] == 1 && XOBoard[1][1] == 1 && XOBoard[2][2] == 1 ) {
           Human_win();
           }
           else if ( XOBoard[2][0] == 1 && XOBoard[1][1] == 1 && XOBoard[0][2] == 1 ) {
           Human_win();
           }
           if ( XOBoard[0][0] == -1 && XOBoard[1][0] == -1 && XOBoard[2][0] == -1 ) {
           Computer_win();
           }
           else if ( XOBoard[0][1] == -1 && XOBoard[1][1] == -1 && XOBoard[2][1] == -1 ) {
           Computer_win();
           }
           else if ( XOBoard[0][2] == -1 && XOBoard[1][2] == -1 && XOBoard[2][2] == -1 ) {
           Computer_win();
           }
           else if ( XOBoard[0][0] == -1 && XOBoard[0][1] == -1 && XOBoard[0][2] == -1 ) {
           Computer_win();
           }
           else if ( XOBoard[1][0] == -1 && XOBoard[1][1] == -1 && XOBoard[1][2] == -1 ) {
           Computer_win();
           }
           else if ( XOBoard[2][0] == -1 && XOBoard[2][1] == -1 && XOBoard[2][2] == -1 ) {
           Computer_win();
           }
           else if ( XOBoard[0][0] == -1 && XOBoard[1][1] == -1 && XOBoard[2][2] == -1 ) {
           Computer_win();
           }
           else if ( XOBoard[2][0] == -1 && XOBoard[1][1] == -1 && XOBoard[0][2] == -1 ) {
           Computer_win();
           }
           return win;                                                             /*returns the value of win counter to calling function*/
}
     void Reset_board ()                                                                  /*fucntion of class Player to reset the game board*/
     {
     int column;
     for (column=0; column<3; column++) {
         XOBoard[column][0] = 0;
         XOBoard[column][1] = 0;
         XOBoard[column][2] = 0;
     }
     }
     void fill_XOBoard(int column, int row, int move_by)                                           /*function of class Player that sets the board after every move*/
     {
          XOBoard[column][row]=move_by;
          }
     bool used_cell_check_for_Human(int column, int row)                                                   /*function of class Player to check whether the cell inout by Player has been occupied earlier or not*/
     {
          if (XOBoard[column][row] == 1 || XOBoard[column][row] == -1) 
          {
          if (XOBoard[column][row] == -1)
          cout<<"\n\n\t      I have already played that cell, Chose another cell.\n\n";           
          if (XOBoard[column][row] == 1)
          cout<<"\n\n\t\tDo you want to keep choosing the same cell...\n\t\t    You have already played with this cell. \n\n\t\t\t    Chose another cell!!!";           
          return false;
          }
          else
             return true;
      }
      bool used_cell_check_for_Computer(int column, int row)                                                   /*function of class Player to check whether the cell inout by Player has been occupied earlier or not*/
     {
          if (XOBoard[column][row] == 1 || XOBoard[column][row] == -1) 
          {
          return false;
          }
          else
             return true;
      }
      int Chk_tie()
      {
       int checking=0;
       checking=chk_cols();
       if (checking==1)
       return checking;
       checking=chk_rows();
       if (checking==1)
       return checking;
       checking=chk_diags();
       return checking;
       }
       
          int chk_cols()                                              /*function of class computer to check if any Player can win by filling any columns*/
          {
           for (int column=0,row=0;column<3;column++)
           {
             if (XOBoard[column][row]+XOBoard[column][row+1]+XOBoard[column][row+2]==2)
             {
                 tie_chk=1;
                 break;
                 }
                 else 
                 tie_chk=0; 
                 }
           return tie_chk;
           }
      

           int chk_rows()                                              /*function of class computer to any Player if computer can win by filling any rows*/
           {
           for (int column=0,row=0;column<3;column++)
           {
             if (XOBoard[row][column]+XOBoard[row+1][column]+XOBoard[row+2][column]==2)
             {
                 tie_chk=1;
                 break;
                 }
                 else 
                 tie_chk=0;
                 } 
          return tie_chk;
          }
          

      int chk_diags()                                             /*function of class computer to check if any Player can win by filling any diagonals*/
      {
       if ((XOBoard[0][0]+XOBoard[1][1]+XOBoard[2][2]==2)||(XOBoard[0][2]+XOBoard[1][1]+XOBoard[2][0]== 2))                      
       {
                tie_chk=1;
                 }
                 else 
                 tie_chk=0; 
       return tie_chk;
                 } 
      
                
};                                                                                 /*end class Player*/
      
class Human_Player : public Player                                                        /*inherited class human from Player class*/
{
      int column, row, move_by;
      char input_check;
      public:
             
      int input_Human_Player_move()                                                       /*function to input human move. The function passes the move to the used_cell and fill_XOBoard function of Player class*/
      {
          
       
       do 
       {
                 do 
       {
                 cout<<"\n\n\n\n\t\t     Choose a top coordinate (1, 2, 3): ";
                 cin>> input_check;                
                 column=int(input_check);             
                 
                 if (column<49 || column>51)
                 cout<<"\n\n\t\t  \a\a\aInvalid input...Please read instructions. \n\t\t  Input can only be 1, 2, or 3!!!\n\t\t\t  Try Again!!!";
                 }while (column<49 || column>51);
                 column = column - 49;
        do {
                 cout<<"\n\n\t\t     Choose a side coordinate (1, 2, 3): ";
                 cin>> input_check;                
                 row=int(input_check);             
                 
                 if (row<49 || row>51)
                 cout<<"\n\n\t\t  \a\a\aInvalid input...Please read instructions. \n\t\t  Input can only be 1, 2, or 3!!!\n\t\t\t  Try Again!";
                 }while (row<49 || row>51);
                 row = row - 49;         
                
              } while ( !used_cell_check_for_Human(column,row));
              move_by=1;
              fill_XOBoard(column, row, move_by);
       win_counter=chkwinner();          
       return win_counter;                                                         /*returns the value of win_counter to calling function*/
       }
};                                                                                 /*end class human*/
      
class Computer_Player: public Player                                                     /*inherited class computer from Player class*/
{
      int column, row, move_by,blank;
      bool movemade;                                                               /*boolean value to indicate when computer has made its move*/
      public:
      int comp_move()                                                              /*function of class computer to decide next move*/
      {
          
          movemade=false;                                                          /*set movemade to false */
          chk_rows(-2);                                                            /*check if computer can win by filling any rows*/
          if (movemade==false)
          chk_cols(-2);                                                            /*check if computer can win by filling any columns*/
          if (movemade==false)
          chk_diags(-2);                                                           /*check if computer can win by filling any diagonals*/
          if (movemade==false)
          chk_rows(2);                                                             /*check if user can win by filling any rows and hence block*/
          if (movemade==false)
          chk_cols(2);                                                             /*check if user can win by filling any columns and hence block*/
          if (movemade==false)
          chk_diags(2);                                                            /*check if user can win by filling any diagnonals and hence block*/
          if (movemade==false)
          Random_move();                                                                   /*if neither can win call function to generate randon cell to play*/
          win_counter=chkwinner();                                                 
          return win_counter;                                                      /*returns the value of win_counter to calling function*/
          }
      void chk_cols(int human_chance)                                              /*function of class computer to check if any Player can win by filling any columns*/
      {
           for (int column=0,row=0;column<3;column++)
           {
             if (XOBoard[column][row]+XOBoard[column][row+1]+XOBoard[column][row+2]==human_chance)
             {
                 int blank;
                 blank = chk_winning_cell(XOBoard[column][row],XOBoard[column][row+1],XOBoard[column][row+2]);    /*check which cell is blank in the sequence*/
                 XOBoard[column][blank]=-1;
                 movemade=true; 
                 if(human_chance==2)
                 {cout<<"\n\n\n\t\t  That was a good try...now check out my move!!!";
                 cout<<"\n\n\t\tI choose the top coordinate "<<column+1<<" and side coordinate "<<blank+1; }
                 else if (human_chance==-2)
                 cout<<"\n\n\n\t\tLet us see what happens if i choose top coordinate "<<column+1<<" \n\t\tand side coordinate "<<blank+1<<" ...You Loose!!!";
                 } 
           }
      }

      void chk_rows(int human_chance)                                              /*function of class computer to any Player if computer can win by filling any rows*/
      {
           for (int column=0,row=0;column<3;column++)
           {
             if (XOBoard[row][column]+XOBoard[row+1][column]+XOBoard[row+2][column]==human_chance)
             {
                blank = chk_winning_cell(XOBoard[row][column],XOBoard[row+1][column],XOBoard[row+2][column]);  /*check which cell is blank in the sequence*/
                XOBoard[blank][column]=-1;
                movemade=true;
                if(human_chance==2)
                 cout<<"\n\n\n\t\tYou thought I was not guarding my land on rows!!! You are wrong";
                 else if (human_chance==-2)
                 cout<<"\n\n\n\t\tBad luck !!!you lose with my next move."; 
                cout<<"\n\n\t\t  I choose the top coordinate "<<blank+1<<" and side coordinate "<<column+1;
             } 
          }
      }

      void chk_diags(int human_chance)                                             /*function of class computer to check if any Player can win by filling any diagonals*/
      {
       int i;
       if (XOBoard[0][0]+XOBoard[1][1]+XOBoard[2][2]==human_chance)                      
       {
                blank = chk_winning_cell(XOBoard[0][0],XOBoard[1][1],XOBoard[2][2]);     /*check which cell is blank in the sequence*/
                fill_XOBoard(blank,blank,-1);
                movemade=true;
                if(human_chance==2)
                 cout<<"\n\n\n\t\t\t    That was a good try!!!\n\t\tPlaying that diagonal game with me...now check out my move!!!";
                 else if (human_chance==-2)
                 cout<<"\n\n\n\t\tYou have wasted too much of my time, ...I want to end this...\n\t\tend this with my next move hahaha";
                cout<<"\n\n\n\t\tI chose the top coordinate "<<blank+1<<" and side coordinate "<<blank+1;
                
       }
       if(movemade==false)
       {
        if (XOBoard[0][2]+XOBoard[1][1]+XOBoard[2][0]== human_chance)       
           {
                blank = chk_winning_cell(XOBoard[0][2],XOBoard[1][1],XOBoard[2][0]);     /*check which cell is blank in the sequence*/
                if (blank==0)
                {
                XOBoard[0][2]=-1;
                if(human_chance==2)
                 cout<<"\n\n\n\t\t  That was a good try...now check out my move!!!";
                 else if (human_chance==-2)
                 cout<<"\n\n\n\t\t  That was a good try...\n\t\tPlaying that diagonal game with me...\n\t\tnow check out my move!!!";
                cout<<"\n\n\t\tI choose the top coordinate 1 and side coordinate 3";
                 
                 }
                else if (blank==1)
                {
                XOBoard[1][1]=-1;
                if(human_chance==2)
                 cout<<"\n\n\n\t\t  That was a good try...now check out my move!!!";
                 else if (human_chance==-2)
                 cout<<"\n\n\n\t\tThat was a good try...\n\t\tPlaying that diagonal game with me...\n\t\tnow check out my move!!!";
                cout<<"\n\n\t\tI choose the top coordinate 2 and side coordinate 2";
                }
                else 
                {
                XOBoard[2][0]=-1;
                if(human_chance==2)
                 cout<<"\n\n\t\t  That was a good try...now check out my move!!!";
                 else if (human_chance==-2)
                 cout<<"\n\n\n\t\tThat was a good try...\n\t\tPlaying that diagonal game with me...\n\t\tnow check out my move!!!";
                cout<<"\n\n\t\tI choose the top coordinate 3 and side coordinate 1";
                }
                movemade=true;                }                      
        }
      }
      int chk_winning_cell(int cell1,int cell2,int cell3)                                      /*function of class computer to check blank cell to make move*/
          {
           if (cell1==0)
           return 0;
           else if (cell2==0)
           return 1;
           else if (cell3==0)
           return 2;                    
          }
    
    void Random_move()                                                                     /*function of class computer to generate random cell to make move*/
      {
           
              do
               {
              if (XOBoard[1][1]==0)
              {
                   column=1;
                   row=1;
                   }
              else if ( XOBoard[0][0]==0)
              {
                   column=0;
                   row=0;    
                   }
              else if ( XOBoard[2][2]==0)
                    {
                   column=2;
                   row=2;    
                   }
              else if ( XOBoard[2][0]==0)
                    {
                   column=2;
                   row=0;    
                   }                                    
              else if ( XOBoard[0][2]==0)
                    {
                   column=0;
                   row=2;    
                   }   
              else 
              {
               
               do {
                     column = rand()%10;
                     row = rand()%10;
                  } while (column <= 0 || column >= 4 || row <= 0 || row >= 4);
                  column = column - 1;
                  row = row - 1;
              
               }
} while ( !used_cell_check_for_Computer(column,row));
                  
                   fill_XOBoard(column,row,-1);
           
           cout<<"\n\n\t\tI choose the top coordinate "<<column+1<<" and side coordinate "<< row+1;
           chkwinner();
     }
};                                                                                 /*end class computer*/

int main()                                                                         /*main function begins*/
{
     Player Play;                                                                     /*object of class Player*/
     Human_Player h;                                                                      /*object of class human*/
     Computer_Player c;
     
     int trn=1;                                                                    /*variable to denote turn of Player*/
     int i=1;
     char ch='y';                                                                  /*character to input if Player wants to play again or not*/
     int winner=0;                                                                   /*integer to denote winner*/
     int ctrl1,ctrl2;                                                                   /*integer to denote winner*/
     int ctr=0;
     int check_for_tie;
     char begin, Instruct;
     
     
         cout<<"\n\n\n\n\n";
         
         
         cout<<"\n**     **  ********  *******";
         cout<<"\n**     **  ********  ********";
         cout<<"\n**     **  **    **  **    **";
         cout<<"\n**  *  **  ********  *******";
         cout<<"\n** *** **  ********  *******";
         cout<<"\n***   ***  **    **  **    **";
         cout<<"\n**     **  **    **  **    **";
         cout<<"\n\n\n";
         for(ctrl1 = 0; ctrl1 < 2000; ctrl1++)
         {
          for(ctrl2 = 0; ctrl2 < 20000; ctrl2++)
           {
           }
           }        
         cout<<"\n\t\t********  ********";
         cout<<"\n\t\t********  ********";
         cout<<"\n\t\t**    **  **";
         cout<<"\n\t\t**    **  *****";
         cout<<"\n\t\t**    **  *****";
         cout<<"\n\t\t********  **";
         cout<<"\n\t\t********  **";
         cout<<"\n\n\n";
         for(ctrl1 = 0; ctrl1 < 2000; ctrl1++)
         {
          for(ctrl2 = 0; ctrl2 < 20000; ctrl2++)
           {
           }
           }
         cout<<"\n\t\t\t********  **    **  ********";
         cout<<"\n\t\t\t********  **    **  ********";
         cout<<"\n\t\t\t   **     ********  **";
         cout<<"\n\t\t\t   **     ********  *****";
         cout<<"\n\t\t\t   **     **    **  **";
         cout<<"\n\t\t\t   **     **    **  ********";
         cout<<"\n\t\t\t   **     **    **  ********";
         cout<<"\n\n\n";
         for(ctrl1 = 0; ctrl1 < 2000; ctrl1++)
         {
          for(ctrl2 = 0; ctrl2 < 20000; ctrl2++)
           {
           }
           }
         cout<<"\n\t\t\t       **        ********  **    **  *******    *******";
         cout<<"\n\t\t\t       **        ********  ***   **  ********  ********";
         cout<<"\n\t\t\t       **        **    **  ****  **  **    **   **";
         cout<<"\n\t\t\t       **        ********  ** ** **  **    **    **";
         cout<<"\n\t\t\t       **        ********  **  ****  **    **      **";
         cout<<"\n\t\t\t       ********  **    **  **   ***  ********  ********";
         cout<<"\n\t\t\t       ********  **    **  **    **  *******   *******";
        
     cout<<"\n\n\n\n\n\t\t    Welcome to the game WAR OF THE LANDS.\n\n\t\t";    
     Play.get_player_name();
     cout<<"\nHello "<<Play.Playername<<", I need to tell you the story of War of the Lands. ";
     cout<<"\nDo you want to read the instructions or simply proceede with the game ? \n(R)ead or (P)roceede :";
     cin>>Instruct;
     if (Instruct=='R' ||Instruct=='r')
     {
   



 
     
     //cin>>Human.name;
     
     cout<<"\n\n     A disputed area of 900 square meters lies between two neighboring villages. ";
     cout<<"\n     The dispute between the neighboring villages has been running for  ";
     cout<<"\n     generations. The government has finally taken a decision to resolve  ";
     cout<<"\n     the dispute and grant the possession of this land to one of the ";
     cout<<"\n     villages using a fair method. ";
     cout<<"\n\n\n     The government has divided the disputed land into 9 equal square plots each";
     cout<<"\n     of 300 square meters as shown in the following figure:";
     for(ctrl1 = 0; ctrl1 < 2000; ctrl1++)
         {
          for(ctrl2 = 0; ctrl2 < 20000; ctrl2++)
           {
           }
           }
     Play.Draw(); 
     for(ctrl1 = 0; ctrl1 < 2000; ctrl1++)
         {
          for(ctrl2 = 0; ctrl2 < 20000; ctrl2++)
           {
           }
           }
    







 cout<<"\n\n     The following method will be used to grant possession of the land to \n     one of the villages: ";      
     for(ctrl1 = 0; ctrl1 < 2000; ctrl1++)
         {
          for(ctrl2 = 0; ctrl2 < 80000; ctrl2++)
           {
           }
           }
     cout<<"\n\n     The government has decided that the entire land will be given to the \n     village that makes three successful plantations.";
     for(ctrl1 = 0; ctrl1 < 2000; ctrl1++)
         {
          for(ctrl2 = 0; ctrl2 < 80000; ctrl2++)
           {
           }
           }
     cout<<"\n\n     At one point of time, only one village will plant vegetation on a \n     square plot. Each village will be given a fair chance to grow \n     vegetation in a square block, turn-by-turn.";
     for(ctrl1 = 0; ctrl1 < 2000; ctrl1++)
         {
          for(ctrl2 = 0; ctrl2 < 80000; ctrl2++)
           {
           }
           }
     cout<<"\n\n     The first village that will plant vegetation on three square plots\n     from one corner to the opposite corner (vertically, horizontally,\n     or diagonally) will be given possession. For example,\n     on plots (1,1), (2,2) and (3,3) or (2,1), (2,2), and (2, 3) and so on";
     for(ctrl1 = 0; ctrl1 < 2000; ctrl1++)
         {
          for(ctrl2 = 0; ctrl2 < 80000; ctrl2++)
           {
           }
           }

     cout<<"\n\n     Each village can plant in a way to block the other village from planting\n     vegetation in three consecutive plots of land.";
     for(ctrl1 = 0; ctrl1 < 2000; ctrl1++)
         {
          for(ctrl2 = 0; ctrl2 < 80000; ctrl2++)
           {
           }
           }
     cout<<"\n\n     In case all the plots have been planted and neither village has planted\n     threeconsecutive plots of land, the government holds\n     possession of the entire land. Both villages will be then\n     given another chance to restart the plantation all over again.";
          for(ctrl1 = 0; ctrl1 < 2000; ctrl1++)
         {
          for(ctrl2 = 0; ctrl2 < 80000; ctrl2++)
           {
           }
           }
     cout<<"\n\n     In the current scenario, one village is represented by I, the computer\n     and the other village is by you, that is "<<Play.Playername<<".\n     The decision that who makes the first move lies with the you.\n     Your plantation will be represented by 'X' on the plot of land\n     and the computer's by 'O'.";       
     cout<<"\n\n     Each player will choose a plot of land by selecting the top and left\n     coordinate pointing to the specific plot of land.";    
     
      
}
while(ch=='y' || ch=='Y')                                                     /*while loop to continue playing until user quits*/
     {
     
     cout<<"\n\n    So, "<<Play.Playername<<", do you want to make the first move or \n    Should I make the first move?\n    Enter (C) if you want me to begin , else press (I): ";
     cin>>begin;
     if (begin=='I'||begin=='i')
     trn=1;
     else if (begin=='c'||begin=='C')
     trn=-1;
     Play.Reset_board();
     do                                                                            /*do wbile loop to continue until there is a winner*/
          {
            Play.Draw();
            
                                                                          /*call function of class Player to draw the XOBoard*/
            if (trn==1)                                                            /*check if turn is human's*/
            {
               cout<<"\n\n\t\t\t"<<Play.Playername<<" , make your move now!!!";
               winner=h.input_Human_Player_move();                                        /*call function to input human move and check if human has won with the move*/
               i++; 
               ctr++;
               trn=trn*-1;
               if (winner==1)
               {
                             
                             
                             cout<<endl<<"\n\n\t\t\tI need to play again with you, "<<Play.Playername<<" !!!\n\t\t\tPlease challenge me again....(Y/N)? ";
                              cin>>ch;  
               i=11;}
            }
            if (i<10 && trn==-1)                                                   /*check if turn is computers as long as moves are less than 10*/
            {
                winner=c.comp_move();                                              /*call function to input computer move and check if computer has won with the move*/
                if (winner==1)
                {
                             
                             
                             cout<<endl<<"\n\n\n\n\n\n\n\t\t\tIf "<<Play.Playername<<", you feel you have been cheated, \n\t\t\tdare to challenge me again....(Y/N)? ";
                              cin>>ch;  
                              }
                else
                i++;
                trn=trn*-1;       
                }
            if (i==9 && winner!=1)
            {
               cout<<"\n\n\n\t       Well, I think we are both are not going to be \n\t       successful...Let me check...";
               check_for_tie=Play.Chk_tie();
               for(ctrl1 = 0; ctrl1 < 2000; ctrl1++)
               {
               for(ctrl2 = 0; ctrl2 < 100000; ctrl2++)
               {
               }
               }
               if (check_for_tie!=1)
                {
                Play.Draw();
                
                cout<<"\n\n\n\t\tSad, the government will now take possession...";
                cout<<endl<<"\n\n\t\tDo you want us to play again....(Y/N)? ";
                cin>>ch;
                break;}                                                             
               }      
            if (i==10 && winner!=1)                                                     /*check if there is a tie*/
            {
                
                Play.Draw();
                
                cout<<"\n\n\n\n\n\n\n\t       Sad, the government will now take possession...";
                cout<<endl<<"\n\n\t\tDo you want us to play again....(Y/N)? ";
                cin>>ch;
                break;                                                             
            }
        }while (winner!=1);   
        
        trn=1;   
        Play.Reset_board();
        i=1;
        
        }
        
        
        
        cout<<"\n\n\n\n\n\n\n\n\n\t\tBye bye "<< Play.Playername<<" !!! See you soon...\n\n";
        cin.get(); 
        return 0;
}                                                                                  /*main funtion ends*/
      

