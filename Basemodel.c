#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
FILE *f;
int pass=123,qntrem;
float tempcost;
char del[100];
typedef struct
{
    char name[100];
    int quantity;
    float cost;
} product;
product p;
void rem()
{
    FILE *f;
    //struct product p;
    f=fopen("stock.txt","a+");
    while(!feof(f))
    {
        fscanf(f,"%s %d %f",p.name,&p.quantity,&p.cost);
        if(stricmp(del,p.name)==0)
        {
            p.quantity-=qntrem;
            tempcost=p.cost;
            break;
        }
    }
    fclose(f);
}
void add()
{
    system("cls");
    f=fopen("stock.txt","a+");
    printf("\n\n\t\tName:");
    scanf("%s",p.name);
    printf("\t\tQuantity:");
    scanf("%d",&p.quantity);
    printf("\t\tCost:");
    scanf("%f",&p.cost);
    fprintf(f,"\n%s\t%d\t%.2f",p.name,p.quantity,p.cost);
    printf("\nItem success fully added.\n");
    fclose(f);
    printf("\nPress any key to main menu.");
    getch();
}
void sys()
{
    //struct product p;
    system("cls");
    printf("\t\t\t\t\t\tSuccessfully logged in\n\n");
    printf("\t\t\t\t\t\tAction to do\n\t\t\t\t\t\t[1]Inventory Management\n\t\t\t\t\t\t[2]Finance Management\n\t\t\t\t\t\t[0]Exit to Main Menu\n");
    int x;
    scanf("%d",&x);
    if(x==1)
    {
        add();
    }
}
void buy()
{
    //struct product p;
    system("cls");
    int j;
    printf("\t\t\t\t\t\tEnter the number of distinct products you want to buy: ");
    scanf("%d",&j);
    while(j--)
    {
        printf("\t\t\t\t\t\tEnter the name of the product and the quantity respectively: ");
        scanf("%s %d",del,&qntrem);
        rem();
        printf("\t\t\t\t\t\tPay the amount of %f: ",qntrem*tempcost);
        int r;
        scanf("%d",&r);
    }
    printf("\t\t\t\t\t\tPress any key to continue to the main menu\n");
    getch();
}
void view()
{
    system("cls");
    f=fopen("stock.txt","r");
    if(f==NULL) {
        printf("\nfile not found\n");
        printf("\nPress any key to main menu.");
        getch();
        return;
    }
    product p[100];
    float tmp;
    char temp[20];
    int i=0;
    while(!feof(f)) {
        fscanf(f,"%s\t%d\t%f\n",p[i].name,p[i].quantity,&p[i].cost);
        i++;
    }
    for(int k=0; k<i; k++) {
        for(int j=k; j<i; j++) {
            if(strcmp(p[k].name,p[j].name)>0) {
                tmp=p[k].cost;
                p[k].cost=p[j].cost;
                p[j].cost=tmp;

                p[k].quantity=p[k].quantity^p[j].quantity;
                p[j].quantity=p[k].quantity^p[j].quantity;
                p[k].quantity=p[k].quantity^p[j].quantity;

                strcpy(temp,p[k].name);
                strcpy(p[k].name,p[j].name);
                strcpy(p[j].name,temp);

            }
        }
    }
    printf("\n\t\tName            Code       Rate\n");
    for(int k=0; k<i; k++)
    {
        printf("\t\t%-11s   %6d   %8.2lf\n",p[k].name,p[k].quantity,p[k].cost);
    }
    fclose(f);
    printf("\nPress any key to main menu.");
    getch();
}
int main()
{
    //struct product p;
    printf("\t\t\t\t\t\tWelcome\n\n\n");
    int x;
    do
    {
        system("cls");
        printf("\t\t\t\t\t\tLogin to the System as:\n");
        printf("\t\t\t\t\t\t[1]A Customer\n\t\t\t\t\t\t[2]An Owner\n\t\t\t\t\t\t[0]Exit from the System\n\t\t\t\t\t\t");
        scanf("%d",&x);
        if(x==1)
        {
            view();
            buy();
        }else if(x==2)
        {
            system("cls");
            printf("\t\t\t\t\t\tLogin to the Management System\n\t\t\t\t\t\tEnter the Password to Login: ");
            int y=pass;
            do
            {
                if(y!=pass)
                {
                    printf("\t\t\t\t\t\tWrong Password. Try Again: ");
                }
                scanf("%d",&y);
            } while (y!=pass);
            if(y==pass)
            {
                sys();
            }
        }
    }while(x==1 || x==2);
}
