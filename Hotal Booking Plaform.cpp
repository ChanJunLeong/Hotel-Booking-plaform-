//library
#include<iostream> 
#include<iomanip>
#include <stdlib.h>
using namespace std; 

class room //a class with name "room"
{
	//variables(private)
	int num; 
	string type[3];  
	bool availability[10]; 
	
	public:
	room() //default constructor to store value
	{
		int i;
		type[0]="Deluxe"; 
		type[1]="Normal";
		type[2]="Presidential";
		for(i=0;i<10;i++) //for loop
		{
			//boolean
			availability[i]=true; 
		}
	};
	void getnum(int rnum) //member function of getting room number from main with no return value
	{
		num=rnum;
	}
	void favailability() //member function of changing the value of availabilty to false
	{
		availability[num-1]=false;
	}	
	void tavailability() //member function of changing the value of availabilty to true
	{
		availability[num-1]=true;
	}
	
	friend void display_availabity(int z, room obj[]); //prototype of friend functon display_availability
};

class customer //a base class with name "customer" 
{	
	//variable(protected)
	protected: 
		int id,day;
		string phonenum,name;
	
	public:
	customer() //default constructor to set value to 0
	{
		id=0;
		day=0;
		phonenum="000-000000";
		name="none";
	}
		
	void booking(room obj[], int rnum, int i) //function of getting details of booking from customer
	{
		cout<<"Enter your ID"<<setw(23)<<": ";
		cin>>id;
		cin.ignore();
		cout<<"Enter your name"<<setw(21)<<": ";
		getline(cin,name);
		cout<<"Enter your phone number"<<setw(13)<<": ";
		cin>>phonenum;
		cout<<"Enter the day you want to stay"<<setw(6)<<": ";
		cin>>day;
		obj[i].getnum(rnum); //caller to call getnum function from class room
		obj[i].favailability(); //caller to call favailability from class room
	}
	
	void checkin() //function of getting id from customer to check in
	{
		//variable
		int id_check;
		
		cout<<"Enter your ID for check-in : ";  //get id from user
		cin >>id_check;
				
		if(id==id_check) //if else statements
		{
			cout<<"\nCheck-in successfully!"<<endl; //situation of check-in successful
		}
		else
		{
			cout<<"\nCheck-in fail. Please enter your ID or room number correctly."<<endl; //situation of check-in fail
		}
	}	
	
	int checkout(room obj[],int rnum, int i) //function of getting id from customer to check out
	{
		//variables
		int id_check,x;
		
		cout<<"Enter your ID for check-out : ";  //get id from user
		cin>>id_check;
		
		if(id==id_check) //if else statements
		{
			cout<<"Check-out successfully!"<<endl; //situation of check-out successfull
			obj[i].getnum(rnum); //caller to call getnum function from class room 
			obj[i].tavailability(); //caller to call favailability from class room
			x=0; 
			return x; //return the value x
		}				
		else
		{
			cout<<"Check-out fail. Please enter your ID or room number correctly."<<endl; //situation of check out fail
			x=1;
			return x; //return the value x
		}
	}
};

class deluxe: public customer //a derived class with name "deluxe" inherited publicly from base class customer
{
	//variables(private)
	float price;
	string type;
	
	public: 
	deluxe() //default constructor to store value
	{
		type="Deluxe";
		price=35.50;
	}
	
	float rprice() //accessor function to return price
	{
		return price;
	}
	string rtype() //accessor function to return type
	{
		return type;
	}
	string rname() //accessor function to return name
	{
		return name;
	}
	string rphonenum() //accessor function to return phone number
	{
		return phonenum;
	}
	int rid() //accessor function to return id
	{
		return id;
	}
	int rday() //accessor function to return day
	{
		return day;
	}
};

class normal: public customer //a derived class with name "normal" inherited publicly from base class customer
{
	//variables(private)
	float price;
	string type;
	
	public:
	normal() //default constructor to store value
	{
		type="Normal";
		price=20.50;
	}
	
	float rprice() //acceesor function to return price
	{
		return price;
	}
	string rtype() //accessor function to return type
	{
		return type;
	}
	string rname() //accessor function to return name
	{
		return name;
	}
	string rphonenum() //accessor function to return phone number
	{
		return phonenum;
	}
	int rid() //accessor function to return id
	{
		return id;
	}
	int rday() //accessor function to return day
	{
		return day;
	}
};

class presidential: public customer //a derived class with name "presidential" inherited publicly from base class customer
{
	//variables(private)
	float price;
	string type;
	
	//varables(public)
	public:
	presidential() //default constructor to store value
	{
		type="Presidential";
		price=55.50;
	}

	float rprice() //acceesor function to return price
	{
		return price;
	}
	string rtype() //accessor function to return type
	{
		return type;
	}
	string rname() //accessor function to return name
	{
		return name;
	}
	string rphonenum() //accessor function to return phone number
	{
		return phonenum;
	}
	int rid() //accessor function to return id
	{
		return id;
	}
	int rday() //accessor function to return day
	{
		return day;
	}
};

class bill //a class name "bill"
{
	//variables(private)
	float price1,totalp;
	int id1,day1,num;
	string phonenum1,name1,type1;
	
	public:
	bill(int rnum, int i, deluxe droom[10], normal nroom[10], presidential proom[10]) //parameterized constructor
	{
		num=rnum;
		if(i==0) //if else statement
		{
			//to get the value that had return in class deluxe
			id1=droom[num].rid();
			day1=droom[num].rday();
			price1=droom[num].rprice();
			phonenum1=droom[num].rphonenum();
			name1=droom[num].rname();
			type1=droom[num].rtype();
		}
		else if(i==1)
		{
			//to get the value that had return in class normal
			id1=nroom[num].rid();
			day1=nroom[num].rday();
			price1=nroom[num].rprice();
			phonenum1=nroom[num].rphonenum();
			name1=nroom[num].rname();
			type1=nroom[num].rtype();
		}
		else if(i==2)
		{
			//to get the value that had return in class presidential
			id1=proom[num].rid();
			day1=proom[num].rday();
			price1=proom[num].rprice();
			phonenum1=proom[num].rphonenum();
			name1=proom[num].rname();
			type1=proom[num].rtype();
		}
	}
	~bill() //destructor
	{
		cout<<"\n\nThanks for choosing FIVE NINJA HOTEL~~~~~~~~\n";
	}
	
	void display() //function to display pay bill after booking order and check out
	{
		totalp=price1*day1;
		cout<<"\n================================"
			<<"\n	    BILL"
			<<"\n================================"
			<<"\n\nName"<<setw(11)<<": "<<name1
			<<"\nID"<<setw(13)<<": "<<id1
			<<"\nPhone Number : "<<phonenum1
			<<"\n\nSelected Room-"
			<<"\nRoom Type"<<setw(6)<<": "<<type1
			<<"\nRoom Number"<<setw(4)<<": "<<num	
			<<"\n\nPrice"<<setw(12)<<": RM"<<fixed<<setprecision(2)<<totalp;
	}
	void forbill() //function to display pay bill when user need to check their pay bill by using their id
	{
		int id_check;
		cout<<"Enter your ID for checking the bill : ";  //entering id
		cin >>id_check;
				
		if(id1==id_check) //if else statement
		{
			totalp=price1*day1; //total price
			cout<<"\n================================"
				<<"\n	    BILL"
				<<"\n================================"
				<<"\n\nName"<<setw(11)<<": "<<name1
				<<"\nID"<<setw(13)<<": "<<id1
				<<"\nPhone Number : "<<phonenum1
				<<"\n\nSelected Room-"
				<<"\nRoom Type"<<setw(6)<<": "<<type1
				<<"\nRoom Number"<<setw(4)<<": "<<num
				<<"\n\nPrice"<<setw(12)<<": RM"<<fixed<<setprecision(2)<<totalp;
		}
		else
		{
			cout<<"\nChecking bill fail! Please enter your ID or room number correctly."<<endl;
		}
	}
};

void display_availabity(int z, room obj[]) //friend function to display availability
{
	//variables
	int i,j,k=0;
	
	cout<<"\nRoom type :"<<obj[z].type[z]<<"\n" 
		<<"(Room available = 1)	(Room unavailable = 0)\n";
	for(i=0;i<2;i++) //for loop (row)
	{
		for(j=0;j<5;j++) //for loop (column)
		{
			cout<<"Room"<<j+k+1<<"	:"<<obj[z].availability[j+k]<<" 	";
		}
		k=5;	
		cout<<"\n";
	}
}

int main() //main function
{
	//object
	customer person; 
	room obj[3];
	deluxe droom[10];
	normal nroom[10];
	presidential proom[10];
	
	//variables
	char type,condition;
	int rnum,i,choose,x;
	
	do //do while loop
	{
		cout<<"===================================\n"
			<<"   Welcome to Five Ninja Hotel\n"
			<<"===================================\n"
		    <<"What can I help you?\n\n"
		    <<"1.Booking\n"
		    <<"2.Checking\n"
		    <<"3.Check in\n"
		    <<"4.Check out\n"
		    <<"5.Bill\n"
		    <<"Choose one of these please~~~       : ";
		cin >>choose;  //choose a number to different situation 
		cout<<"\nEnter the room type you want (Deluxe[D] / Normal[N] / Presidential[P]) : ";
		cin >>type; //choose a room type that user prefer
		
		if(choose==1) //if else statements
		{
			if(type=='D') //if else statements
			{
				i=0;
				display_availabity(i,obj); //caller to call friend function to display availabity
				cout<<"\nEnter the room you want [1~10]"<<setw(6)<<": ";
				cin >>rnum; //store room number into rnum
				droom[rnum].booking(obj,rnum,i); //caller to call booking function from class deluxe
			}
			else if(type=='N')
			{
				i=1;
				display_availabity(i,obj); 
				cout<<"\nEnter the room you want [1~10]"<<setw(6)<<": ";
				cin >>rnum;
				nroom[rnum].booking(obj,rnum,i); //caller to call booking function from class normal
			}
			else if(type=='P')
			{
				i=2;
				display_availabity(i,obj);
				cout<<"\nEnter the room you want [1~10]"<<setw(6)<<": ";
				cin >>rnum;
				proom[rnum].booking(obj,rnum,i); //caller to call booking function from class presidential
			}
			bill *obja; 
			obja= new bill(rnum,i,droom,nroom,proom); //declare a dynamic object by using new operator 
			obja->display(); //caller to call display function from class bill
			delete obja; //delete dynamic object by using delete operator
		}
		else if(choose==2)
		{
			if(type=='D')
			{
				i=0;
			}
			else if(type=='N')
			{
				i=1;
			}
			else if(type=='P')
			{
				i=2;
			}
			display_availabity(i,obj); //caller to call friend function availabity
		}
		else if(choose==3)
		{
			cout<<"Enter the room you want to check in [1~10] : ";
			cin >>rnum;
			if(type=='D')
			{
				droom[rnum].checkin(); //caller to call check in function from class deluxe
			}
			else if(type=='N')
			{
				nroom[rnum].checkin(); //caller to call check in function from class normal
			}
			else if(type=='P')
			{
				proom[rnum].checkin(); //caller to call check in function from class presidential
			}
		}
		else if(choose==4)
		{
			cout<<"Enter the room you want to check out [1~10] : ";
			cin >>rnum;
			if(type=='D')
			{
				i=0;
				x=droom[rnum].checkout(obj,rnum,i); //caller to call check out function from class deluxe and get return value x
			}
			else if(type=='N')
			{
				i=1;
				x=nroom[rnum].checkout(obj,rnum,i); //caller to call check out function from class normal and get return value x
			}
			else if(type=='P')
			{
				i=2;
				x=proom[rnum].checkout(obj,rnum,i); //caller to call check out function from class presidential and get return value x
			}
			if(x==0)
			{
				bill *obja;
				obja= new bill(rnum,i,droom,nroom,proom);
				obja->display();
				delete obja;
			}
		}
		else if(choose==5)
		{
			cout<<"Enter the room you want to check the bill [1~10] : ";
			cin >>rnum;
			bill *obja;
			obja= new bill(rnum,i,droom,nroom,proom); //declare a dynamic object by using new operator 
			obja->forbill(); //caller to call forbill function from class bill
			delete obja; //delete dynamic object by using delete operator
		}
		cout<<"\nDid you want to continue? [Y/N] : "; //choose to continue
		cin>>condition;
		system("cls");	 //clear the page
	}while(condition=='Y'); //will continue if user choose y
}
