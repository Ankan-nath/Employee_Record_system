//Employee_record_system.
// Header files required.
#include<stdio.h>    //For print and scan function.
#include<stdlib.h>   //For exit function.
#include<string.h>   //For string functions.
#include<windows.h>  //For windows function like system etc.(not so important.)
#include<conio.h>    //For standard I/O system.

//Prototype of the functions used in the code.
void gotoxy(int,int);
void intro();
void work();
void pass(int);
void AdminMenu();
void add();
void modify(int);
void deleterecord();
void modify_password(int);
void employeeMenu(int);
void view_1(int);
void view(int);
void search_1(int);
void view_emp(int);

//Structure of employee details.
typedef struct
{
    int Id;
    int Age;
    char Name[50];
    char Address[200];
    char DOB[10];
    char Qualification[20];
    char Designation[20];
    long int Salary;
    long int Phone;

}EMPLOYEE;

//Structure of employee password.
typedef struct
{
    char Password[50];
}PASSWORD;

//All global variables required.
COORD coord = {0,0};   //Defining the screen coordinates.
FILE *f,*fp;          //File pointers.
EMPLOYEE emp[200];    //Array of structures.
PASSWORD pas[200];   //Array of structures.
long int size=sizeof(emp);    //Size of structure.
long int size1=sizeof(pas);   //Size of structure.

//Function for screen coordinate.
void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//Function for introduction.
void intro()
{
    system("cls");
    gotoxy(30,8);
    printf("PROJECT: EMPLOYEE RECORD SYSTEM");
    gotoxy(30,10);
    printf("MADE BY: ANKAN NATH AND PRAYASH KUMAR SAHA");
    gotoxy(30,12);
    printf("COLLEGE: TECHNO MAIN SALT LAKE");
    gotoxy(30,14);
    printf("DEPARTMENT: ELECTRONICS AND COMMUNICATION ENGINEERING");
    int ans= getche();
}

//Main function.
void main()
{
    intro();
    work();
}

//Function for main menu and all working.
void work()
{
    char choice;
    f=fopen("Employee.txt","rb+");    //File for employee record.
    fp=fopen("Password.txt","rb+");   //File for password.


    do
    {
         system("cls");
         gotoxy(30,8);
         printf("MAIN MENU");
         gotoxy(30,10);
         printf("1. ADD RECORD");
         gotoxy(30,12);
         printf("2. VIEW RECORD");
         gotoxy(30,14);
         printf("3. ADMIN");
         gotoxy(30,16);
         printf("4. EMPLOYEE PERSONAL");
         gotoxy(30,18);
         printf("5. EXIT");
         gotoxy(30,20);
         printf("ENTER YOUR CHOICE: ");
         fflush(stdin);
        choice = getche();
         switch(choice)
         {
         case '1':add();break;
         case '2':view_1(1);break;
         case '3':pass(0);break;
         case '4':gotoxy(30,22);
         printf("\nENTER ID: ");
         int id;
         scanf("%d",&id);
         if(id==0){gotoxy(30,24);printf("NOT VALID");}
         else
         {pass(id);}
         break;
         case '5':fclose(f);fclose(fp);exit(0);
         default: printf("\nWRONG CHOICE\n");break;

         }

    }while(1);


}

//Function for checking password.
void pass(int n)
{char p[50];int i=0,found=0;
system("cls");
printf("ENTER YOUR PASSWORD: ");
fflush(stdin);
fgets(p,50,stdin);
fp=fopen("Password.txt","rb");
rewind(fp);
while(fread(&pas[i],size1,1,fp))
{
    if(strcmp(p,pas[i].Password)==0)
       {  found=1;
           if(i==0)
        {   fclose(fp);
            AdminMenu();}
        else
        {   fclose(fp);
            employeeMenu(i);}}
    i++;

}
if(found==0)
    printf("\nWRONG PASSWORD");

getch();

}

//Function for Admin menu.
void AdminMenu()
{
    char ch,choice;
    do{
    system("cls");
    gotoxy(30,8);
    printf("ADMIN MENU");
    gotoxy(30,10);
    printf("1. MODIFY RECORD");
    gotoxy(30,12);
    printf("2. VIEW RECORD");
    gotoxy(30,14);
    printf("3. DELETE RECORD");
    gotoxy(30,16);
    printf("4. RETURN TO MAIN MENU");
    gotoxy(30,18);
    printf("ENTER YOUR CHOICE: ");
    gotoxy(30,20);
    choice=getche();
    switch(choice)
    {
        case '1': modify(0);break;
        case '2': view_1(0);break;
        case '3': deleterecord();break;
        case '4': fclose(f);fclose(fp);return;
        default: printf("WRONG CHOICE\n");break;
    }

    }while(1);
}

//Function for Adding of record.
void add()
{   system("cls");
    char ch;int j=0,i;int k,l=0;
    f=fopen("Employee.txt","rb+");
    if(f==NULL)
    {
        f=fopen("Employee.txt","wb+");
        if(f==NULL)
        {
            printf("FILE DOESN'T EXISTS");
            exit(1);
        }
        else
        {
            i=0;
        }

    }
    else{
            while(fread(&emp[j],size,1,f)==1)
               j++;
            i=j;
    }
    fp=fopen("Password.txt","rb+");
    if(fp==NULL)
    {
        fp=fopen("Password.txt","wb+");
        if(fp==NULL)
        {
            printf("FILE DOESN'T EXISTS");
            exit(1);
        }
        else
        {

            k=0;
        }

    }
    else{
            while(fread(&pas[l],size1,1,fp)==1)
               l++;
            k=l;
    }

           fseek(f,0,SEEK_END);

           fseek(fp,0,SEEK_END);
            do{
            fflush(stdin);
            system("cls");
            printf("\nENTER YOUR NAME: ");
            fflush(stdin);
            fgets(emp[i].Name,50,stdin);
            printf("\nENTER YOUR AGE: ");
            fflush(stdin);
            scanf("%d",&emp[i].Age);
            printf("\nENTER YOUR ADDRESS: ");
            fflush(stdin);
            fgets(emp[i].Address,200,stdin);
            printf("\nENTER YOUR PHONE NUMBER: ");
            fflush(stdin);
            scanf("%ld",&emp[i].Phone);
             printf("\nENTER THE DOB(dd.mm.yyyy): ");
             fflush(stdin);
             fgets(emp[i].DOB,10,stdin);
             printf("\nENTER THE QUALIFICATION: ");
             fflush(stdin);
             fgets(emp[i].Qualification,20,stdin);
             fflush(stdin);
             printf("\nCREATE YOUR PASSWORD: ");
             fflush(stdin);
             fgets(pas[k].Password,50,stdin);
             fflush(stdin);
             emp[i].Salary=0;
             fflush(stdin);
             emp[i].Id=i;
             fflush(stdin);
             strcpy(emp[i].Designation,"DEFAULT");
             fflush(stdin);

            fwrite(&emp[i], size,1, f);
            fwrite(&pas[k], size1,1, fp);
            printf("\nThe record is sucessfully added\nWith your ID: %d\nPASSWORD: %s\n",i,pas[k].Password);

            if(i==0)
            {
                printf("YOU ARE THE ADMIN NOW");
                strcpy(emp[0].Designation,"ADMIN");
                }
                i++;k++;
            printf("\nDO YOU WANT TO CONTINUE(y/n)?: ");
            fflush(stdin);
            ch=getche();

            }while(ch=='y' || ch=='Y');
            fclose(f);
            fclose(fp);
            return;
}

//Function for deleting record.
void deleterecord()
{
    system("cls");
    int id, i=0,j=0;
    printf("Enter ID to Delete: ");
    fflush(stdin);
    scanf("%d",&id);
    FILE  *temp,*temp1;
    f = fopen("Employee.txt","rb+");
    fp=fopen("Password.txt","rb+");
    rewind(f);
    rewind(fp);
    temp = fopen("temp.txt", "wb");
    temp1 = fopen("temp1.txt", "wb");
    while(fread(&emp[i], size,1,f)==1)
    {
        if(id!=emp[i].Id)
        {

             fwrite(&emp[i],size,1,temp);
        }
       i++;
    }
    while(fread(&pas[j], size1,1,fp)==1)
    {
        if(strcmp(pas[j].Password,pas[id].Password)!=0)
        {

             fwrite(&pas[j],size1,1,temp1);          // How delete function works: finds the required file to delete
        }                                            //Creates temporary files and copy all data except the required data
       j++;                                          //to the temporary file and rename it to the previous.
    }
    fclose(fp);
    fclose(f);
    fclose(temp);
     fclose(temp1);
    remove("Employee.txt");
    remove("Password.txt");
    rename("temp.txt","Employee.txt");
    rename("temp1.txt","Password.txt");
    printf("The record is sucessfully deleted\n");
    getch();
}

//Function for modifying password.
void modify_password(int n)
{
    char p[50];int ch;
    system("cls");int i=0,found=0;
    fp=fopen("Password.txt","rb+");
    rewind(fp);
    if(n==0)
    {
        printf("ENTER PREVIOUS PASSWORD: ");
        fflush(stdin);
        fgets(p,50,stdin);
        while(fread(&pas[i],size1,1,fp)==1)
              {


        if(strcmp(pas[i].Password,p)==0)
        {
            found=1;
            printf("\nENTER THE NEW PASSWORD: ");
            fflush(stdin);
            fgets(pas[i].Password,50,stdin);
            fflush(stdin);
            fseek(fp,-size1,SEEK_CUR);
            fwrite(&pas[i].Password,size1,1,fp);
            printf("\nThe password is changed sucessfully\n");
            fclose(fp);

        }i++;

        }
        if(found==0)
            printf("\nWRONG PASSWORD");
        fclose(fp);
    }
    else
    {
      printf("ENTER PREVIOUS PASSWORD: ");
      fflush(stdin);
        fgets(p,50,stdin);
        while(fread(&pas[i],size1,1,fp)==1)
        {


        if(strcmp(pas[i].Password,p)==0)
        {
            found=1;
            printf("\nENTER THE NEW PASSWORD: ");
            fflush(stdin);
            fgets(pas[i].Password,50,stdin);
            fflush(stdin);
            fseek(fp,-size1,SEEK_CUR);
            fwrite(&pas[i].Password,size1,1,fp);
            printf("\nThe password is changed sucessfully\n");
            fclose(fp);

        }i++;
        }
        if(found==0)
            printf("\nWRONG PASSWORD");
        fclose(fp);
    }
getch();
}

//Function for Employee menu.
void employeeMenu(int n)
{
    char choice;
    system("cls");
    do
    {
    system("cls");
    gotoxy(30,8);
    printf("EMPLOYEE MENU");
    gotoxy(30,10);
    printf("1. MODIFY RECORD");
    gotoxy(30,12);
    printf("2. VIEW RECORD");
    gotoxy(30,14);
    printf("3. RETURN TO MAIN MENU");
    gotoxy(30,16);
    printf("ENTER YOUR CHOICE: ");
    fflush(stdin);
    choice=getche();
    switch(choice)
    {
        case '1':modify(n);break;
        case '2':view_emp(n);break;
        case '3':fclose(f);fclose(fp);return;
        default: printf("WRONG CHOICE\n");break;
    }

    }while(1);

}

//Function for viewing option.
void view_1(int n)
{
    system("cls");
    char ch,choice;
        gotoxy(30,14);
        printf("1. VIEW SPECIFIC");
        gotoxy(30,16);
        printf("2. VIEW ALL");
        gotoxy(30,18);
        printf("ENTER YOUR CHOICE: ");
        fflush(stdin);
        choice=getche();
        switch(choice)
        {
            case '1':if(n==0)
            {
                search_1(0);
            }
            else{

            search_1(1);
            }break;

            case '2':if(n==0)
            {
                view(0);
            }
            else{
            view(1);
            }break;
        default: printf("\nWRONG CHOICE");break;}
        return;
}

//Function for viewing all the records.
void view(int n)
{
    system("cls");
    int i=0;
    f = fopen("Employee.txt","rb+");
    rewind(f);
        while(fread(&emp[i], size,1,f)==1)
        {
            printf("ID: %d\n",emp[i].Id);
            printf("Name: %s\n",emp[i].Name);
            printf("Address: %s\n",emp[i].Address);
            printf("Age: %d\n",emp[i].Age);
            printf("DOB(dd.mm.yyyy): %s\n",emp[i].DOB);
            fflush(stdin);
            if(n==0)
            {
                printf("Designation: %s\n",emp[i].Designation);
                fflush(stdin);
                printf("Qualifications: %s\n",emp[i].Qualification);
                fflush(stdin);
                printf("Salary: %ld\n",emp[i].Salary);
                fflush(stdin);
                printf("Phone no,: %ld\n",emp[i].Phone);
                fflush(stdin);
            }
            i++;
        }
    fclose(f);
    getch();
}

//Function for viewing a specific record.
void search_1(int n)
{
    system("cls");
    printf("Search Record\n");
    int id,i=0;
    int isFound = 0;
    printf("Enter ID to Search: ");
    fflush(stdin);
    scanf("%d",&id);
    f = fopen("Employee.txt","rb+");
    rewind(f);
    while(fread(&emp[i],size,1,f)==1)
    {
        if(id==emp[i].Id)
        {
            isFound = 1;
            break;
        }
        i++;
    }
    fseek(f,-size,SEEK_CUR);
    if(isFound == 1)
    {
        printf("\nThe record is Found");
        fflush(stdin);
        printf("\nID: %d",emp[i].Id);
        fflush(stdin);
        printf("\nName: %s",emp[i].Name);
        fflush(stdin);
        printf("\nAddress: %s",emp[i].Address);
        fflush(stdin);
        printf("\nAge: %d",emp[i].Age);
        fflush(stdin);
        printf("\nDOB(dd.mm.yyyy): %s",emp[i].DOB);
        fflush(stdin);
        if(n==0 || n==2)
        {
            printf("\nDesignation: %s",emp[i].Designation);
            fflush(stdin);
            printf("\nQualification: %s",emp[i].Qualification);
            fflush(stdin);
            printf("\nSalary: %ld",emp[i].Salary);
            fflush(stdin);
            printf("\nPhone no,: %ld",emp[i].Phone);
            fflush(stdin);

        }
    }
    else
    {
        printf("\nSorry, No record found in the database");
    }
    fclose(f);
    getch();
}

//Function for viewing record of a specific employee.
void view_emp(int id)
{
 system("cls");
    int i=0;
    int isFound = 0;
    f = fopen("Employee.txt","rb+");
    rewind(f);
    while(fread(&emp[i],size,1,f)==1)
    {
        if(id==emp[i].Id)
        {
            isFound=1;
            break;
        }i++;
    }
    fseek(f,-size,SEEK_CUR);
        if(isFound==1)
        {


        printf("\nID: %d",emp[i].Id);
        fflush(stdin);
        printf("\nName: %s",emp[i].Name);
        fflush(stdin);
        printf("\nAddress: %s",emp[i].Address);
        fflush(stdin);
        printf("\nAge: %d",emp[i].Age);
        fflush(stdin);
        printf("\nDOB: %s",emp[i].DOB);
        fflush(stdin);
        printf("\nDesignation: %s",emp[i].Designation);
        fflush(stdin);
        printf("\nQualification: %s",emp[i].Qualification);
        fflush(stdin);
        printf("\nSalary: %ld",emp[i].Salary);
        fflush(stdin);
        printf("\nPhone no,: %ld",emp[i].Phone);
        fflush(stdin);
        }

    fclose(f);
    getch();
}

//Function for modification of record.
void modify(int n)
{   char choice;int id;int i=0;int found=0;
    system("cls");
    if(n==0)
    {
        do
        {
        printf("1. ALL\n");
        printf("2. PASSWORD\n");
        printf("3. RETURN TO ADMIN MENU\n");
        choice=getche();
        switch(choice)
        {
            case '1':system("cls");
            printf("ENTER THE ID: ");
            scanf("%d",&id);
            f=fopen("Employee.txt","rb+");
            rewind(f);
            while(fread(&emp[i],size,1,f)==1)
            {
                if(emp[i].Id==id)
                {   found=1;

                    emp[i].Id=id;
                    printf("\nENTER YOUR NAME: ");
            fflush(stdin);
            fgets(emp[i].Name,50,stdin);
            printf("\nENTER YOUR AGE: ");
            fflush(stdin);
            scanf("%d",&emp[i].Age);
            printf("\nENTER YOUR ADDRESS: ");
            fflush(stdin);
            fgets(emp[i].Address,200,stdin);
            printf("\nENTER YOUR PHONE NUMBER: ");
            fflush(stdin);
            scanf("%ld",&emp[i].Phone);
             printf("\nENTER THE DOB(dd.mm.yyyy): ");
             fflush(stdin);
             fgets(emp[i].DOB,10,stdin);
             printf("\nENTER THE QUALIFICATION: ");
             fflush(stdin);
             fgets(emp[i].Qualification,20,stdin);
             fflush(stdin);
             printf("\nENTER THE DESIGNATION: ");
             fflush(stdin);
             fgets(emp[i].Designation,20,stdin);
             printf("\nENTER THE SALARY: ");
             fflush(stdin);
             scanf("%ld",&emp[i].Salary);
             fflush(stdin);
             fseek(f,-size,SEEK_CUR);
             fwrite(&emp[i],size,1,f);
             printf("YOUR DATA IS SUCCESSFULLY MODIFIED\n");


                }i++;

            }fclose(f);
            if(found==0)
            {
                printf("\nSORRY RECORD NOT FOUND");
            }
            break;

            case '2': modify_password(0);break;
            case '3':return;
            default: printf("\nWRONG CHOICE ");break;
        }
    }while(1);}
    else
    {
         do{
         printf("1. ALL\n");
        printf("2. PASSWORD\n");
        printf("3. RETURN TO EMPLOYEE MENU\n");
        choice=getche();
        switch(choice)
        {
            case '1':system("cls");
            f=fopen("Employee.txt","rb+");
            rewind(f);
            while(fread(&emp[i],size,1,f)==1)
            {
                if(emp[i].Id==n)
                {
                    fseek(f,-size,SEEK_CUR);
                    emp[i].Id=n;
                    printf("\nENTER YOUR NAME: ");
            fflush(stdin);
            fgets(emp[i].Name,50,stdin);
            printf("\nENTER YOUR AGE: ");
            fflush(stdin);
            scanf("%d",&emp[i].Age);
            printf("\nENTER YOUR ADDRESS: ");
            fflush(stdin);
            fgets(emp[i].Address,200,stdin);
            printf("\nENTER YOUR PHONE NUMBER: ");
            fflush(stdin);
            scanf("%ld",&emp[i].Phone);
             printf("\nENTER THE DOB(dd.mm.yyyy): ");
             fflush(stdin);
             fgets(emp[i].DOB,10,stdin);
             printf("\nENTER THE QUALIFICATION: ");
             fflush(stdin);
             fgets(emp[i].Qualification,20,stdin);
             fflush(stdin);
             strcpy(emp[i].Designation,emp[n].Designation);
             emp[i].Salary=emp[n].Salary;
             fwrite(&emp[i],size,1,f);printf("YOUR DATA IS SUCCESSFULLY MODIFIED\n");

                 }i++;

            }fclose(f);
            if(found==0)
            break;
            case '2':modify_password(n);break;
            case '3':return;
            default: printf("\nWRONG CHOICE");break;

        }
    }while(1);}
    return;
}
