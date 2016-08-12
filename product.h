#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "trace.h"

// 为了使用单来源调用提供的接口处理
class absProductManager
{
protected:
	bool isPermittedCreate;
	absProductManager()
		:isPermittedCreate(false)
	{}
public:
	virtual bool isCreateProduct()
	{
		return isPermittedCreate;
	}
};

class product
{
protected:
	string name;
	bool canChanged;
	product(string _name)
	:name(_name)
	,canChanged(true)
	{
		Trace("");
	}

public:
	static product* getProduct(absProductManager *m,string _name);
public:
	~product()
	{
		Trace("");
	}
	product(product& p)
	{
		Trace("clone");
		name = p.getName();
		canChanged = p.canChanged;
	}
	string getName()
	{
		return name;
	}
	void setName(string _name)
	{
		if(canChanged)
		{
			name = _name;
		}
	}
};

product* product::getProduct(absProductManager *m,string _name)
{
	Trace("");
	//允许创建产品
	if(m->isCreateProduct())
	{	
		return new product(_name);
	}
	return NULL;
}

class ProductManager:public absProductManager
{
public:
	ProductManager()
	{
		Trace("");
	}

	product* createProduct(string _name)
	{
		isPermittedCreate = true;
		return product::getProduct(this,_name);
	}
	void abndonProduct(product* &p)
	{
		Trace("");
		p->~product();
		p = NULL;
	}

	void editProduct(product*p,string _name)
	{
		p->setName(_name);
	}
	bool isCreateProduct()
	{
		return isPermittedCreate;
	}

	product* clone(product* p)
	{
		return new product(*p);
	}

	~ProductManager()
	{
		Trace("");
	}
};

int testproduct()
{
	ProductManager manager;
	product* pro = manager.createProduct("lianglihui");
	product* pro1 = manager.clone(pro);
	manager.editProduct(pro1,"hanyi");
	cout << (pro->getName())<<endl;
	cout << (pro1->getName())<<endl;
	manager.abndonProduct(pro1);
	cout << pro1<<endl;
}