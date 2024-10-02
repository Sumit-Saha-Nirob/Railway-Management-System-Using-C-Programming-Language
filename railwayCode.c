#include<stdio.h>
#include<conio.h>
#include<string.h>


struct system
{
    char train_name[50];
    char train_time[50];
    char train_destination[50];
    char train_code[50];
};



struct system train[100];
int main_exit;
int n=0;
void menu();
void add_train();
void show();
void edit();
void write();
void read();
void del_train();
void exit();



void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}



void menu()
{
    system("color f3");
    system("cls");
    printf("\n\xB3\xDB\xDB\xDB\xDB\xDB\xB2\xB2\xB2\xB2\xB1\xB1MENU\xB1\xB1\xB2\xB2\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xB3\n");
    printf("\n\xB2PRESS 1 TO ADD TRAINS");
    printf("\n\n\xB2PRESS 2 TO VIEW ALL TRAINS");
    printf("\n\n\xB2PRESS 3 TO EDIT");
    printf("\n\n\xB2PRESS 4 TO SAVE INFORMATION");
    printf("\n\n\xB2PRESS 5 TO READ FROM FILE");
    printf("\n\n\xB2PRESS 6 TO DELETE");
    printf("\n\n\xB2PRESS 7 TO EXIT\n");


    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        system("cls");
        add_train();
        menu();
        break;
    case 2:
        system("cls");
        show();
        menu();
        break;
    case 3:
        system("cls");
        edit();
        menu();
        break;
    case 4:
        system("cls");
        write();
        menu();
        break;
    case 5:
        system("cls");
        read();
        menu();
        break;
    case 6:
        system("cls");
        del_train();
        menu();
        break;
    case 7:
        system("cls");
        exit();
        break;

    default:
        printf("\n\nEnter a valid choice\n\n");
    }
}



void add_train()
{
    printf("\t\t\tADDING TRAIN\n\n");
    system("color F2");
    system("cls");
    int i;
    printf("How many trains you want to add: \n\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)

    {
        printf("Enter the train no.%d:\n\n",i+1);
        printf("Enter train name: \n");
        scanf("%s",train[i].train_name);
        printf("Enter train time: \n");
        scanf("%s",train[i].train_time);
        printf("Enter train destination:(to where) \n");
        scanf("%s",train[i].train_destination);
        printf("Enter train code: \n");
        scanf("%s",train[i].train_code);
        printf("\n\n");
}

     printf("Enter 0 to return main menu: ");
        scanf("%d",&i);

        if(i==0)
        {
            menu();
        }
}



void edit()
{
    system("color F2");
    system("cls");
    printf("Enter the train number you want to edit\n");
    int i;
    scanf("%d",&i);
    int j=i-1;
    printf("Enter 1 to change train name\n");
    printf("Enter 2 to change train time\n");
    printf("Enter 3 to change train destination\n");
    printf("Enter 4 to change train code\n");
    int m;
    scanf("%d",&m);

    if(m==1)
     {
        printf("\n\n\nEnter train name\n");
        scanf("%s",train[j].train_name);
        printf("Your edited train name is \n:");
        printf("%s",train[j].train_name);
     }
    if(m==2)
     {
        printf("Enter train time\n");
        scanf("%s",train[j].train_time);
        printf("Your edited train time is:\n");
        printf("%s",train[j].train_time);

     }
    if(m==3)
     {
        printf("Enter train destination\n");
        scanf("%s",train[j].train_destination);
        printf("Your edited train destination is:\n");
        printf("%s",train[j].train_destination);
     }
    if(m==4)
     {
        printf("Enter train code\n");
        scanf("%s",train[j].train_code);
        printf("Your edited train code is:\n");
        printf("%s",train[j].train_code);
     }

}



void show()
{
     system("cls");
     int i,n;
     printf("How many trains information do you need?: ");
     scanf("%d",&n);

     for(i=0;i<n;i++)
    {
        printf("\n%d no. train is:\n\n",i+1);
        printf(" train name: ");
        printf("%s",train[i].train_name);
        printf("\n train time: ");
        printf("%s",train[i].train_time);
        printf("\n train destination: ");
        printf("%s",train[i].train_destination);
        printf("\n train code: ");
        printf("%s\n",train[i].train_code);
    }
    printf("\nEnter 0 to return main menu: ");
        scanf("%d",&i);

        if(i==0)
        {
            menu();
        }
}



void del_train()
{
    printf("\n\n\nEnter the train number you want to delete\n\n\n");
    int d,i;
    scanf("%d",&d);
    if(d>n)
      {
         printf("\n\n\nThere isn't any train of that number!!!\n\n\n");
         del_train();
      }
    else{

    for(i=d-1;i<n-1;i++)
      {
        train[i]=train[i+1];
      }
    getch();
    menu();
    }

}




void write()
{
    FILE *fp;
    fp=fopen("train.txt","wt+");
    int i,c;
    fprintf(fp,"%d\n\n\n",n);
    printf("information has been saved");
    for(i=0;i<n;i++)
     {
        fprintf(fp,"%s\n",train[i].train_name);
        fprintf(fp,"%s\n",train[i].train_time);
        fprintf(fp,"%s\n",train[i].train_destination);
        fprintf(fp,"%s\n",train[i].train_code);
     }

    fclose(fp);

      printf("\t\t\tValue put into file\n\n\n");
      printf("Enter 0 to return main menu: ");
      scanf("%d",&c);

      if(c==0)
        {
            menu();
        }
      getch();
}



void read()
{
    system("cls");
    FILE *fp;
    fp=fopen("train.txt","r");
    int i,j;
    fscanf(fp,"%d",&n);
    for(j=0;j<n;j++)
     {
        fscanf(fp,"%s\n",&train[j].train_name);
        fscanf(fp,"%s\n",&train[j].train_time);
        fscanf(fp,"%s\n",&train[j].train_destination);
        fscanf(fp,"%s\n",&train[j].train_code);

     }
    for(j=0;j<n;j++)
     {
        fprintf(fp,"%s\n",&train[j].train_name);
        fprintf(fp,"%s\n",&train[j].train_time);
        fprintf(fp,"%s\n",&train[j].train_destination);
        fprintf(fp,"%s\n",&train[j].train_code);

        fclose(fp);

        printf("\t\t\t***********We loaded your file***********\n\n\n");
        printf("Enter 0 to return menu: ");
        scanf("%d",&i);

     if(i==0)
        {
            menu();
        }
     }

}



void main()
{
    system("color F0");
    printf("      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  WELCOME TO NSU RAILWAY MANAGEMENT SYSTEM  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n");

    printf("\n                       \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    printf("\n                       \xDB:::::::::::::::::::::::::::::::::::::\xDB");
    printf("\n                       \xDB::                                 ::\xDB");
    printf("\n                       \xDB::    \xB3***********************\xB3    ::\xDB");
    printf("\n                       \xDB::    \xB3*                     *\xB3    ::\xDB");
    printf("\n                       \xDB::    \xB3*     NSU RAILWAY     *\xB3    ::\xDB");
    printf("\n                       \xDB::    \xB3*       SYSTEM        *\xB3    ::\xDB");
    printf("\n                       \xDB::    \xB3*                     *\xB3    ::\xDB");
    printf("\n                       \xDB::    \xB3***********************\xB3    ::\xDB");
    printf("\n                       \xDB::                                 ::\xDB");
    printf("\n                       \xDB:::::::::::::::::::::::::::::::::::::\xDB");
    printf("\n                       \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");


    char pass[10],password[10]="12345";
    int i=0;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);

    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
                system("cls");
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {
                    printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;
                    }

        }

}
