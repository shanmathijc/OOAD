#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Methodology
{
public:
	virtual string getUnit()=0;
	virtual string getParadigm()=0;
};

class Procedural:public Methodology
{
public:
	string getUnit()
	{
		return "Function";
	}
	string getParadigm()
	{
		return "Procedural";
	}
};
class ObjectOriented:public Methodology
{
public:
	string getUnit()
	{
		return "Class";
	}
	string getParadigm()
	{
		return "ObjectOriented";
	}
};

class ProgLang
{
protected:
	vector<Methodology *>v;
public:
	
	virtual ~ProgLang()
	{}
	virtual string getUnit()
	{
		string s="";
		for(int i=0;i<v.size();i++)
			s += v[i]->getUnit();
		return s;
	}
	
	virtual string getParadigm()
	{
		string s="";
		for(int i=0;i<v.size();i++)
			s += v[i]->getParadigm();
		return s;
	}

	virtual string getName()=0;
};


class LangC:public ProgLang
{
	
public:
	LangC()
	{
		v.push_back(new Procedural);
	}
	~LangC()
	{
		for(int i=0;i<v.size();i++)
			delete v[i];
		v.clear();
	}
	string getName()
	{
		return "C";
	}
};

class LangCobol:public ProgLang
{

public:
	LangCobol()
	{
		v.push_back(new Procedural);
	}
	~LangCobol()
	{
		for(int i=0;i<v.size();i++)
			delete v[i];
		v.clear();
	}
	
	
	string getName()
	{
		return "Cobol";
	}
};

class LangCSharp:public ProgLang
{

public:
	LangCSharp()
	{
		v.push_back(new ObjectOriented);
	}
	~LangCSharp()
	{
		for(int i=0;i<v.size();i++)
			delete v[i];
		v.clear();
	}
	
	string getName()
	{
		return "C#";
	}
};
class LangJava:public ProgLang
{

public:
	LangJava()
	{
		v.push_back(new ObjectOriented);
	}
	~LangJava()
	{
		for(int i=0;i<v.size();i++)
			delete v[i];
		v.clear();
	}
	
	string getName()
	{
		return "Java";
	}
};


class LangCPP:public ProgLang
{
public:
	LangCPP()
	{
		v.push_back(new Procedural);
		v.push_back(new ObjectOriented);
	}
	~LangCPP()
	{
		for(int i=0;i<v.size();i++)
			delete v[i];
		v.clear();
	}
	string getName()
	{
		return "CPP";
	}
};

void main()
{
	int choice;
	ProgLang *p = NULL;
	do
	{
		cout<<"1:LangC"<<endl;
		cout<<"2:LangCSharp"<<endl;
		cout<<"3:LangJava"<<endl;
		cout<<"4:LangCobol"<<endl;
		cout<<"5:LangCPP"<<endl;
		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			p = new LangC;
			break;
		case 2:
			p=new LangCSharp;
			break;
		case 3:
			p=new LangJava;
			break;
		case 4:
			p = new LangCobol;
			break;
		case 5:
			p = new LangCPP;
			break;
		}
		cout<<"Unit:"<<p->getUnit()<<endl;
		cout<<"Paradigm:"<<p->getParadigm()<<endl;
		cout<<"Name:"<<p->getName()<<endl;
        delete p;
		cout<<"enter 1 to continue"<<endl;
		cin>>choice;
	}while(choice==1);
}
