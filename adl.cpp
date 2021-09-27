#include<bits/stdc++.h>
#include<list>

using namespace std;

int main(){
int i,n,a,b;
int count2=0,count1=0,count=0;
list<int> adj[100];
list<int>::iterator j;
cout<<"enter size of Vartex(3x3): ";
cin>>n;


while(1){
cout<<" Enter connected Edge: ";
cin>>a;
cin>>b;
if(a==0&&b==0)
{
    break;
}
else if(b>n || a>n || b<1 || a<1)
{
	cout<<"Invalid Input."<<endl;
}
else
{
adj[a].push_back(b);
adj[b].push_back(a);
}


count1++;
}


for(i=1;i<=n;i++)
{
	cout<<"IN degree of "<<i<<": "<<endl
    for( j=adj[i].begin(); j!=adj[i].end(); j++)
    {
	count2++;
    }
    cout<<count2<<endl;

	if(count1==count2)
	{
	count++;	
	}
	count2=0;
}


if(count==1)
{
cout<<"Universal Sink";
}
else
cout<<"Not Universal Sink";


}

