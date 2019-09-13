#include<iostream>
#include<string>
using namespace std;

class Procedural
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
class ObjectOriented
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
	Procedural *p;
	ObjectOriented *o;
public:
	ProgLang():p(NULL),o(NULL)
	{}
	virtual ~ProgLang()
	{}
	string getUnit()
	{
		string s="";
		if(p!=NULL)
			s = p->getUnit();
		if(o!=NULL)
			s += o->getUnit();
		return s;
	}
	
	string getParadigm()
	{
		string s="";
		if(p!=NULL)
			s = p->getParadigm();
		if(o!=NULL)
			s += o->getParadigm();
		return s;
	}

	virtual string getName()=0;
};


class LangC:public ProgLang
{
	
public:
	LangC()
	{
		p=new Procedural;
	}
	~LangC()
	{
		delete p;
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
		p=new Procedural;
	}

	~LangCobol()
	{
		delete p;
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
		o=new ObjectOriented;
	}
	~LangCSharp()
	{
		delete o;
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
		o=new ObjectOriented;
	}
	~LangJava()
	{
		delete o;
	}
	
	string getName()
	{
		return "Java";
	}
};

class Heterogeneous:public ProgLang
{
public:
	Heterogeneous()
	{
		p=new Procedural;
		o=new ObjectOriented;
	}
};

class LangCPP:public Heterogeneous
{
public:
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
