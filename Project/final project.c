/*
 *          Project: Hospital Management System
 *          Made by:
 *                    1.)Name: Ahnaf Ojayer
 *                          ID:2121949642
 *                          Section:10
 *
 *
 *
 *
 */





#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

struct patient
{
    char name[20];
    char last_name[20];
    char disease[30];
    char gender[6];
    int age;
    int phone;
    int cabin;

} pat[100];
struct doctor
{
    char name[40];
    char name_2[40];
    char dept[30];
    float st_time;
    float end_time;
} doc[20];
void fordelay(int j);
void password();
void main_menu();
void add_patient();
void view_patient();
void search_patient();
void remove_patient();
void edit_patient();
void doctor();

int main()
{
    password();
    main_menu();
    return 0;
}

void fordelay(int j)
{
    int i,k;
    for(i=0; i<j; i++)
        k=i;
}
void password()
{
    system("color 0A");
    char pwd1[10] = {"123456"};
    char pwd2[10] ;

    printf("\n\n\n\n\t\t\t\t\tEnter password: ");
    scanf("%s",pwd2);

    if(strcmp(pwd1,pwd2)== 0)                                   //Verifying password
    {
        printf("\n\n\t\t\t\t\tMatch password.Loading");         //Password match
        for(int i=0; i<3; i++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("color 21");
        printf("\n\t\t\t\t\tLoading complete.Press any key to continue.");
    }
    else
    {
        system("color 4A");
        printf("\n\n\t\t\t\t\tWrong password! \n");             //Incorrect  password
        printf("\n\n\t\t\t\t\tTry again...");

        fflush(stdin);
        getchar();

        system("cls");
        password();
    }
    fflush(stdin);
    getchar();

    main_menu();
}

void main_menu()                                //Main menu layout
{
    system("cls");
    int option;
    system("color 7A");
menu:
    printf("\n\n\n\n\n\n\t\t\t\t=================================================================\n");
    printf("\t\t\t\t\t\t\tWELCOME TO CITY HOSPITAL\n");
    printf("\t\t\t\t=================================================================\n");
    printf("\t\t\t\t\tSelect an option:\n");
    printf("\t\t\t\t\t1.)Add patient record\n");
    printf("\t\t\t\t\t2.)View patient record\n");
    printf("\t\t\t\t\t3.)Search patient record\n");
    printf("\t\t\t\t\t4.)Remove patient record\n");
    printf("\t\t\t\t\t5.)Edit patient record\n");
    printf("\t\t\t\t\t6.)View available doctors\n");
    printf("\t\t\t\t\t7.)Exit\n");
    printf("\n\n\n\t\t\t\t\tEnter your option:");
    scanf("%d",&option);

    switch(option)
    {
    case 1:
        system("cls");
        add_patient();
        break;
    case 2:
        system("cls");
        view_patient();
        break;
    case 3:
        system("cls");
        search_patient();
        break;
    case 4:
        system("cls");
        remove_patient();
    case 5:
        system("cls");
        edit_patient();
        break;
    case 6:
        system("cls");
        doctor();
        break;
    case 7:
        exit(1);
        break;
    default:
        system("color 4A");
        printf("Wrong Input. Try again\n");
        goto menu;

    }
}


void add_patient()                              //Adding patient record
{
    int n;
    int num;
    FILE *fptr;
    fptr=fopen("patient.txt","r");              //Taking previous info from file before opening in write mode
    if(fptr==NULL)
        printf("File does not exist");

    fscanf(fptr,"%d", &n);

    for(int i=0; i<n; i++)
    {
        fflush(stdin);
        fscanf(fptr,"%s %s %s %s %d %d", pat[i].name,pat[i].last_name,pat[i].disease, pat[i].gender, &pat[i].age, &pat[i].phone);
    }
    fclose(fptr);

    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\tFirst Name:");          //Entering Patient record
    fflush(stdin);
    scanf("%s", pat[n].name);
    printf("\t\t\t\t\tLast Name:");
    fflush(stdin);
    scanf("%s", pat[n].last_name);
    printf("\t\t\t\t\tDisease:");
    fflush(stdin);
    scanf("%s", pat[n].disease);
    printf("\t\t\t\t\tGender:");
    fflush(stdin);
    scanf("%s", pat[n].gender);
    printf("\t\t\t\t\tAge:");
    fflush(stdin);
    scanf("%d", &pat[n].age);
    printf("\t\t\t\t\tPhone number:");
    fflush(stdin);
    scanf("%d", &pat[n].phone);
    printf("\t\t\t\t\tCabin number:");
    fflush(stdin);
    scanf("%d", &pat[n].cabin);

    n++;                            //Adding total no. of patient in file
    FILE *fp;
    fp=fopen("patient.txt","w");

    fprintf(fp,"%d\n", n);

    for(int i=0; i<n; i++)
    {
        fprintf(fp,"%s %s %s %s %d %d %d\n", pat[i].name,pat[i].last_name, pat[i].disease, pat[i].gender, pat[i].age, pat[i].phone,pat[i].cabin);

    }

    fclose(fp);
    main_menu();
}



void view_patient()                 //Viewing Patient record
{
    int n;
    FILE *fptr;
    fptr=fopen("patient.txt","r");
    if(fptr==NULL)
        printf("File does not exist");

    fscanf(fptr,"%d", &n);

    for(int i=0; i<n; i++)
    {
        fflush(stdin);
        fscanf(fptr,"%s %s %s %s %d %d %d", pat[i].name,pat[i].last_name,pat[i].disease, pat[i].gender, &pat[i].age, &pat[i].phone,&pat[i].cabin);
    }
    fclose(fptr);
    printf("\n\n\n\n\n\n\t\t\t\tLoading patient record. Please wait");
    for(int i=0; i<3; i++)
    {
        fordelay(100000000);
        printf(".");
    }
    system("cls");
    system("color 21");
    printf("\t\t\t\t----------------------------------\n");
    printf("\t\t\t\t\tPatient records\n");
    printf("\t\t\t\t----------------------------------\n");
    printf("\n\n\n\n");
    for(int i=0; i<n; i++)
    {
        printf("\t\t\t\t\tFirst Name:");
        printf("%s\n", pat[i].name);
        printf("\t\t\t\t\tLast Name:");
        printf("%s\n", pat[i].last_name);
        printf("\t\t\t\t\tDisease:");
        printf("%s\n", pat[i].disease);
        printf("\t\t\t\t\tGender:");
        printf("%s\n", pat[i].gender);
        printf("\t\t\t\t\tAge:");
        printf("%d\n", pat[i].age);
        printf("\t\t\t\t\tPhone number:");
        printf("%d\n", pat[i].phone);
        printf("\t\t\t\t\tCabin number:");
        printf("%d\n", pat[i].cabin);
        printf("\n\n");
    }
    printf("Press any key to continue");
    getch();
    main_menu();
}


void search_patient()
{
    int n,i,flag=0;
    char search[100];
    FILE *fp_2;
    fp_2=fopen("patient.txt","r");                  //Taking previous info from file before opening in write mode
    if(fp_2==NULL)
        printf("File does not exist");

    fscanf(fp_2,"%d", &n);

    for(int i=0; i<n; i++)
    {
        fflush(stdin);
        fscanf(fp_2,"%s %s %s %s %d %d %d", pat[i].name,pat[i].last_name,pat[i].disease, pat[i].gender, &pat[i].age, &pat[i].phone, &pat[i].cabin);
    }
    fclose(fp_2);

    printf("\n\n\n\n\n\t\t\t\t\tEnter Patient name:");
    scanf("%s", search);
    printf("\n\n\n\n\n\n\t\t\t\tSearching");
    for(int i=0; i<3; i++)
    {
        fordelay(100000000);
        printf(".");
    }
    system("cls");

    for(int i=0; i<n; i++)
    {
        if(strcmp(pat[i].name,search)==0)           //verifying if patient name is in file
        {
            system("color 21");
            printf("\n\n\n\n\t\t\t\t\tPATIENT RECORD FOUND\n");
            printf("\t\t\t\t\tName:%s %s\n\t\t\t\t\tDisease:%s\n\t\t\t\t\tGender:%s\n\t\t\t\t\tAge:%d\n\t\t\t\t\tPhone number:%d\n\t\t\t\t\tCabin:%d\n", pat[i].name,pat[i].last_name,pat[i].disease, pat[i].gender, pat[i].age, pat[i].phone,pat[i].cabin);
            flag=1;
            break;
        }

    }
    if(flag=0)
    {
        system("color 41");
        printf("\n\n\n\n\t\t\t\t\tRecord not found\n");
    }
    printf("\t\t\t\t\tPress any key to continue");

    getch();
    main_menu();

}



void remove_patient()
{
    int n;
    char search[100];
    FILE *fp_2;                             //Taking previous info from file before opening in write mode
    fp_2=fopen("patient.txt","r");
    if(fp_2==NULL)
        printf("File does not exist");

    fscanf(fp_2,"%d", &n);

    for(int i=0; i<n; i++)
    {
        fflush(stdin);
        fscanf(fp_2,"%s %s %s %s %d %d %d", pat[i].name,pat[i].last_name,pat[i].disease, pat[i].gender, &pat[i].age, &pat[i].phone, &pat[i].cabin);
    }
    fclose(fp_2);

    printf("\n\n\n\t\t\t\tEnter Patient name:");                  //Taking patient name to remove
    scanf("%s", search);



    FILE *fp_3;
    fp_3=fopen("patient.txt","w");


    for(int i=0; i<n; i++)
    {
        if(strcmp(pat[i].name,search)==0)               //If patient name exist we skip it's printing
        {
            continue;
        }
        else
        {
            system("color 4A");
            printf("\t\t\t\tError! Patient record does not exist\n\n");
            printf("\t\t\t\tPress any key to continue");
            getch();
            main_menu();
        }

    }
    n--;
                                                    //substracting the number of patients
    fprintf(fp_3,"%d\n", n);
    for(int i=0; i<n; i++)
    {
        if(strcmp(pat[i].name,search)==0)               //If patient name exist we skip it's printing
        {
            continue;
        }
        fprintf(fp_3,"%s %s %s %s %d %d %d\n", pat[i].name,pat[i].last_name,pat[i].disease, pat[i].gender, pat[i].age, pat[i].phone,pat[i].cabin);
        system("color 21");
        printf("\t\t\t\tPatient record removed\n\n\n");
    }
    fclose(fp_3);
    printf("\t\t\t\tPress any key to continue");
    getch();
    main_menu();
}

void
edit_patient()
{
    int n,i,flag=0;
    char search[100];
    FILE *fp_2;
    fp_2=fopen("patient.txt","r");                      //Taking patient name to remove
    if(fp_2==NULL)
        printf("File does not exist");

    fscanf(fp_2,"%d", &n);

    for(int i=0; i<n; i++)
    {
        fflush(stdin);
        fscanf(fp_2,"%s %s %s %s %d %d %d", pat[i].name,pat[i].last_name,pat[i].disease, pat[i].gender, &pat[i].age, &pat[i].phone, &pat[i].cabin);
    }
    fclose(fp_2);

    printf("\n\n\n\n\t\t\t\tEnter Patient name:");
    scanf("%s", search);                                   //Searching patient name in file to edit
    printf("\n\n\n\n\n\n\t\t\t\tSearching");
    for(int i=0; i<3; i++)
    {
        fordelay(100000000);
        printf(".");
    }
    system("cls");
    for(int i=0; i<n; i++)
    {
        if(strcmp(pat[i].name,search)==0)                   //Patient record found
        {
            system("color 21");
            printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\tPatient record found!!!\n");
            printf("\t\t\t\t\tFirst Name:");
            fflush(stdin);
            scanf("%s", pat[i].name);
            printf("\t\t\t\t\tLast Name:");
            fflush(stdin);
            scanf("%s", pat[i].last_name);
            printf("\t\t\t\t\tDisease:");
            fflush(stdin);
            scanf("%s", pat[i].disease);
            printf("\t\t\t\t\tGender:");
            fflush(stdin);
            scanf("%s", pat[i].gender);
            printf("\t\t\t\t\tAge:");
            fflush(stdin);
            scanf("%d", &pat[i].age);
            printf("\t\t\t\t\tPhone number:");
            fflush(stdin);
            scanf("%d", &pat[i].phone);
            printf("\t\t\t\t\tCabin number:");
            fflush(stdin);
            scanf("%d", &pat[i].cabin);
            flag=1;
            break;

        }
    }
    if(flag==0)          //If the name was not found i.e the loop went all the way until n-1
    {
        system("color 41");
        printf("\n\n\n\n\t\t\t\t\tRecord not found!\n");
    }
    FILE *fptr;
    fptr=fopen("patient.txt","w");
    if(fptr==NULL)
        printf("File does not exist");
    fprintf(fptr,"%d\n", n);
    for(int i=0; i<n; i++)
    {
        fprintf(fptr,"%s %s %s %s %d %d %d\n", pat[i].name,pat[i].last_name,pat[i].disease, pat[i].gender, pat[i].age, pat[i].phone,pat[i].cabin);
    }
    fclose(fptr);
    printf("\t\t\t\t\tPress any key to continue");
    getch();
    main_menu();
}



void
doctor()                                        //Available doctors list
{
    int n;
    int num;
    FILE *fptr;
    fptr=fopen("doctor.txt","r");
    if(fptr==NULL)
        printf("File does not exist");

    fscanf(fptr,"%d", &n);

    for(int i=0; i<n; i++)
    {
        fflush(stdin);
        fscanf(fptr,"%s %s %s %f %f", doc[i].name,doc[i].name_2,doc[i].dept, &doc[i].st_time, &doc[i].end_time);
    }
    fclose(fptr);
    printf("\n\n\n\n\n\n\t\t\t\tLoading Doctor record. Please wait");
    for(int i=0; i<3; i++)
    {
        fordelay(100000000);
        printf(".");
    }
    system("cls");
    system("color 30");
    for(int i=0; i<n; i++)
    {
        printf("\n\t\t\t\t\tName:%s %s\n", doc[i].name,doc[i].name_2,doc[i].dept, doc[i].st_time, doc[i].end_time);
        printf("\t\t\t\t\tDepartment:%s\n", doc[i].dept, doc[i].st_time, doc[i].end_time);
        printf("\t\t\t\t\tTime:%.2f - %.2f\n", doc[i].st_time, doc[i].end_time);
    }
    printf("\t\t\t\tPress any key to continue");
    getch();
    main_menu();
}
