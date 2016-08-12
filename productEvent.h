#pragma once
// #include "eventDispatch.h"
#include "product.h"
#include "observer.h"

struct productEventType
{
private:
	int value;
public:
	enum{
		READ = 1,
		WRITE = 2,
		EXIT = 3
	};
	productEventType(int _value)
	:value(_value)
	{}
public:
	int getValue()
	{
		return value;
	}
};

class productEvent
{
protected:
	product* source; //源头事件
	productEventType* type; //动作类型
	observer* obs;	//观察者

public:
	productEvent(observer* _obs,product* p)
	:source(p)
	,type(new productEventType(productEventType::READ))
	,obs(_obs)
	{
		Trace("");
		notifyEventDispatch();
	}
	productEvent(observer* _obs,product* p,const int _type)
	:source(p)
	,type(new productEventType(_type))
	,obs(_obs)
	{
		Trace("");
		// 事件触发
		notifyEventDispatch();
	}
	product* getSource()
	{
		return source;
	}

	productEventType* getEventType()
	{
		return type;
	}

protected:
	void notifyEventDispatch()
	{
		Trace("");
		// obs = eventDispatch::getEventDispatch();
		obs->update(this,source);
	}
	~productEvent()
	{
		Trace("");
	}
};

