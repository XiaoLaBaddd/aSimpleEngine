#include "sepch.h"
#include "Application.h"

#include"aSimpleEngine/Event/ApplicationEvent.h"
#include"aSimpleEngine/Log.h"

namespace aSimpleEngine {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application(){}
	
	
	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
	

}