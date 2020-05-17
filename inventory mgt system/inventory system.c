#include <stdio.h>                      //for standard input output like printf , scanf
#include <string.h>                     // for strings
#include <ctype.h>                      //for isalpha(),isdigit()
#include <conio.h>                      // for console input output like getch(),printf()
#include<stdlib.h>
#include<windows.h>

FILE *f1,*f2;                         //declare files globally

int add();
int del();
int modify();
int disp();
int search();
int finish();

struct product                         //structure of product
{
 int code;
 char name[20];
 char compname[20];
 long int price;
 int pieces;
 char model[20];
}p;

void clrscr()
{
    system("cls");
}

int gotoxy(int x,int y)
{
    COORD coord = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void delay(const unsigned short ms)
{
    unsigned short i,k;
    k = 120*ms;
    for(i=0;i<k;i++){;}
}

void header()                         // First page
{
 clrscr();
 gotoxy(15,3);
 printf("Welcome to    ");
 gotoxy(10,7);
 printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  ");
 gotoxy(15,10);
 printf("INVENTORY");
 printf("\n\n\n\n \t\t\t\t\tMANAGEMENT");
 printf("\n\n\n\n \t\t\t\t\t\t\t\t   SYSTEM");
 gotoxy(10,20);
 printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
 gotoxy(55,22);
 printf("Press any key to continue  ");
 getch();
}

int strval(char s[])                                 //String validation
{
 int i,f=0;
 fflush(stdin);
 for(i=0;i<strlen(s);i++)
 {
  if(!isalpha(s[i]))
  {
   if(s[i]==' ')
     f=0;
   else
   {
    f=1;
    break;
   }
  }
 }
 if(f==1)
   return 1 ;
 else
   return 0 ;
}

int alpnum(char s[])                      // Alpha numeric validation
{
 int i,f=0;
 fflush(stdin);
 for(i=0;i<strlen(s);i++)
 {
  if(!isalnum(s[i]))
  {
    f=1;
    break;
  }
 }
  if(f==1)
    return 1 ;
  else
    return 0 ;
}

int digval(char s[])                     //Digits validation
{
 int i,f=0;
 for(i=0;i<strlen(s);i++)
 {
  if(!isdigit(s[i]))
  {
   f=1;
   break;
  }
 }
 if(f==1)
   return 1 ;
 else
   return 0 ;
}

void menu()                           // Main menu
{
 int ch;
 clrscr();
 gotoxy(34,2);
 delay(400);
 printf("*  MAIN  MENU  *");
 delay(400);
 gotoxy(33,3);
 printf(" *  *  *  *  *  *");
 delay(500);
 gotoxy(32,6);
 printf("1 : ADD PRODUCT");
 gotoxy(32,8);
 delay(500);
 printf("2 : DELETE PRODUCT");
 gotoxy(32,10);
 delay(500);
 printf("3 : MODIFY PRODUCT");
 gotoxy(32,12);
 delay(500);
 printf("4 : DISPLAY PRODUCT");
 gotoxy(32,14);
 delay(500);
 printf("5 : SEARCH PRODUCT");
 gotoxy(32,16);
 delay(500);
 printf("6 : EXIT");
 fflush(stdin);
 delay(800);
 gotoxy(32,22);
 printf("ENTER YOUR CHOICE :-  ");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1 : add();
	   break;
  case 2 : del();
	   break;
  case 3 : modify();
	   break;
  case 4 : disp();
	   break;
  case 5 : search();
	   break;
  case 6 : finish();

  default :gotoxy(35,24);
	   delay(1500);
	   printf("It's wrong choice!!!!!!      ");
	   gotoxy(35,25);
	   printf("Please choose correct option!!");
	   menu();
 }
}

int finish()                              // Finish page
{
 clrscr();
 gotoxy(35,12);
 printf("Thank  You !!!!!!!!");
 delay(2000);
 exit(0);
 return 0 ;
}

int add()                                   // Addition of product
{
  int f=0,k,g;
  float x,y,z;
  char s[20],a[20];
  f1=fopen("Product.txt","ab+");
  clrscr();
  if(f1==NULL)
  {
   gotoxy(15,10);
   printf("Cannot open file");
   exit(0);
  }
  else
  {
    gotoxy(15,3);
    printf("* * * * * * * * Addition of new product * * * * * * * * * * ");
    printf("\n\n\n");
    k=0;
    fseek(f2,-71,SEEK_END);
      while(fread(&p,sizeof(p),1,f1)==1)
      {
	fflush(stdin);
	k=p.code;
      }
    fflush(stdin);
    k=k+1;

    p.code=k;
    printf("Code = %d",p.code);
    b:
      f=0;
      delay(400);
      printf("\n\n");
      fflush(stdin);
      printf("Enter Name of product :- ");
      gets(p.name);
      f=strval(p.name);
      if(f==1)
      {
	delay(300);
	printf("                                     Invalid name!!   Please enter again ");
	goto b;
      }
      strcpy(s,p.name);
      strcpy(a,s);
      fseek(f1,0,SEEK_SET);
      while(fread(&p,sizeof(p),1,f1)==1)
      {
       if((strcmp(p.name,a))==0)
       {
	 delay(300);
	 printf("                             Sorry!!!! Product already  exist");
	 goto b;
       }
      }
      strcpy(p.name,s);
      f=0;
      c:
      printf("\n");
      fflush(stdin);
      printf("Enter Model no. of product :- ");
      gets(p.model);
      f=alpnum(p.model);
      if(f==1)
      {
       delay(300);
       printf("                                         Only alphanumerics are allowed");
       goto c;
      }
	      delay(400);

	    f=0;
	    d:
	    printf("\n");
	    fflush(stdin);
	    printf("Enter Company name of the product :- ");
	    gets(p.compname);
	    f=strval(p.compname);
	    if(f==1)
	      {
	       delay(300);
	       printf("                                          Only alphabets are allowed");
	       goto d;
	      }
	      delay(400);
	    e:
	     fflush(stdin);
	     printf("\n");
	     printf("Enter Price of product :- ");
	     scanf("%f",&y);
	     p.price=y;
	     if(p.price!=y)
	     {
	      delay(300);
	      printf("                                          Only digits are allowed");
	      goto e;
	     }
	     delay(400);
	    h:
	     printf("\n");
	     fflush(stdin);
	     printf("Enter Pieces of product :- ");
	     scanf("%f",&z);
	     p.pieces=z;
	     if(p.pieces!=z)
	     {
	      delay(300);
	      printf("                                          Only digits are allowed");
	      goto h;
	     }
	     fseek(f1,0,SEEK_END);
	     fflush(stdin);
	     p.code=k;
	     fwrite(&p,sizeof(p),1,f1);
	     fclose(f1);
	     delay(1000);
	     printf("\n\n             ");
	     printf(" * * * * * * * * Addition of product successfull * * * * * *");
	     getch();
	     menu();
 }
 return 0 ;
}

int del()                                 // Deletion of product
{
    char s[20];
    int f=0,flag=1;
    clrscr();
    f1=fopen("Product.txt","rb");
    f2=fopen("temp.txt","wb");
    if(fread(&p,sizeof(p),1,f1)==0)
    {
      delay(300);
      gotoxy(25,15);
      printf("Sorry\n");
      printf("No records to delete");
      getch();
      menu();
    }

    fseek(f1,0,SEEK_SET);
    gotoxy(15,3);
    printf("* * * * * * * * Deletion of new product * * * * * * * * * * ");
    printf("\n");
    g:
	fflush(stdin);
	printf("\n");
	printf("Enter the name of product to delete  :- ");
	gets(s);
	f=strval(s);
	if(f==1)
	{
	 delay(300);
	 printf("                                           Only alphabets are allowed");
	 goto g;
	}
	while(fread(&p,sizeof(p),1,f1)==1)
	{
	  fflush(stdin);
	  if((strcmp(p.name,s))!=0)
	    fwrite(&p,sizeof(p),1,f2);
	  else
	  {
	    printf("\n\n\n");
	    printf("The details of product are :- ");
	    printf("\n\n");
	    printf("Name         :- %s",p.name);
	    printf("\n\n");
	    printf("Model no.    :- %s",p.model);
	    printf("\n\n");
	    printf("Company name :- %s",p.compname);
	    printf("\n\n");
	    printf("Pieces       :- %d",p.pieces);
	    printf("\n\n");
	    printf("Price        :- %ld",p.price);
	    flag=0;
	  }
	}
	fclose(f1);
	fclose(f2);
	if(flag==1)
	{
	  delay(300);
	  gotoxy(30,13);
	  printf("Sorry\n");
	  printf("   Product was not found");
	  getch();
	  menu();
	}
	remove("Product.txt");
	rename("temp.txt","Product.txt");
	delay(1000);
	printf("\n\n\n\n       ");
	printf("* * * * * * * * * Deletion of product is successful * * * * * * * * * * *");
	getch();
	menu();

     return 0 ;
}

int disp()                   //  display products
{
char c;
int i,n;
clrscr();
f1=fopen("Product.txt","rb");
if((fread(&p,sizeof(p),1,f1))==0)
{
  delay(300);
  gotoxy(25,15);
  printf("Sorry\n");
  printf("   No records to display");
  getch();
  menu();
}
 fseek(f1,0,SEEK_SET);
 gotoxy(17,2);
 printf("* * * * * * * * FILE CONTENTS * * * * * * * *                   \n");
 delay(400);
 printf("--------------------------------------------------------------------------------");
 printf("\n| Code |  Name          |  Model      |  Company name     |  Price    | Pieces |");
 printf("\n--------------------------------------------------------------------------------");
 fflush(stdin);
 i=7;
 while(fread(&p,sizeof(p),1,f1)==1)
 {
  delay(600);
  gotoxy(1,i);
  printf("|");
  gotoxy(4,i);
  fflush(stdin);
  printf("%d",p.code);
  gotoxy(8,i);
  printf("|");
  gotoxy(11,i);
  fflush(stdin);
  printf("%s",p.name);
  gotoxy(25,i);
  printf("|");
  gotoxy(28,i);
  fflush(stdin);
  printf("%s",p.model);
  gotoxy(39,i);
  printf("|");
  gotoxy(42,i);
  fflush(stdin);
  printf("%s",p.compname);
  gotoxy(58,i);
  printf("|");
  gotoxy(61,i);
  fflush(stdin);
  printf("%ld",p.price);
  gotoxy(70,i);
  printf("|");
  gotoxy(72,i);
  fflush(stdin);
  printf("%d",p.pieces);
  gotoxy(80,i);
  printf("|");
  i=i+2;
 }
 fclose(f1);
 getch();
 menu();

 return 0 ;
}

int search()                     // Search product
{
  char s[10];
  int f=0,flag=1;
  clrscr();
  f1=fopen("Product.txt","rb");
  if(fread(&p,sizeof(p),1,f1)==0)
   {
    delay(300);
    gotoxy(25,15);
    printf("Sorry\n");
    printf("  No records to search");
    getch();
    menu();
   }
    fseek(f1,0,SEEK_SET);
    gotoxy(15,3);
    printf("* * * * * * * * Searching of new product * * * * * * * * * * ");
    printf("\n\n");
    i:
      printf("\n");
      fflush(stdin);
      printf("Enter name of product to be searched  :- ");
      gets(s);
      f=strval(s);
      if(f==1)
      {
       delay(300);
       printf("                                               Only alphabets are allowed");
       goto i;
      }
      delay(600);
      while(fread(&p,sizeof(p),1,f1)==1)
      {
       if((strcmp(p.name,s))==0)
       {
	 printf("\n\n\n");
	 printf("The details of product are :- ");
	 printf("\n\n");
	 printf("Name         :- %s",p.name);
	 printf("\n\n");
	 printf("Model no.    :- %s",p.model);
	 printf("\n\n");
	 printf("Company name :- %s",p.compname);
	 printf("\n\n");
	 printf("Pieces       :- %d",p.pieces);
	 printf("\n\n");
	 printf("Price        :- %ld",p.price);
	 flag=0;
       }
      }

    if(flag==1)
    {
      delay(300);
      gotoxy(30,13);
      printf("Sorry\n");
      printf("  Product was not found");
      getch();
      menu();
    }
    fclose(f1);
    fflush(stdin);
    getch();
    menu();

    return 0 ;
}

int modify()                                 // Modify product
{
    int ch,flag=1;
    float x,y;
    char s[20];
    int f;
    char c;
    clrscr();
    f1=fopen("Product.txt","rb");
    f2=fopen("temp.txt","wb");
  if(fread(&p,sizeof(p),1,f1)==0)
    {
      delay(300);
      gotoxy(25,15);
      printf("Sorry\n");
      printf("  No records to modify");
      getch();
      menu();
    }
    fseek(f1,0,SEEK_SET);
    gotoxy(15,3);
    printf("* * * * * * * * Modification of new product * * * * * * * ");
    printf("\n");
    j:
      fflush(stdin);
      printf("\n");
      printf("Enter name of product which is to be modify :- ");
      gets(s);
      f=strval(s);
      if(f==1)
      {
       delay(300);
       printf("\n                                     Only alphabets are allowed");
       goto j;
      }
      delay(700);
      while(fread(&p,sizeof(p),1,f1)==1)
      {
       if(strcmp(p.name,s)==0)
       {
	printf("\n\n");
	printf("The details of product are :- ");
	printf("\n");
	printf("Name         :- %s",p.name);
	printf("\n");
	printf("Model no.    :- %s",p.model);
	printf("\n");
	printf("Company name :- %s",p.compname);
	printf("\n");
	printf("Pieces       :- %d",p.pieces);
	printf("\n");
	printf("Price        :- %d",p.price);
	flag=0;
	delay(600);
	printf("\n\n");
	printf("What do you want to modify?");
	printf("\n");
	printf("Press 1 for Name");
	printf("\n");
	printf("Press 2 for model no.");
	printf("\n");
	printf("Press 3 for Company name");
	printf("\n");
	printf("Press 4 for pieces");
	fflush(stdin);
	printf("\n");
	printf("Press 5 for price");
	delay(400);
	l:
	printf("\n     ");
	printf("Enter choice :- ");
	scanf("%d",&ch);
	switch (ch)
	{
	 case 1 : m:
		  fflush(stdin);
		  printf("\n");
		  printf("Enter new name  :- ");
		  gets(p.name);
		  f=strval(p.name);
		  if(f==1)
		  {
		   delay(300);
		   printf("                                             Only alphabets are allowed");
		   goto m;
		  }
		  f=0;
		  break;
	 case 2 : n:
		  fflush(stdin);
		  printf("\n");
		  printf("Enter new model no.  :- ");
		  gets(p.model);
		  f=alpnum(p.model);
		  if(f==1)
		  {
		    delay(300);
		    printf("                                            Only alphabets are allowed");
		    goto n;
		  }
		  f=0;
		  break;
	 case 3 : o:
		  printf("\n");
		  fflush(stdin);
		  printf("Enter new Company name  :- ");
		  gets(p.compname);
		  f=strval(p.compname);
		  if(f==1)
		  {
		   delay(300);
		   printf("                                         Only alphabets are allowed");
		   goto o;
		  }
		  f=0;
		  break;
	 case 4 : q:
		  printf("\n");
		  fflush(stdin);
		  printf("Enter new pieces of product  :- ");
		  scanf("%f",&x);
		  p.pieces=x;
		  if(p.pieces!=x)
		  {
		    delay(300);
		    printf("                                    Only digits are allowed");
		    goto q;
		   }
		   break;
	 case 5 : r:
		  fflush(stdin);
		  printf("\n");
		  printf("Enter new price  :- ");
		  scanf("%f",&y);
		  p.price=y;
		  if(p.price!=y)
		  {
		   delay(300);
		   printf("                                  Only digits are allowed");
		   goto r;
		  }
		  break;
	 default :  delay(300);
		    printf("                Please choose correct option");
		    getch();
		    goto l ;

	}
	fwrite(&p,sizeof(p),1,f2);
      }
     else
     {
       fwrite(&p,sizeof(p),1,f2);
     }
  }

  fclose(f1);
  fclose(f2);
  if(flag==1)
  {
   delay(300);
   gotoxy(30,13);
   printf("Sorry\n");
   printf("  Product was not found");
   getch();
   menu();
  }
  remove("Product.txt");
  rename("temp.txt","Product.txt");
  delay(1000);
  printf("\n\n           ");
  printf("* * * * * * * * Modification of new product * * * * * * * * * * ");
  fflush(stdin);

  getch();
  menu();
  return 0 ;
}

void main()                       // Main
{
    header();
    menu();
    getch();
}
