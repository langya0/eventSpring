#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
using namespace std;
#include "trace.h"
#include "product.h"
#include "observer.h"
#include "productEvent.h"
#include "eventCustomer.h"

class productEventType;


// 静态观察者&中介，调度中心
class eventDispatch:public observer
{
public:
	std::vector<eventCustomer*> customer;
	static observer* dispatch;

	eventDispatch()
	{
		Trace("");
	}
public:
	// static observer*getEventDispatch();
	void update(productEvent* event,product* pro)
	{
		Trace("");
		cout << "事件发生。触发器工作...."<<endl;
		int len = customer.size();
		bool isExec=false;
		// 处理者处理，这里是中介者模式的核心，可以是很复杂的逻辑
		for(int i = 0; i < len; ++i)
		{
			vector<eventCustomType> custype = customer[i]->getCustomType();
			// ///////////////////
			for(int i = 0;i < custype.size();++i)
			if(custype[i].getValue() == event->getEventType()->getValue())
			{
				customer[i]->exec(event);
				isExec = true;
			}
		}
		if (isExec == false)
		{
			cout << "未注册执行者"<<endl;
		}
		sleep(1);

		Trace("");
	}
	void registerCustomer(eventCustomer *_customer)
	{
		Trace("");
		customer.push_back(_customer);
	}
};
// observer* eventDispatch::dispatch = new eventDispatch();
// observer* eventDispatch::getEventDispatch()
// {
// 	return dispatch;
// }


// void testeventDispatch()
// {
// 	observer* p = eventDispatch::getEventDispatch();
// 	p = eventDispatch::getEventDispatch();
// }