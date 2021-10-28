#ifndef CONFIG_API_INCLUDED
#define CONFIG_API_INCLUDED

#ifdef CONFIG_EXPORTS
#define CONFIG_API __declspec(dllexport)
#else
#define CONFIG_API __declspec(dllimport)

#ifdef NDEBUG
#pragma comment(lib, "soulng_library_config.lib")
#else
#pragma comment(lib, "soulng_library_configd.lib")
#endif

#endif

#endif // CONFIG_API_INCLUDED
