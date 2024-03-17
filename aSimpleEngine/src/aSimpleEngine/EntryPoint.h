#pragma once

# ifdef SE_PLATFORM_WINDOWS

extern aSimpleEngine::Application* aSimpleEngine::CreateApplication();

int main(int argc, char** argv)
{
	aSimpleEngine::Log::Init();//引擎初始化，log初始化
	SE_CORE_CRITAL("LOG");
	auto app = aSimpleEngine::CreateApplication();//app变量的类型是由CreateApplication()这个函数的返回值类型来确定
	app->Run();
	delete app;
}

# endif