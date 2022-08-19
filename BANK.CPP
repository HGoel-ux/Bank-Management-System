
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>
//CLASS ACCOUNT AS THE MASTER CLASS
class account
{
double accno;
char name[30];
char address[40];
double balance;
double dd;
double yy;
double mm;
public:
       void getdetail();
       void showdetail();
       void modify_details();
       int retaccno(){return accno;}
       char* retname(){return name;}
       char* retadd(){return address;}
       float retbal(){return balance;}
       int retdd(){return dd;}
       int retmm(){return mm;}
       double retyy(){return yy;}
       void trans_in(int);
       void trans_out(int);
       void loan(int);

};
//CLASS MEMBER FUNCTION TO SHOW VALUES
void account::showdetail()
{


cout<<"\n+The Account holder Name ::> ";
cout<<name;
cout<<"\n+The Account initial Balance ::> ";
cout<<balance;
cout<<"\n+The Account holder's DOB ::> ";
cout<<dd<<"/"<<mm<<"/"<<yy;
cout<<"\n+The Account holder's Address ::> ";
cout<<address;
cout<<"\n+The Account Number is ::> "<<accno;

}

//CLASS MEMBER FUNCTION TO GET VALUES
void account::getdetail()
{
cout<<"Enter the account holder name (customer)  ::> ";
gets(name);
cout<<"\nEnter the account initial balance  ::> ";
cin>>balance;
cout<<"\nEnter the account holder's address  ::> ";
gets(address);
cout<<"\nEnter the Account holder's DOB (dd/mm/yyyy) ::> __:__:____";
gotoxy(49,9);
cin>>dd;
gotoxy(52,9);
cin>>mm;
gotoxy(55,9);
cin>>yy;
cout<<"\n________________________________________________________________________________";
cout<<"\nPress enter key to proceed : _ ";
cout<<"\n________________________________________________________________________________";
gotoxy(30,13);
getch();
gotoxy(1,16);
int y;
int s;
account p;
fstream f;
randomize();
again:
s=0;
y=random(500);
f.open("account.dat",ios::binary|ios::in);
while(!f.eof())
{ f.read((char*)&p,sizeof(p));
  if(y==p.retaccno())
    {
    s=1;
    break;
    }
}
f.close();
if(s==0)
  {cout<<"\n Your account no. is :: "<<y;
   accno=y;
   getch();
  }
else
   goto again;

}
//FUNCTION TO CREATE NEW ACCOUNT
void create_account()
{
clrscr();
cout<<"\t\tMAKE A NEW ACCOUNT \n\n";
account a;
a.getdetail();
fstream f;
f.open("account.dat",ios::binary|ios::app);
f.write((char*)&a,sizeof(a));
f.close();

}
//FUNCTION TO SEE A SPECIFIC ACCOUNT NUMBER BASED ACCOUNT DETAILS
void see_account()
{
clrscr();
cout<<"\t\tSEARCH RECORDS FOR EXISTING ACCOUNTS\n";
int x;
cout<<"\nEnter the account number to be searched for details ::> ";
cin>>x;
int k=0;
fstream f;
account a;
f.open("account.dat",ios::binary|ios::in);
while(!f.eof())
{
f.read((char*)&a,sizeof(a));
if(a.retaccno()==x){
if(f.eof()){
break;}
a.showdetail();
getch();
k=1;}
}
f.close();
if(k==0){
cout<<"\nAccount not found";
getch(); }
}

void account::modify_details()
{
cout<<"Enter the account holder name (customer)  ::> ";
gets(name);
cout<<"\nEnter the account holder's address  ::> ";
gets(address);
cout<<"\nEnter the Account holder's DOB (dd/mm/yyyy) ::> __:__:____";
gotoxy(49,7);
cin>>dd;
gotoxy(52,7);
cin>>mm;
gotoxy(55,7);
cin>>yy;
cout<<"\n________________________________________________________________________________";
cout<<"\nPress enter key to proceed : _ ";
cout<<"\n________________________________________________________________________________";
gotoxy(30,11);
getch();

}
void account::trans_in(int b)
{
clrscr();
cout<<"\nYour account number : "<<accno;
cout<<"\nYour account holder name : "<<name;
cout<<"\nYour initial balance : "<<balance;
balance+=b;
cout<<"\nYour account balance after deposit : "<<balance;
cout<<"\n\nThank u, for your trustful deposit\n";
}
void deposit()
{
account a;
int df;
int dep;
clrscr();
fstream f;
f.open("account.dat",ios::binary|ios::in|ios::out);
cout<<"\t\t\t    DEPOSIT CORNER\n";
cout<<"Enter the account number in which you want to deposit money : ";
cin>>df;
while(!f.eof())
{
f.read((char*)&a,sizeof(a));
if(a.retaccno()==df)
{
cout<<"\nACCOUNT FOUND!!!\n";
cout<<"Enter the amount of money to be added : ";
cin>>dep;
a.trans_in(dep);
f.seekp(f.tellg()-sizeof(a));
f.write((char*)&a,sizeof(a));
}}
cout<<"\nCASH DEPOSITED!!!\n";
getch();
}
void account::trans_out(int b)
{
clrscr();
cout<<"\nYour account number : "<<accno;
cout<<"\nYour account holder name : "<<name;
cout<<"\nYour initial balance : "<<balance;
if(b>balance-25)cout<<"\nyour balnce is not sufficient, Transaction failed!!!\nAn account must secure a minimum balance of 25 rupees\n";
else
{balance-=b;
cout<<"\nYour account balance after withdrawl : "<<balance;
cout<<"\n\nWe hope you have a better experience with us!!!\n";
}
}
void withdrawl()
{
account a;
int df;
int dep;
clrscr();
fstream f;
f.open("account.dat",ios::binary|ios::in|ios::out);
cout<<"\t\t\t    WITHDRAWL CORNER\n";
cout<<"Enter the account number from which you want to withdraw money : ";
cin>>df;
while(f.read((char*)&a,sizeof(a)))
{
if(a.retaccno()==df)
{
cout<<"\nACCOUNT FOUND!!!\n";
cout<<"Enter the amount of money to be withdrawn : ";
cin>>dep;
a.trans_out(dep);
f.seekp(f.tellg()-sizeof(a));
f.write((char*)&a,sizeof(a));
}
}
getch();
}


//FUNCTION TO SEE THE LIST OF ALL ACCOUNT HOLDERS
void see_acc_holders()
{
clrscr();
account a;
fstream f;

char h;
int i;
f.open("account.dat",ios::binary|ios::in);
prev:
clrscr();
cout<<"***********************ACCOUNT HOLDER'S SECURED DATA****************************";
cout<<"________________________________________________________________________________";
cout<<"Acc.no";
gotoxy(10,3);
cout<<"Name";
gotoxy(25,3);
cout<<"Address";
gotoxy(40,3);
cout<<"Balance";
gotoxy(55,3);
cout<<"DOB (dd:mm:yyyy)\n";
cout<<"________________________________________________________________________________\n";

//int fk;
//char cf;
//re:
i=5;
//fk=0;
while(f.read((char*)&a,sizeof(a)))
{
gotoxy(3,i);
cout<<a.retaccno();
gotoxy(10,i);
cout<<a.retname();
gotoxy(25,i);
cout<<a.retadd();
gotoxy(40,i);
cout<<a.retbal();
gotoxy(60,i);
cout<<a.retdd();
gotoxy(62,i);
cout<<":";
cout<<a.retmm();
gotoxy(65,i);
cout<<":"<<a.retyy();
++i;
if(i==25){
cout<<"\nPress any key to move to next screen";
getch();
clrscr();
i=5;

cout<<"________________________________________________________________________________";
cout<<"Acc.no";
gotoxy(10,3);
cout<<"Name";
gotoxy(25,3);
cout<<"Address";
gotoxy(40,3);
cout<<"Balance";
gotoxy(55,3);
cout<<"DOB (dd:mm:yyyy)\n";
cout<<"________________________________________________________________________________\n";

}
//{
//cout<<"\nDo you want to go to next page ? (Y/N) ::> ";
//cin>>cf;
//if((cf!='y')||(cf!='Y'))break;
//else{ fk=1;
//clrscr();}
//}
if(f.eof())
cout<<"\nEnter any key to move to main menu : ";
}
/*if(f.eof())
{cout<<"\nDo you want to go to previous page ?(y/n) ";
cin>>h;
if(h=='y')
goto prev;
}*/
f.close();
//if(fk==1)
//{cout<<"\n\nDo you want to go to previous page ? (Y/N) ::> ";
//cin>>cf;
//if((cf=='y')||(cf=='Y'))goto re; }
getch();
}
int accp;
long gh;
void modify_account()
{
clrscr();
cout<<"Enter the account number whose details are to modified : ";
cin>>accp;
cout<<"\n";
account a;
fstream f("account.dat",ios::in|ios::binary|ios::out);
while(!f.eof())
{
gh=f.tellg();
f.read((char*)&a,sizeof(a));
if(a.retaccno()==accp)
{
a.modify_details();
f.seekp(gh);
f.write((char*)&a,sizeof(a));
}

}
f.close();
}

void sort_balance()
{
clrscr();

fstream fi;
fi.open("account.dat",ios::in|ios::binary);
account ba[500];
int n=0;
while(fi.read((char*)&ba[n],sizeof(account)))
n++;
account temp;
for(int i=1;i<n;i++)
for(int j=0;j<n-i;j++)
if(ba[j].retbal()<ba[j+1].retbal())
{
temp=ba[j];
ba[j]=ba[j+1];
ba[j+1]=temp;
}
fi.close();
//to write the sorted array back
fstream f;
f.open("account.dat",ios::binary|ios::out);
i=0;
while(i<n)
{
f.write((char*)&ba[i],sizeof(account));
++i;
}
cout<<"\n\nTHE ACCOUNT DATA HAS SUCCESSFULLY BEEN SORTED\n";
f.close();
}

void sort_accno()
{
clrscr();

fstream fi;
fi.open("account.dat",ios::in|ios::binary);
account ba[500];
int n=0;
while(fi.read((char*)&ba[n],sizeof(account)))
n++;
account temp;
for(int i=1;i<n;i++)
for(int j=0;j<n-i;j++)
if(ba[j].retaccno()>ba[j+1].retaccno())
{
temp=ba[j];
ba[j]=ba[j+1];
ba[j+1]=temp;
}
fi.close();
//to write the sorted array back
fstream f;
f.open("account.dat",ios::binary|ios::out);
i=0;
while(i<n)
{
f.write((char*)&ba[i],sizeof(account));
++i;
}
cout<<"\n\nTHE ACCOUNT DATA HAS SUCCESSFULLY BEEN SORTED\n";
f.close();
}
void introduction()
{
clrscr();
char sa[9000];
fstream f;
f.open("intro.txt",ios::in);
while(!f.eof())
{f.getline(sa,8999,'*');
cout<<sa;
cout<<"\nClick to move to next page\n";
getch();
clrscr();
}
f.close();
}

/* needed to be deleted
void close_acc()
{
fstream f;
account a;
int ac;
cout<<"Enter the account the account number to be closed";
cin>>ac;
fstream f1;
f1.open("new.dat",ios::binary|ios::out);
f.open("account.dat",ios::binary|ios::in);
while(f.read((char*)&a,sizeof(account)))
{
if(a.retaccno()!=ac)
{
f1.write((char*)&a,sizeof(account));
}
}
f.close();
f1.close();
remove("account.dat");
rename("new.dat","account.dat");
}*/

void bank_economy()
{long int eco=0;
clrscr();
account a;
fstream f;
f.open("account.dat",ios::in|ios::binary);
while(f.read((char*)&a,sizeof(a)))
{
eco+=a.retbal();
}
f.close();
cout<<"ECONOMY of HVZ bank : !!! "<<eco<<" !!!\n\n";
cout<<"Press enter to continue to main menu\n";
}
void sort_acchnm()
{
clrscr();

fstream fi;
fi.open("account.dat",ios::in|ios::binary);
account ba[500];
int n=0;
while(fi.read((char*)&ba[n],sizeof(account)))
n++;
account temp;
for(int i=1;i<n;i++)
for(int j=0;j<n-i;j++)
if(strcmpi(ba[j].retname(),ba[j+1].retname())>0)
{
temp=ba[j];
ba[j]=ba[j+1];
ba[j+1]=temp;
}
fi.close();
//to write the sorted array back
fstream f;
f.open("account.dat",ios::binary|ios::out);
i=0;
while(i<n)
{
f.write((char*)&ba[i],sizeof(account));
++i;
}
cout<<"\n\nTHE ACCOUNT DATA HAS SUCCESSFULLY BEEN SORTED\n";
f.close();
}
void close_acc()
{
clrscr();
int racc;
account a;
fstream f,f1;
cout<<"\n\nWELCOME TO DELETE COUNTER\n";
cout<<"\n Enter the account number which is required to be closed : ";
cin>>racc;
f.open("account.dat",ios::binary|ios::in);
f1.open("new.dat",ios::binary|ios::out);
while(f.read((char*)&a,sizeof(a)))
{
if(a.retaccno()!=racc)
f1.write((char*)&a,sizeof(a));
else
cout<<"ACCOUNT NO."<<racc<<" has been successfully closed. You can collect your balance amount from counter.\n";
}
f.close();
f1.close();
remove("account.dat");
rename("new.dat","account.dat");
}


void main()
{
clrscr();
int choice;

char pass[20],npass1[20],npass2[20];
strcpy(pass,"bahubali");

textcolor(14);
textbackground(1);
clrscr();

for(int you=0;you<85;you++)
{
delay(100);
cout<<"!!   HGPL BANK  !!**!!";
};

textcolor(142);
textbackground(6);
clrscr();

for(you=0;you<230;you++)
{
delay(10);
cout<<" ^ >< ^ ";
};
char ash,are[20];
textcolor(142);
textbackground(1);
clrscr();
cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t loading...   ";
delay(3000);

char y;
redo:
clrscr();
cout<<"\n\n\n\n\n\n\nEnter the password : ";
cin>>are;
if(strcmp(are,pass)!=0){cout<<"\n\nALERT :::: WRONG PASSWORD";
cout<<"\nDo you want to enter it again ?(y/n) ";
cin>>ash;
if(ash=='y')
goto redo;
else exit(0);
}
cout<<"Press enter to continue : ";
getch();
textcolor(12);
textbackground(9);
clrscr();
cout<<"\n\n\t\t\tW\n";
delay(100);

cout<<"\t\t\t  E\n";
delay(100);

cout<<"\t\t\t    L\n";
delay(100);

cout<<"\t\t\t      C\n";
delay(100);

cout<<"\t\t\t        O\n";
delay(100);

cout<<"\t\t\t          M\n";
delay(100);

cout<<"\t\t\t            E\n\n";
delay(100);

cout<<"\t\t\t               T\n";
delay(100);

cout<<"\t\t\t                 O\n\n";
delay(100);

cout<<"\t\t\t                    H\n";
delay(100);

cout<<"\t\t\t                      G\n";
delay(100);

cout<<"\t\t\t                        P\n";
delay(100);

cout<<"\t\t\t                          L\n\n\n\n\n\n\n";
delay(50);


cout<<" PRESS ENTER TO PROCEED TO MAIN MENU\n";
getch();

start:
textcolor(15);
textbackground(14);
clrscr();
cout<<"\t\t\t       ***************\n\t\t\t       *  MAIN MENU  *\n\t\t\t       ***************\n";

cout<<"                    H-G-P-L  B-A-N-K O-F  H-I-N-D-U-S-T-A-N\n";

cout<<"_______________________________________________________________________________\n";

cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

cout<<"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";

cout<<"\t\t\t     -------------------\n\t\t\t     | 1.Introduction  |\n\t\t\t     | 2.create account|\n\t\t\t     | 3.see account   |\n\t\t\t     | 4.modify        |\n\t\t\t     | 5.sort accno.   |\n\t\t\t     | 6.sort accname  |\n\t\t\t     | 7.sort balance  |\n\t\t\t     | 8.deposit       |\n\t\t\t     | 9.withdrawl     |\n\t\t\t     | 10.close account|\n\t\t\t     | 11.Bank economy |\n\t\t\t     | 12.Security     |\n\t\t\t     | 13.Exit         |\n\t\t             -------------------\n";

cout<<"()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()\nEnter Your Choice : ";

cin>>choice;
textcolor(12);
textbackground(3);
clrscr();

if(choice==13)
exit(0);
if(choice==12)
{
clrscr();
cout<<"\n\t\t\tSECURITY__change the login password !!!\n";
cout<<"ENTER THE PASSWORD : ------\n\n\n\n\n\n\n\n\n\n";
gotoxy(22,3);
cin>>pass;
if(strcmpi(pass,"bahubali")==0)
{
fir:
clrscr();
cout<<"\nEnter the new password : ";
cin>>npass1;
cout<<"\nEnter the new password again : ";
cin>>npass2;
if(strcmp(npass1,npass2)==0)
{strcpy(pass,npass1);
cout<<"\nyour password has been changed\n";
}
else {cout<<"You have entered different passwords, please check again";
goto fir;}
cout<<"\n\n\n\n\nPress key go back to main menu";
getch();
goto start;
}
else
{
clrscr();
cout<<"\n\n\n\n\t\t          --------------------\n\t\t          |      Alert!!!    |\n\t\t          |  wrong password  |\n\t\t          --------------------";
getch();
goto start;
}
}
if(choice==2){
create_account();
clrscr();
cout<<"\nDo you want to go to main menu ? (y/n) : \n";
cin>>y;
if(y=='y') goto start;
else exit(0);
}
if(choice==3)
{
see_account();
clrscr();
cout<<"\nDo you want to go to main menu ? (y/n) : \n";
cin>>y;
if(y=='y') goto start;
else exit(0);
}
if(choice==4)
{
modify_account();
clrscr();
cout<<"\nDo you want to go to main menu ? (y/n) : \n";
cin>>y;
if(y=='y') goto start;
else exit(0);

}

if(choice==5)
{
sort_accno();
see_acc_holders();
getch();
clrscr();
cout<<"\nDo you want to go to main menu ? (y/n) : \n";
cin>>y;
if(y=='y') goto start;
else exit(0);

}

if(choice==6)
{
sort_acchnm();
see_acc_holders();

getch();
clrscr();
cout<<"\nDo you want to go to main menu ? (y/n) : \n";
cin>>y;
if(y=='y') goto start;
else exit(0);

}
if(choice==7)
{
sort_balance();
see_acc_holders();

getch();
clrscr();
cout<<"\nDo you want to go to main menu ? (y/n) : \n";
cin>>y;
if(y=='y') goto start;
else exit(0);

}

if(choice==8)
{deposit();

getch();
clrscr();
cout<<"\nDo you want to go to main menu ? (y/n) : \n";
cin>>y;
if(y=='y') goto start;
else exit(0);

}
if(choice==9)
{withdrawl();

getch();
clrscr();
cout<<"\nDo you want to go to main menu ? (y/n) : \n";
cin>>y;
if(y=='y') goto start;
else exit(0);

}

if(choice==10){
//interest();
close_acc();
//loan();
getch();
clrscr();
cout<<"\nDo you want to go to main menu ? (y/n) : \n";
cin>>y;
if(y=='y') goto start;
else exit(0);
}
if(choice==1){
introduction();
getch();
clrscr();
cout<<"\nDo you want to go to main menu ? (y/n) : \n";
cin>>y;
if(y=='y') goto start;
else exit(0);
}



if(choice==11)
{bank_economy();
 //security_login_detail();

getch();
clrscr();
cout<<"\nDo you want to go to main menu ? (y/n) : \n";
cin>>y;
if(y=='y') goto start;
else exit(0);

}
	      //future_development();passbook


/*cout<<"Do you want to go to main menu ? (y/n) : \n";
cin>>you;
if(you=='y') goto start;
else exit(0);
  */
getch();
}