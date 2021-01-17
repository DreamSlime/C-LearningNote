#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//提供一种代理来控制对其他对象的访问

class AbstractCommonInterface {
public:
	virtual void run() = 0;
};

//我已经写好的代理
class MySystem : public AbstractCommonInterface{
public:
	virtual void run() {
		cout << "系统启动" << endl;
	}
};

//必须要权限的验证，不是所有人都来启动我的系统，提供用户名和密码
class MySystemProxy : public AbstractCommonInterface {
public:
	MySystemProxy(string username,string password) {
		this->mUsername = username;
		this->mPassword = password;
		pSystem = new MySystem;
	}
	bool checkUsernameAndPassword() {
		if (mUsername == "admin" && mPassword == "admin") {
			return true;
		}
		return false;
	}
	virtual void run() {
		if (checkUsernameAndPassword()) {
			cout << "用户名和密码正确，验证通过" << endl;
			this->pSystem->run();
		}
		else {
			cout << "用户名或密码错误，权限不足..." << endl;
		}
	}
	~MySystemProxy() {
		if (pSystem != NULL) {
			delete pSystem;
		}
	}
public:
	MySystem* pSystem;
	string mUsername;
	string mPassword;
};

void test01() {
	MySystemProxy* proxy = new MySystemProxy("admin","admin");
	proxy->run();
}


int main(void) {
	test01();

	return 0;
}