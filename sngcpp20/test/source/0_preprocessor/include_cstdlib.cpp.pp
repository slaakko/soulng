 
  
 
  
   
                                           
                                                 
           
     
                                                                                               
  
    
                                                                                              
                     
  

    
 

 





  

 


 

      
   
    
  
 
  
 
  
   
   
 

   
 
  

 
  
 
  

 


 



 
   
 





 
    

  
 


 



 
               

 

 

    

 








 



  
 

 
    
 
 
  
 
 

 
 
 

 
  
   
 




   
   

   

   
 

 

   
    
  
 

 
 
    
  
 
 
 
 




 

  
 
 
  
 
  
  

   
 
 
  
 
   
 
 
  
  
 

 

  

  



 


  



 
 
 
 
    
 
  
 
 
 


 


  
 
 
 

 
    
 
  
 
 
 


 


  
 
 
 

   

   
   
 
  
 
 
 
  
 
 
 

 
 
  
 
 
  
 
 
 


 


  
 
 
 

  
 
 
 
    



     









    



   

    
      
   




 



























 

 
 


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




