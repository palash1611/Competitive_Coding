#include<bits/stdc++.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream>
#include<string.h>
#include<dos.h>
#include<graphics>
using namespace std;
int p_no,choice1;
int logo();
int intro();
void last();
class product
{
int prod_no,qty;
char prod_name[30];
float prod_mrp,price;
public:
void display_product();
char* retprodname();
int retprodno();
float retprodprice();
void create_product()
{ cout<<"\n Enter product no.: ";
cin>>prod_no;
cout<<"\nEnter product name :";
gets(prod_name);
cout<<"\nEnter rate of product :";
cin>>prod_mrp;
}
};
void product::display_product()
{
cout<<"\nTHe Product no is :"<<prod_no;
cout<<"\nThe name of product is :";
puts(prod_name);
cout<<"\nThe price of product is :"<<prod_mrp;
}
int product::retprodno()
{return prod_no;}
char* product::retprodname()
{return prod_name;}
float product::retprodprice()
{return prod_mrp;}
void write_product()
{
fstream fp1;
product p;
fp1.open("shop.dat",ios::app|ios::binary);
p.create_product();
fp1.write((char*)&p,sizeof(product));
fp1.close();
cout<<"\n\nThe Product has been created";
delay(1000);
}
void displayall()
{
fstream fp;
product p;
clrscr();
cout<<"\n\n\n\t\tDISPLAY ALL RECORDS!!!\n\n";
fp.open("shop.dat",ios::in|ios::binary);
while(fp.read((char*)&p,sizeof(product)))
{
p.display_product();
cout<<"\n\n \n\n";
getch();
}
fp.close();
//delay(2500);
}
void delete_product()
{
fstream fp;
product p;
char y;
clrscr();
cout<<"\nAre you Sure You Want to Delete the records?? (Y or
N)\a\a\a\n";
cin>>y;
if(y=='y'||y=='Y')
{
cout<<"\n\n\tRecord Deleted ..";
delay(1000);
fp.open("Shop.dat",ios::in|ios::out|ios::binary);
fstream fp2;
fp2.open("Temp.dat",ios::out|ios::binary);
remove("Shop.dat");
rename("Temp.dat","Shop.dat");
}
}
void menu()
{
fstream fp;
product p;
clrscr();
fp.open("Shop.dat",ios::in|ios::binary);
if(!fp)
{
cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To
Admin Menu to create a file";
getch();
exit(0);
}
cout<<"\n\n\t\t\t\tProduct MENU\n\n";
cout<<"\t################################################
#############\n";
cout<<"\t\t P.NO.\t\tNAME\t\tPRICE\n";
cout<<"\t################################################
#############\n";
while(fp.read((char*)&p,sizeof(product)))
{
cout<<"\t\t
"<<p.retprodno()<<"\t\t"<<p.retprodname()<<"\t\t"<<p.retprodprice(
)<<endl;
}
fp.close();
}
void placeorder()
{
fstream fp;
product p;
int order_arr[30],l=0,quan[30];
float total=0;
char ch='Y';
menu();
cout<<"\n\n\t\t\t============================";
cout<<"\n\t\t\t PLACE YOUR ORDER";
cout<<"\n\t\t\t============================\n";
do{
cout<<"\n\nEnter The Product Number Of The Product : ";
cin>>order_arr[l];
cout<<"\nQuantity in number : ";
cin>>quan[l];
l++;
cout<<"\nDo You Want To Order Another Product ? (y/n)";
cin>>ch;
}while(ch=='y' ||ch=='Y');
cout<<"\n\nThank You For Placing The Order";
clrscr();
cout<<"\n\n*************************************INVOICE
************************************\n";
cout<<"\nPr No.\t\tPr Name\t\t Quantity \t\tPrice \t\tAmount ";
for(int x=0;x<=l;x++)
{
fp.open("Shop.dat",ios::in|ios::binary);
fp.read((char*)&p,sizeof(product));
while(!fp.eof())
{
if(p.retprodno()==order_arr[x])
{
total+=p.retprodprice()*quan[x];
cout<<"\n"<<order_arr[x]<<"\t\t"<<p.retprodname()<<"\t\t\t"<<quan
[x]<<"\t\t"<<p.retprodprice()<<"\t\t"<<p.retprodprice()*quan[x];
getch();
}
fp.read((char*)&p,sizeof(product));
}
fp.close();
}
cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
cout<<"\n\n";
}
void adminmenu()
{
clrscr();
int ch;
cout<<"\n\n\n\tAdmin Menu";
cout<<"\n\n\t1.Create a Product";
cout<<"\n\n\t2.Display all Products";
cout<<"\n\n\t3.Delete All Product";
cout<<"\n\n\t4.Back to Main Menu";
cout<<"\n\n\tEnter your Choice (1-4) :";
cin>>ch;
switch(ch)
{
case 1: clrscr();
write_product();
break;
case 2: displayall();
break;
case 3: delete_product();
break;
case 4: break;
default: cout<<"\a";
adminmenu();
}
}
void login()
{
char m,k;
char username[20], password[20];
back:
clrscr();
cout<<"\n\n\n\t\t\t Login to Access the Store";
cout<<"\n\n\t\t\t Enter the detaiils below:";
cout<<"\n\n\n\t\tUSERNAME : ";
gets(username);
cout<<"\n\n\t\tPASSWORD : ";
gets(password);
if((strcmp(username,"username")!=0)||
(strcmp(password,"password")!=0))
{cout<<"\n\n\tWRONG PASSWORD!!!! Want to try Again>
(Y,y/N,n)";
cin>>m;
if (m=='y' || m=='Y')
goto back;
else
exit(0);
}
}
int logo()
{
restart:
clrscr();
void last();
int g=DETECT,d;
initgraph(&g, &d, "c:\\tc\\bgi");
int poly1[15];
//screen
poly1[0]=250;
poly1[1]=50;
poly1[2]=340;
poly1[3]=50;
poly1[4]=340;
poly1[5]=150;
poly1[6]=340;
poly1[7]=150;
poly1[8]=250;
poly1[9]=150;
drawpoly(5,poly1);
int poly2[15];
poly2[0]=260;
poly2[1]=60;
poly2[2]=330;
poly2[3]=60;
poly2[4]=330;
poly2[5]=140;
poly2[6]=260;
poly2[7]=140;
poly2[8]=260;
poly2[9]=60;
fillpoly(5,poly2);
//keyboard
int poly3[15];
poly3[0]=230;
poly3[1]=170;
poly3[2]=360;
poly3[3]=170;
poly3[4]=380;
poly3[5]=190;
poly3[6]=210;
poly3[7]=190;
poly3[8]=230;
poly3[9]=170;
setfillstyle(2,-1);
fillpoly(5,poly3);
line(250,50,250,150);
line(310,150,310,170);
line(280,150,280,170);
//mouse wire
arc(380, 190, 10, 120, 15);
arc(405,186, 190,270,10);
arc(407,200,10,100,4);
//mouse
ellipse(410, 204, 90, 450,6, 10);
//mouse button
arc(410,197,200,340,5);
int midx=getmaxx()/2;
int midy=getmaxy()/2;
settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
outtextxy(midx-243,midy+40,"WELCOME TO BIG
BAZAR ...A COMPLETE STORE !!!! ");
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(midx-130,midy+100,"For all your Daily needs !!! ");
outtextxy(midx-147,midy+140,"Press any key to enter the
Store.... ");
getch();
closegraph();
return(0);
}
void last()
{
cout<<"\n\n\n ,@@, \n\t\t"
<<" / / \n\t\t"
<<" Thanks For Shopping!! / / \n\t\t"
<<" \\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/._/ \n\t\t"
<<" \\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/ \n\t\t"
<<" \\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/ \n\t\t"
<<" \\~~~~~~~~~~~~~~~~~~~~~~~~~~~/ \n\t\t"
<<" \\~~~~~~~~~~~~~~~~~~~~~~~~~/ \n\t\t"
<<" \\_______________________/ \n\t\t"
<<" | | \n\t\t"
<<" |~~~~~~~~~~~~~~~~~~~~~~| \n\t\t"
<<" |______________________| \n\t\t"
<<" /``\\ /``\\ \n\t\t"
<<" \\__/ \\__/ \n\t\t";
delay(2000);
exit(0);
}
int intro()
{
clrscr();
textmode(BW80);
textcolor(2);
cprintf("\n\n Introduction");
textcolor(3);
cprintf("\n\n The following Project
is on the topic");
textcolor(5);
cprintf("\n\n SHOP
MANAGEMENT");
cprintf("\n\n\n\n");
textcolor(9);
cprintf(" The Project has been made By-");
textcolor(15);
cprintf("\n\n@ Divyanshu Khare
@ Palash Chaturvedi");
cprintf("\n\n\n\n");
textcolor(-12);
cprintf("\n\n\nPress any key to continue..");
textcolor(15);
getch();
return(0);
}
void main()
{
int ch1;
intro();
clrscr();
logo();
login();
do
{
clrscr();
cout<<"\n\n\t\t\t\t WELCOME";
cout<<"\n\n\n\n\n\t MAIN MENU";
cout<<"\n\t1. MAKE A PURCHASE";
cout<<"\n\t2. ADMIN MENU";
cout<<"\n\t3. EXIT";
cout<<"\n\t Please Select Your Option (1-3)";
cin>>ch1;
switch(ch1)
{
case 1: placeorder();
getch();
break;
case 2: adminmenu();
break;
case 3: {
clrscr();
goto K;
break;
}
default : cout<<"\a";
}
}
while(ch1>=1&&ch1<=3) ;
getch();
K:
last();
}
