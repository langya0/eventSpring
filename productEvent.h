#pragma once
#include "eventDispatch.h"
struct productEventType
{
private:
	int value;
public:
	enum{NEW_PRODUCT=1,DEL_PRODUCT=2,EDIT_PRODUCT=3,CLONE_PRODUCT=4};
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
	productEvent(product* p)
	:source(p)
	,type(new productEventType(productEventType::NEW_PRODUCT))
	,obs(NULL)
	{
		Trace("");
		notifyEventDispatch();
	}
	productEvent(product* p,productEventType* _type)
	:source(p)
	,type(_type)
	,obs(NULL)
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
		obs = eventDispatch::getEventDispatch();
		obs->update(type,source);
	}
	~productEvent()
	{
		Trace("");
	}
};
void testproductEvent()
{
	ProductManager manager;
	product* pro = manager.createProduct("lianglihui");
	productEvent* p = new productEvent(pro);	
}