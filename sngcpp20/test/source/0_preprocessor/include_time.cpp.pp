       
       
                     
  

    
 

 





  

 


 

      
   
    
  
 
  
 
  
   
   
 

   
 
  

 
  
 
  

 


 



 
   
 





 
    

  
 


 



 
               

 

 

    

 








 



  
 

 
    
 
 
  
 
 

 
 
 

 
  
   
 




   
   

   

   
 

 

   
    
  
 

 
 
    
  
 
 
 
 




 

  
 
 
  
 
  
  

   
 
 
  
 
   
 
 
  
  
 

 

  

  



 


  



 
 
 
 
    
 
  
 
 
 


 


  
 
 
 

 
    
 
  
 
 
 


 


  
 
 
 

   

   
   
 
  
 
 
 
  
 
 
 

 
 
  
 
 
  
 
 
 


 


  
 
 
 

  
 
 
 
    



     









    



   

    
      
   




 



























 

 
 


extern "C" {


 

 





 


 




    





     
 



    


     
 





}

 



extern "C" {












 





}

          

 
  
 
  

extern "C" {


        typedef unsigned __int64  uintptr_t;

        typedef char* va_list;




    void __cdecl __va_start(va_list* , ...);



}  
    extern "C++"
    {
        template <typename _Ty>
        struct __vcrt_va_list_is_reference
        {
            enum : bool { __the_value = false };
        };

        template <typename _Ty>
        struct __vcrt_va_list_is_reference<_Ty&>
        {
            enum : bool { __the_value = true };
        };

        template <typename _Ty>
        struct __vcrt_va_list_is_reference<_Ty&&>
        {
            enum : bool { __the_value = true };
        };

        template <typename _Ty>
        struct __vcrt_assert_va_start_is_not_reference
        {
            static_assert(!__vcrt_va_list_is_reference<_Ty>::__the_value,
                "va_start argument must not have reference type and must not be parenthesized");
        };
    }  




   



         extern "C" {












 


 




 
     typedef unsigned __int64 size_t;
    typedef __int64          ptrdiff_t;
    typedef __int64          intptr_t;

    typedef bool  __vcrt_bool;

 


 



    extern "C++"
    {
        template <typename _CountofType, size_t _SizeOfArray>
        char (*__countof_helper(__unaligned _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];

    }




 

 




    void __cdecl __security_init_cookie(void);

        void __cdecl __security_check_cookie(  uintptr_t _StackCookie);
        __declspec(noreturn) void __cdecl __report_gsfailure(  uintptr_t _StackCookie);

extern uintptr_t __security_cookie;


}                             



     
  
 
           




         extern "C" {

     
  




 

     








     extern "C++"
{
    template<bool _Enable, typename _Ty>
    struct _CrtEnableIf;

    template<typename _Ty>
    struct _CrtEnableIf<true, _Ty>
    {
        typedef _Ty _Type;
    };
}

    typedef bool  __crt_bool;





         



     


 


     
 void __cdecl _invalid_parameter_noinfo(void);
 __declspec(noreturn) void __cdecl _invalid_parameter_noinfo_noreturn(void);

__declspec(noreturn)
 void __cdecl _invoke_watson(
      wchar_t const* _Expression,
      wchar_t const* _FunctionName,
      wchar_t const* _FileName,
            unsigned int _LineNo,
            uintptr_t _Reserved);

                                                                                                   


     





     




     











                  






     typedef int                           errno_t;
typedef unsigned short                wint_t;
typedef unsigned short                wctype_t;
typedef long                          __time32_t;
typedef __int64                       __time64_t;

typedef struct __crt_locale_data_public
{
      unsigned short const* _locale_pctype;
      int _locale_mb_cur_max;
               unsigned int _locale_lc_codepage;
} __crt_locale_data_public;

typedef struct __crt_locale_pointers
{
    struct __crt_locale_data*    locinfo;
    struct __crt_multibyte_data* mbcinfo;
} __crt_locale_pointers;

typedef __crt_locale_pointers* _locale_t;

typedef struct _Mbstatet
{      unsigned long _Wchar;
    unsigned short _Byte, _State;
} _Mbstatet;

typedef _Mbstatet mbstate_t;



        typedef __time64_t time_t;

 
    typedef size_t rsize_t;




     








































     













































}                             


        
       


         extern "C" {



     struct tm
{
    int tm_sec;        int tm_min;        int tm_hour;       int tm_mday;       int tm_mon;        int tm_year;       int tm_wday;       int tm_yday;       int tm_isdst;  };


       __declspec(deprecated("This function or variable may be unsafe. Consider using _wasctime_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 
 
 wchar_t* __cdecl _wasctime(
      struct tm const* _Tm
    );

 

 errno_t __cdecl _wasctime_s(
        wchar_t*         _Buffer,
                                          size_t           _SizeInWords,
                                                       struct tm const* _Tm
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                                errno_t __cdecl _wasctime_s(  wchar_t (&_Buffer)[_Size],                       struct tm const* _Time) throw()                 {                                                                                                                    return _wasctime_s(_Buffer, _Size, _Time);                                                                       }                                                                                                            }

 

 size_t __cdecl wcsftime(
       wchar_t*         _Buffer,
                               size_t           _SizeInWords,
                             wchar_t const*   _Format,
                               struct tm const* _Tm
    );

 

 size_t __cdecl _wcsftime_l(
       wchar_t*         _Buffer,
                               size_t           _SizeInWords,
                             wchar_t const*   _Format,
                               struct tm const* _Tm,
                           _locale_t        _Locale
    );

 
  __declspec(deprecated("This function or variable may be unsafe. Consider using _wctime32_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 wchar_t* __cdecl _wctime32(
      __time32_t const* _Time
    );


 errno_t __cdecl _wctime32_s(
        wchar_t*          _Buffer,
                                      size_t            _SizeInWords,
                                                       __time32_t const* _Time
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl _wctime32_s(  wchar_t (&_Buffer)[_Size],                       __time32_t const* _Time) throw()                 {                                                                                                                    return _wctime32_s(_Buffer, _Size, _Time);                                                                       }                                                                                                            }

 
 
  __declspec(deprecated("This function or variable may be unsafe. Consider using _wctime64_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 wchar_t* __cdecl _wctime64(
      __time64_t const* _Time
    );


 errno_t __cdecl _wctime64_s(
        wchar_t*          _Buffer,
                                      size_t            _SizeInWords,
                                                       __time64_t const* _Time);

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl _wctime64_s(  wchar_t (&_Buffer)[_Size],                       __time64_t const* _Time) throw()                 {                                                                                                                    return _wctime64_s(_Buffer, _Size, _Time);                                                                       }                                                                                                            }


 errno_t __cdecl _wstrdate_s(
       wchar_t* _Buffer,
                                                                                size_t   _SizeInWords
    );

extern "C++"                                                                                      {                                                                                                     template <size_t _Size>                                                                           inline                                                                                            errno_t __cdecl _wstrdate_s(  wchar_t (&_Buffer)[_Size]) throw()                  {                                                                                                     return _wstrdate_s(_Buffer, _Size);                                                                }                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))      wchar_t* __cdecl _wstrdate(  wchar_t *_Buffer);


 errno_t __cdecl _wstrtime_s(
       wchar_t* _Buffer,
                                                                                size_t   _SizeInWords
    );

extern "C++"                                                                                      {                                                                                                     template <size_t _Size>                                                                           inline                                                                                            errno_t __cdecl _wstrtime_s(  wchar_t (&_Buffer)[_Size]) throw()                  {                                                                                                     return _wstrtime_s(_Buffer, _Size);                                                                }                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))      wchar_t* __cdecl _wstrtime(  wchar_t *_Buffer);



     
         
        static __inline wchar_t * __cdecl _wctime(
              time_t const* const _Time)
        {
            return _wctime64(_Time);
        }

        
        static __inline errno_t __cdecl _wctime_s(
                  wchar_t*      const _Buffer,
                                                             size_t        const _SizeInWords,
                                                             time_t const* const _Time
            )
        {
            return _wctime64_s(_Buffer, _SizeInWords, _Time);
        }


}                             




         extern "C" {



     typedef long clock_t;

struct _timespec32
{
    __time32_t tv_sec;
    long       tv_nsec;
};

struct _timespec64
{
    __time64_t tv_sec;
    long       tv_nsec;
};

    struct timespec
    {
        time_t tv_sec;           long   tv_nsec;      };



 



        __declspec(deprecated("This function or variable may be unsafe. Consider using replacement instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 int* __cdecl __daylight(void);


   __declspec(deprecated("This function or variable may be unsafe. Consider using replacement instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 long* __cdecl __dstbias(void);


   __declspec(deprecated("This function or variable may be unsafe. Consider using replacement instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 long* __cdecl __timezone(void);


     __declspec(deprecated("This function or variable may be unsafe. Consider using replacement instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 char** __cdecl __tzname(void);


  
 errno_t __cdecl _get_daylight(
      int* _Daylight
    );

 
 errno_t __cdecl _get_dstbias(
      long* _DaylightSavingsBias
    );

  
 errno_t __cdecl _get_timezone(
      long* _TimeZone
    );

 
 errno_t __cdecl _get_tzname(
                             size_t* _ReturnValue,
      char*   _Buffer,
                              size_t  _SizeInBytes,
                              int     _Index
    );



      
 
  __declspec(deprecated("This function or variable may be unsafe. Consider using asctime_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 char* __cdecl asctime(
      struct tm const* _Tm
    );

     
    
     errno_t __cdecl asctime_s(
            char*            _Buffer,
                                            size_t           _SizeInBytes,
                                                         struct tm const* _Tm
        );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl asctime_s(  char (&_Buffer)[_Size],                       struct tm const* _Time) throw()                 {                                                                                                                    return asctime_s(_Buffer, _Size, _Time);                                                                       }                                                                                                            }

 
 clock_t __cdecl clock(void);

 
 
  __declspec(deprecated("This function or variable may be unsafe. Consider using _ctime32_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 char* __cdecl _ctime32(
      __time32_t const* _Time
    );


 errno_t __cdecl _ctime32_s(
        char*             _Buffer,
                                        size_t            _SizeInBytes,
                                                     __time32_t const* _Time
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl _ctime32_s(  char (&_Buffer)[_Size],                       __time32_t const* _Time) throw()                 {                                                                                                                    return _ctime32_s(_Buffer, _Size, _Time);                                                                       }                                                                                                            }

 
 
  __declspec(deprecated("This function or variable may be unsafe. Consider using _ctime64_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 char* __cdecl _ctime64(
      __time64_t const* _Time
    );


 errno_t __cdecl _ctime64_s(
        char*             _Buffer,
                                          size_t            _SizeInBytes,
                                                       __time64_t const* _Time
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl _ctime64_s(  char (&_Buffer)[_Size],                       __time64_t const* _Time) throw()                 {                                                                                                                    return _ctime64_s(_Buffer, _Size, _Time);                                                                       }                                                                                                            }

 
 double __cdecl _difftime32(
      __time32_t _Time1,
      __time32_t _Time2
    );

 
 double __cdecl _difftime64(
      __time64_t _Time1,
      __time64_t _Time2
    );

 
  __declspec(deprecated("This function or variable may be unsafe. Consider using _gmtime32_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 struct tm* __cdecl _gmtime32(
      __time32_t const* _Time
    );


 errno_t __cdecl _gmtime32_s(
      struct tm*        _Tm,
       __time32_t const* _Time
    );

 
  __declspec(deprecated("This function or variable may be unsafe. Consider using _gmtime64_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 struct tm* __cdecl _gmtime64(
      __time64_t const* _Time
    );


 errno_t __cdecl _gmtime64_s(
      struct tm*        _Tm,
       __time64_t const* _Time
    );

 
  __declspec(deprecated("This function or variable may be unsafe. Consider using _localtime32_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 struct tm* __cdecl _localtime32(
      __time32_t const* _Time
    );


 errno_t __cdecl _localtime32_s(
      struct tm*        _Tm,
       __time32_t const* _Time
    );

 
  __declspec(deprecated("This function or variable may be unsafe. Consider using _localtime64_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 struct tm* __cdecl _localtime64(
      __time64_t const* _Time
    );


 errno_t __cdecl _localtime64_s(
      struct tm*        _Tm,
       __time64_t const* _Time
    );

 
 __time32_t __cdecl _mkgmtime32(
      struct tm* _Tm
    );

 
 __time64_t __cdecl _mkgmtime64(
      struct tm* _Tm
    );


 __time32_t __cdecl _mktime32(
      struct tm* _Tm
    );


 __time64_t __cdecl _mktime64(
      struct tm* _Tm
    );

 

 size_t __cdecl strftime(
       char*            _Buffer,
                               size_t           _SizeInBytes,
        char const*      _Format,
                               struct tm const* _Tm
    );

 

 size_t __cdecl _strftime_l(
           char*            _Buffer,
                               size_t           _MaxSize,
        char const*      _Format,
                               struct tm const* _Tm,
                           _locale_t        _Locale
    );


 errno_t __cdecl _strdate_s(
       char*  _Buffer,
                                                                              size_t _SizeInBytes
    );

extern "C++"                                                                                      {                                                                                                     template <size_t _Size>                                                                           inline                                                                                            errno_t __cdecl _strdate_s(  char (&_Buffer)[_Size]) throw()                  {                                                                                                     return _strdate_s(_Buffer, _Size);                                                                }                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))    char* __cdecl _strdate(  char *_Buffer);


 errno_t __cdecl _strtime_s(
       char*  _Buffer,
                                                                              size_t _SizeInBytes
    );

extern "C++"                                                                                      {                                                                                                     template <size_t _Size>                                                                           inline                                                                                            errno_t __cdecl _strtime_s(  char (&_Buffer)[_Size]) throw()                  {                                                                                                     return _strtime_s(_Buffer, _Size);                                                                }                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _strtime(  char *_Buffer);

 __time32_t __cdecl _time32(
      __time32_t* _Time
    );

 __time64_t __cdecl _time64(
      __time64_t* _Time
    );

 
 
 int __cdecl _timespec32_get(
      struct _timespec32* _Ts,
       int                 _Base
    );

 
 
 int __cdecl _timespec64_get(
      struct _timespec64* _Ts,
       int                 _Base
    );



     
     void __cdecl _tzset(void);

         __declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using GetLocalTime instead. See online help for details."))
     unsigned __cdecl _getsystime(
          struct tm* _Tm
        );

    __declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using SetLocalTime instead. See online help for details."))
     unsigned __cdecl _setsystime(
          struct tm* _Tm,
          unsigned   _Milliseconds
        );




     

          __declspec(deprecated("This function or variable may be unsafe. Consider using ctime_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
        static __inline char* __cdecl ctime(
              time_t const* const _Time
            )
        {
            return _ctime64(_Time);
        }

         
        static __inline double __cdecl difftime(
              time_t const _Time1,
              time_t const _Time2
            )
        {
            return _difftime64(_Time1, _Time2);
        }

          __declspec(deprecated("This function or variable may be unsafe. Consider using gmtime_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
        static __inline struct tm* __cdecl gmtime(
              time_t const* const _Time)
        {
            return _gmtime64(_Time);
        }

        __declspec(deprecated("This function or variable may be unsafe. Consider using localtime_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
        static __inline struct tm* __cdecl localtime(
              time_t const* const _Time
            )
        {
            return _localtime64(_Time);
        }

         
        static __inline time_t __cdecl _mkgmtime(
              struct tm* const _Tm
            )
        {
            return _mkgmtime64(_Tm);
        }

        
        static __inline time_t __cdecl mktime(
              struct tm* const _Tm
            )
        {
            return _mktime64(_Tm);
        }

        static __inline time_t __cdecl time(
              time_t* const _Time
            )
        {
            return _time64(_Time);
        }

         
        static __inline int __cdecl timespec_get(
              struct timespec* const _Ts,
               int              const _Base
            )
        {
            return _timespec64_get((struct _timespec64*)_Ts, _Base);
        }

            
            static __inline errno_t __cdecl ctime_s(
                    char*         const _Buffer,
                                                    size_t        const _SizeInBytes,
                                                                 time_t const* const _Time
                )
            {
                return _ctime64_s(_Buffer, _SizeInBytes, _Time);
            }

            
            static __inline errno_t __cdecl gmtime_s(
                  struct tm*    const _Tm,
                   time_t const* const _Time
                )
            {
                return _gmtime64_s(_Tm, _Time);
            }

            
            static __inline errno_t __cdecl localtime_s(
                  struct tm*    const _Tm,
                   time_t const* const _Time
                )
            {
                return _localtime64_s(_Tm, _Time);
            }





     

        __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _tzset. See online help for details."))  void __cdecl tzset(void);




}                             


