#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip.h>

/***************************************************************************
*                       structure for date                                 *
***************************************************************************/
struct date{
int d;
int m;
int y;
};
/****************************************************************************
*                 structure for detail of crime by criminal                 *
****************************************************************************/
struct court{
char crime[20];
char act[20];
char cour[20];
char state[20];
};
/****************************************************************************
*             structure for physical description of criminal                *
****************************************************************************/
struct descp{
char colour[20];
char face[20];
char imark[20];              //identification mark(deformities)
char hight[10];
};

/****************************************************************************
*               structure for details of fir                              *
****************************************************************************/
struct police{
char station[50];
char fir_no[10];
date date_arrest;
};
/***************************************************************************
*           class CRIMINAL for getting all information about convict       *
****************************************************************************/
class criminal{
char name[20];
char sex[3];
char conno[10];
char age[4];
char address[50];   //address of criminal before arrest
court COURT;
police POLICE;
descp des;
public :
int ncheck(char arr[]); //function to check input is not numeric
int s_check(char a[]);//function to check input for sex has only one character
void input();
void output();
void delete_rec(char con_no[]);
int dcheck(char n[]);
void display();
void remove();
int menu();
void modify();
void list();
void empty();
int concheck(char b[]);
};

// ***********************end of class   *********************************


/**************************************************************************
*           functions to check for correct input                          **
************************************************************************* */
int criminal::ncheck(char arr[])
{
int i=0;
while(arr[i]!='\0')
{
if(((arr[i]>64)&&(arr[i]<92))||((arr[i]>95)&&(arr[i]<124))||(arr[i]==' '))
{
i++; continue;
}else
{cout<<"\n incorrect input  \ntry again \n\n";
return 0;
}}return 1;}


int criminal::s_check(char a[])
{clrscr();
if((a[0]=='m')||(a[0]=='f')||(a[0]=='M')||(a[0]=='F')&&(a[1]=='\0'))
return 1;
else
{cout<<"\n incorrect input\n try again \n\n";
return 0;
}}
/***************************************************************************
*               function to get convict record                            **
*****************************************************************************/
void criminal::input()
{clrscr();
this->empty(); criminal x;
int c=0;
fstream filin("jail.dat",ios::app|ios::binary);
while(!c)
{cout<<"\n enter convict code:";
gets(this->conno);
c=x.concheck(this->conno);
}c=0;
while(!c)
{cout<<"\n enter convict name:";
gets(this->name);
c=x.ncheck(this->name);
}c=0;
while(!c)
{cout<<"\n enter convict sex:";
gets(this->sex);
c=x.s_check(this->sex);
}

cout<<"\n enter convict address:";
gets(this->address);

cout<<"\n enter age of convict :";
gets(this->age);


clrscr();

c=0;
cout<<"\n enter description \n\n\t";
while(!c)
{cout<<"\n enter convict colour:";
gets(this->des.colour);
c=ncheck(this->des.colour);
}

c=0;
 while(!c)
{cout<<"\n enter convict face description:";
gets(this->des.face);
c=x.concheck(this->conno);
}

cout<<"\n enter convict hight in cm:";
gets(this->des.hight);



cout<<"\n enter convict identification mark (if nothing nill) :";
gets(this->des.imark);


clrscr();

cout<<"\n\n\t\t";
  c=0;
while(!c)
{cout<<"\n COURT (from which prisoner is convicted):";
gets(this->COURT.cour);
c=ncheck(this->COURT.cour);
}

c=0;
while(!c)
{cout<<"\n\n\tSTATE:";
 gets(this->COURT.state);
c=ncheck(this->COURT.state);
}

c=0;
while(!c)
{cout<<"\n\t\tCRIME:";
gets(this->COURT.crime);
c=ncheck(this->COURT.crime);
}

cout<<"\n\t\tACT(under which convicted):" ;
gets(this->COURT.act);


clrscr();

cout<<"\nENTER:\n\n\t\t\n\t\tCOMPLETE ADDRESS OF POLICE STATION:";
gets(this->POLICE.station);

cout<<"\n\t\tFIR_NO:";
gets(this->POLICE.fir_no);
cout<<"\n\t\tEnter date of arrest(dd/mm/yy):";

c=0;
while(!c)
{cout<<"\n\t\t\t\t\tday:";
cin>>this->POLICE.date_arrest.d;
   if((this->POLICE.date_arrest.d>31)||(this->POLICE.date_arrest.d<1))
   {cout<<"\n\nTHIS DATE DOES NOT EXIST....!!TRY AGAIN";
   c=0;}
    else
    c=1;
    }


c=0;
while(!c)
{cout<<"\n\t\t\t\t\tmonth:";
cin>>this->POLICE.date_arrest.m;
   if((this->POLICE.date_arrest.m>12)||(this->POLICE.date_arrest.m<1))
   {cout<<"\n\nTHIS MONTH DOES NOT EXIST....!!TRY AGAIN";
   c=0; continue; }
    else
    c=1;
   if((this->POLICE.date_arrest.d==31)&&(this->POLICE.date_arrest.m==2)||
      (this->POLICE.date_arrest.m==4)||(this->POLICE.date_arrest.m==6)||
      (this->POLICE.date_arrest.m==9)&&(this->POLICE.date_arrest.m==11))
   {cout<<"\n THIS MONTH DOES NOT HAVE 31 DAYS\N TRY AGAIN!!!!...";
   c=0;
   }else
   c=1;
   }

   c=0;
   while(!c)
   {cout<<"\n\t\t\t\t\tyear (in 4 digit):";
   cin>>this->POLICE.date_arrest.y;
   if((this->POLICE.date_arrest.y<=1930)||(this->POLICE.date_arrest.y>2017))
   {cout<<"\n INCORRECT INPUT \N TRY AGAIN !!!!!...";
   c=0;
    }
    else c=1;
    }
    char ch;
    do
    {cout<<"\n DO U WANT TO SAVE THIS INFORMATION(Y/N)";
    cin>>ch;
    if(ch=='y'||ch=='Y')
    {cout<<"\n\t\t  <<RECORD HAS BEEN SAVED>>" ;
    filin.write((char*)this,sizeof(criminal));
    }
    else{ if(ch=='n'||ch=='N')
    cout<<"\n enter correctly .TRY AGAIN !!!!...." ;
    }}while((ch!='y')&&(ch!='Y')&&(ch!='N')&&(ch!='n'));
    filin.close();
    }

    //end of input function


/****************************************************************************
**                  function showing convict record                      ****
*****************************************************************************/
void criminal::output()
{
clrscr();
cout<<"@@@@@@@@@@@@@PERSNOL RECORD OF CONVICT NO@@@@@@@@@@@@@@@@";
cout<<"\n\nCONVICT NO    :\t";
puts(conno);
cout<<"\n\nNAME    :\t";
puts(this->name);
cout<<"\n\nSEX    :\t"<<this->sex;
cout<<"\n\nADDRESS    :\t";
puts(this->address);
cout<<"\n\nAGE    :\t";
puts(this->age);
cout<<"\n\n DESCRIPTION\n";
cout<<"\n1 COLOUR     :\t";
puts(this->des.colour);
cout<<"\n2 FACE     :\t";
puts(this->des.face);
cout<<"\n3 IDENTIFICATION MARK     :\t";
puts(this->des.imark);
cout<<"\n4 HIGHT     :\t";
puts(this->des.hight);
cout<<"\n\n\n\n\t\t\t\t\tpress a key to continue ..." ;
getch();
clrscr();
cout<<"@@@@@@@@@@@@@@@@@@@@ CRIMINAL RECORD @@@@@@@@@@";
cout<<"\n\nCOURT INFORMATION\n\n";
cout<<"\n1. COURT IN WHICH CONVICTED:\t";
puts(this->COURT.cour);
cout<<"\n2.STATE:\t";
puts(this->COURT.state);
cout<<"\n3.CRIME:\t";
puts(this->COURT.crime);
cout<<"\n4.ACT UNDER WHICH CONVICTED:\t";
puts(this->COURT.act);
cout<<"\n\n\n\n\n\n\t\t\t\t\tpress a key to continue";
getch();
   clrscr();
cout<<"@@@@@@@@@@@@@@@@@@@@ CRIMINAL RECORD @@@@@@@@@@";
cout<<"\n\nPOLICE INFORMATION\n\n";
cout<<"\n1.FIR NO:\t";
puts(this->POLICE.fir_no);
cout<<"\n2.DATE OF ARREST:\t"<<this->POLICE.date_arrest.d<<"/"<<
			       this->POLICE.date_arrest.m<<"/"<<
			       this->POLICE.date_arrest.y;
cout<<"\n3.POLICE STATION (fir lodged at):\t";
puts(this->POLICE.station);
cout<<"\n\n\n\n\n\t\t\t\t\t\tpress a key to continue";
getch();
clrscr();
}//end of otput function


/****************************************************************************
**                  function deleting rec of a convict               *****  *
*****************************************************************************/
void criminal::delete_rec(char con_no[])
{
fstream filin("jail.dat",ios::in|ios::ate);
int q=filin.tellg();
int c =q/sizeof(criminal);
fstream temp("temp.dat",ios::out);
filin.seekg(0);
for(int i=0;i<c;i++)
{
filin.read((char*)this,sizeof(criminal));
if(strcmp(con_no,conno)!=0)
temp.write((char*)this,sizeof(criminal));
}filin.close();
temp.close();
filin.open("jail.dat",ios::out);
temp.open("temp.dat",ios::in|ios::ate);
int a =temp.tellg();
int size=a/sizeof(criminal);
temp.seekg(0);
for(int k=0;k<size;k++)
{temp.read((char*)this,sizeof(criminal));
filin.write((char*)this,sizeof(criminal));
}
filin.close();
temp.close();
cout<<"\n\nTASK COMPLETE\nRECORD DELETED";
}


//................     .............................     ....................
int criminal::dcheck(char n[])
{clrscr();
fstream file;
file.open("jail.dat",ios::in|ios::ate|ios::binary);
int x=0,count=0,c;
int q=file.tellg();
c=q/sizeof(criminal);
file.close();
file.open("jail.dat",ios::in|ios::binary);
for(int i=0;i<c;i++)
{file.read((char*)this,sizeof(criminal));
count++;
if(strcmp(n,conno)==0)
{x++;
break;
}}
if(x==0)
{cout<<"\nconvict not found!!....";
return 0;}
else {
return (count);
}
file.close();
}
//................... ..     .........   ...............     ................
void criminal::display()
{clrscr();
char N[10];
int rec, loc ;
cout<<"\n enter convict code of convict for information";
gets(N);                    rec=this->dcheck(N);
fstream file("jail.dat",ios::in|ios::binary);
if(rec!=0)
{loc=(rec-1)*sizeof(criminal);
 file.seekg(loc);
 file.read((char*)this,sizeof(criminal));
 this->output();
 }
 file.close();
 }

 //.............. ............    .........................         .........
 void criminal::remove()
 {clrscr();
 char no[10];int s;
 cout<<"\n enter the convict no of convict whose record u want to delete";
 gets(no);
 s=this->dcheck(no);
 if(s!=0)
 this->delete_rec(no);
 }
 //................... .    ................   ....................   .......
 int criminal::menu()
 {int ch;
 do{clrscr();
 cout<<"\n@@@@@@@@@@@@@@@@@@@@@@ MAIN MENU @@@@@@@@@@@@@@@@@@@" ;
 cout<<"\n press:\n\n";
 cout<<" \n\t\t\t1.TO ADD RECORD " ;
  cout<<" \n\t\t\t2.TO MODIFY RECORD " ;
 cout<<" \n\t\t\t3.TO DISPLAY RECORD " ;
 cout<<" \n\t\t\t4.TO DELETE RECORD " ;
 cout<<" \n\t\t\t5.TO LIST " ;
 cout<<" \n\t\t\t6.TO QUIT\n " ;
 cin>>ch;
 }while((ch!=1)&&(ch!=2)&&(ch!=3)&&(ch!=4)&&(ch!=5)&&(ch!=6));
 return ch;
 }
 //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
 void criminal::modify()
 {clrscr();
 fstream file;
 char npdr[10],ncrime[10],nact[10],nstate[10],ncourt[10],nstat[10],nfir[10];
 char str[10],nprd[10],cno[10];
 int check,loc;  criminal x;       date D;
 cout<<"\n MODIFICATIOIN FUNCTION";
 cout<<"\n enter convict no of convict to modify:";
 gets(str);
 check=this->dcheck(str);
 if(check!=0)
 {
 file.open ("jail.dat",ios::out|ios::ate);
 int d=0;
 while(!d)
 {cout<<"\n ENTER THE MODIFIED CONVICT NO:";
  gets(cno);
  d=x.concheck(cno);
  }
  strcpy(conno,cno);
cout<<"\n ENTER THE MODIFIED CRIME:";
  gets(ncrime);
  strcpy(COURT.crime,ncrime);
cout<<"\n ENTER THE MODIFIED COURT RECORD:"<<"\n ACT:";
  gets(nact);
  strcpy(COURT.act,nact);
cout<<"\n ENTER THE MODIFIED STATE:";
  gets(nstate);
  strcpy(COURT.state,nstate);
cout<<"\n COURT:";
  gets(ncourt);
  strcpy(COURT.cour,ncourt);
clrscr();
cout<<"\n ENTER MODIFIED POLICE RECORD";
cout<<"\n ENTER POLICE STATION:";
  gets(nstat);
  strcpy(POLICE.station,nstat);
cout<<"\n ENTER FIR NO:";
  gets(nfir);
  strcpy(POLICE.fir_no,nfir);
cout<<"\n ENTER THE DATE OF ARREST(DD/MM/YYYY):";
  int c=0;
  while(!c)
  {cout<<"\n\t\t\t\t\tday:";
  cin>>D.d;
   if((D.d>31)||(D.d<1))
   {cout<<"\n\nTHIS DATE DOES NOT EXIST....!!TRY AGAIN";
   c=0;}
    else
    c=1;
    }
     c=0;
  while(!c)
  {cout<<"\n\t\t\t\t\tmonth:";
  cin>>D.m;
   if((D.m>12)||(D.m<1))
   {cout<<"\n\nTHIS MONTH DOES NOT EXIST....!!TRY AGAIN";
   c=0;continue;}
    else
    c=1;
    if((D.d>31)&&(D.m==2)||(D.m==4)||(D.m==6)||(D.m==9)||(D.m==11))
    {cout<<"\n THIS MONTH DOES NOT HAS 31 DAYS\N TRY AGAIN!!.....";
    c=0;}
    else
    c=1;
    }c=0;

    while(!c)
    {
    cout<<"\n\t\t\t\t\tyear(yyyy):";
    cin>>D.y;
    if((D.y<=1930)||(D.y>2017))
    {cout<<"\n INCORRECT INPUT .TRY AGAIN!!!!......";
			   c=0;
			   }else
			   c=1;
			   }
    POLICE.date_arrest.d=D.d;
    POLICE.date_arrest.m=D.m;
    POLICE.date_arrest.y=D.y;
  loc=(check-1)*sizeof(criminal);
  file.seekp(loc);
  file.write((char*)this,sizeof(criminal));
  file.close();
  }}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void criminal::list()
{clrscr();
int j;
fstream file("jail.dat",ios::in|ios::ate|ios::binary);
int q=file.tellg();
int c=q/sizeof(criminal);
file.seekg(0);
cout<<"\t\n\t\n\tconvict list\n\t\t\n\t\n";
cout<<"\n==================================================================\n";
cout<<"SNO\tNAME\t\t\tCONVICT NO\t\t\tCRIME\n";
cout<<"====================================================================\n";
int i=0;
while(file.read((char*)this,sizeof(criminal)))
{i++;  cout<<i<<"  ";
for(j=0;j<strlen(this->name);j++)
cout<<this->name[j];
cout<<"\t\t\t ";
for(j=0;j<strlen(this->conno);j++)
cout<<this->conno[j];
cout<<"\t\t\t ";
for(j=0;j<strlen(this->COURT.crime);j++)
cout<<this->COURT.crime[j];
cout<<"\t\t\t ";
cout<<"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
if((i%3)==0&&(i!=c))
{cout<<"\n press a key to continue.....";
getch();
clrscr();
cout<<"\n=================================================================\n";
cout<<"SNO\tNAME\t\t\tCONVICT NO\t\t\tCRIME\n";
cout<<"====================================================================\n";
}}
file.close();
}
//---------------------------------------------------------------------------
void criminal::empty()
{int i;

strcpy(name," ");
strcpy(conno," ");
strcpy(sex," ");
strcpy(age," ");
strcpy(address," ");
strcpy(COURT.cour," ");
strcpy(COURT.crime," ");
strcpy(COURT.state," ");
strcpy(des.colour," ");
strcpy(des.imark," ");
strcpy(des.face," ");
strcpy(des.hight," ");
strcpy(POLICE.station," ");
strcpy(POLICE.fir_no," ");
strcpy(COURT.act," ");

POLICE.date_arrest.m=0;
POLICE.date_arrest.d=0;
POLICE.date_arrest.y=0;
}
//---------------------------------------------------------------------------
int criminal::concheck(char b[])
{
fstream file("jail.dat",ios::in|ios::out);
char a[10]; int check=0;
int q=file.tellg();
file.seekg(0);int size=q/sizeof(criminal);
for(int i=0;i<size;i++)
{file.read((char*)this,sizeof(criminal));
strcpy(a,conno) ;
if(strcmp(b,a)==0)
{check+=1;
break;
}}
if(check==0)
return 10;
else
{cout<<"\n GIVEN CONVICT CODE EXIST\n";
return 0;}
file.close();
}

/****************************************************************************
****          MAIN FUNCTION                                  ****************
*****************************************************************************/



void main()
{clrscr();
int x;
for(int i=0;i<3;i++)
{clrscr();
cout<<"\n CRIMINAL RECORD \n\n\t\t\t  BY DHARANJAY SINGH\n\n\n\n\n\n\t\t\t\t\t";
cout<<"ENTER PASSWORD..";
char*pass;
cin>>pass;
x=strcmp(pass,"1234");
if(x==0)
break;
else
cout<<"\a\a";
}
if(x==0)
{int choice,ans='y';
criminal l;
while(ans=='y'||ans=='Y')
{
choice=l.menu();
switch(choice)
{
case 1:l.input();
break;
case 2:l.modify();
break;
case 3:l.display();
break;
case 4:l.remove();
break;
case 5:l.list();
break;
case 6:exit(0);
break;     }
cout<<"\n\n\nDO YOU WANT TO CONTINUE(Y/N)";
ans=getch();
if(ans=='y'||ans=='Y')
continue;
}}getch();
}
