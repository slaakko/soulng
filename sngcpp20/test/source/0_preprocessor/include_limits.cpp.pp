 
  
 
  
   
                                           
                                                 
           
     
                                                                                               
  
    
                                                                                              
                     
  

    
 

 





  

 


 

      
   
    
  
 
  
 
  
   
   
 

   
 
  

 
  
 
  

 


 



 
   
 





 
    

  
 


 



 
               

 

 

    

 








 



  
 

 
    
 
 
  
 
 

 
 
 

 
  
   
 




   
   

   

   
 

 

   
    
  
 

 
 
    
  
 
 
 
 




 

  
 
 
  
 
  
  

   
 
 
  
 
   
 
 
  
  
 

 

  

  



 


  



 
 
 
 
    
 
  
 
 
 


 


  
 
 
 

 
    
 
  
 
 
 


 


  
 
 
 

   

   
   
 
  
 
 
 
  
 
 
 

 
 
  
 
 
  
 
 
 


 


  
 
 
 

  
 
 
 
    



     









    



   

    
      
   




 



























 

 
 


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





              


     





     
 
 

 

 


 


 


 





 




       
 unsigned int __cdecl _clearfp(void);


 __declspec(deprecated("This function or variable may be unsafe. Consider using _controlfp_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 unsigned int __cdecl _controlfp(
      unsigned int _NewValue,
      unsigned int _Mask
    );



 void __cdecl _set_controlfp(
      unsigned int _NewValue,
      unsigned int _Mask
    );


 errno_t __cdecl _controlfp_s(
      unsigned int* _CurrentState,
           unsigned int  _NewValue,
           unsigned int  _Mask
    );


 unsigned int __cdecl _statusfp(void);


 void __cdecl _fpreset(void);




 unsigned int __cdecl _control87(
      unsigned int _NewValue,
      unsigned int _Mask
    );


  
 int* __cdecl __fpecode(void);


 
 int __cdecl __fpe_flt_rounds(void);




        double __cdecl _copysign(  double _Number,   double _Sign);
   double __cdecl _chgsign(  double _X);
   double __cdecl _scalb(  double _X,   long _Y);
   double __cdecl _logb(  double _X);
   double __cdecl _nextafter(  double _X,   double _Y);
   int    __cdecl _finite(  double _X);
   int    __cdecl _isnan(  double _X);
   int    __cdecl _fpclass(  double _X);

       float __cdecl _scalbf(  float _X,   long _Y);



     

    
     void __cdecl fpreset(void);



     













}                             

 
  
 
  

       
       

         extern "C" {








     

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

 




 


 








 





typedef __int64 fpos_t;




    
     errno_t __cdecl _get_stream_buffer_pointers(
               FILE*   _Stream,
          char*** _Base,
          char*** _Pointer,
          int**   _Count
        );


                         
        
         errno_t __cdecl clearerr_s(
              FILE* _Stream
            );

        
         
         errno_t __cdecl fopen_s(
              FILE**      _Stream,
                                     char const* _FileName,
                                     char const* _Mode
            );

        
         
         size_t __cdecl fread_s(
                void*  _Buffer,
                                    size_t _BufferSize,
                                                                            size_t _ElementSize,
                                                                            size_t _ElementCount,
                                                                         FILE*  _Stream
            );

        
         errno_t __cdecl freopen_s(
              FILE**      _Stream,
                                 char const* _FileName,
                                 char const* _Mode,
                                FILE*       _OldStream
            );

         
         char* __cdecl gets_s(
              char*   _Buffer,
                               rsize_t _Size
            );

        
         errno_t __cdecl tmpfile_s(
                FILE** _Stream
            );

         
        
         errno_t __cdecl tmpnam_s(
              char*   _Buffer,
                               rsize_t _Size
            );


     void __cdecl clearerr(
          FILE* _Stream
        );

     
    
     int __cdecl fclose(
          FILE* _Stream
        );

    
     int __cdecl _fcloseall(void);

     
     FILE* __cdecl _fdopen(
            int         _FileHandle,
          char const* _Mode
        );

     
     int __cdecl feof(
          FILE* _Stream
        );

     
     int __cdecl ferror(
          FILE* _Stream
        );

    
     int __cdecl fflush(
          FILE* _Stream
        );

     
    
     int __cdecl fgetc(
          FILE* _Stream
        );

    
     int __cdecl _fgetchar(void);

     
    
     int __cdecl fgetpos(
          FILE*   _Stream,
            fpos_t* _Position
        );

     
    
     char* __cdecl fgets(
          char* _Buffer,
                               int   _MaxCount,
                            FILE* _Stream
        );

     
     int __cdecl _fileno(
          FILE* _Stream
        );

    
     int __cdecl _flushall(void);

      __declspec(deprecated("This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
     FILE* __cdecl fopen(
          char const* _FileName,
          char const* _Mode
        );


     
    
     int __cdecl fputc(
             int   _Character,
          FILE* _Stream
        );

    
     int __cdecl _fputchar(
          int _Character
        );

     
    
     int __cdecl fputs(
           char const* _Buffer,
          FILE*       _Stream
        );

    
     size_t __cdecl fread(
          void*  _Buffer,
                                                      size_t _ElementSize,
                                                      size_t _ElementCount,
                                                   FILE*  _Stream
        );

     
      __declspec(deprecated("This function or variable may be unsafe. Consider using freopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
     FILE* __cdecl freopen(
           char const* _FileName,
           char const* _Mode,
          FILE*       _Stream
        );

     
     FILE* __cdecl _fsopen(
          char const* _FileName,
          char const* _Mode,
            int         _ShFlag
        );

     
    
     int __cdecl fsetpos(
          FILE*         _Stream,
             fpos_t const* _Position
        );

     
    
     int __cdecl fseek(
          FILE* _Stream,
             long  _Offset,
             int   _Origin
        );

     
    
     int __cdecl _fseeki64(
          FILE*   _Stream,
             __int64 _Offset,
             int     _Origin
        );

     
     
     long __cdecl ftell(
          FILE* _Stream
        );

     
     
     __int64 __cdecl _ftelli64(
          FILE* _Stream
        );

    
     size_t __cdecl fwrite(
          void const* _Buffer,
                                                    size_t      _ElementSize,
                                                    size_t      _ElementCount,
                                                 FILE*       _Stream
        );

     
     
     int __cdecl getc(
          FILE* _Stream
        );

     
     int __cdecl getchar(void);

     
     int __cdecl _getmaxstdio(void);

    extern "C++"                                                                                      {                                                                                                     template <size_t _Size>                                                                           inline                                                                                            char* __cdecl gets_s(char (&_Buffer)[_Size]) throw()                  {                                                                                                     return gets_s(_Buffer, _Size);                                                                }                                                                                             }

     
     int __cdecl _getw(
          FILE* _Stream
        );

     void __cdecl perror(
          char const* _ErrorMessage
        );


         
        
         int __cdecl _pclose(
              FILE* _Stream
            );

         
         FILE* __cdecl _popen(
              char const* _Command,
              char const* _Mode
            );


     
    
     int __cdecl putc(
             int   _Character,
          FILE* _Stream
        );

    
     int __cdecl putchar(
          int _Character
        );

    
     int __cdecl puts(
          char const* _Buffer
        );

     
    
     int __cdecl _putw(
             int   _Word,
          FILE* _Stream
        );

     int __cdecl remove(
          char const* _FileName
        );

     
     int __cdecl rename(
          char const* _OldFileName,
          char const* _NewFileName
        );

     int __cdecl _unlink(
          char const* _FileName
        );


        __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _unlink. See online help for details."))
         int __cdecl unlink(
              char const* _FileName
            );


     void __cdecl rewind(
          FILE* _Stream
        );

    
     int __cdecl _rmtmp(void);

    __declspec(deprecated("This function or variable may be unsafe. Consider using setvbuf instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
     void __cdecl setbuf(
                                                      FILE* _Stream,
            char* _Buffer
        );

    
     int __cdecl _setmaxstdio(
          int _Maximum
        );

     
    
     int __cdecl setvbuf(
                               FILE*  _Stream,
            char*  _Buffer,
                                  int    _Mode,
                                  size_t _Size
        );


     
     __declspec(allocator) char* __cdecl _tempnam(
          char const* _DirectoryName,
          char const* _FilePrefix
        );


      __declspec(deprecated("This function or variable may be unsafe. Consider using tmpfile_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
     FILE* __cdecl tmpfile(void);

    extern "C++"                                                                                      {                                                                                                     template <size_t _Size>                                                                           inline                                                                                                     errno_t __cdecl tmpnam_s( char (&_Buffer)[_Size]) throw()                  {                                                                                                     return tmpnam_s(_Buffer, _Size);                                                                }                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))           char* __cdecl tmpnam(   char *_Buffer);

     
    
     int __cdecl ungetc(
             int   _Character,
          FILE* _Stream
        );



                              void __cdecl _lock_file(
          FILE* _Stream
        );

     void __cdecl _unlock_file(
          FILE* _Stream
        );

     
    
     int __cdecl _fclose_nolock(
          FILE* _Stream
        );

     
    
     int __cdecl _fflush_nolock(
          FILE* _Stream
        );

     
    
     int __cdecl _fgetc_nolock(
          FILE* _Stream
        );

     
    
     int __cdecl _fputc_nolock(
             int   _Character,
          FILE* _Stream
        );

    
     size_t __cdecl _fread_nolock(
          void*  _Buffer,
                                                      size_t _ElementSize,
                                                      size_t _ElementCount,
                                                   FILE*  _Stream
        );

    
     
     size_t __cdecl _fread_nolock_s(
          void*  _Buffer,
                              size_t _BufferSize,
                                                                      size_t _ElementSize,
                                                                      size_t _ElementCount,
                                                                   FILE*  _Stream
        );

    
     int __cdecl _fseek_nolock(
          FILE* _Stream,
             long  _Offset,
             int   _Origin
        );

    
     int __cdecl _fseeki64_nolock(
          FILE*   _Stream,
             __int64 _Offset,
             int     _Origin
        );

     
     long __cdecl _ftell_nolock(
          FILE* _Stream
        );

     
     __int64 __cdecl _ftelli64_nolock(
          FILE* _Stream
        );

    
     size_t __cdecl _fwrite_nolock(
          void const* _Buffer,
                                                    size_t      _ElementSize,
                                                    size_t      _ElementCount,
                                                 FILE*       _Stream
        );

    
     int __cdecl _getc_nolock(
          FILE* _Stream
        );

    
     int __cdecl _putc_nolock(
             int   _Character,
          FILE* _Stream
        );

    
     int __cdecl _ungetc_nolock(
             int   _Character,
          FILE* _Stream
        );







     int* __cdecl __p__commode(void);




     
                              int __cdecl __stdio_common_vfprintf(
                                             unsigned __int64 _Options,
                                          FILE*            _Stream,
            char const*      _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     int __cdecl __stdio_common_vfprintf_s(
                                             unsigned __int64 _Options,
                                          FILE*            _Stream,
            char const*      _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     
     int __cdecl __stdio_common_vfprintf_p(
                                             unsigned __int64 _Options,
                                          FILE*            _Stream,
            char const*      _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

    
    __inline int __cdecl _vfprintf_l(
           FILE*       const _Stream,
            char const* const _Format,
          _locale_t   const _Locale,
                 va_list           _ArgList
        )
    {
        return __stdio_common_vfprintf((*__local_stdio_printf_options()), _Stream, _Format, _Locale, _ArgList);
    }

    
    __inline int __cdecl vfprintf(
                                FILE*       const _Stream,
            char const* const _Format,
                                      va_list           _ArgList
        )
    {
        return _vfprintf_l(_Stream, _Format, 0, _ArgList);
    }

    
    __inline int __cdecl _vfprintf_s_l(
           FILE*       const _Stream,
            char const* const _Format,
          _locale_t   const _Locale,
                 va_list           _ArgList
        )
    {
        return __stdio_common_vfprintf_s((*__local_stdio_printf_options()), _Stream, _Format, _Locale, _ArgList);
    }


        
        __inline int __cdecl vfprintf_s(
                                    FILE*       const _Stream,
                char const* const _Format,
                                          va_list           _ArgList
            )
        {
            return _vfprintf_s_l(_Stream, _Format, 0, _ArgList);
        }


    
    __inline int __cdecl _vfprintf_p_l(
           FILE*       const _Stream,
            char const* const _Format,
          _locale_t   const _Locale,
                 va_list           _ArgList
        )
    {
        return __stdio_common_vfprintf_p((*__local_stdio_printf_options()), _Stream, _Format, _Locale, _ArgList);
    }

    
    __inline int __cdecl _vfprintf_p(
                                FILE*       const _Stream,
            char const* const _Format,
                                      va_list           _ArgList
        )
    {
        return _vfprintf_p_l(_Stream, _Format, 0, _ArgList);
    }

    
    __inline int __cdecl _vprintf_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
                                                va_list           _ArgList
        )
    {
        return _vfprintf_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
    }

    
    __inline int __cdecl vprintf(
            char const* const _Format,
                                      va_list           _ArgList
        )
    {
        return _vfprintf_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
    }

    
    __inline int __cdecl _vprintf_s_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
                                                va_list           _ArgList
        )
    {
        return _vfprintf_s_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
    }


        
        __inline int __cdecl vprintf_s(
                char const* const _Format,
                                          va_list           _ArgList
            )
        {
            return _vfprintf_s_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
        }


    
    __inline int __cdecl _vprintf_p_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
                                                va_list           _ArgList
        )
    {
        return _vfprintf_p_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
    }

    
    __inline int __cdecl _vprintf_p(
            char const* const _Format,
                                      va_list           _ArgList
        )
    {
        return _vfprintf_p_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
    }

    
    __inline int __cdecl _fprintf_l(
                                          FILE*       const _Stream,
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfprintf_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl fprintf(
                                FILE*       const _Stream,
            char const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vfprintf_l(_Stream, _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     int __cdecl _set_printf_count_output(
          int _Value
        );

     int __cdecl _get_printf_count_output(void);

    
    __inline int __cdecl _fprintf_s_l(
                                          FILE*       const _Stream,
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfprintf_s_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


        
        __inline int __cdecl fprintf_s(
                                    FILE*       const _Stream,
                char const* const _Format,
            ...)
        {
            int _Result;
            va_list _ArgList;
            ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
            _Result = _vfprintf_s_l(_Stream, _Format, 0, _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }


    
    __inline int __cdecl _fprintf_p_l(
                                          FILE*       const _Stream,
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfprintf_p_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _fprintf_p(
                                FILE*       const _Stream,
            char const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vfprintf_p_l(_Stream, _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _printf_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfprintf_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl printf(
            char const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vfprintf_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _printf_s_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfprintf_s_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


        
        __inline int __cdecl printf_s(
                char const* const _Format,
            ...)
        {
            int _Result;
            va_list _ArgList;
            ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
            _Result = _vfprintf_s_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }


    
    __inline int __cdecl _printf_p_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfprintf_p_l((__acrt_iob_func(1)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _printf_p(
            char const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vfprintf_p_l((__acrt_iob_func(1)), _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


                              int __cdecl __stdio_common_vfscanf(
                                            unsigned __int64 _Options,
                                         FILE*            _Stream,
            char const*      _Format,
                                        _locale_t        _Locale,
                                               va_list          _Arglist
        );

    
    __inline int __cdecl _vfscanf_l(
                                FILE*       const _Stream,
            char const* const _Format,
                               _locale_t   const _Locale,
                                      va_list           _ArgList
        )
    {
        return __stdio_common_vfscanf(
            (*__local_stdio_scanf_options ()),
            _Stream, _Format, _Locale, _ArgList);
    }

    
    __inline int __cdecl vfscanf(
                                FILE*       const _Stream,
            char const* const _Format,
                                      va_list           _ArgList
        )
    {
        return _vfscanf_l(_Stream, _Format, 0, _ArgList);
    }

    
    __inline int __cdecl _vfscanf_s_l(
                                FILE*       const _Stream,
            char const* const _Format,
                               _locale_t   const _Locale,
                                      va_list           _ArgList
        )
    {
        return __stdio_common_vfscanf(
            (*__local_stdio_scanf_options ()) | (1ULL << 0),
            _Stream, _Format, _Locale, _ArgList);
    }



        
        __inline int __cdecl vfscanf_s(
                                    FILE*       const _Stream,
                char const* const _Format,
                                          va_list           _ArgList
            )
        {
            return _vfscanf_s_l(_Stream, _Format, 0, _ArgList);
        }


    
    __inline int __cdecl _vscanf_l(
            char const* const _Format,
                               _locale_t   const _Locale,
                                      va_list           _ArgList
        )
    {
        return _vfscanf_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
    }

    
    __inline int __cdecl vscanf(
            char const* const _Format,
                                      va_list           _ArgList
        )
    {
        return _vfscanf_l((__acrt_iob_func(0)), _Format, 0, _ArgList);
    }

    
    __inline int __cdecl _vscanf_s_l(
            char const* const _Format,
                               _locale_t   const _Locale,
                                      va_list           _ArgList
        )
    {
        return _vfscanf_s_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
    }


        
        __inline int __cdecl vscanf_s(
                char const* const _Format,
                                          va_list           _ArgList
            )
        {
            return _vfscanf_s_l((__acrt_iob_func(0)), _Format, 0, _ArgList);
        }


     __declspec(deprecated("This function or variable may be unsafe. Consider using _fscanf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _fscanf_l(
                                         FILE*       const _Stream,
            char const* const _Format,
                                        _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfscanf_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

      __declspec(deprecated("This function or variable may be unsafe. Consider using fscanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl fscanf(
                               FILE*       const _Stream,
            char const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vfscanf_l(_Stream, _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _fscanf_s_l(
                                           FILE*       const _Stream,
            char const* const _Format,
                                          _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfscanf_s_l(_Stream, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


        
        __inline int __cdecl fscanf_s(
                                     FILE*       const _Stream,
                char const* const _Format,
            ...)
        {
            int _Result;
            va_list _ArgList;
            ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
            _Result = _vfscanf_s_l(_Stream, _Format, 0, _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }


     __declspec(deprecated("This function or variable may be unsafe. Consider using _scanf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _scanf_l(
            char const* const _Format,
                                        _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfscanf_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

      __declspec(deprecated("This function or variable may be unsafe. Consider using scanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl scanf(
            char const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vfscanf_l((__acrt_iob_func(0)), _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _scanf_s_l(
            char const* const _Format,
                                          _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vfscanf_s_l((__acrt_iob_func(0)), _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


        
        __inline int __cdecl scanf_s(
                char const* const _Format,
            ...)
        {
            int _Result;
            va_list _ArgList;
            ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
            _Result = _vfscanf_s_l((__acrt_iob_func(0)), _Format, 0, _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }




                              
     int __cdecl __stdio_common_vsprintf(
                                             unsigned __int64 _Options,
                 char*            _Buffer,
                                             size_t           _BufferCount,
            char const*      _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     
     int __cdecl __stdio_common_vsprintf_s(
                                             unsigned __int64 _Options,
                     char*            _Buffer,
                                             size_t           _BufferCount,
            char const*      _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     
     int __cdecl __stdio_common_vsnprintf_s(
                                             unsigned __int64 _Options,
                 char*            _Buffer,
                                             size_t           _BufferCount,
                                             size_t           _MaxCount,
            char const*      _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     
     int __cdecl __stdio_common_vsprintf_p(
                                             unsigned __int64 _Options,
                     char*            _Buffer,
                                             size_t           _BufferCount,
            char const*      _Format,
                                         _locale_t        _Locale,
                                                va_list          _ArgList
        );

     
     __declspec(deprecated("This function or variable may be unsafe. Consider using _vsnprintf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _vsnprintf_l(
            char*       const _Buffer,
                                                  size_t      const _BufferCount,
                 char const* const _Format,
                                              _locale_t   const _Locale,
                                                     va_list           _ArgList
        )
    {
        int const _Result = __stdio_common_vsprintf(
            (*__local_stdio_printf_options()) | (1ULL << 0),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }

     
    
    __inline int __cdecl _vsnprintf(
            char*       const _Buffer,
                                                 size_t      const _BufferCount,
                          char const* const _Format,
                                                    va_list           _ArgList
        )
    {
        return _vsnprintf_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
    }


     
    
    __inline int __cdecl vsnprintf(
           char*       const _Buffer,
                                                       size_t      const _BufferCount,
                                char const* const _Format,
                                                          va_list           _ArgList
        )
    {
        int const _Result = __stdio_common_vsprintf(
            (*__local_stdio_printf_options()) | (1ULL << 1),
            _Buffer, _BufferCount, _Format, 0, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }

     
     __declspec(deprecated("This function or variable may be unsafe. Consider using _vsprintf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _vsprintf_l(
           char*       const _Buffer,
                                    char const* const _Format,
                                  _locale_t   const _Locale,
                                         va_list           _ArgList
        )
    {
        return _vsnprintf_l(_Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    }

     
     __declspec(deprecated("This function or variable may be unsafe. Consider using vsprintf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl vsprintf(
           char*       const _Buffer,
               char const* const _Format,
                                         va_list           _ArgList
        )
    {
        return _vsnprintf_l(_Buffer, (size_t)-1, _Format, 0, _ArgList);
    }

     
    
    __inline int __cdecl _vsprintf_s_l(
           char*       const _Buffer,
                                                   size_t      const _BufferCount,
                  char const* const _Format,
                                               _locale_t   const _Locale,
                                                      va_list           _ArgList
        )
    {
        int const _Result = __stdio_common_vsprintf_s(
            (*__local_stdio_printf_options()),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }


         
        
        __inline int __cdecl vsprintf_s(
               char*       const _Buffer,
                                                       size_t      const _BufferCount,
                                char const* const _Format,
                                                          va_list           _ArgList
            )
        {
            return _vsprintf_s_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
        }

        extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                                        int __cdecl vsprintf_s(            char (&_Buffer)[_Size],     char const* _Format, va_list _ArgList) throw()                 {                                                                                                                                    return vsprintf_s(_Buffer, _Size, _Format, _ArgList);                                                                               }                                                                                                                            }


     
    
    __inline int __cdecl _vsprintf_p_l(
           char*       const _Buffer,
                                                   size_t      const _BufferCount,
                  char const* const _Format,
                                               _locale_t   const _Locale,
                                                      va_list           _ArgList
        )
    {
        int const _Result = __stdio_common_vsprintf_p(
            (*__local_stdio_printf_options()),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }

     
    
    __inline int __cdecl _vsprintf_p(
           char*       const _Buffer,
                                                   size_t      const _BufferCount,
                            char const* const _Format,
                                                      va_list           _ArgList
        )
    {
        return _vsprintf_p_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
    }

     
    
    __inline int __cdecl _vsnprintf_s_l(
           char*       const _Buffer,
                                                       size_t      const _BufferCount,
                                                       size_t      const _MaxCount,
                      char const* const _Format,
                                                   _locale_t   const _Locale,
                                                          va_list          _ArgList
        )
    {
        int const _Result = __stdio_common_vsnprintf_s(
            (*__local_stdio_printf_options()),
            _Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }

     
    
    __inline int __cdecl _vsnprintf_s(
           char*       const _Buffer,
                                                       size_t      const _BufferCount,
                                                       size_t      const _MaxCount,
                                char const* const _Format,
                                                          va_list           _ArgList
        )
    {
        return _vsnprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, 0, _ArgList);
    }

    extern "C++"                                                                                                                                     {                                                                                                                                                    template <size_t _Size>                                                                                                                          inline                                                                                                                                                    int __cdecl _vsnprintf_s(            char (&_Buffer)[_Size],                            size_t _BufferCount,     char const* _Format, va_list _ArgList) throw()                 {                                                                                                                                                    return _vsnprintf_s(_Buffer, _Size, _BufferCount, _Format, _ArgList);                                                                                       }                                                                                                                                            }


         
        
        __inline int __cdecl vsnprintf_s(
               char*       const _Buffer,
                                                           size_t      const _BufferCount,
                                                           size_t      const _MaxCount,
                                    char const* const _Format,
                                                              va_list           _ArgList
            )
        {
            return _vsnprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, 0, _ArgList);
        }

        extern "C++"                                                                                                                                     {                                                                                                                                                    template <size_t _Size>                                                                                                                          inline                                                                                                                                                        int __cdecl vsnprintf_s(            char (&_Buffer)[_Size],                            size_t _BufferCount,     char const* _Format, va_list _ArgList) throw()                 {                                                                                                                                                    return vsnprintf_s(_Buffer, _Size, _BufferCount, _Format, _ArgList);                                                                                       }                                                                                                                                            }


    
    __inline int __cdecl _vscprintf_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
                                                va_list           _ArgList
        )
    {
        int const _Result = __stdio_common_vsprintf(
            (*__local_stdio_printf_options()) | (1ULL << 1),
            0, 0, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }

     
    __inline int __cdecl _vscprintf(
            char const* const _Format,
                                      va_list           _ArgList
        )
    {
        return _vscprintf_l(_Format, 0, _ArgList);
    }

    
    __inline int __cdecl _vscprintf_p_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
                                                va_list           _ArgList
        )
    {
        int const _Result = __stdio_common_vsprintf_p(
            (*__local_stdio_printf_options()) | (1ULL << 1),
            0, 0, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }

     
    __inline int __cdecl _vscprintf_p(
            char const* const _Format,
                                      va_list           _ArgList
        )
    {
        return _vscprintf_p_l(_Format, 0, _ArgList);
    }

    
    __inline int __cdecl _vsnprintf_c_l(
                   char*       const _Buffer,
                                             size_t      const _BufferCount,
            char const* const _Format,
                                         _locale_t   const _Locale,
                                                va_list           _ArgList
        )
    {
        int const _Result = __stdio_common_vsprintf(
            (*__local_stdio_printf_options()),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }

     
    
    __inline int __cdecl _vsnprintf_c(
          char*       const _Buffer,
                                    size_t      const _BufferCount,
             char const* const _Format,
                                       va_list           _ArgList
        )
    {
        return _vsnprintf_c_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
    }

     
     __declspec(deprecated("This function or variable may be unsafe. Consider using _sprintf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _sprintf_l(
                  char*       const _Buffer,
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));

        _Result = _vsprintf_l(_Buffer, _Format, _Locale, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    
    __inline int __cdecl sprintf(
           char*       const _Buffer,
               char const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));

        _Result = _vsprintf_l(_Buffer, _Format, 0, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    __declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))           int __cdecl sprintf(   char *_Buffer,         char const* _Format, ...);                 __declspec(deprecated("This function or variable may be unsafe. Consider using _SecureVFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))           int __cdecl vsprintf(   char *_Buffer,         char const* _Format, va_list _Args);

     
    
    __inline int __cdecl _sprintf_s_l(
           char*       const _Buffer,
                                                   size_t      const _BufferCount,
                  char const* const _Format,
                                               _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vsprintf_s_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


         
        
        __inline int __cdecl sprintf_s(
               char*       const _Buffer,
                                                       size_t      const _BufferCount,
                                char const* const _Format,
            ...)
        {
            int _Result;
            va_list _ArgList;
            ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
            _Result = _vsprintf_s_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
            ((void)(_ArgList = (va_list)0));
            return _Result;
        }


    extern "C++"                                                                                                                       {                                                                                                                                      template <size_t _Size>                                                                                                            inline                                                                                                                                      int __cdecl sprintf_s(            char (&_Buffer)[_Size],     char const* _Format, ...) throw()                              {                                                                                                                                      va_list _ArgList;                                                                                                                  ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));                                                                                                  return vsprintf_s(_Buffer, _Size, _Format, _ArgList);                                                                              }                                                                                                                              }

     
    
    __inline int __cdecl _sprintf_p_l(
           char*       const _Buffer,
                                                   size_t      const _BufferCount,
                  char const* const _Format,
                                               _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vsprintf_p_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    
    __inline int __cdecl _sprintf_p(
           char*       const _Buffer,
                                                   size_t      const _BufferCount,
                            char const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vsprintf_p_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
     __declspec(deprecated("This function or variable may be unsafe. Consider using _snprintf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _snprintf_l(
            char*       const _Buffer,
                                                  size_t      const _BufferCount,
                 char const* const _Format,
                                              _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));

        _Result = _vsnprintf_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


     
    
    __inline int __cdecl snprintf(
           char*       const _Buffer,
                                                       size_t      const _BufferCount,
                                char const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = vsnprintf(_Buffer, _BufferCount, _Format, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    
    __inline int __cdecl _snprintf(
            char*       const _Buffer,
                                                  size_t      const _BufferCount,
                           char const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vsnprintf(_Buffer, _BufferCount, _Format, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    __declspec(deprecated("This function or variable may be unsafe. Consider using _FuncName##_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))           int __cdecl _snprintf(    char *_Buffer,                                            size_t _BufferCount,                     char const* _Format, ...);                 __declspec(deprecated("This function or variable may be unsafe. Consider using _VFuncName##_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))           int __cdecl _vsnprintf(    char *_Buffer,                                            size_t _BufferCount,                     char const* _Format, va_list _Args);

     
    
    __inline int __cdecl _snprintf_c_l(
                   char*       const _Buffer,
                                             size_t      const _BufferCount,
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vsnprintf_c_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    
    __inline int __cdecl _snprintf_c(
          char*       const _Buffer,
                                    size_t      const _BufferCount,
             char const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vsnprintf_c_l(_Buffer, _BufferCount, _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    
    __inline int __cdecl _snprintf_s_l(
           char*       const _Buffer,
                                                       size_t      const _BufferCount,
                                                       size_t      const _MaxCount,
                      char const* const _Format,
                                                   _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vsnprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    
    __inline int __cdecl _snprintf_s(
           char*       const _Buffer,
                                                       size_t      const _BufferCount,
                                                       size_t      const _MaxCount,
                                char const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vsnprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    extern "C++"                                                                                                                                        {                                                                                                                                                       template <size_t _Size>                                                                                                                             inline                                                                                                                                                       int __cdecl _snprintf_s(            char (&_Buffer)[_Size],                            size_t _BufferCount,     char const* _Format, ...) throw()                               {                                                                                                                                                       va_list _ArgList;                                                                                                                                   ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));                                                                                                                   return _vsnprintf_s(_Buffer, _Size, _BufferCount, _Format, _ArgList);                                                                                       }                                                                                                                                               }

    
    __inline int __cdecl _scprintf_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vscprintf_l(_Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    __inline int __cdecl _scprintf(
            char const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vscprintf_l(_Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _scprintf_p_l(
            char const* const _Format,
                                         _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vscprintf_p_l(_Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     
    __inline int __cdecl _scprintf_p(
            char const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vscprintf_p(_Format, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

                              int __cdecl __stdio_common_vsscanf(
                                            unsigned __int64 _Options,
                  char const*      _Buffer,
                                            size_t           _BufferCount,
            char const*      _Format,
                                        _locale_t        _Locale,
                                               va_list          _ArgList
        );

    
    __inline int __cdecl _vsscanf_l(
                                 char const* const _Buffer,
            char const* const _Format,
                               _locale_t   const _Locale,
                                      va_list           _ArgList
        )
    {
        return __stdio_common_vsscanf(
            (*__local_stdio_scanf_options ()),
            _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    }

    
    __inline int __cdecl vsscanf(
                                 char const* const _Buffer,
            char const* const _Format,
                                      va_list           _ArgList
        )
    {
        return _vsscanf_l(_Buffer, _Format, 0, _ArgList);
    }

    
    __inline int __cdecl _vsscanf_s_l(
                                 char const* const _Buffer,
            char const* const _Format,
                               _locale_t   const _Locale,
                                      va_list           _ArgList
        )
    {
        return __stdio_common_vsscanf(
            (*__local_stdio_scanf_options ()) | (1ULL << 0),
            _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    }



        
        __inline int __cdecl vsscanf_s(
                                     char const* const _Buffer,
                char const* const _Format,
                                          va_list           _ArgList
            )
        {
            return _vsscanf_s_l(_Buffer, _Format, 0, _ArgList);
        }

        extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           int __cdecl vsscanf_s(                         char const (&_Buffer)[_Size],     char const* _Format, va_list _ArgList) throw()                 {                                                                                                                                    return vsscanf_s(_Buffer, _Size, _Format, _ArgList);                                                                               }                                                                                                                            }



     __declspec(deprecated("This function or variable may be unsafe. Consider using _sscanf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _sscanf_l(
                                          char const* const _Buffer,
            char const* const _Format,
                                        _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vsscanf_l(_Buffer, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

      __declspec(deprecated("This function or variable may be unsafe. Consider using sscanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl sscanf(
                                char const* const _Buffer,
            char const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));
        _Result = _vsscanf_l(_Buffer, _Format, 0, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _sscanf_s_l(
                                            char const* const _Buffer,
            char const* const _Format,
                                          _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));
        _Result = _vsscanf_s_l(_Buffer, _Format, _Locale, _ArgList);
        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


        
        __inline int __cdecl sscanf_s(
                                      char const* const _Buffer,
                char const* const _Format,
            ...)
        {
            int _Result;
            va_list _ArgList;
            ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));

            _Result = vsscanf_s(_Buffer, _Format, _ArgList);

            ((void)(_ArgList = (va_list)0));
            return _Result;
        }



     __declspec(deprecated("This function or variable may be unsafe. Consider using _snscanf_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _snscanf_l(
            char const* const _Buffer,
                                            size_t      const _BufferCount,
            char const* const _Format,
                                        _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));

        _Result = __stdio_common_vsscanf(
            (*__local_stdio_scanf_options ()),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

     __declspec(deprecated("This function or variable may be unsafe. Consider using _snscanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
    __inline int __cdecl _snscanf(
            char const* const _Buffer,
                                            size_t      const _BufferCount,
                      char const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));

        _Result = __stdio_common_vsscanf(
            (*__local_stdio_scanf_options ()),
            _Buffer, _BufferCount, _Format, 0, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }


    
    __inline int __cdecl _snscanf_s_l(
              char const* const _Buffer,
                                              size_t      const _BufferCount,
            char const* const _Format,
                                          _locale_t   const _Locale,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Locale)))));

        _Result = __stdio_common_vsscanf(
            (*__local_stdio_scanf_options ()) | (1ULL << 0),
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }

    
    __inline int __cdecl _snscanf_s(
            char const* const _Buffer,
                                            size_t      const _BufferCount,
                    char const* const _Format,
        ...)
    {
        int _Result;
        va_list _ArgList;
        ((void)(__vcrt_assert_va_start_is_not_reference<decltype(x)>(), ((void)(__va_start(&_ArgList, _Format)))));

        _Result = __stdio_common_vsscanf(
            (*__local_stdio_scanf_options ()) | (1ULL << 0),
            _Buffer, _BufferCount, _Format, 0, _ArgList);

        ((void)(_ArgList = (va_list)0));
        return _Result;
    }





                         


        __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _tempnam. See online help for details."))
         char* __cdecl tempnam(
              char const* _Directory,
              char const* _FilePrefix
            );


         __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _fcloseall. See online help for details."))  int   __cdecl fcloseall(void);
              __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _fdopen. See online help for details."))     FILE* __cdecl fdopen(  int _FileHandle,   char const* _Format);
         __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _fgetchar. See online help for details."))   int   __cdecl fgetchar(void);
              __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _fileno. See online help for details."))     int   __cdecl fileno(  FILE* _Stream);
         __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _flushall. See online help for details."))   int   __cdecl flushall(void);
         __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _fputchar. See online help for details."))   int   __cdecl fputchar(  int _Ch);
              __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _getw. See online help for details."))       int   __cdecl getw(  FILE* _Stream);
         __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _putw. See online help for details."))       int   __cdecl putw(  int _Ch,   FILE* _Stream);
              __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _rmtmp. See online help for details."))      int   __cdecl rmtmp(void);




}                             




 
 
namespace std {

using :: FILE;
using :: _Mbstatet;

using :: size_t;
using :: fpos_t;
using :: FILE;
using :: clearerr;
using :: fclose;
using :: feof;
using :: ferror;
using :: fflush;
using :: fgetc;
using :: fgetpos;
using :: fgets;
using :: fopen;
using :: fprintf;
using :: fputc;
using :: fputs;
using :: fread;
using :: freopen;
using :: fscanf;
using :: fseek;
using :: fsetpos;
using :: ftell;
using :: fwrite;
using :: getc;
using :: getchar;
using :: perror;
using :: putc;
using :: putchar;
using :: printf;
using :: puts;
using :: remove;
using :: rename;
using :: rewind;
using :: scanf;
using :: setbuf;
using :: setvbuf;
using :: sprintf;
using :: sscanf;
using :: tmpfile;
using :: tmpnam;
using :: ungetc;
using :: vfprintf;
using :: vprintf;
using :: vsprintf;

using :: snprintf;
using :: vsnprintf;
using :: vfscanf;
using :: vscanf;
using :: vsscanf;

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




using _Mbstatet = mbstate_t;

namespace std {

using :: _Mbstatet;

using :: mbstate_t;
using :: size_t;
using :: tm;
using :: wint_t;

using :: btowc;
using :: fgetwc;
using :: fgetws;
using :: fputwc;
using :: fputws;
using :: fwide;
using :: fwprintf;
using :: fwscanf;
using :: getwc;
using :: getwchar;
using :: mbrlen;
using :: mbrtowc;
using :: mbsrtowcs;
using :: mbsinit;
using :: putwc;
using :: putwchar;
using :: swprintf;
using :: swscanf;
using :: ungetwc;
using :: vfwprintf;
using :: vswprintf;
using :: vwprintf;
using :: wcrtomb;
using :: wprintf;
using :: wscanf;
using :: wcsrtombs;
using :: wcstol;
using :: wcscat;
using :: wcschr;
using :: wcscmp;
using :: wcscoll;
using :: wcscpy;
using :: wcscspn;
using :: wcslen;
using :: wcsncat;
using :: wcsncmp;
using :: wcsncpy;
using :: wcspbrk;
using :: wcsrchr;
using :: wcsspn;
using :: wcstod;
using :: wcstoul;
using :: wcsstr;
using :: wcstok;
using :: wcsxfrm;
using :: wctob;
using :: wmemchr;
using :: wmemcmp;
using :: wmemcpy;
using :: wmemmove;
using :: wmemset;
using :: wcsftime;

using :: vfwscanf;
using :: vswscanf;
using :: vwscanf;
using :: wcstof;
using :: wcstold;
using :: wcstoll;
using :: wcstoull;

}



 

       


extern "C" {

 


 






 






 

(void __dmb(unsigned int _Type))

unsigned char _BitScanForward(unsigned long * _Index, unsigned long _Mask);
unsigned char _BitScanForward64(unsigned long * _Index, unsigned __int64 _Mask);
(unsigned char _BitScanForward64(unsigned long * _Index, unsigned __int64 _Mask))
unsigned char _BitScanReverse(unsigned long * _Index, unsigned long _Mask);
unsigned char _BitScanReverse64(unsigned long * _Index, unsigned __int64 _Mask);
(unsigned char _BitScanReverse64(unsigned long * _Index, unsigned __int64 _Mask))
unsigned char _bittest(long const *, long);
(unsigned int _CountLeadingZeros(unsigned long))
(unsigned int _CountLeadingZeros64(unsigned __int64))
long _InterlockedAnd(long volatile * _Value, long _Mask);
short _InterlockedAnd16(short volatile * _Value, short _Mask);
(short _InterlockedAnd16_acq(short volatile * _Value, short _Mask))
(short _InterlockedAnd16_nf(short volatile * _Value, short _Mask))
(short _InterlockedAnd16_rel(short volatile * _Value, short _Mask))
__int64 _InterlockedAnd64(__int64 volatile * _Value, __int64 _Mask);
(__int64 _InterlockedAnd64_acq(__int64 volatile * _Value, __int64 _Mask))
(__int64 _InterlockedAnd64_nf(__int64 volatile * _Value, __int64 _Mask))
(__int64 _InterlockedAnd64_rel(__int64 volatile * _Value, __int64 _Mask))
char _InterlockedAnd8(char volatile * _Value, char _Mask);
(char _InterlockedAnd8_acq(char volatile * _Value, char _Mask))
(char _InterlockedAnd8_nf(char volatile * _Value, char _Mask))
(char _InterlockedAnd8_rel(char volatile * _Value, char _Mask))
(long _InterlockedAnd_acq(long volatile * _Value, long _Mask))
(long _InterlockedAnd_nf(long volatile * _Value, long _Mask))
(long _InterlockedAnd_rel(long volatile * _Value, long _Mask))
long  _InterlockedCompareExchange(long volatile * _Destination, long _Exchange, long _Comparand);

short _InterlockedCompareExchange16(short volatile * _Destination, short _Exchange, short _Comparand);
(short _InterlockedCompareExchange16_acq(short volatile * _Destination, short _Exchange, short _Comparand))
(short _InterlockedCompareExchange16_nf(short volatile * _Destination, short _Exchange, short _Comparand))
(short _InterlockedCompareExchange16_rel(short volatile * _Destination, short _Exchange, short _Comparand))
__int64 _InterlockedCompareExchange64(__int64 volatile * _Destination, __int64 _Exchange, __int64 _Comparand);
(__int64 _InterlockedCompareExchange64_acq(__int64 volatile * _Destination, __int64 _Exchange, __int64 _Comparand))
(__int64 _InterlockedCompareExchange64_nf(__int64 volatile * _Destination, __int64 _Exchange, __int64 _Comparand))
(__int64 _InterlockedCompareExchange64_rel(__int64 volatile * _Destination, __int64 _Exchange, __int64 _Comparand))
char _InterlockedCompareExchange8(char volatile * _Destination, char _Exchange, char _Comparand);
(char _InterlockedCompareExchange8_acq(char volatile * _Destination, char _Exchange, char _Comparand))
(char _InterlockedCompareExchange8_nf(char volatile * _Destination, char _Exchange, char _Comparand))
(char _InterlockedCompareExchange8_rel(char volatile * _Destination, char _Exchange, char _Comparand))
(long _InterlockedCompareExchange_acq(long volatile * _Destination, long _Exchange, long _Comparand))
(long _InterlockedCompareExchange_nf(long volatile * _Destination, long _Exchange, long _Comparand))
(long _InterlockedCompareExchange_rel(long volatile * _Destination, long _Exchange, long _Comparand))
unsigned char _InterlockedCompareExchange128(__int64 volatile * _Destination, __int64 _ExchangeHigh, __int64 _ExchangeLow, __int64 * _ComparandResult);
(unsigned char _InterlockedCompareExchange128_acq(__int64 volatile * _Destination, __int64 _ExchangeHigh, __int64 _ExchangeLow, __int64 * _ComparandResult))
(unsigned char _InterlockedCompareExchange128_nf(__int64 volatile * _Destination, __int64 _ExchangeHigh, __int64 _ExchangeLow, __int64 * _ComparandResult))
(unsigned char _InterlockedCompareExchange128_rel(__int64 volatile * _Destination, __int64 _ExchangeHigh, __int64 _ExchangeLow, __int64 * _ComparandResult))
long  _InterlockedDecrement(long volatile * _Addend);

short _InterlockedDecrement16(short volatile * _Addend);
__int64 _InterlockedDecrement64(__int64 volatile * _Addend);
long  _InterlockedExchange(long volatile * _Target, long _Value);

short _InterlockedExchange16(short volatile * _Target, short _Value);
(short _InterlockedExchange16_acq(short volatile * _Target, short _Value))
(short _InterlockedExchange16_nf(short volatile * _Target, short _Value))
(short _InterlockedExchange16_rel(short volatile * _Target, short _Value))
__int64 _InterlockedExchange64(__int64 volatile * _Target, __int64 _Value);
(__int64 _InterlockedExchange64_acq(__int64 volatile * _Target, __int64 _Value))
(__int64 _InterlockedExchange64_nf(__int64 volatile * _Target, __int64 _Value))
(__int64 _InterlockedExchange64_rel(__int64 volatile * _Target, __int64 _Value))
char _InterlockedExchange8(char volatile * _Target, char _Value);
(char _InterlockedExchange8_acq(char volatile * _Target, char _Value))
(char _InterlockedExchange8_nf(char volatile * _Target, char _Value))
(char _InterlockedExchange8_rel(char volatile * _Target, char _Value))
long  _InterlockedExchangeAdd(long volatile * _Addend, long _Value);
short _InterlockedExchangeAdd16(short volatile * _Addend, short _Value);
(short _InterlockedExchangeAdd16_acq(short volatile * _Addend, short _Value))
(short _InterlockedExchangeAdd16_nf(short volatile * _Addend, short _Value))
(short _InterlockedExchangeAdd16_rel(short volatile * _Addend, short _Value))
__int64 _InterlockedExchangeAdd64(__int64 volatile * _Addend, __int64 _Value);
(__int64 _InterlockedExchangeAdd64_acq(__int64 volatile * _Addend, __int64 _Value))
(__int64 _InterlockedExchangeAdd64_nf(__int64 volatile * _Addend, __int64 _Value))
(__int64 _InterlockedExchangeAdd64_rel(__int64 volatile * _Addend, __int64 _Value))
char _InterlockedExchangeAdd8(char volatile * _Addend, char _Value);
(char _InterlockedExchangeAdd8_acq(char volatile * _Addend, char _Value))
(char _InterlockedExchangeAdd8_nf(char volatile * _Addend, char _Value))
(char _InterlockedExchangeAdd8_rel(char volatile * _Addend, char _Value))
(long _InterlockedExchangeAdd_acq(long volatile * _Addend, long _Value))
(long _InterlockedExchangeAdd_nf(long volatile * _Addend, long _Value))
(long _InterlockedExchangeAdd_rel(long volatile * _Addend, long _Value))
(long _InterlockedExchange_acq(long volatile * _Target, long _Value))
(long _InterlockedExchange_nf(long volatile * _Target, long _Value))
(long _InterlockedExchange_rel(long volatile * _Target, long _Value))
long  _InterlockedIncrement(long volatile * _Addend);

short _InterlockedIncrement16(short volatile * _Addend);
__int64 _InterlockedIncrement64(__int64 volatile * _Addend);
(long _InterlockedIncrement_nf(long volatile * _Addend))
long _InterlockedOr(long volatile * _Value, long _Mask);
short _InterlockedOr16(short volatile * _Value, short _Mask);
(short _InterlockedOr16_acq(short volatile * _Value, short _Mask))
(short _InterlockedOr16_nf(short volatile * _Value, short _Mask))
(short _InterlockedOr16_rel(short volatile * _Value, short _Mask))
__int64 _InterlockedOr64(__int64 volatile * _Value, __int64 _Mask);
(__int64 _InterlockedOr64_acq(__int64 volatile * _Value, __int64 _Mask))
(__int64 _InterlockedOr64_nf(__int64 volatile * _Value, __int64 _Mask))
(__int64 _InterlockedOr64_rel(__int64 volatile * _Value, __int64 _Mask))
char _InterlockedOr8(char volatile * _Value, char _Mask);
(char _InterlockedOr8_acq(char volatile * _Value, char _Mask))
(char _InterlockedOr8_nf(char volatile * _Value, char _Mask))
(char _InterlockedOr8_rel(char volatile * _Value, char _Mask))
(long _InterlockedOr_acq(long volatile * _Value, long _Mask))
(long _InterlockedOr_nf(long volatile * _Value, long _Mask))
(long _InterlockedOr_rel(long volatile * _Value, long _Mask))
long _InterlockedXor(long volatile * _Value, long _Mask);
short _InterlockedXor16(short volatile * _Value, short _Mask);
(short _InterlockedXor16_acq(short volatile * _Value, short _Mask))
(short _InterlockedXor16_nf(short volatile * _Value, short _Mask))
(short _InterlockedXor16_rel(short volatile * _Value, short _Mask))
__int64 _InterlockedXor64(__int64 volatile * _Value, __int64 _Mask);
(__int64 _InterlockedXor64_acq(__int64 volatile * _Value, __int64 _Mask))
(__int64 _InterlockedXor64_nf(__int64 volatile * _Value, __int64 _Mask))
(__int64 _InterlockedXor64_rel(__int64 volatile * _Value, __int64 _Mask))
char _InterlockedXor8(char volatile * _Value, char _Mask);
(char _InterlockedXor8_acq(char volatile * _Value, char _Mask))
(char _InterlockedXor8_nf(char volatile * _Value, char _Mask))
(char _InterlockedXor8_rel(char volatile * _Value, char _Mask))
(long _InterlockedXor_acq(long volatile * _Value, long _Mask))
(long _InterlockedXor_nf(long volatile * _Value, long _Mask))
(long _InterlockedXor_rel(long volatile * _Value, long _Mask))
void _ReadWriteBarrier(void);
__int16 __iso_volatile_load16(const volatile __int16 *);
__int32 __iso_volatile_load32(const volatile __int32 *);
__int64 __iso_volatile_load64(const volatile __int64 *);
__int8 __iso_volatile_load8(const volatile __int8 *);
void __iso_volatile_store16(volatile __int16 *, __int16);
void __iso_volatile_store32(volatile __int32 *, __int32);
void __iso_volatile_store64(volatile __int64 *, __int64);
void __iso_volatile_store8(volatile __int8 *, __int8);
(__int64 __ldrexd(const volatile __int64 *))
(void __yield(void))
unsigned char _interlockedbittestandset(long volatile *, long);
(unsigned char _interlockedbittestandset_acq(long volatile *, long))
(unsigned char _interlockedbittestandset_nf(long volatile *, long))
(unsigned char _interlockedbittestandset_rel(long volatile *, long))
unsigned int __lzcnt(unsigned int);
unsigned short __lzcnt16(unsigned short);
unsigned __int64 __lzcnt64(unsigned __int64);
unsigned int __popcnt(unsigned int);
unsigned short __popcnt16(unsigned short);
unsigned __int64 __popcnt64(unsigned __int64);
unsigned __int64 __shiftright128(unsigned __int64 _LowPart, unsigned __int64 _HighPart, unsigned char _Shift);
unsigned int _tzcnt_u32(unsigned int);
unsigned __int64 _tzcnt_u64(unsigned __int64);
unsigned __int64 _umul128(unsigned __int64 _Multiplier, unsigned __int64 _Multiplicand, unsigned __int64 * _HighProduct);
double __ceil(double);
float __ceilf(float);
double __floor(double);
float __floorf(float);
double __round(double);
float __roundf(float);
double __trunc(double);
float __truncf(float);
double __copysign(double, double);
float __copysignf(float, float);
unsigned __signbitvalue(double);
unsigned __signbitvaluef(float);
constexpr void * __cdecl __builtin_assume_aligned(const void *, size_t, ...) noexcept;

 

}
 
 

enum ISA_AVAILABILITY
{
    __ISA_AVAILABLE_X86   = 0,
    __ISA_AVAILABLE_SSE2  = 1,
    __ISA_AVAILABLE_SSE42 = 2,
    __ISA_AVAILABLE_AVX   = 3,
    __ISA_AVAILABLE_ENFSTRG = 4,
    __ISA_AVAILABLE_AVX2 = 5,
    __ISA_AVAILABLE_AVX512 = 6,

    __ISA_AVAILABLE_ARMNT   = 0,        __ISA_AVAILABLE_NEON    = 1,        __ISA_AVAILABLE_NEON_ARM64 = 2,                                     };


 
 


 
  
 
  
 
  
 
  

       
       


         extern "C" {



    namespace std
    {
        typedef decltype(__nullptr) nullptr_t;
    }

    using ::std::nullptr_t;




     int* __cdecl _errno(void);

     errno_t __cdecl _set_errno(  int _Value);
     errno_t __cdecl _get_errno(  int* _Value);





 extern unsigned long  __cdecl __threadid(void);
 extern uintptr_t __cdecl __threadhandle(void);



}                             

 
  
 
  



namespace std {
 template <class _Ty, _Ty _Val>
struct integral_constant {
    static constexpr _Ty value = _Val;

    using value_type = _Ty;
    using type       = integral_constant;

    constexpr operator value_type() const noexcept {
        return value;
    }

     constexpr value_type operator()() const noexcept {
        return value;
    }
};

 template <bool _Val>
using bool_constant = integral_constant<bool, _Val>;

using true_type  = bool_constant<true>;
using false_type = bool_constant<false>;

 template <bool _Test, class _Ty = void>
struct enable_if {};  
template <class _Ty>
struct enable_if<true, _Ty> {      using type = _Ty;
};

template <bool _Test, class _Ty = void>
using enable_if_t = typename enable_if<_Test, _Ty>::type;

 template <bool _Test, class _Ty1, class _Ty2>
struct conditional {      using type = _Ty1;
};

template <class _Ty1, class _Ty2>
struct conditional<false, _Ty1, _Ty2> {
    using type = _Ty2;
};

template <bool _Test, class _Ty1, class _Ty2>
using conditional_t = typename conditional<_Test, _Ty1, _Ty2>::type;

 template <class, class>
inline constexpr bool is_same_v = false;  template <class _Ty>
inline constexpr bool is_same_v<_Ty, _Ty> = true;

template <class _Ty1, class _Ty2>
struct is_same : bool_constant<is_same_v<_Ty1, _Ty2>> {};

 template <class _Ty>
struct remove_const {      using type = _Ty;
};

template <class _Ty>
struct remove_const<const _Ty> {
    using type = _Ty;
};

template <class _Ty>
using remove_const_t = typename remove_const<_Ty>::type;

 template <class _Ty>
struct remove_volatile {      using type = _Ty;
};

template <class _Ty>
struct remove_volatile<volatile _Ty> {
    using type = _Ty;
};

template <class _Ty>
using remove_volatile_t = typename remove_volatile<_Ty>::type;

 template <class _Ty>
struct remove_cv {      using type = _Ty;

    template <template <class> class _Fn>
    using _Apply = _Fn<_Ty>;  };

template <class _Ty>
struct remove_cv<const _Ty> {
    using type = _Ty;

    template <template <class> class _Fn>
    using _Apply = const _Fn<_Ty>;
};

template <class _Ty>
struct remove_cv<volatile _Ty> {
    using type = _Ty;

    template <template <class> class _Fn>
    using _Apply = volatile _Fn<_Ty>;
};

template <class _Ty>
struct remove_cv<const volatile _Ty> {
    using type = _Ty;

    template <template <class> class _Fn>
    using _Apply = const volatile _Fn<_Ty>;
};

template <class _Ty>
using remove_cv_t = typename remove_cv<_Ty>::type;

 template <bool _First_value, class _First, class... _Rest>
struct _Disjunction {      using type = _First;
};

template <class _False, class _Next, class... _Rest>
struct _Disjunction<false, _False, _Next, _Rest...> {      using type = typename _Disjunction<_Next::value, _Next, _Rest...>::type;
};

template <class... _Traits>
struct disjunction : false_type {};  
template <class _First, class... _Rest>
struct disjunction<_First, _Rest...> : _Disjunction<_First::value, _First, _Rest...>::type {
     };

template <class... _Traits>
inline constexpr bool disjunction_v = disjunction<_Traits...>::value;

 template <class _Ty, class... _Types>
inline constexpr bool _Is_any_of_v =      disjunction_v<is_same<_Ty, _Types>...>;

  constexpr bool is_constant_evaluated() noexcept {
    return __builtin_is_constant_evaluated();
}

 template <class _Ty>
inline constexpr bool is_integral_v = _Is_any_of_v<remove_cv_t<_Ty>, bool, char, signed char, unsigned char,
    wchar_t,
    char8_t,
    char16_t, char32_t, short, unsigned short, int, unsigned int, long, unsigned long, long long, unsigned long long>;

template <class _Ty>
struct is_integral : bool_constant<is_integral_v<_Ty>> {};

 template <class _Ty>
inline constexpr bool is_floating_point_v = _Is_any_of_v<remove_cv_t<_Ty>, float, double, long double>;

template <class _Ty>
struct is_floating_point : bool_constant<is_floating_point_v<_Ty>> {};

 template <class _Ty>
inline constexpr bool is_arithmetic_v =      is_integral_v<_Ty> || is_floating_point_v<_Ty>;

template <class _Ty>
struct is_arithmetic : bool_constant<is_arithmetic_v<_Ty>> {};

 template <class _Ty>
struct remove_reference {
    using type                 = _Ty;
    using _Const_thru_ref_type = const _Ty;
};

template <class _Ty>
struct remove_reference<_Ty&> {
    using type                 = _Ty;
    using _Const_thru_ref_type = const _Ty&;
};

template <class _Ty>
struct remove_reference<_Ty&&> {
    using type                 = _Ty;
    using _Const_thru_ref_type = const _Ty&&;
};

template <class _Ty>
using remove_reference_t = typename remove_reference<_Ty>::type;

 template <class _Ty>
using _Const_thru_ref = typename remove_reference<_Ty>::_Const_thru_ref_type;

template <class _Ty>
using _Remove_cvref_t = remove_cv_t<remove_reference_t<_Ty>>;

template <class _Ty>
using remove_cvref_t = _Remove_cvref_t<_Ty>;

template <class _Ty>
struct remove_cvref {
    using type = remove_cvref_t<_Ty>;
};

}




namespace std {
using :: ptrdiff_t;
using :: size_t;
using max_align_t = double;  
                             enum class byte : unsigned char {};

template <class _IntType, enable_if_t<is_integral_v<_IntType>, int> = 0>
 constexpr byte operator<<(
    const byte _Arg, const _IntType _Shift) noexcept {      return static_cast<byte>(static_cast<unsigned char>(static_cast<unsigned int>(_Arg) << _Shift));
}

template <class _IntType, enable_if_t<is_integral_v<_IntType>, int> = 0>
 constexpr byte operator>>(
    const byte _Arg, const _IntType _Shift) noexcept {      return static_cast<byte>(static_cast<unsigned char>(static_cast<unsigned int>(_Arg) >> _Shift));
}

 constexpr byte operator|(
    const byte _Left, const byte _Right) noexcept {      return static_cast<byte>(
        static_cast<unsigned char>(static_cast<unsigned int>(_Left) | static_cast<unsigned int>(_Right)));
}

 constexpr byte operator&(
    const byte _Left, const byte _Right) noexcept {      return static_cast<byte>(
        static_cast<unsigned char>(static_cast<unsigned int>(_Left) & static_cast<unsigned int>(_Right)));
}

 constexpr byte operator^(
    const byte _Left, const byte _Right) noexcept {      return static_cast<byte>(
        static_cast<unsigned char>(static_cast<unsigned int>(_Left) ^ static_cast<unsigned int>(_Right)));
}

 constexpr byte operator~(const byte _Arg) noexcept {      return static_cast<byte>(static_cast<unsigned char>(~static_cast<unsigned int>(_Arg)));
}

template <class _IntType, enable_if_t<is_integral_v<_IntType>, int> = 0>
constexpr byte& operator<<=(byte& _Arg, const _IntType _Shift) noexcept {      return _Arg = _Arg << _Shift;
}

template <class _IntType, enable_if_t<is_integral_v<_IntType>, int> = 0>
constexpr byte& operator>>=(byte& _Arg, const _IntType _Shift) noexcept {      return _Arg = _Arg >> _Shift;
}

constexpr byte& operator|=(byte& _Left, const byte _Right) noexcept {      return _Left = _Left | _Right;
}

constexpr byte& operator&=(byte& _Left, const byte _Right) noexcept {      return _Left = _Left & _Right;
}

constexpr byte& operator^=(byte& _Left, const byte _Right) noexcept {      return _Left = _Left ^ _Right;
}

template <class _IntType, enable_if_t<is_integral_v<_IntType>, int> = 0>
 constexpr _IntType to_integer(const byte _Arg) noexcept {      return static_cast<_IntType>(_Arg);
}

}

using ::std:: max_align_t;  


 
  
 
  

                 
       


         extern "C" {

              struct _exception
    {
        int    type;            char*  name;            double arg1;            double arg2;            double retval;      };

          
        struct _complex
        {
            double x, y;          };




        typedef float  float_t;
    typedef double double_t;



 
           extern double const _HUGE;







 






 
 
 


void __cdecl _fperrraise(  int _Except);

   short __cdecl _dclass(  double _X);
   short __cdecl _ldclass(  long double _X);
   short __cdecl _fdclass(  float _X);

   int __cdecl _dsign(  double _X);
   int __cdecl _ldsign(  long double _X);
   int __cdecl _fdsign(  float _X);

   int __cdecl _dpcomp(  double _X,   double _Y);
   int __cdecl _ldpcomp(  long double _X,   long double _Y);
   int __cdecl _fdpcomp(  float _X,   float _Y);

   short __cdecl _dtest(  double* _Px);
   short __cdecl _ldtest(  long double* _Px);
   short __cdecl _fdtest(  float* _Px);

 short __cdecl _d_int(  double* _Px,   short _Xexp);
 short __cdecl _ld_int(  long double* _Px,   short _Xexp);
 short __cdecl _fd_int(  float* _Px,   short _Xexp);

 short __cdecl _dscale(  double* _Px,   long _Lexp);
 short __cdecl _ldscale(  long double* _Px,   long _Lexp);
 short __cdecl _fdscale(  float* _Px,   long _Lexp);

 short __cdecl _dunscale(  short* _Pex,   double* _Px);
 short __cdecl _ldunscale(  short* _Pex,   long double* _Px);
 short __cdecl _fdunscale(  short* _Pex,   float* _Px);

   short __cdecl _dexp(  double* _Px,   double _Y,   long _Eoff);
   short __cdecl _ldexp(  long double* _Px,   long double _Y,   long _Eoff);
   short __cdecl _fdexp(  float* _Px,   float _Y,   long _Eoff);

   short __cdecl _dnorm(  unsigned short* _Ps);
   short __cdecl _fdnorm(  unsigned short* _Ps);

   double __cdecl _dpoly(  double _X,   double const* _Tab,   int _N);
   long double __cdecl _ldpoly(  long double _X,   long double const* _Tab,   int _N);
   float __cdecl _fdpoly(  float _X,   float const* _Tab,   int _N);

   double __cdecl _dlog(  double _X,   int _Baseflag);
   long double __cdecl _ldlog(  long double _X,   int _Baseflag);
   float __cdecl _fdlog(  float _X,   int _Baseflag);

   double __cdecl _dsin(  double _X,   unsigned int _Qoff);
   long double __cdecl _ldsin(  long double _X,   unsigned int _Qoff);
   float __cdecl _fdsin(  float _X,   unsigned int _Qoff);

 typedef union
{        unsigned short _Sh[4];
    double _Val;
} _double_val;

 typedef union
{        unsigned short _Sh[2];
    float _Val;
} _float_val;

 typedef union
{        unsigned short _Sh[4];
    long double _Val;
} _ldouble_val;

typedef union
{        unsigned short _Word[4];
    float _Float;
    double _Double;
    long double _Long_double;
} _float_const;

extern const _float_const _Denorm_C,  _Inf_C,  _Nan_C,  _Snan_C, _Hugeval_C;
extern const _float_const _FDenorm_C, _FInf_C, _FNan_C, _FSnan_C;
extern const _float_const _LDenorm_C, _LInf_C, _LNan_C, _LSnan_C;

extern const _float_const _Eps_C,  _Rteps_C;
extern const _float_const _FEps_C, _FRteps_C;
extern const _float_const _LEps_C, _LRteps_C;

extern const double      _Zero_C,  _Xbig_C;
extern const float       _FZero_C, _FXbig_C;
extern const long double _LZero_C, _LXbig_C;


extern "C++"
{
      inline int fpclassify(  float _X) throw()
    {
        return _fdtest(&_X);
    }

      inline int fpclassify(  double _X) throw()
    {
        return _dtest(&_X);
    }

      inline int fpclassify(  long double _X) throw()
    {
        return _ldtest(&_X);
    }

      inline bool signbit(  float _X) throw()
    {
        return _fdsign(_X) != 0;
    }

      inline bool signbit(  double _X) throw()
    {
        return _dsign(_X) != 0;
    }

      inline bool signbit(  long double _X) throw()
    {
        return _ldsign(_X) != 0;
    }

      inline int _fpcomp(  float _X,   float _Y) throw()
    {
        return _fdpcomp(_X, _Y);
    }

      inline int _fpcomp(  double _X,   double _Y) throw()
    {
        return _dpcomp(_X, _Y);
    }

      inline int _fpcomp(  long double _X,   long double _Y) throw()
    {
        return _ldpcomp(_X, _Y);
    }

    template <class _Trc, class _Tre> struct _Combined_type
    {            typedef float _Type;
    };

    template <> struct _Combined_type<float, double>
    {            typedef double _Type;
    };

    template <> struct _Combined_type<float, long double>
    {            typedef long double _Type;
    };

    template <class _Ty, class _T2> struct _Real_widened
    {            typedef long double _Type;
    };

    template <> struct _Real_widened<float, float>
    {            typedef float _Type;
    };

    template <> struct _Real_widened<float, double>
    {            typedef double _Type;
    };

    template <> struct _Real_widened<double, float>
    {            typedef double _Type;
    };

    template <> struct _Real_widened<double, double>
    {            typedef double _Type;
    };

    template <class _Ty> struct _Real_type
    {            typedef double _Type;        };

    template <> struct _Real_type<float>
    {            typedef float _Type;
    };

    template <> struct _Real_type<long double>
    {            typedef long double _Type;
    };

    template <class _T1, class _T2>
      inline int _fpcomp(  _T1 _X,   _T2 _Y) throw()
    {            typedef typename _Combined_type<float,
            typename _Real_widened<
            typename _Real_type<_T1>::_Type,
            typename _Real_type<_T2>::_Type>::_Type>::_Type _Tw;
        return _fpcomp((_Tw)_X, (_Tw)_Y);
    }

    template <class _Ty>
      inline bool isfinite(  _Ty _X) throw()
    {
        return fpclassify(_X) <= 0;
    }

    template <class _Ty>
      inline bool isinf(  _Ty _X) throw()
    {
        return fpclassify(_X) == 1;
    }

    template <class _Ty>
      inline bool isnan(  _Ty _X) throw()
    {
        return fpclassify(_X) == 2;
    }

    template <class _Ty>
      inline bool isnormal(  _Ty _X) throw()
    {
        return fpclassify(_X) == (-1);
    }

    template <class _Ty1, class _Ty2>
      inline bool isgreater(  _Ty1 _X,   _Ty2 _Y) throw()
    {
        return (_fpcomp(_X, _Y) & 4) != 0;
    }

    template <class _Ty1, class _Ty2>
      inline bool isgreaterequal(  _Ty1 _X,   _Ty2 _Y) throw()
    {
        return (_fpcomp(_X, _Y) & (2 | 4)) != 0;
    }

    template <class _Ty1, class _Ty2>
      inline bool isless(  _Ty1 _X,   _Ty2 _Y) throw()
    {
        return (_fpcomp(_X, _Y) & 1) != 0;
    }

    template <class _Ty1, class _Ty2>
      inline bool islessequal(  _Ty1 _X,   _Ty2 _Y) throw()
    {
        return (_fpcomp(_X, _Y) & (1 | 2)) != 0;
    }

    template <class _Ty1, class _Ty2>
      inline bool islessgreater(  _Ty1 _X,   _Ty2 _Y) throw()
    {
        return (_fpcomp(_X, _Y) & (1 | 4)) != 0;
    }

    template <class _Ty1, class _Ty2>
      inline bool isunordered(  _Ty1 _X,   _Ty2 _Y) throw()
    {
        return _fpcomp(_X, _Y) == 0;
    }
}   



      int       __cdecl abs(  int _X);
      long      __cdecl labs(  long _X);
      long long __cdecl llabs(  long long _X);

      double __cdecl acos(  double _X);
      double __cdecl asin(  double _X);
      double __cdecl atan(  double _X);
      double __cdecl atan2(  double _Y,   double _X);

      double __cdecl cos(  double _X);
      double __cdecl cosh(  double _X);
      double __cdecl exp(  double _X);
       double __cdecl fabs(  double _X);
      double __cdecl fmod(  double _X,   double _Y);
      double __cdecl log(  double _X);
      double __cdecl log10(  double _X);
      double __cdecl pow(  double _X,   double _Y);
      double __cdecl sin(  double _X);
      double __cdecl sinh(  double _X);
       double __cdecl sqrt(  double _X);
      double __cdecl tan(  double _X);
      double __cdecl tanh(  double _X);

       double    __cdecl acosh(  double _X);
       double    __cdecl asinh(  double _X);
       double    __cdecl atanh(  double _X);
        double    __cdecl atof(  char const* _String);
        double    __cdecl _atof_l(  char const* _String,   _locale_t _Locale);
       double    __cdecl _cabs(  struct _complex _Complex_value);
       double    __cdecl cbrt(  double _X);
       double    __cdecl ceil(  double _X);
       double    __cdecl _chgsign(  double _X);
       double    __cdecl copysign(  double _Number,   double _Sign);
       double    __cdecl _copysign(  double _Number,   double _Sign);
       double    __cdecl erf(  double _X);
       double    __cdecl erfc(  double _X);
       double    __cdecl exp2(  double _X);
       double    __cdecl expm1(  double _X);
       double    __cdecl fdim(  double _X,   double _Y);
       double    __cdecl floor(  double _X);
       double    __cdecl fma(  double _X,   double _Y,   double _Z);
       double    __cdecl fmax(  double _X,   double _Y);
       double    __cdecl fmin(  double _X,   double _Y);
       double    __cdecl frexp(  double _X,   int* _Y);
       double    __cdecl hypot(  double _X,   double _Y);
       double    __cdecl _hypot(  double _X,   double _Y);
       int       __cdecl ilogb(  double _X);
       double    __cdecl ldexp(  double _X,   int _Y);
       double    __cdecl lgamma(  double _X);
       long long __cdecl llrint(  double _X);
       long long __cdecl llround(  double _X);
       double    __cdecl log1p(  double _X);
       double    __cdecl log2(  double _X);
       double    __cdecl logb(  double _X);
       long      __cdecl lrint(  double _X);
       long      __cdecl lround(  double _X);

    int __cdecl _matherr(  struct _exception* _Except);

       double __cdecl modf(  double _X,   double* _Y);
       double __cdecl nan(  char const* _X);
       double __cdecl nearbyint(  double _X);
       double __cdecl nextafter(  double _X,   double _Y);
       double __cdecl nexttoward(  double _X,   long double _Y);
       double __cdecl remainder(  double _X,   double _Y);
       double __cdecl remquo(  double _X,   double _Y,   int* _Z);
       double __cdecl rint(  double _X);
       double __cdecl round(  double _X);
       double __cdecl scalbln(  double _X,   long _Y);
       double __cdecl scalbn(  double _X,   int _Y);
       double __cdecl tgamma(  double _X);
       double __cdecl trunc(  double _X);
       double __cdecl _j0(  double _X );
       double __cdecl _j1(  double _X );
       double __cdecl _jn(int _X,   double _Y);
       double __cdecl _y0(  double _X);
       double __cdecl _y1(  double _X);
       double __cdecl _yn(  int _X,   double _Y);

       float     __cdecl acoshf(  float _X);
       float     __cdecl asinhf(  float _X);
       float     __cdecl atanhf(  float _X);
       float     __cdecl cbrtf(  float _X);
       float     __cdecl _chgsignf(  float _X);
       float     __cdecl copysignf(  float _Number,   float _Sign);
       float     __cdecl _copysignf(  float _Number,   float _Sign);
       float     __cdecl erff(  float _X);
       float     __cdecl erfcf(  float _X);
       float     __cdecl expm1f(  float _X);
       float     __cdecl exp2f(  float _X);
       float     __cdecl fdimf(  float _X,   float _Y);
       float     __cdecl fmaf(  float _X,   float _Y,   float _Z);
       float     __cdecl fmaxf(  float _X,   float _Y);
       float     __cdecl fminf(  float _X,   float _Y);
       float     __cdecl _hypotf(  float _X,   float _Y);
       int       __cdecl ilogbf(  float _X);
       float     __cdecl lgammaf(  float _X);
       long long __cdecl llrintf(  float _X);
       long long __cdecl llroundf(  float _X);
       float     __cdecl log1pf(  float _X);
       float     __cdecl log2f(  float _X);
       float     __cdecl logbf(  float _X);
       long      __cdecl lrintf(  float _X);
       long      __cdecl lroundf(  float _X);
       float     __cdecl nanf(  char const* _X);
       float     __cdecl nearbyintf(  float _X);
       float     __cdecl nextafterf(  float _X,   float _Y);
       float     __cdecl nexttowardf(  float _X,   long double _Y);
       float     __cdecl remainderf(  float _X,   float _Y);
       float     __cdecl remquof(  float _X,   float _Y,   int* _Z);
       float     __cdecl rintf(  float _X);
       float     __cdecl roundf(  float _X);
       float     __cdecl scalblnf(  float _X,   long _Y);
       float     __cdecl scalbnf(  float _X,   int _Y);
       float     __cdecl tgammaf(  float _X);
       float     __cdecl truncf(  float _X);



           float __cdecl _logbf(  float _X);
           float __cdecl _nextafterf(  float _X,   float _Y);
           int   __cdecl _finitef(  float _X);
           int   __cdecl _isnanf(  float _X);
           int   __cdecl _fpclassf(  float _X);

           int   __cdecl _set_FMA3_enable(  int _Flag);
           int   __cdecl _get_FMA3_enable(void);





           float __cdecl acosf(  float _X);
           float __cdecl asinf(  float _X);
           float __cdecl atan2f(  float _Y,   float _X);
           float __cdecl atanf(  float _X);
           float __cdecl ceilf(  float _X);
           float __cdecl cosf(  float _X);
           float __cdecl coshf(  float _X);
           float __cdecl expf(  float _X);



          __inline float __cdecl fabsf(  float _X)
        {
            return (float)fabs(_X);
        }



           float __cdecl floorf(  float _X);
           float __cdecl fmodf(  float _X,   float _Y);


      __inline float __cdecl frexpf(  float _X,   int *_Y)
    {
        return (float)frexp(_X, _Y);
    }

      __inline float __cdecl hypotf(  float _X,   float _Y)
    {
        return _hypotf(_X, _Y);
    }

      __inline float __cdecl ldexpf(  float _X,   int _Y)
    {
        return (float)ldexp(_X, _Y);
    }


           float  __cdecl log10f(  float _X);
           float  __cdecl logf(  float _X);
           float  __cdecl modff(  float _X,   float *_Y);
           float  __cdecl powf(  float _X,   float _Y);
           float  __cdecl sinf(  float _X);
           float  __cdecl sinhf(  float _X);
           float  __cdecl sqrtf(  float _X);
           float  __cdecl tanf(  float _X);
           float  __cdecl tanhf(  float _X);


       long double __cdecl acoshl(  long double _X);

      __inline long double __cdecl acosl(  long double _X)
    {
        return acos((double)_X);
    }

       long double __cdecl asinhl(  long double _X);

      __inline long double __cdecl asinl(  long double _X)
    {
        return asin((double)_X);
    }

      __inline long double __cdecl atan2l(  long double _Y,   long double _X)
    {
        return atan2((double)_Y, (double)_X);
    }

       long double __cdecl atanhl(  long double _X);

      __inline long double __cdecl atanl(  long double _X)
    {
        return atan((double)_X);
    }

       long double __cdecl cbrtl(  long double _X);

      __inline long double __cdecl ceill(  long double _X)
    {
        return ceil((double)_X);
    }

      __inline long double __cdecl _chgsignl(  long double _X)
    {
        return _chgsign((double)_X);
    }

       long double __cdecl copysignl(  long double _Number,   long double _Sign);

      __inline long double __cdecl _copysignl(  long double _Number,   long double _Sign)
    {
        return _copysign((double)_Number, (double)_Sign);
    }

      __inline long double __cdecl coshl(  long double _X)
    {
        return cosh((double)_X);
    }

      __inline long double __cdecl cosl(  long double _X)
    {
        return cos((double)_X);
    }

       long double __cdecl erfl(  long double _X);
       long double __cdecl erfcl(  long double _X);

      __inline long double __cdecl expl(  long double _X)
    {
        return exp((double)_X);
    }

       long double __cdecl exp2l(  long double _X);
       long double __cdecl expm1l(  long double _X);

      __inline long double __cdecl fabsl(  long double _X)
    {
        return fabs((double)_X);
    }

       long double __cdecl fdiml(  long double _X,   long double _Y);

      __inline long double __cdecl floorl(  long double _X)
    {
        return floor((double)_X);
    }

       long double __cdecl fmal(  long double _X,   long double _Y,   long double _Z);
       long double __cdecl fmaxl(  long double _X,   long double _Y);
       long double __cdecl fminl(  long double _X,   long double _Y);

      __inline long double __cdecl fmodl(  long double _X,   long double _Y)
    {
        return fmod((double)_X, (double)_Y);
    }

      __inline long double __cdecl frexpl(  long double _X,   int *_Y)
    {
        return frexp((double)_X, _Y);
    }

       int __cdecl ilogbl(  long double _X);

      __inline long double __cdecl _hypotl(  long double _X,   long double _Y)
    {
        return _hypot((double)_X, (double)_Y);
    }

      __inline long double __cdecl hypotl(  long double _X,   long double _Y)
    {
        return _hypot((double)_X, (double)_Y);
    }

      __inline long double __cdecl ldexpl(  long double _X,   int _Y)
    {
        return ldexp((double)_X, _Y);
    }

       long double __cdecl lgammal(  long double _X);
       long long __cdecl llrintl(  long double _X);
       long long __cdecl llroundl(  long double _X);

      __inline long double __cdecl logl(  long double _X)
    {
        return log((double)_X);
    }

      __inline long double __cdecl log10l(  long double _X)
    {
        return log10((double)_X);
    }

       long double __cdecl log1pl(  long double _X);
       long double __cdecl log2l(  long double _X);
       long double __cdecl logbl(  long double _X);
       long __cdecl lrintl(  long double _X);
       long __cdecl lroundl(  long double _X);

      __inline long double __cdecl modfl(  long double _X,   long double* _Y)
    {
        double _F, _I;
        _F = modf((double)_X, &_I);
        *_Y = _I;
        return _F;
    }

       long double __cdecl nanl(  char const* _X);
       long double __cdecl nearbyintl(  long double _X);
       long double __cdecl nextafterl(  long double _X,   long double _Y);
       long double __cdecl nexttowardl(  long double _X,   long double _Y);

      __inline long double __cdecl powl(  long double _X,   long double _Y)
    {
        return pow((double)_X, (double)_Y);
    }

       long double __cdecl remainderl(  long double _X,   long double _Y);
       long double __cdecl remquol(  long double _X,   long double _Y,   int* _Z);
       long double __cdecl rintl(  long double _X);
       long double __cdecl roundl(  long double _X);
       long double __cdecl scalblnl(  long double _X,   long _Y);
       long double __cdecl scalbnl(  long double _X,   int _Y);

      __inline long double __cdecl sinhl(  long double _X)
    {
        return sinh((double)_X);
    }

      __inline long double __cdecl sinl(  long double _X)
    {
        return sin((double)_X);
    }

      __inline long double __cdecl sqrtl(  long double _X)
    {
        return sqrt((double)_X);
    }

      __inline long double __cdecl tanhl(  long double _X)
    {
        return tanh((double)_X);
    }

      __inline long double __cdecl tanl(  long double _X)
    {
        return tan((double)_X);
    }

       long double __cdecl tgammal(  long double _X);
       long double __cdecl truncl(  long double _X);






            extern double HUGE;

        __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _j0. See online help for details."))    double __cdecl j0(  double _X);
        __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _j1. See online help for details."))    double __cdecl j1(  double _X);
        __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _jn. See online help for details."))    double __cdecl jn(  int _X,   double _Y);
        __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _y0. See online help for details."))    double __cdecl y0(  double _X);
        __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _y1. See online help for details."))    double __cdecl y1(  double _X);
        __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _yn. See online help for details."))    double __cdecl yn(  int _X,   double _Y);


}                             


       
               
       


         extern "C" {




     
 __declspec(allocator) __declspec(restrict)
void* __cdecl _calloc_base(
      size_t _Count,
      size_t _Size
    );

     
  __declspec(allocator) __declspec(restrict) 
void* __cdecl calloc(
       size_t _Count,
       size_t _Size
    );

 
 int __cdecl _callnewh(
      size_t _Size
    );

     
 __declspec(allocator) 
void* __cdecl _expand(
                void*  _Block,
       size_t _Size
    );


void __cdecl _free_base(
        void* _Block
    );

 
void __cdecl free(
        void* _Block
    );

     
 __declspec(allocator) __declspec(restrict)
void* __cdecl _malloc_base(
      size_t _Size
    );

     
 __declspec(allocator)  __declspec(restrict) 
void* __cdecl malloc(
       size_t _Size
    );

 

size_t __cdecl _msize_base(
      void* _Block
    );

 
 
size_t __cdecl _msize(
      void* _Block
    );

       
 __declspec(allocator) __declspec(restrict)
void* __cdecl _realloc_base(
         void*  _Block,
                                 size_t _Size
    );

       
 __declspec(allocator) __declspec(restrict) 
void* __cdecl realloc(
        void*  _Block,
              size_t _Size
    );

       
 __declspec(allocator) __declspec(restrict)
void* __cdecl _recalloc_base(
        void*  _Block,
                                size_t _Count,
                                size_t _Size
    );

       
 __declspec(allocator) __declspec(restrict)
void* __cdecl _recalloc(
        void*  _Block,
              size_t _Count,
              size_t _Size
    );


void __cdecl _aligned_free(
        void* _Block
    );

     
 __declspec(allocator) __declspec(restrict)
void* __cdecl _aligned_malloc(
       size_t _Size,
                         size_t _Alignment
    );

     
 __declspec(allocator) __declspec(restrict)
void* __cdecl _aligned_offset_malloc(
       size_t _Size,
                         size_t _Alignment,
                         size_t _Offset
    );

 

size_t __cdecl _aligned_msize(
      void*  _Block,
               size_t _Alignment,
               size_t _Offset
    );

       
 __declspec(allocator) __declspec(restrict)
void* __cdecl _aligned_offset_realloc(
        void*  _Block,
              size_t _Size,
                                size_t _Alignment,
                                size_t _Offset
    );

       
 __declspec(allocator) __declspec(restrict)
void* __cdecl _aligned_offset_recalloc(
        void*  _Block,
              size_t _Count,
              size_t _Size,
                                size_t _Alignment,
                                size_t _Offset
    );

       
 __declspec(allocator) __declspec(restrict)
void* __cdecl _aligned_realloc(
        void*  _Block,
              size_t _Size,
                                size_t _Alignment
    );

       
 __declspec(allocator) __declspec(restrict)
void* __cdecl _aligned_recalloc(
        void*  _Block,
              size_t _Count,
              size_t _Size,
                                size_t _Alignment
    );




}                             

          
              


         extern "C" {


    typedef int (__cdecl* _CoreCrtSecureSearchSortCompareFunction)(void*, void const*, void const*);
    typedef int (__cdecl* _CoreCrtNonSecureSearchSortCompareFunction)(void const*, void const*);



     
     void* __cdecl bsearch_s(
                                                        void const* _Key,
          void const* _Base,
                                                        rsize_t     _NumOfElements,
                                                        rsize_t     _SizeOfElements,
                            _CoreCrtSecureSearchSortCompareFunction _CompareFunction,
                                                    void*       _Context
        );

     void __cdecl qsort_s(
          void*   _Base,
                                                             rsize_t _NumOfElements,
                                                             rsize_t _SizeOfElements,
                             _CoreCrtSecureSearchSortCompareFunction _CompareFunction,
                                                         void*   _Context
        );




 
 void* __cdecl bsearch(
                                                    void const* _Key,
      void const* _Base,
                                                    size_t      _NumOfElements,
                                                    size_t      _SizeOfElements,
                     _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
    );

 void __cdecl qsort(
      void*  _Base,
                                                         size_t _NumOfElements,
                                                         size_t _SizeOfElements,
                     _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
    );

 
 void* __cdecl _lfind_s(
                                                       void const*   _Key,
      void const*   _Base,
                                                    unsigned int* _NumOfElements,
                                                       size_t        _SizeOfElements,
                             _CoreCrtSecureSearchSortCompareFunction _CompareFunction,
                                                       void*         _Context
    );

 
 void* __cdecl _lfind(
                                                       void const*   _Key,
      void const*   _Base,
                                                    unsigned int* _NumOfElements,
                                                       unsigned int  _SizeOfElements,
                          _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
    );

 
 void* __cdecl _lsearch_s(
                                                             void const*   _Key,
      void*         _Base,
                                                          unsigned int* _NumOfElements,
                                                             size_t        _SizeOfElements,
                                   _CoreCrtSecureSearchSortCompareFunction _CompareFunction,
                                                             void*         _Context
    );

 
 void* __cdecl _lsearch(
                                                             void const*   _Key,
      void*         _Base,
                                                          unsigned int* _NumOfElements,
                                                             unsigned int  _SizeOfElements,
                                _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
    );



 



      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _lfind. See online help for details."))
     void* __cdecl lfind(
                                                           void const*   _Key,
          void const*   _Base,
                                                        unsigned int* _NumOfElements,
                                                           unsigned int  _SizeOfElements,
                              _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
        );

      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _lsearch. See online help for details."))
     void* __cdecl lsearch(
                                                                void const*   _Key,
          void*         _Base,
                                                             unsigned int* _NumOfElements,
                                                                unsigned int  _SizeOfElements,
                                   _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
        );




}                             

               


         extern "C" {






 


 void __cdecl _swab(
        char* _Buf1,
        char* _Buf2,
                                                                  int   _SizeInBytes
    );



      
     __declspec(noreturn) void __cdecl exit(  int _Code);
     __declspec(noreturn) void __cdecl _exit(  int _Code);
     __declspec(noreturn) void __cdecl _Exit(  int _Code);
     __declspec(noreturn) void __cdecl quick_exit(  int _Code);
     __declspec(noreturn) void __cdecl abort(void);

 
 unsigned int __cdecl _set_abort_behavior(
      unsigned int _Flags,
      unsigned int _Mask
    );




    typedef int (__cdecl* _onexit_t)(void);

     





    int       __cdecl atexit(void (__cdecl*)(void));
    _onexit_t __cdecl _onexit(  _onexit_t _Func);

int __cdecl at_quick_exit(void (__cdecl*)(void));



              typedef void (__cdecl* _purecall_handler)(void);

         typedef void (__cdecl* _invalid_parameter_handler)(
        wchar_t const*,
        wchar_t const*,
        wchar_t const*,
        unsigned int,
        uintptr_t
        );

          _purecall_handler __cdecl _set_purecall_handler(
          _purecall_handler _Handler
        );

     _purecall_handler __cdecl _get_purecall_handler(void);

          _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(
          _invalid_parameter_handler _Handler
        );

     _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(void);

     _invalid_parameter_handler __cdecl _set_thread_local_invalid_parameter_handler(
          _invalid_parameter_handler _Handler
        );

     _invalid_parameter_handler __cdecl _get_thread_local_invalid_parameter_handler(void);





 
  int __cdecl _set_error_mode(  int _Mode);



     int* __cdecl _errno(void);

     errno_t __cdecl _set_errno(  int _Value);
     errno_t __cdecl _get_errno(  int* _Value);

     unsigned long* __cdecl __doserrno(void);

     errno_t __cdecl _set_doserrno(  unsigned long _Value);
     errno_t __cdecl _get_doserrno(  unsigned long * _Value);

          __declspec(deprecated("This function or variable may be unsafe. Consider using strerror instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) char** __cdecl __sys_errlist(void);

     __declspec(deprecated("This function or variable may be unsafe. Consider using strerror instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.")) int * __cdecl __sys_nerr(void);

     void __cdecl perror(  char const* _ErrMsg);



 __declspec(deprecated("This function or variable may be unsafe. Consider using replacement instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char**    __cdecl __p__pgmptr (void);
__declspec(deprecated("This function or variable may be unsafe. Consider using replacement instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t** __cdecl __p__wpgmptr(void);
__declspec(deprecated("This function or variable may be unsafe. Consider using replacement instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int*      __cdecl __p__fmode  (void);


 
 errno_t __cdecl _get_pgmptr (  char**    _Value);

 
 errno_t __cdecl _get_wpgmptr(  wchar_t** _Value);

 errno_t __cdecl _set_fmode  (               int       _Mode );

 errno_t __cdecl _get_fmode  (              int*      _PMode);



     typedef struct _div_t
{
    int quot;
    int rem;
} div_t;

typedef struct _ldiv_t
{
    long quot;
    long rem;
} ldiv_t;

typedef struct _lldiv_t
{
    long long quot;
    long long rem;
} lldiv_t;

  int       __cdecl abs   (  int       _Number);
  long      __cdecl labs  (  long      _Number);
  long long __cdecl llabs (  long long _Number);
  __int64   __cdecl _abs64(  __int64   _Number);

  unsigned short   __cdecl _byteswap_ushort(  unsigned short   _Number);
  unsigned long    __cdecl _byteswap_ulong (  unsigned long    _Number);
  unsigned __int64 __cdecl _byteswap_uint64(  unsigned __int64 _Number);

   div_t   __cdecl div  (  int       _Numerator,   int       _Denominator);
   ldiv_t  __cdecl ldiv (  long      _Numerator,   long      _Denominator);
   lldiv_t __cdecl lldiv(  long long _Numerator,   long long _Denominator);

  
unsigned int __cdecl _rotl(
      unsigned int _Value,
      int          _Shift
    );

 
unsigned long __cdecl _lrotl(
      unsigned long _Value,
      int           _Shift
    );

unsigned __int64 __cdecl _rotl64(
      unsigned __int64 _Value,
      int              _Shift
    );

unsigned int __cdecl _rotr(
      unsigned int _Value,
      int          _Shift
    );

 
unsigned long __cdecl _lrotr(
      unsigned long _Value,
      int           _Shift
    );

unsigned __int64 __cdecl _rotr64(
      unsigned __int64 _Value,
      int              _Shift
    );




 
 void __cdecl srand(  unsigned int _Seed);

   int __cdecl rand(void);




extern "C++"
{
    inline long abs(long const _X) throw()
    {
        return labs(_X);
    }

    inline long long abs(long long const _X) throw()
    {
        return llabs(_X);
    }

    inline ldiv_t div(long const _A1, long const _A2) throw()
    {
        return ldiv(_A1, _A2);
    }

    inline lldiv_t div(long long const _A1, long long const _A2) throw()
    {
        return lldiv(_A1, _A2);
    }
}




  

    typedef struct
    {
        unsigned char ld[10];
    } _LDOUBLE;



typedef struct
{
    double x;
} _CRT_DOUBLE;

typedef struct
{
    float f;
} _CRT_FLOAT;

 
typedef struct
{
    long double x;
} _LONGDOUBLE;


typedef struct
{
    unsigned char ld12[12];
} _LDBL12;



                           double    __cdecl atof   (  char const* _String);
    int       __cdecl atoi   (  char const* _String);
                      long      __cdecl atol   (  char const* _String);
                      long long __cdecl atoll  (  char const* _String);
                      __int64   __cdecl _atoi64(  char const* _String);

   double    __cdecl _atof_l  (  char const* _String,   _locale_t _Locale);
   int       __cdecl _atoi_l  (  char const* _String,   _locale_t _Locale);
   long      __cdecl _atol_l  (  char const* _String,   _locale_t _Locale);
   long long __cdecl _atoll_l (  char const* _String,   _locale_t _Locale);
   __int64   __cdecl _atoi64_l(  char const* _String,   _locale_t _Locale);

   int __cdecl _atoflt (  _CRT_FLOAT*  _Result,   char const* _String);
   int __cdecl _atodbl (  _CRT_DOUBLE* _Result,   char*       _String);
   int __cdecl _atoldbl(  _LDOUBLE*    _Result,   char*       _String);

 
 int __cdecl _atoflt_l(
         _CRT_FLOAT* _Result,
        char const* _String,
      _locale_t   _Locale
    );

 
 int __cdecl _atodbl_l(
         _CRT_DOUBLE* _Result,
        char*        _String,
      _locale_t    _Locale
    );


 
 int __cdecl _atoldbl_l(
         _LDOUBLE* _Result,
        char*     _String,
      _locale_t _Locale
    );

 
 float __cdecl strtof(
                        char const* _String,
        char**      _EndPtr
    );

 
 float __cdecl _strtof_l(
                        char const* _String,
        char**      _EndPtr,
                      _locale_t   _Locale
    );

 
 double __cdecl strtod(
                        char const* _String,
        char**      _EndPtr
    );

 
 double __cdecl _strtod_l(
                        char const* _String,
        char**      _EndPtr,
                      _locale_t   _Locale
    );

 
 long double __cdecl strtold(
                        char const* _String,
        char**      _EndPtr
    );

 
 long double __cdecl _strtold_l(
                        char const* _String,
        char**      _EndPtr,
                      _locale_t   _Locale
    );

 
 long __cdecl strtol(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix
    );

 
 long __cdecl _strtol_l(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix,
                      _locale_t   _Locale
    );

 
 long long __cdecl strtoll(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix
    );

 
 long long __cdecl _strtoll_l(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix,
                      _locale_t   _Locale
    );

 
 unsigned long __cdecl strtoul(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix
    );

 
 unsigned long __cdecl _strtoul_l(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix,
                      _locale_t   _Locale
    );

 
 unsigned long long __cdecl strtoull(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix
    );

 
 unsigned long long __cdecl _strtoull_l(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix,
                      _locale_t   _Locale
    );

 
 __int64 __cdecl _strtoi64(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix
    );

 
 __int64 __cdecl _strtoi64_l(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix,
                      _locale_t   _Locale
    );

 
 unsigned __int64 __cdecl _strtoui64(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix
    );

 
 unsigned __int64 __cdecl _strtoui64_l(
                        char const* _String,
        char**      _EndPtr,
                          int         _Radix,
                      _locale_t   _Locale
    );



      

 errno_t __cdecl _itoa_s(
                              int    _Value,
      char*  _Buffer,
                              size_t _BufferCount,
                              int    _Radix
    );

extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                                errno_t __cdecl _itoa_s(  int _Value, char (&_Buffer)[_Size],   int _Radix) throw()                 {                                                                                                                                    return _itoa_s(_Value, _Buffer, _Size, _Radix);                                                                               }                                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _itoa(                     int _Value,     char *_Buffer,                      int _Radix);

 

 errno_t __cdecl _ltoa_s(
                              long   _Value,
      char*  _Buffer,
                              size_t _BufferCount,
                              int    _Radix
    );

extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl _ltoa_s(  long _Value, char (&_Buffer)[_Size],   int _Radix) throw()                 {                                                                                                                                    return _ltoa_s(_Value, _Buffer, _Size, _Radix);                                                                               }                                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _ltoa(                     long _Value,     char *_Buffer,                      int _Radix);

 

 errno_t __cdecl _ultoa_s(
                              unsigned long _Value,
      char*         _Buffer,
                              size_t        _BufferCount,
                              int           _Radix
    );

extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl _ultoa_s(  unsigned long _Value, char (&_Buffer)[_Size],   int _Radix) throw()                 {                                                                                                                                    return _ultoa_s(_Value, _Buffer, _Size, _Radix);                                                                               }                                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _ultoa(                     unsigned long _Value,     char *_Buffer,                      int _Radix);

 

 errno_t __cdecl _i64toa_s(
                              __int64 _Value,
      char*   _Buffer,
                              size_t  _BufferCount,
                              int     _Radix
    );

 
__declspec(deprecated("This function or variable may be unsafe. Consider using _i64toa_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 char* __cdecl _i64toa(
                        __int64 _Value,
        char*   _Buffer,
                        int     _Radix
    );

 

 errno_t __cdecl _ui64toa_s(
                              unsigned __int64 _Value,
      char*            _Buffer,
                              size_t           _BufferCount,
                              int              _Radix
    );

__declspec(deprecated("This function or variable may be unsafe. Consider using _ui64toa_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 char* __cdecl _ui64toa(
                        unsigned __int64 _Value,
        char*            _Buffer,
                        int              _Radix
    );



        
 

 errno_t __cdecl _ecvt_s(
      char* _Buffer,
       size_t                       _BufferCount,
       double                       _Value,
       int                          _DigitCount,
      int*                         _PtDec,
      int*                         _PtSign
    );

extern "C++"                                                                                                                                                      {                                                                                                                                                                     template <size_t _Size>                                                                                                                                           inline                                                                                                                                                            errno_t __cdecl _ecvt_s(char (&_Buffer)[_Size],    double _Value,    int _DigitCount,   int* _PtDec,   int* _PtSign) throw()                  {                                                                                                                                                                     return _ecvt_s(_Buffer, _Size, _Value, _DigitCount, _PtDec, _PtSign);                                                                                                }                                                                                                                                                             }

  __declspec(deprecated("This function or variable may be unsafe. Consider using _ecvt_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 char* __cdecl _ecvt(
       double _Value,
       int    _DigitCount,
      int*   _PtDec,
      int*   _PtSign
    );

 

 errno_t __cdecl _fcvt_s(
      char*  _Buffer,
                              size_t _BufferCount,
                              double _Value,
                              int    _FractionalDigitCount,
                             int*   _PtDec,
                             int*   _PtSign
    );

extern "C++"                                                                                                                                                      {                                                                                                                                                                     template <size_t _Size>                                                                                                                                           inline                                                                                                                                                                 errno_t __cdecl _fcvt_s(char (&_Buffer)[_Size],    double _Value,    int _FractionalDigitCount,   int* _PtDec,   int* _PtSign) throw()                  {                                                                                                                                                                     return _fcvt_s(_Buffer, _Size, _Value, _FractionalDigitCount, _PtDec, _PtSign);                                                                                                }                                                                                                                                                             }

 
  __declspec(deprecated("This function or variable may be unsafe. Consider using _fcvt_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 char* __cdecl _fcvt(
       double _Value,
       int    _FractionalDigitCount,
      int*   _PtDec,
      int*   _PtSign
    );

 
 errno_t __cdecl _gcvt_s(
      char*  _Buffer,
                              size_t _BufferCount,
                              double _Value,
                              int    _DigitCount
    );

extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                                errno_t __cdecl _gcvt_s(char (&_Buffer)[_Size],   double _Value,   int _DigitCount) throw()                 {                                                                                                                                    return _gcvt_s(_Buffer, _Size, _Value, _DigitCount);                                                                               }                                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _gcvt_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 char* __cdecl _gcvt(
                        double _Value,
                        int    _DigitCount,
        char*  _Buffer
    );



       

     
     int __cdecl ___mb_cur_max_func(void);

     
     int __cdecl ___mb_cur_max_l_func(_locale_t _Locale);



 
 int __cdecl mblen(
        char const* _Ch,
                                             size_t      _MaxCount
    );

 
 int __cdecl _mblen_l(
        char const* _Ch,
                                             size_t      _MaxCount,
                                         _locale_t   _Locale
    );

 
 
 size_t __cdecl _mbstrlen(
      char const* _String
    );

 
 
 size_t __cdecl _mbstrlen_l(
        char const* _String,
      _locale_t   _Locale
    );

 
 
 size_t __cdecl _mbstrnlen(
      char const* _String,
        size_t      _MaxCount
    );

 
 
 size_t __cdecl _mbstrnlen_l(
        char const* _String,
          size_t      _MaxCount,
      _locale_t   _Locale
    );

 
 int __cdecl mbtowc(
                      wchar_t*    _DstCh,
      char const* _SrcCh,
                                      size_t      _SrcSizeInBytes
    );

 
 int __cdecl _mbtowc_l(
                      wchar_t*    _DstCh,
      char const* _SrcCh,
                                      size_t      _SrcSizeInBytes,
                                  _locale_t   _Locale
    );


 errno_t __cdecl mbstowcs_s(
                                                      size_t*     _PtNumOfCharConverted,
      wchar_t*    _DstBuf,
                                                           size_t      _SizeInWords,
                                     char const* _SrcBuf,
                                                           size_t      _MaxCount
    );

extern "C++"                                                                                                                                     {                                                                                                                                                    template <size_t _Size>                                                                                                                          inline                                                                                                                                           errno_t __cdecl mbstowcs_s(  size_t* _PtNumOfCharConverted,    wchar_t (&_Dest)[_Size],      char const* _Source,        size_t _MaxCount) throw()                 {                                                                                                                                                    return mbstowcs_s(_PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount);                                                                                       }                                                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  size_t __cdecl mbstowcs(  wchar_t *_Dest,                           char const* _Source,                             size_t _MaxCount);


 errno_t __cdecl _mbstowcs_s_l(
                                                      size_t*     _PtNumOfCharConverted,
      wchar_t*    _DstBuf,
                                                           size_t      _SizeInWords,
                                     char const* _SrcBuf,
                                                           size_t      _MaxCount,
                                                       _locale_t   _Locale
    );

extern "C++"                                                                                                                                                      {                                                                                                                                                                     template <size_t _Size>                                                                                                                                           inline                                                                                                                                                            errno_t __cdecl _mbstowcs_s_l(  size_t* _PtNumOfCharConverted,    wchar_t (&_Dest)[_Size],      char const* _Source,        size_t _MaxCount,    _locale_t _Locale) throw()                  {                                                                                                                                                                     return _mbstowcs_s_l(_PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount, _Locale);                                                                                                }                                                                                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  size_t __cdecl _mbstowcs_l(  wchar_t *_Dest,                       char const* _Source,                         size_t _MaxCount,                     _locale_t _Locale);




__declspec(deprecated("This function or variable may be unsafe. Consider using wctomb_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 int __cdecl wctomb(
      char*   _MbCh,
                                wchar_t _WCh
    );

__declspec(deprecated("This function or variable may be unsafe. Consider using _wctomb_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 int __cdecl _wctomb_l(
        char*     _MbCh,
                          wchar_t   _WCh,
                      _locale_t _Locale
    );


    
     errno_t __cdecl wctomb_s(
                                                         int*    _SizeConverted,
          char*   _MbCh,
                                                              rsize_t _SizeInBytes,
                                                              wchar_t _WCh
        );



 errno_t __cdecl _wctomb_s_l(
                             int*     _SizeConverted,
      char*     _MbCh,
                                  size_t    _SizeInBytes,
                                  wchar_t   _WCh,
                              _locale_t _Locale);


 errno_t __cdecl wcstombs_s(
                                                               size_t*        _PtNumOfCharConverted,
      char*          _Dst,
                                                                    size_t         _DstSizeInBytes,
                                                                  wchar_t const* _Src,
                                                                    size_t         _MaxCountInBytes
    );

extern "C++"                                                                                                                                     {                                                                                                                                                    template <size_t _Size>                                                                                                                          inline                                                                                                                                           errno_t __cdecl wcstombs_s(                      size_t* _PtNumOfCharConverted,   char (&_Dest)[_Size],                          wchar_t const* _Source,                            size_t _MaxCount) throw()                 {                                                                                                                                                    return wcstombs_s(_PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount);                                                                                       }                                                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  size_t __cdecl wcstombs(  char *_Dest,                           wchar_t const* _Source,                             size_t _MaxCount);


 errno_t __cdecl _wcstombs_s_l(
                                                               size_t*        _PtNumOfCharConverted,
      char*          _Dst,
                                                                    size_t         _DstSizeInBytes,
                                                                  wchar_t const* _Src,
                                                                    size_t         _MaxCountInBytes,
                                                                _locale_t      _Locale
    );

extern "C++"                                                                                                                                                      {                                                                                                                                                                     template <size_t _Size>                                                                                                                                           inline                                                                                                                                                            errno_t __cdecl _wcstombs_s_l(                size_t* _PtNumOfCharConverted,   char (&_Dest)[_Size],                    wchar_t const* _Source,                      size_t _MaxCount,                  _locale_t _Locale) throw()                  {                                                                                                                                                                     return _wcstombs_s_l(_PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount, _Locale);                                                                                                }                                                                                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  size_t __cdecl _wcstombs_l(  char *_Dest,                       wchar_t const* _Source,                         size_t _MaxCount,                     _locale_t _Locale);



       


 
 
 __declspec(allocator) char* __cdecl _fullpath(
      char*       _Buffer,
                                char const* _Path,
                                  size_t      _BufferCount
    );



 errno_t __cdecl _makepath_s(
      char*       _Buffer,
                              size_t      _BufferCount,
                        char const* _Drive,
                        char const* _Dir,
                        char const* _Filename,
                        char const* _Ext
    );

extern "C++"                                                                                                                                                      {                                                                                                                                                                     template <size_t _Size>                                                                                                                                           inline                                                                                                                                                            errno_t __cdecl _makepath_s(char (&_Buffer)[_Size],   char const* _Drive,   char const* _Dir,   char const* _Filename,   char const* _Ext) throw()                  {                                                                                                                                                                     return _makepath_s(_Buffer, _Size, _Drive, _Dir, _Filename, _Ext);                                                                                                }                                                                                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  void __cdecl _makepath(    char *_Buffer,                char const* _Drive,                char const* _Dir,                char const* _Filename,                char const* _Ext);

__declspec(deprecated("This function or variable may be unsafe. Consider using _splitpath_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 void __cdecl _splitpath(
                        char const* _FullPath,
        char*       _Drive,
        char*       _Dir,
        char*       _Filename,
        char*       _Ext
    );


 errno_t __cdecl _splitpath_s(
                                  char const* _FullPath,
         char*       _Drive,
                                    size_t      _DriveCount,
           char*       _Dir,
                                    size_t      _DirCount,
      char*       _Filename,
                                    size_t      _FilenameCount,
           char*       _Ext,
                                    size_t      _ExtCount
    );

extern "C++"                                                                                                      {                                                                                                                     template <size_t _DriveSize, size_t _DirSize, size_t _NameSize, size_t _ExtSize>                                  inline                                                                                                            errno_t __cdecl _splitpath_s(                                                                                        char const* _Dest,                                                                                        char (&_Drive)[_DriveSize],                                                                            char (&_Dir)[_DirSize],                                                                                char (&_Name)[_NameSize],                                                                              char (&_Ext)[_ExtSize]                                                                               ) throw()                                                                                     {                                                                                                                     return _splitpath_s(_Dest, _Drive, _DriveSize, _Dir, _DirSize, _Name, _NameSize, _Ext, _ExtSize);                 }                                                                                                             }



 
 errno_t __cdecl getenv_s(
                                 size_t*     _RequiredCount,
      char*       _Buffer,
                                  rsize_t     _BufferCount,
                                char const* _VarName
    );





 int*       __cdecl __p___argc (void);
 char***    __cdecl __p___argv (void);
 wchar_t*** __cdecl __p___wargv(void);


 char***    __cdecl __p__environ (void);
 wchar_t*** __cdecl __p__wenviron(void);





 


      __declspec(deprecated("This function or variable may be unsafe. Consider using _dupenv_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
     char* __cdecl getenv(
          char const* _VarName
        );

    extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl getenv_s(   size_t* _RequiredCount, char (&_Buffer)[_Size],   char const* _VarName) throw()                 {                                                                                                                                    return getenv_s(_RequiredCount, _Buffer, _Size, _VarName);                                                                               }                                                                                                                            }


    
     errno_t __cdecl _dupenv_s(
            char**      _Buffer,
                                                                            size_t*     _BufferCount,
                                                                               char const* _VarName
        );


     int __cdecl system(
          char const* _Command
        );

          
     
     int __cdecl _putenv(
          char const* _EnvString
        );

    
     errno_t __cdecl _putenv_s(
          char const* _Name,
          char const* _Value
        );


     errno_t __cdecl _searchenv_s(
                                char const* _Filename,
                                char const* _VarName,
          char*       _Buffer,
                                  size_t      _BufferCount
        );

    extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl _searchenv_s(  char const* _Filename,   char const* _VarName, char (&_Buffer)[_Size]) throw()                 {                                                                                                                                    return _searchenv_s(_Filename, _VarName, _Buffer, _Size);                                                                               }                                                                                                                            }

    __declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  void __cdecl _searchenv(                   char const* _Filename,                    char const* _VarName,     char *_Buffer);

         __declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using SetErrorMode instead. See online help for details."))
     void __cdecl _seterrormode(
          int _Mode
        );

    __declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using Beep instead. See online help for details."))
     void __cdecl _beep(
          unsigned _Frequency,
          unsigned _Duration
        );

    __declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using Sleep instead. See online help for details."))
     void __cdecl _sleep(
          unsigned long _Duration
        );



     



      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _ecvt. See online help for details.")) __declspec(deprecated("This function or variable may be unsafe. Consider using _ecvt_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
     char* __cdecl ecvt(
           double _Value,
           int    _DigitCount,
          int*   _PtDec,
          int*   _PtSign
        );

      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _fcvt. See online help for details.")) __declspec(deprecated("This function or variable may be unsafe. Consider using _fcvt_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
     char* __cdecl fcvt(
           double _Value,
           int    _FractionalDigitCount,
          int*   _PtDec,
          int*   _PtSign
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _gcvt. See online help for details.")) __declspec(deprecated("This function or variable may be unsafe. Consider using _fcvt_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
     char* __cdecl gcvt(
                            double _Value,
                            int    _DigitCount,
            char*  _DstBuf
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _itoa. See online help for details.")) __declspec(deprecated("This function or variable may be unsafe. Consider using _itoa_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
     char* __cdecl itoa(
                            int   _Value,
            char* _Buffer,
                            int   _Radix
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _ltoa. See online help for details.")) __declspec(deprecated("This function or variable may be unsafe. Consider using _ltoa_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
     char* __cdecl ltoa(
                            long  _Value,
            char* _Buffer,
                            int   _Radix
        );


    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _swab. See online help for details."))
     void __cdecl swab(
          char* _Buf1,
          char* _Buf2,
                                     int   _SizeInBytes
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _ultoa. See online help for details.")) __declspec(deprecated("This function or variable may be unsafe. Consider using _ultoa_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
     char* __cdecl ultoa(
                            unsigned long _Value,
            char*         _Buffer,
                            int           _Radix
        );


      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _putenv. See online help for details."))
     int __cdecl putenv(
          char const* _EnvString
        );


    _onexit_t __cdecl onexit(  _onexit_t _Func);




}                             




    inline double abs(  double _Xx) noexcept   {
    return :: fabs(_Xx);
}

   inline float abs(  float _Xx) noexcept   {
    return :: fabsf(_Xx);
}

   inline long double abs(  long double _Xx) noexcept   {
    return :: fabsl(_Xx);
}

namespace std {
using :: size_t;
using :: div_t;
using :: ldiv_t;
using :: abort;
using :: abs;
using :: atexit;
using :: atof;
using :: atoi;
using :: atol;
using :: bsearch;
using :: calloc;
using :: div;
using :: exit;
using :: free;
using :: labs;
using :: ldiv;
using :: malloc;
using :: mblen;
using :: mbstowcs;
using :: mbtowc;
using :: qsort;
using :: rand;
using :: realloc;
using :: srand;
using :: strtod;
using :: strtol;
using :: strtoul;
using :: wcstombs;
using :: wctomb;

using :: lldiv_t;

using :: getenv;
using :: system;

using :: atoll;
using :: llabs;
using :: lldiv;
using :: strtof;
using :: strtold;
using :: strtoll;
using :: strtoull;

using :: _Exit;
using :: at_quick_exit;
using :: quick_exit;
}



 
  
 
  
 
  



namespace std {
 template <class _Elem>
class initializer_list {
public:
    using value_type      = _Elem;
    using reference       = const _Elem&;
    using const_reference = const _Elem&;
    using size_type       = size_t;

    using iterator       = const _Elem*;
    using const_iterator = const _Elem*;

    constexpr initializer_list() noexcept : _First(nullptr), _Last(nullptr) {}

    constexpr initializer_list(const _Elem* _First_arg, const _Elem* _Last_arg) noexcept
        : _First(_First_arg), _Last(_Last_arg) {}

     constexpr const _Elem* begin() const noexcept {
        return _First;
    }

     constexpr const _Elem* end() const noexcept {
        return _Last;
    }

     constexpr size_t size() const noexcept {
        return static_cast<size_t>(_Last - _First);
    }

private:
    const _Elem* _First;
    const _Elem* _Last;
};

 template <class _Elem>
 constexpr const _Elem* begin(initializer_list<_Elem> _Ilist) noexcept {
    return _Ilist.begin();
}

 template <class _Elem>
 constexpr const _Elem* end(initializer_list<_Elem> _Ilist) noexcept {
    return _Ilist.end();
}
}

 
  



namespace std {
 template <class>
 inline constexpr bool _Always_false = false;

 
 template <class _Ty = void>
struct plus {
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_first_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_second_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_result;

     constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left + _Right;
    }
};

 template <class _Ty = void>
struct minus {
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_first_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_second_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_result;

     constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left - _Right;
    }
};

 template <class _Ty = void>
struct multiplies {
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_first_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_second_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_result;

     constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left * _Right;
    }
};

 template <class _Ty = void>
struct equal_to {
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_first_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_second_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef bool _Unnameable_result;

     constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left == _Right;
    }
};

 template <class _Ty = void>
struct not_equal_to {
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_first_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_second_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef bool _Unnameable_result;

     constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left != _Right;
    }
};

 template <class _Ty = void>
struct greater {
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_first_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_second_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef bool _Unnameable_result;

     constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left > _Right;
    }
};

 template <class _Ty = void>
struct less {
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_first_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_second_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef bool _Unnameable_result;

     constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left < _Right;
    }
};

 template <class _Ty = void>
struct greater_equal {
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_first_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_second_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef bool _Unnameable_result;

     constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left >= _Right;
    }
};

 template <class _Ty = void>
struct less_equal {
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_first_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty _Unnameable_second_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef bool _Unnameable_result;

     constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const {
        return _Left <= _Right;
    }
};

 template <>
struct plus<void> {
    template <class _Ty1, class _Ty2>
     constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        noexcept(noexcept(static_cast<_Ty1&&>(_Left) + static_cast<_Ty2&&>(_Right)))          -> decltype(static_cast<_Ty1&&>(_Left) + static_cast<_Ty2&&>(_Right)) {
        return static_cast<_Ty1&&>(_Left) + static_cast<_Ty2&&>(_Right);
    }

    using is_transparent = int;
};

 template <>
struct minus<void> {
    template <class _Ty1, class _Ty2>
     constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        noexcept(noexcept(static_cast<_Ty1&&>(_Left) - static_cast<_Ty2&&>(_Right)))          -> decltype(static_cast<_Ty1&&>(_Left) - static_cast<_Ty2&&>(_Right)) {
        return static_cast<_Ty1&&>(_Left) - static_cast<_Ty2&&>(_Right);
    }

    using is_transparent = int;
};

 template <>
struct multiplies<void> {
    template <class _Ty1, class _Ty2>
     constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        noexcept(noexcept(static_cast<_Ty1&&>(_Left) * static_cast<_Ty2&&>(_Right)))          -> decltype(static_cast<_Ty1&&>(_Left) * static_cast<_Ty2&&>(_Right)) {
        return static_cast<_Ty1&&>(_Left) * static_cast<_Ty2&&>(_Right);
    }

    using is_transparent = int;
};

 template <>
struct equal_to<void> {
    template <class _Ty1, class _Ty2>
     constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        noexcept(noexcept(static_cast<_Ty1&&>(_Left) == static_cast<_Ty2&&>(_Right)))          -> decltype(static_cast<_Ty1&&>(_Left) == static_cast<_Ty2&&>(_Right)) {
        return static_cast<_Ty1&&>(_Left) == static_cast<_Ty2&&>(_Right);
    }

    using is_transparent = int;
};

 template <>
struct not_equal_to<void> {
    template <class _Ty1, class _Ty2>
     constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        noexcept(noexcept(static_cast<_Ty1&&>(_Left) != static_cast<_Ty2&&>(_Right)))          -> decltype(static_cast<_Ty1&&>(_Left) != static_cast<_Ty2&&>(_Right)) {
        return static_cast<_Ty1&&>(_Left) != static_cast<_Ty2&&>(_Right);
    }

    using is_transparent = int;
};

 template <>
struct greater<void> {
    template <class _Ty1, class _Ty2>
     constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        noexcept(noexcept(static_cast<_Ty1&&>(_Left) > static_cast<_Ty2&&>(_Right)))          -> decltype(static_cast<_Ty1&&>(_Left) > static_cast<_Ty2&&>(_Right)) {
        return static_cast<_Ty1&&>(_Left) > static_cast<_Ty2&&>(_Right);
    }

    using is_transparent = int;
};

 template <>
struct less<void> {
    template <class _Ty1, class _Ty2>
     constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        noexcept(noexcept(static_cast<_Ty1&&>(_Left) < static_cast<_Ty2&&>(_Right)))          -> decltype(static_cast<_Ty1&&>(_Left) < static_cast<_Ty2&&>(_Right)) {
        return static_cast<_Ty1&&>(_Left) < static_cast<_Ty2&&>(_Right);
    }

    using is_transparent = int;
};

 template <>
struct greater_equal<void> {
    template <class _Ty1, class _Ty2>
     constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        noexcept(noexcept(static_cast<_Ty1&&>(_Left) >= static_cast<_Ty2&&>(_Right)))          -> decltype(static_cast<_Ty1&&>(_Left) >= static_cast<_Ty2&&>(_Right)) {
        return static_cast<_Ty1&&>(_Left) >= static_cast<_Ty2&&>(_Right);
    }

    using is_transparent = int;
};

 template <>
struct less_equal<void> {
    template <class _Ty1, class _Ty2>
     constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        noexcept(noexcept(static_cast<_Ty1&&>(_Left) <= static_cast<_Ty2&&>(_Right)))          -> decltype(static_cast<_Ty1&&>(_Left) <= static_cast<_Ty2&&>(_Right)) {
        return static_cast<_Ty1&&>(_Left) <= static_cast<_Ty2&&>(_Right);
    }

    using is_transparent = int;
};

 template <class _Ty>
 constexpr _Ty* addressof(_Ty& _Val) noexcept {
    return __builtin_addressof(_Val);
}

template <class _Ty>
const _Ty* addressof(const _Ty&&) = delete;

 template <class _Ptrty>
 constexpr auto _Unfancy(_Ptrty _Ptr) noexcept {      return ::std:: addressof(*_Ptr);
}

template <class _Ty>
 constexpr _Ty* _Unfancy(_Ty* _Ptr) noexcept {      return _Ptr;
}
}




















namespace std {
 enum float_denorm_style {      denorm_indeterminate = -1,
    denorm_absent        = 0,
    denorm_present       = 1
};

 enum float_round_style {      round_indeterminate       = -1,
    round_toward_zero         = 0,
    round_to_nearest          = 1,
    round_toward_infinity     = 2,
    round_toward_neg_infinity = 3
};

 struct _Num_base {      static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss          = false;
    static constexpr bool has_infinity             = false;
    static constexpr bool has_quiet_NaN            = false;
    static constexpr bool has_signaling_NaN        = false;
    static constexpr bool is_bounded               = false;
    static constexpr bool is_exact                 = false;
    static constexpr bool is_iec559                = false;
    static constexpr bool is_integer               = false;
    static constexpr bool is_modulo                = false;
    static constexpr bool is_signed                = false;
    static constexpr bool is_specialized           = false;
    static constexpr bool tinyness_before          = false;
    static constexpr bool traps                    = false;
    static constexpr float_round_style round_style = round_toward_zero;
    static constexpr int digits                    = 0;
    static constexpr int digits10                  = 0;
    static constexpr int max_digits10              = 0;
    static constexpr int max_exponent              = 0;
    static constexpr int max_exponent10            = 0;
    static constexpr int min_exponent              = 0;
    static constexpr int min_exponent10            = 0;
    static constexpr int radix                     = 0;
};

 template <class _Ty>
class numeric_limits : public _Num_base {  public:
     static constexpr _Ty(min)() noexcept {
        return _Ty();
    }

     static constexpr _Ty(max)() noexcept {
        return _Ty();
    }

     static constexpr _Ty lowest() noexcept {
        return _Ty();
    }

     static constexpr _Ty epsilon() noexcept {
        return _Ty();
    }

     static constexpr _Ty round_error() noexcept {
        return _Ty();
    }

     static constexpr _Ty denorm_min() noexcept {
        return _Ty();
    }

     static constexpr _Ty infinity() noexcept {
        return _Ty();
    }

     static constexpr _Ty quiet_NaN() noexcept {
        return _Ty();
    }

     static constexpr _Ty signaling_NaN() noexcept {
        return _Ty();
    }
};

template <class _Ty>
class numeric_limits<const _Ty> : public numeric_limits<_Ty> {};  
template <class _Ty>
class numeric_limits<volatile _Ty> : public numeric_limits<_Ty> {};  
template <class _Ty>
class numeric_limits<const volatile _Ty> : public numeric_limits<_Ty> {};  
 struct _Num_int_base : _Num_base {      static constexpr bool is_bounded     = true;
    static constexpr bool is_exact       = true;
    static constexpr bool is_integer     = true;
    static constexpr bool is_specialized = true;
    static constexpr int radix           = 2;
};

 struct _Num_float_base : _Num_base {      static constexpr float_denorm_style has_denorm = denorm_present;
    static constexpr bool has_infinity             = true;
    static constexpr bool has_quiet_NaN            = true;
    static constexpr bool has_signaling_NaN        = true;
    static constexpr bool is_bounded               = true;
    static constexpr bool is_iec559                = true;
    static constexpr bool is_signed                = true;
    static constexpr bool is_specialized           = true;
    static constexpr float_round_style round_style = round_to_nearest;
    static constexpr int radix                     = 2;
};

 template <>
class numeric_limits<bool> : public _Num_int_base {
public:
     static constexpr bool(min)() noexcept {
        return false;
    }

     static constexpr bool(max)() noexcept {
        return true;
    }

     static constexpr bool lowest() noexcept {
        return (min)();
    }

     static constexpr bool epsilon() noexcept {
        return 0;
    }

     static constexpr bool round_error() noexcept {
        return 0;
    }

     static constexpr bool denorm_min() noexcept {
        return 0;
    }

     static constexpr bool infinity() noexcept {
        return 0;
    }

     static constexpr bool quiet_NaN() noexcept {
        return 0;
    }

     static constexpr bool signaling_NaN() noexcept {
        return 0;
    }

    static constexpr int digits = 1;
};

 template <>
class numeric_limits<char> : public _Num_int_base {
public:
     static constexpr char(min)() noexcept {
        return (-128);
    }

     static constexpr char(max)() noexcept {
        return 127;
    }

     static constexpr char lowest() noexcept {
        return (min)();
    }

     static constexpr char epsilon() noexcept {
        return 0;
    }

     static constexpr char round_error() noexcept {
        return 0;
    }

     static constexpr char denorm_min() noexcept {
        return 0;
    }

     static constexpr char infinity() noexcept {
        return 0;
    }

     static constexpr char quiet_NaN() noexcept {
        return 0;
    }

     static constexpr char signaling_NaN() noexcept {
        return 0;
    }

    static constexpr bool is_signed = (-128) != 0;
    static constexpr bool is_modulo = (-128) == 0;
    static constexpr int digits     = 8 - ((-128) != 0);
    static constexpr int digits10   = 2;
};

 template <>
class numeric_limits<signed char> : public _Num_int_base {
public:
     static constexpr signed char(min)() noexcept {
        return (-128);
    }

     static constexpr signed char(max)() noexcept {
        return 127;
    }

     static constexpr signed char lowest() noexcept {
        return (min)();
    }

     static constexpr signed char epsilon() noexcept {
        return 0;
    }

     static constexpr signed char round_error() noexcept {
        return 0;
    }

     static constexpr signed char denorm_min() noexcept {
        return 0;
    }

     static constexpr signed char infinity() noexcept {
        return 0;
    }

     static constexpr signed char quiet_NaN() noexcept {
        return 0;
    }

     static constexpr signed char signaling_NaN() noexcept {
        return 0;
    }

    static constexpr bool is_signed = true;
    static constexpr int digits     = 7;
    static constexpr int digits10   = 2;
};

 template <>
class numeric_limits<unsigned char> : public _Num_int_base {
public:
     static constexpr unsigned char(min)() noexcept {
        return 0;
    }

     static constexpr unsigned char(max)() noexcept {
        return 0xff;
    }

     static constexpr unsigned char lowest() noexcept {
        return (min)();
    }

     static constexpr unsigned char epsilon() noexcept {
        return 0;
    }

     static constexpr unsigned char round_error() noexcept {
        return 0;
    }

     static constexpr unsigned char denorm_min() noexcept {
        return 0;
    }

     static constexpr unsigned char infinity() noexcept {
        return 0;
    }

     static constexpr unsigned char quiet_NaN() noexcept {
        return 0;
    }

     static constexpr unsigned char signaling_NaN() noexcept {
        return 0;
    }

    static constexpr bool is_modulo = true;
    static constexpr int digits     = 8;
    static constexpr int digits10   = 2;
};

 template <>
class numeric_limits<char8_t> : public _Num_int_base {
public:
     static constexpr char8_t(min)() noexcept {
        return 0;
    }

     static constexpr char8_t(max)() noexcept {
        return 0xff;
    }

     static constexpr char8_t lowest() noexcept {
        return 0;
    }

     static constexpr char8_t epsilon() noexcept {
        return 0;
    }

     static constexpr char8_t round_error() noexcept {
        return 0;
    }

     static constexpr char8_t denorm_min() noexcept {
        return 0;
    }

     static constexpr char8_t infinity() noexcept {
        return 0;
    }

     static constexpr char8_t quiet_NaN() noexcept {
        return 0;
    }

     static constexpr char8_t signaling_NaN() noexcept {
        return 0;
    }

    static constexpr bool is_modulo = true;
    static constexpr int digits     = 8;
    static constexpr int digits10   = 2;
};

 template <>
class numeric_limits<char16_t> : public _Num_int_base {
public:
     static constexpr char16_t(min)() noexcept {
        return 0;
    }

     static constexpr char16_t(max)() noexcept {
        return 0xffff;
    }

     static constexpr char16_t lowest() noexcept {
        return (min)();
    }

     static constexpr char16_t epsilon() noexcept {
        return 0;
    }

     static constexpr char16_t round_error() noexcept {
        return 0;
    }

     static constexpr char16_t denorm_min() noexcept {
        return 0;
    }

     static constexpr char16_t infinity() noexcept {
        return 0;
    }

     static constexpr char16_t quiet_NaN() noexcept {
        return 0;
    }

     static constexpr char16_t signaling_NaN() noexcept {
        return 0;
    }

    static constexpr bool is_modulo = true;
    static constexpr int digits     = 16;
    static constexpr int digits10   = 4;
};

 template <>
class numeric_limits<char32_t> : public _Num_int_base {
public:
     static constexpr char32_t(min)() noexcept {
        return 0;
    }

     static constexpr char32_t(max)() noexcept {
        return 0xffffffff;
    }

     static constexpr char32_t lowest() noexcept {
        return (min)();
    }

     static constexpr char32_t epsilon() noexcept {
        return 0;
    }

     static constexpr char32_t round_error() noexcept {
        return 0;
    }

     static constexpr char32_t denorm_min() noexcept {
        return 0;
    }

     static constexpr char32_t infinity() noexcept {
        return 0;
    }

     static constexpr char32_t quiet_NaN() noexcept {
        return 0;
    }

     static constexpr char32_t signaling_NaN() noexcept {
        return 0;
    }

    static constexpr bool is_modulo = true;
    static constexpr int digits     = 32;
    static constexpr int digits10   = 9;
};

 template <>
class numeric_limits<wchar_t> : public _Num_int_base {
public:
     static constexpr wchar_t(min)() noexcept {
        return 0x0000;
    }

     static constexpr wchar_t(max)() noexcept {
        return 0xffff;
    }

     static constexpr wchar_t lowest() noexcept {
        return (min)();
    }

     static constexpr wchar_t epsilon() noexcept {
        return 0;
    }

     static constexpr wchar_t round_error() noexcept {
        return 0;
    }

     static constexpr wchar_t denorm_min() noexcept {
        return 0;
    }

     static constexpr wchar_t infinity() noexcept {
        return 0;
    }

     static constexpr wchar_t quiet_NaN() noexcept {
        return 0;
    }

     static constexpr wchar_t signaling_NaN() noexcept {
        return 0;
    }

    static constexpr bool is_modulo = true;
    static constexpr int digits     = 16;
    static constexpr int digits10   = 4;
};

 template <>
class numeric_limits<short> : public _Num_int_base {
public:
     static constexpr short(min)() noexcept {
        return (-32768);
    }

     static constexpr short(max)() noexcept {
        return 32767;
    }

     static constexpr short lowest() noexcept {
        return (min)();
    }

     static constexpr short epsilon() noexcept {
        return 0;
    }

     static constexpr short round_error() noexcept {
        return 0;
    }

     static constexpr short denorm_min() noexcept {
        return 0;
    }

     static constexpr short infinity() noexcept {
        return 0;
    }

     static constexpr short quiet_NaN() noexcept {
        return 0;
    }

     static constexpr short signaling_NaN() noexcept {
        return 0;
    }

    static constexpr bool is_signed = true;
    static constexpr int digits     = 15;
    static constexpr int digits10   = 4;
};

 template <>
class numeric_limits<int> : public _Num_int_base {
public:
     static constexpr int(min)() noexcept {
        return (-2147483647 - 1);
    }

     static constexpr int(max)() noexcept {
        return 2147483647;
    }

     static constexpr int lowest() noexcept {
        return (min)();
    }

     static constexpr int epsilon() noexcept {
        return 0;
    }

     static constexpr int round_error() noexcept {
        return 0;
    }

     static constexpr int denorm_min() noexcept {
        return 0;
    }

     static constexpr int infinity() noexcept {
        return 0;
    }

     static constexpr int quiet_NaN() noexcept {
        return 0;
    }

     static constexpr int signaling_NaN() noexcept {
        return 0;
    }

    static constexpr bool is_signed = true;
    static constexpr int digits     = 31;
    static constexpr int digits10   = 9;
};

 template <>
class numeric_limits<long> : public _Num_int_base {
public:
     static constexpr long(min)() noexcept {
        return (-2147483647L - 1);
    }

     static constexpr long(max)() noexcept {
        return 2147483647L;
    }

     static constexpr long lowest() noexcept {
        return (min)();
    }

     static constexpr long epsilon() noexcept {
        return 0;
    }

     static constexpr long round_error() noexcept {
        return 0;
    }

     static constexpr long denorm_min() noexcept {
        return 0;
    }

     static constexpr long infinity() noexcept {
        return 0;
    }

     static constexpr long quiet_NaN() noexcept {
        return 0;
    }

     static constexpr long signaling_NaN() noexcept {
        return 0;
    }

    static_assert(sizeof(int) == sizeof(long), "LLP64 assumption");
    static constexpr bool is_signed = true;
    static constexpr int digits     = 31;
    static constexpr int digits10   = 9;
};

 template <>
class numeric_limits<long long> : public _Num_int_base {
public:
     static constexpr long long(min)() noexcept {
        return (-9223372036854775807i64 - 1);
    }

     static constexpr long long(max)() noexcept {
        return 9223372036854775807i64;
    }

     static constexpr long long lowest() noexcept {
        return (min)();
    }

     static constexpr long long epsilon() noexcept {
        return 0;
    }

     static constexpr long long round_error() noexcept {
        return 0;
    }

     static constexpr long long denorm_min() noexcept {
        return 0;
    }

     static constexpr long long infinity() noexcept {
        return 0;
    }

     static constexpr long long quiet_NaN() noexcept {
        return 0;
    }

     static constexpr long long signaling_NaN() noexcept {
        return 0;
    }

    static constexpr bool is_signed = true;
    static constexpr int digits     = 63;
    static constexpr int digits10   = 18;
};

 template <>
class numeric_limits<unsigned short> : public _Num_int_base {
public:
     static constexpr unsigned short(min)() noexcept {
        return 0;
    }

     static constexpr unsigned short(max)() noexcept {
        return 0xffff;
    }

     static constexpr unsigned short lowest() noexcept {
        return (min)();
    }

     static constexpr unsigned short epsilon() noexcept {
        return 0;
    }

     static constexpr unsigned short round_error() noexcept {
        return 0;
    }

     static constexpr unsigned short denorm_min() noexcept {
        return 0;
    }

     static constexpr unsigned short infinity() noexcept {
        return 0;
    }

     static constexpr unsigned short quiet_NaN() noexcept {
        return 0;
    }

     static constexpr unsigned short signaling_NaN() noexcept {
        return 0;
    }

    static constexpr bool is_modulo = true;
    static constexpr int digits     = 16;
    static constexpr int digits10   = 4;
};

 template <>
class numeric_limits<unsigned int> : public _Num_int_base {
public:
     static constexpr unsigned int(min)() noexcept {
        return 0;
    }

     static constexpr unsigned int(max)() noexcept {
        return 0xffffffff;
    }

     static constexpr unsigned int lowest() noexcept {
        return (min)();
    }

     static constexpr unsigned int epsilon() noexcept {
        return 0;
    }

     static constexpr unsigned int round_error() noexcept {
        return 0;
    }

     static constexpr unsigned int denorm_min() noexcept {
        return 0;
    }

     static constexpr unsigned int infinity() noexcept {
        return 0;
    }

     static constexpr unsigned int quiet_NaN() noexcept {
        return 0;
    }

     static constexpr unsigned int signaling_NaN() noexcept {
        return 0;
    }

    static constexpr bool is_modulo = true;
    static constexpr int digits     = 32;
    static constexpr int digits10   = 9;
};

 template <>
class numeric_limits<unsigned long> : public _Num_int_base {
public:
     static constexpr unsigned long(min)() noexcept {
        return 0;
    }

     static constexpr unsigned long(max)() noexcept {
        return 0xffffffffUL;
    }

     static constexpr unsigned long lowest() noexcept {
        return (min)();
    }

     static constexpr unsigned long epsilon() noexcept {
        return 0;
    }

     static constexpr unsigned long round_error() noexcept {
        return 0;
    }

     static constexpr unsigned long denorm_min() noexcept {
        return 0;
    }

     static constexpr unsigned long infinity() noexcept {
        return 0;
    }

     static constexpr unsigned long quiet_NaN() noexcept {
        return 0;
    }

     static constexpr unsigned long signaling_NaN() noexcept {
        return 0;
    }

    static_assert(sizeof(unsigned int) == sizeof(unsigned long), "LLP64 assumption");
    static constexpr bool is_modulo = true;
    static constexpr int digits     = 32;
    static constexpr int digits10   = 9;
};

 template <>
class numeric_limits<unsigned long long> : public _Num_int_base {
public:
     static constexpr unsigned long long(min)() noexcept {
        return 0;
    }

     static constexpr unsigned long long(max)() noexcept {
        return 0xffffffffffffffffui64;
    }

     static constexpr unsigned long long lowest() noexcept {
        return (min)();
    }

     static constexpr unsigned long long epsilon() noexcept {
        return 0;
    }

     static constexpr unsigned long long round_error() noexcept {
        return 0;
    }

     static constexpr unsigned long long denorm_min() noexcept {
        return 0;
    }

     static constexpr unsigned long long infinity() noexcept {
        return 0;
    }

     static constexpr unsigned long long quiet_NaN() noexcept {
        return 0;
    }

     static constexpr unsigned long long signaling_NaN() noexcept {
        return 0;
    }

    static constexpr bool is_modulo = true;
    static constexpr int digits     = 64;
    static constexpr int digits10   = 19;
};

 template <>
class numeric_limits<float> : public _Num_float_base {
public:
     static constexpr float(min)() noexcept {
        return 1.175494351e-38F;
    }

     static constexpr float(max)() noexcept {
        return 3.402823466e+38F;
    }

     static constexpr float lowest() noexcept {
        return -(max)();
    }

     static constexpr float epsilon() noexcept {
        return 1.192092896e-07F;
    }

     static constexpr float round_error() noexcept {
        return 0.5F;
    }

     static constexpr float denorm_min() noexcept {
        return 1.401298464e-45F;
    }

     static constexpr float infinity() noexcept {
        return __builtin_huge_valf();
    }

     static constexpr float quiet_NaN() noexcept {
        return __builtin_nanf("0");
    }

     static constexpr float signaling_NaN() noexcept {
        return __builtin_nansf("1");
    }

    static constexpr int digits         = 24;
    static constexpr int digits10       = 6;
    static constexpr int max_digits10   = 9;
    static constexpr int max_exponent   = 128;
    static constexpr int max_exponent10 = 38;
    static constexpr int min_exponent   = (-125);
    static constexpr int min_exponent10 = (-37);
};

 template <>
class numeric_limits<double> : public _Num_float_base {
public:
     static constexpr double(min)() noexcept {
        return 2.2250738585072014e-308;
    }

     static constexpr double(max)() noexcept {
        return 1.7976931348623158e+308;
    }

     static constexpr double lowest() noexcept {
        return -(max)();
    }

     static constexpr double epsilon() noexcept {
        return 2.2204460492503131e-016;
    }

     static constexpr double round_error() noexcept {
        return 0.5;
    }

     static constexpr double denorm_min() noexcept {
        return 4.9406564584124654e-324;
    }

     static constexpr double infinity() noexcept {
        return __builtin_huge_val();
    }

     static constexpr double quiet_NaN() noexcept {
        return __builtin_nan("0");
    }

     static constexpr double signaling_NaN() noexcept {
        return __builtin_nans("1");
    }

    static constexpr int digits         = 53;
    static constexpr int digits10       = 15;
    static constexpr int max_digits10   = 17;
    static constexpr int max_exponent   = 1024;
    static constexpr int max_exponent10 = 308;
    static constexpr int min_exponent   = (-1021);
    static constexpr int min_exponent10 = (-307);
};

 template <>
class numeric_limits<long double> : public _Num_float_base {
public:
     static constexpr long double(min)() noexcept {
        return 2.2250738585072014e-308;
    }

     static constexpr long double(max)() noexcept {
        return 1.7976931348623158e+308;
    }

     static constexpr long double lowest() noexcept {
        return -(max)();
    }

     static constexpr long double epsilon() noexcept {
        return 2.2204460492503131e-016;
    }

     static constexpr long double round_error() noexcept {
        return 0.5L;
    }

     static constexpr long double denorm_min() noexcept {
        return 4.9406564584124654e-324;
    }

     static constexpr long double infinity() noexcept {
        return __builtin_huge_val();
    }

     static constexpr long double quiet_NaN() noexcept {
        return __builtin_nan("0");
    }

     static constexpr long double signaling_NaN() noexcept {
        return __builtin_nans("1");
    }

    static constexpr int digits         = 53;
    static constexpr int digits10       = 15;
    static constexpr int max_digits10   = 17;
    static constexpr int max_exponent   = 1024;
    static constexpr int max_exponent10 = 308;
    static constexpr int min_exponent   = (-1021);
    static constexpr int min_exponent10 = (-307);
};

   template <class _Ty>
 constexpr int _Countl_zero_fallback(_Ty _Val) noexcept {
    _Ty _Yy = 0;

    unsigned int _Nn = numeric_limits<_Ty>::digits;
    unsigned int _Cc = numeric_limits<_Ty>::digits / 2;
    do {
        _Yy = static_cast<_Ty>(_Val >> _Cc);
        if (_Yy != 0) {
            _Nn -= _Cc;
            _Val = _Yy;
        }
        _Cc >>= 1;
    } while (_Cc != 0);
    return static_cast<int>(_Nn) - static_cast<int>(_Val);
}

   template <class _Ty>
 constexpr int _Countr_zero_fallback(const _Ty _Val) noexcept {
    constexpr int _Digits = std::numeric_limits<_Ty>::digits;
    return _Digits - _Countl_zero_fallback(static_cast<_Ty>(static_cast<_Ty>(~_Val) & static_cast<_Ty>(_Val - 1)));
}

extern "C" {
extern int __isa_available;
}

template <class _Ty>
 int _Checked_x86_x64_countr_zero(const _Ty _Val) noexcept {
    constexpr int _Digits = numeric_limits<_Ty>::digits;
    constexpr _Ty _Max    = (numeric_limits<_Ty>::max)();

    const bool _Definitely_have_tzcnt = __isa_available >= __ISA_AVAILABLE_AVX2;
    if (!_Definitely_have_tzcnt && _Val == 0) {
        return _Digits;
    }

    if constexpr (_Digits <= 32) {
                                   return static_cast<int>(_tzcnt_u32(static_cast<unsigned int>(~_Max | _Val)));
    } else {
        return static_cast<int>(_tzcnt_u64(_Val));
    }
}

template <class _Ty>
constexpr bool _Is_standard_unsigned_integer =
    _Is_any_of_v<remove_cv_t<_Ty>, unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long>;

template <class _Ty, enable_if_t<_Is_standard_unsigned_integer<_Ty>, int> = 0>
 constexpr int _Countr_zero(const _Ty _Val) noexcept {
    if (!::std:: is_constant_evaluated()) {
        return _Checked_x86_x64_countr_zero(_Val);
    }
         return _Countr_zero_fallback(_Val);
}

}

