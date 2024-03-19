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

#ifdef SE_ENABLE_ASSERTS
	#define SE_ASSERT(x, ...){if(!(x){SE_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak();})}
	#define SE_CORE_ASSERT(x, ...){if(!(x){SE_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak();})}
#else
	#define SE_ASSERT(x, ...)
	#define SE_CORE_ASSERT(x, ...)
#endif // SE_ENABLE_ASSERTS


#define BIT(x) (1<<x)//1 << x 是位操作中的左移操作，表示将数字1向左移动x位，这相当于计算2的x次幂