#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include"car.h"

int main()
{
 int i,type,k,choice,result;
 User *usr;
 gotoxy(31,15);
 textcolor(YELLOW);
 printf("\"WELCOME TO CAR RENTAL SYSTEM\"");
 gotoxy(27,18);
 textcolor(LIGHTGREEN);
 printf("\"RENT A CAR AND GO WHEREVER YOU WANT.\"");
 getch();
 textcolor(YELLOW);
 addAdmin();

 while(1)
 {
  clrscr();
  textcolor(LIGHTRED);
  gotoxy(40,2);
  printf("* Car rental System *");
  gotoxy(1,8);
  textcolor(YELLOW);
  for(i=0;i<94;i++)
  {
   printf("*");
  }
  gotoxy(1,24);
  for(i=0;i<94;i++)
  {
   printf("*");
  }
  gotoxy(40,10);
  printf("1.Admin:");
  gotoxy(40,12);
  printf("2.Employee:");
  gotoxy(40,14);
  printf("3.Quit:");
  gotoxy(40,16);
  textcolor(WHITE);
  printf("Select Your Role:");
  do
  {
   scanf("%d",&type);
   if(type==1)
   {
    do
     {
      usr=getInput();
      if(usr==NULL)
         break;
      else
      {
       k=checkUserExist(*usr,"admin");
      }
     }while(k==0);
     if(usr==NULL)
         break;
   if(k==-1)
      break;
    if(k==1)
    {
     gotoxy(35,28);
     textcolor(WHITE);
     printf("Press any key to continue.");
     getch();
     clrscr();
  do
   {
     choice=adminMenu();
     if(choice==7)
        break;
     switch(choice)
     {
      case 1:
             clrscr();
             addEmployee();
             break;
      case 2:
             clrscr();
             viewEmployee();
             break;
      case 3:
             clrscr();
             addCarDetails();
             break;
      case 4:
             clrscr();
             FILE *fp=fopen("car.bin","rb");

             showCarDetails();
             break;
      case 5:
             clrscr();
             result=deleteEmp();
             gotoxy(40,15);
             if(result==0)
             {
                 textcolor(LIGHTRED);
                 printf("Sorry!No emp found for given emp id.");
             }
             else if(result==1)
             {
                 textcolor(LIGHTGREEN);
                 printf("Record deleted successfully!");
             }
             else if(result==2)
             {
                 textcolor(LIGHTRED);
                 printf("Sorry!Error in deletion.Try again.");
             }
             textcolor(WHITE);
             printf("\n\n\n\n\nPress any key to go back to the main screen:");
             getch();
             break;
      default:
             gotoxy(47,17);
             textcolor(LIGHTRED);
             printf("Wrong Choice.Try again.");
             getch();
             gotoxy(47,17);
             printf("\t\t\t\t");
             textcolor(WHITE);
             gotoxy(65,15);
             printf("\t\b\b\b\b\b\b\b\b");
             break;
     }
   }while(choice>=1||choice<=6);
   break;
   }
  }
  else if(type==2)
  {

  }
  else if(type==3)
  {
    clrscr();
    textcolor(LIGHTGREEN);
    gotoxy(35,15);
    printf("Thank You For Using The App.");
    gotoxy(33,18);
    textcolor(WHITE);
    printf("Press any key to leave the app.");
    getch();
    exit(0);
  }
  else
  {
    textcolor(LIGHTRED);
    gotoxy(43,26);
    printf("Invalid Choice!");
    getch();
    textcolor(WHITE);
    gotoxy(43,26);
    printf("\t\t\t");
    gotoxy(57,16);
    printf("\t");
    gotoxy(57,16);
  }
 }while(1);
getch();
}
return 0;
}





