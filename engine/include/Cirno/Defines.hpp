#if defined (CIRNO_EXPORTS)
    #if defined (CIRNO_SHARED)
        #if defined (_WIN32)
            #define CIRNO_API __declspec(dllexport)
        #elif defined (__APPLE__)
            #define CIRNO_API __attribute__((visibility("default")))
        #else
            #error "Unsupported platform"
        #endif
    #else
        #define CIRNO_API
    #endif
#else
    #if defined (_WIN32) && defined (CIRNO_SHARED)
        #define CIRNO_API __declspec(dllimport)
    #else 
        #define CIRNO_API
    #endif
#endif