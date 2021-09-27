#include<bits/stdc++.h>
using namespace std;

int main(){
int i,j ,n,a,b,adj[100][100];

cout<<"enter size of matrix(3x3): ";
cin>>n;

for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++){
	adj[i][j]=0;
    }
}
while(1){
cout<<" Enter connected vertex: ";
cin>>a;
cin>>b;
if(a==0||b==0)
{
    break;
}
else
{
adj[a][b]=1;
adj[b][a]=1;
}
}

cout<<".................."<<endl;
cout<<":Adjacent Matrix :"<<endl;
cout<<".................."<<endl;

for(i=1;i<=n;i++)
{
    for( j=1;j<=n;j++){
	cout<<adj[i][j]<<" ";
}
	cout<<endl;
}

cout<<endl;
cout<<endl;

cout<<".................."<<endl;
cout<<":Adjacent list   :"<<endl;
cout<<".................."<<endl;

for(i=1;i<=n;i++)
{
cout<<i<<" ->";
for(int j=1;j<=n;j++){
	if(adj[i][j]==1)
	cout<<j<<"->";
	}
	cout<<"NULL"<<endl;
	}


}
