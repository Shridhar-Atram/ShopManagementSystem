#include<iostream>
#include<fstream>

using namespace std;
 
class shopping
{
	private:
		int product_code;
		float price;
		float discount;
		string product_name;
		
	public :
		void menu();
		void administrator();
		void buyer();
		void add();
		void edit();
		void remove_product();
		void list();
		void receipt();
		
};

void shopping :: menu()
{
	m: 
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t_________________________________________\n";
	cout<<"\t\t\t\t                                         \n";
	cout<<"\t\t\t\t        Supermarket Main Menu            \n";
	cout<<"\t\t\t\t                                         \n";
	cout<<"\t\t\t\t_________________________________________\n";
	cout<<"\t\t\t\t                                         \n";
	cout<<"\t\t\t\t|  1) Administrator |\n";
	cout<<"\t\t\t\t|                   |\n";
	cout<<"\t\t\t\t|  2) Buyer         |\n";
	cout<<"\t\t\t\t|                   |\n";
	cout<<"\t\t\t\t|  3) Exit          |\n";
	cout<<"\t\t\t\t|                   |\n";
	cout<<"\t\t\t\t Please select :";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"\t\t\t\t\n Please Login ";
			cout<<"\t\t\t\t\n Enter Email  ";
			cin>>email;
			cout<<"\t\t\t\t\n Password";
			cin>>password;
			
			
			if( email == "shri@gmail.com" && password=="shri@123")
			{
				administrator();
			}
			else
			{
				cout<<"Invalid Email/Password\n";
			}
			break;
			
			
		case 2:
			{
				buyer();
				
			}
			
		case 3:
			{
				exit(0);
			}
			
		default :
			{
				cout<<"Please select from the given option\n";
				
			}
						
	}
	goto m;
} 
void shopping :: administrator()
{
	m:
	int choice;
	cout<<"\n\n\n\t\t\t Administrator Menu";
	cout<<"\n\t\t\t|_____1) Add the Product_____|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_____2) Modify the Product__|";
	cout<<"\n\t\t\t|							|";
	cout<<"\n\t\t\t|_____3) Delete the Product__|";
	cout<<"\n\t\t\t|							|";
	cout<<"\n\t\t\t|_____4) Back to main menu___|";
	
	cout<<"\nPlease Enter Your Choice";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			add();
			break;
			
		case 2:
			edit();
			break;
			
		case 3:
			remove_product();
			break;
			
		case 4:
			menu();
			break;
		
		default :
			cout<<"\nInvalid Choice";
			
	}
	goto m;
	
}

void shopping:: buyer()
{
	m:
	int choice ;
	cout<<"\t\t\t Buyer           \n";
	cout<<"\t\t\t_________________\n";
	cout<<"                       \n";
	cout<<"\t\t\t 1) Buy product  \n";
	cout<<"                       \n";
	cout<<"\t\t\t 2) Go back      \n";
	cout<<"\n\t\t\t Enter Your Choice : ";
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
			
		case 2:
			menu();
			
		default :

			cout<<"\ninvalid choice";
						
	}
	
	goto m;
		
		
}

void shopping :: add()
{
	m:
	fstream data;
	int c;;
	int token=0;
	float p;
	float d;
	string n;	
	cout<<"\n\n\t\t\t Add new product";
	cout<<"\n\n\t Product code of the product ";
	cin>>product_code;
	cout<<"\n\n\t  Name of the product ";
	cin>>product_name;
	cout<<"\n\n\t Price of the Product ";
	cin>>price;
	cout<<"\n\n\t Discount on product ";
	cin>>discount;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<discount<<"\n";
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d;
		
		while(!data.eof())
		{
			if(c== product_code)
			{
				token++;
				
			}
			data>>c>>n>>p>>d;

		}
		data.close();
		

	
	if(token==1)
	   goto m;
	   
	else
	{
    	data.open("database.txt", ios::app|ios::out);
	    data<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<discount<<"\n";
	    data.close(); 
	
	}

}
	cout<<"\n\n\t\t Record inserted !";
}

void shopping :: edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\t\t\t Modify the record ";
	cout<<"\n\t\t\t Product code :";
	cin>>pkey;
	
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"\n\n File doesn't exist :";
	}
	else
	{
		data1.open("database1.txt,ios::app|ios::out");//"edited data will be stored in database1.txt"	
		data>>product_code>>product_name>>price>>discount;
		while(!data.eof())
		{
			if(pkey=product_code)
			{
				cout<<"\n\t\t Product new code :";
				cin>>c;
				cout<<"\n\t\t Name of the product : ";
				cin>>n;
				cout<<"\n\t\t Discount :";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				token++;
			}
			else
			{
				data1<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<discount<<"\n";
				
			}
			data>>product_code>>product_name>>price>>discount;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0)
		{
			cout<<"\n\n Record not found sorry !";
		}
	
	}
}
void shopping :: remove_product()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t Delete product";
	cout<<"\n\n\t Product code :";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"File doesn't exist ";
	}
 else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>product_code>>product_name>>price>>discount;
		while(!data.eof())
		{
			if(product_code==pkey)
			{
				cout<<"\n\n\t Product deleted succesfully";
			}
			else
			{
				data<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<discount<<"\n";
		
			}
			data>>product_code>>product_name>>price>>discount;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0)
		{
			cout<<"\n\n Record not found";
		}
	}
	
}
void shopping:: list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|________________________________________\n";
	cout<<"Product_Number\t\tName\t\tPrice\n";
	cout<<"\n\n|________________________________________\n";
	data>>product_code>>product_name>>price>>discount;
	while(!data.eof())
	{
		cout<<product_code<<"\t\t"<<product_name<<"\t\t"<<price<<"\n";
		data>>product_code>>product_name>>price>>discount;
	}
	data.close();
}
void shopping:: receipt()
{
	fstream data;
	
	int arrc[100];//code
	int arrq[100];//quantity
	char choice;
	int c=0;
	float amount=0;
	float discount=0;
	float total=0;
	cout<<"\n\n\t\t\t\t RECEIPT";
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n Empty database";
	}
	else
	{
		data.close();
		list();
		cout<<"\n__________________________________________\n";
		cout<<"\n										   \n";
		cout<<"\n         Please place the order           \n";
		cout<<"\n										   \n";
		cout<<"\n__________________________________________\n";
		do
		{
			m:
			cout<<"\n\n Enter Product code : ";
			cin>>arrc[c];
			cout<<"\n\nEnter the product quantity : ";
			cin>>arrq[c];
			for(int i=0;i<c;i++)
			{
				if(arrc[c]==arrc[i])
				{
					cout<<"\n\n Duplicate Product code.Please try again";
					goto m;
				}
			}
			c++;
			cout<<"\n\n Do you want to buy another product? if yes then press y else n for no";
			cin>>choice;
		}
		while(choice == 'y');
		cout<<"\n\n\t\t\t__________________RECEIPT__________________\n";
		cout<<"\nProduct No\t Product Name \t Product quantity\tPrice\tAmount with discount";
		
		for(int i=0;i<c;i++)
		{
			data.open("database.txt",ios::in);
			data>>product_code>>product_name>>price>>discount;
			while(!data.eof())
			{
				if(product_code==arrc[i])
				{
					amount=price*arrq[i];
					discount= amount-(amount*discount/100);
					total = total + discount;
					cout<<"\n"<<product_code<<"\t\t"<<product_name<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<discount;
				}
			}
		}
		data.close();
	}
	cout<<"\n\n__________________________________________\n";
	cout<<"\nTotal Amount :"<<total;
}
int main()
{
	shopping s;
	s.menu();
}
