#pragma once
#include "Core.h"
#include"Event/Event.h"
#include"Window.h"

namespace aSimpleEngine {
		class SE_API  Application //SE_API 在core.h中，用于dll的import
		{
		public:
			Application();
			virtual ~Application();//virtual,因为会被继承
			void Run();//程序运行
		private:
			//std::unique_ptr<Window> 表示一个指向 Window 类型对象的智能指针，拥有它所指向的 Window 对象的唯一所有权
			//智能指针：自动管理动态分配的内存，从而避免内存泄漏和其他相关问题
			std::unique_ptr<Window> m_Window;
			bool m_Running = true;
		};
		//在客户端进行定义
		Application* CreateApplication();
}


