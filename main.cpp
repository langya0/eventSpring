// #include "product.h"

#define __NOTRACE
#include <stdlib.h>
#include "eventDispatch.h"
// #include "productEvent.h"

void testproductEvent()
{
	ProductManager manager;
	product* pro = manager.createProduct("lianglihui");
	observer* dis = new eventDispatch();
	productEvent* p = new productEvent(dis ,pro);	
}

int main(int argc, char const *argv[])
{
	// testproduct();
	// testeventDispatch();
	// testproductEvent();
	// 事件分发中心
	eventDispatch* dis = new eventDispatch();

	eventCustomer *_reader = new reader();
	eventCustomer *_writer = new writer();
	// 注册两个读事件执行者
	cout << "注册一个读事件执行者" <<endl;
	dis->registerCustomer(_reader);
	cout << "注册一个写事件执行者" <<endl;
	dis->registerCustomer(_writer);

	// 建立一个原子弹生叉工厂
	ProductManager *factory = new ProductManager();
	for(int i = 0 ; i < 10; ++ i)
	{
		int random = rand()%4;
		cout << endl <<"=============模拟产生事件==============="<<endl;
		cout << "随机产生一个事件：事件类型 "<<random <<endl;
		productEvent*event = new productEvent(dis,factory->createProduct("写事件"),random);
	}
	
	return 0;
}