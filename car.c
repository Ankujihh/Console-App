#include<stdio.h>
#include"conio2.h"
#include"car.h"
#include<string.h>

void addAdmin()
{
    FILE *fp=fopen("admin.bin","rb");
    if(fp==NULL)
    {
        fp=fopen("admin.bin","wb");
        User u[2]={{"admin 1","test","ravi"},{"admin 2","demo","Anil"}};
        fwrite(u,sizeof(u),1,fp);
        getch();
    }
    fclose(fp);
}
User *getInput()
{
    int i;
    char userid[20];
    clrscr();
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM");
    gotoxy(1,3);
    for(i=1;i<=80;i++)
        printf("%c",247);
        gotoxy(32,5);
        printf("*LOGIN PANEL*");
        gotoxy(1,7);
        textcolor(LIGHTCYAN);
        for(i=1;i<=80;i++)
            printf("%c",247);
        gotoxy(1,15);
         for(i=1;i<=80;i++)
         printf("%c",247);
         gotoxy(60,8);
        textcolor(WHITE);
        printf("Press 0 to exit");
        textcolor(LIGHTCYAN);
        gotoxy(25,10);
        printf("Enter Userid=");
        textcolor(WHITE);
        static User u;
        fflush(stdin);
        fgets(u.userid,20,stdin);
        char *pos;
        pos=strchr(u.userid,'\n');
        if(pos!=NULL)
        {
            *pos='\0';
        }
        if(strcmp(u.userid,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(30,17);
            printf("LOGIN CANCELLED");
            getch();
            textcolor(YELLOW);
            return NULL;

        }
        textcolor(LIGHTCYAN);
        gotoxy(25,11);
        printf("Enter password=");
        fflush(stdin);
        i=0;
        textcolor(WHITE);
        for(;;)
        {
            u.pwd[i]=getch();
            if(u.pwd[i]==13)
            {
                break;
            }
            printf("*");
            i++;
        }
        u.pwd[i]='\0';
        if(strcmp(u.pwd,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(30,17);
            printf("Login Cancelled");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        getch();
         return &u;
    }
    int checkUserExist(User u,char *usertype)
    {
        if(strlen(u.userid)==0||strlen(u.pwd)==0)
        {
            gotoxy(28,20);
            textcolor(LIGHTRED);
            printf("Both fields are mandatory.try again");
            getch();
            gotoxy(28,20);
            printf("\t\t\t\t\t\t");
            return 0;
        }
        FILE *fp;
        if(strcmp(usertype,"admin")==0)
        {
            fp=fopen("admin.bin","rb");
        }
        else
            {
             fp=fopen("emp.bin","rb");
            }
        if(fp==NULL)
        {
            gotoxy(28,20);
            textcolor(LIGHTRED);
            printf("Sorry!cannot open the file");
            getch();
            gotoxy(28,20);
            printf("\t\t\t\t\t");
            return -1;
        }
          int found=0;
          User user;
          while(fread(&user,sizeof(user),1,fp)==1)
          {
              if(strcmp(u.userid,user.userid)==0&&strcmp(u.pwd,user.pwd)==0)
              {
                  found=1;
                  break;
              }
          }
          if(found==0)
          {
              gotoxy(28,20);
              textcolor(LIGHTRED);
            printf("invaild userid/password!Try again");
            getch();
            gotoxy(29,20);
            printf("\t\t\t\t\t");
          }
          else
          {
               gotoxy(28,20);
              textcolor(GREEN);
            printf("LOGIN SUCESSFUL");
            getch();
            gotoxy(28,20);
            printf("\t\t\t\t\t\t");
          }
          fclose(fp);
          return found;

        }
        int adminMenu()
        {
            int i,choice;
            textcolor(LIGHTRED);
            gotoxy(32,2);
            printf("CAR RENTAL SYSTEM");
            textcolor(LIGHTGREEN);
            gotoxy(35,6);
            printf("ADMIN MENU\n");
            for(i=0;i<=80;i++)
                 printf("*");
              textcolor(YELLOW);
              gotoxy(32,8);
              printf(" 1.Add Employee");
              gotoxy(32,9);
              printf("2.Add Car Details");
              gotoxy(32,10);
              printf("3.Show Employee");
              gotoxy(32,11);
              printf("4.Show Car Details");
              gotoxy(32,12);
              printf("5.Delete Employee");
              gotoxy(32,13);
              //printf("6.Delete Car Details");
              //gotoxy(32,14);
              printf("7.Exit");
              gotoxy(32,16);
              printf("Enter Choice:");
              scanf("%d",&choice);
              return choice;

}
  void addEmployee()
  {
      char empid[10]="EMP-";
      char temp[10];
      char choice;
      User u;
      FILE *fp=fopen("emp.bin","ab+");
      fseek(fp,0,SEEK_END);
      long total_rec=ftell(fp)/sizeof(User);
      total_rec++;
      sprintf(temp,"%d",total_rec);
      strcat(empid,temp);
      strcpy(u.userid,empid);
      do
      {
          clrscr();
          gotoxy(32,2);
          textcolor(LIGHTRED);
          printf("CAR RENTAL APP");
          textcolor("LIGHTGREEN");
          int i;
          gotoxy(1,3);
          for(i=1;i<=80;i++)
            printf("~");
          textcolor(WHITE);
          gotoxy(25,5);
          printf("*****ADD EMPLOYEE DETAILS *****");
          gotoxy(1,8);
          textcolor(YELLOW);
          printf("Enter Employee Name:");
          fflush(stdin);
          textcolor(WHITE);
          fgets(u.name,20,stdin);
          char *pos;
          pos=strchr(u.name,'\n');
          if(pos!=NULL)
          {
              *pos='\0';
          }
          textcolor(YELLOW);
          printf("Enter Employee pwd:");
          fflush(stdin);
          textcolor(WHITE);
          fgets(u.pwd,20,stdin);
          pos=strchr(u.pwd,'\n');
          if(pos!=NULL)
          {
              *pos='\0';
          }
          fwrite(&u,sizeof(u),1,fp);
          gotoxy(30,15);
          textcolor(LIGHTGREEN);
          printf("EMPLOYEE ADDED SUCCESSFULLY");
          printf("\nEMPLOYEE  ID is %s",u.userid);
          getch();
          gotoxy(1,20);
          textcolor(LIGHTRED);
          printf("DO You want to add more employee(Y/N):");
          textcolor(WHITE);
          fflush(stdin);
          scanf("%c",&choice);
          if(choice=='N');
          break;
          total_rec++;
          sprintf(u.userid,"EMP-%d",total_rec);
      }while(1);
      fclose(fp);
  }

void addCarDetails()
{
   char carid[10]=("CAR-");
   char temp[10];
   char choice;
   Car u;
   FILE *fp=fopen("car.bin","ab+");
   fseek(fp,0,SEEK_END);
   long total_rec=ftell(fp)/sizeof(Car);
   total_rec++;
   sprintf(temp,"%d",total_rec);
   strcat(carid,temp);
   strcpy(u.car_id,carid);

   do
   {
       clrscr();
       gotoxy(32,2);
       textcolor(LIGHTRED);
       printf("CAR RENTAL APP");
       textcolor(LIGHTGREEN);
       int i;
       gotoxy(1,3);
       for(i=0;i<80;i++)
       {
           printf("~");
       }
        gotoxy(30,5);
        textcolor(WHITE);
       printf("****ADD CAR DETAILS****\n");
       gotoxy(1,9);
       textcolor(YELLOW);
       printf("Enter Car Model:");
       fflush(stdin);
       textcolor(WHITE);
       fgets(u.car_name,50,stdin);
       char *pos;
       pos=strchr(u.car_name,'\n');
       if(pos!=NULL)
       {
           *pos='\0';
       }
       gotoxy(1,10);
       textcolor(YELLOW);
       printf("Enter Car Capacity:");
       textcolor(WHITE);
       scanf("%d",&i);
       gotoxy(1,11);
       textcolor(YELLOW);
       printf("Enter Car Count:");
       textcolor(WHITE);
       scanf("%d",&i);
       int arr[50];
       gotoxy(1,12);
       textcolor(YELLOW);
       printf("Enter Car price per day:");
       textcolor(WHITE);
       scanf("%d",arr[i]);
       pos=strchr(u.car_name,'\n');
       if(pos!=NULL)
       {
           *pos='\0';

       }
       textcolor(YELLOW);
       fseek(fp,0,SEEK_END);
       fwrite(&u,sizeof(u),2,fp);
       gotoxy(30,18);
       textcolor(LIGHTGREEN);
       printf("Car Added Suceesfully\n");
       printf("CAR ID IS:%s",u.car_id);
       getch();
       char choice;
       gotoxy(1,23);
       textcolor(LIGHTRED);
       printf("Do You Want To Add More(y/n):");
       textcolor(WHITE);
       fflush(stdin);
       scanf("%c",&choice);
       if(choice=='n');
       break;
       total_rec++;
       strcpy(carid,"CAR-");
      sprintf(u.car_id,"CAR-%d",total_rec);
      strcat(carid,temp);
      strcpy(u.car_id,carid);
       getch();
          }while(1);
          fclose(fp);

}

void viewEmployee()
{
    FILE *fp=fopen("emp.bin","rb");
    User ur;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1;i<=80;i++)
     printf("%c",247);
   gotoxy(31,5);
   printf("EMPLOYEE DETAILS");
   gotoxy(1,7);
   textcolor(LIGHTGREEN);
     for(i=1;i<=80;i++)
        printf("%c",247);
     if(fp==NULL)
     {
         gotoxy(31,9);
         textcolor(LIGHTRED);
         printf("Sorry !No employee added yet!");
         getch();
         return ;
     }
     gotoxy(1,8);
     printf("Employee ID\t\t\tName\t\tPassword");
     gotoxy(1,9);
     for(i=1;i<80;i++)
        printf("%c",247);
     int row=10;
     textcolor(YELLOW);
     while(fread(&ur,sizeof(ur),1,fp)==1)
     {
         gotoxy(2,row);
         printf("%s",ur.userid);
         gotoxy(33,row);
         printf("%s",ur.name);
         gotoxy(57,row);
         printf("%s",ur.pwd);
         row++;
     }
     fclose(fp);
     _getch();
    }

 void showCarDetails()
 {
     FILE *fp=fopen("car.bin","rb");
     Car ur;
     int i;
     textcolor(YELLOW);
     gotoxy(32,1);
     printf("CAR RENTAL SYSTEM\n");
     for(i=1;i<=80;i++)
        printf("%c",247);
        gotoxy(32,5);
        printf("*ALL CAR DETAILS*");
        gotoxy(1,7);
     textcolor(LIGHTGREEN);
     for(i=1;i<80;i++)
         printf("%c",247);
     if(fp==NULL)
     {
         gotoxy(31,9);
         textcolor(LIGHTGREEN);
         printf("SORRY!NO CAR DETAILS ADDED YET!");
         getch();
         return;

     }
 }

 int deleteEmp()
{
    FILE *fp1=fopen("emp.bin","rb");
    char empid[10];
    int i,result;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTEM\n");
    for(i=1; i<=80; i++)
        printf("%c",247);
    gotoxy(29,5);
    textcolor(YELLOW);
    printf("* DELETE EMPLOYEE RECORD *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1; i<80; i++)
        printf("%c",247);
    gotoxy(1,12);
    for(i=1; i<80; i++)
        printf("%c",247);
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo Employee Added Yet!");
        return -1;
    }
    FILE *fp2=fopen("temp.bin","wb+");
    gotoxy(10,9);
    textcolor(YELLOW);
    printf("Enter Employee Id to delete the record:");
    textcolor(WHITE);
    scanf("%s",empid);
    User U;
    int found=0;
    while(fread(&U,sizeof(U),1,fp1)==1)
    {
     if(strcmp(U.userid,empid)!=0)
       fwrite(&U,sizeof(U),1,fp2);
     else
       found=1;
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
      remove("temp.bin");
    else
    {
     result=remove("emp.bin");
     if(result!=0)
       return 2;
     result=rename("temp.bin","emp.bin");
     if(result!=0)
       return 2;
    }
    return found;
}

