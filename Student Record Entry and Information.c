/******************************************

  Application : Student Record Entry and Information
  Submitted by: Aiman Lameesa(RK-092-041), Ahsan Imran(AE-092-018), Sheikh Mehedi Hasan(AE-092-008)

******************************************/

#include <stdio.h>
#include <string.h>
#include<windows.h>
#include<time.h>

void informationEntry(void);
void selectAdminOption(void);
void getInfo(int option);
void gotoxy(int x, int y);
int showAdminMenu;

/*gotoxy function needed to define in code blocks*/

void gotoxy(int x, int y)
   {
       COORD c;
       c.X=x;
       c.Y=y;
       SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
   }
/*main function start from here*/
void main()
{
    int cancelOption,timeOption,entryOption,exitOption;
    char choice[1];
    char selectOption[1];

    cancelOption=0;

    /* Shows the main menu for the application*/
        while (cancelOption==0)
    {
        gotoxy(30,7);
        printf("Please Select an Action-->");
        gotoxy(30,10);
        printf("Daily Time Record [1] ");
        gotoxy(30,11);
        printf("Data Entry        [2] ");
        gotoxy(30,12);
        printf("Close             [3] ");
        gotoxy(30,15);
        printf("Please Enter Your Choice (1/2/3): ");
        scanf("%s",&choice);
        timeOption=strcmp(choice,"1");
        entryOption=strcmp(choice,"2");
        exitOption=strcmp(choice,"3");


        if (timeOption==0)
        {
        printf("\n\n\nDAILY STUDENT TIME RECORDING SYSTEM\n");
        printf("Input Any Other key to Return to Previous Screen.\n");
        printf("[1] Student Log In \n");
        printf("[2] Student Log Out\n");
        printf("Please Enter Your Option: ");
        scanf("%s",&selectOption);
        if (strcmp(selectOption,"1")==0)
        {
           getInfo(5);
        }
        if (strcmp(selectOption,"2")==0)
        {
           getInfo(6);
        }
        cancelOption=0;
        }
        if (entryOption==0)
        {
        informationEntry();
        cancelOption=0;
        }
        if (exitOption==0)
        {
        cancelOption=1;
        }

        if (!(timeOption==0 || entryOption==0 || exitOption==0))
        {
           printf("\n\n\nYou Have Entered an Invalid Option. Please Choose Either 1, 2 or 3. \n");
           getch();
           cancelOption=0;
        }

    }
    printf("\nThe Application will Close Now. Thanks!\n");
    getch();
}

/* This function provides logic for data entry to be done for the system.
Access to Data Entry screens will be only allowed to administrator user.*/
void informationEntry(void)
{

char adminName[10], passwd[5],buffer[1];
char tempo[6],sel[1];
int validUserNameOption,validUserPwdOption,returnOption,UserName,inc,tmp;
char plus;

    validUserNameOption=0;
    validUserPwdOption=0;
    while (validUserPwdOption==0)
    {

        while (validUserNameOption==0)
        {

            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAdmin Name: admin; Password: admin11\n\n");
            printf("STUDENT DATA ENTRY SYSTEM, ADMIN TEACHER INTERFACE\n");
            printf("Info: Type return to go back to the main screen.\n");
            printf("Enter Administrator Teacher Name: \n");
            scanf("%s",&adminName);
            returnOption=strcmp(adminName,"return");
            UserName=strcmp(adminName,"admin");

            if (returnOption==0)
            {
            goto stream;
            }
            if (!(UserName==0 || returnOption==0))
            {

            printf("Administrator Teacher Name is Invalid.\n");
            getch();
            validUserNameOption=0;
            }
            else
            validUserNameOption=1;

        }

    printf("Enter Password: \n");
    inc=0;
    while (inc<5)
    {
     passwd[inc]=getch();
     inc=inc+1;
     printf("* ");
    }
    inc=0;
    while (inc<5)
    {
     tempo[inc]=passwd[inc];
     inc=inc+1;
    }
    while(getch()!=13);
    if (!strcmp(tempo, "admin11"))
        {

            printf("\nYou have Entered a Wrong Password. Please Try Again.\n");
            getch();
            validUserPwdOption=0;
            validUserNameOption=0;
        }
        else
        {

            printf("You Have Successfully Logged In.\n");

            printf("Press Any Key to Continue.\n");
            validUserPwdOption=1;
            validUserNameOption=1;
            getch();
            showAdminMenu=0;

             while (showAdminMenu==0)
             {


            printf("\nADMIN OPTIONS\n");
            printf("Add New Students      [1]\n");
            printf("Show Daily Entries    [2]\n");
            printf("Search Student Record [3]\n");
            printf("Remove Student        [4]\n");
            printf("Close                 [5]\n");
            printf("Please enter your choice: \n");
            selectAdminOption();
           }
        }
    }
stream:{}

}

/* This function provides the administrator level functionalities, such as Adding or deleting an employee.*/
void selectAdminOption(void)
{
  char chc[1];
  int chooseNew,chooseShow,chooseSearch,chooseRemove,chooseClose;

  gets(chc);

  chooseNew=strcmp(chc,"1");
  chooseShow=strcmp(chc,"2");
  chooseSearch=strcmp(chc,"3");
  chooseRemove=strcmp(chc,"4");
  chooseClose=strcmp(chc,"5");

  if (!(chooseNew==0 || chooseShow==0 || chooseSearch==0 || chooseRemove==0 || chooseClose==0))
  {

     printf("Invalid Input!\n");

     printf("Press any key to continue.\n");
  }

  if (chooseNew==0)
  {


     getInfo(1);
  }
  else if(chooseShow==0)
  {
     getInfo(2);
  }
  else if(chooseSearch==0)
  {

     getInfo(3);
  }
  else if(chooseRemove==0)
  {
     getInfo(4);
  }
  else if (chooseClose==0)
  {
     showAdminMenu=1;
  }
}

/* This function retreives data from the database as well as do data processing according to user requests.
   The function provides functionality for menu options provided to both students as well as administrator user*/
void getInfo(int option)
{
 FILE *db,*tempdb;
 char anotherStd;
 int choice;
 int showMenu;
 char checkSave,checkAddNew;
 int i;

 struct student
 {
    char firstname[30];
    char lastname[30];
    char password[30];
    int  empid;
    char loginhour;
    char loginmin;
    char loginsec;
    char logouthour;
    char logoutmin;
    char logoutsec;
    float CGPA;
    int  meritPosition;
    int day;
    int mon;
    int yr;

 };

 /*Some informations*/
 struct student stdData;
 strcpy(stdData.firstname,"Aiman" );
 strcpy(stdData.lastname,"Lameesa");
 strcpy(stdData.password,"aiman1");
 stdData.empid=41;
 stdData.CGPA=3.92;
 stdData.meritPosition=2;
 strcpy(stdData.firstname,"Imran" );
 strcpy(stdData.lastname,"Mirza");
 strcpy(stdData.password,"imran1");
 stdData.empid=18;
 stdData.CGPA=3.91;
 strcpy(stdData.firstname,"Mehedi" );
 strcpy(stdData.lastname,"Hasan");
 strcpy(stdData.password,"hasan1");
 stdData.empid=8;
 stdData.CGPA=3.80;

 char confirmPassword[30];
 long int size;
 char lastNameTemp[30],firstNameTemp[30],password[30];
 int  searchId;
 char pass[30];
 char findStudent;
 char confirmDelete;

 /* Opens the Employee Database*/
 db=fopen("student_file.dat","rb+");
 if(db==NULL)
    {
        db=fopen("student_file.dat","wb+");
        if(db==NULL)
        {
            printf("The File could not be opened.\n");
            exit(1);
        }
    }
  printf("Application Database \n");
  size=sizeof(stdData);
  showMenu=0;
  while(showMenu==0)
  {
   fflush(stdin);
   choice=option;

   /* Based on the choice selected by admin/student, this switch statement processes the request*/
   switch(choice)
   {

   /* To add a new student to the database*/
   case 1:
       fseek(db,0,SEEK_END);
       anotherStd='y';

       while(anotherStd=='y')
       {
                   checkAddNew=0;
           while(checkAddNew==0)
           {
           printf("\n\nADD A NEW STUDENT.\n");
           printf("Warning: Password Must Contain Six(6) AlphaNumeric Digits.\n");
           printf("Enter First Name: \n");
           scanf("%s",&firstNameTemp);
           printf("Enter Last Name: \n");
           scanf("%s",&lastNameTemp);
           printf("Enter Password: \n");
           for (i=0;i<6;i++)
           {
            password[i]=getch();
            printf("* ");
           }
           password[6]='\0';

           while(getch()!=13);

           printf("Confirm Password: \n");
           for (i=0;i<6;i++)
           {
            confirmPassword[i]=getch();
            printf("* ");
           }
           confirmPassword[6]='\0';

           while(getch()!=13);
           if (strcmp(password,confirmPassword))
           {
              printf("Passwords do not match.\n");
              printf("Press any key to continue.\n");
              getch();
           }
           else
           {
           checkAddNew=1;
           rewind(db);
           stdData.empid=0;
           while(fread(&stdData,size,1,db)==1);
           if (stdData.empid<2000)
           stdData.empid=20400;

           stdData.empid=stdData.empid+1;
           printf("\nSave Employee Information? (y/n): \n");
           checkSave=getche();
           if (checkSave=='y')
           {
           strcpy(stdData.firstname,firstNameTemp);
           strcpy(stdData.lastname,lastNameTemp);
           strcpy(stdData.password,password);
           stdData.loginhour='t';
           stdData.logouthour='t';
           stdData.day='j';
           fwrite(&stdData,size,1,db);
           }
           printf("                        ");
           printf("\nWould like to add another employee? (y/n):\n");
           fflush(stdin);
           anotherStd=getche();
           printf("\n");
           }
           }
       }
       break;

   /* To view time records for all students*/
   case 2:


       printf("VIEW STUDENT INFORMATION\n");
       printf("Name | Roll | CGPA | Merit\n\n");
       rewind(db);
       while(fread(&stdData,size,1,db)==1)
       {
        stdData.firstname[0]=toupper(stdData.firstname[0]);
        stdData.lastname[0]=toupper(stdData.lastname[0]);
        printf("%s %s | %d| %.2f | %d",
        &stdData.firstname,
        &stdData.lastname,
        stdData.empid,
        stdData.CGPA,
        stdData.meritPosition);
       }
           getch();

       printf("\n");
       break;

  /* To search a particular student and view their time records*/
  case 3:



       printf("\nSEARCH STUDENT INFORMATION\n");
       printf("\nEnter STUDENT Roll No to Search: \n");
       scanf("%d", &searchId);
       findStudent='f';
       rewind(db);
           while(fread(&stdData,size,1,db)==1)
       {
           if (stdData.empid==searchId)
           {

        printf("Student Information is Available.\n");
        printf("Student name is: %s %s\n", stdData.lastname,stdData.firstname);
        if(stdData.loginhour=='t')
        {
        printf("Log In Time: Not Logged In");
        }
        else
        {
        printf("Log In Time is: %d:%d:%d",stdData.loginhour,stdData.loginmin,stdData.loginsec);
        }
        if(stdData.logouthour=='t')
        {
        printf("Log Out Time: Not Logged Out\n");
        }
        else
        {
        printf("Log Out Time is: %d:%d:%d\n",stdData.logouthour,stdData.logoutmin,stdData.logoutsec);
        }
        findStudent='t';
           getch();
           }
       }
       if (findStudent!='t')
       {
       printf("Student Information not available. Please modify the search.\n");
       getch();
       }
       break;

  /* To remove entry of an student from the database*/
  case 4:

       printf("\nREMOVE AN SUDENT\n");
       printf("Enter Roll No to Delete: \n");
       scanf("%d", &searchId);
       findStudent='f';
       rewind(db);
           while(fread(&stdData,size,1,db)==1)
       {

           if (stdData.empid==searchId)
           {
        printf("Student Information is Available.\n");
        printf("Student name is: %s %s",stdData.lastname,stdData.firstname);
        findStudent='t';

           }
       }
       if (findStudent!='t')
       {
       printf("Student Information not available. Please modify the search.\n");
       getch();
       }
       if (findStudent=='t')
       {
       printf("Do you want to Delete the Student? (y/n)\n");
       confirmDelete=getche();
        if (confirmDelete=='y' || confirmDelete=='Y')
        {
        tempdb=fopen("student_file.dat","wb+");
        rewind(db);
        while(fread(&stdData,size,1,db)==1)
            {
             if (stdData.empid!=searchId)
             {
             fseek(tempdb,0,SEEK_END);
             fwrite(&stdData,size,1,tempdb);
             }
            }
        fclose(tempdb);
        fclose(db);
        remove("student_file.dat");
        rename("student_info.dat","student_file.dat");
        db=fopen("student_info.dat","rb+");
        }
       }
       break;

  /* To login an employee into the system and record the login date and time*/
  case 5:


       printf("\nDAILY STUDENT TIME RECORDING SYSTEM\n");
       printf("Warning: Please Enter Numeric Values Only.\n");
       printf("Enter Your Roll No to Login: ");
       scanf("%d", &searchId);

       printf("           ");
       findStudent='f';
       rewind(db);
           while(fread(&stdData,size,1,db)==1)
       {
           if (stdData.empid==searchId)
           {
        printf("\nEnter Your Password: ");

                 for (i=0;i<6;i++)
           {
            pass[i]=getch();
            printf("* ");
           }
           pass[6]='\0';
         while(getch()!=13);

        if (strcmp(stdData.password,pass))
        {
         printf("\nYou Have Supplied a Wrong Password.\n");
         findStudent='t';
         getch();
         break;
        }

        printf("You have successfully Logged In the System.\n");
        printf("Student name: %s %s\n",stdData.lastname,stdData.firstname);
        SYSTEMTIME today;
        GetSystemTime(&today);
        time_t now;
        struct tm *local;
        now=time(NULL);
        local=localtime(&now);
        printf("Your LogIn Time: %d:%d:%d\n",local->tm_hour, local->tm_min, local->tm_sec);
        printf("Your Log In Date: %d/%d/%d\n",today.wDay,today.wMonth,today.wYear);
        stdData.day=today.wDay;
        stdData.mon=today.wMonth;
        stdData.yr=today.wYear;
        fseek(db,-size,SEEK_CUR);
        fwrite(&stdData,size,1,db);
        findStudent='t';
        getch();

           }
       }
       if (findStudent!='t')
       {
       printf("\nStudent Information is not available.\n");
       getch();
       }

       break;

  /* To logout an student and record the logout date and time*/
  case 6:

       printf("\nDAILY STUDENT TIME RECORDING SYSTEM\n");

       printf("Warning: Please Enter Numeric Values Only.\n");
       printf("Enter Your Roll No to Logout: ");
       scanf("%d", &searchId);
       printf("                                            ");
       findStudent='f';
       rewind(db);
           while(fread(&stdData,size,1,db)==1)
       {
           if (stdData.empid==searchId)
           {
        printf("\nEnter Password: ");

                 for (i=0;i<6;i++)
           {
            pass[i]=getch();
            printf("* ");
           }
           pass[6]='\0';
         while(getch()!=13);

        if (strcmp(stdData.password,pass))
        {
         printf("\nYou Have Supplied a Wrong Password.\n");
         findStudent='t';
         getch();
         break;
        }
        printf("\nYou have successfully Logged Out of the System.\n");
        printf("Student name is: %s %s\n",stdData.lastname,stdData.firstname);
        SYSTEMTIME today;
        GetSystemTime(&today);
        time_t now;
        struct tm *local;
        now=time(NULL);
        local=localtime(&now);
        printf("Your Log Out Time: %d:%d:%d\n",local->tm_hour, local->tm_min, local->tm_sec);
        printf("Your Log Out Date: %d/%d/%d\n",today.wDay,today.wMonth,today.wYear);
        fseek(db,-size,SEEK_CUR);
        fwrite(&stdData,size,1,db);
        findStudent='t';
        getch();

           }
       }
       if (findStudent!='t')
       {

       printf("\nStudent Information is not available.\n");
       getch();
       }

       break;

  /* Show previous menu*/
  case 7:

       printf("\n");
       exit(1);
       }
   fclose(db);
   showMenu=1;
   }

 }

