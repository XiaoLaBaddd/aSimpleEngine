#pragma once
//#include<memory>//ʹ����std::shared_ptr
#include"Core.h"
#include "spdlog/spdlog.h"//include��������
#include "spdlog/sinks/stdout_color_sinks.h"
#include"spdlog/fmt/ostr.h"

namespace aSimpleEngine {
	
	class SE_API Log //export dll
	{
	public:
		static void Init();//��ʼ����־ϵͳ,static ����Ҫʵ�����ɵ���
		//������̬��Ա��������������ͨ����ζ�ű������᳢���ڵ��õ�ֱ�Ӳ��뺯���壬�����ǽ��г���ĺ�������
		//std::shared_ptr��C++11���Ժ�汾�е�����ָ�룬���ڹ�����������Ȩ
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		//һ��ָ��spdlog::logger���͵�����ָ�룬���ڼ�¼���ģ���������ˣ�����־
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}
//���Ķ���־��
# define SE_CORE_TRACE(...) ::aSimpleEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)//����ձ����������������ݸ���ʵ�ʵĺ���
# define SE_CORE_INFO(...) ::aSimpleEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
# define SE_CORE_WARN(...) ::aSimpleEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
# define SE_CORE_ERROR(...) ::aSimpleEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
# define SE_CORE_CRITAL(...) ::aSimpleEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)
//�ͻ�����־��
# define SE_TRACE(...) ::aSimpleEngine::Log::GetClientLogger()->trace(__VA_ARGS__)//����ձ����������������ݸ���ʵ�ʵĺ���
# define SE_INFO(...) ::aSimpleEngine::Log::GetClientLogger()->info(__VA_ARGS__)
# define SE_WARN(...) ::aSimpleEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
# define SE_ERROR(...) ::aSimpleEngine::Log::GetClientLogger()->error(__VA_ARGS__)
# define SE_FATAL(...) ::aSimpleEngine::Log::GetClientLogger()->critical(__VA_ARGS__)
