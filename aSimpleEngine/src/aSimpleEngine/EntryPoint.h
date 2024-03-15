#pragma once

# ifdef SE_PLATFORM_WINDOWS

extern aSimpleEngine::Application* aSimpleEngine::CreateApplication();

int main(int argc, char** argv)
{
	printf("a");
	auto app = aSimpleEngine::CreateApplication();
	app->Run();
	delete app;
}

# endif