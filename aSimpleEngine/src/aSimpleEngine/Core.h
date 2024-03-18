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

#define BIT(x) (1<<x)//1 << x 是位操作中的左移操作，表示将数字1向左移动x位，这相当于计算2的x次幂