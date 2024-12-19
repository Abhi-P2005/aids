#include<iostream>
#include<map>
#include<string>
#include<iterator>
using namespace std;
int main()
{
	int n,p;
	string state;
	map<string,int>mymap;
	cout<<"\nhow many states u want to stored :";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nenter the name of the state:";
		cin>>state;
		cout<<"\nenter the population of state:";
		cin>>p;
		mymap.insert(make_pair(state,p));
	}
	map<string,int>::iterator itr;
	cout<<"\nstate\t\tPopulation"<<endl;
	for(itr=mymap.begin();itr!=mymap.end();itr++)
	{
		cout<<(*itr).first<<"\t\t"<<(*itr).second<<endl;
	}
	cout<<"\nenter state to be searched:";
	cin>>state;
	itr=mymap.find(state);
	if(itr==mymap.end())
	{
		cout<<"state not found";
	}
	else{
		cout<<"population of"<<state<<"is:"<<(*itr).second;
	}
	return 0;
}

