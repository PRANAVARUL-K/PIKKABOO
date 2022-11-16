#include <iostream>
#include <iomanip>
#include <ios>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
//subject of the period to be mentioned
using namespace std;
int roll=0;
string dept="MSCSS";
int y=10,x=9;
int TT[5][7]={
				{21,21,1,1,27,27,27},
				{26,26,23,22,25,25,25},
				{24,21,27,27,22,22,1},
				{22,1,25,25,26,26,26},
				{23,23,28,28,24,24,21}
			};
int code[9]={1,21,22,23,24,25,26,27,28};
char SUB[9][20]={"ENG","MATHS","DSA","FWT","OOPS","FWT lab","DSA lab","OOPS lab","EMP lab"};
char day[5][20]={"MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY"};
struct student{
	string name;
	string roll_no;
	string pass;
	string course;
	string dept;
	float attend[9][6];
	struct student *next;
    struct student *previous;
    student()
    {
    	pass="cit202110";
	}
};
struct admin{
	string aname;
	string apass;
	admin()
	{
		aname="admin123";
		apass="12345";
	}
};
struct admin a1;
struct student* head = NULL;
void title()
{
	cout<<"--------------------------------------------------------------------\n";
	cout<<"-------------------------ATTENDANCE REPORT--------------------------\n";
	cout<<"--------------------------------------------------------------------\n";
}
void insertend(struct student** head)
{
	struct student* stu = new student;
	roll=roll+1;
	stu->roll_no=dept+to_string(roll);
	cout<<"\nENTER THE NAME OF THE STUDENT: ";
	getline(cin,stu->name);
	getline(cin,stu->name);
	cout<<"\nENTER THE COURSE OF THE STUDENT: ";
	getline(cin,stu->course);
	cout<<"\nENTER THE DEPARTMENT OF THE STUDENT: ";
	getline(cin,stu->dept);
	if (*head == NULL) 
	{
        stu->next = stu->previous = stu;
        *head = stu;
    }
    else
    {
    	student* last = (*head)->previous;
    	stu->next = *head;
    	(*head)->previous = stu; 
    	stu->previous = last;
    	last->next = stu;
	}
}
/*void insertbtw(struct student** head)
{
	struct student* stu = new student;
	cout<<"\nENTER THE NAME OF THE STUDENT: ";
	cin>>stu->name;
	cout<<"\nENTER THE ROLL NUMBER OF THE STUDENT: ";
	cin>>stu->roll_no;
	cout<<"\nENTER THE COURSE OF THE STUDENT: ";
	cin>>stu->course;
	cout<<"\nENTER THE DEPARTMENT OF THE STUDENT: ";
	cin>>stu->dept;
	if(stu->roll_no<roll)
	{
		int value2=stu->roll_no-1;
    	struct student* temp = *head;
    	while (temp->roll_no != value2)
        	temp = temp->next;
	    struct student* next = temp->next;
		temp->next = stu;
	    stu->previous = temp;
	    stu->next = next;
	    next->previous = stu;
	    struct student* summa = stu->next;
	    while (summa->next != *head) 
		{
		   	summa->roll_no=summa->roll_no+1;
	    	summa = summa->next;
	    }
	    summa->roll_no=summa->roll_no+1;
	    roll++;
	}
	//inset at the end (error)
	else
	{
		struct student* last = (*head)->previous;
    	stu->next = *head;
    	stu->previous = last;
    	last->next = (*head)->previous = stu;
    	*head = stu;
    	stu->roll_no=++roll;
	}
}*/
void get_stu_detail(struct student* temp)
{
	int x=16;
	cout<< left<< setw(x)<<temp->roll_no;
	cout<< left<< setw(x)<<temp->name;
	cout<< left<< setw(x)<<temp->course;
    cout<< left<< setw(x)<<temp->dept;
    cout<<"\n\n\n";
}
void display(struct student* head)
{
	if(head == NULL)
	{
		cout<<"\nTHE STUDENT LIST IS EMPTY\n";
		return;
	}
    struct student* temp = head;
    cout<<"\nSTUDENT DATA: \n";
	int x=16;
    cout<< left<< setw(x)<< "ROLL"<< left<< setw(x)<< "NAME"<< left<< setw(x)
			<< "COURSE"<< left<< setw(x)<< "DEPARTMENT"<<"\n\n";
    while (temp->next != head) 
	{
		get_stu_detail(temp);
		temp = temp->next;
    }
    get_stu_detail(temp);
}
int DAY()
{
	int tday;
	redoday:
	cout<<"\n\n\n\t\t\tENTER DAY: \n";
	cout<<"\t\t\t\t1)MONDAY \n\n\t\t\t\t2)TUESDAY\n\n\t\t\t\t3)WEDNESDAY\n\n\t\t\t\t4)THURSDAY\n\n\t\t\t\t5)FRIDAY\n\n\t\t\t\t";
	cin>>tday;
	if(tday > 5 || tday < 1)
	{
		cout<<"\nENTER A VALID INPUT\n";
		goto redoday;
	}
	return tday;
}
int getsub(int i,int j)
{
	if(TT[i][j] == code[0])
		return 0;
	else if(TT[i][j] == code[1])
		return 1;
	else if(TT[i][j] == code[2])
		return 2;
	else if(TT[i][j] == code[3])
		return 3;
	else if(TT[i][j] == code[4])
		return 4;
	else if(TT[i][j] == code[5])
		return 5;
	else if(TT[i][j] == code[6])
		return 6;
	else if(TT[i][j] == code[7])
		return 7;
	else
		return 8;
}
void bunk(struct student* s1)
{
	int day,sub;
	float bunk[9][6];
	for(int s=0;s<9;s++)
	{
		for(int m=0;m<6;m++)
		{
			bunk[s][m]=s1->attend[s][m];
		}
	}
	day=DAY();
	int i=day-1;
	for(int j=0;j<7;j++)
	{
		sub=getsub(i,j);
		bunk[sub][0]=bunk[sub][0];
		bunk[sub][1]=bunk[sub][1]+1;
		bunk[sub][2]=bunk[sub][2]+1;
		bunk[sub][3]=(bunk[sub][0]/bunk[sub][2])*100;
		bunk[sub][4]=(bunk[sub][1]/bunk[sub][2])*100;
	}
	cout<<"\n\n\n\n";
    cout<< left<< setw(y)<< "SUBJECT"<< left<< setw(x)<< "PRESENT"<< left<< setw(x)
       	<< "ABSENT"<< left<< setw(x)<< "TOTAL"<< left<< setw(x)<< "P%"<< left<< setw(x)
       	<< "A%"<< endl;
   	for(int s=0;s<9;s++)
   	{
    	cout<< left<< setw(y)<<SUB[s];
    	for(int m =0;m<6;m++)
    	{
	    	cout<< left<< setw(x)<<bunk[s][m];
    	}cout<<"\n\n";
    }
}
void attendance(struct student* s1,int i)
{
	int sub,j;
	char summa;
	for(j=0;j<7;j++)
	{
		sub=getsub(i,j);
		redoj:
		cout<<"\nEnter present(P)/absent(A):("<<j+1<<"th period): ";
		cin>>summa;
		if(summa == 'p' || summa == 'P')
		{
			s1->attend[sub][0]++;
			s1->attend[sub][2]++;
			s1->attend[sub][3]=(s1->attend[sub][0]/s1->attend[sub][2])*100;
			s1->attend[sub][4]=(s1->attend[sub][1]/s1->attend[sub][2])*100;
		}
		else if(summa == 'a' || summa == 'A')
		{
			s1->attend[sub][1]++;
			s1->attend[sub][2]++;	
			s1->attend[sub][3]=(s1->attend[sub][0]/s1->attend[sub][2])*100;
			s1->attend[sub][4]=(s1->attend[sub][1]/s1->attend[sub][2])*100;
		}
		else
		{
			cout<<"Re-Enter the attendence for period "<<j+1<<" present(P)/absent(A)";
			goto redoj;
		}
	}
}
void print_attend(struct student* s1)
{
	cout<<"\n\n\n\n";
	cout<< left<< setw(y)<< "SUBJECT"<< left<< setw(x)<< "PRESENT"<< left<< setw(x)
		<< "ABSENT"<< left<< setw(x)<< "TOTAL"<< left<< setw(x)<< "P%"
		<< left<< setw(x)<< "A%"<< "\n\n";
    	for(int s=0;s<9;s++)
    	{
	    	cout<< left<< setw(y);
    		cout<<SUB[s];
    		for(int m =0;m<6;m++)
    		{
	    		cout<< left<< setw(x)<<s1->attend[s][m];
    		}cout<<"\n\n";
    	}
}
void trav_attend(struct student* head)
{
	if(head == NULL)
	{
		cout<<"\nTHE STUDENT LIST IS EMPTY\n";
		cout<<"\nPRESS ENTER TO CONTINUE";
		getchar();getchar();
		return;
	}
	struct student* temp = head;
	int day=DAY();
	int	i=day-1;
    cout<<"\nSTUDENT DATA: \n";
    while (temp->next != head) 
	{
		cout<<"\nEnter the attendence of student: "<<temp->name<<"\nRoll Number: "<<temp->roll_no;
		attendance(temp,i);
		//print_attend(temp);
		temp=temp->next;
	}
	cout<<"\nEnter the attendence of student: "<<temp->name<<"\nRoll Number: "<<temp->roll_no;
	attendance(temp,i);
	//print_attend(temp);
}
void print_all_attend(struct student* head)
{
	if(head == NULL)
	{
		cout<<"\nTHE STUDENT LIST IS EMPTY\n";
		return;
	}
    struct student* temp = head;
    cout<<"\nSTUDENT DATA: \n\n";
    while (temp->next != head) 
	{
		cout<<"NAME: "<<temp->name<<"\n";
		cout<<"ROLL NO: "<<temp->roll_no<<"\n";
		print_attend(temp);
		temp=temp->next;
	}
	cout<<"NAME: "<<temp->name<<"\n";
	cout<<"ROLL NO: "<<temp->roll_no<<"\n";
	print_attend(temp);
}
student* user_check(struct student* head,string roll,string up)
{
	if(head == NULL)
	{
		cout<<"\nTHE STUDENT LIST IS EMPTY\n";
		return NULL;
	}
    struct student* temp = head;
    cout<<"\nSTUDENT DATA: \n";
    while (temp->next != head) 
	{
		if(roll==temp->roll_no)
		{
			if(up==temp->pass)
				return temp;
		}
    	temp = temp->next;
    }
    if(roll==temp->roll_no)
	{
		if(up==temp->pass)
			return temp;
	}
	else 
		return NULL;
}
void view_profile(struct student* temp)
{
	cout<<"\n\nNAME: "<<temp->name<<"\n";
	cout<<"ROLL NO: "<<temp->roll_no<<"\n";
	cout<<"COURSE: "<<temp->course<<"\n";
	cout<<"DEPARTMENT: "<<temp->dept<<"\n";
}
void less_than_75(struct student* head)
{
	if(head == NULL)
	{
		cout<<"\nTHE STUDENT LIST IS EMPTY\n";
	}
    struct student* temp = head;
    while (temp->next != head) 
	{
		cout<<"NAME: "<<temp->name<<"\n";
		cout<<"ROLL NO: "<<temp->roll_no<<"\n";
		cout<< left<< setw(y)<< "SUBJECT"<< left<< setw(x)<< "PRESENT%"<< left<< setw(x)
			<< "ABSENT%"<<"\n\n";
		int b=0;
		for(int s=0;s<9;s++)
    	{
	    	cout<< left<< setw(y);
	    	if(temp->attend[s][4]>25)
	    	{
	    		cout<<SUB[s];
	    		cout<< left<< setw(x)<<temp->attend[s][3]<<"%"<< left<< setw(x)<<temp->attend[s][4]<<"%";
				cout<<"\n\n";b++;
			}
    	}
    	if(b==0)
    	{
    		cout<<"NIL\n\n";
		}
    	temp = temp->next;
    }
    cout<<"NAME: "<<temp->name<<"\n";
	cout<<"ROLL NO: "<<temp->roll_no<<"\n";
	cout<< left<< setw(y)<< "SUBJECT"<< left<< setw(x)<< "PRESENT%"<< left<< setw(x)
		<< "ABSENT%"<<"\n\n";
	int b=0;
    for(int s=0;s<9;s++)
    {
	    cout<< left<< setw(y);
	    if(temp->attend[s][4]>25)
	    {
	    	cout<<SUB[s];
	    	cout<< left<< setw(x)<<temp->attend[s][3]<<"%"<< left<< setw(x)<<temp->attend[s][4]<<"%";
			cout<<"\n\n";b++;
		}
    }
    if(b==0)
   	{
    	cout<<"NIL";
	}
}
void print_TT()
{
	int x=14;
	int i;
	cout<< left<< setw(x)<< "DAY"<< left<< setw(x)<< "1"<< left<< setw(x)
		<< "2"<< left<< setw(x)<< "3"<< left<< setw(x)<< "4"<< left<< setw(x)
		<< "5"<< left<< setw(x)<< "6"<< left<< setw(x)<< "7"<<"\n\n";
	for(int s=0;s<5;s++)
	{
		cout<< left<< setw(x)<<day[s];
		for(int m=0;m<7;m++)
		{
			i=getsub(s,m);
			cout<< left<< setw(x)<<SUB[i];
		}
		cout<<"\n\n";
	}
}
void specific_attend(struct student* head)
{
	int b=0;
	string r;
	cout<<"\nENTER THE ROLL NUMBER: ";
	cin>>r;
	if(head == NULL)
	{
		cout<<"\nTHE STUDENT LIST IS EMPTY\n";
		return;//(imp)
	}
	struct student* temp = head;
    cout<<"\nSTUDENT DATA: \n";
    while (temp->next != head) 
	{
		if(r==temp->roll_no)
		{
			cout<<"\n\nNAME: "<<temp->name<<"\n";
			cout<<"ROLL NO: "<<temp->roll_no<<"\n";
			print_attend(temp);
			b++;
			return;
		}
    	temp = temp->next;
    }
    if(r==temp->roll_no)
	{
		cout<<"\n\nNAME: "<<temp->name<<"\n";
		cout<<"ROLL NO: "<<temp->roll_no<<"\n";
		print_attend(temp);
		b++;
		return;
	}
	if(b==0)
	{
		cout<<"\nSTUDENT NOT FOUND";
		return;
	}
}
//VALIDATION NOT GIVEN
void update_TT()
{
	int i=0;
	int cod;
	cout<<"\nENTER THE CODES AND NAMES OF ALL THE SUBJECTS IN ORDER: \n";
	while(i<9)
	{
		cout<<"\nENTER CODE OF "<<i+1<<"th SUBJECT: ";cin>>cod;
		cout<<"\nENTER NAME OF "<<i+1<<"th SUBJECT: ";cin>>SUB[i];
		for(int s=0;s<5;s++)
		{
			for(int m=0;m<7;m++)
			{
				if(TT[s][m]==code[i])
				{
					TT[s][m]=cod;
				}
			}
		}
		code[i]=cod;
		i++;
	}
}
void change_pass(struct student* temp)
{
	string current_pass,new_pass,re_pass;
    cout<<"\nSTUDENT DATA: \n";
    redocur:
	cout<<"\nENTER YOUR CURRENT PASSWORD: ";
	cin>>current_pass;
	if(temp->pass==current_pass)
	{
		cout<<"\nENTER YOUR NEW PASSWORD: ";
		cin>>new_pass;
		redore:
		cout<<"\nRE-ENTER NEW PASSWORD: ";
		cin>>re_pass;
		if(re_pass==new_pass)
		{
			temp->pass=new_pass;
			cout<<"\nPASSWORD CHANGED SUCCESSFULLY\n";
			return;
		}
		else
		{
			cout<<"\nTHE NEW PASSWORDS DOESN'T MATCH, ENTER AGAIN\n";
			goto redore;
		}
	}
	else
	{
		cout<<"\nENTER THE CORRECT CURRENT PASSWORD, ENTER AGAIN\n";
		goto redocur;
	}
}
void login(struct admin* a1);
void alogin(struct admin* a1);
void ulogin();
void login(struct admin* a1)
{
	int log;
	do
	{
		system("CLS");
		title();
		cout<<"\n\n\n\t\t\tENTER DESIRED OPTION: \n";
		cout<<"\t\t\t\t1)ADMIN\n\n\t\t\t\t2)USER\n\n\t\t\t\t3)VIEW LIST\n\n\t\t\t\t4)EXIT\n\t\t\t\t";
		cin>>log;
		switch(log)
		{
			case 1:
				system("CLS");
				title();
				alogin(a1);
				break;
			case 2:
				system("CLS");
				title();
				ulogin();
				break;
			case 3:
				system("CLS");
				title();
				display(head);
				cout<<"\nENTER ANY KEY TO ENTER LOGIN PAGE";
				getchar();getchar();
				login(a1);
				break;
			case 4:
				system("CLS");
				cout<<"\nYOU CHOOSE TO EXIT\n";
				exit(1);
		}
	}while(log!=4);
	
}
string password_hiding(string ap)
{
	int i=0;
	while(1)
    {
        char a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            ap=ap+a;i++;
            cout<<"*";
        }
        if(a=='\b' && i>0)
        {
            cout<<"\b \b";
            i--;
            ap=ap.substr(0, ap.size()-1);
        }
        if(a=='\r')
        {
            return ap;
        }
    }
}
void alogin(struct admin* a1)
{
	redoalogin:
	system("CLS");
	title();
	string an,ap;
	cout<<"\n\n\n\t\t\tENTER REQUIRED DETAILS: \n";
	cout<<"\t\t\t\t1)ADMIN NAME:";
	cin>>an;
	cout<<"\n\t\t\t\t2)PASSWORD:";
	ap=password_hiding(ap);
	cout<<"\n\t\t\t\t";
	int option;
	if(an==a1->aname && ap==a1->apass)
	{
		system("CLS");
		title();
		do
		{
			system("CLS");
			title();
			cout<<"\n\n\n\t\t\tENTER DESIRED OPTION: \n";
			cout<<"\t\t\t\t1)VIEW ALL ATTENDANCE\n\n\t\t\t\t2)ADD STUDENT\n\n\t\t\t\t3)VIEW ATTENDANCE OF A SPECIFIC ROLL NUMBER\n\n\t\t\t\t4)STUDENTS WITH LESS THAN 75%\n\n\t\t\t\t5)ENTER ATTENDENCE\n\n\t\t\t\t6)TIMETABLE\n\n\t\t\t\t7)UPDATE TIME TABLE\n\n\t\t\t\t8)STUDENT LIST\n\n\t\t\t\t9)EXIT\n\n\t\t\t\t";
			cin>>option;
			switch(option)
			{
				case 1:
					system("CLS");
					title();
					print_all_attend(head);
					cout<<"\nPRESS ENTER TO CONTINUE";
					getchar();getchar();
					break;
				case 2:
					system("CLS");
					title();
					insertend(&head);
					break;
				case 3:
					system("CLS");
					title();
					specific_attend(head);
					cout<<"\nPRESS ENTER TO CONTINUE";
					getchar();getchar();
					break;
				case 4:
					system("CLS");
					title();
					less_than_75(head);
					cout<<"\nPRESS ENTER TO CONTINUE";
					getchar();getchar();
					break;
				case 5:
					system("CLS");
					title();
					trav_attend(head);
					break;
				case 6:
					system("CLS");
					title();
					print_TT();
					cout<<"\nPRESS ENTER TO CONTINUE";
					getchar();getchar();
					break;
				case 7:
					system("CLS");
					title();
					update_TT();
					break;
				case 8:
					system("CLS");
					title();
					display(head);
					cout<<"\nPRESS ENTER TO CONTINUE";
					getchar();getchar();
					break;
				case 9:
					system("CLS");
					cout<<"\nYOU CHOOSE TO EXIT\n";
					login(a1);
					break;
				default:
					system("CLS");
					title();
					cout<<"\nENTER A VALID INPUT\n";
					break;
			}
		}while(option!=9);
	}
	//struct student* temp = admin_check(head,roll,ap);a
	else
	{
		cout<<"\t\t\t\tLOGIN UNSUCCESSFUL\n";
		cout<<"\nENTER ANY KEY TO ENTER LOGIN PAGE";
		getchar();getchar();
		goto redoalogin;
	}
}
void ulogin()
{
	//give an exit option
	redoulogin:
	system("CLS");
	title();
	string up;
	string roll;
	cout<<"\n\n\n\t\t\tENTER REQUIRED DETAILS:\n";
	cout<<"\t\t\t\t1)ROLL NUMBER:";
	cin>>roll;
	cout<<"\n\t\t\t\t2)PASSWORD:";
	up=password_hiding(up);
	cout<<"\n\t\t\t\t";
	int option;
	struct student* temp = user_check(head,roll,up);
	if(temp)
	{
		do
		{
			system("CLS");
			title();
			cout<<"\n\n\n\t\t\tENTER DESIRED OPTION: \n";
			cout<<"\t\t\t\t1)VIEW PROFILE\n\n\t\t\t\t2)VIEW ATTENDANCE\n\n\t\t\t\t3)PREDICTION\n\n\t\t\t\t4)TIMETABLE\n\n\t\t\t\t5)CHANGE PASSWORD\n\n\t\t\t\t6)EXIT\n\n\t\t\t\t";
			cin>>option;
			switch(option)
			{
				case 1:
					system("CLS");
					title();
					view_profile(temp);
					cout<<"\nPRESS ENTER TO CONTINUE";
					getchar();getchar();
					break;
				case 2:
					system("CLS");
					title();
					print_attend(temp);
					cout<<"\nPRESS ENTER TO CONTINUE";
					getchar();getchar();
					break;
				case 3:
					system("CLS");
					title();
					bunk(temp);
					cout<<"\nPRESS ENTER TO CONTINUE";
					getchar();getchar();
					break;
				case 4:
					system("CLS");
					title();
					print_TT();
					cout<<"\nPRESS ENTER TO CONTINUE";
					getchar();getchar();
					break;
				case 5:
					system("CLS");
					title();
					change_pass(temp);
					break;
				case 6:
					system("CLS");
					cout<<"\nYOU CHOOSE TO EXIT\n";
					login(&a1);
					break;
				default:
					system("CLS");
					title();
					cout<<"\nENTER A VALID INPUT";
					break;
			}
		}while(option!=6);
	}
	else
	{
		cout<<"\t\t\t\tLOGIN UNSUCCESSFUL\n";
		cout<<"\nENTER ANY KEY TO ENTER LOGIN PAGE";
		getchar();getchar();
		goto redoulogin;
	}
}
int main()
{	
	login(&a1);
}