#include<iostream>
#include<string>
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

class Heterogeneous:public Methodology
{
	
public:
	
	string getUnit()
	{
		return "Function And Class";
	}
	string getParadigm()
	{
		return "Procedural And ObjectOriented";
	}

};
class ProgLang
{
protected:
	Methodology *m1;
public:
	ProgLang():m1(NULL)
	{}
	virtual ~ProgLang()
	{}
	virtual string getUnit()
	{
		if(m1!=NULL)
			return m1->getUnit();
	}
	
	virtual string getParadigm()
	{
		if(m1!=NULL)
			return m1->getParadigm();
	}

	virtual string getName()=0;
};


class LangC:public ProgLang
{
	
public:
	LangC()
	{
		m1=new Procedural;
	}
	~LangC()
	{
		delete m1;
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
		m1=new Procedural;
	}

	~LangCobol()
	{
		delete m1;
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
		m1=new ObjectOriented;
	}
	~LangCSharp()
	{
		delete m1;
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
		m1=new ObjectOriented;
	}
	~LangJava()
	{
		delete m1;
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
		m1=new Heterogeneous;
	}

	~LangCPP()
	{
		delete m1;
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
