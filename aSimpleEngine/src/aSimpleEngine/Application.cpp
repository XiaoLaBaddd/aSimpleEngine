#include "sepch.h"
#include "Application.h"

//#include"aSimpleEngine/Event/ApplicationEvent.h"
#include"aSimpleEngine/Log.h"

#include <GLFW/glfw3.h>

namespace aSimpleEngine {

//�꣬���ҽ���һ������x������һ���󶨵�Application���x��Ա�����Ŀɵ��ö��󣬸ö��������Ϊһ���¼�������ʹ�ã�������һ������
//std::bind�����ڴ���һ���ɵ��ö����纯�������lambda���ʽ�����ö�����԰󶨵�ĳ�����󣨼�thisָ�룩�ĳ�Ա�����������ܰ󶨵�һЩ����Ĳ�����
//this������std::bind����Ҫ�󶨵��ĸ������x��Ա����
//placehoder��std::bind��һ��ռλ������ʾ�ڵ��ð󶨵ĺ���ʱ����λ��Ӧ����һ������
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

		SE_CORE_TRACE("{0}",e);//ÿ���¼�����д��log
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