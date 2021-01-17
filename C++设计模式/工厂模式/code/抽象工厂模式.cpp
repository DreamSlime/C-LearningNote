#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//抽象苹果
class AbstractApple {
public:
	virtual void ShowName() = 0;
};

//中国苹果
class ChinaApple :public AbstractApple {
public:
	virtual void ShowName() {
		cout << "中国苹果" << endl;
	}
};

//美国苹果
class USAApple :public AbstractApple {
public:
	virtual void ShowName() {
		cout << "美国苹果" << endl;
	}
};


//倭国苹果
class JapanApple :public AbstractApple {
public:
	virtual void ShowName() {
		cout << "倭国苹果" << endl;
	}
};


//抽象的香蕉
class AbstractBanana {
public:
	virtual void ShowName() = 0;
};

class ChinaBanana : public AbstractBanana {
public:
	virtual void ShowName() {
		cout << "中国香蕉" << endl;
	}
};

class USABanana : public AbstractBanana {
public:
	virtual void ShowName() {
		cout << "美国香蕉" << endl;
	}
};

class JapanBanana : public AbstractBanana {
public:
	virtual void ShowName() {
		cout << "倭国香蕉" << endl;
	}
};

//抽象工厂
class AbstractFactory {
public:
	virtual AbstractApple* CreateApple() = 0;
	virtual AbstractBanana* CreateBanana() = 0;
};

//中国工厂
class ChinaFactory : public AbstractFactory {
public:
	virtual AbstractApple* CreateApple() {
		return new ChinaApple;
	}
	virtual AbstractBanana* CreateBanana() {
		return new ChinaBanana;
	}
};
//美国工厂
class USAFactory : public AbstractFactory {
public:
	virtual AbstractApple* CreateApple() {
		return new  USAApple;
	}
	virtual AbstractBanana* CreateBanana() {
		return new  USABanana;
	}
};
//倭国工厂
class JapanFactory : public AbstractFactory {
public:
	virtual AbstractApple* CreateApple() {
		return new  JapanApple;
	}
	virtual AbstractBanana* CreateBanana() {
		return new  JapanBanana;
	}
};

void test01() {
	AbstractFactory* factory = NULL;
	AbstractApple* apple = NULL;
	AbstractBanana* banana = NULL;
	//中国工厂
	factory = new ChinaFactory;
	apple = factory->CreateApple();
	banana = factory->CreateBanana();
	apple->ShowName();
	banana->ShowName();
	delete apple;
	delete banana;
	delete factory;
}

int main(void) {
	test01();
	return 0;
}