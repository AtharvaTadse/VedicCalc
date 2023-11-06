
#include <bits/stdc++.h> 
using namespace std;
class Num
{
	public:
	string value;
	bool decim;
	Num(void)
	{
		value="";
		
	}
	bool isNum(string num)
	{
		bool hasdecim=false;
		for(int i=0;i<num.size();i++)
		{
			if(num[i]=='.')
			{
				if(!hasdecim)
				hasdecim=true;
				else 
				return false;
			}
			else if(num[i]<48 || num[i]>57)
			{
				return false;
			}
			
		}
		if(hasdecim)
		decim=true;
		return true;
	}
	void print_val()
	{
		if(value!="")
		cout<<value<<endl;
		else cout<<"Error:No num defined"<<endl;
	}
	void LeadingZeroes()
	{
		bool Firstnotzero=false;
		string s="";
		for(int i=0;i<value.size();i++)
		{
			if(!Firstnotzero)
			{
				if(value[i]!='0')
				{
					Firstnotzero=true;
					s+=value[i];
				}
			}
			else{
				s+=value[i];
			}
		}
		value=s;
		return;
	}
	void Complement()
	{
		string s;
		if(value=="")
		{
			cout<<"No value assigned yet"<<endl;
			return;
		}
		else{
			s=value;
		}
		int j=s.size()-1;
	while(j>=0) {
		if(s[j]=='0') {
			j--;
		} else break;
	}
	
	for(int i=0; i<s.size(); i++) {
		if(i==j) {
			string a="";
			a+=s[i];
			int b;
			b=stoi(a);


			cout<<10-b;
		} else if(i>j) {
			cout<<0;
		} else {
			if(i==s.size()-1) {
				string a="";
				a+=s[i];
				int b;
				b=stoi(a);
				cout<<10-b;
			} else
				cout<<57-s[i];
		}
	}
	}
	void add_val(vector<int> &list){
		value="";
		int i=1;
	    while(i>0 && i<list.size())
	    {
	    	if(list[i]>=10)
	    	{
	    		list[i-1]+=list[i]/10;
	    		list[i]=list[i]%10;
	    		i--;
			}
			else i++;
		}
	
	
	
	for(auto a: list)
	{
		vector<int> digits;
		if(a==0)
		digits.push_back(a);
		else
		{
			int a1=a;
			while(a1>0)
			{
				digits.push_back(a1%10);
				a1/=10;
			}
		}
		reverse(digits.begin(), digits.end());
		for(auto d: digits)
		value+=char(d+48);
	}
	
}
	Num(string value1)
	{
		if(isNum(value1))
		{
			value=value1;
		}
		else cout<<"Error in number definition"<<endl;
	}
	
	void add(Num a, Num b)
	{
		
		int maxm= max(a.value.size(), b.value.size());
		vector<int> lista(maxm, 0);
		vector<int> listb(maxm, 0);
		int j=maxm-1;
		for(int i=a.value.size()-1;i>=0;i--)
		{
			lista[j]=a.value[i]-48;
			j--;
		}
		j=maxm-1;
		for(int i=b.value.size()-1;i>=0;i--)
		{
			listb[j]=b.value[i]-48;
			j--;
		}
		for(int i=0;i<maxm;i++)
		{
			if(i==0)
			{
				lista[i]+=listb[i];
			}
			else{
				lista[i]+=listb[i];
				lista[i-1]+=lista[i]/10;
				lista[i]=lista[i]%10;
			}
		}
		
		cout<<endl;
		add_val(lista);
		
	}
	void subtract(Num a, Num b)
	{
	
	
		int maxm= max(a.value.size(), b.value.size());
		vector<int> lista(maxm, 0);
		vector<int> listb(maxm, 0);
		int j=maxm-1;
		for(int i=a.value.size()-1;i>=0;i--)
		{
			lista[j]=a.value[i]-48;
			j--;
		}
		j=maxm-1;
		for(int i=b.value.size()-1;i>=0;i--)
		{
			listb[j]=b.value[i]-48;
			j--;
		}
		int insub=false;
		for(int i=maxm-1;i>=0;i--)
		{
			if(!insub)
			{
				if(lista[i]>=listb[i])
				{
					lista[i]-=listb[i];
				}
				else {
					int complement=listb[i]-lista[i];
					lista[i]=10-complement;
					insub=true;
				}
			}
			else
			{
				if(lista[i]>listb[i])
				{
					lista[i]=lista[i]-listb[i]-1;
					insub=false;
				}
				else if(lista[i]==listb[i])
				{
					lista[i]=9;
				}
				else {
					int complement=listb[i]-lista[i];
					lista[i]=9-complement;
				}
			}
		}
		add_val(lista);
	}
	void mul(Num a, Num b)
	{
			int maxm= max(a.value.size(), b.value.size());
		vector<int> lista(maxm, 0);
		vector<int> listb(maxm, 0);
		vector<int> listc;
		int j=maxm-1;
		for(int i=a.value.size()-1;i>=0;i--)
		{
			lista[j]=a.value[i]-48;
			j--;
		}
		j=maxm-1;
		for(int i=b.value.size()-1;i>=0;i--)
		{
			listb[j]=b.value[i]-48;
			j--;
		}
		int carry=0;
		int sum;
		for(int i=lista.size()-1;i>=0;i--)
		{
			int left=i;
			sum=0;
			for(int right=lista.size()-1;right>=i;right--)
			{
				
				sum+=listb[right]*lista[left];
				left++;
			}
			sum+=carry;
		//	cout<<sum<<endl;
			listc.push_back(sum%10);
			carry=sum/10;
		//	cout<<carry<<endl;
		}
		
		
		for(int i=lista.size()-2;i>=0;i--)
		{
			sum=0;
			int left=0;
			
			for(int right=i;right>=0;right--)
			{
				sum+=listb[right]*lista[left];
				left++;
			}
			sum+=carry;
			//cout<<sum<<endl;
			
			carry=sum/10;
			listc.push_back(sum%10);
			//cout<<carry<<endl;
		}
		while(carry>0){
		
		listc.push_back(carry%10);
		carry/=10;
	}
		reverse(listc.begin(), listc.end());
		add_val(listc);
		LeadingZeroes();
		return;
	}
    Num operator+(Num &other)
	{
		Num temp=*this;
		
		temp.add(temp, other);
		return temp;
		
		
	}

};
int main() {
	
	/*string s;
	cin>>s;
	Num a(s);
	cout<<"The number you entered is:"<<endl;
	a.print_val();
	cout<<"The complement number:"<<endl;
	a.Complement();
	cout<<endl;
	string s2;
	cin>>s2;
	Num b(s2);
	cout<<"The number you have entered is:"<<endl; 
	b.print_val();
	Num c(s2);
	c=a+b;
	cout<<"The addition of the two numbers is:"<<endl;
	c.print_val();
	cout<<"One more:"<<endl;
	string s3;
	cin>>s3;
	Num d(s3);
	Num e=a+b+d;
	cout<<"Sum:"<<endl;
	e.print_val();*/
	string s, s2;
	cin>>s>>s2;
	Num a(s);
	Num b(s2);
	a.mul(a,b);
	a.print_val();
	/*long long int a,b;
	cin>>a>>b;
	cout<<a+b<<endl;*/
	
	return 0;
}