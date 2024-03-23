#include "sepch.h"
#include "Application.h"

//#include"aSimpleEngine/Event/ApplicationEvent.h"
#include"aSimpleEngine/Log.h"

#include <GLFW/glfw3.h>

namespace aSimpleEngine {

//宏，并且接受一个参数x。创建一个绑定到Application类的x成员函数的可调用对象，该对象可以作为一个事件处理函数使用，并接受一个参数
//std::bind，用于创建一个可调用对象（如函数对象或lambda表达式），该对象可以绑定到某个对象（即this指针）的成员函数，并可能绑定到一些额外的参数。
//this：告诉std::bind我们要绑定到哪个对象的x成员函数
//placehoder：std::bind的一个占位符，表示在调用绑定的函数时，该位置应接受一个参数
#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}
	Application::~Application(){}
	
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		SE_CORE_TRACE("{0}",e);//每个事件都会写入log
	}
	
	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}