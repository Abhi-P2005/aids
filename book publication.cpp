# include<iostream>
#include<string.h>

using namespace std;
class publication                
 {
 	protected:
 	char title[100];
 	float price;
 	public: 
 	void read()
 	{
  		cout << "\nEnter Title of the Publication : ";
 		cin>>title;
 		cout << "Enter Price of Publication : ";
		 cin >> price;
 	}
 	void display()
 	{
 		cout << "\nTitle of Publication : " << title;
 		cout << "\nPublication Price : " << price;
 	}
 };
 class book : public publication  
 {
 	public:
 	int page_count;
 	public:
	void read_book()
	 {
      	read();
      	cout<<"Enter page count  :";
      	cin>>page_count;
      	try
      	{
      		if(page_count<=0)
      		throw 1;
		 }catch(int i)
		{
		strcpy(title,"0");
		price=0;
		page_count=0;
		}
 	}
 	void display_book()
 	{
      display();
      cout << "\nPage Count : " <<page_count;
 	}
 };
 class tape : public publication     
 {
 	public:
	float play_time;
 	public:
	void read_tape()
 	{
      	read();
      	cout<<"Enter play time:";
      	cin>>play_time;
      	try
      	{
      		if(play_time<=0)
      		throw 1;
		 }catch(int i)
		{
		strcpy(title,"0");
		price=0;
		play_time=0;
		}
	}
	void display_tape()
 	{
     	 display();
     	 cout << "\nPlay Time : " <<play_time << " min";
 	}
 };
 
int main()
 {
 book b1[10];            // object of class book
 tape t1[10];            // object of class tape
 int ch, b_count = 0, t_count = 0;
 do
 {
 cout << "\n* * * * * PUBLICATION DATABASE SYSTEM * * * * *";
 cout << "\n--------------------MENU-----------------------";
 cout << "\n1. Add Information to Books";
 cout << "\n2. Add Information to Tapes";
 cout << "\n3. Display Books Information";
 cout << "\n4. Display Tapes Information";
 cout << "\n5. Exit";
 cout << "\n\nEnter your choice : ";
 cin >> ch;
 switch(ch)
 {
 case 1:
 b1[b_count].read_book();
b_count ++;
break;

 case 2:
 t1[t_count].read_tape();
 t_count ++;
 break;

 case 3:
 cout << "\n* * * * BOOK PUBLICATION DATABASE SYSTEM * * * *";
 for (int j=0;j < b_count;j++)
 {
   b1[j].display_book();
 }
 break;

 case 4:
 cout << "\n* * * * TAPE PUBLICATION DATABASE SYSTEM * * * *";
 for (int j=0;j < t_count;j++)
 {
   t1[j].display_tape();
 }
 break;

 case 5:
 exit(0);
 }
 }while (ch != 5);
 return 0;
 }
