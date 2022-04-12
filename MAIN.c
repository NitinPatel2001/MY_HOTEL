//project for DTU CANTEEN
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
void owner();
void employee();
void sales_record();
void add_item();
void delete_menu();
void view_employee_detail(int );
void add_employee();
void delete_employee();
void menu(int c);
void order();
void spacing();
void welcome();
void login();
void delete_sales_record();



struct employee
{
    char name[30];
    long id;
    long salary;
}emp;



struct menu
{
    char name[30];
    int price;
}menu_var;




struct student
{
    char name[20];
    char rollnumber[30];
}stud;


void spacing()
{
    int i;
    for(i=0;i<45;i++)
        printf(" ");
}



int main()
{
     welcome();

    return 0;
}



void welcome()
{
    system("cls");
    spacing();
    printf("\tWELCOME TO THE DTU CANTEEN\n\n");
    spacing();
    printf("\t\tcreated by:\n\n");
    spacing();
    printf("\t\tNITIN PATEL\n");
    spacing();
    printf("\t\t2K20/CO/308\n");
    spacing();
    printf("\n");
    login();
}



void login()
{

    char password[6]={'\0'},ch;
    int n,k,i;
    printf("\t\tLOGIN:\n\n");
    spacing();
    printf("\t\t1.owner\n");
    spacing();
    printf("\t\t2.employee\n");
    spacing();
    printf("\t\t3.Exit\n");
    spacing();
    printf("ENTER CHOICE: ");
    scanf("%d",&n);
    system("cls");
    if(n==1)
    {
        again:
        system("cls");
        spacing();
        printf("ENTER PASSWORD <any  5 character>:\n");
        spacing();
        for(i=0;i<5;i++)
        {

            ch=getch();
            password[i]=ch;
            ch='*';
            printf("%c",ch);
        }
        password[5]='\0';
        if(strcmp(password,"12345")==0)
            owner();
        else
        {
            printf("\n");
            spacing();
            printf("WRONG PASSWORD\n");
            spacing();
            printf("1.TRY AGAIN\n");
            spacing();
            printf("2.EXIT\n");
            spacing();
            printf("ENTER CHOICE: ");
            scanf("%d",&k);

            if(k==1)
            {
                goto again;
            }
            else
            {
                exit(0);
            }

        }


    }

    else if(n==2)
    {
        again1:
        system("cls");
        spacing();
        printf("ENTER PASSWORD <any  5 character>:\n");
        spacing();
        for(i=0;i<5;i++)
        {
            ch=getch();
            password[i]=ch;
            ch='*';
            printf("%c",ch);
        }
        password[5]='\0';
        if(strcmp(password,"12345")==0)
            employee();
        else
        {
            printf("\n");
            spacing();
            printf("WRONG PASSWORD\n");
            spacing();
            printf("1.TRY AGAIN\n");
            spacing();
            printf("2.EXIT\n");
            spacing();
            printf("ENTER CHOICE: ");
            scanf("%d",&k);

            if(k==1)
            {
                goto again1;
            }
            else
            {
                exit(0);
            }

        }


    }
    else
        {
            system("cls");
            printf("\n\n\n");
            spacing();
            printf("THANK YOU FOR USING DTU CANTEEN MANAGEMENT SYSTEM\n\n\n");
            spacing();
            printf("BY:\n");
            spacing();
            printf("\t\tNITIN PATEL\n");
            spacing();
            printf("\t\t2k20/CO/308\n");
            spacing();
        }

}



void owner()
{
    system("cls");
    int i,n,k;
    char  *list[9]={"1.VIEW SALES RECORD.","2.CHANGE IN MENU","3.VIEW MENU","4.VIEW EMPLOYEE DETAILS","5.DELETE SALES RECORD","6.ADD NEW EMPLOYEE","7.DELETE EMPLOYEE","8.LOG OUT","\0"};
    for(i=0;i<8;i++)
        printf("\t\t\t\t%s\n",list[i]);
    printf("\t\t\t\tENTER CHOICE: ");
    scanf("%d",&n);

    switch(n)
    {
    case 1:
        sales_record(1);
        break;
    case 2:
        system("cls");
        printf("WHAT DO WANT \n\t\t\t\t1.ADD\n\t\t\t\t2.DELETE\n");
        printf("\t\t\t\tENTER CHOICE: ");
        scanf("%d",&k);
        if(k==1)
            add_item();
        else if(k==2)
            delete_menu();
        else
            printf("\t\t\t\tWRONG CHOICE");
        break;

    case 3:
        menu(1);
        break;
    case 4:
        view_employee_detail(2);
        break;
    case 5:
        delete_sales_record();
        break;
    case 6:
        add_employee();
        break ;
    case 7:
        delete_employee();
        break  ;
    case 8:
         welcome();
         break ;
    default:
        printf("\t\t\t\tWRONG CHOICE\n");

    }
}



void employee()
{
    system("cls");
    int i,n;
    char *list2[5]={"1.VIEW SALES RECORD","2.TAKE ORDER ","3.VIEW MENU","4.LOG OUT","\0"};
    for(i=0;i<4;i++)
        printf("\t\t\t\t%s\n",list2[i]);
    printf("\t\t\t\tENTER CHOICE: ");
    scanf("%d",&n);

    switch(n)
    {
    case 1:
        sales_record(2);
        break;
    case 2:
        order();
        break;
    case 3:
        menu(2);
        break;
    case 4:
        welcome();
        break ;
    default:
        printf("\t\t\t\tWRONG CHOICE\n");

    }

}



void add_employee()
{
    system("cls");
    FILE *employee;
    employee=fopen("DETAILS","a");
     if(employee==NULL)
        printf("\t\t\t\tTHE FILE  DOES NOT OPEN OR EXIST.\n");
    printf("\t\t\t\tENTER THE DETAILS OF NEW EMPOLYEE\n");
    printf("\t\t\t\tFIRST NAME     ID      SALARY\n\t\t\t\t");
    fscanf(stdin,"%s %ld %ld",emp.name,&emp.id,&emp.salary);
    fprintf(employee," %s %ld %ld",emp.name,emp.id,emp.salary);
    printf("\t\t\t\tADDED  SUCCESSFULLY");
    fclose(employee);
    printf("\n\t\t\t\tPRESS ANY KEY TO RETURN TO OWNER PAGE: ");
    getch();
    owner();
}



void view_employee_detail(int c)
{
    system("cls");
    FILE *ptr;
    ptr=fopen("DETAILS","r");
    if(ptr==NULL)
        printf("\t\t\t\tTHE FILE  DOES NOT OPEN OR EXIST.\n");
    printf("\t\t\t\tEMPLYOEE NAME\tID\t\tSALARY");
    while(feof(ptr)==0)
    {
        fscanf(ptr,"%s %ld %ld\n",emp.name,&emp.id,&emp.salary);
        fprintf(stdout,"\n\t\t\t\t%s\t\t%ld\t\t%ld",emp.name,emp.id,emp.salary);

    }
    fclose(ptr);
    if(c==1)
    {
        printf("\n\t\t\t\tPRESS ANY KEY: ");
        getch();

    }
    else
    {
       printf("\n\t\t\t\tPRESS ANY KEY TO RETURN TO OWNER PAGE: ");
    getch();
    owner();
    }

}




void delete_employee()
{
    view_employee_detail(1);

    char name[30];
    long id;
    FILE *ptr1,*ptr2;
    ptr1=fopen("DETAILS","r");
    ptr2=fopen("TEMP","w");

    if(ptr1==NULL||ptr2==NULL)
        printf("\n\t\t\t\tTHE FILE DOES NOT OPEN OR EXIST.\n");


    printf("\n\t\t\t\tENTER THE FIRST NAME AND ID OF EMLOYEE.\n");
    printf("\t\t\t\tNAME\t\tID\n\t\t\t\t");
    scanf("%s%ld",name,&id);

    while(feof(ptr1)==0)
    {
        fscanf(ptr1," %s %ld %ld",emp.name,&emp.id,&emp.salary);
        if(strcmp(emp.name,name)==0&&emp.id==id)
            continue;
        fprintf(ptr2," %s %ld %ld",emp.name,emp.id,emp.salary);

    }

    fclose(ptr1);
    fclose(ptr2);
    remove("DETAILS");
    rename("TEMP","DETAILS");

    printf("\t\t\t\tDELETED SUCCESSFULY\n");
    view_employee_detail(2);


}




void add_item()
{
    system("cls");
    FILE *ptr;
    ptr=fopen("MENU","a");
     if(ptr==NULL)
        printf("\t\t\t\tTHE FILE  DOES NOT OPEN OR EXIST.\n");
    printf("\t\t\t\tENTER THE NAME OF ITEM AND THEIR PRICE:\n");
    printf("\t\t\t\tITEM NAME     PRICE\n\t\t\t\t");
    fscanf(stdin,"%s %d",menu_var.name,&menu_var.price);
    fprintf(ptr," %s %d",menu_var.name,menu_var.price);
    fclose(ptr);
    printf("\n\t\t\t\tPRESS ANY KEY TO RETURN TO OWNER PAGE: ");
    getch();
    owner();
}



void menu(int c)
{
    system("cls");
    FILE *ptr;
    ptr=fopen("MENU","r");
    if(ptr==NULL)
        printf("\t\t\t\tTHE FILE  DOES NOT OPEN OR EXIST.\n");
    printf("\t\t\t\tITEM\t\t\tPRICE\n");
    while(feof(ptr)==0)
    {
        fscanf(ptr,"%s %d\n",menu_var.name,&menu_var.price);
        fprintf(stdout,"\t\t\t\t%s\t\t\t%d\n",menu_var.name,menu_var.price);

    }
    fclose(ptr);
    printf("\t\t\t\tPRESS ANY KEY:");
    getch();
    if(c==1)
    {
        owner();
    }
    else if(c==2)
    {
        employee();
    }

}




void delete_menu()
{
    menu(3);

    char item[30];
    int price;
    FILE *ptr1,*ptr2;
    ptr1=fopen("MENU","r");
    ptr2=fopen("TEMP","w");

    if(ptr1==NULL||ptr2==NULL)
        printf("\n\t\t\t\tTHE FILE DOES NOT OPEN OR EXIST.\n");


    printf("\n\t\t\t\tENTER THE ITEM AND ITS PRICE.\n");
    printf("\t\t\t\tITEM\t\tPRICE\n\t\t\t\t");
    scanf("%s%d",item,&price);
    char ch='a';
    while(ch!=EOF)
    {
        fscanf(ptr1," %s %d",menu_var.name,&menu_var.price);
        ch=fgetc(ptr1);

        if(strcmp(menu_var.name,item)==0&&menu_var.price==price)
            continue;
        fprintf(ptr2," %s %d",menu_var.name,menu_var.price);

    }

    fclose(ptr1);
    fclose(ptr2);
    remove("MENU");
    rename("TEMP","MENU");

    printf("\t\t\t\tDELETED SUCCESSFULY\n");
    printf("\n\t\t\t\tPRESS ANY KEY TO RETURN TO OWNER PAGE: ");
    getch();
    owner();


}




void order()
{
    system("cls");

    int i=1,n,k,total=0;
    printf("\t\t\t\tENTER YOUR FIRST NAME AND ROLL NUMBER:\n\t\t\t\t");
    scanf("%s %s",stud.name,stud.rollnumber);
    printf("\t\t\t\tHERE IS YOURS MEAL, WHICH ONE YOU WANT TO PREFER:\n ");
    FILE  *ptr2;
    FILE *ptr;
    ptr=fopen("MENU","r");
    if(ptr==NULL)
        printf("\t\t\t\tTHE FILE  DOES NOT OPEN OR EXIST.\n");
    printf("\t\t\t\tITEM\t\tPRICE\n");
    while(feof(ptr)==0)
    {
        fscanf(ptr,"%s %d\n",menu_var.name,&menu_var.price);
        fprintf(stdout,"\t\t\t\t%d\t\t%s\t\t%d\n",i,menu_var.name,menu_var.price);
        i++;
    }


    printf("\t\t\t\tENTER NUMBER OF ITEMS YOU WANT: ");
    scanf("%d",&n);
    while(n>0)
    {
        printf("\t\t\t\tENTER THE CHIOCE:");
        scanf("%d",&k);
        fseek(ptr,0,SEEK_SET);
        for(i=0;i<k;i++)
        {
            fscanf(ptr,"%s %d",menu_var.name,&menu_var.price);
        }


        printf("\t\t\t\tHOW MANY %s DO YOU WANT : ",menu_var.name);
        scanf("%d",&k);

        total+=menu_var.price*k;
        n--;
    }

    printf("\t\t\t\t\tYOUR TOTAL BILL: %d",total);

    ptr2=fopen("SALES","a");
    fprintf(ptr2,"%s %s %d\n",stud.name,stud.rollnumber,total);

    fclose(ptr);
    fclose(ptr2);
    printf("\n\t\t\t\tPRESS ANY KEY TO RETURN TO EMPLOYEE PAGE: ");
    getch();
    employee();


}




void sales_record(int c)
{
    system("cls");
    long total=0;
    int amount;

    FILE *ptr;
    ptr=fopen("SALES","r");
    if(ptr==NULL)
        printf("\t\t\t\tTHE FILE  DOES NOT OPEN OR EXIST.\n");

    int q=1;
    printf("\t\t\t\tS.NO\t\tNAME\t\t\tROLL NUMBER\t\tAMOUNT\n");
    while(feof(ptr)==0)
    {
        fscanf(ptr,"%s %s %d\n",stud.name,stud.rollnumber,&amount);
        fprintf(stdout,"\t\t\t\t%d.\t\t%s\t\t\t%s\t\t%d\n",q,stud.name,stud.rollnumber,amount);
        total+=amount;
        q++;
    }
    fclose(ptr);


    printf("\n\t\t\t\tTHE TOTAL SALE TILL NOW IS: %ld",total);

    printf("\n\t\t\t\tPRESS ANY KEY TO RETURN:");
    getch();
     if(c==1)
    {
        owner();
    }
    else
    {
        employee();
    }

}


void delete_sales_record()
{
    system("cls");

    remove("SALES");
    FILE *ptr;
    ptr=fopen("SALES","a");
    fclose(ptr);
    printf("\t\t\t\tSALES RECORD DELETED SUCCESSFULLY\n");
    printf("\t\t\t\tPRESS ANY  KEY TO RETURN: ");
    getch();
    owner();
}