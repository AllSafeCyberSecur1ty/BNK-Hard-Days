#include<iostream> 
#include<stdio> //gets() and puts()
#include<stdlib> //exit()
using namespace std;
class banking
{
  // by default member are private
   int amount,ac_number;
   char cust_name[20],ac_type;
 public:
 // member are public
   void get_record();
   friend void show_record(banking); // displaying customer record
   int re_amount();  // to return spacific customer amount
   int re_account(); // to return spacific customer account
   int deposit();    // deposit into account
   int withdraw();   // withdraw from account
};
 // storing data from user
    void banking::get_record()
      {
	 cout<<"Enter Account No: ";
	 cin>>ac_number;
	 cout<<"Enter the Name: ";
	 gets(cust_name);
	 cout<<"Enter the Account type(CS): ";
	 cin>>ac_type;
	 cout<<"Enter the Amount: ";
	 cin>>amount;
      }
     // return amount a specific customer
     int banking::re_amount()
     {
      return(amount);
     }
// using friend function to displaying customer record so not need to :: operator for defination
    void show_record(banking obj)
    {
       // obj can access private member of same class
       cout<<"Account No : "<<obj.ac_number<<"n";
       cout<<"Name : ";puts(obj.cust_name);
       cout<<"Account Type : "<<obj.ac_type<<"n";
       cout<<"Amount : "<<obj.amount<<"n";
    }
   // return account a customer
   int banking::re_account()
   {
      return(ac_number);
   }
  int banking::deposit()
  {
     int d;
     cout<<"Enter the ammount to be deposit: ";
     cin>>d;
     amount = amount+d;
     return amount;    // return total depsit in account
  }
  int banking::withdraw()
  {
     int w;
     if(amount<500)
     {
      cout<<endl;
      cout<<"Sorry! Insuficient Balance transection not available";}else{
      cout<<"nEnter the ammount to be withdraw: n";
      cin>>w;
      amount = amount-w;
      cout<<"amount successfully withdraw";
     }
     return amount; // return wiithdraw amount
    }
// starting main function
int main()
{
     
     banking x[6];      //that means we can store 6 customer at a time.
     int ch,count,account,amount;
  do{
	start:
	cout<<"nnntttt****BANKING****nn";
	cout<<"tttt1.CREATE ACCOUNTnn";
	cout<<"tttt2.DEPOSITnn";
	cout<<"tttt3.WITHDRAWnn";
	cout<<"tttt4.DISPLAY ALL ACCOUNTnn";
	cout<<"tttt5.SEARCHnn";
	cout<<"tttt0.EXITnnnn";
	int n=0;
	while(n<80)
	{
	 cout<<"_";n++;  // printing a line
	}
	cout<<endl;
	cout<<"tttttEnter Your Choice: ";
	cin>>ch;
	switch(ch)
	{
	case 1: 
		int cust;
		cout<<"How Many Customer Record you want to Store: ";
		cin>>cust;
		for(count=0;count<cust;count++)
		{
		  cout<<count+1<<". ACCOUNTn";
		  x[count].get_record();  // get_record function calling
		  cout<<"nn";
		  cout<<"Account Created Successfully";
		  
		}
		break;
	case 2: 
		int true=0;
		cout<<"nEnter the Account No:";
		cin>>account;
		for(count=0;count<cust;count++)
		{
		 if(account==x[count].re_account())
		 {
		   x[count].deposit(); // deposit function calling
		   cout<<"Amount Successfully Deposit";
		  
		   true=1;
		 }
		}
		if(!true)
		{
		  cout<<"Account Not Found";
		
		}
		break;
      case 3:  
		int right=0;
		cout<<"nEnter the account No:";
		cin>>account;
		for(count=0;count<cust;count++)
		{
		 if(account==x[count].re_account())   // check account match or not
		 {
		   x[count].withdraw();
		   
		   right=1;
		 }
		}
		if(!right)
		{
		 cout<<"Account Not Found";
		
		}
		break;
      case 4:  
		int a;
		cout<<"tALL ACCOUNT DISPLAY:n";
		cout<<"==================================n";
		for(count=0;count<cust;count++)
		{
		 if(x[count].re_account()==0)
		    return;
		 cout<<count+1<<". ACCOUNTn";
		 cout<<"--------------------------------------n";
		 show_record(x[count]);   // display all account record
		 cout<<"=====================================n";
		
		}
		
		break;
      case 5:  
		int search,correct=0;
		cout<<"nEnter account No. to be search: ";
		cin>>search;
		for(count=0;count<cust;count++)
		{
		 if(search==x[count].re_account())
		 {
		   cout<<endl<<count+1<<". ACCOUNTn";
		   show_record(x[count]);   // display search account detail
		   correct=1;
		 
		 }
		}
		if(!correct)  {
		   cout<<"nThis Acount Not Available....Try Again.";
		   
		   goto start;
			      }
		   break;
      case 0:  exit(0);
	      break;
      default: cout<<"Invalid Choice";
		
		goto start;
	}
  }while(ch!=0);
}