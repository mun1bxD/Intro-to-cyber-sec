#include<iostream>
using namespace std;
int main(){
	
	string s;
	cout<<"Enter a Sentence to Encrypt:";
	getline(cin,s);
	int toincrement=9;
	//using for loop to take size of string
	for(int i=0;i<s.size();i++)
	{
		//using condition for making increment of two after space.
		if(s[i]==' ')
		{
			toincrement+=2;
	      	cout<<" ";
		}
		else
		{
			int c=s[i];
			if(c>=65 && c<=90){		
				c+=toincrement;
					if(c>90) {
					c%=90;
					c+=64;
				}
			}
			else if((c>=97 && c<=122)){
				c+=toincrement;			
					if(c>122) { 
					c%=122;
					c+=96;
				}
			}		
			char out_char=c;
			cout<<out_char;
		}
	}
	return 0;
}
