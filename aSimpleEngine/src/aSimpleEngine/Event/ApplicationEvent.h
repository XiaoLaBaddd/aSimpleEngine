#pragma once

#include"Event.h"

namespace aSimpleEngine {

	class SE_API WindowResizeEvent: public Event
	{
	public:
		//���캯�������������� unsigned int ���͵Ĳ�����width �� height�������������ֱ����ڳ�ʼ�����˽�г�Ա���� m_Width �� m_Height
		WindowResizeEvent(unsigned int width,unsigned int height)
			: m_Width(width),m_Height(height){}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override//override ��д�˻����е��麯��
		{
			std::stringstream ss;
			ss << "WindowResizeEvent:" << m_Width << "," << m_Height;//stringstream ��һ�����࣬�������������ļ��������̨��һ�������ַ�����
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_Width, m_Height;
	};

	class SE_API WindowCloseEvent :public Event
	{
	public:
		WindowCloseEvent(){}
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class SE_API AppTickEvent :public Event
	{
	public:
		AppTickEvent() {}
		EVENT_CLASS_TYPE(AppTick)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class SE_API AppUpdateEvent :public Event
	{
	public:
		AppUpdateEvent(){}
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class SE_API AppRenderEvent :public Event
	{
	public:
		AppRenderEvent(){}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

}
