#pragma once
#include "Core.h"
namespace aSimpleEngine {
		class SE_API  Application //SE_API ��core.h�У�����dll��import
		{
		public:
			Application();
			virtual ~Application();//virtual,��Ϊ�ᱻ�̳�
			void Run();//��������
		};
		//�ڿͻ��˽��ж���
		Application* CreateApplication();
}


