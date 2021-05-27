       
       
                     
  

    
 

 





  

 


 

      
   
    
  
 
  
 
  
   
   
 

   
 
  

 
  
 
  

 


 



 
   
 





 
    

  
 


 



 
               

 

 

    

 








 



  
 

 
    
 
 
  
 
 

 
 
 

 
  
   
 




   
   

   

   
 

 

   
    
  
 

 
 
    
  
 
 
 
 




 

  
 
 
  
 
  
  

   
 
 
  
 
   
 
 
  
  
 

 

  

  



 


  



 
 
 
 
    
 
  
 
 
 


 


  
 
 
 

 
    
 
  
 
 
 


 


  
 
 
 

   

   
   
 
  
 
 
 
  
 
 
 

 
 
  
 
 
  
 
 
 


 


  
 
 
 

  
 
 
 
    



     









    



   

    
      
   




 



























 

 
 


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





 int __cdecl fegetround(void);
 int __cdecl fesetround(  int _Round);




    typedef unsigned long fexcept_t;

    typedef struct fenv_t
    {
        unsigned long _Fe_ctl, _Fe_stat;
    } fenv_t;





     int __cdecl fegetenv(  fenv_t* _Env);
     int __cdecl fesetenv(  fenv_t const* _Env);
     int __cdecl feclearexcept(  int _Flags);
       int __cdecl feholdexcept(  fenv_t* _Env);
     int __cdecl fetestexcept(  int _Flags);
     int __cdecl fegetexceptflag(  fexcept_t* _Except,   int _TestFlags);
     int __cdecl fesetexceptflag(  fexcept_t const* _Except,   int _SetFlags);

                                                __declspec(selectany) extern const fenv_t _Fenv1 = { 0x3f00003f, 0 };




                                           
        __inline int __cdecl feraiseexcept(  int _Except)
        {
            static struct
            {
                int    _Except_Val;
                double _Num;
                double _Denom;
            } const _Table[] =
            {                   {0x00000010,   0.0,    0.0    },
                {0x00000008, 1.0,    0.0    },
                {0x00000004,  1e+300, 1e-300 },
                {0x00000002, 1e-300, 1e+300 },
                {0x00000001,   2.0,    3.0    }
            };

            double _Ans = 0.0;
            size_t _Index;

            if ((_Except &= (0x00000008 | 0x00000001 | 0x00000010 | 0x00000004 | 0x00000002)) == 0)
            {
                return 0;
            }

                         for (_Index = 0; _Index < sizeof(_Table) / sizeof(_Table[0]); ++_Index)
            {
                if ((_Except & _Table[_Index]._Except_Val) != 0)
                {
                    _Ans = _Table[_Index]._Num / _Table[_Index]._Denom;

                                                                               }
            }

            return 0;
        }
        

        __inline int __cdecl feupdateenv(  const fenv_t *_Penv)
        {
            int _Except = fetestexcept((0x00000008 | 0x00000001 | 0x00000010 | 0x00000004 | 0x00000002));

            if (fesetenv(_Penv) != 0 || feraiseexcept(_Except) != 0)
            {
                return 1;
            }

            return 0;
        }


}                             


