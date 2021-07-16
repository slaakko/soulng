 
  
 
  
   
                                           
                                                 
           
     
                                                                                                                   
  
    
                                                                                              
                     
  

    
 

 





  

 


 

      
   
    
  
 
  
 
  
   
   
 

   
 
  

 
  
 
  

 


 



 
   
 





 
    

  
 


 



 
               

 

 

    

 








 



  
 

 
    
 
 
  
 
 

 
 
 

 
  
   
 




   
   

   

   
 

 

   
    
  
 

 
 
    
  
 
 
 
 




 

  
 
 
  
 
  
  

   
 
 
  
 
   
 
 
  
  
 

 

  

  



 


  



 
 
 
 
    
 
  
 
 
 


 


  
 
 
 

 
    
 
  
 
 
 


 


  
 
 
 

   

   
   
 
  
 
 
 
  
 
 
 

 
 
  
 
 
  
 
 
 


 


  
 
 
 

  
 
 
 
    



     









    



   

    
      
   




 



























 

 
 


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



        int __cdecl _isctype(  int _C,   int _Type);
   int __cdecl _isctype_l(  int _C,   int _Type,   _locale_t _Locale);
    int __cdecl isalpha(  int _C);
   int __cdecl _isalpha_l(  int _C,   _locale_t _Locale);
    int __cdecl isupper(  int _C);
   int __cdecl _isupper_l(  int _C,   _locale_t _Locale);
    int __cdecl islower(  int _C);
   int __cdecl _islower_l(  int _C,   _locale_t _Locale);


    int __cdecl isdigit(  int _C);

   int __cdecl _isdigit_l(  int _C,   _locale_t _Locale);
   int __cdecl isxdigit(  int _C);
   int __cdecl _isxdigit_l(  int _C,   _locale_t _Locale);


    int __cdecl isspace(  int _C);

   int __cdecl _isspace_l(  int _C,   _locale_t _Locale);
   int __cdecl ispunct(  int _C);
   int __cdecl _ispunct_l(  int _C,   _locale_t _Locale);
   int __cdecl isblank(  int _C);
   int __cdecl _isblank_l(  int _C,   _locale_t _Locale);
    int __cdecl isalnum(  int _C);
   int __cdecl _isalnum_l(  int _C,   _locale_t _Locale);
   int __cdecl isprint(  int _C);
   int __cdecl _isprint_l(  int _C,   _locale_t _Locale);
   int __cdecl isgraph(  int _C);
   int __cdecl _isgraph_l(  int _C,   _locale_t _Locale);
   int __cdecl iscntrl(  int _C);
   int __cdecl _iscntrl_l(  int _C,   _locale_t _Locale);


    int __cdecl toupper(  int _C);


    int __cdecl tolower(  int _C);

    int __cdecl _tolower(  int _C);
   int __cdecl _tolower_l(  int _C,   _locale_t _Locale);
    int __cdecl _toupper(  int _C);
   int __cdecl _toupper_l(  int _C,   _locale_t _Locale);

   int __cdecl __isascii(  int _C);
   int __cdecl __toascii(  int _C);
   int __cdecl __iscsymf(  int _C);
   int __cdecl __iscsym(  int _C);



     __inline int __cdecl __acrt_locale_get_ctype_array_value(
      unsigned short const * const _Locale_pctype_array,
              int                    const _Char_value,
                             int                    const _Mask
    )
{
                        if (_Char_value >= -1 && _Char_value <= 255)
    {
        return _Locale_pctype_array[_Char_value] & _Mask;
    }

    return 0;
}


          

                           
         int __cdecl ___mb_cur_max_func(void);
         
         int __cdecl ___mb_cur_max_l_func(_locale_t _Locale);

          




        __forceinline int __cdecl __ascii_tolower(int const _C)
        {
            if (_C >= 'A' && _C <= 'Z')
            {
                return _C - ('A' - 'a');
            }
            return _C;
        }

        __forceinline int __cdecl __ascii_toupper(int const _C)
        {
            if (_C >= 'a' && _C <= 'z')
            {
                return _C - ('a' - 'A');
            }
            return _C;
        }

        __forceinline int __cdecl __ascii_iswalpha(int const _C)
        {
            return (_C >= 'A' && _C <= 'Z') || (_C >= 'a' && _C <= 'z');
        }

        __forceinline int __cdecl __ascii_iswdigit(int const _C)
        {
            return _C >= '0' && _C <= '9';
        }

        __forceinline int __cdecl __ascii_towlower(int const _C)
        {
            return __ascii_tolower(_C);
        }

        __forceinline int __cdecl __ascii_towupper(int const _C)
        {
            return __ascii_toupper(_C);
        }




    __inline __crt_locale_data_public* __cdecl __acrt_get_locale_data_prefix(void const volatile* const _LocalePointers)
    {
        _locale_t const _TypedLocalePointers = (_locale_t)_LocalePointers;
        return (__crt_locale_data_public*)_TypedLocalePointers->locinfo;
    }


    __inline int __cdecl _chvalidchk_l(
              int       const _C,
              int       const _Mask,
          _locale_t const _Locale
        )
    {
        if (_Locale)
        {
            return __acrt_locale_get_ctype_array_value(__acrt_get_locale_data_prefix(_Locale)->_locale_pctype, _C, _Mask);
        }

        return (__acrt_locale_get_ctype_array_value(__pctype_func(), (_C), (_Mask)));
    }


    __inline int __cdecl _ischartype_l(
              int       const _C,
              int       const _Mask,
          _locale_t const _Locale
        )
    {
        if (_Locale) {
            if (_C >= -1 && _C <= 255)
            {
                return __acrt_get_locale_data_prefix(_Locale)->_locale_pctype[_C] & _Mask;
            }

            if (__acrt_get_locale_data_prefix(_Locale)->_locale_mb_cur_max > 1)
            {
                return _isctype_l(_C, _Mask, _Locale);
            }

            return 0;          }

        return _chvalidchk_l(_C, _Mask, 0);
    }





     






}                             




 
namespace std {
using :: isalnum;
using :: isalpha;
using :: iscntrl;
using :: isdigit;
using :: isgraph;
using :: islower;
using :: isprint;
using :: ispunct;
using :: isspace;
using :: isupper;
using :: isxdigit;
using :: tolower;
using :: toupper;

using :: isblank;
}




