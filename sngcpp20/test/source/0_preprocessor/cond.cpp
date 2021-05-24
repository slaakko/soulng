#define FOO
#define BAR
#define BAZ

#if !defined(FOO)
// not processed
#elif defined(BAR)
// processed
	#ifndef BAZ
	// not processed
	#else
	// processed
	#endif
#else
// not processed
#endif
