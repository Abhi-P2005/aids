#include<iostream>
#include<string.h>
using namespace std;
class student
{
	int r;
	string name;
	string clas ;
	string div;
	string dob;
	string bgr;
	string add ;
	string mob ;
	static int count;
	
	public:
		student()
		{
			r=2;
			name="abc";
			div="a";
			dob="17-06-2006";
			bgr="A+";
			mob="11234579999";
			add="abcd";
			count++	;	
		}
		student(student &s)
		{
			r=s.r;
			name=s.name;
			div=s.div;
			dob=s.dob;
			bgr=s.bgr;
			mob=s.mob;
			add=s.add;
			count++;
		}
		void read()
		{
			cout<<"\n enter r=";
			cin>>r;
			cout<<"\n enter name=";
			cin>>name;
			cout<<"\nenter div=";
			cin>>div;
			cout<<"\nenter dob=";
			cin>>dob;
			cout<<"\nenter bgr=";
			cin>>bgr;
			cout<<"\nenter mob=";
			cin>>mob;
			cout<<"\nenter add=";
			cin>>add;
		}
	
	
		
	    friend void display(student *p);
		
	  static void displaycount()
	  {
	    cout<<"\n no of student="<<count;
		cout<<"\n";	
	  }
	  ~student()
	  {
	  	cout<< this->name<<"is destroyed\n" ;
	  }
	   //friend void display(student *p);
};
int student :: count=0 ;
void display(student *p)

{
	
	cout<<"\n name="<<p->name;
			cout<<"\n roll no="<<p->r;
			cout<<"\n div="<<p->div;
			cout<<"\n address="<<p->add;
			cout<<"\n dob="<<p->dob;
			cout<<"\n mob="<<p->mob;
			cout<<"\n bg="<<p->bgr;
}
int main()
{
	
	student s1,s2(s1);
	int n,i;
	student *ptr[n];
	cout<<"\n enter how many student";
	cin>>n;
	for(i=0;i<n;i++)
	{
		ptr[i]=new student();
		ptr[i]-> read();
		
	}
	display(&s1);
	cout<<"\n";
	display(&s2);
	for(i=0;i<n;i++)
	{
	  display(ptr[i]);
	}
	student :: displaycount();
	for(i=0;i<n;i++)
	{
		delete ptr[i];
	}
	
	//s1.display();
	//s2.display();
	//s3.read();
	//s3.display();
	return 0;
}
