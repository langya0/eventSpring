#pragma once

class productEventType;
class productEvent;
class observer
{
public:
	virtual	void update(productEvent *,product* )=0;
};
