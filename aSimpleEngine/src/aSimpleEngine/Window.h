#pragma once

#include"sepch.h"

#include"aSimpleEngine/Core.h"
#include"aSimpleEngine/Event/Event.h"

namespace aSimpleEngine {


	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "a Simple Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			:Title(title), Width(width), Height(height) {}
	};

	//桌面窗口的接口(全是纯虚函数，没有任何数据与实现)，由Application使用
	class SE_API Window
	{
	public:
		//std::function 是一个通用的、多态的函数封装器，它可以存储、复制和调用任何可调用的目标
		//EventCallbackFn 的好处是，你可以将这个类型作为参数传递给函数，或者作为类成员变量，从而允许调用者传递任何满足这个签名的可调用的对象（函数、lambda、函数对象等）
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window(){}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//window属性
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;//将窗口上发生的事件传回Application
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());

	};


}