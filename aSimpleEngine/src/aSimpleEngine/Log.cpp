#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace aSimpleEngine{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");//ʱ�� ��־����core/client�� ʵ����Ϣ
		s_CoreLogger = spdlog::stdout_color_mt("core");
		s_CoreLogger->set_level(spdlog::level::trace);//�趨Ϊtrace���� trace-debug-info-warn-err-critical-off
		s_ClientLogger =   spdlog::stdout_color_mt("client");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}