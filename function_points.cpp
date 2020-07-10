#include<bits/stdc++.h>
#include<chrono>
#define vpspsi vector<pair<string,pair<string,int>>>
#define vbpii vector<bool,pair<int,int>>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define vb vector<bool>
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define make_pair mp
#define f first
#define s second

using namespace std;
using namespace std::chrono;

string numtostring(int num)
{
	if(num == 0)
	{
		return "EI";
	}
	if(num == 1)
	{
		return "EO";
	}
	if(num == 2)
	{
		return "EQ";
	}
	if(num == 3)
	{
		return "ILF";
	}
	if(num == 4)
	{
		return "EIF";
	}
}
int ufp()
{
	
	int ufp[5][3]; // ufp[i][j] : [i = function units], [j = complexity]
	
	cout<<" complexities : "<<endl;
	cout<<"low -> 0"<<endl<<"avg -> 1"<<endl<<"high -> 2"<<endl;
	
	// external input (EI) - 0
	
	ufp[0][0] = 3; // low
	ufp[0][1] = 4; // avg
	ufp[0][2] = 6; // high
	
	// external output (EO) - 1
	
	ufp[1][0] = 4; // low
	ufp[1][1] = 5; // avg
	ufp[1][2] = 7; // high
	
	// external enquiries (EQ) - 2
	
	ufp[2][0] = 3; //low
	ufp[2][1] = 4; //avg
	ufp[2][2] = 6; //hight
	
	// internal logical files (ILF) - 3
	
	ufp[3][0] = 7; // low
	ufp[3][1] = 10; // avg
	ufp[3][2] = 15; // high
	
	// external interface files (EIF) - 4
	
	ufp[4][0] = 5; // low
	ufp[4][1] = 7; // avg
	ufp[4][2] = 10; // high
	
	int ans = 0;
	bool issimple;
	cout<<"ufp simple?";
	cin>>issimple;
	cout<<endl;
	if(issimple){
    for(int i=0;i<5;i++)
	{
	   int comp,users;
	   cout<<"enter users and comlexity for : "<<numtostring(i)<<" : ";
	   cin>>users>>comp; 
	   cout<<endl;
	   
	   ans += users * ufp[i][comp]; 
	} 
}
	else
	{
		for(int i=0;i<5;i++)
	  {
	   int comp,users;
	   
	   cout<<"how many "<<numtostring(i)<<"? : ";
	   int x;
	   cin>>x;
	   for(int k=0;k<x;k++)
	   {
	     cout<<"enter users and comlexity for : "<<numtostring(i)<<" : ";
	     cin>>users>>comp; 
	     cout<<endl;
		 
	     ans += users * ufp[i][comp]; 
	     
	   }
      } 

   }  


	return ans;	
}
float caf()
{
	float ans = 0;
	
	cout<<"For CAF : "<<endl<<"no influence - 0"<<endl<<"incidental - 1"<<endl<<"moderate - 2"<<endl<<"average - 3"<<endl<<"significant - 4"<<endl<<"essential - 5"<<endl;

    bool sameforall;
    cout<<"is same for all?";
    cin>>sameforall;
    cout<<endl;
    
    if(!sameforall)
    {
    	for(int i=0;i<14;i++)
    	{
    		int complexity;
    		cout<<"enter complexity for caf, for "<<i<<" ";
    		cin>>complexity;
    		
    		ans += complexity;
		}
	}
	else
	{
		int val;
		cout<<"enter complexity for caf :";
		cin>>val;
		
		ans = 14*val;
	}
	
	ans = 0.65 + (0.01 * ans);
	return ans;
}    
int main()
{
   float UFP =(float) ufp();
   
   cout<<"caf given? : ";
   bool givencaf;
   cin>>givencaf;
   cout<<endl;
   
   float CAF;
   if(!givencaf){
      CAF = caf();
   }
   else
   {
   	cout<<"enter caf : ";
   	cin>>CAF;
   } 
	
	cout<<"ufp :"<<UFP<<endl<<"caf :"<<CAF<<endl;
	cout<<UFP*CAF;
}

   

