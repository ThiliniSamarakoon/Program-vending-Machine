#include<iostream>
using namespace std;
//HW6

//The vending machine contains  4 products as Product A,Product B,Product C and Product D
//Assume that the customer always input legal coins of 1,2,5 and 10   
//There are four denomination reserves for each denomination and the maximum size of each reserve is 150 coins and 100 of each coin are preloaded
//There are four overflow bins for each coin 1, 2, 5 and 10 and they are limitless

int main(){
	int prdA=50, prdB=80, prdC=40, prdD=70;			//prices of the products
	
	int r1=100, r2=100, r5=100, r10=100;		//defining  number of coins
	
	int excr1=0, excr2=0, excr5=0, excr10=0;		//the number of coins in each overflow bin
	
	int tempr1=0, tempr2=0, tempr5=0, tempr10=0;		//variables that shows number of coins to pay customer 
	
	int tempb1=0, tempb2=0, tempb5=0, tempb10=0;		//variables that used to identify  the balance should give to the customer
	
	int password=0; 								//password can be used for terminate the process as owner's wish and the password is 123(default value is 0)
	
	int choice;
	
	cout<< "Product A : Enter 1" << endl;		//choice numbers for the 4 products are prdA=1, prdB=2, prdC=3, prdD=4
	cout<< "Product B : Enter 2" << endl;
	cout<< "Product C : Enter 3" << endl;
	cout<< "Product D : Enter 4" << endl;
	
	
	while(r1!=0 && r2!=0 && r5!=0 && r10!=0 ){
		cout<< "Welcome! Please enter a Product Number"<< endl;
		
		cout<< "======================================" << endl << endl;
	
	
	cout<< "Please enter a Product Number: ";
	cin>> choice;
	cout<<endl;
	
	while(!(choice>=1 && choice<=4)){
		cout<< "Invalid  Product Number, please select desired product again..."<<endl;
		cout<< "Product A : Enter 1" << endl;		//choice numbers for the 4 products are prdA=1, prdB=2, prdC=3, prdD=4
		cout<< "Product B : Enter 2" << endl;
		cout<< "Product C : Enter 3" << endl;
		cout<< "Product D : Enter 4" << endl;
		cout<<"Please enter a Product Number: ";
		
		cin.clear();
		cin.ignore();
		cin>> choice;
		cout<< endl;
		
		}
		
	int price=0;
	switch(choice){
		case 1 : price=prdA; cout <<  "The price of Product A is Rs.50" <<endl;break;
		case 2 : price=prdB; cout << "The price of Product B is Rs.80" << endl;break;
		case 3 : price=prdC; cout << "The price of Product C is Rs.40" << endl;break;
		case 4 : price=prdD; cout << "The price of Product D is Rs.70" << endl;
		
	}
	
	cout<<endl;
	
	int count=0, balance=0, payment=0;
	while(payment<price){
		if(count!=0){
			balance=price-payment;
			cout<< "Rs." << balance << " remain, so please insert remaining amount" << endl;
			
			
		}
		cout<< "Number of Rs.1 coins : ";
		cin>>tempr1;
		tempb1+=tempr1;
		cout<<"Number of Rs.2 coins: ";
		cin>> tempr2;
		tempb2+=tempr2;
		cout<< "Number of Rs.5 coins : ";
		cin>>tempr5;
		tempb5+=tempr5;
		cout<< "Number of Rs.10 coins : ";
		cin>>tempr10;
		tempb10+=tempr10;
		
		payment+=(tempr1*1+tempr2*2+tempr5*5+tempr10*10);		//calculate the total payment done
		
		r1+=tempr1;
		r2+=tempr2;
		r5+=tempr5;
		r10+=tempr10;
		
		tempr1=0, tempr2=0, tempr5=0, tempr10=0;
		count++;
		cout<<endl;
		
		}
		
		cout<<endl;
		
		bool remainchanges=1; 			//ask whether the balance can be paid or not
	
		balance=payment-price;
		int tempbalance=balance;
		tempr1=0, tempr2=0, tempr5=0, tempr10=0;
		
		tempr10=balance/10;
		if(r10<tempr10){
			tempr10=r10;
		}
		
		balance=balance-tempr10*10;
		
		tempr5=balance/5;
		if(r5<tempr5){
			tempr5=r5;
			
		}
		balance=balance-tempr5*5;
		
		tempr2=balance/2;
		if(r2<tempr2){
			tempr2=r2;
			
		}
		
		balance=balance=tempr2*2;
		
		tempr1=balance/1;
		if(r1<tempr1){
		remainchanges=0;
		tempr10=tempb10;
		tempr5=tempb5;
		tempr2=tempb2;
		tempr1=tempb1;
	}
	
	if(remainchanges){
		if(tempbalance==0){
			cout<< "Your balance is Rs. " << tempbalance << endl;
			
		}
		else{
			cout<< "Your balance is Rs. " << tempbalance << " Please collect your balance through the coin slot " << endl;
		}
	}else{
		cout<< "Out of change. Get back your Rs. " << payment << " through the coin slot"<<endl;
	}
		
		if(tempr10){
			cout<< "Rs.10: " << tempr10 <<endl;
			
		}
		if(tempr5){
			cout<< "Rs.5 : " <<tempr5 <<endl;
			
		}
		if(tempr2){
			cout<< "Rs.2 : " <<tempr2 <<endl;
		}
		
		if(tempr1){
			cout<<"Rs.1 : " << tempr1 <<endl;
		}
		
		cout<< endl<<endl;
		
		cout<< "Thank you and please come again..." << endl << endl;
		
		r1-=tempr1;
		r2-=tempr2;
		r5-=tempr5;
		r10-=tempr10;
		
		
		if(r1>150){
			excr1+=(r1-100);
			r1=100;
		}
		
		if(r2>150){
			excr2+=(r2-100);
			r2=100;
			
		if(r5>150){
			excr5+=(r5-100);
			r5=100;
		}	
		
		if(r10>150){
			excr10+=(r10-100);
			r10=100;
		}
		
		
	
		tempr1=0, tempr2=0, tempr5=0, tempr10=0;				//reinitialize variables with 0	
		tempb1=0, tempb2=0, tempb5=0, tempb10=0;	
		payment=0,balance=0;
		
		password=0;			//Owner's password is 123
		cout<< 	"Enter the password to terminate(Only people who have password)" <<endl;
		cout<< "If you are a customer enter 0 as the password" << endl;
		cout<< "password: ";
		cin>> password;	
	
		if(password==123){
			break;					//In here progress stop if password is correct
		}	
			
		cout<<endl <<endl;
	} 
	
	cout<< endl << endl;
			
	if(password!=123){
			cout<< "The machine is going out of change" << endl;
			cout<< "Please check the denomination reserves"<< endl << endl;
			
		}else{
			cout<< "Program is ended up by owner..." <<endl << endl;			//This happen when owner put correct password
		}	
		
		cout << "Coins in each denomination reserve " <<endl;				//Display the coins in each denomination
		cout << "===================================" << endl;
			
		cout << "Number of coins in Rs. 1 reserve : " << r1 << endl;			//Display coins in each denomination reserve after out of change or the process is terminate by the owner
		cout << "Number of coins in Rs. 2 reserve : " << r2 << endl;
		cout << "Number of coins in Rs. 5 reserve : " << r5 << endl;
		cout << "Number of coins in Rs. 10 reserve :  " << r10 << endl << endl;	
		
		cout << "Coins in each overflow bin" <<endl;							//Display coins in  each overflow bin after out of change or the process is terminate by the owner
		cout << "===========================" << endl;
		
		cout << "Number of Rs.1 coins in overflow bin : " << excr1 << endl;
		cout << "Number of Rs.2 coins in overflow bin : " << excr2 << endl;
		cout << "Number of Rs.5 coins in overflow bin : " << excr5 << endl;
		cout << "Number of Rs.10 coins in overflow bin : " << excr10 << endl << endl;
		
		
		
		
		}
	}
		
		
		
		
		
		
		
	
	
	
	
	
	
	
		
	
	


