#pragma once
#include "Core.h"
#include"Event/Event.h"
#include"Window.h"

namespace aSimpleEngine {
		class SE_API  Application //SE_API ��core.h�У�����dll��import
		{
		public:
			Application();
			virtual ~Application();//virtual,��Ϊ�ᱻ�̳�
			void Run();//��������
		private:
			//std::unique_ptr<Window> ��ʾһ��ָ�� Window ���Ͷ��������ָ�룬ӵ������ָ��� Window �����Ψһ����Ȩ
			//����ָ�룺�Զ�����̬������ڴ棬�Ӷ������ڴ�й©�������������
			std::unique_ptr<Window> m_Window;
			bool m_Running = true;
		};
		//�ڿͻ��˽��ж���
		Application* CreateApplication();
}


