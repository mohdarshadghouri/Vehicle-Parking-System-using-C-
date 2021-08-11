#include<iostream>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<windows.h>
using namespace std;
class vehicle
{
	protected:
		struct bike_node
		{
			string r_dr_name;
			string bike_no;
			string r_mobile_no;
			int r_slot;
			string r_parking_type;
			bike_node *link_r;
		}
		*ra;
		//node for bike
		struct car_node
		{
			string c_dr_name;
			string car_no;
			string mobile_no;
			string c_parking_type;
			int c_slot;
			car_node *link_a;
		}
		*pa;
		//node for car
			struct bus_node
		{
			string b_dr_name;
			string bus_no;
			string b_mobile_no;
			int b_slot;
			string b_parking_type;
			bus_node *link_b;
		}
		*ba;
	//node for bus
	public:
		vehicle();
		int login();
		int secondlogin(int);
		void information();
		//functions for bike
			
			int add_bike(string,string,int,string,string);
			void disp_bike();
			int del_bike(int);
			int search_bike(int);
			void r_menu();
		//functions for car
			int add_car(string,string,int,string,string);
			void disp_car();
			int del_car(int);
			int search_car(int);
			void menu();
			
		//functions for bus
		
			int add_bus(string,string,int,string,string);
			void disp_bus();
			int del_bus(int);
			int search_bus(int);
			void b_menu();
			
			};// class of name bike is created
			
vehicle::vehicle() 	//bike constructure
{
	ra=NULL;
	pa=NULL;
	ba=NULL;
}


int vehicle::login()
{
	HANDLE i=GetStdHandle( STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(i, BACKGROUND_INTENSITY);
	int regeneration;
	int scode;
	int newcode;
	int pwd=00005;
	cout<<"\n\n\t ENTER THE PIN : ";
	cout<<"\n\t ----->"
			"<------"<<endl;
	SetConsoleTextAttribute(i, FOREGROUND_INTENSITY| BACKGROUND_INTENSITY);
	cin>>scode;
	SetConsoleTextAttribute(i, BACKGROUND_INTENSITY);
	
	
	
	cout<<" You have entered :";
	SetConsoleTextAttribute(i, FOREGROUND_INTENSITY| BACKGROUND_INTENSITY);
	cout<<scode;
	SetConsoleTextAttribute(i, BACKGROUND_INTENSITY);
	cout<<"\t\t--->Press Enter. . ."<<endl;

	getch();
	if(scode==pwd)
	{
		system("cls");
		system("color 07");
		cout<<"\n\n\t  --- ACCESS GRANTED ---"<<endl;
	
		cout<<"\n...Press any key to continue....\n";
			getch();
		system("cls");
		return 0;		
	}
	else
	{
		
		system("color 81");
	cout<<"Invalid pin!\n";
	cout<<"\n\t\t\t\t   Forgot pin?\n";
	cout<<"\nPress 1 to regenerate the pin\n";
	cin>>regeneration;
	if(regeneration == 1)
		{
	
		cout<<"\nEnter the secure code provided with the application\n";
		SetConsoleTextAttribute(i, FOREGROUND_INTENSITY| BACKGROUND_INTENSITY);
		cin>>newcode;
		if(newcode==12345)
			{system("cls");
			system("color 81");
				cout<<"\n\tENTER A NEW PIN HERE :\t";
				SetConsoleTextAttribute(i, FOREGROUND_INTENSITY| BACKGROUND_INTENSITY);
				cin>>scode;
				system("cls");
				system("color 81");
				
				secondlogin(scode);
				return 0;
	}
	else
	cout<<"Invalid secure code"<<endl;
	return 1;
		}
	else 
	exit(0);
	}
}

int vehicle::secondlogin(int ncode)
{	HANDLE j=GetStdHandle( STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(j, BACKGROUND_INTENSITY);
	int newpwd=ncode;
	cout<<"Please enter pin\n";
	SetConsoleTextAttribute(j, FOREGROUND_INTENSITY| BACKGROUND_INTENSITY);
	cin>>ncode;
	if(ncode==newpwd)
	{system("cls");
	system("color 07");
		cout<<"\n\n\t  ---ACCESS GRANTED --- "<<endl;
		
		cout<<"\n...Press any key to continue...\n";
		getch();
		system("cls");
		system("color 07");
		return 0;	
	}
	else
	{
return 1;
	}
}

void vehicle::information()
{
	system("cls");
	system("color 8B");
	cout<<"\n"<<"######################### WELCOME TO THE DECCAN PARKING LOT ####################"<<endl;
	//cout<<"================================================================================"<<endl;
	cout<<" Parking information is as follows:"<<endl;
	cout<<" Total Number of bikes= 120"<<endl;
	cout<<" Total Number of cars = 80"<<endl;
	cout<<" Total Number of Buses= 50"<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<" TOTAL VEHICLES \t: 250 VEHICLES"<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<" Type of Parking: 1) Normal\t2) Special"<<endl;

	cout<<"\t\t\t. . . NORMAL PARKING . . .\n\n";
	cout<<" Parking fee per Hour = 20 for BIKE\n";
	cout<<" Parking fee per Hour = 30 for CAR \n";
	cout<<" Parking fee per Hour = 50 for BUS \n";
	cout<<"\t\t\t. . . SPECIAL PARKING . . .\n\n";
	cout<<" Parking fee per Day = 450 for BIKE\n";
	cout<<" Parking fee per Day = 700 for CAR \n";
	cout<<" Parking fee per day = 1000 for BUS\n";
	cout<<"________________________________________________________________________________"<<endl;
	cout<<"\t\t\t\t\t\t Press any key to continue...\n";
	cout<<"\t\t\t\t\t\t";
	getch();
	system("cls");
}
		
int vehicle::add_bike(string r_dr_name,string bike_no,int r_slot,string r_mobile_no,string r_parkingtype)	//add bike function
{
	
	bike_node *r_temp, *rt;
	if(ra==NULL)
		{
			ra=new bike_node;
			ra->r_dr_name=r_dr_name;
			ra->bike_no=bike_no;
			ra->r_slot=r_slot;
			ra->r_mobile_no=r_mobile_no;
			ra->r_parking_type=r_parkingtype;	
			ra->link_r=NULL;
		}
		else
			{
			r_temp=ra;
				while(r_temp->link_r!=NULL)
					{
						r_temp=r_temp->link_r;
					}
				rt=new bike_node;
				rt->r_dr_name=r_dr_name;
				rt->bike_no=bike_no;
	    		rt->r_mobile_no=r_mobile_no;
				if(ra->r_slot==r_slot)
					{
						cout<<"Parking is not available!\n";
						cout<<endl<<endl;
    					r_temp=r_temp->link_r;
						return 0;
					}
					else
					{
						rt->r_slot=r_slot;
						rt->r_parking_type=r_parkingtype;
					}	
					
				rt->link_r=NULL;
				r_temp->link_r=rt;
			}
		
}	
		
void vehicle::disp_bike()			//display bike function
	{
		bike_node *r_temp=ra;
		cout<<endl;
			while(r_temp!=NULL)
				{
					cout<<"     =============================================="<<endl;
					cout<<"\n\tName             :\t\t"<<r_temp->r_dr_name<<endl;
					cout<<"\tBike number       :\t\t"<<r_temp->bike_no<<endl;
					cout<<"\tMobile number    :\t\t"<<r_temp->r_mobile_no<<endl;
					cout<<"\tParking slot no  :\t\t"<<r_temp->r_slot<<endl;
					cout<<"\tParking type     :\t\t"<<r_temp->r_parking_type<<endl;
					cout<<"     =============================================="<<endl;	
					cout<<endl;
					cout<<endl;
		
					r_temp=r_temp->link_r;
				
				}
	}
		
int vehicle::del_bike(int r_no)		//delete bike function
		{
		
			bike_node *old_r, *r_temp;
			r_temp=ra;
			
			while(r_temp!=NULL)
			{
			
				 if (r_temp->r_slot==r_no)
				{
					if(r_temp==ra)
					ra=r_temp->link_r;
					else
					old_r->link_r=r_temp->link_r;
					delete r_temp;
					return 0;
				}
				else 
				{
				old_r=r_temp;
				r_temp=r_temp->link_r;
				}
		
		}
		return 1;
}

int vehicle::search_bike(int r_slot)		//search bike function
{
	bike_node *r_temp;
	r_temp=ra;
	float r_hour,r_amount=0.0;
	
	while(r_temp!=NULL)
	{
		
		
		if(r_temp->r_slot==r_slot)
		{
			if(r_slot<81)
			{
				cout<<"Enter the time period : \t";
				cin>>r_hour;
				r_amount=r_amount=20*r_hour;
				cout<<"Press Enter to collect the receipt. . ."<<endl;
				getch();
				system("cls");
				system("color F9");
				cout<<"\n\n\t\t. . . R.E.C.E.I.P.T. . .\n";
				cout<<"     =============================================="<<endl;
				cout<<"     **********************************************\n";
				cout<<"\n\tName             :\t\t"<<r_temp->r_dr_name<<endl;
				cout<<"\tBike number       :\t\t"<<r_temp->bike_no<<endl;
				cout<<"\tTime period      :\t\t"<<r_hour<<endl;
			
				cout<<"\tMobile number    :\t\t"<<r_temp->r_mobile_no<<endl;
				cout<<"\tParking slot no  :\t\t"<<r_temp->r_slot<<endl;
				cout<<"\tParking type     :\t\t"<<r_temp->r_parking_type<<endl;
				cout<<"     **********************************************\n";
				cout<<"\tAmount           :\t\tRs."<<r_amount<<endl;
				cout<<"     **********************************************\n";	
		
				cout<<endl;
				cout<<"\n\t     - Thank you to park here :)\n";
			
				r_temp=r_temp->link_r;
				return 0;	
			}
			else
			{
				cout<<"Enter the number of days: \t";
				cin>>r_hour;
				r_amount=r_amount=500*r_hour;
				cout<<"Press Enter to collect the receipt. . ."<<endl;
				getch();
				system("cls");
				system("color F9");
				cout<<"\n\n\t\t. . . R.E.C.E.I.P.T. . .\n";
				cout<<"     =============================================="<<endl;
				cout<<"     **********************************************\n";
				cout<<"\n\tName             :\t\t"<<r_temp->r_dr_name<<endl;
				cout<<"\tBike number       :\t\t"<<r_temp->bike_no<<endl;
				cout<<"\tNumber of days   :\t\t"<<r_hour<<endl;
			
				cout<<"\tMobile number    :\t\t"<<r_temp->r_mobile_no<<endl;
				cout<<"\tParking slot no  :\t\t"<<r_temp->r_slot<<endl;
				cout<<"\tParking type     :\t\t"<<r_temp->r_parking_type<<endl;
				cout<<"     **********************************************\n";
				cout<<"\tAmount           :\t\tRs."<<r_amount<<endl;
				cout<<"     **********************************************\n";	
		
				cout<<endl;
				cout<<"\n\t     - Thank you to park here :)\n";
			
				r_temp=r_temp->link_r;
				return 0;
			}
					
		}
		else
		{
		r_temp=r_temp->link_r;
		}
	}
return 2;
}
	
void vehicle:: r_menu()		//bike option
	{
		cout<<endl<<endl;
		cout<<"\t1.Add Bike\t\t\t2.Delete Bike\n\n\n\t3.Display Bike record\t\t4.Collect Receipt\n\n\n\t\t\t5.Return to main menu\n\n";
		cout<<"\n Enter your choice:\t";
	}




int vehicle::add_car(string c_dr_name,string car_no,int c_slot,string mobile_no,string c_parkingtype)	//add car function
{
	
	car_node *tempe, *t;
	if(pa==NULL)
		{
			pa=new car_node;
			pa->c_dr_name=c_dr_name;
			pa->car_no=car_no;
			pa->c_slot=c_slot;
			pa->mobile_no=mobile_no;
			pa->c_parking_type=c_parkingtype;	
			pa->link_a=NULL;
		}
		else
			{
			tempe=pa;
				while(tempe->link_a!=NULL)
					{
						tempe=tempe->link_a;
					}
				t=new car_node;
				t->c_dr_name=c_dr_name;
				t->car_no=car_no;
	    		t->mobile_no=mobile_no;
				if(pa->c_slot==c_slot)
					{
						cout<<"Parking is not available!\n";
						cout<<endl<<endl;
    					tempe=tempe->link_a;
						return 0;
					}
					else
					{
						t->c_slot=c_slot;
						t->c_parking_type=c_parkingtype;
					}	
					
				t->link_a=NULL;
				tempe->link_a=t;
			}
		
}	



void vehicle::disp_car()		//display car function
{
		car_node *tempe=pa;
		cout<<endl;
			while(tempe!=NULL)
				{
					cout<<"     =============================================="<<endl;
					cout<<"\n\tName             :\t\t"<<tempe->c_dr_name<<endl;
					cout<<"\tCar number       :\t\t"<<tempe->car_no<<endl;
					cout<<"\tMobile number    :\t\t"<<tempe->mobile_no<<endl;
					cout<<"\tParking slot no  :\t\t"<<tempe->c_slot<<endl;
					cout<<"\tParking type     :\t\t"<<tempe->c_parking_type<<endl;
					cout<<"     =============================================="<<endl;
					cout<<endl;
					cout<<endl;
					tempe=tempe->link_a;
				
				}
				
		
}


int vehicle::del_car(int no)		//delete car function
		{
		
			int return_value=0;
			car_node *old_a, *tempe;
			tempe=pa;
			
			while(tempe!=NULL)
			{
			
				 if (tempe->c_slot==no)
				{
					if(tempe==pa)
					pa=tempe->link_a;
					else
					old_a->link_a=tempe->link_a;
					delete tempe;
					return 0;
				}
				else 
				{
				old_a=tempe;
				tempe=tempe->link_a;
				}
		
			}
		return 1;
}


int vehicle::search_car(int c_slot)		//car receipt function
{
	int value=0;
	car_node *tempe;
	tempe=pa;
	float c_hour,amount=0.0;
	while(tempe!=NULL)
	{
		
		
		if(tempe->c_slot==c_slot)
		{
			if(c_slot<50)
			{
				cout<<"Enter the time period : \t";
				cin>>c_hour;
				amount=amount=30*c_hour;
				cout<<"Press Enter to collect the receipt. . ."<<endl;
				getch();
				system("cls");
				system("color F9");
				cout<<"\n\n\t\t. . . R.E.C.E.I.P.T. . .\n";
				cout<<"     =============================================="<<endl;
				cout<<"     **********************************************\n";
				cout<<"\n\tName             :\t\t"<<tempe->c_dr_name<<endl;
				cout<<"\tCar number       :\t\t"<<tempe->car_no<<endl;
				cout<<"\tTime period      :\t\t"<<c_hour<<endl;
			
				cout<<"\tMobile number    :\t\t"<<tempe->mobile_no<<endl;
				cout<<"\tParking slot no  :\t\t"<<tempe->c_slot<<endl;
				cout<<"\tParking type     :\t\t"<<tempe->c_parking_type<<endl;
				cout<<"     **********************************************\n";
				cout<<"\tAmount           :\t\tRs."<<amount<<endl;
				cout<<"     **********************************************\n";	
		
				cout<<endl;
				cout<<"\n\t     - Thank you to park here :)\n";
			
				tempe=tempe->link_a;
				return 0;	
			}
			else
			{
					cout<<"Enter Number of Days : \t";
					cin>>c_hour;
					amount=amount=750*c_hour;
					cout<<"Press Enter to collect the receipt. . ."<<endl;
					getch();
					system("cls");
					system("color F9");
					cout<<"\n\n\t\t. . . R.E.C.E.I.P.T. . .\n";
					cout<<"     =============================================="<<endl;
					cout<<"     **********************************************\n";
					cout<<"\n\tName             :\t\t"<<tempe->c_dr_name<<endl;
					cout<<"\tCar number       :\t\t"<<tempe->car_no<<endl;
					cout<<"\tTime period      :\t\t"<<c_hour<<endl;
			
					cout<<"\tMobile number    :\t\t"<<tempe->mobile_no<<endl;
					cout<<"\tParking slot no  :\t\t"<<tempe->c_slot<<endl;
					cout<<"\tParking type     :\t\t"<<tempe->c_parking_type<<endl;
					cout<<"     **********************************************\n";
					cout<<"\tAmount           :\t\tRs."<<amount<<endl;
					cout<<"     **********************************************\n";	
		
					cout<<endl;
					cout<<"\n\t     - Thank you to park here :)\n";
			
					tempe=tempe->link_a;
					return 0;	
		
			}
	
		}
		else
		{
			tempe=tempe->link_a;
		 
		}
	}
return 2;
}
	

void vehicle:: menu()		//car menu
	{
		cout<<"Enter your choice:\n";
		cout<<"1.Add Car\t2.Delete Car\t3.Display Car record \t4.Collect Receipt\t5.Return to main menu\n\n";
	}

	
int vehicle::add_bus(string b_dr_name,string bus_no,int b_slot,string b_mobile_no,string b_parkingtype)		//add bus function
{
	
	bus_node *b_temp, *bt;
	if(ba==NULL)
		{
			ba=new bus_node;
			ba->b_dr_name=b_dr_name;
			ba->bus_no=bus_no;
			ba->b_slot=b_slot;
			ba->b_mobile_no=b_mobile_no;
			ba->b_parking_type=b_parkingtype;	
			ba->link_b=NULL;
		}
		else
			{
			b_temp=ba;
				while(b_temp->link_b!=NULL)
					{
						b_temp=b_temp->link_b;
					}
				bt=new bus_node;
				bt->b_dr_name=b_dr_name;
				bt->bus_no=bus_no;
	    		bt->b_mobile_no=b_mobile_no;
				if(ba->b_slot==b_slot)
					{
						cout<<"Parking is not available!\n";
						cout<<endl<<endl;
    					b_temp=b_temp->link_b;
						return 0;
					}
					else
					{
						bt->b_slot=b_slot;
						bt->b_parking_type=b_parkingtype;
					}	
					
				bt->link_b=NULL;
				b_temp->link_b=bt;
			}
		
}		

void vehicle::disp_bus()		//display bus function
	{
		bus_node *b_temp=ba;
		cout<<endl;
			while(b_temp!=NULL)
				{
					cout<<"     =============================================="<<endl;
					cout<<"\n\tName             :\t\t"<<b_temp->b_dr_name<<endl;
					cout<<"\tBus number       :\t\t"<<b_temp->bus_no<<endl;
					cout<<"\tMobile number    :\t\t"<<b_temp->b_mobile_no<<endl;
		
					cout<<"\tParking slot no  :\t\t"<<b_temp->b_slot<<endl;
					cout<<"\tParking type     :\t\t"<<b_temp->b_parking_type<<endl;
					cout<<"     =============================================="<<endl;	
					cout<<endl;
					cout<<endl;
		
					b_temp=b_temp->link_b;
				
				}
	}
		

int vehicle::del_bus(int b_no)		//delete bus function
		{
		
			bus_node *old_b, *b_temp;
			b_temp=ba;
			
			while(b_temp!=NULL)
			{
			
				 if (b_temp->b_slot==b_no)
				{
					if(b_temp==ba)
					ba=b_temp->link_b;
					else
					old_b->link_b=b_temp->link_b;
					delete b_temp;
					return 0;
				}
				else 
				{
				old_b=b_temp;
				b_temp=b_temp->link_b;
				
				}
		
		}
		return 1;
}

		
int vehicle::search_bus(int b_slot)		//bus receipt function
{
	bus_node *b_temp;
	b_temp=ba;
	float b_hour,b_amount=0.0;
	
	while(b_temp!=NULL)
	{
		
		
		if(b_temp->b_slot==b_slot)
		{
			if(b_slot<26)
			{
				cout<<"Enter the time period : \t";
		cin>>b_hour;
		b_amount=b_amount=50*b_hour;
		cout<<"Press Enter to collect the receipt. . ."<<endl;
		getch();
		
		system("cls");
		system("color F9");
		cout<<"\n\n\t\t. . . R.E.C.E.I.P.T. . .\n";
		cout<<"     =============================================="<<endl;
			cout<<"     **********************************************\n";
			cout<<"\n\tName             :\t\t"<<b_temp->b_dr_name<<endl;
			cout<<"\tCar number       :\t\t"<<b_temp->bus_no<<endl;
			cout<<"\tTime period      :\t\t"<<b_hour<<endl;
			
			cout<<"\tMobile number    :\t\t"<<b_temp->b_mobile_no<<endl;
			cout<<"\tParking slot no  :\t\t"<<b_temp->b_slot<<endl;
			cout<<"\tParking type     :\t\t"<<b_temp->b_parking_type<<endl;
			cout<<"     **********************************************\n";
			cout<<"\tAmount           :\t\tRs."<<b_amount<<endl;
			cout<<"     **********************************************\n";	
		
			cout<<endl;
			cout<<"\n\t     - Thank you to park here :)\n";
			
		b_temp=b_temp->link_b;
		return 0;	
			}
			
			else
			{
				cout<<"Enter number of days : \t";
		cin>>b_hour;
		b_amount=b_amount=1300*b_hour;
		cout<<"Press Enter to collect the receipt. . ."<<endl;
		getch();
		
		system("cls");
		system("color F9");
		cout<<"\n\n\t\t. . . R.E.C.E.I.P.T. . .\n";
		cout<<"     =============================================="<<endl;
			cout<<"     **********************************************\n";
			cout<<"\n\tName             :\t\t"<<b_temp->b_dr_name<<endl;
			cout<<"\tCar number       :\t\t"<<b_temp->bus_no<<endl;
			cout<<"\tTime period      :\t\t"<<b_hour<<endl;
			
			cout<<"\tMobile number    :\t\t"<<b_temp->b_mobile_no<<endl;
			cout<<"\tParking slot no  :\t\t"<<b_temp->b_slot<<endl;
		cout<<"\tParking type     :\t\t"<<b_temp->b_parking_type<<endl;
			cout<<"     **********************************************\n";
			cout<<"\tAmount           :\t\tRs."<<b_amount<<endl;
			cout<<"     **********************************************\n";	
		
			cout<<endl;
			cout<<"\n\t     - Thank you to park here :)\n";
			
		b_temp=b_temp->link_b;
		return 0;	
			}
		
		}
		else
		{
		b_temp=b_temp->link_b;
		}
	}
return 2;
}
	

void vehicle:: b_menu()			//bus menu function
	{
		cout<<"Enter your choice:\n";
		cout<<"1.Add Bus\t2.Delete Bus\t3.Display Bus record \t4.Collect Receipt\t5.Return to main menu\n\n";
	}
		




int main()
{int choice;
vehicle obj;	
string r_dr_name,bike_no,r_mobile_no;
int ch_r,slot3,r_slot;
vehicle r_obj;
int rcount=0;
int r_type;
string r_parking1="Normal";
string r_parking2="Special";
system ("cls");
HANDLE h=GetStdHandle( STD_OUTPUT_HANDLE);
				
				
string dr_name,car_no,mobile_no;
int ch_a,slot,c_slot;
vehicle c_obj;
int ccount=0;
int c_type;
string c_parking1="Normal";
string c_parking2="Special";
system ("cls");
			
				
				
string b_dr_name,bus_no,b_mobile_no;
int ch_b,slot2,b_slot;
vehicle b_obj;
int bcount=0;
int b_type;
string b_parking1="Normal";
string b_parking2="Special";
system ("cls");
system("color 81");
if(obj.login()==0)
{
obj.information();
 goto come;
}
else
exit(0);
												
system("color 07");
while(true)
	{
come:
	system("cls");
	
SetConsoleTextAttribute(h, BACKGROUND_RED| BACKGROUND_INTENSITY);
cout<<"\n\n\n";
cout<<" \t\t\t==========================\t\t                 ";
cout<<" \t\t\t||  Enter your choice   ||\t\t                 ";		
cout<<" \t\t\t|| 1. BIKE\t 2. CAR ||\t\t                     "; 
cout<<" \t\t\t|| 3. BUS \t 4. EXIT||\t\t                     ";
cout<<" \t\t\t==========================\t\t                ";

SetConsoleTextAttribute(h, BACKGROUND_INTENSITY);

cout<<"\n\t\t\t :";
cin>>choice;
				
switch(choice)
{
	case 1:
{
jump:	
system("color 07");	
system("cls");
	
	r_obj.r_menu();
	
		cin>>ch_r;
		system("color 07");
		
if(ch_r==1)
	{

		if(rcount<121)
			{
				cout<<"\nChose parking type\n";
				cout<<"1.Normal\t2.Special\n";
				cin>>r_type;
				if(r_type ==1)
				{
					system("cls");
					cout<<"Enter Driver's name(First,Last) :\t";
					cin>>r_dr_name;
					cout<<"Enter bike  number  \t\t:\t";
					cin>>bike_no;
					cout<<"Enter mobile Number \t\t:\t";
					cin>>r_mobile_no;
					cout<<"Enter parking slot from(1-80)  :\t";
					cin>>r_slot;
					if(r_slot>80)
					{	
						SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
						cout<<"Can't park a bike ! "<<endl;
						cout<<"Normal Parking area can include only 80 Bikes."<<endl;
						SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
						cout<<"Press any key to return...\n";
						
						getch();
						system("cls");
						system("color 07");
						goto jump;
					}
					else
					rcount=rcount+1;
					r_obj.add_bike(r_dr_name,bike_no,r_slot,r_mobile_no,r_parking1);
					cout<<endl<<endl;
					cout<<". . . Press any key to continue . . .\n";
					getch();
					system("cls");
					goto jump;
				}
				else if(r_type==2)
				{
					system("cls");
					cout<<"Enter Driver's name(First,Last) :\t";
					cin>>r_dr_name;
					cout<<"Enter bike  number  \t\t:\t";
					cin>>bike_no;
					cout<<"Enter mobile Number \t\t:\t";
					cin>>r_mobile_no;
					cout<<"Enter parking slot from(81-120)  \t\t:\t";
					cin>>r_slot;
					if(r_slot<81||r_slot>120)
					{	
						SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
						cout<<"Can't park a bike ! "<<endl;
						cout<<"Special Parking area can include only 40 Bikes."<<endl;
						SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
						cout<<"Press any key to return...\n";
					
						getch();
						system("cls");
						system("color 07");
							goto jump;
					}
					else
					//cout<<"Enter parking type  \t\t:\t";
					//cin>>r_parking2;
					rcount=rcount+1;
					r_obj.add_bike(r_dr_name,bike_no,r_slot,r_mobile_no,r_parking2);
					cout<<endl<<endl;
					cout<<". . . Press any key to continue . . .\n";
					getch();
					system("cls");
					goto jump;
				}
			
			}
			else
			cout<<"Parking is full\n";
			cout<<"press any key to continue...\n";
			getch();
			system("cls");
			goto jump;
	}

else if(rcount<121&&ch_r==2)
	{
		cout<<"Enter slot number to be deleted:\t";
		cin>>slot3;
		if(r_obj.del_bike(slot3)==0)
		{
		cout<<"\nbike on th slot number '"<<slot3<<"' is deleted\n";
		cout<<endl;
		rcount=rcount-1;
		cout<<". . . Press any key to continue . . .\n";
		getch();
		system("cls");
		goto jump;
		}
		else
		{
		SetConsoleTextAttribute(h,FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout<<"No bike found on slot no. "<<slot3<<endl;
		getch();
		system("cls");
		system("color 07");	
		goto jump;
		}
	}
else if(ch_r==3)
	{
		
		r_obj.disp_bike();
	
		cout<<endl<<endl;
		cout<<"\tTotal Number of bike[s] can be parkes is 120"<<endl;
		cout<<"     =============================================="<<endl;
		cout<<"\tTotal bike parked = "<<rcount<<endl;
		cout<<"\tParking space left = "<<120-rcount<<endl;
		cout<<"     =============================================="<<endl;
		cout<<"\n. . . Press any key to continue . . .\n";

		getch();
		system("cls");
		goto jump;
	}
else if(ch_r==4)
	{
	cout<<"Enter slot number:\t";
	cin>>slot3;
	if(r_obj.search_bike(slot3)==0)
	{
		cout<<"\n. . . Press any key to continue . . .\n";
		getch();
		system("cls");
		system("color 07");
		goto jump;
	}

	else
		SetConsoleTextAttribute(h,FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout<<"\nNo bike found on slot no "<<slot3<<endl;
		getch();
		system("cls");
		system("color 07");
		goto jump;
	}
else if(ch_r==5)
{
	goto come;
}
else
cout<<"Choose correct option\n\n";
			
break;			
		}
		
		
case 2:
	{
system("cls");				
here:
	system("color 07");	


	    c_obj.menu();
		cin>>ch_a;
		system("color 07");
if(ch_a==1)
	{

		if(ccount<80)
			{
				cout<<"choose your parking type\n";
				cout<<"1.normal\t2.special";
				cin>>c_type;
				if(c_type==1)
				{
					
					cout<<"Enter Driver's name(First,Last) :\t";
					cin>>dr_name;
					cout<<"Enter Car  number  \t\t:\t";
					cin>>car_no;
					cout<<"Enter Mobile Number \t\t:\t";
					cin>>mobile_no;
					cout<<"Enter Parking slot from(1-50)  \t\t:\t";
					cin>>c_slot;
					if(c_slot>50)
					{	
						SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
						cout<<"Can't park a Car ! "<<endl;
						cout<<"Normal Parking area can include only 50 Cars."<<endl;
						SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
						cout<<"Press any key to return...\n";
					
						getch();
						system("cls");
						system("color 07");
						goto here;
					
					}
					else
					ccount=ccount+1;
					c_obj.add_car(dr_name,car_no,c_slot,mobile_no,c_parking1);
					cout<<endl<<endl;
					cout<<". . . Press any key to continue . . .\n";
					getch();
					system("cls");
					goto here;
				}
				else if(c_type==2)
				{
					cout<<"Enter Driver's name(First,Last) :\t";
				cin>>dr_name;
				cout<<"Enter Car  number  \t\t:\t";
				cin>>car_no;
				cout<<"Enter Mobile Number \t\t:\t";
				cin>>mobile_no;
				cout<<"Enter Parking slot(from 51-80)  \t\t:\t";
				cin>>c_slot;
				if(c_slot<51||c_slot>80)
				{	
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout<<"Can't park a Car ! "<<endl;
					cout<<"Parking area can include only 30 Cars."<<endl;
					SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
					cout<<"Press any key to return...\n";
					
					getch();
					system("cls");
					system("color 07");
					goto here;
					
				}
				else
				ccount=ccount+1;
				c_obj.add_car(dr_name,car_no,c_slot,mobile_no,c_parking2);
				cout<<endl<<endl;
				cout<<". . . Press any key to continue . . .\n";
				getch();
				system("cls");
				goto here;
				}
				
			}
			else
				cout<<"Parking is full\n";
				cout<<"Press any key to continue...\n";
				getch();
				system("cls");
				goto here;
	}

else if(ccount<81&&ch_a==2)
	{
		cout<<"Enter slot number to be deleted:\t";
		cin>>slot;
		if(c_obj.del_car(slot)==0)
		{
		cout<<"\nCar on th slot number '"<<slot<<"' is deleted\n";
		cout<<endl;
		ccount=ccount-1;
		cout<<". . . Press any key to continue . . .\n";
		getch();
		system("cls");
		goto here;
		}
		else
		
		{
		SetConsoleTextAttribute(h,FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout<<"No car found on slot no. "<<slot<<endl;
		getch();
		system("cls");
		system("color 07");	
		goto here;
		}
	}
else if(ch_a==3)
	{
		
		c_obj.disp_car();
	
		cout<<endl<<endl;
		cout<<"\tTotal Number of car[s] can be parkes is 80"<<endl;
		cout<<"     =============================================="<<endl;
		cout<<"\tTotal Car parked = "<<ccount<<endl;
		cout<<"\tParking space left = "<<80-ccount<<endl;
		cout<<"     =============================================="<<endl;
		cout<<"\n. . . Press any key to continue . . .\n";

		getch();
		system("cls");
		goto here;
	}
else if(ch_a==4)
	{
	cout<<"Enter slot number:\t";
	cin>>slot;
	if(c_obj.search_car(slot)==0)
	{
		
	
		cout<<"\n. . . Press any key to continue . . .\n";
		getch();
		system("cls");
		system("color 07");
		goto here;
	}
	else
		SetConsoleTextAttribute(h,FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout<<"\nNo Car found on slot no "<<slot<<endl;
		getch();
		system("cls");
		system("color 07");
		goto here;
	}
else if(ch_a==5)
{
	goto come;
}
else
cout<<"Choose correct option\n\n";

				
		break;		
			}
			
			
case 3:
{
system("cls");				
there:
		system("color 07");

	    b_obj.b_menu();
		cin>>ch_b;
		system("color 07");
if(ch_b==1)
	{

		if(bcount<50)
			{
			cout<<"Choose parking type:\n";
			cout<<"1.Normal\t2.Special\n";
					cin>>b_type;
					if(b_type==1)
					{
						cout<<"Enter Driver's name(First,Last) :\t";
				cin>>b_dr_name;
				cout<<"Enter bus  number  \t\t:\t";
				cin>>bus_no;
				cout<<"Enter mobile Number \t\t:\t";
				cin>>b_mobile_no;
				cout<<"Enter parking slot from(1-25)  \t\t:\t";
				cin>>b_slot;
				if(b_slot>25)
				{	
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout<<"Can't park a Bus ! "<<endl;
					cout<<" Normal Parking area can include only 25 Buses."<<endl;
					SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
					cout<<"Press any key to return...\n";
					
					getch();
					system("cls");
					system("color 07");
					goto there;
					
				}
				else
				bcount=bcount+1;
				b_obj.add_bus(b_dr_name,bus_no,b_slot,b_mobile_no,b_parking1);
				cout<<endl<<endl;
				cout<<". . . Press any key to continue . . .\n";
				getch();
				system("cls");
			goto there;	
						
					}
					else if(b_type==2)
					{
						cout<<"Enter Driver's name(First,Last) :\t";
				cin>>b_dr_name;
				cout<<"Enter bus  number  \t\t:\t";
				cin>>bus_no;
				cout<<"Enter mobile Number \t\t:\t";
				cin>>b_mobile_no;
				cout<<"Enter parking slot from(26-50)  \t\t:\t";
				cin>>b_slot;
				if(b_slot<26||b_slot>50)
				{	
				
				
				
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					cout<<"Can't park a Bus ! "<<endl;
					cout<<"Special Parking area can include only 25 Buses."<<endl;
					SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);
					cout<<"Press any key to return...\n";
					
					getch();
					system("cls");
					system("color 07");
					goto there;
				
				}
				else
				bcount=bcount+1;
				b_obj.add_bus(b_dr_name,bus_no,b_slot,b_mobile_no,b_parking2);
				cout<<endl<<endl;
				cout<<". . . Press any key to continue . . .\n";
				getch();
				system("cls");
			goto there;	
					}
				
			
			}
			else
				cout<<"Parking is full\n";
				cout<<"Press any key to continue...\n";
				getch();
				system("cls");
				goto there;
	}

else if(bcount<51&&ch_b==2)
	{
		cout<<"Enter slot number to be deleted:\t";
		cin>>slot2;
		if(b_obj.del_bus(slot2)==0)
		{
		cout<<"\nbus on th slot number '"<<slot2<<"' is deleted\n";
		cout<<endl;
		bcount=bcount-1;
		cout<<". . . Press any key to continue . . .\n";
		getch();
		system("cls");
		goto there;
		}
		else
		
		{
		SetConsoleTextAttribute(h,FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout<<"No bus found on slot no. "<<slot2<<endl;
		getch();
		system("cls");
		system("color 07");	
		goto there;
		}
	}
else if(ch_b==3)
	{
		
		b_obj.disp_bus();
	
		cout<<endl<<endl;
		cout<<"\tTotal Number of bus[s] can be parkes is 50"<<endl;
		cout<<"     =============================================="<<endl;
		cout<<"\tTotal bus parked = "<<bcount<<endl;
		cout<<"\tParking space left = "<<50-bcount<<endl;
		cout<<"     =============================================="<<endl;
		cout<<"\n. . . Press any key to continue . . .\n";

		getch();
		system("cls");
		goto there;
	}
else if(ch_b==4)
	{
	cout<<"Enter slot number:\t";
	cin>>slot2;
	if(b_obj.search_bus(slot2)==0)
	{
		cout<<"\n. . . Press any key to continue . . .\n";
		getch();
		system("cls");
		system("color 07");
		goto there;
	}

	else
		SetConsoleTextAttribute(h,FOREGROUND_RED| FOREGROUND_INTENSITY);
		cout<<"\nNo bus found on slot no "<<slot2<<endl;
		getch();
		system("cls");
		system("color 07");
		goto there;
	}
else if(ch_b==5)
{
	goto come;
}
else
cout<<"Choose correct option\n\n";

		break;		
			}
		case 4:
			system("cls");
			cout<<endl<<endl;
			cout<<"\t  . . . PARKING CLOSED . . ."<<endl;
			cout<<"\n\n\t\t\t\t. . . Press any key to exit . . .\n";
			cout<<"--------------------------------------------------------------------------------"<<endl;
			getch();
			
			exit(0);
		
		
		}
				
	    
	}
return 0;
}
