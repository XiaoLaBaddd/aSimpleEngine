#pragma once
//#include<memory>//使用了std::shared_ptr
#include"Core.h"
#include "spdlog/spdlog.h"//include第三方库
#include "spdlog/sinks/stdout_color_sinks.h"
#include"spdlog/fmt/ostr.h"

namespace aSimpleEngine {
	
	class SE_API Log //export dll
	{
	public:
		static void Init();//初始化日志系统,static 不需要实例即可调用
		//内联静态成员函数，内联函数通常意味着编译器会尝试在调用点直接插入函数体，而不是进行常规的函数调用
		//std::shared_ptr是C++11及以后版本中的智能指针，用于共享对象的所有权
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		//一个指向spdlog::logger类型的智能指针，用于记录核心（或服务器端）的日志
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}
//核心端日志宏
# define SE_CORE_TRACE(...) ::aSimpleEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)//宏接收变量，并将变量传递给了实际的函数
# define SE_CORE_INFO(...) ::aSimpleEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
# define SE_CORE_WARN(...) ::aSimpleEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
# define SE_CORE_ERROR(...) ::aSimpleEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
# define SE_CORE_CRITAL(...) ::aSimpleEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)
//客户端日志宏
# define SE_TRACE(...) ::aSimpleEngine::Log::GetClientLogger()->trace(__VA_ARGS__)//宏接收变量，并将变量传递给了实际的函数
# define SE_INFO(...) ::aSimpleEngine::Log::GetClientLogger()->info(__VA_ARGS__)
# define SE_WARN(...) ::aSimpleEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
# define SE_ERROR(...) ::aSimpleEngine::Log::GetClientLogger()->error(__VA_ARGS__)
# define SE_FATAL(...) ::aSimpleEngine::Log::GetClientLogger()->critical(__VA_ARGS__)
