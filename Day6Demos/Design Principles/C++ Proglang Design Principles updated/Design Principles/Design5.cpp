#include<iostream>
#include<string>
using namespace std;

class ProgLang
{
public:
	virtual string getUnit()=0;
	virtual string getParadigm()=0;
	virtual string getName()=0;
	
};

class Procedural:public ProgLang
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
class ObjectOriented:public ProgLang
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

class LangC:public Procedural
{
public:
	string getName()
	{
		return "C";
	}
};

class LangCobol:public Procedural
{
public:
	string getName()
	{
		return "Cobol";
	}
};

class LangCSharp:public ObjectOriented
{
public:
	string getName()
	{
		return "C#";
	}
};
class LangJava:public ObjectOriented
{
public:
	string getName()
	{
		return "Java";
	}
};


class Heterogeneous:public ProgLang
{
	Procedural *p;
	ObjectOriented *o;
	class ProcImpl:public Procedural
	{
	public:
		string getName()
		{
			return "";
		}
	};

	class OOImpl:public ObjectOriented
	{
	public:
		string getName()
		{
			return "";
		}
	};
public:
	Heterogeneous():p(new ProcImpl),o(new OOImpl)
	{
	}
	
	string getUnit()
	{
		return p->getUnit()+" And "+o->getUnit();
	}
	string getParadigm()
	{
		return p->getParadigm()+" And "+o->getParadigm();
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
