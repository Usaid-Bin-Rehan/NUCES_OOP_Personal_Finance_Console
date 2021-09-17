/*
PERSONAL FINANCE CONSOLE APPLICATION (CATEGORY: PRODUCTIVITY TOOLS) - OBJECT ORIENTED PROGRAMMING
by Usaid Rehan (20K-0297) and Huzaifa Jawad (20K-)

Classes: 10
Data Science Functions: 3 (1 with STL + 1 with Generic Programming)
Filing Function: 1
Downcasting and Exception Handling Function: 1

All C++ OOP Concepts covered:

A. Encapsulation
B. Abstraction
C. Inheritance (Virtual Hybrid / Diamond)

1. Polymorphism
		i.	(Compile-Time)
				Overloading of Account Constructor + Operator Overloading (++)  
		ii.	(Run-Time) / Abstract Class / Pure Virtual Function 
				Behaviour to Calculate Total Expenses
2. Interface
		Revenue Class and Investment Class
3. Explicit Keyword + Deep Copy Constructor
		To avoid user from stealing password
4. Data Member  Overriding 
		Important Expense Variables Specified in Base Class and Overriden in Derived
5. Operator Overloading (++) 
		Increment Login Count
6. Downcasting
		Derived ACCOUNT Class Pointer Dynamic Casted with Base EXPENSE Class Pointer in E2E Encryption Function
7. Exception Handling (bad_typeid)
		TypeID Error in End to End Encryption Function
8. Generic Programming / Templates (2 Generic Types) 
		Investment Advisor Function
9. Standard Template Library (Vector + Iterator + Map)
		Iterator and Map in Data Analytics Function
		Vector and its functions in Investment Advisor Function
10. Filing (Writing Object Data)
		Monthly Summary stored in Monthly_Report.txt
*/

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

// Standard Libraries and Header Files //

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <vector>
# include <exception>
# include <typeinfo>
# include <conio.h>
# include <stdlib.h>
using namespace std;

// Display Header Files //

# include <time.h>
# include <windows.h>

// Maximize the Screen //

# pragma comment(lib,"kernel32.lib")
# pragma comment(lib,"user32.lib")

// Global Variables and Prototypes //

int x = 0;
void Intro(void);
void Prompt(void);
void Outro(void);
void Outroduction(void);

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/


class ACCOUNT
{
	private:
		string password;
		string name;
		string cnic;
		
		int logins;
		
		// Data Members in Base Class to Overriden by Derived Class
		
		double tax;
		double insurance;
		double tloan;
		double tmorgage;
		
	protected:
		double emergency_fund;
		double balance;	
		
	public:
		ACCOUNT()
		{			
			Intro();
			
			cout << "Please enter your password: ";
			cin >> password;
			
			if(password != "20K-0297")
			{
				Outroduction();
				exit(1);
			}
			
			cout << "Enter your name and CNIC:" << endl;
			cin >> name;
			cin >> cnic;
			
			cout << "Enter any emergency funds you have: ";
			cin >> emergency_fund;
			
			cout << "Enter your current balance: ";
			cin >> balance;
		}
		
		void setbal()
		{
			cout << "Enter the new balance: ";
			cin >> balance;
		}
		
		void setef()
		{
			cout << "Enter the new emergency fund amount: ";
			cin >> emergency_fund;
		}
		
		double getbal()
		{
			return balance;
		}
		
		double getef()
		{
			return emergency_fund;
		}
		
		// Explicit Deep Copy Constructor to Avoid Password Stealing
		
		explicit ACCOUNT(ACCOUNT &copying_object)
		{
			copying_object.password = password;
		}
		
		// Overloading Account++ Operator to Increment Login Count
		
		void operator ++ (int)
		{
			logins++;
		}
};

class EXPENSE : virtual public ACCOUNT
{
	private:
		double estimatedexpence;
		
	protected:
		double total_expenses;
		
    public:
		EXPENSE ()
		{
			cout << "Enter the estimated amount you send in a month: ";
			cin >> estimatedexpence;
		}
	
		void setee()
		{
			cout << "Enter the estimated amount you send in a month: ";
			cin >> estimatedexpence;
		}
	
		double getee()
		{
			return estimatedexpence;
		}
		
		void Print_Summary(void)
		{
			cout << "Balance: " << balance << endl;
			cout << "Emergency Fund: " << emergency_fund << endl;
			cout << "Expenses: " << total_expenses << endl;
		}
	
		virtual void caldis() = 0;
};


class RECURRING_EXPENSE : virtual public EXPENSE
{
	private:
		double tax;
		double insurance;
		double tloan;
		double loan;
		float loaninterest;
		double tmorgage;
		double morgage;
		float morint;
		int lyear;
		int myear;
		
	public:
		RECURRING_EXPENSE()
		{
			cout << "Enter tax and insurance cost: ";
			cin >> tax >> insurance;
			cout<<"Enter loan and morgage amount: ";
			cin >> tloan >> tmorgage;
			cout << "Enter interest and moragage interest rates: ";
			cin >> loaninterest >> morint;
			cout << "Enter year by which loan must be payed: ";
			cin >> lyear;
			cout << "Enter year by which morgage must be payed: ";
			cin >> myear;
		}
		
		inline double gettax()
		{
			return tax;
		}
		
		double getins()
		{
			return insurance;
		}
		
		double getloan()
		{
			return loan;
		}
		
		double getmor()
		{
			return morgage;
		}
		
		void settax()
		{
			cout << "Enter Tax Value: ";
			cin >> tax;
		}
		
		void setins()
		{
			cout << "Enter Insurance Value: ";
			cin >> insurance;
		}
		
		void settloan()
		{
			cout << "Enter Loan Value: ";
			cin >> tloan;
		}
		
		void settmor()
		{
			cout << "Enter Morgage Value: ";
			cin >> tmorgage;
		}
		
		void cal()
		{
			loan = (tloan + ( tloan * loaninterest * (lyear - 2021) ) ) / ( 12 * (lyear - 2021) );
			morgage = (tmorgage + ( tmorgage * morint * (myear - 2021) ) ) / ( 12 * (myear - 2021) );
		}
		
		void caldis()
		{
			total_expenses = loan + morgage + tax + insurance;
			cout << total_expenses;
		}
		
		double gettotalexpence()
		{
			return total_expenses;
		}
};

class ONETIME_EXPENSE : virtual public EXPENSE
{
	private:
		double bill;
		int oyear;
	
	public:
		ONETIME_EXPENSE()
		{
			cout << "Please Enter any One-Time payments than you need to spend: ";
			cin >> bill;
			cout << "Please Enter the year by which this payment needs to be made: ";
			cin >> oyear;
		}
	
		void setbill()
		{
			cout << "Enter Bill Value: ";
			cin >> bill;
		}
	
		double getbill()
		{
			return bill;
		}
	
		void sety()
		{
			cout << "Enter Tax Value: ";
			cin >> oyear;
		}
	
		int gety()
		{
			return oyear;
		}
};

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

// Revenue Classes //

class REVENUE : virtual public ACCOUNT
{
	// Interface	
};

class INVESTMENT : virtual public REVENUE
{
	// Interface
};

class LONG_TERM : virtual public REVENUE
{
	protected:
		double gold_price;  // Current Price of Gold
		double gold_value; // Value of Gold Owned after 10 Years
		
		double index_price;  // Current Price of Index Fund
		double index_value; // Value of Index Fund after 1 Year (S&P 500 Capital Gains = Rate of Inflation) 
		
	public:
		LONG_TERM(void)
		{
			cout << "Input the price of gold: ";
			cin >> gold_price;
			
			cout << "Input the price of the index fund: ";
			cin >> index_price;
			
			gold_value = 0;
			index_value = 0;
		}
		
		void setgold(void)
		{
			cout << "Input the current price of gold: ";
			cin >> gold_price;
		}
			
		double getgold(void)
		{
			double owned;
			cout << "Input the amount of gold owned: ";
			cin >> owned;
			
			gold_value = owned * ( gold_price + (gold_price * 10 / 100) );
			return gold_value;
		}
		
		void setindex(void)
		{
			cout << "Input the current price of index funds: ";
			cin >> index_price;
		}
		
		double getindex(void)
		{
			double owned;
			cout << "Input the amount of Index Funds owned: ";
			cin >> owned;
			
			index_value = owned * ( index_price + (index_price * 10 / 100) );
			return index_value;
		}
};

class REAL_ESTATE : virtual public INVESTMENT
{
	protected:
		double land_value;
		double land_rent;
		
		double agricultural_value;
		double agricultural_rent;
		
		double residential_value;
		double residential_rent;
		
		double commercial_value;
		double commercial_rent;
		
		double mixeduse_value;
		double mixeduse_rent;
		
		double industrial_value;
		double industrial_rent;
		
	public:
		// Relevant Functions //
		
		REAL_ESTATE(void)
		{
			cout << "Input the initial land value and the rent: ";
			cin >> land_value;
			cin >> land_rent;
			
			cout << "Input the initial agricultural value and the rent: ";
			cin >> agricultural_value;
			cin >> agricultural_rent;
			
			cout << "Input the initial residential value and the rent: ";
			cin >> residential_value;
			cin >> residential_rent;
		
			cout << "Input the initial commercial value and the rent: ";
			cin >> commercial_value;
			cin >> commercial_rent;
			
			cout << "Input the initial mixed-use value and the rent: ";
			cin >> mixeduse_value;
			cin >> mixeduse_rent;
			
			cout << "Input the initial industrial value and the rent: ";
			cin >> industrial_value;
			cin >> industrial_rent;
		}
		
		void setland(void)
		{
			double area_value = 1;
			double facilities_value = 1;
			double yards = 1;
			double rent_percent = 1;
			
			cout << "Input the area value, facilities value, yards and rent percent: ";
			cin >> area_value;
			cin >> facilities_value;
			cin >> yards;
			cin >> rent_percent;
			
			land_value = (area_value + facilities_value) * yards;
			land_rent = rent_percent * land_value;
		}
		double getland(void)
		{
			return land_value;
		}
		double getlandrent(void)
		{
			return land_rent;
		}
		
		void setagricultural(void)
		{
			double yards = 1;
			double irrigation_value; 
			double network_value; 
			double soil_value;
			double net_cash_flow_at_time; 
			double discount_rate; 
			double rent_percent;
			double net_present_value;
			
			cout << "Input the yards, irrigation value, network value, soil value, net cash flow at time, discount rate and rent percent: ";
			cin >> yards;
			cin >> irrigation_value; 
			cin >> network_value; 
			cin >> soil_value;
			cin >> net_cash_flow_at_time; 
			cin >> discount_rate; 
			cin >> rent_percent;
			
			agricultural_value = yards * (irrigation_value * network_value * soil_value);
			net_present_value = net_cash_flow_at_time / (1 + discount_rate);
			agricultural_rent = rent_percent/100 * net_present_value;
		}
		double getagricultural(void)
		{
			return agricultural_value;
		}
		double getagricultural_rent(void)
		{
			return agricultural_rent;
		}
		
		void setresidential(void)
		{
			double land_value = 1; 
			double yards = 1;
			double construction_cost = 1; 
			double rent_percent = 1; 
			double floors_portions = 1;
			
			cout << "Input the land value, yards, construction cost, rent percent and floors or portions: ";
			cin >> land_value; 
			cin >> yards; 
			cin >> construction_cost; 
			cin >> rent_percent; 
			cin >> floors_portions;
			
			residential_value = (land_value * yards) + construction_cost;
			residential_rent = (rent_percent/100 * residential_value) * floors_portions;
		}
		double getresidential(void)
		{
			return residential_value;
		}
		double getresidential_rent(void)
		{
			return residential_rent;
		}
		
		void setcommercial(void)
		{
			double market_value;
			double yards;
			double gross_rental_income;
			double rent_percent;
			
			cout << "Input the market value, yards and rent percent: ";
			cin >> market_value;
			cin >> yards;
			cin >> rent_percent;
			
			commercial_value = market_value * yards;
			commercial_rent = (commercial_value * gross_rental_income) * rent_percent/100;
		}
		double getcommercial(void)
		{
			return commercial_value;
		}
		double getcommercialrent(void)
		{
			return commercial_rent;
		}
		
		void setmixeduse(void)
		{
			double use1_value = 1; 
			double use1_percent = 1;
			double use2_value = 1;
			double use2_percent = 1;
			double rent_percent = 1;
			double yards = 1;
			
			cout << "Enter value and percentage of use 1 and use 2, rent percent and yards: ";
			cin >> use1_value; 
			cin >> use1_percent;
			cin >> use2_value;
			cin >> use2_percent;
			cin >> rent_percent;
			cin >> yards;
			
			mixeduse_value = ( (use1_value * use1_percent/100) + (use2_value * use2_percent/100) ) * yards;
			mixeduse_rent = rent_percent/100 * mixeduse_value;
		}
		double getmixeduse(void)
		{
			return mixeduse_value;
		}
		double getmixeduserent(void)
		{
			return mixeduse_rent;
		}
		
		void setindustrial(void)
		{
			double local_cost; 
			double sqfeet; 
			double features_value; 
			double facilities_value; 
			double network_value; 
			double rent_percent; 
			double gross_rental_income;
			double warehouse_value;
			
			cin >> local_cost; 
			cin >> sqfeet; 
			cin >> features_value; 
			cin >> facilities_value; 
			cin >> network_value; 
			cin >> rent_percent; 
			cin >> gross_rental_income;
			
			warehouse_value = (local_cost * sqfeet) + features_value; 
			industrial_value = warehouse_value + facilities_value + network_value;
			industrial_rent = (rent_percent/100 * industrial_value) + (rent_percent/100 * gross_rental_income);
		}
		double getindustrial(void)
		{
			return industrial_value;
		}
		double getindustrialrent(void)
		{
			return industrial_rent;
		}
};


class INCOME : virtual public REVENUE
{
	protected:
		double fulltime;
		double freelancing; // Increments with earnings from each gig
		double affiliate;  // Increments with earnings from each affiliate product sale
		
	public:
		INCOME(void)
		{
			cout << "Input the full-time income: ";
			cin >> fulltime;
			
			cout << "Input free-lancing income: ";
			cin >> freelancing;
			
			cout << "Input affiliate income: ";
			cin >> affiliate;			
		}
		
		void setfulltime(void)
		{
			cout << "Enter full time income: ";
			cin >> fulltime;
		}
		
		double getfulltime(void)
		{
			return fulltime;
		}
		
		void setfreelancing(void)
		{
			double gig = 1;
			cout << "Enter gig income: ";
			cin >> gig;
			
			freelancing = freelancing + gig;
		}
		
		double getfreelancing(void)
		{
			return freelancing;
		}
		
		void setaffiliate(void)
		{
			double product_price;
			double percent_affiliate;
			
			cout << "Enter product price and percent affiliate: ";
			cin >> product_price;
			cin >> percent_affiliate;
			
			affiliate = affiliate + ( product_price *  (percent_affiliate/100) );
		}
};

class PASSIVE : virtual public REVENUE
{
	protected:
		double dividends;
		double business_revenue;
		double royalties;
		
		double total_dividends; // Sum of entire dividend earnings
		double net_income;	   // Business earnings for owner's personal use
	
	public:
		PASSIVE(void)
		{
			double dividends; 
			double business_revenue; 
			double royalties;
			
			cout << "Enter dividends, business revenue, royalties: ";
			cin >> dividends;
			cin >> business_revenue;
			cin >> royalties;
		}
		
		void setdividends(void)
		{
			double monthly_dividend;
			cout << "Enter monthly dividend: ";
			cin >> monthly_dividend;
			
			dividends = dividends + monthly_dividend;
		}
		
		double getdividends(void)
		{
			cout << "Enter dividends: ";
			cin >> dividends;
			
			total_dividends = dividends;
			total_dividends = total_dividends + dividends;
			return total_dividends;
		}
		
		void setbusiness(void)
		{
			cout << "Enter current business revenue: ";
			cin >> business_revenue;
		}
		
		double getbusiness(void)
		{
			double reinvestment; 
			double incometax;
			double netincome;
			cout << "Enter reinvestment and income tax: ";
			cin >> reinvestment;
			cin >> incometax;
			
			netincome = business_revenue - reinvestment - incometax;
			return netincome;
		}
		
		void setroyalties(void)
		{
			double intellectualproperty_price; 
			double percent;
			cout << "Enter intellectual property price and royalty percent: ";
			
			royalties = royalties + (intellectualproperty_price * (percent / 100) );
		}
		
		double getroyalties(void)
		{
			return royalties;
		}
};


/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

class ACCOUNT : public RECURRING_EXPENSE, public ONETIME_EXPENSE, public LONG_TERM, public REAL_ESTATE, public INCOME, public PASSIVE
{
	private:
		double wealth;
	
	public:
		double Total_Revenue(void)
		{
			wealth = total_dividends + net_income + fulltime + freelancing + affiliate + land_value+ land_rent+agricultural_value+agricultural_rent+ residential_value + residential_rent + commercial_value + commercial_rent + mixeduse_value + mixeduse_rent + industrial_value + industrial_rent + gold_value + index_value;
			return wealth;
		}
};

ACCOUNT person; // Global Object of Person Class

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/


	// Incorporating Data Science into OOP //

// BUILDING A DATA PLATFORM : Incorporating Data Engineering into OOP

void Data_Visualization(void)
{
	// Incorporating Data Visualization into OOP (Bar Charts) //
	
	// Map is used to count frequency of assets entered since user can enter any cryptocurrency name //
	
	int i; 
	char s[100]; 
	string datastorage;
	
	cout << "Enter the name of assets upto the number of times you own them: ";
	fflush(stdin);
	gets(s);
	cout << endl << endl << "===========================================================================" << endl;
	
    map <string, int> mapname; 
    stringstream sobj(s);
    
    while (sobj >> datastorage) 
    {
    	mapname[datastorage]++;
	}
	
    map <string, int> :: iterator it; 
    
    for (it = mapname.begin(); it != mapname.end(); it++) 
	{
		cout << it->first << "\t";
		for(i=0;i<(it->second);i++)
		{
			cout << "\xdb";
		}
		cout << endl;
	}
	
	cout << "===========================================================================" << endl;

	
	Prompt();
}

void Retirement_Predictor()
{
	int x, y=0, z=0;
	double networth = person.Total_Revenue() - person.gettotalexpence();
	if(networth <= 0)
	{
		cout << "Sorry this function does not work on a negative value\n";
	}
	else
	{
		cout << "Choose From one of these cases: " << endl;
		cout << "[Case 1]: Enter the amount at which you want to retire and the programm will tell by what time(in year and month) will you be to retire...\n";
		cout << "[Case 2]: Enter the time in(year and month) and the programm will tell you your estimated net worth in the future...\n";
		cin>>x;
		switch(x)
		{
			case 1:
			{
			double amount;
			cout<<"Please enter a valid positive amount\n";
			cin>>amount;
			while(z<amount-person.getbal())
			{
				y++;
				z+=networth;
			}
			cout<<(int)y/12<<"Years and "<<y%12<<"months left in your retirement\n";
			cout<<"Thanks\n";
			break;
			}
			case 2:
			{
			cout<<"Please enter year and month\n";
			cin>>x>>y;
			double variable = (((12*x)+y)*networth)+person.getbal();
			cout<<"The amount you will have by this time is " << variable;
			break;
			}
			
			default: 
			Retirement_Predictor();
	}
}
	
	Prompt();
}

template <class T>
void Investment_Advisor(T parameter_only_used_for_function_call)
{	
	T type;
	double percent;
	cout << "1. Short-Term" << endl;
	cout << "\t" << "C) Cryptocurrency" << endl;
	cout << "\t" << "S) Stocks" << endl;
	cout << "2. Long-Term" << endl;
	cout << "\t" << "M) Metal" << endl;
	cout << "\t" << "I) Index-Fund" << endl;
	cout << "\t" << "R) Real-Estate" << endl;	
	cout << "Enter the respective number or character of the asset type: ";
	cin >> type;
	cout << "Enter its percent in your portfolio: ";
	cin >> percent;
	
	if(type == 1 || type == 'C' || type == 'S')
	{
		if(percent < 30)
		{
			cout << "Invest more in Short Term Assets" << endl;
		}
		else
		{
			cout << "Invest more in Long Term Assets" << endl;
		}
	}
	
	else if(type == 2 || type == 'M' || type == 'I' || type == 'R')
	{
		if(percent < 30)
		{
			cout << "Invest more in Long Term Assets" << endl;
		}
		else
		{
			cout << "Invest more in Short Term Assets" << endl;
		}
	}
	
	vector <char> assets;
	cout << "The number of assets you own is " << assets.size() << endl;
	cout << "Enter 1. to add an asset, 2. to clear all assets OR any other value to skip: ";
	cin >> x;
	if(x == 1)
	{
		cout << "Enter the number of assets you want to enter: ";
		int newsize;
		cin >> newsize;
		assets.resize(newsize);
		
		cout << "Enter the character of asset you want to enter: ";
		char asset;
		cin >> asset;
		assets.push_back(asset);
	}
	if(x == 2)
	{
		assets.clear();
		bool e = assets.empty();
		if(e == true)
		{
			cout << "Assets successfully removed" << endl;
		}
		else
		{
			cout << "Error emptying assets!" << endl;
		}
	}
	else
	{
		Prompt();
	}
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

void Balance(void)
{
	cout << "Enter 1. to view OR 2. to update " << endl;
	cin >> x;
	switch(x)
	{
		case 1:
			cout << person.getbal() << endl;
			break;
			
		case 2:
			person.setbal();
			break;	
			
		default:
			Balance();	
	}
}

void Emergency_Fund(void)
{
	cout << "Enter 1. to view OR 2. to update " << endl;
	cin >> x;
	switch(x)
	{
		case 1:
			cout << person.getef() << endl;
			break;
			
		case 2:
			person.setef(); 
			break;	
	}
}

void View_Expense(void)
{
	cout << "View Expense: " << endl;
	cout << "1. Tax " << endl;
	cout << "2. Insurance " << endl;
	cout << "3. Loan" << endl;
	cout << "4. Morgage" << endl;
	cin >> x;
	switch(x)
	{
		case 1:
			cout << person.gettax () << endl;
			break;
			
		case 2:
			cout << person.getins() << endl;
			break;
			
		case 3:
		 cout << person.getloan() << endl;
			break;
		    
		case 4:
			cout << person.getmor() << endl;
			break;
			
		default:
			View_Expense();
	}
}

void Update_Expense(void)
{
	cout << "Update Expense: " << endl;
	cout << "1. Tax " << endl;
	cout << "2. Insurance" << endl;
	cout << "3. Total Loan" << endl;
	cout << "4. Total Morgage" << endl;
	cin >> x;
	switch(x)
	{
		case 1:
			person.settax();
			break;
			
		case 2:
			person.setins();
			break;
			
		case 3:
		    person.settloan();
			break;
		case 4:
			person.settmor(); 
			break;
			
		default:
			Update_Expense();		
	}	
}

void Expense(void)
{
	cout << "Enter 1. to view OR 2. to update: ";
	cin >> x;
	switch(x)
	{
		case 1:
			View_Expense();
			break;
			
		case 2:
			Update_Expense();
			break;
			
		default:
			Expense();
	}
}

void View_Investments(void)
{
	cout << "VIEW INVESTMENTS" << endl;
	cout << "1. Gold Value in Decade" << endl;
	cout << "2. Index Fund Value in Decade" << endl;
	cout << "3. Land Estate" << endl;
	cout << "4. Agricultural Real Estate" << endl;
	cout << "5. Residential Real Estate" << endl;
	cout << "6. Commercial Real Estate" << endl;
	cout << "7. Mixed Use Real Estate" << endl;
	cout << "8. Industrial Real Estate" << endl;
	
	cin >> x;
	switch(x)
	{
		case 1:
			cout << person.getgold() << endl;
			break;
			
		case 2:	
			cout << person.getindex() << endl;
			break;
			
		case 3:	
			cout << person.getland() << endl;
			break;
			
		case 4:
			cout << person.getagricultural() << endl;
			break;
			
		case 5:	
			cout << person.getresidential() << endl;
			break;
			
		case 6:
			cout << person.getcommercial() << endl;
			break;
		
		case 7:
			cout << person.getmixeduse() << endl;
			break;
		
		case 8:
			cout << person.getindustrial() << endl;
			break;
			
		default:
			View_Investments();
	}
}

void Update_Investments(void)
{
	cout << "Update INVESTMENTS" << endl;
	cout << "1. Gold Price" << endl;
	cout << "2. Index Fund Price" << endl;
	cout << "3. Land Estate" << endl;
	cout << "4. Agricultural Real Estate" << endl;
	cout << "5. Residential Real Estate" << endl;
	cout << "6. Commercial Real Estate" << endl;
	cout << "7. Mixed Use Real Estate" << endl;
	cout << "8. Industrial Real Estate" << endl;
	
	cin >> x;
	switch(x)
	{
		case 1:
			person.setgold();
			break;
			
		case 2:	
			person.setindex();
			break;
			
		case 3:	
			person.setland();
			break;
			
		case 4:
			person.setagricultural();
			break;
			
		case 5:	
			person.setresidential();
			break;
			
		case 6:
			person.setcommercial();
			break;
		
		case 7:
			person.setmixeduse();
			break;
		
		case 8:
			person.setindustrial();
			break;
			
		default:
			Update_Investments();
	}
}

void Investments(void)
{
	cout << "Enter 1. to view and 2. to update: ";
	cin >> x;
	switch(x)
	{
		case 1:
			View_Investments();
			break;
			
		case 2:
			Update_Investments();
			break;	
		
		default:
			Investments();
	}
}

void Update_Month_and_Generate_Previous_Summary(void)
{
				ofstream write_object;
				write_object.open("Monthly_Report.txt",ios::out);
				if(!write_object)
				{
					cout << "Error File Not Created!" << endl;
				}
				person.Print_Summary();
				write_object.write( (char*) &person, sizeof(person) );
				write_object.close();
				Prompt();			
}

void E2Encryption(void)
{
	cout << "This function will try to hack expenses memory " << endl << " as well as create invalid type ID" << endl;
	cout << "This is a proof that hacking attempt will be prevented" << endl << " by program becoming unresponsive" << endl;
	system("PAUSE");
	
	// Downcasting
	
	EXPENSE *ptr;
	PERSON *p = dynamic_cast <PERSON *> (ptr);
	
	// Exception Handling
	
	PERSON *pointer = 0;
	try
	{
		typeid(*pointer);
	}
	catch(exception &eobj)
	{
		cout << "Exception: " << eobj.what() << endl;
	}
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

void Prompt(void)
{
	system("PAUSE");
	system("cls");
	cout << "#########" << endl;
	cout << "# MENU: #" << endl;
	cout << "#########" << endl << endl;
	cout << "[ 1 ]	Balance" << endl;
	cout << "[ 2 ]	Emergency Fund" << endl;
	cout << "[ 3 ]	Expense" << endl;
	cout << "[ 4 ]	Investments" << endl;
	cout << "[ 5 ]	Data Visualization" << endl;
	cout << "[ 6 ]	Investment Advisor" << endl;
	cout << "[ 7 ]	Retirement Predictor" << endl;
	cout << "[ 8 ]	Store Encrypted Month's Summary File on PC" << endl;
	cout << "[ 9 ]	Proof of End to End Encryption of this App" << endl;
	cout << "[ 0 ]	Exit" << endl;
	
	cin >> x;
	switch(x)
	{
		case 1:
			Balance();
			Prompt();
			
		case 2:
			Emergency_Fund();
			Prompt();
				
		case 3:
			Expense();
			Prompt();
			
		case 4:
			Investments();
			Prompt();
			
		case 5:	
			Data_Visualization();
			Prompt();
			
		case 6:	
			Investment_Advisor(0);
			Prompt();
			
		case 7:	
			Retirement_Predictor();
			Prompt();
			
		case 8:
			Update_Month_and_Generate_Previous_Summary();
			Prompt();
			
		case 9:
			E2Encryption();
			break;	
			
		case 0:
			Outro();
			break;
			
		default:
			Prompt();	
	}
};


int main()
{
	Prompt();
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

void delay(clock_t a)
{
    clock_t start;
    start  = clock();
    while(clock()-start<a)
    {

    }
}

void FloatingText(void)
{
	int i,y,chk=0,win=0,uposa[5][2],uposb[4][2],uposd[3][2],uposc[2][2],a=0,b=0,c=0,d=0,probab,diff;
    char gridu[10][10],griduv[10][10],gridc[10][10],gridcv[10][10],orin[2],tempstr[10],str[100]="  PERSONAL\n\t\t\t\tFINANCE\n\t\t\t\tCONSOLE\n\t\t\t\tAPPLICATION\n\n\t\t\t\t   BY:\n\t\t\t\tUsaid Rehan\n\t\t\t\tHuzaifa Jawad",ch;
    cout << endl << endl << endl << endl << endl << endl;
	for(i=0;i<10;i++)
    {
        printf("\n");
    }
    for(i=0;i<30;i++)
    {
        printf(" ");
    }
    for(i=0;str[i]!='\0';i++)
    {
        	printf("%c",str[i]);
        	delay(60);
    	}
    	printf("\n");
		delay(1500);
    	system("cls");
}

void Intro(void)
{	
			// Background and Text Colour Setting Function
			
			system("Color F4");
			
			// Maximize the Screen //
			HWND hWnd = GetConsoleWindow();
			ShowWindow(hWnd,SW_MAXIMIZE);
			
			FloatingText();
			
			system("Color 06");
			// Number of lines for the alphabet's pattern 
			int height = 5; 
			// Number of character width in each line 
			int width = (2 * height) - 1; 
			int i, j;
    		for (i = 0; i < height; i++) 
			{ 
        		cout << "*"; 
        		for(j = 0; j < height; j++) 
				{ 
					if ((i == 0) || (i == height / 2 && j <= height / 2)) 
                		cout << "*";
           			else
                		continue; 
        		} 
        		cout << "\n"; 
    		}
    		
    		int n = width / 2; 
    		for (i = 0; i < height; i++) 
			{ 
        		for (j = 0; j <= width; j++) 
				{ 
            		if (j == n || j == (width - n) || (i == height / 2 && j > n && j < (width - n))) 
                		cout << "*"; 
            		else
                		cout << " "; 
        		} 
        		cout <<"\n"; 
        		n--; 
    		}
    		
    		for (i = 0; i < height; i++) 
			{
				cout << "\t"; 
    			for (j = 0; j < height; j++) 
				{
            		if ((i == 0 || i == height / 2 || i == height - 1)) 
                		cout << "*"; 
            		else if (i < height / 2 && j == 0) 
                		cout << "*"; 
            		else if (i > height / 2 && j == height - 1) 
                		cout << "*"; 
            		else
                		cout << " ";         
        		}
        		cout << "\n";
    		} 
    
    		for (i = 0; i < height; i++) 
			{ 
				cout << "\t\t";
        		for (j = 0; j < height; j++) 
				{ 
            		if (i == 0) 
                		cout << "*"; 
            		else if (j == height / 2) 
             		   cout << "*"; 
            		else
                		cout << " "; 
        		}
        		cout << "\n"; 
    		} 
    		cout << endl;
    		    		
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb     \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb    \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb    \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb    \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb    \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb        \xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb        \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb       \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb       \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb      \xdb\xdb\xdb\xdb\xdb\xdb  \xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb      \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb      \xdb\xdb\xdb\xdb     \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb    \xdb\xdb\xdb\xdb      \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb              \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb            \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  \xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb  \xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb \xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  \xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb  \xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb  \xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  \xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb  \xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb \xdb\xdb  \xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb \xdb\xdb \xdb\xdb\xdb   \xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb  \xdb \xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb \xdb  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			
			cout << endl << endl << "LOADING: ";
			
			Beep(300,100);
			Beep(100,100);
			Beep(300,100);
			Beep(100,300);
			cout << " \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			Beep(300,100);
			Beep(150,100);
			Beep(300,100);
			Beep(100,100);
			Beep(300,100);
			Beep(150,300);
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			Beep(350,100);
			Beep(200,100);
			Beep(250,100);
			Beep(150,100);
			Beep(350,100);
			Beep(200,300);
			Beep(300,100);
			Beep(200,100);
			Beep(300,100);
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			Beep(150,100);
			Beep(300,100);
			Beep(120,300);
			Beep(300,100);
			Beep(190,100);
			Beep(300,100);
			Beep(140,100);
			Beep(300,100);
			Beep(170,300);
			Beep(360,100);
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			Beep(130,100);
			Beep(300,100);
			Beep(120,100);
			Beep(300,100);
			Beep(190,300);
			Beep(300,100);
			Beep(150,100);
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			Beep(300,100);
			Beep(150,100);
			Beep(300,100);
			Beep(100,300);
			Beep(150,200);
			Beep(200,200);
			Beep(250,300);
			cout << "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
			system("cls");
			system("Color 4F");
}

void Outro(void)
{
			cout<<"\n\n";
			cout<<"[][][] [][][] [][][] [][][] [][][]    []    []    []\n";	
			cout<<"[]  [] []  [] []  [] []     []  []  []  []  [][][][]\n";
			cout<<"[][][] [][][] []  [] [] []  [][][] [][][][] [] [] []\n";
			cout<<"[]     [] []  []  [] []  [] [] []  []    [] []    []\n";
			cout<<"[]     []  [] [][][] [][][] []  [] []    [] []    []\n\n";
			cout<<"[][][] [][][]     [][][] []     [][][] [][][] [][][] []   [] [][][]\n";	
			cout<<"  []   []         []  [] []     []  [] []       []   []]  [] []\n";
			cout<<"  []   [][][]     []     []     []  [] [][][]   []   [][] [] [] []\n";
			cout<<"  []       []     []  [] []     []  []     []   []   [] [][] []  []\n";
			cout<<"[][][] [][][]     [][][] [][][] [][][] [][][] [][][] []  [[] [][][]\n\n";
			cout<<"[][][]  []     [] [][][]   [] [] []\n";	
			cout<<"[]   []  []  []   []       [] [] []\n";
			cout<<"[]  []     []     [][][]   [] [] []\n";
			cout<<"[]   []    []     []\n";
			cout<<"[][][]     []     [][][]   [] [] []\n\n";
	
				Beep(100,100);
				Beep(120,100);
				Beep(140,100);
				Beep(160,100);
				Beep(180,100);
				Beep(200,100);
				Beep(220,100);
				Beep(240,100);
				Beep(260,100);
				Beep(280,100);
				Beep(300,100);
				Beep(320,100);
				Beep(340,100);
				Beep(360,100);
				Beep(380,100);
				Beep(400,100);
				Beep(420,100);
				Beep(440,100);
				Beep(460,100);
				Beep(480,100);
				Beep(500,100);
				Beep(600,300);
}

void Outroduction(void)
{
			cout<<"\t\t\t[][][] [][][] [][][] [][][] [][][]\n";
			cout<<"\t\t\t[]     []  [] []  [] []  [] []  []\n";
			cout<<"\t\t\t[][][] [][][] [][][] []  [] [][][]\n";
			cout<<"\t\t\t[]     [] []  [] []  []  [] [] []\n";
			cout<<"\t\t\t[][][] []  [] []  [] [][][] []  []\n\n";
}

/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
