         
       
                     
  

    
 

 





  

 


 

      
   
    
  
 
  
 
  
   
   
 

   
 
  

 
  
 
  

 


 



 
   
 





 
    

  
 


 



 
               

 

 

    

 








 



  
 

 
    
 
 
  
 
 

 
 
 

 
  
   
 




   
   

   

   
 

 

   
    
  
 

 
 
    
  
 
 
 
 




 

  
 
 
  
 
  
  

   
 
 
  
 
   
 
 
  
  
 

 

  

  



 


  



 
 
 
 
    
 
  
 
 
 


 


  
 
 
 

 
    
 
  
 
 
 


 


  
 
 
 

   

   
   
 
  
 
 
 
  
 
 
 

 
 
  
 
 
  
 
 
 


 


  
 
 
 

  
 
 
 
    



     









    



   

    
      
   




 



























 

 
 


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



     int* __cdecl _errno(void);

     errno_t __cdecl _set_errno(  int _Value);
     errno_t __cdecl _get_errno(  int* _Value);

     unsigned long* __cdecl __doserrno(void);

     errno_t __cdecl _set_doserrno(  unsigned long _Value);
     errno_t __cdecl _get_doserrno(  unsigned long * _Value);



 
 
 
 


}                             

       
       


         extern "C" {



  
 void const* __cdecl memchr(
      void const* _Buf,
                                 int         _Val,
                                 size_t      _MaxCount
    );

  
int __cdecl memcmp(
      void const* _Buf1,
      void const* _Buf2,
                         size_t      _Size
    );


 

void* __cdecl memcpy(
      void* _Dst,
            void const* _Src,
                               size_t      _Size
    );


 void* __cdecl memmove(
      void*       _Dst,
            void const* _Src,
                                   size_t      _Size
    );

 

void* __cdecl memset(
      void*  _Dst,
                               int    _Val,
                               size_t _Size
    );

  
 char const* __cdecl strchr(
      char const* _Str,
        int         _Val
    );

  
 char const* __cdecl strrchr(
      char const* _Str,
        int         _Ch
    );

    
 char const* __cdecl strstr(
      char const* _Str,
      char const* _SubStr
    );

  

 wchar_t const* __cdecl wcschr(
      wchar_t const* _Str,
        wchar_t        _Ch
    );

  
 wchar_t const* __cdecl wcsrchr(
      wchar_t const* _Str,
        wchar_t        _Ch
    );

    

 wchar_t const* __cdecl wcsstr(
      wchar_t const* _Str,
      wchar_t const* _SubStr
    );



}                             





         extern "C" {




     
    
    static __inline errno_t __cdecl memcpy_s(
          void*       const _Destination,
                                                              rsize_t     const _DestinationSize,
                                 void const* const _Source,
                                                              rsize_t     const _SourceSize
        )
    {
        if (_SourceSize == 0)
        {
            return 0;
        }

        {                                                                                  int _Expr_val=!!(_Destination != 0);                                                        if (!(_Expr_val))                                                              {                                                                                  (*_errno()) = 22;                                                             _invalid_parameter_noinfo();                                                   return 22;                                                          }                                                                          };
        if (_Source == 0 || _DestinationSize < _SourceSize)
        {
            memset(_Destination, 0, _DestinationSize);

            {                                                                                  int _Expr_val=!!(_Source != 0);                                                        if (!(_Expr_val))                                                              {                                                                                  (*_errno()) = 22;                                                             _invalid_parameter_noinfo();                                                   return 22;                                                          }                                                                          };
            {                                                                                  int _Expr_val=!!(_DestinationSize >= _SourceSize);                                                        if (!(_Expr_val))                                                              {                                                                                  (*_errno()) = 34;                                                             _invalid_parameter_noinfo();                                                   return 34;                                                          }                                                                          };

                         return 22;
        }
        memcpy(_Destination, _Source, _SourceSize);
        return 0;
    }

    
    static __inline errno_t __cdecl memmove_s(
          void*       const _Destination,
                                                              rsize_t     const _DestinationSize,
                                 void const* const _Source,
                                                              rsize_t     const _SourceSize
        )
    {
        if (_SourceSize == 0)
        {
            return 0;
        }

        {                                                                                  int _Expr_val=!!(_Destination != 0);                                                        if (!(_Expr_val))                                                              {                                                                                  (*_errno()) = 22;                                                             _invalid_parameter_noinfo();                                                   return 22;                                                          }                                                                          };
        {                                                                                  int _Expr_val=!!(_Source != 0);                                                        if (!(_Expr_val))                                                              {                                                                                  (*_errno()) = 22;                                                             _invalid_parameter_noinfo();                                                   return 22;                                                          }                                                                          };
        {                                                                                  int _Expr_val=!!(_DestinationSize >= _SourceSize);                                                        if (!(_Expr_val))                                                              {                                                                                  (*_errno()) = 34;                                                             _invalid_parameter_noinfo();                                                   return 34;                                                          }                                                                          };

        memmove(_Destination, _Source, _SourceSize);
        return 0;
    }




}                             
        
              
       


         extern "C" {






          

   
                 
    
    __declspec(noinline) __inline unsigned __int64* __cdecl __local_stdio_printf_options(void)
    {
        static unsigned __int64 _OptionsStorage;
        return &_OptionsStorage;
    }

                 
    
    __declspec(noinline) __inline unsigned __int64* __cdecl __local_stdio_scanf_options(void)
    {
        static unsigned __int64 _OptionsStorage;
        return &_OptionsStorage;
    }










}                             




         extern "C" {





    
     
     errno_t __cdecl _cgetws_s(
          wchar_t* _Buffer,
                                               size_t   _BufferCount,
                                              size_t*  _SizeRead
        );

    extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                                    errno_t __cdecl _cgetws_s(  wchar_t (&_Buffer)[_Size],                       size_t* _SizeRead) throw()                 {                                                                                                                    return _cgetws_s(_Buffer, _Size, _SizeRead);                                                                       }                                                                                                            }

    
     int __cdecl _cputws(
          wchar_t const* _Buffer
        );

           wint_t __cdecl _getwch  (void);
           wint_t __cdecl _getwche (void);
      wint_t __cdecl _putwch  (  wchar_t _Character);
      wint_t __cdecl _ungetwch(  wint_t  _Character);

           wint_t __cdecl _getwch_nolock  (void);
           wint_t __cdecl _getwche_nolock (void);
      wint_t __cdecl _putwch_nolock  (  wchar_t _Character);
      wint_t __cdecl _ungetwch_nolock(  wint_t  _Character);



                             
     int __cdecl __conio_common_vcwprintf(
                                             unsigned __int64 _Options,
            wchar_t const*   _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

    
     int __cdecl __conio_common_vcwprintf_s(
                                             unsigned __int64 _Options,
            wchar_t const*   _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

    
     int __cdecl __conio_common_vcwprintf_p(
                                             unsigned __int64 _Options,
            wchar_t const*   _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

    
    __inline int __cdecl _vcwprintf_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    {
        return __conio_common_vcwprintf((*__local_stdio_printf_options()), _Format, _Locale, _ArgList);
    }

    
    __inline int __cdecl _vcwprintf(
            wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    {
        return _vcwprintf_l(_Format, 0, _ArgList);
    }

    
    __inline int __cdecl _vcwprintf_s_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    {
        return __conio_common_vcwprintf_s((*__local_stdio_printf_options()), _Format, _Locale, _ArgList);
    }

    
    __inline int __cdecl _vcwprintf_s(
            wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    {
        return _vcwprintf_s_l(_Format, 0, _ArgList);
    }

    
    __inline int __cdecl _vcwprintf_p_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    {
        return __conio_common_vcwprintf_p((*__local_stdio_printf_options()), _Format, _Locale, _ArgList);
    }

    
    __inline int __cdecl _vcwprintf_p(
            const wchar_t* const _Format,
                                      va_list              _ArgList
        )
    {
        return _vcwprintf_p_l(_Format, 0, _ArgList);
    }

    
    __inline int __cdecl _cwprintf_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vcwprintf_l(_Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _cwprintf(
            wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vcwprintf_l(_Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _cwprintf_s_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vcwprintf_s_l(_Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _cwprintf_s(
            wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vcwprintf_s_l(_Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _cwprintf_p_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vcwprintf_p_l(_Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _cwprintf_p(
            wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vcwprintf_p_l(_Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }



                             
     int __cdecl __conio_common_vcwscanf(
                                            unsigned __int64 _Options,
            wchar_t const*   _Format,
                                        _locale_t        _Locale,
                                               va_list          _ArgList
        );

     __declspec(deprecated("This function or variable may be unsafe. Consider using _vcwscanf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _vcwscanf_l(
            wchar_t const* const _Format,
                                        _locale_t      const _Locale,
                                               va_list              _ArgList
        )
    {
        return __conio_common_vcwscanf(
            (*__local_stdio_scanf_options ()),
            _Format, _Locale, _ArgList);
    }

     __declspec(deprecated("This function or variable may be unsafe. Consider using _vcwscanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _vcwscanf(
            wchar_t const* const _Format,
                                               va_list              _ArgList
        )
    {
        return _vcwscanf_l(_Format, 0, _ArgList);
    }

    
    __inline int __cdecl _vcwscanf_s_l(
            wchar_t const* const _Format,
                                        _locale_t      const _Locale,
                                               va_list              _ArgList
        )
    {
        return __conio_common_vcwscanf(
            (*__local_stdio_scanf_options ()) | (1ULL << 0),
            _Format, _Locale, _ArgList);
    }

    
    __inline int __cdecl _vcwscanf_s(
            wchar_t const* const _Format,
                                               va_list              _ArgList
        )
    {
        return _vcwscanf_s_l(_Format, 0, _ArgList);
    }

     __declspec(deprecated("This function or variable may be unsafe. Consider using _cwscanf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _cwscanf_l(
            wchar_t const* const _Format,
                                        _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));

        _Result = _vcwscanf_l(_Format, _Locale, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     __declspec(deprecated("This function or variable may be unsafe. Consider using _cwscanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _cwscanf(
            wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));

        _Result = _vcwscanf_l(_Format, 0, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _cwscanf_s_l(
            wchar_t const* const _Format,
                                        _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vcwscanf_s_l(_Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _cwscanf_s(
            wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vcwscanf_s_l(_Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


}                             

        
       


         extern "C" {






  

     const unsigned short* __cdecl __pctype_func(void);
     const wctype_t*       __cdecl __pwctype_func(void);


 



        int __cdecl iswalnum  (  wint_t _C);
   int __cdecl iswalpha  (  wint_t _C);
   int __cdecl iswascii  (  wint_t _C);
   int __cdecl iswblank  (  wint_t _C);
   int __cdecl iswcntrl  (  wint_t _C);


   int __cdecl iswdigit  (  wint_t _C);

   int __cdecl iswgraph  (  wint_t _C);
   int __cdecl iswlower  (  wint_t _C);
   int __cdecl iswprint  (  wint_t _C);
   int __cdecl iswpunct  (  wint_t _C);
   int __cdecl iswspace  (  wint_t _C);
   int __cdecl iswupper  (  wint_t _C);
   int __cdecl iswxdigit (  wint_t _C);
   int __cdecl __iswcsymf(  wint_t _C);
   int __cdecl __iswcsym (  wint_t _C);

   int __cdecl _iswalnum_l (  wint_t _C,   _locale_t _Locale);
   int __cdecl _iswalpha_l (  wint_t _C,   _locale_t _Locale);
   int __cdecl _iswblank_l (  wint_t _C,   _locale_t _Locale);
   int __cdecl _iswcntrl_l (  wint_t _C,   _locale_t _Locale);
   int __cdecl _iswdigit_l (  wint_t _C,   _locale_t _Locale);
   int __cdecl _iswgraph_l (  wint_t _C,   _locale_t _Locale);
   int __cdecl _iswlower_l (  wint_t _C,   _locale_t _Locale);
   int __cdecl _iswprint_l (  wint_t _C,   _locale_t _Locale);
   int __cdecl _iswpunct_l (  wint_t _C,   _locale_t _Locale);
   int __cdecl _iswspace_l (  wint_t _C,   _locale_t _Locale);
   int __cdecl _iswupper_l (  wint_t _C,   _locale_t _Locale);
   int __cdecl _iswxdigit_l(  wint_t _C,   _locale_t _Locale);
   int __cdecl _iswcsymf_l (  wint_t _C,   _locale_t _Locale);
   int __cdecl _iswcsym_l  (  wint_t _C,   _locale_t _Locale);


   wint_t __cdecl towupper(  wint_t _C);
   wint_t __cdecl towlower(  wint_t _C);
   int    __cdecl iswctype(  wint_t _C,   wctype_t _Type);

   wint_t __cdecl _towupper_l(  wint_t _C,   _locale_t _Locale);
   wint_t __cdecl _towlower_l(  wint_t _C,   _locale_t _Locale);
   int    __cdecl _iswctype_l(  wint_t _C,   wctype_t _Type,   _locale_t _Locale);


       int __cdecl isleadbyte(  int _C);
       int __cdecl _isleadbyte_l(  int _C,   _locale_t _Locale);

    __declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using iswctype instead. See online help for details."))  int __cdecl is_wctype(  wint_t _C,   wctype_t _Type);



     


}                             

        
       


         extern "C" {


 
   
 __declspec(allocator) wchar_t* __cdecl _wgetcwd(
      wchar_t* _DstBuf,
                                  int      _SizeInWords
    );

 
   
 __declspec(allocator) wchar_t* __cdecl _wgetdcwd(
                                  int      _Drive,
      wchar_t* _DstBuf,
                                  int      _SizeInWords
    );



 
 int __cdecl _wchdir(
      wchar_t const* _Path
    );

 
 int __cdecl _wmkdir(
      wchar_t const* _Path
    );

 
 int __cdecl _wrmdir(
      wchar_t const* _Path
    );



}                             

        
               
       










         extern "C" {

     
typedef unsigned long _fsize_t;

struct _wfinddata32_t
{
    unsigned   attrib;
    __time32_t time_create;         __time32_t time_access;         __time32_t time_write;
    _fsize_t   size;
    wchar_t    name[260];
};

struct _wfinddata32i64_t
{
    unsigned   attrib;
    __time32_t time_create;         __time32_t time_access;         __time32_t time_write;
    __int64    size;
    wchar_t    name[260];
};

struct _wfinddata64i32_t
{
    unsigned   attrib;
    __time64_t time_create;         __time64_t time_access;         __time64_t time_write;
    _fsize_t   size;
    wchar_t    name[260];
};

struct _wfinddata64_t
{
    unsigned   attrib;
    __time64_t time_create;         __time64_t time_access;         __time64_t time_write;
    __int64    size;
    wchar_t    name[260];
};



     
 
 int __cdecl _waccess(
      wchar_t const* _FileName,
        int            _AccessMode
    );


 errno_t __cdecl _waccess_s(
      wchar_t const* _FileName,
        int            _AccessMode
    );

 
 int __cdecl _wchmod(
      wchar_t const* _FileName,
        int            _Mode
    );

  __declspec(deprecated("This function or variable may be unsafe. Consider using _wsopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 int __cdecl _wcreat(
      wchar_t const* _FileName,
        int            _PermissionMode
    );

 
 
 intptr_t __cdecl _wfindfirst32(
      wchar_t const*         _FileName,
       struct _wfinddata32_t* _FindData
    );

 
 
 int __cdecl _wfindnext32(
       intptr_t               _FindHandle,
      struct _wfinddata32_t* _FindData
    );

 int __cdecl _wunlink(
      wchar_t const* _FileName
    );

 
 int __cdecl _wrename(
      wchar_t const* _OldFileName,
      wchar_t const* _NewFileName
    );

 errno_t __cdecl _wmktemp_s(
      wchar_t* _TemplateName,
                                 size_t   _SizeInWords
    );

extern "C++"                                                                                      {                                                                                                     template <size_t _Size>                                                                           inline                                                                                            errno_t __cdecl _wmktemp_s(wchar_t (&_TemplateName)[_Size]) throw()                  {                                                                                                     return _wmktemp_s(_TemplateName, _Size);                                                                }                                                                                             }

 
__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _wmktemp(  wchar_t *_TemplateName);

 
 
 intptr_t __cdecl _wfindfirst32i64(
      wchar_t const*            _FileName,
       struct _wfinddata32i64_t* _FindData
    );

 
 
 intptr_t __cdecl _wfindfirst64i32(
      wchar_t const*            _FileName,
       struct _wfinddata64i32_t* _FindData
    );

 
 
 intptr_t __cdecl _wfindfirst64(
      wchar_t const*         _FileName,
       struct _wfinddata64_t* _FindData
    );

 
 
 int __cdecl _wfindnext32i64(
       intptr_t                  _FindHandle,
      struct _wfinddata32i64_t* _FindData
    );

 
 
 int __cdecl _wfindnext64i32(
       intptr_t                  _FindHandle,
      struct _wfinddata64i32_t* _FindData
    );

 
 
 int __cdecl _wfindnext64(
       intptr_t               _FindHandle,
      struct _wfinddata64_t* _FindData
    );


 errno_t __cdecl _wsopen_s(
       int*           _FileHandle,
      wchar_t const* _FileName,
        int            _OpenFlag,
        int            _ShareFlag,
        int            _PermissionFlag
    );

 errno_t __cdecl _wsopen_dispatch(
      wchar_t const* _FileName,
        int            _OFlag,
        int            _ShFlag,
        int            _PMode,
       int*           _PFileHandle,
        int            _BSecure
    );




         extern "C++"   __declspec(deprecated("This function or variable may be unsafe. Consider using _wsopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    inline int __cdecl _wopen(
          wchar_t const* _FileName,
            int            _OFlag,
            int            _PMode = 0
        )
    {
        int _FileHandle;
                 errno_t const _Result = _wsopen_dispatch(_FileName, _OFlag, 0x40, _PMode, &_FileHandle, 0);
        return _Result ? -1 : _FileHandle;
    }

    extern "C++"   __declspec(deprecated("This function or variable may be unsafe. Consider using _wsopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    inline int __cdecl _wsopen(
          wchar_t const* _FileName,
            int            _OFlag,
            int            _ShFlag,
            int            _PMode = 0
        )
    {
        int _FileHandle;
                 errno_t const _Result = _wsopen_dispatch(_FileName, _OFlag, _ShFlag, _PMode, &_FileHandle, 0);
        return _Result ? -1 : _FileHandle;
    }



}                             

        
       


         extern "C" {




         intptr_t __cdecl _wexecl(
              wchar_t const* _FileName,
              wchar_t const* _ArgList,
            ...);

         intptr_t __cdecl _wexecle(
              wchar_t const* _FileName,
              wchar_t const* _ArgList,
            ...);

         intptr_t __cdecl _wexeclp(
              wchar_t const* _FileName,
              wchar_t const* _ArgList,
            ...);

         intptr_t __cdecl _wexeclpe(
              wchar_t const* _FileName,
              wchar_t const* _ArgList,
            ...);

         intptr_t __cdecl _wexecv(
              wchar_t const*        _FileName,
              wchar_t const* const* _ArgList
            );

         intptr_t __cdecl _wexecve(
                  wchar_t const*        _FileName,
                  wchar_t const* const* _ArgList,
              wchar_t const* const* _Env
            );

         intptr_t __cdecl _wexecvp(
              wchar_t const*        _FileName,
              wchar_t const* const* _ArgList
            );

         intptr_t __cdecl _wexecvpe(
                  wchar_t const*        _FileName,
                  wchar_t const* const* _ArgList,
              wchar_t const* const* _Env
            );

         intptr_t __cdecl _wspawnl(
                int            _Mode,
              wchar_t const* _FileName,
              wchar_t const* _ArgList,
            ...);

         intptr_t __cdecl _wspawnle(
                int            _Mode,
              wchar_t const* _FileName,
              wchar_t const* _ArgList,
            ...);

         intptr_t __cdecl _wspawnlp(
                int            _Mode,
              wchar_t const* _FileName,
              wchar_t const* _ArgList,
            ...);

         intptr_t __cdecl _wspawnlpe(
                int            _Mode,
              wchar_t const* _FileName,
              wchar_t const* _ArgList,
            ...);

         intptr_t __cdecl _wspawnv(
                int                   _Mode,
              wchar_t const*        _FileName,
              wchar_t const* const* _ArgList
            );

         intptr_t __cdecl _wspawnve(
                    int                   _Mode,
                  wchar_t const*        _FileName,
                  wchar_t const* const* _ArgList,
              wchar_t const* const* _Env
            );

         intptr_t __cdecl _wspawnvp(
                int                   _Mode,
              wchar_t const*        _FileName,
              wchar_t const* const* _ArgList
            );

         intptr_t __cdecl _wspawnvpe(
                    int                   _Mode,
                  wchar_t const*        _FileName,
                  wchar_t const* const* _ArgList,
              wchar_t const* const* _Env
            );

         int __cdecl _wsystem(
              wchar_t const* _Command
            );




}                             

         
              


         extern "C" {

         typedef struct _iobuf
    {
        void* _Placeholder;
    } FILE;

 FILE* __cdecl __acrt_iob_func(unsigned _Ix);





                             
     wint_t __cdecl fgetwc(
          FILE* _Stream
        );

    
     wint_t __cdecl _fgetwchar(void);

    
     wint_t __cdecl fputwc(
             wchar_t _Character,
          FILE*   _Stream);

    
     wint_t __cdecl _fputwchar(
          wchar_t _Character
        );

     
     wint_t __cdecl getwc(
          FILE* _Stream
        );

     
     wint_t __cdecl getwchar(void);


    
     
     wchar_t* __cdecl fgetws(
          wchar_t* _Buffer,
                                  int      _BufferCount,
                               FILE*    _Stream
        );

    
     int __cdecl fputws(
           wchar_t const* _Buffer,
          FILE*          _Stream
        );

    
     
     wchar_t* __cdecl _getws_s(
          wchar_t* _Buffer,
                                  size_t   _BufferCount
        );

    extern "C++"                                                                                      {                                                                                                     template <size_t _Size>                                                                           inline                                                                                                     wchar_t* __cdecl _getws_s( wchar_t (&_Buffer)[_Size]) throw()                  {                                                                                                     return _getws_s(_Buffer, _Size);                                                                }                                                                                             }

    
     wint_t __cdecl putwc(
             wchar_t _Character,
          FILE*   _Stream
        );

    
     wint_t __cdecl putwchar(
          wchar_t _Character
        );

    
     int __cdecl _putws(
          wchar_t const* _Buffer
        );

    
     wint_t __cdecl ungetwc(
             wint_t _Character,
          FILE*  _Stream
        );

     
     FILE * __cdecl _wfdopen(
            int            _FileHandle,
          wchar_t const* _Mode
        );

      __declspec(deprecated("This function or variable may be unsafe. Consider using _wfopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
     FILE* __cdecl _wfopen(
          wchar_t const* _FileName,
          wchar_t const* _Mode
        );

    
     errno_t __cdecl _wfopen_s(
          FILE**         _Stream,
                             wchar_t const* _FileName,
                             wchar_t const* _Mode
        );

     
    __declspec(deprecated("This function or variable may be unsafe. Consider using _wfreopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
     FILE* __cdecl _wfreopen(
           wchar_t const* _FileName,
           wchar_t const* _Mode,
          FILE*          _OldStream
        );

    
     errno_t __cdecl _wfreopen_s(
          FILE**         _Stream,
                             wchar_t const* _FileName,
                             wchar_t const* _Mode,
                            FILE*          _OldStream
        );

     
     FILE* __cdecl _wfsopen(
          wchar_t const* _FileName,
          wchar_t const* _Mode,
            int            _ShFlag
        );

     void __cdecl _wperror(
          wchar_t const* _ErrorMessage
        );


         
         FILE* __cdecl _wpopen(
              wchar_t const* _Command,
              wchar_t const* _Mode
            );


     int __cdecl _wremove(
          wchar_t const* _FileName
        );


     
     __declspec(allocator) wchar_t* __cdecl _wtempnam(
          wchar_t const* _Directory,
          wchar_t const* _FilePrefix
        );


     
    
     errno_t __cdecl _wtmpnam_s(
          wchar_t* _Buffer,
                                  size_t   _BufferCount
        );

    extern "C++"                                                                                      {                                                                                                     template <size_t _Size>                                                                           inline                                                                                                     errno_t __cdecl _wtmpnam_s( wchar_t (&_Buffer)[_Size]) throw()                  {                                                                                                     return _wtmpnam_s(_Buffer, _Size);                                                                }                                                                                             }

    __declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))           wchar_t* __cdecl _wtmpnam(   wchar_t *_Buffer);



                             
     wint_t __cdecl _fgetwc_nolock(
          FILE* _Stream
        );

    
     wint_t __cdecl _fputwc_nolock(
             wchar_t _Character,
          FILE*   _Stream
        );

    
     wint_t __cdecl _getwc_nolock(
          FILE* _Stream
        );

    
     wint_t __cdecl _putwc_nolock(
             wchar_t _Character,
          FILE*   _Stream
        );

    
     wint_t __cdecl _ungetwc_nolock(
             wint_t _Character,
          FILE*  _Stream
        );




     


                             
     int __cdecl __stdio_common_vfwprintf(
                                             unsigned __int64 _Options,
                                          FILE*            _Stream,
            wchar_t const*   _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

    
     int __cdecl __stdio_common_vfwprintf_s(
                                             unsigned __int64 _Options,
                                          FILE*            _Stream,
            wchar_t const*   _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

    
     int __cdecl __stdio_common_vfwprintf_p(
                                             unsigned __int64 _Options,
                                          FILE*            _Stream,
            wchar_t const*   _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

    
    __inline int __cdecl _vfwprintf_l(
                                          FILE*          const _Stream,
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    {
        return __stdio_common_vfwprintf((*__local_stdio_printf_options()), _Stream, _Format, _Locale, _ArgList);
    }

    
    __inline int __cdecl vfwprintf(
                                FILE*          const _Stream,
            wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    {
        return _vfwprintf_l(_Stream, _Format, 0, _ArgList);
    }

    
    __inline int __cdecl _vfwprintf_s_l(
                                          FILE*          const _Stream,
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    {
        return __stdio_common_vfwprintf_s((*__local_stdio_printf_options()), _Stream, _Format, _Locale, _ArgList);
    }


        
        __inline int __cdecl vfwprintf_s(
                                    FILE*          const _Stream,
                wchar_t const* const _Format,
                                          va_list              _ArgList
            )
        {
            return _vfwprintf_s_l(_Stream, _Format, 0, _ArgList);
        }


    
    __inline int __cdecl _vfwprintf_p_l(
                                          FILE*          const _Stream,
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    {
        return __stdio_common_vfwprintf_p((*__local_stdio_printf_options()), _Stream, _Format, _Locale, _ArgList);
    }

    
    __inline int __cdecl _vfwprintf_p(
                                FILE*          const _Stream,
            wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    {
        return _vfwprintf_p_l(_Stream, _Format, 0, _ArgList);
    }

    
    __inline int __cdecl _vwprintf_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    {
        return _vfwprintf_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
    }

    
    __inline int __cdecl vwprintf(
            wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    {
        return _vfwprintf_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
    }

    
    __inline int __cdecl _vwprintf_s_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    {
        return _vfwprintf_s_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
    }


        
        __inline int __cdecl vwprintf_s(
                wchar_t const* const _Format,
                                          va_list              _ArgList
            )
        {
            return _vfwprintf_s_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
        }


    
    __inline int __cdecl _vwprintf_p_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    {
        return _vfwprintf_p_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
    }

    
    __inline int __cdecl _vwprintf_p(
            wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    {
        return _vfwprintf_p_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
    }

    
    __inline int __cdecl _fwprintf_l(
                                          FILE*          const _Stream,
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfwprintf_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl fwprintf(
                                FILE*          const _Stream,
            wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vfwprintf_l(_Stream, _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _fwprintf_s_l(
                                          FILE*          const _Stream,
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfwprintf_s_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


        
        __inline int __cdecl fwprintf_s(
                                    FILE*          const _Stream,
                wchar_t const* const _Format,
            ...)
        {
            int _Result;
            va_list _ArgList;
            ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
            _Result = _vfwprintf_s_l(_Stream, _Format, 0, _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }


    
    __inline int __cdecl _fwprintf_p_l(
                                          FILE*          const _Stream,
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfwprintf_p_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _fwprintf_p(
                                FILE*          const _Stream,
            wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vfwprintf_p_l(_Stream, _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _wprintf_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfwprintf_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl wprintf(
            wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vfwprintf_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _wprintf_s_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfwprintf_s_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


        
        __inline int __cdecl wprintf_s(
                wchar_t const* const _Format,
            ...)
        {
            int _Result;
            va_list _ArgList;
            ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
            _Result = _vfwprintf_s_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }


    
    __inline int __cdecl _wprintf_p_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfwprintf_p_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _wprintf_p(
            wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vfwprintf_p_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


                             
     int __cdecl __stdio_common_vfwscanf(
                                            unsigned __int64 _Options,
                                         FILE*            _Stream,
            wchar_t const*   _Format,
                                        _locale_t        _Locale,
                                               va_list          _ArgList
        );

    
    __inline int __cdecl _vfwscanf_l(
          FILE*                                const _Stream,
            wchar_t const* const _Format,
                               _locale_t      const _Locale,
                                      va_list              _ArgList
        )
    {
        return __stdio_common_vfwscanf(
            (*__local_stdio_scanf_options ()),
            _Stream, _Format, _Locale, _ArgList);
    }

    
    __inline int __cdecl vfwscanf(
          FILE*                                const _Stream,
            wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    {
        return _vfwscanf_l(_Stream, _Format, 0, _ArgList);
    }

    
    __inline int __cdecl _vfwscanf_s_l(
                                FILE*          const _Stream,
            wchar_t const* const _Format,
                               _locale_t      const _Locale,
                                      va_list              _ArgList
        )
    {
        return __stdio_common_vfwscanf(
            (*__local_stdio_scanf_options ()) | (1ULL << 0),
            _Stream, _Format, _Locale, _ArgList);
    }


        
        __inline int __cdecl vfwscanf_s(
                                    FILE*          const _Stream,
                wchar_t const* const _Format,
                                          va_list              _ArgList
            )
        {
            return _vfwscanf_s_l(_Stream, _Format, 0, _ArgList);
        }


    __inline int __cdecl _vwscanf_l(
            wchar_t const* const _Format,
                               _locale_t      const _Locale,
                                      va_list              _ArgList
        )
    {
        return _vfwscanf_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
    }

    
    __inline int __cdecl vwscanf(
            wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    {
        return _vfwscanf_l((__acrt_iob_func(0)), _Format, 0, _ArgList);
    }

    
    __inline int __cdecl _vwscanf_s_l(
            wchar_t const* const _Format,
                               _locale_t      const _Locale,
                                      va_list              _ArgList
        )
    {
        return _vfwscanf_s_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
    }


        
        __inline int __cdecl vwscanf_s(
                wchar_t const* const _Format,
                                          va_list              _ArgList
            )
        {
            return _vfwscanf_s_l((__acrt_iob_func(0)), _Format, 0, _ArgList);
        }


     __declspec(deprecated("This function or variable may be unsafe. Consider using _fwscanf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _fwscanf_l(
                                         FILE*          const _Stream,
            wchar_t const* const _Format,
                                        _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfwscanf_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

      __declspec(deprecated("This function or variable may be unsafe. Consider using fwscanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl fwscanf(
                               FILE*          const _Stream,
            wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vfwscanf_l(_Stream, _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _fwscanf_s_l(
                                           FILE*          const _Stream,
            wchar_t const* const _Format,
                                          _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfwscanf_s_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


        
        __inline int __cdecl fwscanf_s(
                                     FILE*          const _Stream,
                wchar_t const* const _Format,
            ...)
        {
            int _Result;
            va_list _ArgList;
            ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
            _Result = _vfwscanf_s_l(_Stream, _Format, 0, _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }


     __declspec(deprecated("This function or variable may be unsafe. Consider using _wscanf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _wscanf_l(
            wchar_t const* const _Format,
                                        _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfwscanf_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

      __declspec(deprecated("This function or variable may be unsafe. Consider using wscanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl wscanf(
            wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vfwscanf_l((__acrt_iob_func(0)), _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _wscanf_s_l(
            wchar_t const* const _Format,
                                          _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfwscanf_s_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


        
        __inline int __cdecl wscanf_s(
                wchar_t const* const _Format,
            ...)
        {
            int _Result;
            va_list _ArgList;
            ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
            _Result = _vfwscanf_s_l((__acrt_iob_func(0)), _Format, 0, _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }




                         
     
    
     int __cdecl __stdio_common_vswprintf(
                                             unsigned __int64 _Options,
                 wchar_t*         _Buffer,
                                             size_t           _BufferCount,
            wchar_t const*   _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     
    
     int __cdecl __stdio_common_vswprintf_s(
                                             unsigned __int64 _Options,
                     wchar_t*         _Buffer,
                                             size_t           _BufferCount,
            wchar_t const*   _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     
    
     int __cdecl __stdio_common_vsnwprintf_s(
                                             unsigned __int64 _Options,
                 wchar_t*         _Buffer,
                                             size_t           _BufferCount,
                                             size_t           _MaxCount,
            wchar_t const*   _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     
    
     int __cdecl __stdio_common_vswprintf_p(
                                             unsigned __int64 _Options,
                     wchar_t*         _Buffer,
                                             size_t           _BufferCount,
            wchar_t const*   _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     
     __declspec(deprecated("This function or variable may be unsafe. Consider using _vsnwprintf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _vsnwprintf_l(
            wchar_t*       const _Buffer,
                                                  size_t         const _BufferCount,
                 wchar_t const* const _Format,
                                              _locale_t      const _Locale,
                                                     va_list              _ArgList
        )
    {
        int const _Result = __stdio_common_vswprintf(
            (*__local_stdio_printf_options()) | (1ULL << 0),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }

     
    
    __inline int __cdecl _vsnwprintf_s_l(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                                                       size_t         const _MaxCount,
                      wchar_t const* const _Format,
                                                   _locale_t      const _Locale,
                                                          va_list              _ArgList
        )
    {
        int const _Result = __stdio_common_vsnwprintf_s(
            (*__local_stdio_printf_options()),
            _Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }

     
    
    __inline int __cdecl _vsnwprintf_s(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                                                       size_t         const _MaxCount,
                                wchar_t const* const _Format,
                                                          va_list              _ArgList
        )
    {
        return _vsnwprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, 0, _ArgList);
    }

    __declspec(deprecated("This function or variable may be unsafe. Consider using _FuncName##_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) __inline          int __cdecl _snwprintf(    wchar_t *_Buffer,                                            size_t _BufferCount,                     wchar_t const* _Format, ...);                 __declspec(deprecated("This function or variable may be unsafe. Consider using _VFuncName##_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) __inline          int __cdecl _vsnwprintf(    wchar_t *_Buffer,                                            size_t _BufferCount,                     wchar_t const* _Format, va_list _Args);

     
     __declspec(deprecated("This function or variable may be unsafe. Consider using _vsnwprintf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _vsnwprintf(
            wchar_t*       _Buffer,
                                                  size_t         _BufferCount,
                           wchar_t const* _Format,
                                                     va_list        _ArgList
        )
    {
        return _vsnwprintf_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
    }

    extern "C++"                                                                                                                                     {                                                                                                                                                    template <size_t _Size>                                                                                                                          inline                                                                                                                                                    int __cdecl _vsnwprintf_s(            wchar_t (&_Buffer)[_Size],                            size_t _BufferCount,     wchar_t const* _Format, va_list _ArgList) throw()                 {                                                                                                                                                    return _vsnwprintf_s(_Buffer, _Size, _BufferCount, _Format, _ArgList);                                                                                       }                                                                                                                                            }

     
    
    __inline int __cdecl _vswprintf_c_l(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                      wchar_t const* const _Format,
                                                   _locale_t      const _Locale,
                                                          va_list              _ArgList
        )
    {
        int const _Result = __stdio_common_vswprintf(
            (*__local_stdio_printf_options()),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }

     
    
    __inline int __cdecl _vswprintf_c(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                                wchar_t const* const _Format,
                                                          va_list              _ArgList
        )
    {
        return _vswprintf_c_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
    }

     
    
    __inline int __cdecl _vswprintf_l(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                      wchar_t const* const _Format,
                                                   _locale_t      const _Locale,
                                                          va_list              _ArgList
        )
    {
        return _vswprintf_c_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
    }

     
    
    __inline int __cdecl __vswprintf_l(
                  wchar_t*       const _Buffer,
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    {
        return _vswprintf_l(_Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    }

     
    
    __inline int __cdecl _vswprintf(
           wchar_t*       const _Buffer,
               wchar_t const* const _Format,
                                         va_list              _ArgList
        )
    {
        return _vswprintf_l(_Buffer, (size_t)-1, _Format, 0, _ArgList);
    }

     
    
    __inline int __cdecl vswprintf(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                      wchar_t const* const _Format,
                                                          va_list              _ArgList
        )
    {
        return _vswprintf_c_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
    }

     
    
    __inline int __cdecl _vswprintf_s_l(
           wchar_t*       const _Buffer,
                                                   size_t         const _BufferCount,
                  wchar_t const* const _Format,
                                               _locale_t      const _Locale,
                                                      va_list              _ArgList
        )
    {
        int const _Result = __stdio_common_vswprintf_s(
            (*__local_stdio_printf_options()),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }


         
        __inline int __cdecl vswprintf_s(
               wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                                wchar_t const* const _Format,
                                                          va_list              _ArgList
            )
        {
            return _vswprintf_s_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
        }


    extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                                    int __cdecl vswprintf_s(            wchar_t (&_Buffer)[_Size],     wchar_t const* _Format, va_list _ArgList) throw()                 {                                                                                                                                    return vswprintf_s(_Buffer, _Size, _Format, _ArgList);                                                                               }                                                                                                                            }

     
    
    __inline int __cdecl _vswprintf_p_l(
           wchar_t*       const _Buffer,
                                                   size_t         const _BufferCount,
                  wchar_t const* const _Format,
                                               _locale_t      const _Locale,
                                                      va_list              _ArgList
        )
    {
        int const _Result = __stdio_common_vswprintf_p(
            (*__local_stdio_printf_options()),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }

     
    
    __inline int __cdecl _vswprintf_p(
           wchar_t*       const _Buffer,
                                                   size_t         const _BufferCount,
                            wchar_t const* const _Format,
                                                      va_list              _ArgList
        )
    {
        return _vswprintf_p_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
    }

     
     
    __inline int __cdecl _vscwprintf_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    {
        int const _Result = __stdio_common_vswprintf(
            (*__local_stdio_printf_options()) | (1ULL << 1),
            0, 0, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }

     
     
    __inline int __cdecl _vscwprintf(
            wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    {
        return _vscwprintf_l(_Format, 0, _ArgList);
    }

     
     
    __inline int __cdecl _vscwprintf_p_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    {
        int const _Result = __stdio_common_vswprintf_p(
            (*__local_stdio_printf_options()) | (1ULL << 1),
            0, 0, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }

     
     
    __inline int __cdecl _vscwprintf_p(
            wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    {
        return _vscwprintf_p_l(_Format, 0, _ArgList);
    }

     
    
    __inline int __cdecl __swprintf_l(
                  wchar_t*       const _Buffer,
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = __vswprintf_l(_Buffer, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    
    __inline int __cdecl _swprintf_l(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                      wchar_t const* const _Format,
                                                   _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vswprintf_c_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    
    __inline int __cdecl _swprintf(
           wchar_t*       const _Buffer,
               wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = __vswprintf_l(_Buffer, _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    
    __inline int __cdecl swprintf(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                                wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vswprintf_c_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    __declspec(deprecated("This function or variable may be unsafe. Consider using _FuncName##_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) __inline          int __cdecl __swprintf_l(   wchar_t *_Buffer,     wchar_t const* _Format,                                  _locale_t _Locale, ...);                 __declspec(deprecated("This function or variable may be unsafe. Consider using _SecureVFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) __inline          int __cdecl __vswprintf_l(   wchar_t *_Buffer,     wchar_t const* _Format,                                  _locale_t _Locale, va_list _Args);

    __declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) __inline          int __cdecl _swprintf(   wchar_t *_Buffer,         wchar_t const* _Format, ...);                 __declspec(deprecated("This function or variable may be unsafe. Consider using _SecureVFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) __inline          int __cdecl _vswprintf(   wchar_t *_Buffer,         wchar_t const* _Format, va_list _Args);

     
    
    __inline int __cdecl _swprintf_s_l(
           wchar_t*       const _Buffer,
                                                   size_t         const _BufferCount,
                  wchar_t const* const _Format,
                                               _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vswprintf_s_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


         
        __inline int __cdecl swprintf_s(
               wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                                wchar_t const* const _Format,
            ...)
        {
            int _Result;
            va_list _ArgList;
            ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
            _Result = _vswprintf_s_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }


    extern "C++"                                                                                                                       {                                                                                                                                      template <size_t _Size>                                                                                                            inline                                                                                                                                      int __cdecl swprintf_s(            wchar_t (&_Buffer)[_Size],     wchar_t const* _Format, ...) throw()                              {                                                                                                                                      va_list _ArgList;                                                                                                                  ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));                                                                                                  return vswprintf_s(_Buffer, _Size, _Format, _ArgList);                                                                              }                                                                                                                              }

     
    
    __inline int __cdecl _swprintf_p_l(
           wchar_t*       const _Buffer,
                                                   size_t         const _BufferCount,
                  wchar_t const* const _Format,
                                               _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vswprintf_p_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    
    __inline int __cdecl _swprintf_p(
           wchar_t*       const _Buffer,
                                                   size_t         const _BufferCount,
                            wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vswprintf_p_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    
    __inline int __cdecl _swprintf_c_l(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                      wchar_t const* const _Format,
                                                   _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vswprintf_c_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    
    __inline int __cdecl _swprintf_c(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                                wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vswprintf_c_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
     __declspec(deprecated("This function or variable may be unsafe. Consider using _snwprintf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _snwprintf_l(
            wchar_t*       const _Buffer,
                                                  size_t         const _BufferCount,
                 wchar_t const* const _Format,
                                              _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));

        _Result = _vsnwprintf_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    
    __inline int __cdecl _snwprintf(
            wchar_t*       _Buffer,
                                                  size_t         _BufferCount,
                           wchar_t const* _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));

        _Result = _vsnwprintf_l(_Buffer, _BufferCount, _Format, 0, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    
    __inline int __cdecl _snwprintf_s_l(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                                                       size_t         const _MaxCount,
                      wchar_t const* const _Format,
                                                   _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vsnwprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    
    __inline int __cdecl _snwprintf_s(
           wchar_t*       const _Buffer,
                                                       size_t         const _BufferCount,
                                                       size_t         const _MaxCount,
                                wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vsnwprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    extern "C++"                                                                                                                                        {                                                                                                                                                       template <size_t _Size>                                                                                                                             inline                                                                                                                                                       int __cdecl _snwprintf_s(            wchar_t (&_Buffer)[_Size],                            size_t _BufferCount,     wchar_t const* _Format, ...) throw()                               {                                                                                                                                                       va_list _ArgList;                                                                                                                                   ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));                                                                                                                   return _vsnwprintf_s(_Buffer, _Size, _BufferCount, _Format, _ArgList);                                                                                       }                                                                                                                                               }

     
    __inline int __cdecl _scwprintf_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vscwprintf_l(_Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
     
    __inline int __cdecl _scwprintf(
            wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vscwprintf_l(_Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
     
    __inline int __cdecl _scwprintf_p_l(
            wchar_t const* const _Format,
                                         _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vscwprintf_p_l(_Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
     
    __inline int __cdecl _scwprintf_p(
            wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vscwprintf_p_l(_Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


                  

            extern "C++" __declspec(deprecated("function has been changed to conform with the ISO C standard, adding an extra character count parameter. To use the traditional Microsoft version, set _CRT_NON_CONFORMING_SWPRINTFS.")) __declspec(deprecated("This function or variable may be unsafe. Consider using swprintf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
            inline int swprintf(
                           wchar_t*       const _Buffer,
                    wchar_t const* const _Format,
                ...) throw()
            {
                int _Result;
                va_list _ArgList;
                ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
                _Result = vswprintf(_Buffer, 2147483647, _Format, _ArgList);
                ((void)(_ArgList = (va_list)0));
                return _Result;
            }

            extern "C++" __declspec(deprecated("function has been changed to conform with the ISO C standard, adding an extra character count parameter. To use the traditional Microsoft version, set _CRT_NON_CONFORMING_SWPRINTFS.")) __declspec(deprecated("This function or variable may be unsafe. Consider using vswprintf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
            inline int __cdecl vswprintf(
                           wchar_t*       const _Buffer,
                    wchar_t const* const _Format,
                                              va_list              _ArgList
                ) throw()
            {
                return vswprintf(_Buffer, 2147483647, _Format, _ArgList);
            }

            extern "C++" __declspec(deprecated("function has been changed to conform with the ISO C standard, adding an extra character count parameter. To use the traditional Microsoft version, set _CRT_NON_CONFORMING_SWPRINTFS.")) __declspec(deprecated("This function or variable may be unsafe. Consider using _swprintf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
            inline int _swprintf_l(
                                     wchar_t*       const _Buffer,
                    wchar_t const* const _Format,
                                                 _locale_t      const _Locale,
                ...) throw()
            {
                int _Result;
                va_list _ArgList;
                ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
                _Result = _vswprintf_l(_Buffer, (size_t)-1, _Format, _Locale, _ArgList);
                ((void)(_ArgList = (va_list)0));
                return _Result;
            }

            extern "C++" __declspec(deprecated("function has been changed to conform with the ISO C standard, adding an extra character count parameter. To use the traditional Microsoft version, set _CRT_NON_CONFORMING_SWPRINTFS.")) __declspec(deprecated("This function or variable may be unsafe. Consider using _vswprintf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
            inline int __cdecl _vswprintf_l(
                                     wchar_t*       const _Buffer,
                    wchar_t const* const _Format,
                                                 _locale_t      const _Locale,
                                                        va_list              _ArgList
                ) throw()
            {
                return _vswprintf_l(_Buffer, (size_t)-1, _Format, _Locale, _ArgList);
            }





                              
     int __cdecl __stdio_common_vswscanf(
                                            unsigned __int64 _Options,
                  wchar_t const*   _Buffer,
                                            size_t           _BufferCount,
            wchar_t const*   _Format,
                                        _locale_t        _Locale,
                                               va_list          _ArgList
        );

     
    
    __inline int __cdecl _vswscanf_l(
                                 wchar_t const* const _Buffer,
            wchar_t const* const _Format,
                               _locale_t      const _Locale,
                                      va_list              _ArgList
        )
    {
        return __stdio_common_vswscanf(
            (*__local_stdio_scanf_options ()),
            _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    }

     
    
    __inline int __cdecl vswscanf(
                                 wchar_t const* _Buffer,
            wchar_t const* _Format,
                                      va_list        _ArgList
        )
    {
        return _vswscanf_l(_Buffer, _Format, 0, _ArgList);
    }

     
    
    __inline int __cdecl _vswscanf_s_l(
                                 wchar_t const* const _Buffer,
            wchar_t const* const _Format,
                               _locale_t      const _Locale,
                                      va_list              _ArgList
        )
    {
        return __stdio_common_vswscanf(
            (*__local_stdio_scanf_options ()) | (1ULL << 0),
            _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    }


         
        
        __inline int __cdecl vswscanf_s(
                                     wchar_t const* const _Buffer,
                wchar_t const* const _Format,
                                          va_list              _ArgList
            )
        {
            return _vswscanf_s_l(_Buffer, _Format, 0, _ArgList);
        }


    extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                                    int __cdecl vswscanf_s(                         wchar_t (&_Buffer)[_Size],     wchar_t const* _Format, va_list _ArgList) throw()                 {                                                                                                                                    return vswscanf_s(_Buffer, _Size, _Format, _ArgList);                                                                               }                                                                                                                            }

     
     __declspec(deprecated("This function or variable may be unsafe. Consider using _vsnwscanf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _vsnwscanf_l(
                  wchar_t const* const _Buffer,
                                            size_t         const _BufferCount,
            wchar_t const* const _Format,
                                        _locale_t      const _Locale,
                                               va_list              _ArgList
        )
    {
        return __stdio_common_vswscanf(
            (*__local_stdio_scanf_options ()),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    }

     
    
    __inline int __cdecl _vsnwscanf_s_l(
                    wchar_t const* const _Buffer,
                                              size_t         const _BufferCount,
            wchar_t const* const _Format,
                                          _locale_t      const _Locale,
                                                 va_list              _ArgList
        )
    {
        return __stdio_common_vswscanf(
            (*__local_stdio_scanf_options ()) | (1ULL << 0),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    }

     
     __declspec(deprecated("This function or variable may be unsafe. Consider using _swscanf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _swscanf_l(
                                          wchar_t const* const _Buffer,
            wchar_t const* const _Format,
                                        _locale_t            _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vswscanf_l(_Buffer, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
      __declspec(deprecated("This function or variable may be unsafe. Consider using swscanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl swscanf(
                                wchar_t const* const _Buffer,
            wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vswscanf_l(_Buffer, _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    
    __inline int __cdecl _swscanf_s_l(
                                            wchar_t const* const _Buffer,
            wchar_t const* const _Format,
                                          _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vswscanf_s_l(_Buffer, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


         
        
        __inline int __cdecl swscanf_s(
                                      wchar_t const* const _Buffer,
                wchar_t const* const _Format,
            ...)
        {
            int _Result;
            va_list _ArgList;
            ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
            _Result = _vswscanf_s_l(_Buffer, _Format, 0, _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }


     
     __declspec(deprecated("This function or variable may be unsafe. Consider using _snwscanf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _snwscanf_l(
                  wchar_t const* const _Buffer,
                                            size_t         const _BufferCount,
            wchar_t const* const _Format,
                                        _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));

        _Result = _vsnwscanf_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
     __declspec(deprecated("This function or variable may be unsafe. Consider using _snwscanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _snwscanf(
            wchar_t const* const _Buffer,
                                      size_t         const _BufferCount,
                wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));

        _Result = _vsnwscanf_l(_Buffer, _BufferCount, _Format, 0, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    
    __inline int __cdecl _snwscanf_s_l(
                    wchar_t const* const _Buffer,
                                              size_t         const _BufferCount,
            wchar_t const* const _Format,
                                          _locale_t      const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vsnwscanf_s_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    
    __inline int __cdecl _snwscanf_s(
             wchar_t const* const _Buffer,
                                       size_t         const _BufferCount,
               wchar_t const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vsnwscanf_s_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


}                             

        
       


         extern "C" {



   






     
    
     errno_t __cdecl _itow_s(
                                  int      _Value,
          wchar_t* _Buffer,
                                  size_t   _BufferCount,
                                  int      _Radix
        );

    extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl _itow_s(  int _Value, wchar_t (&_Buffer)[_Size],   int _Radix) throw()                 {                                                                                                                                    return _itow_s(_Value, _Buffer, _Size, _Radix);                                                                               }                                                                                                                            }

    __declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _itow(                     int _Value,     wchar_t *_Buffer,                      int _Radix);

     
    
     errno_t __cdecl _ltow_s(
                                  long     _Value,
          wchar_t* _Buffer,
                                  size_t   _BufferCount,
                                  int      _Radix
        );

    extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl _ltow_s(  long _Value, wchar_t (&_Buffer)[_Size],   int _Radix) throw()                 {                                                                                                                                    return _ltow_s(_Value, _Buffer, _Size, _Radix);                                                                               }                                                                                                                            }

    __declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _ltow(                     long _Value,     wchar_t *_Buffer,                      int _Radix);

    
     errno_t __cdecl _ultow_s(
                                  unsigned long _Value,
          wchar_t*      _Buffer,
                                  size_t        _BufferCount,
                                  int           _Radix
        );

    extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl _ultow_s(  unsigned long _Value, wchar_t (&_Buffer)[_Size],   int _Radix) throw()                 {                                                                                                                                    return _ultow_s(_Value, _Buffer, _Size, _Radix);                                                                               }                                                                                                                            }

    __declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _ultow(                     unsigned long _Value,     wchar_t *_Buffer,                      int _Radix);

     
     double __cdecl wcstod(
                            wchar_t const* _String,
            wchar_t**      _EndPtr
        );

     
     double __cdecl _wcstod_l(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                          _locale_t      _Locale
        );

     
     long __cdecl wcstol(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix
        );

     
     long __cdecl _wcstol_l(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix,
                          _locale_t      _Locale
        );

     
     long long __cdecl wcstoll(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix
        );

     
     long long __cdecl _wcstoll_l(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix,
                          _locale_t      _Locale
        );

     
     unsigned long __cdecl wcstoul(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix
        );

     
     unsigned long __cdecl _wcstoul_l(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix,
                          _locale_t      _Locale
        );

     
     unsigned long long __cdecl wcstoull(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix
        );

     
     unsigned long long __cdecl _wcstoull_l(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix,
                          _locale_t      _Locale
        );

     
     long double __cdecl wcstold(
                            wchar_t const* _String,
            wchar_t**      _EndPtr
        );

     
     long double __cdecl _wcstold_l(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                          _locale_t      _Locale
        );

     
     float __cdecl wcstof(
                            wchar_t const* _String,
            wchar_t**      _EndPtr
        );

     
     float __cdecl _wcstof_l(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                          _locale_t      _Locale
        );

     
     double __cdecl _wtof(
          wchar_t const* _String
        );

     
     double __cdecl _wtof_l(
            wchar_t const* _String,
          _locale_t      _Locale
        );

     
     int __cdecl _wtoi(
          wchar_t const* _String
        );

     
     int __cdecl _wtoi_l(
            wchar_t const* _String,
          _locale_t      _Locale
        );

     
     long __cdecl _wtol(
          wchar_t const* _String
        );

     
     long __cdecl _wtol_l(
            wchar_t const* _String,
          _locale_t      _Locale
        );

     
     long long __cdecl _wtoll(
          wchar_t const* _String
        );

     
     long long __cdecl _wtoll_l(
            wchar_t const* _String,
          _locale_t      _Locale
        );

    
     errno_t __cdecl _i64tow_s(
                                  __int64  _Value,
          wchar_t* _Buffer,
                                  size_t   _BufferCount,
                                  int      _Radix
        );

    __declspec(deprecated("This function or variable may be unsafe. Consider using _i64tow_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
     wchar_t* __cdecl _i64tow(
                            __int64  _Value,
            wchar_t* _Buffer,
                            int      _Radix
        );

    
     errno_t __cdecl _ui64tow_s(
                                  unsigned __int64 _Value,
          wchar_t*         _Buffer,
                                  size_t           _BufferCount,
                                  int              _Radix
        );

    __declspec(deprecated("This function or variable may be unsafe. Consider using _ui64tow_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
     wchar_t* __cdecl _ui64tow(
                            unsigned __int64 _Value,
            wchar_t*         _Buffer,
                            int              _Radix
        );

     
     __int64 __cdecl _wtoi64(
          wchar_t const* _String
        );

     
     __int64 __cdecl _wtoi64_l(
            wchar_t const* _String,
          _locale_t      _Locale
        );

     
     __int64 __cdecl _wcstoi64(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix
        );

     
     __int64 __cdecl _wcstoi64_l(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix,
                          _locale_t      _Locale
        );

     
     unsigned __int64 __cdecl _wcstoui64(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix
        );

     
     unsigned __int64 __cdecl _wcstoui64_l(
                            wchar_t const* _String,
            wchar_t**      _EndPtr,
                              int            _Radix,
                          _locale_t      _Locale
        );


     
     
     __declspec(allocator) wchar_t* __cdecl _wfullpath(
          wchar_t*       _Buffer,
                                    wchar_t const* _Path,
                                      size_t         _BufferCount
        );


    
     errno_t __cdecl _wmakepath_s(
          wchar_t*       _Buffer,
                                  size_t         _BufferCount,
                            wchar_t const* _Drive,
                            wchar_t const* _Dir,
                            wchar_t const* _Filename,
                            wchar_t const* _Ext
        );

    extern "C++"                                                                                                                                                      {                                                                                                                                                                     template <size_t _Size>                                                                                                                                           inline                                                                                                                                                            errno_t __cdecl _wmakepath_s(wchar_t (&_Buffer)[_Size],   wchar_t const* _Drive,   wchar_t const* _Dir,   wchar_t const* _Filename,   wchar_t const* _Ext) throw()                  {                                                                                                                                                                     return _wmakepath_s(_Buffer, _Size, _Drive, _Dir, _Filename, _Ext);                                                                                                }                                                                                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  void __cdecl _wmakepath(    wchar_t *_Buffer,                wchar_t const* _Drive,                wchar_t const* _Dir,                wchar_t const* _Filename,                wchar_t const* _Ext);

     void __cdecl _wperror(
          wchar_t const* _ErrorMessage
        );

    __declspec(deprecated("This function or variable may be unsafe. Consider using _wsplitpath_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
     void __cdecl _wsplitpath(
                            wchar_t const* _FullPath,
            wchar_t*       _Drive,
            wchar_t*       _Dir,
            wchar_t*       _Filename,
            wchar_t*       _Ext
        );

     errno_t __cdecl _wsplitpath_s(
                                      wchar_t const* _FullPath,
             wchar_t*       _Drive,
                                        size_t         _DriveCount,
               wchar_t*       _Dir,
                                        size_t         _DirCount,
          wchar_t*       _Filename,
                                        size_t         _FilenameCount,
               wchar_t*       _Ext,
                                        size_t         _ExtCount
        );

    extern "C++"                                                                                                      {                                                                                                                     template <size_t _DriveSize, size_t _DirSize, size_t _NameSize, size_t _ExtSize>                                  inline                                                                                                            errno_t __cdecl _wsplitpath_s(                                                                                        wchar_t const* _Path,                                                                                        wchar_t (&_Drive)[_DriveSize],                                                                            wchar_t (&_Dir)[_DirSize],                                                                                wchar_t (&_Name)[_NameSize],                                                                              wchar_t (&_Ext)[_ExtSize]                                                                               ) throw()                                                                                     {                                                                                                                     return _wsplitpath_s(_Path, _Drive, _DriveSize, _Dir, _DirSize, _Name, _NameSize, _Ext, _ExtSize);                 }                                                                                                             }


        
         errno_t __cdecl _wdupenv_s(
                wchar_t**      _Buffer,
                                                                                size_t*        _BufferCount,
                                                                                   wchar_t const* _VarName
            );


          __declspec(deprecated("This function or variable may be unsafe. Consider using _wdupenv_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
         wchar_t* __cdecl _wgetenv(
              wchar_t const* _VarName
            );

         
        
         errno_t __cdecl _wgetenv_s(
                                         size_t*        _RequiredCount,
              wchar_t*       _Buffer,
                                          size_t         _BufferCount,
                                        wchar_t const* _VarName
            );

        extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                                        errno_t __cdecl _wgetenv_s(   size_t* _RequiredCount, wchar_t (&_Buffer)[_Size],   wchar_t const* _VarName) throw()                 {                                                                                                                                    return _wgetenv_s(_RequiredCount, _Buffer, _Size, _VarName);                                                                               }                                                                                                                            }

         
         int __cdecl _wputenv(
              wchar_t const* _EnvString
            );

        
         errno_t __cdecl _wputenv_s(
              wchar_t const* _Name,
              wchar_t const* _Value
            );

         errno_t __cdecl _wsearchenv_s(
                                    wchar_t const* _Filename,
                                    wchar_t const* _VarName,
              wchar_t*       _Buffer,
                                      size_t         _BufferCount
            );

        extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl _wsearchenv_s(  wchar_t const* _Filename,   wchar_t const* _VarName, wchar_t (&_ResultPath)[_Size]) throw()                 {                                                                                                                                    return _wsearchenv_s(_Filename, _VarName, _ResultPath, _Size);                                                                               }                                                                                                                            }

        __declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  void __cdecl _wsearchenv(                   wchar_t const* _Filename,                    wchar_t const* _VarName,     wchar_t *_ResultPath);

         int __cdecl _wsystem(
              wchar_t const* _Command
            );




}                             

        
              



         extern "C" {



     
    
     errno_t __cdecl wcscat_s(
          wchar_t* _Destination,
          rsize_t _SizeInWords,
          wchar_t const* _Source
        );

    
     errno_t __cdecl wcscpy_s(
          wchar_t* _Destination,
          rsize_t _SizeInWords,
          wchar_t const* _Source
        );

    
     errno_t __cdecl wcsncat_s(
          wchar_t*       _Destination,
                                     rsize_t        _SizeInWords,
               wchar_t const* _Source,
                                     rsize_t        _MaxCount
        );

    
     errno_t __cdecl wcsncpy_s(
          wchar_t*       _Destination,
                                  rsize_t        _SizeInWords,
            wchar_t const* _Source,
                                  rsize_t        _MaxCount
        );

     
     wchar_t* __cdecl wcstok_s(
                          wchar_t*       _String,
                                 wchar_t const* _Delimiter,
            wchar_t**      _Context
        );




     
 
 __declspec(allocator) wchar_t* __cdecl _wcsdup(
      wchar_t const* _String
    );




extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl wcscat_s(wchar_t (&_Destination)[_Size],   wchar_t const* _Source) throw()                 {                                                                                                                    return wcscat_s(_Destination, _Size, _Source);                                                                       }                                                                                                            }

    __declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl wcscat(  wchar_t *_Destination,                                                                             wchar_t const* _Source);

 
 int __cdecl wcscmp(
      wchar_t const* _String1,
      wchar_t const* _String2
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl wcscpy_s(wchar_t (&_Destination)[_Size],   wchar_t const* _Source) throw()                 {                                                                                                                    return wcscpy_s(_Destination, _Size, _Source);                                                                       }                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl wcscpy(  wchar_t *_Destination,                                          wchar_t const* _Source);

 
 size_t __cdecl wcscspn(
      wchar_t const* _String,
      wchar_t const* _Control
    );

 
 size_t __cdecl wcslen(
      wchar_t const* _String
    );

 


 size_t __cdecl wcsnlen(
      wchar_t const* _Source,
                            size_t         _MaxCount
    );


     
    
    
    static __inline size_t __cdecl wcsnlen_s(
          wchar_t const* _Source,
                                size_t         _MaxCount
        )
    {
        return (_Source == 0) ? 0 : wcsnlen(_Source, _MaxCount);
    }


extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl wcsncat_s(              wchar_t (&_Destination)[_Size],   wchar_t const* _Source,                      size_t _Count) throw()                 {                                                                                                                                    return wcsncat_s(_Destination, _Size, _Source, _Count);                                                                               }                                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl wcsncat(  wchar_t *_Destination,      wchar_t const* _Source,                         size_t _Count);

 
 int __cdecl wcsncmp(
      wchar_t const* _String1,
      wchar_t const* _String2,
                            size_t         _MaxCount
    );

extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl wcsncpy_s(wchar_t (&_Destination)[_Size],   wchar_t const* _Source,                      size_t _Count) throw()                 {                                                                                                                                    return wcsncpy_s(_Destination, _Size, _Source, _Count);                                                                               }                                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl wcsncpy(    wchar_t *_Destination,               wchar_t const* _Source,                                  size_t _Count);

 
 wchar_t const* __cdecl wcspbrk(
      wchar_t const* _String,
      wchar_t const* _Control
    );

 
 size_t __cdecl wcsspn(
      wchar_t const* _String,
      wchar_t const* _Control
    );

  __declspec(deprecated("This function or variable may be unsafe. Consider using wcstok_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 wchar_t* __cdecl wcstok(
                          wchar_t*       _String,
                                 wchar_t const* _Delimiter,
        wchar_t**      _Context
    );



      __declspec(deprecated("This function or variable may be unsafe. Consider using wcstok_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    static __inline wchar_t* __cdecl _wcstok(
          wchar_t*       const _String,
                 wchar_t const* const _Delimiter
        )
    {
        return wcstok(_String, _Delimiter, 0);
    }


        extern "C++"   __declspec(deprecated("wcstok has been changed to conform with the ISO C standard, adding an extra context parameter. To use the legacy Microsoft wcstok, define _CRT_NON_CONFORMING_WCSTOK."))
        inline wchar_t* __cdecl wcstok(
              wchar_t*       _String,
                     wchar_t const* _Delimiter
            ) throw()
        {
            return wcstok(_String, _Delimiter, 0);
        }




 
  __declspec(deprecated("This function or variable may be unsafe. Consider using _wcserror_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 wchar_t* __cdecl _wcserror(
      int _ErrorNumber
    );


 errno_t __cdecl _wcserror_s(
      wchar_t* _Buffer,
                                  size_t   _SizeInWords,
                                  int      _ErrorNumber
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl _wcserror_s(wchar_t (&_Buffer)[_Size],   int _Error) throw()                 {                                                                                                                    return _wcserror_s(_Buffer, _Size, _Error);                                                                       }                                                                                                            }

 
 
  __declspec(deprecated("This function or variable may be unsafe. Consider using __wcserror_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 wchar_t* __cdecl __wcserror(
      wchar_t const* _String
    );

  errno_t __cdecl __wcserror_s(
      wchar_t*       _Buffer,
                                  size_t         _SizeInWords,
                                wchar_t const* _ErrorMessage
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl __wcserror_s(wchar_t (&_Buffer)[_Size],   wchar_t const* _ErrorMessage) throw()                 {                                                                                                                    return __wcserror_s(_Buffer, _Size, _ErrorMessage);                                                                       }                                                                                                            }

   int __cdecl _wcsicmp(
      wchar_t const* _String1,
      wchar_t const* _String2
    );

   int __cdecl _wcsicmp_l(
        wchar_t const* _String1,
        wchar_t const* _String2,
      _locale_t      _Locale
    );

   int __cdecl _wcsnicmp(
      wchar_t const* _String1,
      wchar_t const* _String2,
                            size_t         _MaxCount
    );

   int __cdecl _wcsnicmp_l(
      wchar_t const* _String1,
      wchar_t const* _String2,
                            size_t         _MaxCount,
                        _locale_t      _Locale
    );

  errno_t __cdecl _wcsnset_s(
      wchar_t* _Destination,
                                 size_t   _SizeInWords,
                                 wchar_t  _Value,
                                 size_t   _MaxCount
    );

extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl _wcsnset_s(  wchar_t (&_Destination)[_Size],          wchar_t _Value,           size_t _MaxCount) throw()                 {                                                                                                                                    return _wcsnset_s(_Destination, _Size, _Value, _MaxCount);                                                                               }                                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _wcsnset(  wchar_t *_String,                            wchar_t _Value,                            size_t _MaxCount);

 wchar_t* __cdecl _wcsrev(
      wchar_t* _String
    );

  errno_t __cdecl _wcsset_s(
      wchar_t* _Destination,
                                 size_t   _SizeInWords,
                                 wchar_t  _Value
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl _wcsset_s(  wchar_t (&_String)[_Size],          wchar_t _Value) throw()                 {                                                                                                                    return _wcsset_s(_String, _Size, _Value);                                                                       }                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _wcsset(  wchar_t *_String,                       wchar_t _Value);

  errno_t __cdecl _wcslwr_s(
      wchar_t* _String,
                                 size_t   _SizeInWords
    );

extern "C++"                                                                                      {                                                                                                     template <size_t _Size>                                                                           inline                                                                                            errno_t __cdecl _wcslwr_s(  wchar_t (&_String)[_Size]) throw()                  {                                                                                                     return _wcslwr_s(_String, _Size);                                                                }                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _wcslwr(  wchar_t *_String);


 errno_t __cdecl _wcslwr_s_l(
      wchar_t*  _String,
                                 size_t    _SizeInWords,
                             _locale_t _Locale
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl _wcslwr_s_l(  wchar_t (&_String)[_Size],      _locale_t _Locale) throw()                 {                                                                                                                    return _wcslwr_s_l(_String, _Size, _Locale);                                                                       }                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _wcslwr_l(  wchar_t *_String,                   _locale_t _Locale);


 errno_t __cdecl _wcsupr_s(
      wchar_t* _String,
                          size_t   _Size
    );

extern "C++"                                                                                      {                                                                                                     template <size_t _Size>                                                                           inline                                                                                            errno_t __cdecl _wcsupr_s(  wchar_t (&_String)[_Size]) throw()                  {                                                                                                     return _wcsupr_s(_String, _Size);                                                                }                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _wcsupr(  wchar_t *_String);


 errno_t __cdecl _wcsupr_s_l(
      wchar_t*  _String,
                          size_t    _Size,
                      _locale_t _Locale
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl _wcsupr_s_l(  wchar_t (&_String)[_Size],      _locale_t _Locale) throw()                 {                                                                                                                    return _wcsupr_s_l(_String, _Size, _Locale);                                                                       }                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _wcsupr_l(  wchar_t *_String,                   _locale_t _Locale);

 

 size_t __cdecl wcsxfrm(
        wchar_t*       _Destination,
                                         wchar_t const* _Source,
                size_t         _MaxCount
    );

 

 size_t __cdecl _wcsxfrm_l(
        wchar_t*       _Destination,
                                         wchar_t const* _Source,
                size_t         _MaxCount,
                                       _locale_t      _Locale
    );

 
 int __cdecl wcscoll(
      wchar_t const* _String1,
      wchar_t const* _String2
    );

 
 int __cdecl _wcscoll_l(
        wchar_t const* _String1,
        wchar_t const* _String2,
      _locale_t      _Locale
    );

 
 int __cdecl _wcsicoll(
      wchar_t const* _String1,
      wchar_t const* _String2
    );

 
 int __cdecl _wcsicoll_l(
        wchar_t const* _String1,
        wchar_t const* _String2,
      _locale_t      _Locale
    );

 
 int __cdecl _wcsncoll(
      wchar_t const* _String1,
      wchar_t const* _String2,
                            size_t         _MaxCount
    );

 
 int __cdecl _wcsncoll_l(
      wchar_t const* _String1,
      wchar_t const* _String2,
                            size_t         _MaxCount,
                        _locale_t      _Locale
    );

 
 int __cdecl _wcsnicoll(
      wchar_t const* _String1,
      wchar_t const* _String2,
                            size_t         _MaxCount
    );

 
 int __cdecl _wcsnicoll_l(
      wchar_t const* _String1,
      wchar_t const* _String2,
                            size_t         _MaxCount,
                        _locale_t      _Locale
    );



     extern "C++" {

     
    
    inline wchar_t* __cdecl wcschr(  wchar_t* _String, wchar_t _C)
    {
        return const_cast<wchar_t*>(wcschr(static_cast<wchar_t const*>(_String), _C));
    }

     
    inline wchar_t* __cdecl wcspbrk(  wchar_t* _String,   wchar_t const* _Control)
    {
        return const_cast<wchar_t*>(wcspbrk(static_cast<wchar_t const*>(_String), _Control));
    }

     
    inline wchar_t* __cdecl wcsrchr(  wchar_t* _String,   wchar_t _C)
    {
        return const_cast<wchar_t*>(wcsrchr(static_cast<wchar_t const*>(_String), _C));
    }

       
    
    inline wchar_t* __cdecl wcsstr(  wchar_t* _String,   wchar_t const*_SubStr)
    {
        return const_cast<wchar_t*>(wcsstr(static_cast<wchar_t const*>(_String), _SubStr));
    }

}



     
      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _wcsdup. See online help for details."))
     wchar_t* __cdecl wcsdup(
          wchar_t const* _String
        );


     
      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _wcsicmp. See online help for details."))
     int __cdecl wcsicmp(
          wchar_t const* _String1,
          wchar_t const* _String2
        );

      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _wcsnicmp. See online help for details."))
     int __cdecl wcsnicmp(
          wchar_t const* _String1,
          wchar_t const* _String2,
                                size_t         _MaxCount
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _wcsnset. See online help for details."))
     
     wchar_t* __cdecl wcsnset(
          wchar_t* _String,
                                  wchar_t  _Value,
                                  size_t   _MaxCount
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _wcsrev. See online help for details."))
     
     wchar_t* __cdecl wcsrev(
          wchar_t* _String
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _wcsset. See online help for details."))
     
     wchar_t* __cdecl wcsset(
          wchar_t* _String,
               wchar_t  _Value
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _wcslwr. See online help for details."))
     
     wchar_t* __cdecl wcslwr(
          wchar_t* _String
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _wcsupr. See online help for details."))
     
     wchar_t* __cdecl wcsupr(
          wchar_t* _String
        );

      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _wcsicoll. See online help for details."))
     int __cdecl wcsicoll(
          wchar_t const* _String1,
          wchar_t const* _String2
        );




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

       
              
       



    typedef unsigned short _ino_t;  
        typedef _ino_t ino_t;




    typedef unsigned int _dev_t;  
        typedef _dev_t dev_t;




    typedef long _off_t;  
        typedef _off_t off_t;





         extern "C" {

     struct _stat32
{
    _dev_t         st_dev;
    _ino_t         st_ino;
    unsigned short st_mode;
    short          st_nlink;
    short          st_uid;
    short          st_gid;
    _dev_t         st_rdev;
    _off_t         st_size;
    __time32_t     st_atime;
    __time32_t     st_mtime;
    __time32_t     st_ctime;
};

struct _stat32i64
{
    _dev_t         st_dev;
    _ino_t         st_ino;
    unsigned short st_mode;
    short          st_nlink;
    short          st_uid;
    short          st_gid;
    _dev_t         st_rdev;
    __int64        st_size;
    __time32_t     st_atime;
    __time32_t     st_mtime;
    __time32_t     st_ctime;
};

struct _stat64i32
{
    _dev_t         st_dev;
    _ino_t         st_ino;
    unsigned short st_mode;
    short          st_nlink;
    short          st_uid;
    short          st_gid;
    _dev_t         st_rdev;
    _off_t         st_size;
    __time64_t     st_atime;
    __time64_t     st_mtime;
    __time64_t     st_ctime;
};

struct _stat64
{
    _dev_t         st_dev;
    _ino_t         st_ino;
    unsigned short st_mode;
    short          st_nlink;
    short          st_uid;
    short          st_gid;
    _dev_t         st_rdev;
    __int64        st_size;
    __time64_t     st_atime;
    __time64_t     st_mtime;
    __time64_t     st_ctime;
};


    struct stat
    {
        _dev_t         st_dev;
        _ino_t         st_ino;
        unsigned short st_mode;
        short          st_nlink;
        short          st_uid;
        short          st_gid;
        _dev_t         st_rdev;
        _off_t         st_size;
        time_t         st_atime;
        time_t         st_mtime;
        time_t         st_ctime;
    };



     



     


 int __cdecl _fstat32(
       int             _FileHandle,
      struct _stat32* _Stat
    );

 int __cdecl _fstat32i64(
       int                _FileHandle,
      struct _stat32i64* _Stat
    );

 int __cdecl _fstat64i32(
       int                _FileHandle,
      struct _stat64i32* _Stat
    );

 int __cdecl _fstat64(
       int             _FileHandle,
      struct _stat64* _Stat
    );

 int __cdecl _stat32(
      char const*     _FileName,
       struct _stat32* _Stat
    );

 int __cdecl _stat32i64(
      char const*        _FileName,
       struct _stat32i64* _Stat
    );

 int __cdecl _stat64i32(
      char const*        _FileName,
       struct _stat64i32* _Stat
    );

 int __cdecl _stat64(
      char const*     _FileName,
       struct _stat64* _Stat
    );

 int __cdecl _wstat32(
      wchar_t const*  _FileName,
       struct _stat32* _Stat
    );

 int __cdecl _wstat32i64(
      wchar_t const*     _FileName,
       struct _stat32i64* _Stat
    );

 int __cdecl _wstat64i32(
      wchar_t const*     _FileName,
       struct _stat64i32* _Stat
    );

 int __cdecl _wstat64(
      wchar_t const*  _FileName,
       struct _stat64* _Stat
    );




        static __inline int __cdecl fstat(int const _FileHandle, struct stat* const _Stat)
        {
            static_assert((sizeof(struct stat) == sizeof(struct _stat64i32)), "sizeof(struct  stat)  ==  sizeof(struct  _stat64i32)");
            return _fstat64i32(_FileHandle, (struct _stat64i32*)_Stat);
        }
        static __inline int __cdecl stat(char const* const _FileName, struct stat* const _Stat)
        {
            static_assert((sizeof(struct stat) == sizeof(struct _stat64i32)), "sizeof(struct  stat)  ==  sizeof(struct  _stat64i32)");
            return _stat64i32(_FileName, (struct _stat64i32*)_Stat);
        }


}                             

              


         extern "C" {






typedef wchar_t _Wint_t;




        
     wchar_t* __cdecl _wsetlocale(
                int            _Category,
          wchar_t const* _Locale
        );

    
     _locale_t __cdecl _wcreate_locale(
            int            _Category,
          wchar_t const* _Locale
        );



     wint_t __cdecl btowc(
          int _Ch
        );

     size_t __cdecl mbrlen(
            char const* _Ch,
                                                    size_t      _SizeInBytes,
                                                 mbstate_t*  _State
        );

     size_t __cdecl mbrtowc(
                                  wchar_t*    _DstCh,
            char const* _SrcCh,
                                                    size_t      _SizeInBytes,
                                                 mbstate_t*  _State
        );

     
     errno_t __cdecl mbsrtowcs_s(
                                  size_t*      _Retval,
                  wchar_t*     _Dst,
                                       size_t       _Size,
                          char const** _PSrc,
                                       size_t       _N,
                                    mbstate_t*   _State
        );

    extern "C++"                                                                                                                                                      {                                                                                                                                                                     template <size_t _Size>                                                                                                                                           inline                                                                                                                                                                     errno_t __cdecl mbsrtowcs_s(                          size_t* _Retval,                            wchar_t (&_Dest)[_Size],     char const** _PSource,                                size_t _Count,                             mbstate_t* _State) throw()                  {                                                                                                                                                                     return mbsrtowcs_s(_Retval, _Dest, _Size, _PSource, _Count, _State);                                                                                                }                                                                                                                                                             }

    __declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))    size_t __cdecl mbsrtowcs(  wchar_t *_Dest,                   char const** _PSrc,                                size_t _Count,                             mbstate_t* _State);

     
     errno_t __cdecl wcrtomb_s(
                                 size_t*    _Retval,
          char*      _Dst,
                                      size_t     _SizeInBytes,
                                      wchar_t    _Ch,
                               mbstate_t* _State
        );

    extern "C++"                                                                                                                                     {                                                                                                                                                    template <size_t _Size>                                                                                                                          inline                                                                                                                                                    errno_t __cdecl wcrtomb_s(                  size_t* _Retval,   char (&_Dest)[_Size],                        wchar_t _Source,                 mbstate_t* _State) throw()                 {                                                                                                                                                    return wcrtomb_s(_Retval, _Dest, _Size, _Source, _State);                                                                                       }                                                                                                                                            }

    __declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  size_t __cdecl wcrtomb(    char *_Dest,                        wchar_t _Source,                mbstate_t* _State);

     
     errno_t __cdecl wcsrtombs_s(
                                                  size_t*         _Retval,
          char*           _Dst,
                                                       size_t          _SizeInBytes,
                                    wchar_t const** _Src,
                                                       size_t          _Size,
                                                mbstate_t*      _State
        );

    extern "C++"                                                                                                                                                      {                                                                                                                                                                     template <size_t _Size>                                                                                                                                           inline                                                                                                                                                                     errno_t __cdecl wcsrtombs_s(                  size_t* _Retval,   char (&_Dest)[_Size],     wchar_t const** _PSrc,                        size_t _Count,                 mbstate_t* _State) throw()                  {                                                                                                                                                                     return wcsrtombs_s(_Retval, _Dest, _Size, _PSrc, _Count, _State);                                                                                                }                                                                                                                                                             }

    __declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  size_t __cdecl wcsrtombs(    char *_Dest,     wchar_t const** _PSource,                        size_t _Count,                 mbstate_t* _State);

     int __cdecl wctob(
          wint_t _WCh
        );


         
        errno_t __cdecl wmemcpy_s(
              wchar_t*       _S1,
                                      rsize_t        _N1,
                        wchar_t const* _S2,
                                      rsize_t        _N
            );

         
        errno_t __cdecl wmemmove_s(
              wchar_t*       _S1,
                                      rsize_t        _N1,
                        wchar_t const* _S2,
                                      rsize_t        _N
            );


    __inline int __cdecl fwide(
          FILE* _F,
              int   _M
        )
    {
        (void)_F;
        return (_M);
    }

    __inline int __cdecl mbsinit(
          mbstate_t const* _P
        )
    {
        return _P == 0 || _P->_Wchar == 0;
    }

    __inline wchar_t const* __cdecl wmemchr(
          wchar_t const* _S,
                    wchar_t        _C,
                    size_t         _N
        )
    {
        for (; 0 < _N; ++_S, --_N)
            if (*_S == _C)
                return (wchar_t const*)_S;

        return 0;
    }

    __inline int __cdecl wmemcmp(
          wchar_t const* _S1,
          wchar_t const* _S2,
                    size_t         _N
        )
    {
        for (; 0 < _N; ++_S1, ++_S2, --_N)
            if (*_S1 != *_S2)
                return *_S1 < *_S2 ? -1 : 1;

        return 0;
    }

     
    
    __inline 
    wchar_t* __cdecl wmemcpy(
          wchar_t*       _S1,
                wchar_t const* _S2,
                          size_t         _N
        )
    {
        return (wchar_t*)memcpy(_S1, _S2, _N*sizeof(wchar_t));
    }

    __inline 
    wchar_t* __cdecl wmemmove(
          wchar_t*       _S1,
                wchar_t const* _S2,
                              size_t         _N
        )
    {
        return (wchar_t*)memmove(_S1, _S2, _N*sizeof(wchar_t));
    }

     
    
    __inline wchar_t* __cdecl wmemset(
          wchar_t* _S,
                          wchar_t  _C,
                          size_t   _N
        )
    {
        wchar_t *_Su = _S;
        for (; 0 < _N; ++_Su, --_N)
        {
            *_Su = _C;
        }
        return _S;
    }


        extern "C++" inline wchar_t* __cdecl wmemchr(
              wchar_t* _S,
                        wchar_t  _C,
                        size_t   _N
            )
        {
            wchar_t const* const _SC = _S;
            return const_cast<wchar_t*>(wmemchr(_SC, _C, _N));
        }




}                             


