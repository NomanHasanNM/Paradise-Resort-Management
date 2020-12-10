#include<stdio.h>
#include<stdlib.h>

struct room
{

    int no;
    int status;
    char name[20];
    char address[50];
    int ph;
    int price;
    int days;
    int cost;
    struct room *next;
    struct room *prev;
}*start=NULL,*end=NULL;
void create()
{
    int num,i;
    struct room *new_room,*current;
    for(i=501; i<521; i++)
    {
        new_room=(struct room*)malloc(1*sizeof(struct room));
        new_room->no=i;
        new_room->price=1000;
        new_room->status=0;
        new_room->next=NULL;
        new_room->prev=NULL;
        if(start==NULL&&end==NULL)
        {
            start=new_room;
            end=new_room;
            current=new_room;
        }
        else
        {
            current->next=new_room;
            new_room->prev=current;
            end=new_room;
            current=new_room;
        }
        new_room->next=new_room;
    }

}

void book()
{

    int i,n=0;

    struct room *current;

    current=start;

    for(i=1; i<21; i++)
    {
        if(current->status==0)
        {
            current->status=1;
            printf("\nROOM NO: %d\n",current->no);
            printf("\nENTER YOUR NAME\n");
            scanf("%s",&current->name);
            printf("\nENTER YOUR ADDRESS\n");
            scanf("%s",&current->address);
            printf("\nENTER YOUR PHONE NUMBER:\n");
            scanf("%s",&current->ph);
            printf("\nHOW menuY DAYS YOU WANT TO STAY?\n");
            scanf("%d",&current->days);
            current->cost=(current->price)*(current->days);


            printf("\nCONGRATULATIONS ROOM NO: %d IS BOOKED FOR MR. %s \n",current->no,current->name);
            printf("\nTOTAL COST = %d tk\n",current->cost);
            menu();
        }
        else
        {
            n++;
            current=current->next;
            if(n==20)
            {
                printf("\nSORRY!NO ROOMS AVAILABLE\n");
                menu();
            }
        }

    }

}


void book1()
{

    int i,n=0;

    struct room *current;

    current=start;

    for(i=1; i<21; i++)
    {
        if(current->status==0)
        {
            current->status=1;
            printf("\nROOM NO: %d\n",current->no);
            printf("\nENTER YOUR NAME\n");
            scanf("%s",&current->name);
            printf("\nENTER YOUR ADDRESS\n");
            scanf("%s",&current->address);
            printf("\nENTER YOUR PHONE NUMBER:\n");
            scanf("%s",&current->ph);
            printf("\nHOW menuY DAYS YOU WANT TO STAY?\n");
            scanf("%d",&current->days);
            current->cost=(current->price)*(current->days);


            printf("\nCONGRATULATIONS ROOM NO: %d IS BOOKED FOR MR. %s \n",current->no,current->name);
            printf("\nTOTAL COST = %d tk\n",current->cost);
            user();
        }
        else
        {
            n++;
            current=current->next;
            if(n==20)
            {
                printf("\nSORRY!NO ROOMS AVAILABLE\n");
                user();
            }
        }

    }

}

void out()
{
    int n,i;
    printf("\nENTER ROOM NO TO CHECK OUT\n");
    scanf("%d",&n);
    struct room *current;

    current=start;

    for(i=1; i<21; i++)
    {
        if(current->no==n)
        {
            current->status=0;
            printf("SUCCESSFULLY CHECKED OUT");
            menu();
        }
        else
            current=current->next;
    }
}


void info()
{
    int n,i;
    printf("\nENTER ROOM NO TO CHECK INFO\n");
    scanf("%d",&n);
    struct room *current;

    current=start;

    for(i=1; i<21; i++)
    {
        if(current->no==n)
        {
            if(current->status==1)
            {
                printf("\nROOM IS TAKEN ALREADY BY:");
                printf("%s\n",current->name);
                printf("\nADDRESS:%s\n",current->address);
                printf("%s\n",current->name);
                printf("\nnumber:%D\n",current->ph);
                printf("\nBOOKED FOR %d DAYS\n",current->days);
                printf("\nCOST %d TK \n",current->cost);
                menu();
            }

        }
        else
            current=current->next;
    }
}

void all()
{
    int n,i;
    struct room *current;

    current=start;

    for(i=1; i<21; i++)
    {

        if(current->status==1)
        {
            printf("\nROOM NO:%d\n",current->no);
            printf("\nROOM IS TAKEN ALREADY BY:");
            printf("%s\n",current->name);
            printf("\nADDRESS:%s\n",current->address);
            printf("\nnumber:%D\n",current->ph);
            printf("\nBOOKED FOR %d DAYS\n",current->days);
            printf("\nCOST %d TK \n",current->cost);

        }


        else
        {
            printf("\nROOM NO:%d IS AVAILABLE\n",current->no);
        }

        current=current->next;
    }
    menu();
}

void menu()
{
    printf("\n\n\n\tHere is our services:\n\n");
    int choice;
    printf("\n1.ROOM BOOKING");
    printf("\n2.CHECK OUT");
    printf("\n3.ROOM CHECK");
    printf("\n4.CHECK ALL ROOMS");
    printf("\n5.ABOUT US\n6.BACK TO LOGIN PAGE\n");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    if(choice==1)
    {
        book();
    }

    if(choice==2)
    {
        out();
    }
    if(choice==3)
    {
        info();
    }
    if(choice==4)
    {
        all();
    }
    if(choice==5)
    {
        about();
    }
    if(choice==6)
    {
        login();
    }
}

void about()
{
    printf("\nPARADISE RESORT IS ONE OF THE BEST HOTEL IN SHANHOK\n");
    printf("\nWE OFFER BEST QUALITY ROOMS,WITH A VERY LOW PRICE\n");
    printf("IF YOU HAVE ANY PROBLEM DONT HESITATE TO CONTACT US\n");
    printf("MOBILE: 0123456789");

}

void user()
{
    int l;
    printf("\nWNTER YOUR CHOICE:\n1.CHECK AVAILABLE ROOMS\n2.BOOK ROOMS\n3.ABOUT US\n4.BACK TO LOGIN PAGE\n\n");
    scanf("%d",&l);
    if(l==1)
    {
        check();
    }
    if(l==2)
    {
        book1();
    }
    if(l==4)
    {
        login();
    }
    else
        about();
}
void check()
{

    int i;
    struct room *current;

    current=start;

    for(i=1; i<21; i++)
    {
        if(current->status==1)
        {
            printf("\nROOM NO: %d is TAKEN\n",current->no);

        }


        else
        {
            printf("\nROOM NO: %d is AVAILABLE TO BOOK\n",current->no);
        }
        current=current->next;



    }
    user();

}

void adm()
{
    int pass;
    printf("\nENTER ADMIN PASSWORD:\n");
    scanf("%d",&pass);
    if(pass==1221)
    {
        menu();
    }
    else
    {
        printf("\nWRONG PASSWORD:\n");

        login();
    }




}


void login()
{

    int w;

    printf("\n LOG IN AS:\n1.ADMIN\n2.USER\n");
    scanf("%d",&w);
    if(w==1)
    {
        adm();
    }
    else
    {
        user();
    }

}


void main()
{

    create();
    printf("\n            WELCOME TO PARADISE RESORT\n\n");
    login();


}
