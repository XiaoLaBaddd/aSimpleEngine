#include "aSimpleEngine.h"//src���е�

class Sandbox : public aSimpleEngine::Application //Sandbox ����public�̳��� aSimpleEngine �����ռ��µ� Application ��
{
public:
	Sandbox(){}
	~Sandbox(){}
};

//���ڴ��������main������д��dll��entry point
aSimpleEngine::Application* aSimpleEngine::CreateApplication()
{
	return new Sandbox();
}