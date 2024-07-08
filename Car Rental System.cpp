#include<iostream>
#include<iomanip>
#include<sstream>
#include<ctime>
#include<conio.h>
#include<string>
#include<cstdlib>
#include<cmath>
#include<fstream>
#include<windows.h>

using namespace std;

			// Sinatures of All Functions 
			
void login();
void dashboard();
void vehicle_management();
void car_type_management();
void add_new_type();
void update_a_type();
void delete_a_type();
void display_all_types();
void car_management();
void add_new_car();
void delete_a_car();
void display_car();
void Billing_management();
void rent_a_car();	
void generate_bill(int car_id,string start_date,string return_date,string selected_car_name,string car_number,string file_color,long long int total_payment,string client_name,long long int cnic_no,long long int phone_no,int days,int car_rent);
void save_bill(int type_id,string start_date,string return_date,string file_number,long long int total_payment,string client_name,long long int cnic_no,long long int phone_no);
void receive_a_car();
void delete_a_bill();
void display_bills();
void display_specific_bills();
void display_by_typeid();
void display_by_cnic_no();
void display_by_car_number();
void display_received_bill();	
void display_unreceived_bill();	
void sale_report();
void change_password();
int check_type_id(int pass_id);
string check_type_name(int pass_id, string pass_name);
string check_car_number(int pass_id, string pass_number);
string check_car_status(string status);
int positive_number_check(int number);
long long int phone_check(long long int phone_no);
long long int cnic_check(long long int cnic_no);
int check_bill_id(int pass_id);
string check_answer(string answer);
void display_slashes();
void display_banner();
void display_plain_line();
void red_color();
void green_color();
void yellow_color();
void blue_color();
void white_color();
void sian_color();
void skin_color();
void start_date_check(string& date);
void return_date_check(string& start_date ,string& return_date );


	// End Signatures


int main()
	{
		login();
		return 0;
	}


void red_color()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
}


void green_color()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
}

	
void blue_color()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
}


void yellow_color()
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
}


void white_color()
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}


void sian_color()
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
}


void skin_color()
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
}


void display_digital_line()
	{
	yellow_color();
	cout<<"    _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   _   "<<endl;
	cout<<" |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_| |_|"<<endl;
	 white_color();	
	}

	
void display_banner()
{
	yellow_color();
	cout<<R"(
                                                           _  _  _    _  _      ___  _       _       _ ___  _  _ _
                                                          |  |_||_|  |_||_ |\ |  |  |_| |   |_  \_/ |_  |  |_ | | |
                                                          |_ | || \  | \|_ | \|  |  | | |_   _|  |   _| |  |_ |   |
      )" <<endl;
    white_color();
}


void display_plain_line()
{
		yellow_color();
		cout<<"________________________________________________________________________________________________________________________________________________________________________"<<endl;
        white_color();
}		


void login()
	{	
		for(int k=2;k>=0;)
		{
			string user_name,file_name,file_password;
			system("cls");
			display_banner();			
			display_digital_line();
			blue_color();
			cout<<"\t\t\t\t\t\t\t\t\t\t   _______"<<endl;
			cout<<"\t\t\t\t\t\t\t\t\t\t  |       |"<<endl;
			cout<<"\t\t\t\t\t\t\t\t\t\t  | LOGIN |"<<endl;
			cout<<"\t\t\t\t\t\t\t\t\t\t  |_______|"<<endl;
			white_color();

                    display_plain_line();
					cout<<"\n\n\n\t\t\t\t\t\t\t User Name \t\t :::::::::: \t";
					cin>>user_name;
			
					cout<<"\n\n\n\t\t\t\t\t\t\t Password \t\t :::::::::: \t";
					//cin>>password;
					char password[32];//to store password.
   					int i = 0;
    				char a;//Temperory char
    				while(1)//infinite loop
    					{
        					a=getch();//stores char typed in a
        					if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
           								 //check if a is numeric or alphabet
        						{
            						password[i]=a;//stores a in pass
            						++i;
            						cout<<"*";
        						}
        					if(a=='\b'&&i>=1)//if user typed backspace
           							 //i should be greater than 1.
        						{
            						cout<<"\b \b";//rub the character behind the cursor.
            						--i;
        						}
       						 if(a=='\r')//if enter is pressed
        						{
            						password[i]='\0';//null means end of string.
            						break;//break the loop
        						}
    					}
					
					
					ifstream outputfile("Login.txt");
					if(outputfile)
						{
							getline(outputfile,file_name);
							outputfile>>file_password;
							outputfile.close();
							if(user_name==file_name	&&	password==file_password)
								{
									 green_color();
									cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tVERIFICATION COMPLETED SUCCESSFULLY"<<endl;
									white_color();
									display_plain_line();
									cin.ignore();
									cin.get();
									dashboard();			// Function Call If Login Successfully
									break;
								}
						
							else
								{
									red_color();
									cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tINVALID USERNAME OR PASSWORD"<<endl;
									if(k==0)
										{
											cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tSORRY! YOU CAN'T LOGIN'"<<endl;
										}
									else
										{
											cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<k<<" ATTEMPTS REMAINING"<<endl;
										}
									white_color();
									display_plain_line();
									cin.ignore();
									cin.get();
									k--;
								}
						}
					else
						{
							red_color();
							cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tFILE DOESNOT FOUNDED.............\t";
							white_color();
							display_plain_line();
							cin.ignore();
							cin.get();
						}
					
			}
	}


void dashboard()
	{
		int choice;
		while(1)
			{
				system("cls");
				display_banner();			
			    display_digital_line();
			    blue_color();
				cout<<"\t   ___________ "<<endl;
			    cout<<"\t  |           |"<<endl;
			    cout<<"\t  | DASHBOARD |"<<endl;
			    cout<<"\t  |___________|"<<endl;
			    white_color();
			    display_plain_line();
			    sian_color();
				cout<<"\n\n";
				sian_color();
				cout<<"\t\t  _____________________     \t\t  _____________________ \t\t  _____________________     \t\t  _____________________ "<<endl;
				cout<<"\t\t |          1          |    \t\t |          2          |\t\t |          3          |    \t\t |          4          |"<<endl;
				cout<<"\t\t |  Vehicle Management |    \t\t |  Billing Management |\t\t |   Change Passward   |    \t\t |       Log Out       |"<<endl;
				cout<<"\t\t |_____________________|    \t\t |_____________________|\t\t |_____________________|    \t\t |_____________________|"<<endl;
				white_color();
				cout<<"\n\n\n\t\t\t\t\t\t Choose [ 1-4 ] \t\t    :::::::::: \t";
				cin>>choice;
				display_plain_line();
				if(choice==1)
					{
						vehicle_management();				// Function Call If Choice is 1
					}
				else if(choice==2)
					{
						Billing_management();				// Function Call If Choice is 2
					}
				else if(choice==3)
					{
						change_password();				// Function Call If Choice is 3
					}	
				else if(choice==4)
					{
						login();
						break;				// Logout If Choice is 4
					}
				else
					{
						red_color();
						cout<<"\n\t\t\t\tYOU ENTERED INVALID CHOICE"<<endl;
						white_color();
			 			cin.ignore();
					}
			}
		
	}	
	

void vehicle_management()
	{
		int choice;
		while(1)
			{
				system("cls");
				display_banner();			
			    display_digital_line();
			    blue_color();
				cout<<"\t   ___________  \t   \t  ____________________"<<endl;
			    cout<<"\t  |           | \t > \t |         *          |"<<endl;
			    cout<<"\t  | DASHBOARD | \t > \t | VEHICLE MANAGEMENT |"<<endl;
			    cout<<"\t  |___________| \t > \t |____________________|"<<endl;
			    white_color();
			    display_plain_line();
				cout<<"\n\n";
				sian_color();
				cout<<"\t\t\t\t  _____________________     \t\t  _____________________ \t\t  _____________________ "<<endl;
				cout<<"\t\t\t\t |          1          |    \t\t |          2          |\t\t |          3          |"<<endl;
				cout<<"\t\t\t\t | Car Type Management |    \t\t |    Cars Management  |\t\t |       Go Back       |"<<endl;
				cout<<"\t\t\t\t |_____________________|    \t\t |_____________________|\t\t |_____________________|"<<endl;
				white_color();
				cout<<"\n\n\n\t\t\t\t\t\t Choose [ 1-3 ] \t\t    :::::::::: \t";
				cin>>choice;
				if(choice==1)
					{
						car_type_management();				// Function Call If Choice is 1
					}
				else if(choice==2)
					{
						car_management();				// Function Call If Choice is 2
					}	
				else if(choice==3)
					{
						break;				// Logout If Choice is 4
					}
				else
					{
						red_color();
						cout<<"\n\t\t\t\tYOU ENTERED INVALID CHOICE"<<endl;
						white_color();
			 			cin.ignore();
					}
			}
	}


void car_type_management()
	{
		int choice;
		while(1)
			{
				system("cls");
				display_banner();			
			    display_digital_line();
			    blue_color();
				cout<<"\t   ___________  \t   \t  ____________________  \t   \t  ______________________ "<<endl;
			    cout<<"\t  |           | \t > \t |                    | \t > \t |          *           |"<<endl;
			    cout<<"\t  | DASHBOARD | \t > \t | VEHICLE MANAGEMENT | \t > \t | CARS TYPE MANAGEMENT |"<<endl;
			    cout<<"\t  |___________| \t > \t |____________________| \t > \t |______________________|"<<endl;
			    white_color();
			    display_plain_line();
			    cout<<"\n\n";
			    sian_color();
				cout<<"\t  _____________________ \t  _____________________ \t  _____________________ \t  _____________________ \t  _____________________ "<<endl;
				cout<<"\t |          1          |\t |          2          |\t |          3          |\t |          4          |\t |          5          |"<<endl;
				cout<<"\t |    Add new type     |\t |    Update a Type    |\t |    Delete a Type    |\t |  Display All Types  |\t |        Go Back      |"<<endl;
				cout<<"\t |_____________________|\t |_____________________|\t |_____________________|\t |_____________________|\t |_____________________|"<<endl;
				white_color();
				cout<<"\n\n\n\t\t\t\t\t\t Choose [ 1-5 ] \t\t    :::::::::: \t";
				cin>>choice;
				if(choice==1)
					{
						add_new_type();				// Function Call If Choice is 1
					}
				else if(choice==2)
					{
						update_a_type();				// Function Call If Choice is 2
					}
				else if(choice==3)
					{
						delete_a_type();			// Function Call If Choice is 3
					}	
				else if(choice==4)
					{
						system("cls");
				        display_banner();			
			            display_digital_line();
			            blue_color();
				        cout<<"\t   ___________  \t   \t  ____________________  \t   \t  _____________________  \t   \t  _____________________ "<<endl;
			            cout<<"\t  |           | \t > \t |                    | \t > \t |                     | \t > \t |          *          |"<<endl;
			            cout<<"\t  | DASHBOARD | \t > \t | VEHICLE MANAGEMENT | \t > \t | CAR TYPE MANAGEMENT | \t > \t |  DISPLAY ALL TYPES  |"<<endl;
			            cout<<"\t  |___________| \t > \t |____________________| \t > \t |_____________________| \t > \t |_____________________|"<<endl;
			            white_color();
			            display_plain_line();
						display_all_types();			// Function Call to Display all Types from File
						green_color();
						cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t PRESS ENTER KEY TO RETURN";
						white_color();
						cin.ignore();
						cin.get();
					}
				else if(choice==5)
					{
						break;			
					}
				else
					{
						red_color();
						cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t YOU ENTERED INVALID CHOICE "<<endl;
						white_color();
					    cin.ignore();
				    	cin.get();
		    	    }
	}
}


void add_new_type()
	{
		int choice,type_id,type_rent;
		string type_name,line,choice_s;
		
				system("cls");
				display_banner();			
			    display_digital_line();
			    blue_color();
				cout<<"\t   ___________  \t   \t  ____________________  \t   \t  _____________________  \t   \t  _____________________ "<<endl;
			    cout<<"\t  |           | \t > \t |                    | \t > \t |                     | \t > \t |          *          |"<<endl;
			    cout<<"\t  | DASHBOARD | \t > \t | VEHICLE MANAGEMENT | \t > \t | CAR TYPE MANAGEMENT | \t > \t |     ADD NEW TYPE    |"<<endl;
			    cout<<"\t  |___________| \t > \t |____________________| \t > \t |_____________________| \t > \t |_____________________|"<<endl;
			    white_color();
			    display_plain_line();
				ifstream outputfile("Car Type.txt");
				if(outputfile)
				{
				while(getline(outputfile,line))
					{
						istringstream data(line);
						data>>type_id;
					}
				outputfile.close();
				cout<<"\n\n\n\t\t\t\t\t\t Car Type ID \t\t    :::::::::: \t"<<++type_id;
				cout<<"\n\n\n\t\t\t\t\t\t Car Type Name \t\t    :::::::::: \t";
				cin.ignore();
				getline(cin,type_name);
				type_name=check_type_name( type_id,type_name );			// Function Call to Check Type name is exist or not
				
				cout<<"\n\n\n\t\t\t\t\t\t Car Rent  \t\t    :::::::::: \t";
				cin>>type_rent;
				type_rent=positive_number_check(type_rent);			// Function Call to Check positive entry
				green_color();
				cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tDO YOU WANT TO ADD [Yes/No] ::";
				cin>>choice_s;
				
				choice_s=check_answer(choice_s);		// Function Call to Check ANSWER
				
				white_color();
				if(choice_s=="YES"	||	choice_s=="Yes"	||	choice_s=="yes")
					{
						fstream output("Car Type.txt", ios::app);
						output<<type_id<<" "<<type_name<<" "<<type_rent<<endl;
						output.close();
						cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t CAR ADDED SUCCESSFULLY";
						cin.ignore();
						cin.get();
					}
			}
			else
				{
					red_color();
					cout<<"\n\t\t\tFILE DOESNOT FOUNDED.............\t";
					white_color();
					cin.ignore();
					cin.get();
					car_type_management();
				}
	}
	

void update_a_type()
	{
		int choice,type_id,type_rent,file_id;
		string type_name,line,choice_s;
		        system("cls");
				display_banner();			
			    display_digital_line();
			    blue_color();
				cout<<"\t   ___________  \t   \t  ____________________  \t   \t  _____________________  \t   \t  _____________________ "<<endl;
			    cout<<"\t  |           | \t > \t |                    | \t > \t |                     | \t > \t |         *           |"<<endl;
			    cout<<"\t  | DASHBOARD | \t > \t | VEHICLE MANAGEMENT | \t > \t | CAR TYPE MANAGEMENT | \t > \t |    UPDATE A TYPE    |"<<endl;
			    cout<<"\t  |___________| \t > \t |____________________| \t > \t |_____________________| \t > \t |_____________________|"<<endl;
			    white_color();
			    display_plain_line();
				
				display_all_types();			// Function Call For displaying All Types record from file
				
				cout<<"\n\n\n\t\t\t\t\t\t Car Type ID \t\t    :::::::::: \t";
				cin>>type_id;
				type_id=check_type_id(type_id);			// Function Call to Check Type ID exist or not
				
				cout<<"\n\n\n\t\t\t\t\t\t New Car Rent \t\t    :::::::::: \t";
				cin>>type_rent;
				type_rent=positive_number_check(type_rent);			// Function Call to Check positive entry
				green_color();
				cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tDO YOU WANT TO UPDATE THIS [Yes/No] ::";
				cin>>choice_s;
				
				choice_s=check_answer(choice_s);		// Function Call to Check ANSWER
				
				white_color();
				if(choice_s=="YES"	||	choice_s=="Yes"	||	choice_s=="yes")
					{
						ifstream outputfile("Car Type.txt");
						ofstream temp("temp.txt");
						while(getline(outputfile,line))
							{
								istringstream data(line);
								data>>file_id>>type_name;
								if(type_id==file_id)
									{
										temp<<type_id<<" "<<type_name<<" "<<type_rent<<endl;
									}
								else
									{
										temp<<line<<endl;
									}
							}
						outputfile.close();
						temp.close();
						remove("Car Type.txt");
						rename("temp.txt","Car Type.txt");
						display_plain_line();
						green_color();
						cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t CAR TYPE UPDATED SUCCESSFULLY :)";
						white_color();
						cin.ignore();
						cin.get();
					}
	}


void delete_a_type()
	{
		int choice,type_id,file_id;
		string line,choice_s;
		
				system("cls");
				display_banner();
				display_digital_line();
				blue_color();
				cout<<"\t   ___________  \t   \t  ____________________  \t   \t  _____________________  \t   \t  _____________________ "<<endl;
			    cout<<"\t  |           | \t > \t |                    | \t > \t |                     | \t > \t |         *           |"<<endl;
			    cout<<"\t  | DASHBOARD | \t > \t | VEHICLE MANAGEMENT | \t > \t | CAR TYPE MANAGEMENT | \t > \t |    DE:ETE A TYPE    |"<<endl;
			    cout<<"\t  |___________| \t > \t |____________________| \t > \t |_____________________| \t > \t |_____________________|"<<endl;
			    white_color();
			    display_plain_line();
				
				display_all_types();			// Function Call For displaying All Types record from file
				
				cout<<"\n\n\n\t\t\t\t\t\t Car Type ID \t\t    :::::::::: \t";
				cin>>type_id;
				type_id=check_type_id(type_id);			// Function Call to Check Type ID exist or not
				green_color();
				cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tDO YOU WANT TO DELETE THIS [Yes/No] ::";
				white_color();
				cin>>choice_s;
				
				choice_s=check_answer(choice_s);		// Function Call to Check ANSWER
				
				if(choice_s=="YES"	||	choice_s=="Yes"	||	choice_s=="yes")
					{
						ifstream outputfile("Car Type.txt");
						ifstream output("Car Details.txt");
						if(!outputfile	|| !output)
							{
								red_color();
								cout<<"\n\t\t\tFILE DOESNOT FOUNDED.............\t";
								white_color();
								cin.ignore();
								cin.get();
							}
						else
							{
								ofstream temp("temp.txt");
								while(getline(outputfile,line))
									{
										istringstream data(line);
										data>>file_id;
										if(type_id!=file_id)
											{
												temp<<line<<endl;
											}
									}
							outputfile.close();
							temp.close();
							remove("Car Type.txt");
							rename("temp.txt","Car Type.txt");
						
							ofstream temp1("temp.txt");
							while(getline(output,line))
									{
										istringstream data(line);
										data>>file_id;
										if(type_id!=file_id)
											{
												temp1<<line<<endl;
											}
									}
							output.close();
							temp1.close();
							remove("Car Details.txt");
							rename("temp.txt","Car Details.txt");
						    display_plain_line();
						    green_color();
							cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t CAR TYPE DELETED SUCCESSFULLY :)";
							white_color();
							cin.ignore();
							cin.get();
							}
						
				}
	}


void display_all_types()
	{
		int type_id,type_rent;
		string type_name,line;
		
		ifstream outputfile("Car Type.txt");
		if(outputfile)
			{
                display_digital_line();				
				cout<<setw(50)<<"TYPE ID"<<setw(35)<<"TYPE NAME"<<setw(35)<<"TYPE RENT\n"<<endl;
				while(getline(outputfile,line))
					{
						istringstream data(line);
						data>>type_id>>type_name>>type_rent;
						cout<<setw(46)<<type_id<<setw(36)<<type_name<<setw(35)<<type_rent<<endl;
					}
				display_digital_line();	
				outputfile.close();
				
			}
		
		else
			{
				red_color();
				cout<<"\n\t\t\tFILE DOESNOT FOUNDED.............\t";
				white_color();
				cin.ignore();
				cin.get();
				car_type_management();
			}
	}
	

void car_management()
	{
		int choice;
		while(1)
			{
				system("cls");
				display_banner();			
			    display_digital_line();
			    blue_color();
				cout<<"\t   ___________  \t   \t  ____________________  \t   \t  ___________________ "<<endl;
			    cout<<"\t  |           | \t > \t |                    | \t > \t |                   |"<<endl;
			    cout<<"\t  | DASHBOARD | \t > \t | VEHICLE MANAGEMENT | \t > \t |  CARS  NANAGEMENT |"<<endl;
			    cout<<"\t  |___________| \t > \t |____________________| \t > \t |___________________|"<<endl;
			    white_color();
			    display_plain_line();
			    cout<<"\n\n";
			    sian_color();
				cout<<"\t  _____________________ \t  _____________________ \t  _____________________ \t  _____________________ "<<endl;
				cout<<"\t |          1          |\t |          2          |\t |          3          |\t |          4          |"<<endl;
				cout<<"\t |     Add New Car     |\t |    Delete a Car     |\t |    Display Cars     |\t |       Go Back       |"<<endl;
				cout<<"\t |_____________________|\t |_____________________|\t |_____________________|\t |_____________________|"<<endl;
				white_color();
				cout<<"\n\n\n\t\t\t\t\t\t Choose [ 1-4 ] \t\t    :::::::::: \t";
				cin>>choice;
				if(choice==1)
					{
						add_new_car();				// Function Call If Choice is 1
					}
				
				else if(choice==2)
					{
						delete_a_car();			// Function Call If Choice is 3
					}	
				else if(choice==3)
					{
						display_car();
					}
				else if(choice==4)
					{
						break;				
					}
				else
					{
						red_color();
						cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t YOU ENTERED INVALID CHOICE "<<endl;
						white_color();
			 			cin.ignore();
					}
			}
	}
	

void add_new_car()
	{
		int type_id;
		string car_number,car_color,car_status,choice_s;
		system("cls");
		display_banner();			
		display_digital_line();
		blue_color();
		cout<<"\t   ___________  \t   \t  ____________________  \t   \t  ___________________  \t   \t  ___________________ "<<endl;
	    cout<<"\t  |           | \t > \t |                    | \t > \t |                   | \t > \t |          *        |"<<endl;
	    cout<<"\t  | DASHBOARD | \t > \t | VEHICLE MANAGEMENT | \t > \t |  CARS  NANAGEMENT | \t > \t |    ADD  NEW CAR   |"<<endl;
	    cout<<"\t  |___________| \t > \t |____________________| \t > \t |___________________| \t > \t |___________________|"<<endl;
	    white_color();
	    display_plain_line();
		display_all_types();			// Function Call to display all car types from file
		
		cout<<"\n\n\n\t\t\t\t\t\t Car Type ID \t\t    :::::::::: \t";
		cin>>type_id;
		type_id=check_type_id(type_id);			// Function Call to Check Type ID exist or not
		
		cout<<"\n\n\n\t\t\t\t\t\t Car Number  \t\t    :::::::::: \t";
		cin>>car_number;
		car_number=check_car_number(type_id,car_number);
		
		cout<<"\n\n\n\t\t\t\t\t\t Car Color  \t\t    :::::::::: \t";
		cin>>car_color;
		cout<<"\n\n\n\t\t\t\t Car Rent Status [Yes/No]  \t\t    :::::::::: \t";
		cin>>car_status;
		car_status=check_car_status(car_status);
		green_color();
		cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tDO YOU WANT TO ADD THIS [Yes/NO]:: ";
		cin>>choice_s;
		
		choice_s=check_answer(choice_s);		// Function Call to Check ANSWER
		
		white_color();
		if(choice_s=="Yes"	||	choice_s=="yes"	||	choice_s=="YES")
			{
				fstream outputfile("Car Details.txt", ios::app);
				outputfile<<type_id<<" "<<car_number<<" "<<car_color<<" "<<car_status<<endl;
				outputfile.close();
				green_color();
				cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t CAR ADDED SUCCESSFULLY :) ";
				white_color();
				cin.ignore();
				cin.get();
			}
		
		
	}
	

void delete_a_car()
	{
		int type_id,msg=0,file_id;
		string car_number,file_number,file_color,file_status,choice_s,line;
		system("cls");
		display_banner();			
		display_digital_line();
		blue_color();
		cout<<"\t   ___________  \t   \t  ____________________  \t   \t  ___________________  \t   \t  ___________________ "<<endl;
	    cout<<"\t  |           | \t > \t |                    | \t > \t |                   | \t > \t |          *        |"<<endl;
	    cout<<"\t  | DASHBOARD | \t > \t | VEHICLE MANAGEMENT | \t > \t |  CARS  NANAGEMENT | \t > \t |    DELETE A CAR   |"<<endl;
	    cout<<"\t  |___________| \t > \t |____________________| \t > \t |___________________| \t > \t |___________________|"<<endl;
	    white_color();
	    display_plain_line();
		display_all_types();			// Function Call to display all car types from file
		
		cout<<"\n\n\n\t\t\t\t\t\t Car Type ID \t\t    :::::::::: \t";
		cin>>type_id;
		type_id=check_type_id(type_id);			// Function Call to Check Type ID exist or not
			
		ifstream outputfile("Car Details.txt");
		if(outputfile)
			{
				display_digital_line();	
				cout<<setw(50)<<"CAR NUMBER"<<setw(35)<<"CAR COLOR"<<setw(35)<<"CAR RENT STATUS\n"<<endl;
				while(getline(outputfile,line))
					{
						istringstream data(line);
						data>>file_id>>file_number>>file_color>>file_status;
						if(type_id==file_id && (file_status=="No"	||	file_status=="NO"	||	file_status=="no"))
						cout<<setw(50)<<file_number<<setw(35)<<file_color<<setw(35)<<file_status<<endl;
					}
				display_digital_line();	
				outputfile.close();
			}
		else
			{
				red_color();
				cout<<"\n\t\t\tFILE DOESNOT FOUNDED.............\t";
				white_color();
				cin.ignore();
				cin.get();
				car_management();
			}
		cout<<"\n\n\n\t\t\t\t\t\t Car Number  \t\t    :::::::::: \t";
		cin>>car_number;
		ifstream out("Car Details.txt");
		while(getline(out,line))
			{
				istringstream data(line);
				data>>file_id>>file_number;
				if(type_id==file_id)
					{
						if(car_number==file_number)
							{
								msg=1;
							}
					}
			}
		out.close();
		if(msg==1)
			{
				green_color();
				cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tDO YOU WANT TO DELETE THIS [Yes/NO]:: ";
				cin>>choice_s;
				
				choice_s=check_answer(choice_s);		// Function Call to Check ANSWER
				
				white_color();
				if(choice_s=="YES"	||	choice_s=="Yes"	||	choice_s=="yes"	)
					{
						msg=0;
						ifstream output("Car Details.txt");
						ofstream temp("temp.txt");
						while(getline(output,line))
							{
								istringstream data(line);
								data>>file_id>>file_number>>file_color>>file_status;
								if(type_id==file_id && car_number==file_number	&& (file_status=="No"	||	file_status=="NO"	||	file_status=="no"))
									{
										msg=1;
									}
								else
									{
										temp<<line<<endl;
									}
							}
					
						output.close();
						temp.close();
						remove("Car Details.txt");
						rename("temp.txt","Car Details.txt");	
						if(msg==1)
							{
								green_color();
								cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t CAR DELETED SUCCESSFULLY :) ";
								white_color();
								cin.ignore();
								cin.get();
							}
						else
							{
						     	red_color();
								cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t CAR CANNOT BE DELETED BECAUSE IT IS ON RENT  :( ";
								white_color();
								cin.ignore();
								cin.get();
							}
					}	
			}
		else
			{
				red_color();
				cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t CAR NUMBER NOT FOUND :(";
				white_color();
				cin.ignore();
				cin.get();
			}
		
	}
	
	
void display_car()
	{

		int type_id,file_id;
		string car_number,car_color,car_status,line;
		system("cls");
		display_banner();			
		display_digital_line();
		blue_color();
		cout<<"\t   ___________  \t   \t  ____________________  \t   \t  ___________________  \t   \t  ___________________ "<<endl;
	    cout<<"\t  |           | \t > \t |                    | \t > \t |                   | \t > \t |          *        |"<<endl;
	    cout<<"\t  | DASHBOARD | \t > \t | VEHICLE MANAGEMENT | \t > \t |  CARS  NANAGEMENT | \t > \t |   DISPLAY A CAR   |"<<endl;
	    cout<<"\t  |___________| \t > \t |____________________| \t > \t |___________________| \t > \t |___________________|"<<endl;
	    white_color();
	    display_plain_line();
		display_all_types();			// Function Call to display all car types from file
		
		cout<<"\n\n\n\t\t\t\t\t\t Car Type ID \t\t    :::::::::: \t";
		cin>>type_id;
		type_id=check_type_id(type_id);			// Function Call to Check Type ID exist or not
		
		ifstream outputfile("Car Details.txt");
		if(outputfile)
			{
				display_digital_line();
				cout<<setw(47)<<"CAR NUMBER"<<setw(35)<<"CAR COLOR"<<setw(35)<<"CAR RENT STATUS\n"<<endl;
				while(getline(outputfile,line))
					{
						istringstream data(line);
						data>>file_id>>car_number>>car_color>>car_status;
						if(type_id==file_id)
								cout<<setw(45)<<car_number<<setw(36)<<car_color<<setw(30)<<car_status<<endl;
					}
				display_digital_line();
				outputfile.close();
				green_color();
				cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t PRESS ENTER KEY TO RETURN ";
				white_color();
				cin.ignore();
				cin.get();
				
			}
		
		else
			{
				red_color();
				cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t FILE DOESNOT FOUND !  ";
				white_color();
				cin.ignore();
				cin.get();
				car_management();
			}
		
	}

		
void Billing_management()
	{
		int choice;
		while(1)
			{
				system("cls");
				display_banner();			
			    display_digital_line();
			    blue_color();
				cout<<"\t   ___________  \t   \t  ____________________"<<endl;
			    cout<<"\t  |           | \t > \t |         *          |"<<endl;
			    cout<<"\t  | DASHBOARD | \t > \t | BILLING MANAGEMENT |"<<endl;
			    cout<<"\t  |___________| \t > \t |____________________|"<<endl;
			    white_color();
			    display_plain_line();
			    cout<<"\n\n";
			    sian_color();
				cout<<"\t  _____________________ \t  _____________________ \t  _____________________ \t  _____________________ \t  _____________________ "<<endl;
				cout<<"\t |          1          |\t |          2          |\t |          3          |\t |          4          |\t |          5          |"<<endl;
				cout<<"\t |      Rent a Car     |\t |    Recieve a Car    |\t |    Delete a Bill    |\t |   Display Bills     |\t |        Go Back      |"<<endl;
				cout<<"\t |_____________________|\t |_____________________|\t |_____________________|\t |_____________________|\t |_____________________|"<<endl;
				white_color();
				cout<<"\n\n\n\t\t\t\t\t\t Choose [ 1-5 ] \t\t    :::::::::: \t";
				cin>>choice;
				if(choice==1)
					{
						rent_a_car();				// Function Call If Choice is 1
					}
				else if(choice==2)
					{
						receive_a_car();				// Function Call If Choice is 2
					}
				else if(choice==3)
					{
						delete_a_bill();				// Function Call If Choice is 3
					}
				else if(choice==4)
					{
						display_bills();				// Function Call If Choice is 3
					}
						
				else if(choice==5)
					{
						break;				// Logout If Choice is 4
					}
				else
					{
						red_color();
						cout<<"\n\t\t\t\tYOU ENTERED INVALID CHOICE"<<endl;
						white_color();
			 			cin.ignore();
					}
			}
	}
	

void rent_a_car()
	{
		int type_id,file_id,selected_car_rent,msg=0;
		long long int phone_no,cnic_no,total_payment;
		string start_date,return_date;
		string client_name,file_color,choice_s,file_status,car_number,selected_car_name,type_name,type_rent,line,file_number,file_color_file_status;
	while(1)
	{
		system("cls");
		display_banner();			
	    display_digital_line();
	    blue_color();
		cout<<"\t   ___________  \t   \t  ____________________  \t   \t  ____________________ "<<endl;
	    cout<<"\t  |           | \t > \t |                    | \t > \t |         *          |"<<endl;
	    cout<<"\t  | DASHBOARD | \t > \t | BILLING MANAGEMENT | \t > \t |    RENT A CAR      |"<<endl;
	    cout<<"\t  |___________| \t > \t |____________________| \t > \t |____________________|"<<endl;
	    white_color();
	    display_plain_line();
		display_all_types();			// Function Call For displaying Car Types
		
		cout<<"\n\n\n\t\t\t\t\t\t Car Type ID \t\t    :::::::::: \t";
		cin>>type_id;
		type_id=check_type_id(type_id);			// Function Call to Check Type ID exist or not
		
		ifstream output("Car Type.txt");
		while(getline(output,line))
			{
				istringstream data(line);
				data>>file_id>>selected_car_name>>selected_car_rent;
				if(type_id==file_id)
					{
						break;
					}
			}
		output.close();
					
		ifstream outputfile("Car Details.txt");
		if(outputfile)
			{
				display_digital_line();
				cout<<setw(50)<<"CAR NUMBER"<<setw(35)<<"CAR COLOR"<<setw(35)<<"CAR RENT STATUS\n"<<endl;
				while(getline(outputfile,line))
					{
						istringstream data(line);
						data>>file_id>>file_number>>file_color>>file_status;
						if(type_id==file_id && (file_status=="No"	||	file_status=="NO"	||	file_status=="no"))
								cout<<setw(47)<<file_number<<setw(36)<<file_color<<setw(33)<<file_status<<endl;
					}
				display_digital_line();
				outputfile.close();
			}
		else
			{
				red_color();
				cout<<"\n\t\t\tFILE DOESNOT FOUNDED.............\t";
				white_color();
				cin.ignore();
				cin.get();
				Billing_management();
			}
		cout<<"\n\n\n\t\t\t\t\t\t Car Number  \t\t    :::::::::: \t";
		cin>>car_number;
		ifstream out("Car Details.txt");
		while(getline(out,line))
			{
				istringstream data(line);
				data>>file_id>>file_number;
				if(type_id==file_id)
					{
						if(car_number==file_number)
							{
								msg=1;
							}
					}
			}
		out.close();
		if(msg==1)
			{
				green_color();
				cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tDO YOU WANT TO RENT THIS CAR [Yes/No] ::";
				white_color();
				cin>>choice_s;
				
				choice_s=check_answer(choice_s);		// Function Call to Check ANSWER
				
				if(choice_s=="YES"	||	choice_s=="Yes"	||	choice_s=="yes"	)
					{
						msg=0;
						ifstream output("Car Details.txt");
						while(getline(output,line))
							{
								istringstream data(line);
								data>>file_id>>file_number>>file_color>>file_status;
								if(type_id==file_id && car_number==file_number	&& (file_status=="No"	||	file_status=="NO"	||	file_status=="no"))
									{
										msg=1;
										break;
									}
							}
					
						output.close();
						if(msg==1)
							{
								green_color();
								cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t CAR SELECTED SUCCESSFULLY :) ";
								white_color();
								cin.ignore();
								cin.get();
								break;
							}
						else
							{
								red_color();
								cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t CAR CAN'T BE SELECTED BECAUSE IT IS ON RENT ";
								white_color();
								cin.ignore();
								cin.get();
								red_color();
								cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t PLEASE CHOOSE A RIGHT CAR :(";
								white_color();
								cin.ignore();
								cin.get();
							}
					}	
				else
					{
						Billing_management();			// Function Call for Back
						break;
					}
			}
		else
			{
				red_color();
				cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t CAR NUMBER NOT FOUND ";
				white_color();
				cin.ignore();
				cin.get();
			}
		}
		
		cout<<"\n\n\n\t\t\t\t\t\t Client Name  \t\t    :::::::::: \t";
		cin>>client_name;
		cout<<"\n\n\n\t\t\t\t  Client CNIC [Numbers only] \t\t    :::::::::: \t";
		cin>>cnic_no;
		cnic_no=cnic_check(cnic_no);			// Function Call for checking cnic_no digits
		
		
		cout<<"\n\n\n\t\t\t\t\t\t   Phone No.\t\t    :::::::::: \t [+92] ";
		cin>>phone_no;
		phone_no=phone_check(phone_no);			// Function Call for checking phone_no digits
		
		cout<<"\n\n\n\t\t\t\t     Start Date [dd-mm-yyyy]\t\t    :::::::::: \t";
		cin>>start_date;
		start_date_check(start_date);			// Function Call to check date
		
		cout<<"\n\n\n\t\t\t\t     Return Date [dd-mm-yyyy]\t\t   :::::::::: \t";
		cin>>return_date;
		return_date_check(start_date,return_date);		// Function Call to check date
			
		//////////////     For getting total Days      ///////////////////
		
		
				char s_d[3] = {start_date[0], start_date[1], '\0'};
			    int f_s_d = atoi(s_d);
			
			    char s_m[3] = {start_date[3], start_date[4], '\0'};
			    int f_s_m = atoi(s_m) - 1;
			
			    char s_y[5] = {start_date[6], start_date[7], start_date[8], start_date[9], '\0'};
			    int f_s_y = atoi(s_y) - 1900;
			
			    // Extract day, month, and year from return_date
			    char r_d[3] = {return_date[0], return_date[1], '\0'};
			    int f_r_d = atoi(r_d);
			
			    char r_m[3] = {return_date[3], return_date[4], '\0'};
			    int f_r_m = atoi(r_m) - 1;
			
			    char r_y[5] = {return_date[6], return_date[7], return_date[8], return_date[9], '\0'};
			    int f_r_y = atoi(r_y) - 1900;
			
			    // Create tm structures for start_date and return_date
			    struct tm a = {0, 0, 0, f_s_d, f_s_m, f_s_y}; 
			    struct tm b = {0, 0, 0, f_r_d, f_r_m, f_r_y}; 
			
			    // Convert tm structures to time_t
			    time_t x = mktime(&a);
			    time_t y = mktime(&b);
			
			    int difference = 0;
			    if (x != (time_t)(-1) && y != (time_t)(-1))
			    {    
			        difference = difftime(y, x) / (60 * 60 * 24);
			        difference++; // Include the start date in the count
			    }
			
				cout<<endl<<difference<<endl;
						 
		//////////////////////      End      ////////////////////////////////
		
		
		total_payment=difference*selected_car_rent;
		
		
					
		
				// for generating bills
		generate_bill(type_id,start_date,return_date,selected_car_name,file_number,file_color,total_payment, client_name, cnic_no,phone_no,difference,selected_car_rent);		// Function Call for generating Bill
		
	}	

void start_date_check(string& date)
				{
				    while (1)
				    {
				        if (date.length() == 10)
				        {
				            char d[3] = {date[0], date[1], '\0'};
				            char m[3] = {date[3], date[4], '\0'};
				            char y[5] = {date[6], date[7], date[8], date[9], '\0'};
				            int f_d = atoi(d);
				            int f_m = atoi(m);
				            int f_y = atoi(y);
				
				            if (date[2] == '-' && date[5] == '-')
				            {
				                if (f_m == 2)
				                {
				                    if ((f_y % 4 == 0 && f_d > 0 && f_d <= 29) || (f_y % 4 != 0 && f_d > 0 && f_d <= 28))
				                    {
				                        break;
				                    }
				                }
				                else if (f_m == 1 || f_m == 3 || f_m == 5 || f_m == 7 || f_m == 8 || f_m == 10 || f_m == 12)
				                {
				                    if (f_d > 0 && f_d <= 31)
				                    {
				                    	break;
				                    }
				                }
				                else if (f_m == 4 || f_m == 6 || f_m == 9 || f_m == 11)
				                {
				                    if (f_d > 0 && f_d <= 30)
				                    {
				                        break;
				                    }
				                }
				            }
				        }
				
				        red_color();
						cout<<"\n\n\n\t\t\t\tEnter Correct Date [dd-mm-yyyy] \t\t      :::::::::: \t";
						white_color();
						cin>>date;
				    }
				}
				
		
void return_date_check(string& start_date, string& return_date)
				{
				    while (1)
				    {
				        if (return_date.length() == 10)
				        {
				            // For Start Date
				            char s_d[3] = {start_date[0], start_date[1], '\0'};
				            char s_m[3] = {start_date[3], start_date[4], '\0'};
				            char s_y[5] = {start_date[6], start_date[7], start_date[8], start_date[9], '\0'};
				            int f_s_d = atoi(s_d);
				            int f_s_m = atoi(s_m);
				            int f_s_y = atoi(s_y);
				
				            // For Return Date
				            char r_d[3] = {return_date[0], return_date[1], '\0'};
				            char r_m[3] = {return_date[3], return_date[4], '\0'};
				            char r_y[5] = {return_date[6], return_date[7], return_date[8], return_date[9], '\0'};
				            int f_r_d = atoi(r_d);
				            int f_r_m = atoi(r_m);
				            int f_r_y = atoi(r_y);
				
				            if ((f_r_y > f_s_y) || (f_r_y == f_s_y && f_r_m > f_s_m) || (f_r_y == f_s_y && f_r_m == f_s_m && f_r_d >= f_s_d))
				            {
				                if (return_date[2] == '-' && return_date[5] == '-')
				                {
				                    if (f_r_m == 2)
				                    {
				                        if ((f_r_y % 4 == 0 && f_r_d > 0 && f_r_d <= 29) || (f_r_y % 4 != 0 && f_r_d > 0 && f_r_d <= 28))
				                        {
				                            break;
				                        }
				                    }
				                    else if (f_r_m == 1 || f_r_m == 3 || f_r_m == 5 || f_r_m == 7 || f_r_m == 8 || f_r_m == 10 || f_r_m == 12)
				                    {
				                        if (f_r_d > 0 && f_r_d <= 31)
				                        {
				                            break;
				                        }
				                    }
				                    else if (f_r_m == 4 || f_r_m == 6 || f_r_m == 9 || f_r_m == 11)
				                    {
				                        if (f_r_d > 0 && f_r_d <= 30)
				                        {
				                            break;
				                        }
				                    }
				                }
				            }
				
				            red_color();
							cout<<"\n\n\n\t\t\t\tEnter Correct Date [dd-mm-yyyy] \t\t      :::::::::: \t";
							white_color();
							cin>>return_date;
				        }
				        else
				        {
				            red_color();
							cout<<"\n\n\n\t\t\t\tEnter Correct Date [dd-mm-yyyy] \t\t      :::::::::: \t";
							white_color();
							cin>>return_date;
				        }
				    }
				}


	
void generate_bill(int type_id,string start_date,string return_date,string selected_car_name,string file_number,string file_color,long long int total_payment,string client_name,long long int cnic_no,long long int phone_no,int days,int car_rent)
	{
		string choice_s;
		system("cls");
		display_plain_line();
		yellow_color();
		cout <<R"(
                                                                      _
                                                                     |_/ | |  |
                                                                     |_\ | |_ |_
          )" <<endl;
        display_plain_line();
        cout<<endl;
		red_color();
		cout<<"\t\t\t\t***********************************************************************************************"<<endl;  
		cout<<"\t\t\t\t* ******************************************************************************************* *"<<endl;  
		cout<<"\t\t\t\t* *                                                                                         * *"<<endl;
		cout<<"\t\t\t\t* *";                                                                                         
		
		green_color();
		cout<<"\t\t Car Name       \t\t    :::::::::: \t"<<selected_car_name;
		red_color();
		cout<<"\t\t\t     * *"<<endl;
		cout<<"\t\t\t\t* *                                                                                         * *"<<endl;
		cout<<"\t\t\t\t* *                                                                                         * *"<<endl;
		cout<<"\t\t\t\t* *";                                                                                         
		
		green_color();
		cout<<"\t\t Car Number       \t\t    :::::::::: \t"<<file_number;
		red_color();
		cout<<"\t\t\t     * *"<<endl;
		red_color();
		cout<<"\t\t\t\t* *                                                                                         * *"<<endl;
		cout<<"\t\t\t\t* *                                                                                         * *"<<endl;
		cout<<"\t\t\t\t* *";                                                                                         
		
		green_color();
		cout<<"\t\t Car Color       \t\t    :::::::::: \t"<<file_color;
		red_color();
		cout<<"\t\t\t     * *"<<endl;
		red_color();
		cout<<"\t\t\t\t* *                                                                                         * *"<<endl;
		cout<<"\t\t\t\t* *                                                                                         * *"<<endl;
		cout<<"\t\t\t\t* *";                                                                                         
		
		green_color();
		cout<<"\t\t Total Days       \t\t    :::::::::: \t"<<days;
		red_color();
		cout<<"\t\t\t     * *"<<endl;
		red_color();
		cout<<"\t\t\t\t* *                                                                                         * *"<<endl;
		cout<<"\t\t\t\t* *                                                                                         * *"<<endl;
		cout<<"\t\t\t\t* *";
		
		green_color();
		cout<<"\t\t Car Rent       \t\t    :::::::::: \t"<<car_rent;
		red_color();
		cout<<"\t\t\t     * *"<<endl;
		red_color();
		cout<<"\t\t\t\t* *                                                                                         * *"<<endl;
		cout<<"\t\t\t\t* *                                                                                         * *"<<endl;
		cout<<"\t\t\t\t* *"; 
		
		green_color();
		cout<<"\t\t Total Payment       \t\t    :::::::::: \t"<<total_payment;
		red_color();
		cout<<"\t\t\t     * *"<<endl;
		red_color();
		cout<<"\t\t\t\t* *                                                                                         * *"<<endl;
		cout<<"\t\t\t\t* *                                                                                         * *"<<endl;		
		cout<<"\t\t\t\t* ******************************************************************************************* *"<<endl;  
        cout<<"\t\t\t\t***********************************************************************************************"<<endl;  
        white_color();
		red_color();
		cout<<"\n\n\t\tAGREEMENT"<<endl;
		white_color();
		green_color();
		cout<<"\n\t\t * If the Car Accident Will Happen By You Then You Must Pay Our Loss."<<endl;
		cout<<"\n\t\t * If Car Returns Late Then Extra Charges will also be Applied"<<endl;
		cout<<"\n\t\t * If You Didn't Return Car within Two Days Of the Deadline.Then, Police Case Will Be Filled Against You"<<endl;
		white_color();
		red_color();		
		cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t YOU AGREED TO THIS AGREEMENT ";
		green_color();
		white_color();
		cin>>choice_s;
		
		choice_s=check_answer(choice_s);		// Function Call to Check ANSWER
		
		if(choice_s=="Yes"	||	choice_s=="yes")
			{
				skin_color();
				cout<<"\n\n\n\t\t\t\t\t\t I Hope That You Will Enjoy Our Service!\n\t\t\t\t\t\t\tThanks For Visiting Us"<<endl;
				white_color();
				save_bill(type_id,start_date,return_date,file_number,total_payment,client_name,cnic_no,phone_no);		// Function Call For saving Bill in File
				cin.ignore();
				cin.get();
			}
		else
			{
				red_color();
				cout<<"\n\n\t\t\tSORRY!You Aren't Able To Get The Car"<<endl;
				white_color();
				cin.ignore();
				cin.get();
			}
	}


void save_bill(int car_id,string start_date,string return_date,string car_number,long long int total_payment,string client_name,long long int cnic_no,long long int phone_no)
	{
		int bill_id=0,type_id;
		string line,file_number,file_color,file_status,bill_status="No";
		
		ifstream outputfile("Billing.txt");
		if(outputfile)
			{
				while(getline(outputfile,line))
					{
						istringstream data(line);
						data>>bill_id;
					}
				outputfile.close();
		
				++bill_id;
				fstream out("Billing.txt", ios::app);
				out<<bill_id<<" "<<car_id<<" "<<car_number<<" "<<client_name<<" "<<cnic_no<<" "<<phone_no<<" "<<start_date<<" "<<return_date<<" "<<total_payment<<" "<<bill_status<<endl;
				out.close();
		
				ifstream output("Car Details.txt");
				ofstream temp("temp.txt");
				while(getline(output,line))
					{
						istringstream data(line);
						data>>type_id>>file_number>>file_color>>file_status;
						if(type_id==car_id	&&	car_number==file_number)
							{
								temp<<type_id<<" "<<file_number<<" "<<file_color<<" "<<"Yes"<<endl;
							}
						else
							{
								temp<<type_id<<" "<<file_number<<" "<<file_color<<" "<<file_status<<endl;
							}
					}
				output.close();
				temp.close();
				remove("Car Details.txt");
				rename("temp.txt","Car Details.txt");
		}
		else
			{
				bill_id=1;
				ofstream outputf("Billing.txt");
				outputf<<bill_id<<" "<<car_id<<" "<<file_number<<" "<<client_name<<" "<<cnic_no<<" "<<phone_no<<" "<<start_date<<" "<<return_date<<" "<<total_payment<<" "<<bill_status<<endl;
				outputf.close();
		
				ifstream outputfi("Car Details.txt");
				ofstream temp1("temp.txt");
				while(getline(outputfi,line))
					{
						istringstream data(line);
						data>>type_id>>file_number>>file_color>>file_status;
						if(type_id==car_id	&&	car_number==file_number)
							{
								temp1<<type_id<<" "<<file_number<<" "<<file_color<<" "<<"Yes"<<endl;
							}
						else
							{
								temp1<<type_id<<" "<<file_number<<" "<<file_color<<" "<<file_status<<endl;
							}
					}
				outputfi.close();
				temp1.close();
				remove("Car Details.txt");
				rename("temp.txt","Car Details.txt");
			}
		
			
	}
	

void receive_a_car()
	{
		int bill_id,user_bill_id,type_id,payment,receive_type_id;
		string line,car_number,client_name,start_date,receive_car_number,return_date,bill_status;
		long long int cnic_no,phone_no;
				system("cls");
		display_banner();			
	    display_digital_line();
		cout<<"\t   ___________  \t   \t  ____________________  \t   \t  ____________________ "<<endl;
	    cout<<"\t  |           | \t > \t |                    | \t > \t |         *          |"<<endl;
	    cout<<"\t  | DASHBOARD | \t > \t | BILLING MANAGEMENT | \t > \t |   RECIEVE A CAR    |"<<endl;
	    cout<<"\t  |___________| \t > \t |____________________| \t > \t |____________________|"<<endl;
	    display_plain_line();
		display_unreceived_bill();
		cout<<"\n\n\n\t\t\t\t\t\t Bill ID \t\t    :::::::::: \t";
		cin>>user_bill_id;
		
		user_bill_id=check_bill_id(user_bill_id);	// Function Call for checking Bill ID contained or not
		
		int msg=0;
		
		ifstream outputfile("Billing.txt");
		ofstream temp("temp.txt");
		while(getline(outputfile,line))
			{
				istringstream data(line);
				data>>bill_id>>type_id>>car_number>>client_name>>cnic_no>>phone_no>>start_date>>return_date>>payment>>bill_status;
				if(user_bill_id==bill_id	&&	(bill_status=="No"	||	bill_status=="no"	||	bill_status=="NO"))
					{
						temp<<bill_id<<" "<<type_id<<" "<<car_number<<" "<<client_name<<" "<<cnic_no<<" "<<phone_no<<" "<<start_date<<" "<<return_date<<" "<<payment<<" yes"<<endl;
						msg=1;
						receive_type_id=type_id;
						receive_car_number=car_number;
					}
				else
					{
						temp<<line<<endl;
					}
			}
		outputfile.close();
		temp.close();
		remove("Billing.txt");
		rename("temp.txt","Billing.txt");
	
		if(msg==1){
	
		int file_type_id;
		string file_car_number,file_car_color,file_car_status;
		
		ifstream output("Car Details.txt");
		ofstream temp2("temp.txt");
		while(getline(output,line))
			{
				istringstream data(line);
				data>>file_type_id>>file_car_number>>file_car_color>>file_car_status;
				if(file_type_id==receive_type_id	&&		receive_car_number==file_car_number)
					{
						temp2<<file_type_id<<" "<<file_car_number<<" "<<file_car_color<<" No"<<endl;
					}
				else
					{
						temp2<<line<<endl;
					}
			}
		output.close();
		temp2.close();
		remove("Car Details.txt");
		rename("temp.txt","Car Details.txt");
		green_color();
		cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t CAR RECEIVED SUCCESSFULLY :) ";
		white_color();
		cin.ignore();
		cin.get();
		}
		else
			{
				green_color();
				cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t BILL ALREADY RECEIVED :) ";
				white_color();
				cin.ignore();
				cin.get();
			}
	}
	

void delete_a_bill()
	{
		int user_bill_id,msg=0,type_id,bill_id;
		string line,car_number,client_name,cnic_no,phone_no,start_date,return_date,payment,bill_status;
		display_unreceived_bill();
		
		cout<<"\n\n\n\t\t\tBill ID \t\t\t>>>>>>>>\t";
		cin>>user_bill_id;
		
		user_bill_id=check_bill_id(user_bill_id);	// Function Call for checking Bill ID contained or not
		
		ifstream outputfile("Billing.txt");
		ofstream temp1("temp.txt");
		while(getline(outputfile,line))
			{
				istringstream data(line);
				data>>bill_id>>type_id>>car_number>>client_name>>cnic_no>>phone_no>>start_date>>return_date>>payment>>bill_status;
				if(user_bill_id==bill_id	&&	(bill_status=="no" || bill_status=="NO" || bill_status=="No" ))
					{
						msg=1;
						data>>type_id>>car_number;				
					}
				else
					{
						temp1<<line<<endl;
					}
			}
		outputfile.close();
		temp1.close();
		remove("Billing.txt");
		rename("temp.txt","Billing.txt");
		if(msg==1)
		{

		int file_type_id;
		string file_car_status,file_car_number,file_car_color;
		
		ifstream output("Car Details.txt");
		ofstream temp2("temp.txt");
		while(getline(output,line))
			{
				istringstream data(line);
				data>>file_type_id>>file_car_number>>file_car_color>>file_car_status;
				if(file_type_id==type_id	&&		car_number==file_car_number)
					{
						temp2<<file_type_id<<" "<<file_car_number<<" "<<file_car_color<<" No"<<endl;
					}
				else
					{
						temp2<<line<<endl;
					}
			}
		output.close();
		temp2.close();
		remove("Car Details.txt");
		rename("temp.txt","Car Details.txt");
		green_color();
		cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t BILL DELETED SUCCESSFULLY :) ";
		white_color();
		cin.ignore();
		cin.get();
	}
	else 
		{
			green_color();
			cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t BILL NOT FOUNDED :) ";
			white_color();
			cin.ignore();
			cin.get();
		}
	}
	
		
void display_bills()
	{
		int choice;
		while(1)
			{
				system("cls");
				display_banner();			
			    display_digital_line();
			    blue_color();
				cout<<"\t   ___________  \t   \t  ____________________  \t   \t  ____________________ "<<endl;
	            cout<<"\t  |           | \t > \t |                    | \t > \t |         *          |"<<endl;
	            cout<<"\t  | DASHBOARD | \t > \t | BILLING MANAGEMENT | \t > \t |    DISPLAY BILLS   |"<<endl;
	            cout<<"\t  |___________| \t > \t |____________________| \t > \t |____________________|"<<endl;
	            white_color();
	            display_plain_line();
			    cout<<"\n\n";
			    sian_color();
				cout<<"\t  _____________________ \t  _____________________ \t  _____________________ \t  _____________________ \t  _____________________ "<<endl;
				cout<<"\t |          1          |\t |          2          |\t |          3          |\t |          4          |\t |          5          |"<<endl;
				cout<<"\t |   Specific Record   |\t |    Received Bill    |\t |  Un-received Bill   |\t |    Sales Report     |\t |        Go Back      |"<<endl;
				cout<<"\t |_____________________|\t |_____________________|\t |_____________________|\t |_____________________|\t |_____________________|"<<endl;
				white_color();
				cout<<"\n\n\n\t\t\t\t\t\t Choose [ 1-5 ] \t\t    :::::::::: \t";
				cin>>choice;
				if(choice==1)
					{
						display_specific_bills();				// Function Call If Choice is 1
					}
				else if(choice==2)
					{
					 	display_received_bill();				// Function Call If Choice is 2
					}
				else if(choice==3)
					{
						system("cls");
						display_banner();			
			            display_digital_line();
			            blue_color();
				        cout<<"\t   ___________  \t   \t  ____________________  \t   \t  ____________________  \t   \t  _______________________ "<<endl;
	                    cout<<"\t  |           | \t > \t |                    | \t > \t |                    | \t > \t |         *             |"<<endl;
	                    cout<<"\t  | DASHBOARD | \t > \t | BILLING MANAGEMENT | \t > \t |    DISPLAY BILLS   | \t > \t | DISPLAY SPECIFICC BILL|"<<endl;
	                    cout<<"\t  |___________| \t > \t |____________________| \t > \t |____________________| \t > \t |_______________________|"<<endl;
	                    white_color();
	                    display_plain_line();
			        	cout<<"\n\n";
						display_unreceived_bill();				// Function Call If Choice is 3
						cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t PRESS ENTER KEY TO CONTINUE ";
					 	white_color();
						cin.ignore();
						cin.get();
					}
				else if(choice==4)
					{
						sale_report();				// Function Call If Choice is 3
					}
						
				else if(choice==5)
					{
						Billing_management();
						break;				// Logout If Choice is 4
					}
				else
					{
						red_color();
						cout<<"\n\t\t\t\tYOU ENTERED INVALID CHOICE"<<endl;
						white_color();
			 			cin.ignore();
					}
			}
	}	


void display_specific_bills()
	{
		int choice;
		while(1)
			{
				system("cls");
				display_banner();			
			    display_digital_line();
			    blue_color();
				cout<<"\t   ___________  \t   \t  ____________________  \t   \t  ____________________  \t   \t  _______________________ "<<endl;
	            cout<<"\t  |           | \t > \t |                    | \t > \t |                    | \t > \t |         *             |"<<endl;
	            cout<<"\t  | DASHBOARD | \t > \t | BILLING MANAGEMENT | \t > \t |    DISPLAY BILLS   | \t > \t | DISPLAY SPECIFICC BILL|"<<endl;
	            cout<<"\t  |___________| \t > \t |____________________| \t > \t |____________________| \t > \t |_______________________|"<<endl;
	            white_color();
	            display_plain_line();
				cout<<"\n\n";
				sian_color();
				cout<<"\t  _____________________ \t  _____________________ \t  _____________________ \t  _____________________ "<<endl;
				cout<<"\t |          1          |\t |          2          |\t |          3          |\t |          4          |"<<endl;
				cout<<"\t |     By Type ID      |\t |    By CNIC Number   |\t |    By Car Number    |\t |       Go Back       |"<<endl;
				cout<<"\t |_____________________|\t |_____________________|\t |_____________________|\t |_____________________|"<<endl;
				white_color();
				cout<<"\n\n\n\t\t\t\t\t\t Choose [ 1-4 ] \t\t    :::::::::: \t";
				cin>>choice;
				if(choice==1)
					{
						display_by_typeid();				// Function Call If Choice is 1
					}
				else if(choice==2)
					{
					 	display_by_cnic_no();				// Function Call If Choice is 2
					}
				else if(choice==3)
					{
						display_by_car_number();				// Function Call If Choice is 3
					}	
				else if(choice==4)
					{
						break;				// Logout If Choice is 4
					}
				else
					{
						red_color();
						cout<<"\n\t\t\t\tYOU ENTERED INVALID CHOICE"<<endl;
						white_color();
			 			cin.ignore();
					}
			}
	}
	

void display_by_typeid()
	{
		int user_type_id,file_bill_id,file_type_id;
		long long int file_payment,file_cnic_no,file_phone_no;
		string line,file_car_number,file_client_name,file_start_date,file_return_date,file_bill_status;
		cout<<"\n\n\n\t\t\t\t\t\t\t Type ID \t\t    :::::::::: \t";
		cin>>user_type_id;
		display_plain_line();
		cout<<"Bill-ID"<<setw(12)<<"Type-ID"<<setw(15)<<"Car-Number"<<setw(18)<<"Client-Name"<<setw(19)<<"CNIC-No"<<setw(20)<<"Phone-No"<<setw(23)<<"Start-Date"<<setw(15)<<"Return-Date"<<setw(13)<<"Payment"<<setw(15)<<"Bill-Status\n"<<endl;
	
		ifstream outputfile("Billing.txt");
	if(outputfile){
		while(getline(outputfile,line))
			{
				istringstream data(line);
				data>>file_bill_id>>file_type_id>>file_car_number>>file_client_name>>file_cnic_no>>file_phone_no>>file_start_date>>file_return_date>>file_payment>>file_bill_status;
				if(user_type_id==file_type_id)
					{
						cout<<setw(2.5)<<file_bill_id<<setw(12)<<file_type_id<<setw(17)<<file_car_number<<setw(18)<<file_client_name<<setw(25)<<file_cnic_no<<setw(19)<<file_phone_no<<setw(20)<<file_start_date<<setw(15)<<file_return_date<<setw(13)<<file_payment<<setw(11)<<file_bill_status<<endl;
					}
			}
		outputfile.close();
		green_color();
		cout<<"\n\t\t\tPRESS ANY KEY TO RETURN.............\t";
		white_color();
		cin.ignore();
		cin.get();
		}
		else
			{
				red_color();
				cout<<"\n\t\t\tFILE DOESNOT FOUNDED.............\t";
				white_color();
				cin.ignore();
				cin.get();
				Billing_management();
			}
	}
		

void display_by_cnic_no()
	{
		int file_bill_id,file_type_id;
		long long int user_cnic_no,file_payment,file_cnic_no,file_phone_no;
		string line,file_car_number,file_client_name,file_start_date,file_return_date,file_bill_status;
		cout<<"\n\n\n\t\t\t\t\t\t\t CNIC No \t\t    :::::::::: \t";
		cin>>user_cnic_no;
		
		user_cnic_no=cnic_check(user_cnic_no);
		
		display_plain_line();
		cout<<"Bill-ID"<<setw(10)<<"Type-ID"<<setw(15)<<"Car-Number"<<setw(18)<<"Client-Name"<<setw(23)<<"CNIC-No"<<setw(20)<<"Phone-No"<<setw(20)<<"Start-Date"<<setw(15)<<"Return-Date"<<setw(15)<<"Payment"<<setw(14)<<"Bill-Status\n"<<endl;
	
		ifstream outputfile("Billing.txt");
	if(outputfile){
		while(getline(outputfile,line))
			{
				istringstream data(line);
				data>>file_bill_id>>file_type_id>>file_car_number>>file_client_name>>file_cnic_no>>file_phone_no>>file_start_date>>file_return_date>>file_payment>>file_bill_status;
				if(user_cnic_no==file_cnic_no)
					{
						cout<<setw(2.5)<<file_bill_id<<setw(12)<<file_type_id<<setw(17)<<file_car_number<<setw(18)<<file_client_name<<setw(25)<<file_cnic_no<<setw(19)<<file_phone_no<<setw(20)<<file_start_date<<setw(15)<<file_return_date<<setw(15)<<file_payment<<setw(11)<<file_bill_status<<endl;
					}
			}
		outputfile.close();
		green_color();
		cout<<"\n\t\t\tPRESS ANY KEY TO RETURN.............\t";
		white_color();
		cin.ignore();
		cin.get();
		}
		else
			{
				red_color();
				cout<<"\n\t\t\tFILE DOESNOT FOUNDED.............\t";
				white_color();
				cin.ignore();
				cin.get();
				Billing_management();
			}
	}
	

void display_by_car_number()
	{
		int file_bill_id,file_type_id;
		long long int file_payment,file_cnic_no,file_phone_no;
		string line,user_car_number,file_car_number,file_client_name,file_start_date,file_return_date,file_bill_status;
		cout<<"\n\n\n\t\t\t\t\t\t\t Car Number \t\t    :::::::::: \t";
		cin>>user_car_number;
		display_plain_line();
		cout<<"Bill-ID"<<setw(10)<<"Type-ID"<<setw(15)<<"Car-Number"<<setw(18)<<"Client-Name"<<setw(23)<<"CNIC-No"<<setw(20)<<"Phone-No"<<setw(20)<<"Start-Date"<<setw(15)<<"Return-Date"<<setw(15)<<"Payment"<<setw(14)<<"Bill-Status\n"<<endl;
	
		ifstream outputfile("Billing.txt");
	if(outputfile){
		while(getline(outputfile,line))
			{
				istringstream data(line);
				data>>file_bill_id>>file_type_id>>file_car_number>>file_client_name>>file_cnic_no>>file_phone_no>>file_start_date>>file_return_date>>file_payment>>file_bill_status;
				if(user_car_number==file_car_number)
					{
						cout<<setw(2.5)<<file_bill_id<<setw(12)<<file_type_id<<setw(17)<<file_car_number<<setw(18)<<file_client_name<<setw(25)<<file_cnic_no<<setw(19)<<file_phone_no<<setw(20)<<file_start_date<<setw(15)<<file_return_date<<setw(15)<<file_payment<<setw(11)<<file_bill_status<<endl;
					}
			}
		outputfile.close();
		green_color();
		cout<<"\n\t\t\tPRESS ANY KEY TO RETURN.............\t";
		white_color();
		cin.ignore();
		cin.get();
		}
		else
			{
				red_color();
				cout<<"\n\t\t\tFILE DOESNOT FOUNDED.............\t";
				white_color();
				cin.ignore();
				cin.get();
				Billing_management();
			}
	}
	
					
void display_received_bill()	
	{
		int bill_id,type_id,payment;
		string line,car_number,client_name,start_date,return_date,bill_status;
		long long int cnic_no,phone_no;
		system("cls");
					display_banner();			
			    display_digital_line();
			    blue_color();
				cout<<"\t   ___________  \t   \t  ____________________  \t   \t  ____________________  \t   \t  ________________________ "<<endl;
	            cout<<"\t  |           | \t > \t |                    | \t > \t |                    | \t > \t |           *            |"<<endl;
	            cout<<"\t  | DASHBOARD | \t > \t | BILLING MANAGEMENT | \t > \t |    DISPLAY BILLS   | \t > \t | DISPLAY RECIEIVED BILL |"<<endl;
	            cout<<"\t  |___________| \t > \t |____________________| \t > \t |____________________| \t > \t |________________________|"<<endl;
	            white_color();
	            display_plain_line();
				cout<<"\n\n";
		cout<<"Bill-ID"<<setw(10)<<"Type-ID"<<setw(15)<<"Car-Number"<<setw(18)<<"Client-Name"<<setw(23)<<"CNIC-No"<<setw(20)<<"Phone-No"<<setw(20)<<"Start-Date"<<setw(15)<<"Return-Date"<<setw(15)<<"Payment"<<setw(14)<<"Bill-Status\n"<<endl;
		ifstream outputfile("Billing.txt");
		if(outputfile)
			{
				while(getline(outputfile,line))
					{
						istringstream data(line);
						data>>bill_id>>type_id>>car_number>>client_name>>cnic_no>>phone_no>>start_date>>return_date>>payment>>bill_status;
						if(bill_status=="Yes"	||	bill_status=="YES"	||	bill_status=="yes")
							{
								cout<<setw(2.5)<<bill_id<<setw(10)<<type_id<<setw(17)<<car_number<<setw(18)<<client_name<<setw(25)<<cnic_no<<setw(19)<<phone_no<<setw(20)<<start_date<<setw(15)<<return_date<<setw(15)<<payment<<setw(11)<<bill_status<<endl;
							}
					}
				outputfile.close();
				green_color();
				cout<<"\n\t\t\tPRESS ANY KEY TO RETURN.............\t";
				white_color();
				cin.ignore();
				cin.get();
			}
		else
			{
				red_color();
				cout<<"\n\t\t\tFILE DOESNOT FOUNDED.............\t";
				white_color();
				cin.ignore();
				cin.get();
				Billing_management();
			}
		
	}


void display_unreceived_bill()	
	{
		int bill_id,type_id,payment;
		string line,car_number,client_name,start_date,return_date,bill_status;
		long long int cnic_no,phone_no;
	    cout<<"\n\n";
		cout<<"Bill-ID"<<setw(10)<<"Type-ID"<<setw(15)<<"Car-Number"<<setw(18)<<"Client-Name"<<setw(23)<<"CNIC-No"<<setw(20)<<"Phone-No"<<setw(20)<<"Start-Date"<<setw(15)<<"Return-Date"<<setw(15)<<"Payment"<<setw(14)<<"Bill-Status\n"<<endl;
		ifstream outputfile("Billing.txt");
		if(outputfile)
			{
				while(getline(outputfile,line))
					{
						istringstream data(line);
						data>>bill_id>>type_id>>car_number>>client_name>>cnic_no>>phone_no>>start_date>>return_date>>payment>>bill_status;
						if(bill_status=="NO"	||	bill_status=="No"	||	bill_status=="no")
							{
								cout<<setw(2.5)<<bill_id<<setw(12)<<type_id<<setw(17)<<car_number<<setw(18)<<client_name<<setw(25)<<cnic_no<<setw(19)<<phone_no<<setw(20)<<start_date<<setw(15)<<return_date<<setw(15)<<payment<<setw(11)<<bill_status<<endl;
							}
					}
				outputfile.close();
				green_color();
			}
		else
			{
				red_color();
				cout<<"\n\t\t\tFILE DOESNOT FOUNDED.............\t";
				white_color();
				cin.ignore();
				cin.get();
				Billing_management();
			}
		
	}
	

void sale_report()
	{
		int bill_id,type_id,payment,total_payment=0,user_month,user_year;
		string line,car_number,client_name,bill_status;
		char start_date[10],return_date[10];
		long long int cnic_no,phone_no;
		cout<<"\n\n";
		cout<<"\n\n\n\t\t\t\t\t\t Month  \t\t\t    :::::::::: \t";
		cin>>user_month;
		cout<<"\n\n\n\t\t\t\t\t\t Year   \t\t\t    :::::::::: \t";
		cin>>user_year;
		display_plain_line();
		ifstream outputfile("Billing.txt");
		if(outputfile){
		cout<<"Bill-ID"<<setw(10)<<"Type-ID"<<setw(15)<<"Car-Number"<<setw(18)<<"Client-Name"<<setw(23)<<"CNIC-No"<<setw(20)<<"Phone-No"<<setw(20)<<"Start-Date"<<setw(15)<<"Return-Date"<<setw(15)<<"Payment"<<setw(14)<<"Bill-Status\n"<<endl;

		while(getline(outputfile,line))
			{
				istringstream data(line);
				data>>bill_id>>type_id>>car_number>>client_name>>cnic_no>>phone_no>>start_date>>return_date>>payment>>bill_status;
				
		// for date checking find month and year in Array
			
			
				char r_m[3] = {return_date[3], return_date[4], '\0'};
				char r_y[5] = {return_date[6], return_date[7], return_date[8], return_date[9], '\0'};	
				int f_r_m=atoi(r_m);
				int f_r_y=atoi(r_y);
			
				
		// End
		
			if(user_month==f_r_m	&&	user_year==f_r_y	&&	(bill_status=="Yes"	|| bill_status=="YES" || bill_status=="yes"))
				{
					cout<<setw(2.5)<<bill_id<<setw(12)<<type_id<<setw(17)<<car_number<<setw(18)<<client_name<<setw(25)<<cnic_no<<setw(19)<<phone_no<<setw(20)<<start_date<<setw(15)<<return_date<<setw(15)<<payment<<setw(11)<<bill_status<<endl;
					total_payment+=payment;
				}
				
			}
			display_plain_line();
			cout<<"\n\n\n\t\t\t\t\t\t Total Sales  \t\t\t    :::::::::: \t"<<total_payment;
			green_color();
			cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t PRESS ENTER KEY TO CONTINUE ";
			white_color();
			cin.ignore();
			cin.get();
			display_bills();
		}
	else
		{
			red_color();
			cout<<"\n\t\t\tFILE DOESNOT FOUNDED.............\t";
			white_color();
			cin.ignore();
			cin.get();
			display_bills();
		}
		outputfile.close();
	}	


void change_password()
	{
		system("cls");
						display_banner();			
			    display_digital_line();
			    blue_color();
				cout<<"\t   ___________  \t   \t  ____________________"<<endl;
			    cout<<"\t  |           | \t > \t |          *         |"<<endl;
			    cout<<"\t  | DASHBOARD | \t > \t |   CHANGE PASSWARD  |"<<endl;
			    cout<<"\t  |___________| \t > \t |____________________|"<<endl;
			    white_color();
			    display_plain_line();
				cout<<"\n\n";
		while(1)
			{
				string user_name,file_name,file_password;
				ifstream outputfile("Login.txt");
				if(outputfile)
				{
				getline(outputfile,file_name);
				getline(outputfile,file_password);
				outputfile.close();
				cout<<"\n\n\n\t\t\t\t\t\t\t User Name \t\t :::::::::: \t";
				cin>>user_name;
				cout<<"\n\n\n\t\t\t\t\t\t\t Passward  \t\t :::::::::: \t";
				char password[32];//to store password.
   					int i = 0;
    				char a;//a Temp char
    				while(1)//infinite loop
    					{
        					a=getch();//stores char typed in a
        					if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
           								 //check if a is numeric or alphabet
        						{
            						password[i]=a;//stores a in pass
            						++i;
            						cout<<"*";
        						}
        					if(a=='\b'&&i>=1)//if user typed backspace
           							 //i should be greater than 1.
        						{
            						cout<<"\b \b";//rub the character behind the cursor.
            						--i;
        						}
       						 if(a=='\r')//if enter is pressed
        						{
            						password[i]='\0';//null means end of string.
            						break;//break the loop
        						}
    					}
    					
    					
				if(user_name==file_name	&&	password==file_password)
						{
							cout<<"\n";
							display_plain_line();
							cout<<"\n\n\n\t\t\t\t\t\t\t New User Name \t\t :::::::::: \t";
							cin>>user_name;
							cout<<"\n\n\n\t\t\t\t\t\t\t New Passward  \t\t :::::::::: \t";
							char password[32];//to store password.
   							int i = 0;
    						char a;//a Temp char
    						while(1)//infinite loop
    							{
        							a=getch();//stores char typed in a
        							if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
           								 //check if a is numeric or alphabet
        								{
            								password[i]=a;//stores a in pass
            								++i;
            								cout<<"*";
        								}
        							if(a=='\b'&&i>=1)//if user typed backspace
           								 //i should be greater than 1.
        								{
            								cout<<"\b \b";//rub the character behind the cursor.
            								--i;
        								}
       						 		if(a=='\r')//if enter is pressed
        								{
            								password[i]='\0';//null means end of string.
            								break;//break the loop
        								}
    							}
    							
							ofstream outputfile("Login.txt");
							outputfile<<user_name<<endl<<password;
							outputfile.close();
							green_color();
							cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t PASSWARD CHANGED SUCCESSFULLY :) "<<endl;
							white_color();
							cin.ignore();
							cin.get();
							break;
						}
						
				else
						{
							
							red_color();
							cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t INVALID USERNAME OR PASSWORD"<<endl;
							white_color();
							cin.ignore();
							cin.get();
							break;
						}		
			}
			else
				{
					red_color();
					cout<<"\n\t\t\tFILE DOESNOT FOUNDED.............\t";
					white_color();
					cin.ignore();
					cin.get();
				}
				
			}
	}
	
	
int check_type_id(int pass_id)
	{
		int type_id;
		string line;
		while(1)
			{
				ifstream outputfile("Car Type.txt");
				if(outputfile)
					{
						while(getline(outputfile,line))
							{
								istringstream data(line);
								data>>type_id;
								if(type_id==pass_id)
									{
										outputfile.close();
										return pass_id;
										break;
									}
							}
						red_color();
						cout<<"\n\n\n\t\t\t\t\t\t Enter Correct Car Type ID \t     :::::::::: \t";
						white_color();
						cin>>pass_id;
					}
				else
					{
						red_color();
						cout<<"\n\t\t\tFILE DOESNOT FOUNDED.............\t";
						white_color();
						cin.ignore();
						cin.get();
						outputfile.close();
						break;
					}
			}
		
	}
	
	
string check_type_name(int pass_id, string pass_name)
	{
		int type_id;
		string line,type_name;
				again:
				ifstream outputfile("Car Type.txt");
				if(outputfile)
					{
						while(getline(outputfile,line))
							{
								istringstream data(line);
								data>>type_id>>type_name;
								
											if(pass_name==type_name)
												{
													red_color();
													cout<<"\n\n\t\t\t\t\t\tTHIS TYPE NAME ALSO CONTAINED ...........\t";
													cout<<"\n\n\n\t\t\t\t\t Enter Correct Car Type Name \t    :::::::::: \t";
													white_color();
													cin>>pass_name;
													goto again;
												}
								}
							outputfile.close();
							return pass_name;	
					}
				else
					{
						red_color();
						cout<<"\n\t\t\tFILE DOESNOT FOUNDED.............\t";
						white_color();
						cin.ignore();
						cin.get();
						car_type_management();
					}
	}	
	
	
string check_car_number(int pass_id, string pass_number)
	{
		int type_id;
		string line,type_number;
				again: 			// Label for goto statement
				ifstream outputfile("Car Details.txt");
				if(outputfile)
					{
						while(getline(outputfile,line))
							{
								istringstream data(line);
								data>>type_id>>type_number;
								
											if(pass_number==type_number)
												{
													red_color();
													cout<<"\n\n\t\t\t\t\t\tTHIS TYPE NUMBER ALSO CONTAINED.............";
													cout<<"\n\n\n\t\t\t\t\t Enter Correct Car Number \t    :::::::::: \t";
													white_color();
													cin>>pass_number;
													goto again;			// Goto again label
												}
							}
						outputfile.close();
						return pass_number;
					}
				else
					{
						red_color();
						cout<<"\n\t\t\t\tFILE DOESNOT FOUNDED.............\t";
						white_color();
						cin.ignore();
						cin.get();
						car_type_management();
					}
	}	
	
	
string check_car_status(string status)
	{
		while(1)
			{
				if(status=="Yes" || status=="YES" || status=="yes" || status=="NO" || status=="no" || status=="No" )
					{
						return status;
						break;
					}
				else
					{
						red_color();
						cout<<"\n\n\n\t\t\t\t\t\t\t Enter Correct Car Status [Yes/No]    :::::::::: \t";
						white_color();
						cin>>status;
					}
			}
	}
	
	
int positive_number_check(int number)
	{
		while(1)
			{
				if(number>0)
					break;
				red_color();
				cout<<"\n\n\n\t\t\t\t\t\t Enter Positive rent \t    :::::::::: \t ";
				white_color();
				cin>>number;
			}
		return number;
	}
	
	
long long int cnic_check(long long int cnic_no)
	{
		while(1)
			{
				int digit;
				digit=log10(cnic_no)+1;
				if(digit!=13)
					{
						red_color();
						cout<<"\n\n\n\t\t\t\t Enter Correct CNIC [Numbers only] \t    :::::::::: \t";
						white_color();
						cin>>cnic_no;
					}
				else
					return cnic_no;
			}
	}
	
	
long long int phone_check(long long int phone_no)
	{
		while(1)
			{
				 int digit=log10(phone_no)+1;
				if(digit==10)
						return phone_no;
				red_color();		
				cout<<"\n\n\n\t\t\t\t\t\t Enter Correct Phone No. \t    :::::::::: \t [+92] ";
				white_color();
				cin>>phone_no;
			}
	}	
	
	
int check_bill_id(int pass_id)
	{
		int type_id;
		string line;
		while(1)
			{
				ifstream outputfile("Billing.txt");
				if(outputfile)
					{
						while(getline(outputfile,line))
							{
								istringstream data(line);
								data>>type_id;
								if(type_id==pass_id)
									{
										outputfile.close();
										return pass_id;
										break;
									}
							}
						red_color();
						cout<<"\n\n\n\t\t\t\t\t\t Enter Correct Car Type ID \t    :::::::::: \t";
						white_color();
						cin>>pass_id;
					}
				else
					{
						red_color();
						cout<<"\n\t\t\tFILE DOESNOT FOUNDED.............\t";
						white_color();
						cin.ignore();
						cin.get();
						outputfile.close();
						break;
					}
			}
		
	}

	
string check_answer(string answer)
	{
		while(1)
			{
				if(answer=="yes" || answer=="YES" || answer=="Yes" || answer=="no" || answer=="No" || answer=="NO")
					{
						return answer;
					}
				else
					{
						red_color();
						cout<<"\n\n\n\t\t\t\t\t\t Enter Correct [Yes/No]\t    :::::::::: \t ";
						white_color();
						cin>>answer;
					}
			}
	}	
	
	
	
	
	
	
	
	
	
