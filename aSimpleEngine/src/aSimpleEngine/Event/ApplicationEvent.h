#pragma once

#include"Event.h"

namespace aSimpleEngine {

	class SE_API WindowResizeEvent: public Event
	{
	public:
		//构造函数，它接受两个 unsigned int 类型的参数：width 和 height。这两个参数分别用于初始化类的私有成员变量 m_Width 和 m_Height
		WindowResizeEvent(unsigned int width,unsigned int height)
			: m_Width(width),m_Height(height){}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override//override 重写了基类中的虚函数
		{
			std::stringstream ss;
			ss << "WindowResizeEvent:" << m_Width << "," << m_Height;//stringstream 是一个流类，允许我们像处理文件流或控制台流一样处理字符串。
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
