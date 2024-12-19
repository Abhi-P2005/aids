#include<iostream>
#include<fstream>
using namespace std;
class employee
 {
 	public:
 	int id,salary;
 	char name[10];
	
		void read()
		{
			cout<<"Enter the name";
			cin>>name;
			cout<<"\n Enter the id";
			cin>>id;
			cout<<"\n Enter the salary";
			cin>>salary;
		}
		void display()
		{
			cout<<"\n Name of employee="<<name;
			cout<<"\n id of employee="<<id;
			cout<<"\n Salary of employee="<<salary;
			
		}
 		
 };
 int main()
 {
 	employee e;
 	ofstream fout;
 	ifstream fin;
 	int i,n,flag,key,ch;
 	char choice;
 	do
 	{
 		cout<<"\n 1.write \n2.append \n3.read \n4.search";
 		cout<<"\n enter your choice";
 		cin>>ch;
 		switch(ch)
 		{
 			case 1:fout.open("a.txt",ios::out);
 			cout<<"\n how many employee data";
 			cin>>n;
 			for(i=0;i<n;i++)
 			{
 				e.read();
 				fout.write((char*)&e,sizeof e);
			 }
			 fout.close();
			 break;
			 case 2:fout.open("a.txt",ios::app);
			 e.read();
			 fout.write((char*)&e,sizeof e);
			 fout.close();
			 break;
			 case 3:fin.open("a.txt");
			 while((fin.read((char*)&e,sizeof e)))
			 {
			 	e.display();
			 }
			 fin.close();
			 break;
			 case 4:
			 cout<<"\n enter the id to search";
			 cin>>key;
			 flag=0;
			 fin.open("a.txt");
			 while(fin)
			 {
			 	fin.read((char*)&e,sizeof e);
			 	if(e.id==key)
			 	{
			 		cout<<"\n id found";
			 		e.display();
			 		flag=1;
			 		break;
				 }
			 }
			 if(flag==0)
			 {
			 	cout<<"\n id not found";
			 }
			 fin.close();
			 break;
		 }
		 cout<<"\n do u want to continue(y/n)";
		 cin>>choice;
	 }while(choice=='y');
	 return 0;
 }
