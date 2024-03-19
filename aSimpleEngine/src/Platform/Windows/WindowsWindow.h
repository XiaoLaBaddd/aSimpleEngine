#pragma once
#include"aSimpleEngine/Window.h"

#include<GLFW/glfw3.h>

namespace aSimpleEngine {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);		
		virtual ~WindowsWindow();

		//更新glfw，当缓冲区轮询输入事件，按帧运行，在application中调用
		virtual void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		//window属性
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		GLFWwindow* m_Window;
		
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;


	};

}



