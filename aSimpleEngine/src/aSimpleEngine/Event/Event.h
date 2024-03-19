#pragma once
#include"aSimpleEngine/Core.h"

namespace aSimpleEngine
{
	enum EventType
	{
		None_Type = 0,
		WindowClose, WindowResize, WindowFocus, WindowLosFoucus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};
	enum EventCategory
	{
		None_Category = 0,//None 被显式地初始化为 0
		EventCategoryApplication = BIT(0),//通过 BIT 宏来初始化
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	//EVENT_CLASS_TYPE 宏,用于 ，包含三个函数
	//GetStaticType，静态成员函数，返回与type对应的EventType对应的类型
	//GetEventType，虚函数，返回当前事件的类型
	//GetName，虚函数，返回当前事件类型的名称。#type 来将宏参数 type 转换为字符串字面量
	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
									virtual EventType GetEventType() const override {return GetStaticType();}\
									virtual const char* GetName() const override { return #type; }

	//EVENT_CLASS_CATEGORY,宏定义了一个名为 GetCategoryFlags 的虚函数, 宏接受一个enum参数 category
	//该函数返回一个整数，表示事件的类别标志
	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

	class SE_API Event
	{
		friend class EventDispatcher;
	public:
		// = 0是一个纯虚函数的声明。纯虚函数是一个在基类中声明但没有定义的虚函数，它要求所有的派生类都必须提供这个函数的定义。包含至少一个纯虚函数的类被称为抽象类，这样的类不能被直接实例化。
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		//inline内联函数，位运算符 &（按位与）会逐位比较两个整数
		//判断是否属于这个类别
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	private:
		bool m_Handled = false;

	};

	//事件调度
	class EventDispatcher
	{
		template<typename T>
		//定义了一个名为 EventFn 的类型别名
		//模板别名申明，代表 std::function<bool(T&)> 类型
		//std::function<bool(T&)> 表示一个函数对象，该函数对象接受一个类型为 T 的引用作为参数，并返回一个布尔值
		//函数对象：
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event){}
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}

