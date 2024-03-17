#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace aSimpleEngine{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");//时间 日志名（core/client） 实际信息
		s_CoreLogger = spdlog::stdout_color_mt("core");
		s_CoreLogger->set_level(spdlog::level::trace);//设定为trace级别 trace-debug-info-warn-err-critical-off
		s_ClientLogger =   spdlog::stdout_color_mt("client");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}