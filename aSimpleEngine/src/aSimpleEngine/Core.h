#pragma once
#ifdef SE_PLATFORM_WINDOWS
	# ifdef SE_BUILD_DLL
		#define SE_API __declspec(dllexport)
	#else
		#define SE_API __declspec(dllimport)
	#endif
# else
	#error our Simpal Engine only support Windows !
#endif

#define BIT(x) (1<<x)//1 << x ��λ�����е����Ʋ�������ʾ������1�����ƶ�xλ�����൱�ڼ���2��x����