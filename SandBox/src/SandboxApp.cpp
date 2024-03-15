#include "aSimpleEngine.h"//src当中的

class Sandbox : public aSimpleEngine::Application //Sandbox 类是public继承自 aSimpleEngine 命名空间下的 Application 类
{
public:
	Sandbox(){}
	~Sandbox(){}
};

//用于创建程序的main函数，写在dll的entry point
aSimpleEngine::Application* aSimpleEngine::CreateApplication()
{
	return new Sandbox();
}