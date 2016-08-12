#pragma once
#include "trace.h"
// #include "productEvent.h"

struct eventCustomType
{
private:
	int value;
public:
	enum{
		READ = 1,
		WRITE = 2,
		EXIT = 3
		// EXCPTION = 4
	};
	eventCustomType(int _value)
	:value(_value)
	{}
public:
	int getValue()
	{
		return value;
	}
};


class eventCustomer
{
protected:
	std::vector<eventCustomType> customType;
public:
	eventCustomer(eventCustomType _type)
	{
		addCustomerType(_type);
	}

	void addCustomerType(eventCustomType _type)
	{
		customType.push_back(_type);
	}

	vector<eventCustomType> getCustomType()
	{
		return customType;
	}
	virtual void exec(productEvent* event)=0;
	virtual ~eventCustomer()
	{
		Trace("");
	}
};

class reader:public eventCustomer
{
public:
	reader()
	:eventCustomer(eventCustomType::READ)
	{
		Trace("");
	}
	void exec(productEvent* event)
	{
		product* p = event->getSource();
		productEventType * _type = event->getEventType();
		cout <<"read执行者：执行[ "<< p->getName()<< "] 事件类型"<< _type->getValue() <<endl;
	}
};
class writer:public eventCustomer
{
public:
	writer()
	:eventCustomer(eventCustomType::WRITE)
	{
		Trace("");
	}
	void exec(productEvent* event)
	{
		product* p = event->getSource();
		productEventType * _type = event->getEventType();
		cout <<"write执行者：执行[ "<< p->getName()<< "] 事件类型"<< _type->getValue() <<endl;
	}
};
class exiter:public eventCustomer
{
public:
	exiter()
	:eventCustomer(eventCustomType::WRITE)
	{
		Trace("");
	}
	void exec(productEvent* event)
	{
		product* p = event->getSource();
		productEventType * _type = event->getEventType();
		cout <<"quit执行者：执行[ "<< p->getName()<< "] 事件类型"<< _type->getValue() <<endl;
	}
};