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
		None_Category = 0,//None ����ʽ�س�ʼ��Ϊ 0
		EventCategoryApplication = BIT(0),//ͨ�� BIT ������ʼ��
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	//EVENT_CLASS_TYPE ��,���� ��������������
	//GetStaticType����̬��Ա������������type��Ӧ��EventType��Ӧ������
	//GetEventType���麯�������ص�ǰ�¼�������
	//GetName���麯�������ص�ǰ�¼����͵����ơ�#type ��������� type ת��Ϊ�ַ���������
	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
									virtual EventType GetEventType() const override {return GetStaticType();}\
									virtual const char* GetName() const override { return #type; }

	//EVENT_CLASS_CATEGORY,�궨����һ����Ϊ GetCategoryFlags ���麯��, �����һ��enum���� category
	//�ú�������һ����������ʾ�¼�������־
	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

	class SE_API Event
	{
		friend class EventDispatcher;
	public:
		// = 0��һ�����麯�������������麯����һ���ڻ�����������û�ж�����麯������Ҫ�����е������඼�����ṩ��������Ķ��塣��������һ�����麯�����౻��Ϊ�����࣬�������಻�ܱ�ֱ��ʵ������
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		//inline����������λ����� &����λ�룩����λ�Ƚ���������
		//�ж��Ƿ�����������
		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	private:
		bool m_Handled = false;

	};

	//�¼�����
	class EventDispatcher
	{
		template<typename T>
		//������һ����Ϊ EventFn �����ͱ���
		//ģ��������������� std::function<bool(T&)> ����
		//std::function<bool(T&)> ��ʾһ���������󣬸ú����������һ������Ϊ T ��������Ϊ������������һ������ֵ
		//��������
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

