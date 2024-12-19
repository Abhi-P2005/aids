#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
class student
{
	string name,dob;
	string phone;
	public:
	int r;
		void read()
		{
			cout<<"\nEnter name of student:";
			cin>>name;
			cout<<"\nEnter Roll number of student:";
			cin>>r;
			cout<<"\nEnter Date of Birth of student:";
			cin>>dob;
			cout<<"\nEnter Phone number:\n";
			cin>>phone;
		}
		
		void display()
		{
			cout<<"Name of student:"<<name<<endl;
			cout<<"\nRoll number of student:"<<r<<endl;
			cout<<"\nDate of birth of student:"<<dob<<endl;
			cout<<"\nPhone number of student:"<<phone<<endl;
		}
		
		bool operator==(const student &s)
		{
			return(r==s.r);	
		}	
};

void insert(vector<student> &v)
{
	student ob;
	ob.read();
	v.push_back(ob);
}

void show(vector<student> v)
{
	vector <student>::iterator itr;
	for(itr=v.begin();itr!=v.end();itr++)
	{
		itr->display();
	}
}

void search(vector<student> v)
{
	student ob;
	cout<<"Enter the Roll no of student you want to search:-";
	cin>>ob.r;
	vector<student>::iterator itr;
	itr=find(v.begin(),v.end(),ob);
	if(itr==v.end())
	{
		cout<<"Record Not found";
	}
	else
	{
		cout<<"Record is found";
		itr->display();
	}
}

void del(vector<student> &v)
{
	student ob;
	cout<<"Enter the roll no you want to delete";
	cin>>ob.r;
	vector<student>::iterator itr;
	itr=find(v.begin(),v.end(),ob);
	if(itr==v.end())
	{
		cout<<"Not found";
	}
	else
	{
		v.erase(itr);
		cout<<"Information is deleted";
	}
}

bool check1(student &s1,student &s2)
{
	return(s1.r<s2.r);
}

void sorting(vector<student> &v)
{
	sort(v.begin(),v.end(),check1);
	cout<<"It is sorted...";
}

int main(){
	vector<student> v;
	int ch;
	char choice;
	do{
		cout<<"1.Create\n2.Display\n3.Insert\n4.Search\n5.delete\n6.Sorting"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				int n,i;
				cout<<"Enter how many students you want to enter the Data:";
				cin>>n;
				for(i=0;i<n;i++){
					insert(v);
				}
				break;
			case 2:
				show(v);
				break;
			case 3:
				insert(v);
				break;
			case 4:
				search(v);
				break;
			case 5:
				del(v);//delete
				break;
			case 6:
				sorting(v);
				break;
		}
		cout<<"Do you want to continue(y/n):";
		cin>>choice;
	}while(choice=='y');
	return 0;
}

