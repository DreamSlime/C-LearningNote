#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//一般情况下 用继承实现类的功能的拓展
//装饰模式 可以动态的给一个类增加功能

//抽象的英雄
class AbstractHero {
public:
	virtual void ShowStatus() = 0;
	int mHP;
	int mMP;
	int mAT;
	int mDF;
};

//具体英雄
class HeroA :public AbstractHero {
public:
	HeroA() {
		mHP = 0;
		mMP = 0;
		mAT = 0;
		mDF = 0;
	}
	virtual void ShowStatus() {
		cout << "血量：" << mHP << endl;
		cout << "法力：" << mMP << endl;
		cout << "攻击：" << mAT << endl;
		cout << "防御：" << mDF << endl;
	}
};

//装设类的基类,英雄穿上某个装饰物 那么他还是个英雄
class AbstractRquipment : public AbstractHero {
public:
	AbstractRquipment(AbstractHero* hero) {
		this->phero = hero;
	}
	virtual void ShowStatus() {

	}
	AbstractHero* phero;
};

//狂徒
class KuangtuEquipment : public AbstractRquipment {
public:
	KuangtuEquipment(AbstractHero* hero) :AbstractRquipment(hero) {}
	//增加额外的功能
	void AddKuangtu() {
		cout << "英雄穿上狂徒后..." << endl;
		this->mHP = this->phero->mHP;
		this->mMP = this->phero->mMP;
		this->mAT = this->phero->mAT;
		this->mDF = this->phero->mDF+30;
		
		delete this->phero;
	}
	
	virtual void ShowStatus() {
		AddKuangtu();
		cout << "血量：" << mHP << endl;
		cout << "法力：" << mMP << endl;
		cout << "攻击：" << mAT << endl;
		cout << "防御：" << mDF << endl;
	}
};

//无尽之刃
class Wujing : public AbstractRquipment {
public:
	Wujing(AbstractHero* hero) :AbstractRquipment(hero) {}
	//增加额外的功能
	void AddKuangtu() {
		cout << "英雄装备无尽之刃后..." << endl;
		this->mHP = this->phero->mHP;
		this->mMP = this->phero->mMP;
		this->mAT = this->phero->mAT+80;
		this->mDF = this->phero->mDF;

		delete this->phero;
	}

	virtual void ShowStatus() {
		AddKuangtu();
		cout << "血量：" << mHP << endl;
		cout << "法力：" << mMP << endl;
		cout << "攻击：" << mAT << endl;
		cout << "防御：" << mDF << endl;
	}
};

void test01() {
	AbstractHero* hero = new HeroA;
	hero->ShowStatus();
	cout << "............." << endl;
	//给英雄穿上装备
	hero = new KuangtuEquipment(hero);
	hero->ShowStatus();
	hero = new Wujing(hero);
	hero->ShowStatus();
}

int main(void) {
	test01();
	return 0;
}