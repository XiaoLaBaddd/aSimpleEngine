#pragma once
#include "Core.h"
namespace aSimpleEngine {
		class SE_API  Application //SE_API 在core.h中，用于dll的import
		{
		public:
			Application();
			virtual ~Application();//virtual,因为会被继承
			void Run();//程序运行
		};
		//在客户端进行定义
		Application* CreateApplication();
}


