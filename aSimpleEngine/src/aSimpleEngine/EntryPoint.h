#pragma once

# ifdef SE_PLATFORM_WINDOWS

extern aSimpleEngine::Application* aSimpleEngine::CreateApplication();

int main(int argc, char** argv)
{
	aSimpleEngine::Log::Init();//�����ʼ����log��ʼ��
	SE_CORE_CRITAL("LOG");
	auto app = aSimpleEngine::CreateApplication();//app��������������CreateApplication()��������ķ���ֵ������ȷ��
	app->Run();
	delete app;
}

# endif