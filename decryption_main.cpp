#include<iostream>
#include<fstream>
using namespace std;
void decrypt(string s,int key);
int findkey(string s);
string key1(string s);
int main()
{
        string s;
        cout<<"Enter a string to decrypt:";
		getline(cin,s);
		cout<<"The key use here is:";
		int key=findkey(key1(s));
		cout<<key;
		cout<<"\nThe decryptes string is:";
		decrypt(s,key);
		        
}

void decrypt(string s,int key)
{
	string decrypted_string="";

		decrypted_string="";
		int todecrement=key;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==' ')
			{
			    todecrement-=2;
		      	cout<<" ";
		      	decrypted_string+=" ";
			}
			else
			{
				int c=s[i];
				if(c>=65 && c<=90)
				{		c+=todecrement;
						if(c>90) { c%=90; c+=64;}
						else if(c<65){ c=91-(65%c) ;}
						
				}
				else if((c>=97 && c<=122))
				{
					c+=todecrement;
					if(c>122) { c%=122; c+=96;}
					else if(c<97){ c=123-(97%c) ;}
					
				}
				char out_char=c;	
				decrypted_string+=out_char;	
			}
		}
		
		cout<<endl<<decrypted_string<<endl;

}


int findkey(string s)
{
	string decrypted_string="";
	int key=0;
	for(int i=-1;i>=-9;i--)
	{
		decrypted_string="";
		int todecrement=i;
		for(int i=0;i<s.size();i++)
		{
		
				int c=s[i];
				if(c>=65 && c<=90)
				{		c+=todecrement;
						if(c>90) { c%=90; c+=64;}
						else if(c<65){ c=91-(65%c) ;}
						
				}
				else if((c>=97 && c<=122))
				{
					c+=todecrement;
					if(c>122) { c%=122; c+=96;}
					else if(c<97){ c=123-(97%c) ;}
					
				}
				char out_char=c;	
				decrypted_string+=out_char;	
			
		}
		
			fstream fs;
        	fs.open("dictionary.txt",ios::in);
        	string word;
        	
		while(fs>>word)
		{
			if(word==decrypted_string)
			{
				
				key=i;
				break;
			}
			
		}
		
   }
	return key;
}

string key1(string s)
{
	string j="";
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==' ')
		break;
	    else j=j+s[i];
	}
	return j;
}
