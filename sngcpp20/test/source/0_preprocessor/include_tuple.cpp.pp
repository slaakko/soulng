 
  
 
  
   
                                           
                                                 
           
     
                                                                                               
  
    
                                                                                              
                     
  

    
 

 





  

 


 

      
   
    
  
 
  
 
  
   
   
 

   
 
  

 
  
 
  

 


 



 
   
 





 
    

  
 


 



 
               

 

 

    

 








 



  
 

 
    
 
 
  
 
 

 
 
 

 
  
   
 




   
   

   

   
 

 

   
    
  
 

 
 
    
  
 
 
 
 




 

  
 
 
  
 
  
  

   
 
 
  
 
   
 
 
  
  
 

 

  

  



 


  



 
 
 
 
    
 
  
 
 
 


 


  
 
 
 

 
    
 
  
 
 
 


 


  
 
 
 

   

   
   
 
  
 
 
 
  
 
 
 

 
 
  
 
 
  
 
 
 


 


  
 
 
 

  
 
 
 
    



     









    



   

    
      
   




 



























 

 
 


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


 
  
 
  


      
 
 
















































































 



 


 




 





  

  
 
 
  
 
 

                         
  
      

  





  
 
 
 
 
 
 
 
 
    
 
  

 
 

 

  


  
   
 
 
 
  
 
 
 
 
 
 
 
 
 
  
 

  
 
 


 
 

 





 
 









  
 
 
 


 











 


 
 






  

 
  
 
  
 
  
 
  

       
       


typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;

typedef signed char        int_least8_t;
typedef short              int_least16_t;
typedef int                int_least32_t;
typedef long long          int_least64_t;
typedef unsigned char      uint_least8_t;
typedef unsigned short     uint_least16_t;
typedef unsigned int       uint_least32_t;
typedef unsigned long long uint_least64_t;

typedef signed char        int_fast8_t;
typedef int                int_fast16_t;
typedef int                int_fast32_t;
typedef long long          int_fast64_t;
typedef unsigned char      uint_fast8_t;
typedef unsigned int       uint_fast16_t;
typedef unsigned int       uint_fast32_t;
typedef unsigned long long uint_fast64_t;

typedef long long          intmax_t;
typedef unsigned long long uintmax_t;

 





     










namespace std {
using :: int8_t;
using :: int16_t;
using :: int32_t;
using :: int64_t;
using :: uint8_t;
using :: uint16_t;
using :: uint32_t;
using :: uint64_t;

using :: int_least8_t;
using :: int_least16_t;
using :: int_least32_t;
using :: int_least64_t;
using :: uint_least8_t;
using :: uint_least16_t;
using :: uint_least32_t;
using :: uint_least64_t;

using :: int_fast8_t;
using :: int_fast16_t;
using :: int_fast32_t;
using :: int_fast64_t;
using :: uint_fast8_t;
using :: uint_fast16_t;
using :: uint_fast32_t;
using :: uint_fast64_t;

using :: intmax_t;
using :: intptr_t;
using :: uintmax_t;
using :: uintptr_t;

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
 template <class _Ty, _Ty... _Vals>
struct integer_sequence {      static_assert(is_integral_v<_Ty>, "integer_sequence<T, I...> requires T to be an integral type.");

    using value_type = _Ty;

     static constexpr size_t size() noexcept {
        return sizeof...(_Vals);
    }
};

 template <class _Ty, _Ty _Size>
using make_integer_sequence = __make_integer_seq<integer_sequence, _Ty, _Size>;

template <size_t... _Vals>
using index_sequence = integer_sequence<size_t, _Vals...>;

template <size_t _Size>
using make_index_sequence = make_integer_sequence<size_t, _Size>;

template <class... _Types>
using index_sequence_for = make_index_sequence<sizeof...(_Types)>;

 template <bool _First_value, class _First, class... _Rest>
struct _Conjunction {      using type = _First;
};

template <class _True, class _Next, class... _Rest>
struct _Conjunction<true, _True, _Next, _Rest...> {      using type = typename _Conjunction<_Next::value, _Next, _Rest...>::type;
};

template <class... _Traits>
struct conjunction : true_type {};  
template <class _First, class... _Rest>
struct conjunction<_First, _Rest...> : _Conjunction<_First::value, _First, _Rest...>::type {
     };

template <class... _Traits>
inline constexpr bool conjunction_v = conjunction<_Traits...>::value;

 template <class _Trait>
struct negation : bool_constant<!static_cast<bool>(_Trait::value)> {};  
template <class _Trait>
inline constexpr bool negation_v = negation<_Trait>::value;

 template <class _Ty>
inline constexpr bool is_void_v = is_same_v<remove_cv_t<_Ty>, void>;

template <class _Ty>
struct is_void : bool_constant<is_void_v<_Ty>> {};

 template <class... _Types>
using void_t = void;

  template <class _Ty>
struct add_const {      using type = const _Ty;
};

template <class _Ty>
using add_const_t = typename add_const<_Ty>::type;

 template <class _Ty>
struct add_volatile {      using type = volatile _Ty;
};

template <class _Ty>
using add_volatile_t = typename add_volatile<_Ty>::type;

 template <class _Ty>
struct add_cv {      using type = const volatile _Ty;
};

template <class _Ty>
using add_cv_t = typename add_cv<_Ty>::type;

 template <class _Ty, class = void>
struct _Add_reference {      using _Lvalue = _Ty;
    using _Rvalue = _Ty;
};

template <class _Ty>
struct _Add_reference<_Ty, void_t<_Ty&>> {      using _Lvalue = _Ty&;
    using _Rvalue = _Ty&&;
};

 template <class _Ty>
struct add_lvalue_reference {
    using type = typename _Add_reference<_Ty>::_Lvalue;
};

template <class _Ty>
using add_lvalue_reference_t = typename _Add_reference<_Ty>::_Lvalue;

 template <class _Ty>
struct add_rvalue_reference {
    using type = typename _Add_reference<_Ty>::_Rvalue;
};

template <class _Ty>
using add_rvalue_reference_t = typename _Add_reference<_Ty>::_Rvalue;

 template <class _Ty>
add_rvalue_reference_t<_Ty> declval() noexcept;

 template <class _Ty>
struct remove_extent {      using type = _Ty;
};

template <class _Ty, size_t _Ix>
struct remove_extent<_Ty[_Ix]> {
    using type = _Ty;
};

template <class _Ty>
struct remove_extent<_Ty[]> {
    using type = _Ty;
};

template <class _Ty>
using remove_extent_t = typename remove_extent<_Ty>::type;

 template <class _Ty>
struct remove_all_extents {      using type = _Ty;
};

template <class _Ty, size_t _Ix>
struct remove_all_extents<_Ty[_Ix]> {
    using type = typename remove_all_extents<_Ty>::type;
};

template <class _Ty>
struct remove_all_extents<_Ty[]> {
    using type = typename remove_all_extents<_Ty>::type;
};

template <class _Ty>
using remove_all_extents_t = typename remove_all_extents<_Ty>::type;

 template <class _Ty>
struct remove_pointer {
    using type = _Ty;
};

template <class _Ty>
struct remove_pointer<_Ty*> {
    using type = _Ty;
};

template <class _Ty>
struct remove_pointer<_Ty* const> {
    using type = _Ty;
};

template <class _Ty>
struct remove_pointer<_Ty* volatile> {
    using type = _Ty;
};

template <class _Ty>
struct remove_pointer<_Ty* const volatile> {
    using type = _Ty;
};

template <class _Ty>
using remove_pointer_t = typename remove_pointer<_Ty>::type;

 template <class _Ty, class = void>
struct _Add_pointer {      using type = _Ty;
};

template <class _Ty>
struct _Add_pointer<_Ty, void_t<remove_reference_t<_Ty>*>> {      using type = remove_reference_t<_Ty>*;
};

template <class _Ty>
struct add_pointer {
    using type = typename _Add_pointer<_Ty>::type;
};

template <class _Ty>
using add_pointer_t = typename _Add_pointer<_Ty>::type;

  template <class>
inline constexpr bool is_array_v = false;  
template <class _Ty, size_t _Nx>
inline constexpr bool is_array_v<_Ty[_Nx]> = true;

template <class _Ty>
inline constexpr bool is_array_v<_Ty[]> = true;

template <class _Ty>
struct is_array : bool_constant<is_array_v<_Ty>> {};

 template <class>
inline constexpr bool is_bounded_array_v = false;

template <class _Ty, size_t _Nx>
inline constexpr bool is_bounded_array_v<_Ty[_Nx]> = true;

template <class _Ty>
struct is_bounded_array : bool_constant<is_bounded_array_v<_Ty>> {};

 template <class>
inline constexpr bool is_unbounded_array_v = false;

template <class _Ty>
inline constexpr bool is_unbounded_array_v<_Ty[]> = true;

template <class _Ty>
struct is_unbounded_array : bool_constant<is_unbounded_array_v<_Ty>> {};

 template <class>
inline constexpr bool is_lvalue_reference_v = false;  
template <class _Ty>
inline constexpr bool is_lvalue_reference_v<_Ty&> = true;

template <class _Ty>
struct is_lvalue_reference : bool_constant<is_lvalue_reference_v<_Ty>> {};

 template <class>
inline constexpr bool is_rvalue_reference_v = false;  
template <class _Ty>
inline constexpr bool is_rvalue_reference_v<_Ty&&> = true;

template <class _Ty>
struct is_rvalue_reference : bool_constant<is_rvalue_reference_v<_Ty>> {};

 template <class>
inline constexpr bool is_reference_v = false;  
template <class _Ty>
inline constexpr bool is_reference_v<_Ty&> = true;

template <class _Ty>
inline constexpr bool is_reference_v<_Ty&&> = true;

template <class _Ty>
struct is_reference : bool_constant<is_reference_v<_Ty>> {};

 template <class>
inline constexpr bool is_pointer_v = false;  
template <class _Ty>
inline constexpr bool is_pointer_v<_Ty*> = true;

template <class _Ty>
inline constexpr bool is_pointer_v<_Ty* const> = true;

template <class _Ty>
inline constexpr bool is_pointer_v<_Ty* volatile> = true;

template <class _Ty>
inline constexpr bool is_pointer_v<_Ty* const volatile> = true;

template <class _Ty>
struct is_pointer : bool_constant<is_pointer_v<_Ty>> {};

 template <class _Ty>
inline constexpr bool is_null_pointer_v =
    is_same_v<remove_cv_t<_Ty>, nullptr_t>;  
template <class _Ty>
struct is_null_pointer : bool_constant<is_null_pointer_v<_Ty>> {};

 template <class _Ty>
struct is_union : bool_constant<__is_union(_Ty)> {};  
template <class _Ty>
inline constexpr bool is_union_v = __is_union(_Ty);

 template <class _Ty>
struct is_class : bool_constant<__is_class(_Ty)> {};  
template <class _Ty>
inline constexpr bool is_class_v = __is_class(_Ty);

 template <class _Ty>
inline constexpr bool is_fundamental_v = is_arithmetic_v<_Ty> || is_void_v<_Ty> || is_null_pointer_v<_Ty>;

template <class _Ty>
struct is_fundamental : bool_constant<is_fundamental_v<_Ty>> {};  
 template <class _From, class _To>
struct is_convertible : bool_constant<__is_convertible_to(_From, _To)> {
     };

template <class _From, class _To>
inline constexpr bool is_convertible_v = __is_convertible_to(_From, _To);

 template <class _Ty>
struct is_enum : bool_constant<__is_enum(_Ty)> {};  
template <class _Ty>
inline constexpr bool is_enum_v = __is_enum(_Ty);

 template <class _Ty>
struct is_compound : bool_constant<!is_fundamental_v<_Ty>> {};  
template <class _Ty>
inline constexpr bool is_compound_v = !is_fundamental_v<_Ty>;

 template <class... _Types>
struct _Arg_types {};  
template <class _Ty1>
struct _Arg_types<_Ty1> {
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty1 _Unnameable_argument;
};

template <class _Ty1, class _Ty2>
struct _Arg_types<_Ty1, _Ty2> {
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty1 _Unnameable_first_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ty2 _Unnameable_second_argument;
};

 template <class _Ty>
struct _Is_memfunptr {      using _Bool_type = false_type;  };


template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };             template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };     template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };           template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };             template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };     template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };          template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };             template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };     template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };             template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };     template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };           template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };             template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };     template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };          template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };             template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };     template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };                                        template <class _Ret, class _Arg0, class... _Types>                                       struct _Is_memfunptr<_Ret (CALL_OPT _Arg0::*)(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT>         : _Arg_types<CV_OPT _Arg0*, _Types...> {                                                  using _Bool_type = true_type;                                                             [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                         using _Class_type = _Arg0;                                                                using _Guide_type = enable_if<!is_same_v<int REF_OPT, int&&>, _Ret(_Types...)>;       };


template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                       template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                                 template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                              template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                        template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                                     template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                                template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                             template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                       template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                                    template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                               template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                            template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                      template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                              template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                        template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                     template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };               template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                             template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                       template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                    template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };              template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                            template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                      template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };                   template <class _Ret, class _Arg0, class... _Types>                          struct _Is_memfunptr<_Ret (_Arg0::*)(_Types..., ...)                                 CV_REF_NOEXCEPT_OPT> {           using _Bool_type = true_type;                                                [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;            using _Class_type = _Arg0;                                                   using _Guide_type = enable_if<false>;                                    };

template <class _Ty>
inline constexpr bool is_member_function_pointer_v = _Is_memfunptr<remove_cv_t<_Ty>>::_Bool_type::value;

template <class _Ty>
struct is_member_function_pointer : bool_constant<is_member_function_pointer_v<_Ty>> {};

 template <class>
inline constexpr bool is_const_v = false;  
template <class _Ty>
inline constexpr bool is_const_v<const _Ty> = true;

template <class _Ty>
struct is_const : bool_constant<is_const_v<_Ty>> {};

 template <class>
inline constexpr bool is_volatile_v = false;  
template <class _Ty>
inline constexpr bool is_volatile_v<volatile _Ty> = true;

template <class _Ty>
struct is_volatile : bool_constant<is_volatile_v<_Ty>> {};

 template <class _Ty>
inline constexpr bool is_function_v =      !is_const_v<const _Ty> && !is_reference_v<_Ty>;

template <class _Ty>
struct is_function : bool_constant<is_function_v<_Ty>> {};

 template <class _Ty>
inline constexpr bool is_object_v =      is_const_v<const _Ty> && !is_void_v<_Ty>;

template <class _Ty>
struct is_object : bool_constant<is_object_v<_Ty>> {};

 template <class>
struct _Is_member_object_pointer {
    static constexpr bool value = false;
};

template <class _Ty1, class _Ty2>
struct _Is_member_object_pointer<_Ty1 _Ty2::*> {
    static constexpr bool value = !is_function_v<_Ty1>;
    using _Class_type           = _Ty2;
};

template <class _Ty>
inline constexpr bool is_member_object_pointer_v = _Is_member_object_pointer<remove_cv_t<_Ty>>::value;

template <class _Ty>
struct is_member_object_pointer : bool_constant<is_member_object_pointer_v<_Ty>> {};

 template <class _Ty>
inline constexpr bool is_member_pointer_v = is_member_object_pointer_v<_Ty> || is_member_function_pointer_v<_Ty>;

template <class _Ty>
struct is_member_pointer : bool_constant<is_member_pointer_v<_Ty>> {};  
 template <class _Ty>
inline constexpr bool is_scalar_v =      is_arithmetic_v<_Ty> || is_enum_v<_Ty> || is_pointer_v<_Ty> || is_member_pointer_v<_Ty> || is_null_pointer_v<_Ty>;

template <class _Ty>
struct is_scalar : bool_constant<is_scalar_v<_Ty>> {};

 template <class _Ty>
struct [[deprecated("warning STL4025: std::is_pod and std::is_pod_v are deprecated in C++20. The std::is_trivially_copyable and/or std::is_standard_layout traits likely suit your use case. You can define _SILENCE_CXX20_IS_POD_DEPRECATION_WARNING or _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] is_pod : bool_constant<__is_pod(_Ty)> {};  
template <class _Ty>
[[deprecated("warning STL4025: std::is_pod and std::is_pod_v are deprecated in C++20. The std::is_trivially_copyable and/or std::is_standard_layout traits likely suit your use case. You can define _SILENCE_CXX20_IS_POD_DEPRECATION_WARNING or _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] inline constexpr bool is_pod_v = __is_pod(_Ty);

 template <class _Ty>
struct is_empty : bool_constant<__is_empty(_Ty)> {};  
template <class _Ty>
inline constexpr bool is_empty_v = __is_empty(_Ty);

 template <class _Ty>
struct is_polymorphic : bool_constant<__is_polymorphic(_Ty)> {};  
template <class _Ty>
inline constexpr bool is_polymorphic_v = __is_polymorphic(_Ty);

 template <class _Ty>
struct is_abstract : bool_constant<__is_abstract(_Ty)> {};  
template <class _Ty>
inline constexpr bool is_abstract_v = __is_abstract(_Ty);

 template <class _Ty>
struct is_final : bool_constant<__is_final(_Ty)> {};  
template <class _Ty>
inline constexpr bool is_final_v = __is_final(_Ty);

 template <class _Ty>
struct is_standard_layout : bool_constant<__is_standard_layout(_Ty)> {};  
template <class _Ty>
inline constexpr bool is_standard_layout_v = __is_standard_layout(_Ty);


 template <class _Ty>
struct is_trivial : bool_constant<__is_trivially_constructible(_Ty) && __is_trivially_copyable(_Ty)> {
     };

template <class _Ty>
inline constexpr bool is_trivial_v = __is_trivially_constructible(_Ty) && __is_trivially_copyable(_Ty);

 template <class _Ty>
struct is_trivially_copyable : bool_constant<__is_trivially_copyable(_Ty)> {
     };

template <class _Ty>
inline constexpr bool is_trivially_copyable_v = __is_trivially_copyable(_Ty);

 template <class _Ty>
struct has_virtual_destructor : bool_constant<__has_virtual_destructor(_Ty)> {
     };

template <class _Ty>
inline constexpr bool has_virtual_destructor_v = __has_virtual_destructor(_Ty);

 template <class _Ty>
struct has_unique_object_representations : bool_constant<__has_unique_object_representations(_Ty)> {
     };

template <class _Ty>
inline constexpr bool has_unique_object_representations_v = __has_unique_object_representations(_Ty);

 template <class _Ty>
struct is_aggregate : bool_constant<__is_aggregate(_Ty)> {};  
template <class _Ty>
inline constexpr bool is_aggregate_v = __is_aggregate(_Ty);

  template <class _Ty, class... _Args>
struct is_constructible : bool_constant<__is_constructible(_Ty, _Args...)> {
     };

template <class _Ty, class... _Args>
inline constexpr bool is_constructible_v = __is_constructible(_Ty, _Args...);

 template <class _Ty>
struct is_copy_constructible : bool_constant<__is_constructible(_Ty, add_lvalue_reference_t<const _Ty>)> {
     };

template <class _Ty>
inline constexpr bool is_copy_constructible_v = __is_constructible(_Ty, add_lvalue_reference_t<const _Ty>);

 template <class _Ty>
struct is_default_constructible : bool_constant<__is_constructible(_Ty)> {
     };

template <class _Ty>
inline constexpr bool is_default_constructible_v = __is_constructible(_Ty);

 template <class _Ty, class = void>
struct _Is_implicitly_default_constructible : false_type {
     };

template <class _Ty>
void _Implicitly_default_construct(const _Ty&);

template <class _Ty>
struct _Is_implicitly_default_constructible<_Ty, void_t<decltype(_Implicitly_default_construct<_Ty>({}))>> : true_type {
};

 template <class _Ty>
struct is_move_constructible : bool_constant<__is_constructible(_Ty, _Ty)> {
     };

template <class _Ty>
inline constexpr bool is_move_constructible_v = __is_constructible(_Ty, _Ty);

 template <class _To, class _From>
struct is_assignable : bool_constant<__is_assignable(_To, _From)> {};  
template <class _To, class _From>
inline constexpr bool is_assignable_v = __is_assignable(_To, _From);

 template <class _Ty>
struct is_copy_assignable
    : bool_constant<__is_assignable(add_lvalue_reference_t<_Ty>, add_lvalue_reference_t<const _Ty>)> {
     };

template <class _Ty>
inline constexpr bool is_copy_assignable_v = __is_assignable(
    add_lvalue_reference_t<_Ty>, add_lvalue_reference_t<const _Ty>);

template <class _Ty>
struct _Is_copy_assignable_no_precondition_check
    : bool_constant<__is_assignable_no_precondition_check(
          add_lvalue_reference_t<_Ty>, add_lvalue_reference_t<const _Ty>)> {};

template <class _Ty>
inline constexpr bool _Is_copy_assignable_unchecked_v = __is_assignable_no_precondition_check(
    add_lvalue_reference_t<_Ty>, add_lvalue_reference_t<const _Ty>);

 template <class _Ty>
struct is_move_assignable : bool_constant<__is_assignable(add_lvalue_reference_t<_Ty>, _Ty)> {
     };

template <class _Ty>
inline constexpr bool is_move_assignable_v = __is_assignable(add_lvalue_reference_t<_Ty>, _Ty);

template <class _Ty>
struct _Is_move_assignable_no_precondition_check
    : bool_constant<__is_assignable_no_precondition_check(add_lvalue_reference_t<_Ty>, _Ty)> {};

template <class _Ty>
inline constexpr bool _Is_move_assignable_unchecked_v = __is_assignable_no_precondition_check(
    add_lvalue_reference_t<_Ty>, _Ty);

 template <class _Ty>
struct is_destructible : bool_constant<__is_destructible(_Ty)> {
     };

template <class _Ty>
inline constexpr bool is_destructible_v = __is_destructible(_Ty);

  template <class _Ty, class... _Args>
struct is_trivially_constructible : bool_constant<__is_trivially_constructible(_Ty, _Args...)> {
     };

template <class _Ty, class... _Args>
inline constexpr bool is_trivially_constructible_v = __is_trivially_constructible(_Ty, _Args...);

 template <class _Ty>
struct is_trivially_copy_constructible
    : bool_constant<__is_trivially_constructible(_Ty, add_lvalue_reference_t<const _Ty>)> {
     };

template <class _Ty>
inline constexpr bool is_trivially_copy_constructible_v = __is_trivially_constructible(
    _Ty, add_lvalue_reference_t<const _Ty>);

 template <class _Ty>
struct is_trivially_default_constructible : bool_constant<__is_trivially_constructible(_Ty)> {
     };

template <class _Ty>
inline constexpr bool is_trivially_default_constructible_v = __is_trivially_constructible(_Ty);

 template <class _Ty>
struct is_trivially_move_constructible : bool_constant<__is_trivially_constructible(_Ty, _Ty)> {
     };

template <class _Ty>
inline constexpr bool is_trivially_move_constructible_v = __is_trivially_constructible(_Ty, _Ty);

 template <class _To, class _From>
struct is_trivially_assignable : bool_constant<__is_trivially_assignable(_To, _From)> {
     };

template <class _To, class _From>
inline constexpr bool is_trivially_assignable_v = __is_trivially_assignable(_To, _From);

 template <class _Ty>
struct is_trivially_copy_assignable
    : bool_constant<__is_trivially_assignable(add_lvalue_reference_t<_Ty>, add_lvalue_reference_t<const _Ty>)> {
     };

template <class _Ty>
inline constexpr bool is_trivially_copy_assignable_v = __is_trivially_assignable(
    add_lvalue_reference_t<_Ty>, add_lvalue_reference_t<const _Ty>);

 template <class _Ty>
struct is_trivially_move_assignable : bool_constant<__is_trivially_assignable(add_lvalue_reference_t<_Ty>, _Ty)> {
     };

template <class _Ty>
inline constexpr bool is_trivially_move_assignable_v = __is_trivially_assignable(add_lvalue_reference_t<_Ty>, _Ty);

 template <class _Ty>
struct is_trivially_destructible : bool_constant<__is_trivially_destructible(_Ty)> {
     };

template <class _Ty>
inline constexpr bool is_trivially_destructible_v = __is_trivially_destructible(_Ty);

  template <class _Ty, class... _Args>
struct is_nothrow_constructible : bool_constant<__is_nothrow_constructible(_Ty, _Args...)> {
     };

template <class _Ty, class... _Args>
inline constexpr bool is_nothrow_constructible_v = __is_nothrow_constructible(_Ty, _Args...);

 template <class _Ty>
struct is_nothrow_copy_constructible
    : bool_constant<__is_nothrow_constructible(_Ty, add_lvalue_reference_t<const _Ty>)> {
          };

template <class _Ty>
inline constexpr bool is_nothrow_copy_constructible_v = __is_nothrow_constructible(
    _Ty, add_lvalue_reference_t<const _Ty>);

 template <class _Ty>
struct is_nothrow_default_constructible : bool_constant<__is_nothrow_constructible(_Ty)> {
     };

template <class _Ty>
inline constexpr bool is_nothrow_default_constructible_v = __is_nothrow_constructible(_Ty);

 template <class _Ty>
struct is_nothrow_move_constructible : bool_constant<__is_nothrow_constructible(_Ty, _Ty)> {
     };

template <class _Ty>
inline constexpr bool is_nothrow_move_constructible_v = __is_nothrow_constructible(_Ty, _Ty);

 template <class _To, class _From>
struct is_nothrow_assignable : bool_constant<__is_nothrow_assignable(_To, _From)> {
     };

template <class _To, class _From>
inline constexpr bool is_nothrow_assignable_v = __is_nothrow_assignable(_To, _From);

 template <class _Ty>
struct is_nothrow_copy_assignable
    : bool_constant<__is_nothrow_assignable(add_lvalue_reference_t<_Ty>, add_lvalue_reference_t<const _Ty>)> {
     };

template <class _Ty>
inline constexpr bool is_nothrow_copy_assignable_v = __is_nothrow_assignable(
    add_lvalue_reference_t<_Ty>, add_lvalue_reference_t<const _Ty>);

 template <class _Ty>
struct is_nothrow_move_assignable : bool_constant<__is_nothrow_assignable(add_lvalue_reference_t<_Ty>, _Ty)> {
     };

template <class _Ty>
inline constexpr bool is_nothrow_move_assignable_v = __is_nothrow_assignable(add_lvalue_reference_t<_Ty>, _Ty);

 template <class _Ty>
struct is_nothrow_destructible : bool_constant<__is_nothrow_destructible(_Ty)> {
          };

template <class _Ty>
inline constexpr bool is_nothrow_destructible_v = __is_nothrow_destructible(_Ty);

 template <class _Ty, bool = is_integral_v<_Ty>>
struct _Sign_base {      using _Uty = remove_cv_t<_Ty>;

    static constexpr bool _Signed   = static_cast<_Uty>(-1) < static_cast<_Uty>(0);
    static constexpr bool _Unsigned = !_Signed;
};

template <class _Ty>
struct _Sign_base<_Ty, false> {                                       static constexpr bool _Signed   = is_floating_point_v<_Ty>;
    static constexpr bool _Unsigned = false;
};

template <class _Ty>
struct is_signed : bool_constant<_Sign_base<_Ty>::_Signed> {};  
template <class _Ty>
inline constexpr bool is_signed_v = _Sign_base<_Ty>::_Signed;

 template <class _Ty>
struct is_unsigned : bool_constant<_Sign_base<_Ty>::_Unsigned> {};  
template <class _Ty>
inline constexpr bool is_unsigned_v = _Sign_base<_Ty>::_Unsigned;

 template <class _Ty>
inline constexpr bool _Is_nonbool_integral = is_integral_v<_Ty> && !is_same_v<remove_cv_t<_Ty>, bool>;

 template <bool>
struct _Select {      template <class _Ty1, class>
    using _Apply = _Ty1;
};

template <>
struct _Select<false> {
    template <class, class _Ty2>
    using _Apply = _Ty2;
};

template <size_t>
struct _Make_signed2;  
template <>
struct _Make_signed2<1> {
    template <class>
    using _Apply = signed char;
};

template <>
struct _Make_signed2<2> {
    template <class>
    using _Apply = short;
};

template <>
struct _Make_signed2<4> {
    template <class _Ty>
    using _Apply =          typename _Select<is_same_v<_Ty, long> || is_same_v<_Ty, unsigned long>>::template _Apply<long, int>;
};

template <>
struct _Make_signed2<8> {
    template <class>
    using _Apply = long long;
};

template <class _Ty>
using _Make_signed1 =      typename _Make_signed2<sizeof(_Ty)>::template _Apply<_Ty>;

template <class _Ty>
struct make_signed {      static_assert(_Is_nonbool_integral<_Ty> || is_enum_v<_Ty>,
        "make_signed<T> requires that T shall be a (possibly cv-qualified) integral type or enumeration but not a bool type.");

    using type = typename remove_cv<_Ty>::template _Apply<_Make_signed1>;
};

template <class _Ty>
using make_signed_t = typename make_signed<_Ty>::type;

 template <size_t>
struct _Make_unsigned2;  
template <>
struct _Make_unsigned2<1> {
    template <class>
    using _Apply = unsigned char;
};

template <>
struct _Make_unsigned2<2> {
    template <class>
    using _Apply = unsigned short;
};

template <>
struct _Make_unsigned2<4> {
    template <class _Ty>
    using _Apply =          typename _Select<is_same_v<_Ty, long> || is_same_v<_Ty, unsigned long>>::template _Apply<unsigned long,
            unsigned int>;
};

template <>
struct _Make_unsigned2<8> {
    template <class>
    using _Apply = unsigned long long;
};

template <class _Ty>
using _Make_unsigned1 =      typename _Make_unsigned2<sizeof(_Ty)>::template _Apply<_Ty>;

template <class _Ty>
struct make_unsigned {      static_assert(_Is_nonbool_integral<_Ty> || is_enum_v<_Ty>,
        "make_unsigned<T> requires that T shall be a (possibly cv-qualified) integral type or enumeration but not a bool type.");

    using type = typename remove_cv<_Ty>::template _Apply<_Make_unsigned1>;
};

template <class _Ty>
using make_unsigned_t = typename make_unsigned<_Ty>::type;

 template <class _Rep>
constexpr make_unsigned_t<_Rep> _Unsigned_value(_Rep _Val) {      return static_cast<make_unsigned_t<_Rep>>(_Val);
}

 template <class _Ty>
struct alignment_of : integral_constant<size_t, alignof(_Ty)> {};  
template <class _Ty>
inline constexpr size_t alignment_of_v = alignof(_Ty);

 template <class _Ty, size_t _Len>
union _Align_type {      _Ty _Val;
    char _Pad[_Len];
};

template <size_t _Len, size_t _Align, class _Ty, bool _Ok>
struct _Aligned;  
template <size_t _Len, size_t _Align, class _Ty>
struct _Aligned<_Len, _Align, _Ty, true> {
    using type = _Align_type<_Ty, _Len>;
};

template <size_t _Len, size_t _Align>
struct _Aligned<_Len, _Align, double, false> {
    static_assert(_Always_false<_Aligned>,
        "You\'ve instantiated std::aligned_storage<Len, Align> with an extended alignment (in other words, Align > alignof(max_align_t)). Before VS 2017 15.8, the member \"type\" would non-conformingly have an alignment of only alignof(max_align_t). VS 2017 15.8 was fixed to handle this correctly, but the fix inherently changes layout and breaks binary compatibility (*only* for uses of aligned_storage with extended alignments). Please define either (1) _ENABLE_EXTENDED_ALIGNED_STORAGE to acknowledge that you understand this message and that you actually want a type with an extended alignment, or (2) _DISABLE_EXTENDED_ALIGNED_STORAGE to silence this message and get the old non-conforming behavior.");
    using type = _Align_type<max_align_t, _Len>;
};

template <size_t _Len, size_t _Align>
struct _Aligned<_Len, _Align, int, false> {
    using _Next                 = double;
    static constexpr bool _Fits = _Align <= alignof(_Next);
    using type                  = typename _Aligned<_Len, _Align, _Next, _Fits>::type;
};

template <size_t _Len, size_t _Align>
struct _Aligned<_Len, _Align, short, false> {
    using _Next                 = int;
    static constexpr bool _Fits = _Align <= alignof(_Next);
    using type                  = typename _Aligned<_Len, _Align, _Next, _Fits>::type;
};

template <size_t _Len, size_t _Align>
struct _Aligned<_Len, _Align, char, false> {
    using _Next                 = short;
    static constexpr bool _Fits = _Align <= alignof(_Next);
    using type                  = typename _Aligned<_Len, _Align, _Next, _Fits>::type;
};

template <size_t _Len, size_t _Align = alignof(max_align_t)>
struct aligned_storage {      using _Next                 = char;
    static constexpr bool _Fits = _Align <= alignof(_Next);
    using type                  = typename _Aligned<_Len, _Align, _Next, _Fits>::type;
};

template <size_t _Len, size_t _Align = alignof(max_align_t)>
using aligned_storage_t = typename aligned_storage<_Len, _Align>::type;

 template <size_t... _Vals>
struct _Maximum;

template <>
struct _Maximum<> : integral_constant<size_t, 0> {};  
template <size_t _Val>
struct _Maximum<_Val> : integral_constant<size_t, _Val> {};  
template <size_t _First, size_t _Second, size_t... _Rest>
struct _Maximum<_First, _Second, _Rest...> : _Maximum<(_First < _Second ? _Second : _First), _Rest...>::type {
     };

template <size_t _Len, class... _Types>
struct aligned_union {      static constexpr size_t _Max_len        = _Maximum<_Len, sizeof(_Types)...>::value;      static constexpr size_t alignment_value = _Maximum<alignof(_Types)...>::value;

    using type = aligned_storage_t<_Max_len, alignment_value>;
};

template <size_t _Len, class... _Types>
using aligned_union_t = typename aligned_union<_Len, _Types...>::type;

 template <class _Ty, bool = is_enum_v<_Ty>>
struct _Underlying_type {
    using type = __underlying_type(_Ty);
};

template <class _Ty>
struct _Underlying_type<_Ty, false> {};

template <class _Ty>
struct underlying_type : _Underlying_type<_Ty> {};  
template <class _Ty>
using underlying_type_t = typename _Underlying_type<_Ty>::type;

 template <class _Ty>
inline constexpr size_t rank_v = 0;  
template <class _Ty, size_t _Nx>
inline constexpr size_t rank_v<_Ty[_Nx]> = rank_v<_Ty> + 1;

template <class _Ty>
inline constexpr size_t rank_v<_Ty[]> = rank_v<_Ty> + 1;

template <class _Ty>
struct rank : integral_constant<size_t, rank_v<_Ty>> {};

 template <class _Ty, unsigned int _Ix = 0>
inline constexpr size_t extent_v = 0;  
template <class _Ty, size_t _Nx>
inline constexpr size_t extent_v<_Ty[_Nx], 0> = _Nx;

template <class _Ty, unsigned int _Ix, size_t _Nx>
inline constexpr size_t extent_v<_Ty[_Nx], _Ix> = extent_v<_Ty, _Ix - 1>;

template <class _Ty, unsigned int _Ix>
inline constexpr size_t extent_v<_Ty[], _Ix> = extent_v<_Ty, _Ix - 1>;

template <class _Ty, unsigned int _Ix = 0>
struct extent : integral_constant<size_t, extent_v<_Ty, _Ix>> {};

 template <class _Base, class _Derived>
struct is_base_of : bool_constant<__is_base_of(_Base, _Derived)> {
     };

template <class _Base, class _Derived>
inline constexpr bool is_base_of_v = __is_base_of(_Base, _Derived);

 template <class _Ty>
struct decay {      using _Ty1 = remove_reference_t<_Ty>;
    using _Ty2 = typename _Select<is_function_v<_Ty1>>::template _Apply<add_pointer<_Ty1>, remove_cv<_Ty1>>;
    using type = typename _Select<is_array_v<_Ty1>>::template _Apply<add_pointer<remove_extent_t<_Ty1>>, _Ty2>::type;
};

template <class _Ty>
using decay_t = typename decay<_Ty>::type;

 template <class _Ty1, class _Ty2>
using _Conditional_type = decltype(false ? ::std:: declval<_Ty1>() : ::std:: declval<_Ty2>());

 template <class _Ty1, class _Ty2, class = void>
struct _Const_lvalue_cond_oper {};

  template <class _Ty1, class _Ty2>
struct _Const_lvalue_cond_oper<_Ty1, _Ty2, void_t<_Conditional_type<const _Ty1&, const _Ty2&>>> {
    using type = remove_cvref_t<_Conditional_type<const _Ty1&, const _Ty2&>>;
};

template <class _Ty1, class _Ty2, class = void>
struct _Decayed_cond_oper : _Const_lvalue_cond_oper<_Ty1, _Ty2> {};

template <class _Ty1, class _Ty2>
struct _Decayed_cond_oper<_Ty1, _Ty2, void_t<_Conditional_type<_Ty1, _Ty2>>> {
    using type = decay_t<_Conditional_type<_Ty1, _Ty2>>;
};

template <class... _Ty>
struct common_type;

template <class... _Ty>
using common_type_t = typename common_type<_Ty...>::type;

template <>
struct common_type<> {};

template <class _Ty1>
struct common_type<_Ty1> : common_type<_Ty1, _Ty1> {};

template <class _Ty1, class _Ty2, class _Decayed1 = decay_t<_Ty1>, class _Decayed2 = decay_t<_Ty2>>
struct _Common_type2 : common_type<_Decayed1, _Decayed2> {};

template <class _Ty1, class _Ty2>
struct _Common_type2<_Ty1, _Ty2, _Ty1, _Ty2> : _Decayed_cond_oper<_Ty1, _Ty2> {};

template <class _Ty1, class _Ty2>
struct common_type<_Ty1, _Ty2> : _Common_type2<_Ty1, _Ty2> {};

template <class _Void, class _Ty1, class _Ty2, class... _Rest>
struct _Common_type3 {};

template <class _Ty1, class _Ty2, class... _Rest>
struct _Common_type3<void_t<common_type_t<_Ty1, _Ty2>>, _Ty1, _Ty2, _Rest...>
    : common_type<common_type_t<_Ty1, _Ty2>, _Rest...> {};

template <class _Ty1, class _Ty2, class... _Rest>
struct common_type<_Ty1, _Ty2, _Rest...> : _Common_type3<void, _Ty1, _Ty2, _Rest...> {};

 template <class, class, template <class> class, template <class> class>
struct basic_common_reference {};

 template <class _Ty>
_Ty _Returns_exactly() noexcept;  
 template <class _Ty1, class _Ty2>
using _Cond_res =      decltype(false ? _Returns_exactly<_Ty1>() : _Returns_exactly<_Ty2>());

 template <class _From>
struct _Copy_cv_impl {
    template <class _To>
    using _Apply = _To;
};
template <class _From>
struct _Copy_cv_impl<const _From> {
    template <class _To>
    using _Apply = const _To;
};
template <class _From>
struct _Copy_cv_impl<volatile _From> {
    template <class _To>
    using _Apply = volatile _To;
};
template <class _From>
struct _Copy_cv_impl<const volatile _From> {
    template <class _To>
    using _Apply = const volatile _To;
};
template <class _From, class _To>
using _Copy_cv =      typename _Copy_cv_impl<_From>::template _Apply<_To>;

 template <class _Ty1>
struct _Add_qualifiers {      template <class _Ty2>
    using _Apply = _Copy_cv<_Ty1, _Ty2>;
};
template <class _Ty1>
struct _Add_qualifiers<_Ty1&> {
    template <class _Ty2>
    using _Apply = add_lvalue_reference_t<_Copy_cv<_Ty1, _Ty2>>;
};
template <class _Ty1>
struct _Add_qualifiers<_Ty1&&> {
    template <class _Ty2>
    using _Apply = add_rvalue_reference_t<_Copy_cv<_Ty1, _Ty2>>;
};

 template <class...>
struct common_reference;

 template <class... _Types>
using common_reference_t = typename common_reference<_Types...>::type;

 template <>
struct common_reference<> {};

 template <class _Ty>
struct common_reference<_Ty> {
    using type = _Ty;
};

 
  template <class _Ty1, class _Ty2, class = void>
struct _Common_reference2C : common_type<_Ty1, _Ty2> {};

 template <class _Ty1, class _Ty2>
struct _Common_reference2C<_Ty1, _Ty2, void_t<_Cond_res<_Ty1, _Ty2>>> {
    using type = _Cond_res<_Ty1, _Ty2>;
};

 template <class _Ty1, class _Ty2>
using _Basic_specialization = typename basic_common_reference<remove_cvref_t<_Ty1>, remove_cvref_t<_Ty2>,
    _Add_qualifiers<_Ty1>::template _Apply, _Add_qualifiers<_Ty2>::template _Apply>::type;

template <class _Ty1, class _Ty2, class = void>
struct _Common_reference2B : _Common_reference2C<_Ty1, _Ty2> {};

template <class _Ty1, class _Ty2>
struct _Common_reference2B<_Ty1, _Ty2, void_t<_Basic_specialization<_Ty1, _Ty2>>> {
    using type = _Basic_specialization<_Ty1, _Ty2>;
};

 template <class _Ty1, class _Ty2, class = void>
struct _Common_reference2A : _Common_reference2B<_Ty1, _Ty2> {};

template <class _Ty1, class _Ty2, class _Result = _Cond_res<_Copy_cv<_Ty1, _Ty2>&, _Copy_cv<_Ty2, _Ty1>&>,
    enable_if_t<is_lvalue_reference_v<_Result>, int> = 0>
using _LL_common_ref = _Result;

template <class _Ty1, class _Ty2>
struct _Common_reference2A<_Ty1&, _Ty2&, void_t<_LL_common_ref<_Ty1, _Ty2>>> {
    using type = _LL_common_ref<_Ty1, _Ty2>;  };

template <class _Ty1, class _Ty2>
struct _Common_reference2A<_Ty1&&, _Ty2&, enable_if_t<is_convertible_v<_Ty1&&, _LL_common_ref<const _Ty1, _Ty2>>>> {
    using type = _LL_common_ref<const _Ty1, _Ty2>;  };

template <class _Ty1, class _Ty2>
struct _Common_reference2A<_Ty1&, _Ty2&&, enable_if_t<is_convertible_v<_Ty2&&, _LL_common_ref<const _Ty2, _Ty1>>>> {
    using type = _LL_common_ref<const _Ty2, _Ty1>;  };

template <class _Ty1, class _Ty2>
using _RR_common_ref = remove_reference_t<_LL_common_ref<_Ty1, _Ty2>>&&;

template <class _Ty1, class _Ty2>
struct _Common_reference2A<_Ty1&&, _Ty2&&,
    enable_if_t<
        is_convertible_v<_Ty1&&, _RR_common_ref<_Ty1, _Ty2>> && is_convertible_v<_Ty2&&, _RR_common_ref<_Ty1, _Ty2>>>> {
    using type = _RR_common_ref<_Ty1, _Ty2>;  };

template <class _Ty1, class _Ty2>
struct common_reference<_Ty1, _Ty2> : _Common_reference2A<_Ty1, _Ty2> {};

 template <class _Void, class _Ty1, class _Ty2, class... _Types>
struct _Fold_common_reference {};
template <class _Ty1, class _Ty2, class... _Types>
struct _Fold_common_reference<void_t<common_reference_t<_Ty1, _Ty2>>, _Ty1, _Ty2, _Types...>
    : common_reference<common_reference_t<_Ty1, _Ty2>, _Types...> {};

template <class _Ty1, class _Ty2, class _Ty3, class... _Rest>
struct common_reference<_Ty1, _Ty2, _Ty3, _Rest...> : _Fold_common_reference<void, _Ty1, _Ty2, _Ty3, _Rest...> {};

 template <class _Ty>
struct _Identity {
    using type = _Ty;
};
template <class _Ty>
using _Identity_t = typename _Identity<_Ty>::type;

 template <class _Ty>
struct type_identity {
    using type = _Ty;
};
template <class _Ty>
using type_identity_t = typename type_identity<_Ty>::type;

 template <class _Type, template <class...> class _Template>
inline constexpr bool _Is_specialization_v = false;  template <template <class...> class _Template, class... _Types>
inline constexpr bool _Is_specialization_v<_Template<_Types...>, _Template> = true;

template <class _Type, template <class...> class _Template>
struct _Is_specialization : bool_constant<_Is_specialization_v<_Type, _Template>> {};

 template <class _Ty>
 constexpr _Ty&& forward(
    remove_reference_t<_Ty>& _Arg) noexcept {      return static_cast<_Ty&&>(_Arg);
}

template <class _Ty>
 constexpr _Ty&& forward(remove_reference_t<_Ty>&& _Arg) noexcept {      static_assert(!is_lvalue_reference_v<_Ty>, "bad forward call");
    return static_cast<_Ty&&>(_Arg);
}

 template <class _Ty>
 constexpr remove_reference_t<_Ty>&& move(_Ty&& _Arg) noexcept {      return static_cast<remove_reference_t<_Ty>&&>(_Arg);
}

 template <class _Ty>
 constexpr conditional_t<!is_nothrow_move_constructible_v<_Ty> && is_copy_constructible_v<_Ty>, const _Ty&,
    _Ty&&>
    move_if_noexcept(_Ty& _Arg) noexcept {      return ::std:: move(_Arg);
}

template <class _Ty>
class reference_wrapper;

   
 enum class _Invoker_strategy {
    _Functor,
    _Pmf_object,
    _Pmf_refwrap,
    _Pmf_pointer,
    _Pmd_object,
    _Pmd_refwrap,
    _Pmd_pointer
};

struct _Invoker_functor {
    static constexpr _Invoker_strategy _Strategy = _Invoker_strategy::_Functor;

    template <class _Callable, class... _Types>
    static constexpr auto _Call(_Callable&& _Obj, _Types&&... _Args) noexcept(
        noexcept(static_cast<_Callable&&>(_Obj)(static_cast<_Types&&>(_Args)...)))
        -> decltype(static_cast<_Callable&&>(_Obj)(static_cast<_Types&&>(_Args)...)) {
        return static_cast<_Callable&&>(_Obj)(static_cast<_Types&&>(_Args)...);
    }
};

struct _Invoker_pmf_object {
    static constexpr _Invoker_strategy _Strategy = _Invoker_strategy::_Pmf_object;

    template <class _Decayed, class _Ty1, class... _Types2>
    static constexpr auto _Call(_Decayed _Pmf, _Ty1&& _Arg1, _Types2&&... _Args2) noexcept(
        noexcept((static_cast<_Ty1&&>(_Arg1).*_Pmf)(static_cast<_Types2&&>(_Args2)...)))
        -> decltype((static_cast<_Ty1&&>(_Arg1).*_Pmf)(static_cast<_Types2&&>(_Args2)...)) {
        return (static_cast<_Ty1&&>(_Arg1).*_Pmf)(static_cast<_Types2&&>(_Args2)...);
    }
};

struct _Invoker_pmf_refwrap {
    static constexpr _Invoker_strategy _Strategy = _Invoker_strategy::_Pmf_refwrap;

    template <class _Decayed, class _Refwrap, class... _Types2>
    static constexpr auto _Call(_Decayed _Pmf, _Refwrap _Rw, _Types2&&... _Args2) noexcept(
        noexcept((_Rw.get().*_Pmf)(static_cast<_Types2&&>(_Args2)...)))
        -> decltype((_Rw.get().*_Pmf)(static_cast<_Types2&&>(_Args2)...)) {
        return (_Rw.get().*_Pmf)(static_cast<_Types2&&>(_Args2)...);
    }
};

struct _Invoker_pmf_pointer {
    static constexpr _Invoker_strategy _Strategy = _Invoker_strategy::_Pmf_pointer;

    template <class _Decayed, class _Ty1, class... _Types2>
    static constexpr auto _Call(_Decayed _Pmf, _Ty1&& _Arg1, _Types2&&... _Args2) noexcept(
        noexcept(((*static_cast<_Ty1&&>(_Arg1)).*_Pmf)(static_cast<_Types2&&>(_Args2)...)))
        -> decltype(((*static_cast<_Ty1&&>(_Arg1)).*_Pmf)(static_cast<_Types2&&>(_Args2)...)) {
        return ((*static_cast<_Ty1&&>(_Arg1)).*_Pmf)(static_cast<_Types2&&>(_Args2)...);
    }
};

struct _Invoker_pmd_object {
    static constexpr _Invoker_strategy _Strategy = _Invoker_strategy::_Pmd_object;

    template <class _Decayed, class _Ty1>
    static constexpr auto _Call(_Decayed _Pmd, _Ty1&& _Arg1) noexcept -> decltype(static_cast<_Ty1&&>(_Arg1).*_Pmd) {
        return static_cast<_Ty1&&>(_Arg1).*_Pmd;
    }
};

struct _Invoker_pmd_refwrap {
    static constexpr _Invoker_strategy _Strategy = _Invoker_strategy::_Pmd_refwrap;

    template <class _Decayed, class _Refwrap>
    static constexpr auto _Call(_Decayed _Pmd, _Refwrap _Rw) noexcept -> decltype(_Rw.get().*_Pmd) {
        return _Rw.get().*_Pmd;
    }
};

struct _Invoker_pmd_pointer {
    static constexpr _Invoker_strategy _Strategy = _Invoker_strategy::_Pmd_pointer;

    template <class _Decayed, class _Ty1>
    static constexpr auto _Call(_Decayed _Pmd, _Ty1&& _Arg1) noexcept(noexcept((*static_cast<_Ty1&&>(_Arg1)).*_Pmd))
        -> decltype((*static_cast<_Ty1&&>(_Arg1)).*_Pmd) {
        return (*static_cast<_Ty1&&>(_Arg1)).*_Pmd;
    }
};

template <class _Callable, class _Ty1, class _Removed_cvref = _Remove_cvref_t<_Callable>,
    bool _Is_pmf = is_member_function_pointer_v<_Removed_cvref>,
    bool _Is_pmd = is_member_object_pointer_v<_Removed_cvref>>
struct _Invoker1;

template <class _Callable, class _Ty1, class _Removed_cvref>
struct _Invoker1<_Callable, _Ty1, _Removed_cvref, true, false>
    : conditional_t<is_base_of_v<typename _Is_memfunptr<_Removed_cvref>::_Class_type, remove_reference_t<_Ty1>>,
          _Invoker_pmf_object,
          conditional_t<_Is_specialization_v<_Remove_cvref_t<_Ty1>, reference_wrapper>, _Invoker_pmf_refwrap,
              _Invoker_pmf_pointer>> {};  
template <class _Callable, class _Ty1, class _Removed_cvref>
struct _Invoker1<_Callable, _Ty1, _Removed_cvref, false, true>
    : conditional_t<
          is_base_of_v<typename _Is_member_object_pointer<_Removed_cvref>::_Class_type, remove_reference_t<_Ty1>>,
          _Invoker_pmd_object,
          conditional_t<_Is_specialization_v<_Remove_cvref_t<_Ty1>, reference_wrapper>, _Invoker_pmd_refwrap,
              _Invoker_pmd_pointer>> {};  
template <class _Callable, class _Ty1, class _Removed_cvref>
struct _Invoker1<_Callable, _Ty1, _Removed_cvref, false, false> : _Invoker_functor {};

template <class _Callable>
constexpr auto invoke(_Callable&& _Obj) noexcept(noexcept(static_cast<_Callable&&>(_Obj)()))
    -> decltype(static_cast<_Callable&&>(_Obj)()) {
    return static_cast<_Callable&&>(_Obj)();
}

template <class _Callable, class _Ty1, class... _Types2>
constexpr auto invoke(_Callable&& _Obj, _Ty1&& _Arg1, _Types2&&... _Args2) noexcept(
    noexcept(_Invoker1<_Callable, _Ty1>::_Call(
        static_cast<_Callable&&>(_Obj), static_cast<_Ty1&&>(_Arg1), static_cast<_Types2&&>(_Args2)...)))
    -> decltype(_Invoker1<_Callable, _Ty1>::_Call(
        static_cast<_Callable&&>(_Obj), static_cast<_Ty1&&>(_Arg1), static_cast<_Types2&&>(_Args2)...)) {
    if constexpr (_Invoker1<_Callable, _Ty1>::_Strategy == _Invoker_strategy::_Functor) {
        return static_cast<_Callable&&>(_Obj)(static_cast<_Ty1&&>(_Arg1), static_cast<_Types2&&>(_Args2)...);
    } else if constexpr (_Invoker1<_Callable, _Ty1>::_Strategy == _Invoker_strategy::_Pmf_object) {
        return (static_cast<_Ty1&&>(_Arg1).*_Obj)(static_cast<_Types2&&>(_Args2)...);
    } else if constexpr (_Invoker1<_Callable, _Ty1>::_Strategy == _Invoker_strategy::_Pmf_refwrap) {
        return (_Arg1.get().*_Obj)(static_cast<_Types2&&>(_Args2)...);
    } else if constexpr (_Invoker1<_Callable, _Ty1>::_Strategy == _Invoker_strategy::_Pmf_pointer) {
        return ((*static_cast<_Ty1&&>(_Arg1)).*_Obj)(static_cast<_Types2&&>(_Args2)...);
    } else if constexpr (_Invoker1<_Callable, _Ty1>::_Strategy == _Invoker_strategy::_Pmd_object) {
        return static_cast<_Ty1&&>(_Arg1).*_Obj;
    } else if constexpr (_Invoker1<_Callable, _Ty1>::_Strategy == _Invoker_strategy::_Pmd_refwrap) {
        return _Arg1.get().*_Obj;
    } else {
        static_assert(_Invoker1<_Callable, _Ty1>::_Strategy == _Invoker_strategy::_Pmd_pointer, "bug in invoke");
        return (*static_cast<_Ty1&&>(_Arg1)).*_Obj;
    }
}

 

template <class _To>
void _Implicitly_convert_to(_To) noexcept;  
template <class _From, class _To, bool = is_convertible_v<_From, _To>, bool = is_void_v<_To>>
inline constexpr bool _Is_nothrow_convertible_v = noexcept(_Implicitly_convert_to<_To>(::std:: declval<_From>()));



template <class _From, class _To, bool _IsVoid>
inline constexpr bool _Is_nothrow_convertible_v<_From, _To, false, _IsVoid> = false;

template <class _From, class _To>
inline constexpr bool _Is_nothrow_convertible_v<_From, _To, true, true> = true;

template <class _From, class _To>
struct _Is_nothrow_convertible : bool_constant<_Is_nothrow_convertible_v<_From, _To>> {
     };

template <class _From, class _To>
inline constexpr bool is_nothrow_convertible_v = _Is_nothrow_convertible_v<_From, _To>;

template <class _From, class _To>
using is_nothrow_convertible = _Is_nothrow_convertible<_From, _To>;

template <class _Ty>
_Ty _Returns_exactly() noexcept;  
template <class _From, class _To, class = void>
struct _Invoke_convertible : false_type {};

template <class _From, class _To>
struct _Invoke_convertible<_From, _To, void_t<decltype(_Implicitly_convert_to<_To>(_Returns_exactly<_From>()))>>
    : true_type {};

template <class _From, class _To>
struct _Invoke_nothrow_convertible : bool_constant<noexcept(_Implicitly_convert_to<_To>(_Returns_exactly<_From>()))> {};

template <class _Result, bool _Nothrow>
struct _Invoke_traits_common {
    using type                  = _Result;
    using _Is_invocable         = true_type;
    using _Is_nothrow_invocable = bool_constant<_Nothrow>;
    template <class _Rx>
    using _Is_invocable_r = bool_constant<disjunction_v<is_void<_Rx>, _Invoke_convertible<type, _Rx>>>;
    template <class _Rx>
    using _Is_nothrow_invocable_r = bool_constant<conjunction_v<_Is_nothrow_invocable,
        disjunction<is_void<_Rx>,
            conjunction<_Invoke_convertible<type, _Rx>, _Invoke_nothrow_convertible<type, _Rx>>>>>;
};

template <class _Void, class _Callable>
struct _Invoke_traits_zero {
         using _Is_invocable         = false_type;
    using _Is_nothrow_invocable = false_type;
    template <class _Rx>
    using _Is_invocable_r = false_type;
    template <class _Rx>
    using _Is_nothrow_invocable_r = false_type;
};

template <class _Callable>
using _Decltype_invoke_zero = decltype(::std:: declval<_Callable>()());

template <class _Callable>
struct _Invoke_traits_zero<void_t<_Decltype_invoke_zero<_Callable>>, _Callable>
    : _Invoke_traits_common<_Decltype_invoke_zero<_Callable>, noexcept(::std:: declval<_Callable>()())> {};

template <class _Void, class... _Types>
struct _Invoke_traits_nonzero {
         using _Is_invocable         = false_type;
    using _Is_nothrow_invocable = false_type;
    template <class _Rx>
    using _Is_invocable_r = false_type;
    template <class _Rx>
    using _Is_nothrow_invocable_r = false_type;
};

template <class _Callable, class _Ty1, class... _Types2>
using _Decltype_invoke_nonzero = decltype(
    _Invoker1<_Callable, _Ty1>::_Call(::std:: declval<_Callable>(), ::std:: declval<_Ty1>(), ::std:: declval<_Types2>()...));

template <class _Callable, class _Ty1, class... _Types2>
struct _Invoke_traits_nonzero<void_t<_Decltype_invoke_nonzero<_Callable, _Ty1, _Types2...>>, _Callable, _Ty1,
    _Types2...> : _Invoke_traits_common<_Decltype_invoke_nonzero<_Callable, _Ty1, _Types2...>,
                      noexcept(_Invoker1<_Callable, _Ty1>::_Call(
                          ::std:: declval<_Callable>(), ::std:: declval<_Ty1>(), ::std:: declval<_Types2>()...))> {};

template <class _Callable, class... _Args>
using _Select_invoke_traits = conditional_t<sizeof...(_Args) == 0, _Invoke_traits_zero<void, _Callable>,
    _Invoke_traits_nonzero<void, _Callable, _Args...>>;


template <class _Callable, class... _Args>
using _Invoke_result_t = typename _Select_invoke_traits<_Callable, _Args...>::type;

template <class _Rx, class _Callable, class... _Args>
using _Is_invocable_r_ = typename _Select_invoke_traits<_Callable, _Args...>::template _Is_invocable_r<_Rx>;

template <class _Rx, class _Callable, class... _Args>
struct _Is_invocable_r : _Is_invocable_r_<_Rx, _Callable, _Args...> {
     };

 template <class _Callable, class... _Args>
struct invoke_result : _Select_invoke_traits<_Callable, _Args...> {
     };

template <class _Callable, class... _Args>
using invoke_result_t = typename _Select_invoke_traits<_Callable, _Args...>::type;

 template <class _Callable, class... _Args>
struct is_invocable : _Select_invoke_traits<_Callable, _Args...>::_Is_invocable {
     };

template <class _Callable, class... _Args>
inline constexpr bool is_invocable_v = _Select_invoke_traits<_Callable, _Args...>::_Is_invocable::value;

 template <class _Callable, class... _Args>
struct is_nothrow_invocable : _Select_invoke_traits<_Callable, _Args...>::_Is_nothrow_invocable {
     };

template <class _Callable, class... _Args>
inline constexpr bool is_nothrow_invocable_v = _Select_invoke_traits<_Callable, _Args...>::_Is_nothrow_invocable::value;

 template <class _Rx, class _Callable, class... _Args>
struct is_invocable_r : _Is_invocable_r_<_Rx, _Callable, _Args...> {
     };

template <class _Rx, class _Callable, class... _Args>
inline constexpr bool is_invocable_r_v = _Is_invocable_r_<_Rx, _Callable, _Args...>::value;

 template <class _Rx, class _Callable, class... _Args>
struct is_nothrow_invocable_r : _Select_invoke_traits<_Callable, _Args...>::template _Is_nothrow_invocable_r<_Rx> {
     };

template <class _Rx, class _Callable, class... _Args>
inline constexpr bool is_nothrow_invocable_r_v =
    _Select_invoke_traits<_Callable, _Args...>::template _Is_nothrow_invocable_r<_Rx>::value;

 template <class _Ty>
struct _Function_args {};  

template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };             template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };        template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };     template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };           template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };             template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };        template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };     template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };          template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };             template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };        template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };     template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };             template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };        template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };     template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };           template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };             template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };        template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };     template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };          template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };             template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };        template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };     template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };                                                 template <class _Ret, class... _Types>                                                                    struct _Function_args<_Ret CALL_OPT(_Types...) CV_OPT REF_OPT NOEXCEPT_OPT> : _Arg_types<_Types...> {         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                     };


template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                       template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                                 template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                              template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                        template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                                     template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                                template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                             template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                       template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                                    template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                               template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                            template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                      template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                              template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                        template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                     template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };               template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                             template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                       template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                    template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };              template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                            template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                      template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };                   template <class _Ret, class... _Types>                                                                          struct _Function_args<_Ret(_Types..., ...) CV_REF_NOEXCEPT_OPT> {           [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Ret _Unnameable_result;                                           };

template <class _Ty, class = void>
struct _Weak_result_type {};  
                 __pragma(warning(disable : 4996))
template <class _Ty>
struct _Weak_result_type<_Ty, void_t<typename _Ty::result_type>> {      [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef typename _Ty::result_type _Unnameable_result;
};


template <class _Ty, class = void>
struct _Weak_argument_type : _Weak_result_type<_Ty> {};  
                 __pragma(warning(disable : 4996))
template <class _Ty>
struct _Weak_argument_type<_Ty, void_t<typename _Ty::argument_type>> : _Weak_result_type<_Ty> {
         [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef typename _Ty::argument_type _Unnameable_argument;
};


template <class _Ty, class = void>
struct _Weak_binary_args : _Weak_argument_type<_Ty> {};  
                 __pragma(warning(disable : 4996))
template <class _Ty>
struct _Weak_binary_args<_Ty, void_t<typename _Ty::first_argument_type,
                                  typename _Ty::second_argument_type>>
    : _Weak_argument_type<_Ty> {      [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef typename _Ty::first_argument_type _Unnameable_first_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef typename _Ty::second_argument_type _Unnameable_second_argument;
};


template <class _Ty>
using _Weak_types = conditional_t<is_function_v<remove_pointer_t<_Ty>>, _Function_args<remove_pointer_t<_Ty>>,
    conditional_t<is_member_function_pointer_v<_Ty>, _Is_memfunptr<remove_cv_t<_Ty>>, _Weak_binary_args<_Ty>>>;

 template <class _Ty>
void _Refwrap_ctor_fun(_Identity_t<_Ty&>) noexcept;
template <class _Ty>
void _Refwrap_ctor_fun(_Identity_t<_Ty&&>) = delete;

template <class _Ty, class _Uty, class = void>
struct _Refwrap_has_ctor_from : false_type {};

template <class _Ty, class _Uty>
struct _Refwrap_has_ctor_from<_Ty, _Uty, void_t<decltype(_Refwrap_ctor_fun<_Ty>(::std:: declval<_Uty>()))>> : true_type {};

template <class _Ty>
class reference_wrapper
{
public:
    static_assert(is_object_v<_Ty> || is_function_v<_Ty>,
        "reference_wrapper<T> requires T to be an object type or a function type.");

    using type = _Ty;

    template <class _Uty, enable_if_t<conjunction_v<negation<is_same<_Remove_cvref_t<_Uty>, reference_wrapper>>,
                                          _Refwrap_has_ctor_from<_Ty, _Uty>>,
                              int> = 0>
    constexpr reference_wrapper(_Uty&& _Val) noexcept(noexcept(_Refwrap_ctor_fun<_Ty>(::std:: declval<_Uty>()))) {
        _Ty& _Ref = static_cast<_Uty&&>(_Val);
        _Ptr      = ::std:: addressof(_Ref);
    }

    constexpr operator _Ty&() const noexcept {
        return *_Ptr;
    }

     constexpr _Ty& get() const noexcept {
        return *_Ptr;
    }

private:
    _Ty* _Ptr{};

public:
    template <class... _Types>
    constexpr auto operator()(_Types&&... _Args) const
        noexcept(noexcept(::std:: invoke(*_Ptr, static_cast<_Types&&>(_Args)...)))          -> decltype(::std:: invoke(*_Ptr, static_cast<_Types&&>(_Args)...)) {
        return ::std:: invoke(*_Ptr, static_cast<_Types&&>(_Args)...);
    }
};

template <class _Ty>
reference_wrapper(_Ty&) -> reference_wrapper<_Ty>;

 template <class _Ty>
 constexpr reference_wrapper<_Ty> ref(_Ty& _Val) noexcept {
    return reference_wrapper<_Ty>(_Val);
}

template <class _Ty>
void ref(const _Ty&&) = delete;

template <class _Ty>
 constexpr reference_wrapper<_Ty> ref(reference_wrapper<_Ty> _Val) noexcept {
    return ::std:: ref(_Val.get());
}

template <class _Ty>
 constexpr reference_wrapper<const _Ty> cref(const _Ty& _Val) noexcept {
    return reference_wrapper<const _Ty>(_Val);
}

template <class _Ty>
void cref(const _Ty&&) = delete;

template <class _Ty>
 constexpr reference_wrapper<const _Ty> cref(reference_wrapper<_Ty> _Val) noexcept {
    return ::std:: cref(_Val.get());
}

 template <class _Ty>
struct unwrap_reference {
    using type = _Ty;
};
template <class _Ty>
struct unwrap_reference<reference_wrapper<_Ty>> {
    using type = _Ty&;
};
template <class _Ty>
using unwrap_reference_t = typename unwrap_reference<_Ty>::type;

 template <class _Ty>
using unwrap_ref_decay_t = unwrap_reference_t<decay_t<_Ty>>;
template <class _Ty>
struct unwrap_ref_decay {
    using type = unwrap_ref_decay_t<_Ty>;
};

 template <class _Ty>
struct _Is_swappable;

 template <class _Ty>
struct _Is_nothrow_swappable;

 template <class _Ty, enable_if_t<is_move_constructible_v<_Ty> && is_move_assignable_v<_Ty>, int> = 0>
constexpr void swap(_Ty&, _Ty&) noexcept(is_nothrow_move_constructible_v<_Ty>&& is_nothrow_move_assignable_v<_Ty>);

template <class _Ty, size_t _Size, enable_if_t<_Is_swappable<_Ty>::value, int> = 0>
constexpr void swap(_Ty (&)[_Size], _Ty (&)[_Size]) noexcept(_Is_nothrow_swappable<_Ty>::value);

 template <class _Ty1, class _Ty2, class = void>
struct _Swappable_with_helper : false_type {};  
template <class _Ty1, class _Ty2>
struct _Swappable_with_helper<_Ty1, _Ty2, void_t<decltype(swap(::std:: declval<_Ty1>(), ::std:: declval<_Ty2>()))>>
    : true_type {};  
 template <class _Ty1, class _Ty2>
struct _Is_swappable_with
    : bool_constant<conjunction_v<_Swappable_with_helper<_Ty1, _Ty2>, _Swappable_with_helper<_Ty2, _Ty1>>> {
     };

 template <class _Ty>
struct _Is_swappable : _Is_swappable_with<add_lvalue_reference_t<_Ty>, add_lvalue_reference_t<_Ty>>::type {
     };

 template <class _Ty1, class _Ty2>
struct _Swap_cannot_throw : bool_constant<noexcept(swap(::std:: declval<_Ty1>(), ::std:: declval<_Ty2>()))                                      && noexcept(swap(::std:: declval<_Ty2>(), ::std:: declval<_Ty1>()))> {
          };

 template <class _Ty1, class _Ty2>
struct _Is_nothrow_swappable_with
    : bool_constant<conjunction_v<_Is_swappable_with<_Ty1, _Ty2>, _Swap_cannot_throw<_Ty1, _Ty2>>> {
          };

 template <class _Ty>
struct _Is_nothrow_swappable
    : _Is_nothrow_swappable_with<add_lvalue_reference_t<_Ty>, add_lvalue_reference_t<_Ty>>::type {
     };

 template <class _Ty1, class _Ty2>
struct is_swappable_with : _Is_swappable_with<_Ty1, _Ty2>::type {
          };

template <class _Ty1, class _Ty2>
inline constexpr bool is_swappable_with_v =
    conjunction_v<_Swappable_with_helper<_Ty1, _Ty2>, _Swappable_with_helper<_Ty2, _Ty1>>;

 template <class _Ty>
struct is_swappable : _Is_swappable<_Ty>::type {};  
template <class _Ty>
inline constexpr bool is_swappable_v = _Is_swappable<_Ty>::value;

 template <class _Ty1, class _Ty2>
struct is_nothrow_swappable_with : _Is_nothrow_swappable_with<_Ty1, _Ty2>::type {
          };

template <class _Ty1, class _Ty2>
inline constexpr bool is_nothrow_swappable_with_v = _Is_nothrow_swappable_with<_Ty1, _Ty2>::value;

 template <class _Ty>
struct is_nothrow_swappable : _Is_nothrow_swappable<_Ty>::type {
     };

template <class _Ty>
inline constexpr bool is_nothrow_swappable_v = _Is_nothrow_swappable<_Ty>::value;

 namespace _Has_ADL_swap_detail {
    void swap();  
    template <class, class = void>
    struct _Has_ADL_swap : false_type {};
    template <class _Ty>
    struct _Has_ADL_swap<_Ty, void_t<decltype(swap(::std:: declval<_Ty&>(), ::std:: declval<_Ty&>()))>> : true_type {};
}  using _Has_ADL_swap_detail::_Has_ADL_swap;

template <class _Ty>
inline constexpr bool _Is_trivially_swappable_v = conjunction_v<is_trivially_destructible<_Ty>,
    is_trivially_move_constructible<_Ty>, is_trivially_move_assignable<_Ty>, negation<_Has_ADL_swap<_Ty>>>;

template <class _Ty>
struct _Is_trivially_swappable : bool_constant<_Is_trivially_swappable_v<_Ty>> {
     };

 
   inline constexpr size_t _FNV_offset_basis = 14695981039346656037ULL;
inline constexpr size_t _FNV_prime        = 1099511628211ULL;

 inline size_t _Fnv1a_append_bytes(size_t _Val, const unsigned char* const _First,
    const size_t _Count) noexcept {      for (size_t _Idx = 0; _Idx < _Count; ++_Idx) {
        _Val ^= static_cast<size_t>(_First[_Idx]);
        _Val *= _FNV_prime;
    }

    return _Val;
}

template <class _Ty>
 size_t _Fnv1a_append_range(const size_t _Val, const _Ty* const _First,
    const _Ty* const _Last) noexcept {      static_assert(is_trivial_v<_Ty>, "Only trivial types can be directly hashed.");
    const auto _Firstb = reinterpret_cast<const unsigned char*>(_First);
    const auto _Lastb  = reinterpret_cast<const unsigned char*>(_Last);
    return _Fnv1a_append_bytes(_Val, _Firstb, static_cast<size_t>(_Lastb - _Firstb));
}

template <class _Kty>
 size_t _Fnv1a_append_value(
    const size_t _Val, const _Kty& _Keyval) noexcept {      static_assert(is_trivial_v<_Kty>, "Only trivial types can be directly hashed.");
    return _Fnv1a_append_bytes(_Val, &reinterpret_cast<const unsigned char&>(_Keyval), sizeof(_Kty));
}

 template <class _Kty>
 size_t _Hash_representation(const _Kty& _Keyval) noexcept {      return _Fnv1a_append_value(_FNV_offset_basis, _Keyval);
}

 template <class _Kty>
 size_t _Hash_array_representation(
    const _Kty* const _First, const size_t _Count) noexcept {      static_assert(is_trivial_v<_Kty>, "Only trivial types can be directly hashed.");
    return _Fnv1a_append_bytes(
        _FNV_offset_basis, reinterpret_cast<const unsigned char*>(_First), _Count * sizeof(_Kty));
}

 template <class _Kty>
struct hash;

template <class _Kty, bool _Enabled>
struct _Conditionally_enabled_hash {      [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef _Kty _Unnameable_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef size_t _Unnameable_result;

     size_t operator()(const _Kty& _Keyval) const
        noexcept(noexcept(hash<_Kty>::_Do_hash(_Keyval)))   {
        return hash<_Kty>::_Do_hash(_Keyval);
    }
};

template <class _Kty>
struct _Conditionally_enabled_hash<_Kty, false> {      _Conditionally_enabled_hash()                                   = delete;
    _Conditionally_enabled_hash(const _Conditionally_enabled_hash&) = delete;
    _Conditionally_enabled_hash(_Conditionally_enabled_hash&&)      = delete;
    _Conditionally_enabled_hash& operator=(const _Conditionally_enabled_hash&) = delete;
    _Conditionally_enabled_hash& operator=(_Conditionally_enabled_hash&&) = delete;
};

 template <class _Kty>
struct hash
    : _Conditionally_enabled_hash<_Kty,
          !is_const_v<_Kty> && !is_volatile_v<_Kty> && (is_enum_v<_Kty> || is_integral_v<_Kty> || is_pointer_v<_Kty>)> {
         static size_t _Do_hash(const _Kty& _Keyval) noexcept {
        return _Hash_representation(_Keyval);
    }
};

template <>
struct hash<float> {
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef float _Unnameable_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef size_t _Unnameable_result;
     size_t operator()(const float _Keyval) const noexcept {
        return _Hash_representation(_Keyval == 0.0F ? 0.0F : _Keyval);      }
};

template <>
struct hash<double> {
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef double _Unnameable_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef size_t _Unnameable_result;
     size_t operator()(const double _Keyval) const noexcept {
        return _Hash_representation(_Keyval == 0.0 ? 0.0 : _Keyval);      }
};

template <>
struct hash<long double> {
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef long double _Unnameable_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef size_t _Unnameable_result;
     size_t operator()(const long double _Keyval) const noexcept {
        return _Hash_representation(_Keyval == 0.0L ? 0.0L : _Keyval);      }
};

template <>
struct hash<nullptr_t> {
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef nullptr_t _Unnameable_argument;
    [[deprecated(                                                                                                         "warning STL4007: Many result_type typedefs and all argument_type, first_argument_type, and second_argument_type typedefs are deprecated in C++17. You can define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] typedef size_t _Unnameable_result;
     size_t operator()(nullptr_t) const noexcept {
        void* _Null{};
        return _Hash_representation(_Null);
    }
};

 template <class _Kty, class = void>
struct _Is_nothrow_hashable : false_type {};  
template <class _Kty>
struct _Is_nothrow_hashable<_Kty, void_t<decltype(hash<_Kty>{}(::std:: declval<const _Kty&>()))>>
    : bool_constant<noexcept(hash<_Kty>{}(::std:: declval<const _Kty&>()))> {};

 
template <class _FloatingType>
struct _Floating_type_traits;

template <>
struct _Floating_type_traits<float> {
    static constexpr int32_t _Mantissa_bits           = 24;      static constexpr int32_t _Exponent_bits           = 8;      static constexpr int32_t _Maximum_binary_exponent = 127;      static constexpr int32_t _Minimum_binary_exponent = -126;      static constexpr int32_t _Exponent_bias           = 127;
    static constexpr int32_t _Sign_shift              = 31;      static constexpr int32_t _Exponent_shift          = 23;  
    using _Uint_type = uint32_t;

    static constexpr uint32_t _Exponent_mask             = 0x000000FFu;      static constexpr uint32_t _Normal_mantissa_mask      = 0x00FFFFFFu;      static constexpr uint32_t _Denormal_mantissa_mask    = 0x007FFFFFu;      static constexpr uint32_t _Special_nan_mantissa_mask = 0x00400000u;      static constexpr uint32_t _Shifted_sign_mask         = 0x80000000u;      static constexpr uint32_t _Shifted_exponent_mask     = 0x7F800000u;  };

template <>
struct _Floating_type_traits<double> {
    static constexpr int32_t _Mantissa_bits           = 53;      static constexpr int32_t _Exponent_bits           = 11;      static constexpr int32_t _Maximum_binary_exponent = 1023;      static constexpr int32_t _Minimum_binary_exponent = -1022;      static constexpr int32_t _Exponent_bias           = 1023;
    static constexpr int32_t _Sign_shift              = 63;      static constexpr int32_t _Exponent_shift          = 52;  
    using _Uint_type = uint64_t;

    static constexpr uint64_t _Exponent_mask             = 0x00000000000007FFu;      static constexpr uint64_t _Normal_mantissa_mask      = 0x001FFFFFFFFFFFFFu;      static constexpr uint64_t _Denormal_mantissa_mask    = 0x000FFFFFFFFFFFFFu;      static constexpr uint64_t _Special_nan_mantissa_mask = 0x0008000000000000u;      static constexpr uint64_t _Shifted_sign_mask         = 0x8000000000000000u;      static constexpr uint64_t _Shifted_exponent_mask     = 0x7FF0000000000000u;  };

template <>
struct _Floating_type_traits<long double> : _Floating_type_traits<double> {};

 

}



 
  
 
  
 
  

       
              
       
       

extern "C++" {



namespace std
{
    enum class align_val_t : size_t {};
}

    namespace std
    {
        struct nothrow_t {
            explicit nothrow_t() = default;
        };

            extern nothrow_t const nothrow;
    }

     __declspec(allocator)
void* __cdecl operator new(
    size_t _Size
    );

       __declspec(allocator)
void* __cdecl operator new(
    size_t _Size,
    ::std::nothrow_t const&
    ) noexcept;

     __declspec(allocator)
void* __cdecl operator new[](
    size_t _Size
    );

       __declspec(allocator)
void* __cdecl operator new[](
    size_t _Size,
    ::std::nothrow_t const&
    ) noexcept;

void __cdecl operator delete(
    void* _Block
    ) noexcept;

void __cdecl operator delete(
    void* _Block,
    ::std::nothrow_t const&
    ) noexcept;

void __cdecl operator delete[](
    void* _Block
    ) noexcept;

void __cdecl operator delete[](
    void* _Block,
    ::std::nothrow_t const&
    ) noexcept;

void __cdecl operator delete(
    void*  _Block,
    size_t _Size
    ) noexcept;

void __cdecl operator delete[](
    void* _Block,
    size_t _Size
    ) noexcept;

     __declspec(allocator)
void* __cdecl operator new(
    size_t             _Size,
    ::std::align_val_t _Al
    );

       __declspec(allocator)
void* __cdecl operator new(
    size_t                  _Size,
    ::std::align_val_t      _Al,
    ::std::nothrow_t const&
    ) noexcept;


     __declspec(allocator)
void* __cdecl operator new[](
    size_t             _Size,
    ::std::align_val_t _Al
    );

       __declspec(allocator)
void* __cdecl operator new[](
    size_t                  _Size,
    ::std::align_val_t      _Al,
    ::std::nothrow_t const&
    ) noexcept;

void __cdecl operator delete(
    void*              _Block,
    ::std::align_val_t _Al
    ) noexcept;

void __cdecl operator delete(
    void*                   _Block,
    ::std::align_val_t      _Al,
    ::std::nothrow_t const&
    ) noexcept;

void __cdecl operator delete[](
    void*              _Block,
    ::std::align_val_t _Al
    ) noexcept;

void __cdecl operator delete[](
    void*                   _Block,
    ::std::align_val_t      _Al,
    ::std::nothrow_t const&
    ) noexcept;

void __cdecl operator delete(
    void*              _Block,
    size_t             _Size,
    ::std::align_val_t _Al
    ) noexcept;

void __cdecl operator delete[](
    void*              _Block,
    size_t             _Size,
    ::std::align_val_t _Al
    ) noexcept;

          
    inline void* __cdecl operator new(size_t _Size,   void* _Where) noexcept
    {
        (void)_Size;
        return _Where;
    }

    inline void __cdecl operator delete(void*, void*) noexcept
    {
        return;
    }

          
    inline void* __cdecl operator new[](size_t _Size,
          void* _Where) noexcept
    {
        (void)_Size;
        return _Where;
    }

    inline void __cdecl operator delete[](void*, void*) noexcept
    {
    }



}  


extern "C++" {




          
    __declspec(allocator) void* __cdecl operator new(
            size_t      _Size,
            int         _BlockUse,
          char const* _FileName,
            int         _LineNumber
        );

          
    __declspec(allocator) void* __cdecl operator new[](
            size_t      _Size,
            int         _BlockUse,
          char const* _FileName,
            int         _LineNumber
        );

    void __cdecl operator delete(
        void*       _Block,
        int         _BlockUse,
        char const* _FileName,
        int         _LineNumber
        ) noexcept;

    void __cdecl operator delete[](
        void*       _Block,
        int         _BlockUse,
        char const* _FileName,
        int         _LineNumber
        ) noexcept;




}  



         extern "C" {



typedef void* _HFILE;  





     
typedef int (__cdecl* _CRT_REPORT_HOOK )(int, char*,    int*);
typedef int (__cdecl* _CRT_REPORT_HOOKW)(int, wchar_t*, int*);



typedef int (__cdecl* _CRT_ALLOC_HOOK)(int, void*, size_t, int, long, unsigned char const*, int);





     
 
  
  


 
     
typedef void (__cdecl* _CRT_DUMP_CLIENT)(void*, size_t);


struct _CrtMemBlockHeader;

typedef struct _CrtMemState
{
    struct _CrtMemBlockHeader* pBlockHeader;
    size_t lCounts[5];
    size_t lSizes[5];
    size_t lHighWaterCount;
    size_t lTotalCount;
} _CrtMemState;









     







     






     









 
 






}                             

                      


      
 
 
   





  

 
 
 













 
  


























 
  



namespace std {
enum _Uninitialized {      _Noinit
};

 class  _Lockit {  public:
    __thiscall _Lockit() noexcept;
    explicit __thiscall _Lockit(int) noexcept;      __thiscall ~_Lockit() noexcept;  
    static void __cdecl _Lockit_ctor(int) noexcept;
    static void __cdecl _Lockit_dtor(int) noexcept;

private:
    static void __cdecl _Lockit_ctor(_Lockit*) noexcept;
    static void __cdecl _Lockit_ctor(_Lockit*, int) noexcept;
    static void __cdecl _Lockit_dtor(_Lockit*) noexcept;

public:
     _Lockit(const _Lockit&) = delete;
    _Lockit&  operator=(const _Lockit&) = delete;

private:
    int _Locktype;
};






class  _Init_locks {  public:
    __thiscall _Init_locks() noexcept;
    __thiscall ~_Init_locks() noexcept;

private:
    static void __cdecl _Init_locks_ctor(_Init_locks*) noexcept;
    static void __cdecl _Init_locks_dtor(_Init_locks*) noexcept;
};

 

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



 
 int __cdecl _memicmp(
      void const* _Buf1,
      void const* _Buf2,
                             size_t      _Size
    );

 
 int __cdecl _memicmp_l(
      void const* _Buf1,
      void const* _Buf2,
                             size_t      _Size,
                         _locale_t   _Locale
    );










    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _memccpy. See online help for details."))
     void* __cdecl memccpy(
          void*       _Dst,
            void const* _Src,
                                   int         _Val,
                                   size_t      _Size
        );

      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _memicmp. See online help for details."))
     int __cdecl memicmp(
          void const* _Buf1,
          void const* _Buf2,
                                 size_t      _Size
        );





    extern "C++"  
    inline void* __cdecl memchr(
          void*  _Pv,
                              int    _C,
                              size_t _N
        )
    {
        void const* const _Pvc = _Pv;
        return const_cast<void*>(memchr(_Pvc, _C, _N));
    }




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





    
     errno_t __cdecl strcpy_s(
          char*       _Destination,
                                  rsize_t     _SizeInBytes,
                                char const* _Source
        );

    
     errno_t __cdecl strcat_s(
          char*       _Destination,
                                     rsize_t     _SizeInBytes,
                                   char const* _Source
        );

    
     errno_t __cdecl strerror_s(
          char*  _Buffer,
                                  size_t _SizeInBytes,
                                  int    _ErrorNumber);

    
     errno_t __cdecl strncat_s(
          char*       _Destination,
                                     rsize_t     _SizeInBytes,
               char const* _Source,
                                     rsize_t     _MaxCount
        );

    
     errno_t __cdecl strncpy_s(
          char*       _Destination,
                                  rsize_t     _SizeInBytes,
            char const* _Source,
                                  rsize_t     _MaxCount
        );

     
     char*  __cdecl strtok_s(
                          char*       _String,
                                 char const* _Delimiter,
            char**      _Context
        );


 void* __cdecl _memccpy(
      void*       _Dst,
                                   void const* _Src,
                                   int         _Val,
                                   size_t      _MaxCount
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl strcat_s(char (&_Destination)[_Size],   char const* _Source) throw()                 {                                                                                                                    return strcat_s(_Destination, _Size, _Source);                                                                       }                                                                                                            }


    __declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl strcat(  char *_Destination,                                                                             char const* _Source);


 
int __cdecl strcmp(
      char const* _Str1,
      char const* _Str2
    );

 
 int __cdecl _strcmpi(
      char const* _String1,
      char const* _String2
    );

 
 int __cdecl strcoll(
      char const* _String1,
      char const* _String2
    );

 
 int __cdecl _strcoll_l(
        char const* _String1,
        char const* _String2,
      _locale_t   _Locale
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl strcpy_s(  char (&_Destination)[_Size],     char const* _Source) throw()                 {                                                                                                                    return strcpy_s(_Destination, _Size, _Source);                                                                       }                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl strcpy(  char *_Destination,                                          char const* _Source);

 
 size_t __cdecl strcspn(
      char const* _Str,
      char const* _Control
    );


 
 __declspec(allocator) char* __cdecl _strdup(
      char const* _Source
    );


 
 
  __declspec(deprecated("This function or variable may be unsafe. Consider using _strerror_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 char*  __cdecl _strerror(
      char const* _ErrorMessage
    );


 errno_t __cdecl _strerror_s(
      char*       _Buffer,
                              size_t      _SizeInBytes,
                        char const* _ErrorMessage
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl _strerror_s(char (&_Buffer)[_Size],   char const* _ErrorMessage) throw()                 {                                                                                                                    return _strerror_s(_Buffer, _Size, _ErrorMessage);                                                                       }                                                                                                            }

 
  __declspec(deprecated("This function or variable may be unsafe. Consider using strerror_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 char* __cdecl strerror(
      int _ErrorMessage
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl strerror_s(char (&_Buffer)[_Size],   int _ErrorMessage) throw()                 {                                                                                                                    return strerror_s(_Buffer, _Size, _ErrorMessage);                                                                       }                                                                                                            }

 
 int __cdecl _stricmp(
      char const* _String1,
      char const* _String2
    );

 
 int __cdecl _stricoll(
      char const* _String1,
      char const* _String2
    );

 
 int __cdecl _stricoll_l(
        char const* _String1,
        char const* _String2,
      _locale_t   _Locale
    );

 
 int __cdecl _stricmp_l(
        char const* _String1,
        char const* _String2,
      _locale_t   _Locale
    );

 
size_t __cdecl strlen(
      char const* _Str
    );


 errno_t __cdecl _strlwr_s(
      char*  _String,
                          size_t _Size
    );

extern "C++"                                                                                      {                                                                                                     template <size_t _Size>                                                                           inline                                                                                            errno_t __cdecl _strlwr_s(  char (&_String)[_Size]) throw()                  {                                                                                                     return _strlwr_s(_String, _Size);                                                                }                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _strlwr(  char *_String);


 errno_t __cdecl _strlwr_s_l(
      char*     _String,
                          size_t    _Size,
                      _locale_t _Locale
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl _strlwr_s_l(  char (&_String)[_Size],      _locale_t _Locale) throw()                 {                                                                                                                    return _strlwr_s_l(_String, _Size, _Locale);                                                                       }                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _strlwr_l(  char *_String,                   _locale_t _Locale);

extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl strncat_s(              char (&_Destination)[_Size],   char const* _Source,                      size_t _Count) throw()                 {                                                                                                                                    return strncat_s(_Destination, _Size, _Source, _Count);                                                                               }                                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl strncat(  char *_Destination,      char const* _Source,                         size_t _Count);

 
 int __cdecl strncmp(
      char const* _Str1,
      char const* _Str2,
                            size_t      _MaxCount
    );

 
 int __cdecl _strnicmp(
      char const* _String1,
      char const* _String2,
                            size_t      _MaxCount
    );

 
 int __cdecl _strnicmp_l(
      char const* _String1,
      char const* _String2,
                            size_t      _MaxCount,
                        _locale_t   _Locale
    );

 
 int __cdecl _strnicoll(
      char const* _String1,
      char const* _String2,
                            size_t      _MaxCount
    );

 
 int __cdecl _strnicoll_l(
      char const* _String1,
      char const* _String2,
                            size_t      _MaxCount,
                        _locale_t   _Locale
    );

 
 int __cdecl _strncoll(
      char const* _String1,
      char const* _String2,
                            size_t      _MaxCount
    );

 
 int __cdecl _strncoll_l(
      char const* _String1,
      char const* _String2,
                            size_t      _MaxCount,
                        _locale_t   _Locale
    );

 size_t __cdecl __strncnt(
      char const* _String,
                         size_t      _Count
    );

extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl strncpy_s(char (&_Destination)[_Size],   char const* _Source,                      size_t _Count) throw()                 {                                                                                                                                    return strncpy_s(_Destination, _Size, _Source, _Count);                                                                               }                                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl strncpy(    char *_Destination,               char const* _Source,                                  size_t _Count);

 


 size_t __cdecl strnlen(
      char const* _String,
                            size_t      _MaxCount
    );


     
    
    
    static __inline size_t __cdecl strnlen_s(
          char const* _String,
                                size_t      _MaxCount
        )
    {
        return _String == 0 ? 0 : strnlen(_String, _MaxCount);
    }



 errno_t __cdecl _strnset_s(
      char*  _String,
                                 size_t _SizeInBytes,
                                 int    _Value,
                                 size_t _MaxCount
    );

extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl _strnset_s(  char (&_Destination)[_Size],          int _Value,          size_t _Count) throw()                 {                                                                                                                                    return _strnset_s(_Destination, _Size, _Value, _Count);                                                                               }                                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _strnset(  char *_Destination,                         int _Value,                         size_t _Count);

 
 char const* __cdecl strpbrk(
      char const* _Str,
      char const* _Control
    );

 char* __cdecl _strrev(
      char* _Str
    );


 errno_t __cdecl _strset_s(
      char*  _Destination,
                                     size_t _DestinationSize,
                                     int    _Value
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl _strset_s(  char (&_Destination)[_Size],          int _Value) throw()                 {                                                                                                                    return _strset_s(_Destination, _Size, _Value);                                                                       }                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _strset(  char *_Destination,         int _Value);

 
 size_t __cdecl strspn(
      char const* _Str,
      char const* _Control
    );

  __declspec(deprecated("This function or variable may be unsafe. Consider using strtok_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 char* __cdecl strtok(
      char*       _String,
             char const* _Delimiter
    );


 errno_t __cdecl _strupr_s(
      char*  _String,
                          size_t _Size
    );

extern "C++"                                                                                      {                                                                                                     template <size_t _Size>                                                                           inline                                                                                            errno_t __cdecl _strupr_s(  char (&_String)[_Size]) throw()                  {                                                                                                     return _strupr_s(_String, _Size);                                                                }                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _strupr(  char *_String);


 errno_t __cdecl _strupr_s_l(
      char*     _String,
                          size_t    _Size,
                      _locale_t _Locale
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl _strupr_s_l(  char (&_String)[_Size],      _locale_t _Locale) throw()                 {                                                                                                                    return _strupr_s_l(_String, _Size, _Locale);                                                                       }                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _SecureFuncName instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _strupr_l(  char *_String,                   _locale_t _Locale);

 

 size_t __cdecl strxfrm(
        char*       _Destination,
                                         char const* _Source,
                 size_t      _MaxCount
    );

 

 size_t __cdecl _strxfrm_l(
        char*       _Destination,
                                         char const* _Source,
                 size_t      _MaxCount,
                                       _locale_t   _Locale
    );



extern "C++"
{
     
    inline char* __cdecl strchr(  char* const _String,   int const _Ch)
    {
        return const_cast<char*>(strchr(static_cast<char const*>(_String), _Ch));
    }

     
    inline char* __cdecl strpbrk(  char* const _String,   char const* const _Control)
    {
        return const_cast<char*>(strpbrk(static_cast<char const*>(_String), _Control));
    }

     
    inline char* __cdecl strrchr(  char* const _String,   int const _Ch)
    {
        return const_cast<char*>(strrchr(static_cast<char const*>(_String), _Ch));
    }

       
    inline char* __cdecl strstr(  char* const _String,   char const* const _SubString)
    {
        return const_cast<char*>(strstr(static_cast<char const*>(_String), _SubString));
    }
}




      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _strdup. See online help for details."))
     char* __cdecl strdup(
          char const* _String
        );

           __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _strcmpi. See online help for details."))
     int __cdecl strcmpi(
          char const* _String1,
          char const* _String2
        );

      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _stricmp. See online help for details."))
     int __cdecl stricmp(
          char const* _String1,
          char const* _String2
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _strlwr. See online help for details."))
     char* __cdecl strlwr(
          char* _String
        );

      __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _strnicmp. See online help for details."))
     int __cdecl strnicmp(
          char const* _String1,
          char const* _String2,
                                size_t      _MaxCount
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _strnset. See online help for details."))
     char* __cdecl strnset(
          char*  _String,
                                  int    _Value,
                                  size_t _MaxCount
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _strrev. See online help for details."))
     char* __cdecl strrev(
          char* _String
        );

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _strset. See online help for details."))
    char* __cdecl strset(
          char* _String,
               int   _Value);

    __declspec(deprecated("The POSIX name for this item is deprecated. Instead, use the ISO C and C++ conformant name: _strupr. See online help for details."))
     char* __cdecl strupr(
          char* _String
        );




}                             




namespace std {

using :: size_t;
using :: memchr;
using :: memcmp;
using :: memcpy;
using :: memmove;
using :: memset;
using :: strcat;
using :: strchr;
using :: strcmp;
using :: strcoll;
using :: strcpy;
using :: strcspn;
using :: strerror;
using :: strlen;
using :: strncat;
using :: strncmp;
using :: strncpy;
using :: strpbrk;
using :: strrchr;
using :: strspn;
using :: strstr;
using :: strtok;
using :: strxfrm;

}



 
  
 
  
 
  
 
  

 
  
 
  

 
  
       


namespace std {
  template <class _Ty1, class _Ty2>
concept _Same_impl =      is_same_v<_Ty1, _Ty2>;

template <class _Ty1, class _Ty2>
concept same_as = _Same_impl<_Ty1, _Ty2> && _Same_impl<_Ty2, _Ty1>;

 template <class _Derived, class _Base>
concept derived_from = __is_base_of(_Base, _Derived)
    && __is_convertible_to(const volatile _Derived*, const volatile _Base*);

 template <class _From, class _To>
concept convertible_to = __is_convertible_to(_From, _To)
    && requires(add_rvalue_reference_t<_From> (&_Fn)()) {
        static_cast<_To>(_Fn());
    };

 template <class _From, class _To>
concept _Implicitly_convertible_to = is_convertible_v<_From, _To>;

 template <class _Ty1, class _Ty2>
concept common_reference_with =
    requires {
        typename common_reference_t<_Ty1, _Ty2>;
        typename common_reference_t<_Ty2, _Ty1>;
    }
    && same_as<common_reference_t<_Ty1, _Ty2>, common_reference_t<_Ty2, _Ty1>>
    && convertible_to<_Ty1, common_reference_t<_Ty1, _Ty2>>
    && convertible_to<_Ty2, common_reference_t<_Ty1, _Ty2>>;

 template <class _Ty1, class _Ty2>
concept common_with =
    requires {
        typename common_type_t<_Ty1, _Ty2>;
        typename common_type_t<_Ty2, _Ty1>;
        requires same_as<common_type_t<_Ty1, _Ty2>, common_type_t<_Ty2, _Ty1>>;
        static_cast<common_type_t<_Ty1, _Ty2>>(::std:: declval<_Ty1>());
        static_cast<common_type_t<_Ty1, _Ty2>>(::std:: declval<_Ty2>());
    }
    && common_reference_with<add_lvalue_reference_t<const _Ty1>, add_lvalue_reference_t<const _Ty2>>
    && common_reference_with<add_lvalue_reference_t<common_type_t<_Ty1, _Ty2>>,
        common_reference_t<add_lvalue_reference_t<const _Ty1>, add_lvalue_reference_t<const _Ty2>>>;

 template <class _Ty>
concept integral = is_integral_v<_Ty>;

 template <class _Ty>
concept signed_integral = integral<_Ty> && static_cast<_Ty>(-1) < static_cast<_Ty>(0);

 template <class _Ty>
concept unsigned_integral = integral<_Ty> && !signed_integral<_Ty>;

 template <class _Ty>
concept floating_point = is_floating_point_v<_Ty>;

 template <class _LTy, class _RTy>
concept assignable_from = is_lvalue_reference_v<_LTy>
    && common_reference_with<const remove_reference_t<_LTy>&, const remove_reference_t<_RTy>&>
    && requires(_LTy _Left, _RTy&& _Right) {
        { _Left = static_cast<_RTy&&>(_Right) } -> same_as<_LTy>;
    };

 
 template <class _Ty>
concept destructible = __is_nothrow_destructible(_Ty);

 template <class _Ty, class... _ArgTys>
concept constructible_from = destructible<_Ty>
    && __is_constructible(_Ty, _ArgTys...);

 template <class _Ty>
concept default_initializable = constructible_from<_Ty>
    && requires {
        _Ty{};
        ::new (static_cast<void*>(nullptr)) _Ty;      };

 template <class _Ty>
concept move_constructible = constructible_from<_Ty, _Ty> && convertible_to<_Ty, _Ty>;

 template <class _Ty>
concept _Has_class_or_enum_type = __is_class(remove_reference_t<_Ty>) || __is_enum(remove_reference_t<_Ty>)
    || __is_union(remove_reference_t<_Ty>);

 namespace ranges {
    namespace _Swap {
        template <class _Ty>
        void swap(_Ty&, _Ty&) = delete;

        template <class _Ty1, class _Ty2>
        concept _Use_ADL_swap = (_Has_class_or_enum_type<_Ty1> || _Has_class_or_enum_type<_Ty2>)
            && requires(_Ty1&& __t, _Ty2&& __u) {
                swap(static_cast<_Ty1&&>(__t), static_cast<_Ty2&&>(__u));
            };

        struct _Cpo {
            template <class _Ty1, class _Ty2>
                requires _Use_ADL_swap<_Ty1, _Ty2>
            constexpr void operator()(_Ty1&& __t, _Ty2&& __u) const
                noexcept(noexcept(swap(static_cast<_Ty1&&>(__t), static_cast<_Ty2&&>(__u)))) {
                swap(static_cast<_Ty1&&>(__t), static_cast<_Ty2&&>(__u));
            }

            template <class _Ty>
                requires (!_Use_ADL_swap<_Ty&, _Ty&> && move_constructible<_Ty> && assignable_from<_Ty&, _Ty>)
            constexpr void operator()(_Ty& __x, _Ty& __y) const
                noexcept(is_nothrow_move_constructible_v<_Ty> && is_nothrow_move_assignable_v<_Ty>) {
                _Ty __tmp(static_cast<_Ty&&>(__x));
                __x = static_cast<_Ty&&>(__y);
                __y = static_cast<_Ty&&>(__tmp);
            }

            template <class _Ty1, class _Ty2, size_t _Size>
            constexpr void operator()(_Ty1 (&__t)[_Size], _Ty2 (&__u)[_Size]) const
                noexcept(noexcept((*this)(__t[0], __u[0])))
                requires requires { (*this)(__t[0], __u[0]); } {
                for (size_t __i = 0; __i < _Size; ++__i) {
                    (*this)(__t[__i], __u[__i]);
                }
            }
        };
    }  
    namespace _Cpos {
        inline constexpr _Swap::_Cpo swap;
    }
    using namespace _Cpos;
}  
 template <class _Ty>
concept swappable = requires(_Ty& __x, _Ty& __y) {
    ::std::ranges:: swap(__x, __y);
};

 template <class _Ty1, class _Ty2>
concept swappable_with = common_reference_with<_Ty1, _Ty2>
    && requires(_Ty1&& __t, _Ty2&& __u) {
        ::std::ranges:: swap(static_cast<_Ty1&&>(__t), static_cast<_Ty1&&>(__t));
        ::std::ranges:: swap(static_cast<_Ty2&&>(__u), static_cast<_Ty2&&>(__u));
        ::std::ranges:: swap(static_cast<_Ty1&&>(__t), static_cast<_Ty2&&>(__u));
        ::std::ranges:: swap(static_cast<_Ty2&&>(__u), static_cast<_Ty1&&>(__t));
    };

 template <class _Ty>
concept copy_constructible = move_constructible<_Ty>
    && constructible_from<_Ty, _Ty&> && convertible_to<_Ty&, _Ty>
    && constructible_from<_Ty, const _Ty&> && convertible_to<const _Ty&, _Ty>
    && constructible_from<_Ty, const _Ty> && convertible_to<const _Ty, _Ty>;

 template <class _Ty>
concept _Boolean_testable_impl = convertible_to<_Ty, bool>;

template <class _Ty>
concept _Boolean_testable = _Boolean_testable_impl<_Ty>
    && requires(_Ty&& __t) {
        { !static_cast<_Ty&&>(__t) } -> _Boolean_testable_impl;
    };

 template <class _Ty1, class _Ty2>
concept _Half_equality_comparable =
    requires(const remove_reference_t<_Ty1>& __x, const remove_reference_t<_Ty2>& __y) {
        { __x == __y } -> _Boolean_testable;
        { __x != __y } -> _Boolean_testable;
    };

template <class _Ty1, class _Ty2>
concept _Weakly_equality_comparable_with =
    _Half_equality_comparable<_Ty1, _Ty2> && _Half_equality_comparable<_Ty2, _Ty1>;

 template <class _Ty>
concept equality_comparable = _Half_equality_comparable<_Ty, _Ty>;

 template <class _Ty1, class _Ty2>
concept equality_comparable_with = equality_comparable<_Ty1> && equality_comparable<_Ty2>
    && common_reference_with<const remove_reference_t<_Ty1>&, const remove_reference_t<_Ty2>&>
    && equality_comparable<common_reference_t<const remove_reference_t<_Ty1>&, const remove_reference_t<_Ty2>&>>
    && _Weakly_equality_comparable_with<_Ty1, _Ty2>;

 template <class _Ty1, class _Ty2>
concept _Half_ordered = requires(const remove_reference_t<_Ty1>& __t, const remove_reference_t<_Ty2>& __u) {
    { __t <  __u } -> _Boolean_testable;
    { __t >  __u } -> _Boolean_testable;
    { __t <= __u } -> _Boolean_testable;
    { __t >= __u } -> _Boolean_testable;
};

template <class _Ty1, class _Ty2>
concept _Partially_ordered_with = _Half_ordered<_Ty1, _Ty2> && _Half_ordered<_Ty2, _Ty1>;

 template <class _Ty>
concept totally_ordered = equality_comparable<_Ty> && _Half_ordered<_Ty, _Ty>;

 template <class _Ty1, class _Ty2>
concept totally_ordered_with = totally_ordered<_Ty1> && totally_ordered<_Ty2>
    && equality_comparable_with<_Ty1, _Ty2>
    && totally_ordered<common_reference_t<const remove_reference_t<_Ty1>&, const remove_reference_t<_Ty2>&>>
    && _Partially_ordered_with<_Ty1, _Ty2>;

 template <class _Ty>
concept movable = is_object_v<_Ty>
    && move_constructible<_Ty>
    && assignable_from<_Ty&, _Ty>
    && swappable<_Ty>;

 template <class _Ty>
concept copyable = copy_constructible<_Ty>
    && movable<_Ty>
    && assignable_from<_Ty&, _Ty&>
    && assignable_from<_Ty&, const _Ty&>
    && assignable_from<_Ty&, const _Ty>;

 template <class _Ty>
concept semiregular = copyable<_Ty> && default_initializable<_Ty>;

 template <class _Ty>
concept regular = semiregular<_Ty> && equality_comparable<_Ty>;

 template <class _FTy, class... _ArgTys>
concept invocable = requires(_FTy&& _Fn, _ArgTys&&... _Args) {
    ::std:: invoke(static_cast<_FTy&&>(_Fn), static_cast<_ArgTys&&>(_Args)...);
};

 template <class _FTy, class... _ArgTys>
concept regular_invocable = invocable<_FTy, _ArgTys...>;

 template <class _FTy, class... _ArgTys>
concept predicate = regular_invocable<_FTy, _ArgTys...>
    && _Boolean_testable<invoke_result_t<_FTy, _ArgTys...>>;

 template <class _FTy, class _Ty1, class _Ty2>
concept relation =
       predicate<_FTy, _Ty1, _Ty1>
    && predicate<_FTy, _Ty2, _Ty2>
    && predicate<_FTy, _Ty1, _Ty2>
    && predicate<_FTy, _Ty2, _Ty1>;

 template <class _FTy, class _Ty1, class _Ty2>
concept equivalence_relation = relation<_FTy, _Ty1, _Ty2>;

 template <class _FTy, class _Ty1, class _Ty2>
concept strict_weak_order = relation<_FTy, _Ty1, _Ty2>;

 
 template <class _Ty>
struct _Choice_t {
    _Ty _Strategy  = _Ty{};
    bool _No_throw = false;
};

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

 
  



namespace std {

template <class _To, class _From,
    enable_if_t<conjunction_v<bool_constant<sizeof(_To) == sizeof(_From)>, is_trivially_copyable<_To>,
                    is_trivially_copyable<_From>>,
        int> = 0>
 constexpr _To bit_cast(const _From& _Val) noexcept {
    return __builtin_bit_cast(_To, _Val);
}

template <class _Ty, enable_if_t<_Is_standard_unsigned_integer<_Ty>, int> = 0>
 constexpr int countl_zero(_Ty _Val) noexcept;

template <class _Ty, enable_if_t<_Is_standard_unsigned_integer<_Ty>, int> = 0>
 constexpr bool has_single_bit(const _Ty _Val) noexcept {
    return _Val != 0 && (_Val & (_Val - 1)) == 0;
}

template <class _Ty, enable_if_t<_Is_standard_unsigned_integer<_Ty>, int> = 0>
 constexpr _Ty bit_ceil(const _Ty _Val) noexcept   {
    if (_Val == 0) {
        return 1;
    }

    return static_cast<_Ty>(_Ty{1} << (numeric_limits<_Ty>::digits - ::std:: countl_zero(static_cast<_Ty>(_Val - 1))));
}

template <class _Ty, enable_if_t<_Is_standard_unsigned_integer<_Ty>, int> = 0>
 constexpr _Ty bit_floor(const _Ty _Val) noexcept {
    if (_Val == 0) {
        return 0;
    }

    return static_cast<_Ty>(_Ty{1} << (numeric_limits<_Ty>::digits - 1 - ::std:: countl_zero(_Val)));
}

template <class _Ty, enable_if_t<_Is_standard_unsigned_integer<_Ty>, int> = 0>
 constexpr _Ty bit_width(const _Ty _Val) noexcept {
    return static_cast<_Ty>(numeric_limits<_Ty>::digits - ::std:: countl_zero(_Val));
}

template <class _Ty, enable_if_t<_Is_standard_unsigned_integer<_Ty>, int> = 0>
 constexpr _Ty rotr(_Ty _Val, int _Rotation) noexcept;

template <class _Ty, enable_if_t<_Is_standard_unsigned_integer<_Ty>, int> = 0>
 constexpr _Ty rotl(const _Ty _Val, const int _Rotation) noexcept {
    constexpr auto _Digits = numeric_limits<_Ty>::digits;
    const auto _Remainder  = _Rotation % _Digits;
    if (_Remainder > 0) {
        return static_cast<_Ty>(
            static_cast<_Ty>(_Val << _Remainder) | static_cast<_Ty>(_Val >> (_Digits - _Remainder)));
    } else if (_Remainder == 0) {
        return _Val;
    } else {          return ::std:: rotr(_Val, -_Remainder);
    }
}

template <class _Ty, enable_if_t<_Is_standard_unsigned_integer<_Ty>, int> _Enabled>
 constexpr _Ty rotr(const _Ty _Val, const int _Rotation) noexcept {
    constexpr auto _Digits = numeric_limits<_Ty>::digits;
    const auto _Remainder  = _Rotation % _Digits;
    if (_Remainder > 0) {
        return static_cast<_Ty>(
            static_cast<_Ty>(_Val >> _Remainder) | static_cast<_Ty>(_Val << (_Digits - _Remainder)));
    } else if (_Remainder == 0) {
        return _Val;
    } else {          return ::std:: rotl(_Val, -_Remainder);
    }
}

  template <class _Ty>
 constexpr int _Popcount_fallback(_Ty _Val) noexcept {
    constexpr int _Digits = numeric_limits<_Ty>::digits;
         _Val = static_cast<_Ty>(_Val - ((_Val >> 1) & static_cast<_Ty>(0x5555'5555'5555'5555ull)));
    _Val = static_cast<_Ty>((_Val & static_cast<_Ty>(0x3333'3333'3333'3333ull))
                            + ((_Val >> 2) & static_cast<_Ty>(0x3333'3333'3333'3333ull)));
    _Val = static_cast<_Ty>((_Val + (_Val >> 4)) & static_cast<_Ty>(0x0F0F'0F0F'0F0F'0F0Full));
    for (int _Shift_digits = 8; _Shift_digits < _Digits; _Shift_digits <<= 1) {
        _Val = static_cast<_Ty>(_Val + static_cast<_Ty>(_Val >> _Shift_digits));
    }
         return static_cast<int>(_Val & static_cast<_Ty>(_Digits + _Digits - 1));
}


extern "C" {
extern int __isa_available;
}

template <class _Ty>
 int _Countl_zero_lzcnt(const _Ty _Val) noexcept {
    constexpr int _Digits = numeric_limits<_Ty>::digits;

    if constexpr (_Digits <= 16) {
        return static_cast<int>(__lzcnt16(_Val) - (16 - _Digits));
    } else if constexpr (_Digits == 32) {
        return static_cast<int>(__lzcnt(_Val));
    } else {
        return static_cast<int>(__lzcnt64(_Val));
    }
}

template <class _Ty>
 int _Countl_zero_bsr(const _Ty _Val) noexcept {
    constexpr int _Digits = numeric_limits<_Ty>::digits;

    unsigned long _Result;
    if constexpr (_Digits <= 32) {
        if (!_BitScanReverse(&_Result, _Val)) {
            return _Digits;
        }
    } else {
        if (!_BitScanReverse64(&_Result, _Val)) {
            return _Digits;
        }
    }
    return static_cast<int>(_Digits - 1 - _Result);
}

template <class _Ty>
 int _Checked_x86_x64_countl_zero(const _Ty _Val) noexcept {
    const bool _Definitely_have_lzcnt = __isa_available >= __ISA_AVAILABLE_AVX2;
    if (_Definitely_have_lzcnt) {
        return _Countl_zero_lzcnt(_Val);
    } else {
        return _Countl_zero_bsr(_Val);
    }
}

template <class _Ty>
 int _Checked_x86_x64_popcount(const _Ty _Val) noexcept {
    constexpr int _Digits              = numeric_limits<_Ty>::digits;
    const bool _Definitely_have_popcnt = __isa_available >= __ISA_AVAILABLE_SSE42;
    if (!_Definitely_have_popcnt) {
        return _Popcount_fallback(_Val);
    }

    if constexpr (_Digits <= 16) {
        return static_cast<int>(__popcnt16(_Val));
    } else if constexpr (_Digits == 32) {
        return static_cast<int>(__popcnt(_Val));
    } else {
        return static_cast<int>(__popcnt64(_Val));
    }
}



template <class _Ty, enable_if_t<_Is_standard_unsigned_integer<_Ty>, int> _Enabled>
 constexpr int countl_zero(const _Ty _Val) noexcept {
    if (::std:: is_constant_evaluated()) {
        return _Countl_zero_fallback(_Val);
    } else {
        return _Checked_x86_x64_countl_zero(_Val);
    }
}

template <class _Ty, enable_if_t<_Is_standard_unsigned_integer<_Ty>, int> = 0>
 constexpr int countl_one(const _Ty _Val) noexcept {
    return ::std:: countl_zero(static_cast<_Ty>(~_Val));
}

template <class _Ty, enable_if_t<_Is_standard_unsigned_integer<_Ty>, int> = 0>
 constexpr int countr_zero(const _Ty _Val) noexcept {
    return _Countr_zero(_Val);
}

template <class _Ty, enable_if_t<_Is_standard_unsigned_integer<_Ty>, int> _Enabled = 0>
 constexpr int countr_one(const _Ty _Val) noexcept {
    return _Countr_zero(static_cast<_Ty>(~_Val));
}

template <class _Ty, enable_if_t<_Is_standard_unsigned_integer<_Ty>, int> _Enabled = 0>
 constexpr int popcount(const _Ty _Val) noexcept {
    if (!::std:: is_constant_evaluated()) {
        return _Checked_x86_x64_popcount(_Val);
    }
    return _Popcount_fallback(_Val);
}

enum class endian { little = 0, big = 1, native = little };

}

 
  



namespace std {
using _Literal_zero = decltype(nullptr);
using _Compare_t    = signed char;

 enum class _Compare_eq : _Compare_t { equal = 0, equivalent = equal };
enum class _Compare_ord : _Compare_t { less = -1, greater = 1 };
enum class _Compare_ncmp : _Compare_t { unordered = -128 };

 struct partial_ordering {
    static const partial_ordering less;
    static const partial_ordering equivalent;
    static const partial_ordering greater;
    static const partial_ordering unordered;

     friend constexpr bool operator==(const partial_ordering _Val, _Literal_zero) noexcept {
        return _Val._Value == 0;
    }

     friend constexpr bool operator==(partial_ordering, partial_ordering) noexcept = default;

     friend constexpr bool operator<(const partial_ordering _Val, _Literal_zero) noexcept {
        return _Val._Value == static_cast<_Compare_t>(_Compare_ord::less);
    }

     friend constexpr bool operator>(const partial_ordering _Val, _Literal_zero) noexcept {
        return _Val._Value > 0;
    }

     friend constexpr bool operator<=(const partial_ordering _Val, _Literal_zero) noexcept {
                                   return static_cast<signed char>(0 - static_cast<unsigned int>(_Val._Value)) >= 0;
    }

     friend constexpr bool operator>=(const partial_ordering _Val, _Literal_zero) noexcept {
        return _Val._Value >= 0;
    }

     friend constexpr bool operator<(_Literal_zero, const partial_ordering _Val) noexcept {
        return _Val > 0;
    }

     friend constexpr bool operator>(_Literal_zero, const partial_ordering _Val) noexcept {
        return _Val < 0;
    }

     friend constexpr bool operator<=(_Literal_zero, const partial_ordering _Val) noexcept {
        return _Val >= 0;
    }

     friend constexpr bool operator>=(_Literal_zero, const partial_ordering _Val) noexcept {
        return _Val <= 0;
    }

     friend constexpr partial_ordering operator<=>(const partial_ordering _Val, _Literal_zero) noexcept {
        return _Val;
    }

     friend constexpr partial_ordering operator<=>(_Literal_zero, const partial_ordering _Val) noexcept {
                                   return {static_cast<_Compare_t>(0 - static_cast<unsigned int>(_Val._Value))};
    }

    _Compare_t _Value;
};

inline constexpr partial_ordering partial_ordering::less{static_cast<_Compare_t>(_Compare_ord::less)};
inline constexpr partial_ordering partial_ordering::equivalent{static_cast<_Compare_t>(_Compare_eq::equivalent)};
inline constexpr partial_ordering partial_ordering::greater{static_cast<_Compare_t>(_Compare_ord::greater)};
inline constexpr partial_ordering partial_ordering::unordered{static_cast<_Compare_t>(_Compare_ncmp::unordered)};

 struct weak_ordering {
    static const weak_ordering less;
    static const weak_ordering equivalent;
    static const weak_ordering greater;

    constexpr operator partial_ordering() const noexcept {
        return {static_cast<_Compare_t>(_Value)};
    }

     friend constexpr bool operator==(const weak_ordering _Val, _Literal_zero) noexcept {
        return _Val._Value == 0;
    }

     friend constexpr bool operator==(weak_ordering, weak_ordering) noexcept = default;

     friend constexpr bool operator<(const weak_ordering _Val, _Literal_zero) noexcept {
        return _Val._Value < 0;
    }

     friend constexpr bool operator>(const weak_ordering _Val, _Literal_zero) noexcept {
        return _Val._Value > 0;
    }

     friend constexpr bool operator<=(const weak_ordering _Val, _Literal_zero) noexcept {
        return _Val._Value <= 0;
    }

     friend constexpr bool operator>=(const weak_ordering _Val, _Literal_zero) noexcept {
        return _Val._Value >= 0;
    }

     friend constexpr bool operator<(_Literal_zero, const weak_ordering _Val) noexcept {
        return _Val > 0;
    }

     friend constexpr bool operator>(_Literal_zero, const weak_ordering _Val) noexcept {
        return _Val < 0;
    }

     friend constexpr bool operator<=(_Literal_zero, const weak_ordering _Val) noexcept {
        return _Val >= 0;
    }

     friend constexpr bool operator>=(_Literal_zero, const weak_ordering _Val) noexcept {
        return _Val <= 0;
    }

     friend constexpr weak_ordering operator<=>(const weak_ordering _Val, _Literal_zero) noexcept {
        return _Val;
    }

     friend constexpr weak_ordering operator<=>(_Literal_zero, const weak_ordering _Val) noexcept {
        return {static_cast<_Compare_t>(-_Val._Value)};
    }

    _Compare_t _Value;
};

inline constexpr weak_ordering weak_ordering::less{static_cast<_Compare_t>(_Compare_ord::less)};
inline constexpr weak_ordering weak_ordering::equivalent{static_cast<_Compare_t>(_Compare_eq::equivalent)};
inline constexpr weak_ordering weak_ordering::greater{static_cast<_Compare_t>(_Compare_ord::greater)};

 struct strong_ordering {
    static const strong_ordering less;
    static const strong_ordering equal;
    static const strong_ordering equivalent;
    static const strong_ordering greater;

    constexpr operator partial_ordering() const noexcept {
        return {static_cast<_Compare_t>(_Value)};
    }

    constexpr operator weak_ordering() const noexcept {
        return {static_cast<_Compare_t>(_Value)};
    }

     friend constexpr bool operator==(const strong_ordering _Val, _Literal_zero) noexcept {
        return _Val._Value == 0;
    }

     friend constexpr bool operator==(strong_ordering, strong_ordering) noexcept = default;

     friend constexpr bool operator<(const strong_ordering _Val, _Literal_zero) noexcept {
        return _Val._Value < 0;
    }

     friend constexpr bool operator>(const strong_ordering _Val, _Literal_zero) noexcept {
        return _Val._Value > 0;
    }

     friend constexpr bool operator<=(const strong_ordering _Val, _Literal_zero) noexcept {
        return _Val._Value <= 0;
    }

     friend constexpr bool operator>=(const strong_ordering _Val, _Literal_zero) noexcept {
        return _Val._Value >= 0;
    }

     friend constexpr bool operator<(_Literal_zero, const strong_ordering _Val) noexcept {
        return _Val > 0;
    }

     friend constexpr bool operator>(_Literal_zero, const strong_ordering _Val) noexcept {
        return _Val < 0;
    }

     friend constexpr bool operator<=(_Literal_zero, const strong_ordering _Val) noexcept {
        return _Val >= 0;
    }

     friend constexpr bool operator>=(_Literal_zero, const strong_ordering _Val) noexcept {
        return _Val <= 0;
    }

     friend constexpr strong_ordering operator<=>(const strong_ordering _Val, _Literal_zero) noexcept {
        return _Val;
    }

     friend constexpr strong_ordering operator<=>(_Literal_zero, const strong_ordering _Val) noexcept {
        return {static_cast<_Compare_t>(-_Val._Value)};
    }

    _Compare_t _Value;
};

inline constexpr strong_ordering strong_ordering::less{static_cast<_Compare_t>(_Compare_ord::less)};
inline constexpr strong_ordering strong_ordering::equal{static_cast<_Compare_t>(_Compare_eq::equal)};
inline constexpr strong_ordering strong_ordering::equivalent{static_cast<_Compare_t>(_Compare_eq::equivalent)};
inline constexpr strong_ordering strong_ordering::greater{static_cast<_Compare_t>(_Compare_ord::greater)};

  constexpr bool is_eq(const partial_ordering _Comp) noexcept {
    return _Comp == 0;
}

  constexpr bool is_neq(const partial_ordering _Comp) noexcept {
    return _Comp != 0;
}

  constexpr bool is_lt(const partial_ordering _Comp) noexcept {
    return _Comp < 0;
}

  constexpr bool is_lteq(const partial_ordering _Comp) noexcept {
    return _Comp <= 0;
}

  constexpr bool is_gt(const partial_ordering _Comp) noexcept {
    return _Comp > 0;
}

  constexpr bool is_gteq(const partial_ordering _Comp) noexcept {
    return _Comp >= 0;
}

 enum _Comparison_category : unsigned char {
    _Comparison_category_none    = 1,
    _Comparison_category_partial = 2,
    _Comparison_category_weak    = 4,
    _Comparison_category_strong  = 0,
};

template <class... _Types>
inline constexpr unsigned char _Classify_category =
    _Comparison_category{(_Classify_category<_Types> | ... | _Comparison_category_strong)};
template <class _Ty>
inline constexpr unsigned char _Classify_category<_Ty> = _Comparison_category_none;
template <>
inline constexpr unsigned char _Classify_category<partial_ordering> = _Comparison_category_partial;
template <>
inline constexpr unsigned char _Classify_category<weak_ordering> = _Comparison_category_weak;
template <>
inline constexpr unsigned char _Classify_category<strong_ordering> = _Comparison_category_strong;

template <class... _Types>
using common_comparison_category_t =
    conditional_t<(_Classify_category<_Types...> & _Comparison_category_none) != 0, void,
        conditional_t<(_Classify_category<_Types...> & _Comparison_category_partial) != 0, partial_ordering,
            conditional_t<(_Classify_category<_Types...> & _Comparison_category_weak) != 0, weak_ordering,
                strong_ordering>>>;

template <class... _Types>
struct common_comparison_category {
    using type = common_comparison_category_t<_Types...>;
};

 template <class _Ty, class _Cat>
concept _Compares_as = same_as<common_comparison_category_t<_Ty, _Cat>, _Cat>;

template <class _Ty, class _Cat = partial_ordering>
concept three_way_comparable = _Half_equality_comparable<_Ty, _Ty> && _Half_ordered<_Ty, _Ty>
    && requires(const remove_reference_t<_Ty>& __a, const remove_reference_t<_Ty>& __b) {
        { __a <=> __b } -> _Compares_as<_Cat>;
    };

template <class _Ty1, class _Ty2, class _Cat = partial_ordering>
concept three_way_comparable_with = three_way_comparable<_Ty1, _Cat> && three_way_comparable<_Ty2, _Cat>
    && common_reference_with<const remove_reference_t<_Ty1>&, const remove_reference_t<_Ty2>&>
    && three_way_comparable<common_reference_t<const remove_reference_t<_Ty1>&, const remove_reference_t<_Ty2>&>, _Cat>
    && _Weakly_equality_comparable_with<_Ty1, _Ty2> && _Partially_ordered_with<_Ty1, _Ty2>
    && requires(const remove_reference_t<_Ty1>& __t, const remove_reference_t<_Ty2>& __u) {
        { __t <=> __u } -> _Compares_as<_Cat>;
        { __u <=> __t } -> _Compares_as<_Cat>;
    };

template <class _Ty1, class _Ty2 = _Ty1>
using compare_three_way_result_t =
    decltype(::std:: declval<const remove_reference_t<_Ty1>&>() <=> ::std:: declval<const remove_reference_t<_Ty2>&>());

template <class _Ty1, class _Ty2 = _Ty1>
struct compare_three_way_result {};

template <class _Ty1, class _Ty2>
    requires requires { typename compare_three_way_result_t<_Ty1, _Ty2>; }
struct compare_three_way_result<_Ty1, _Ty2> {
    using type = compare_three_way_result_t<_Ty1, _Ty2>;
};

struct compare_three_way {
    template <class _Ty1, class _Ty2>
        requires three_way_comparable_with<_Ty1, _Ty2>       constexpr auto operator()(_Ty1&& _Left, _Ty2&& _Right) const
        noexcept(noexcept(::std:: forward<_Ty1>(_Left) <=> ::std:: forward<_Ty2>(_Right)))   {
        return ::std:: forward<_Ty1>(_Left) <=> ::std:: forward<_Ty2>(_Right);
    }

    using is_transparent = int;
};
 
 
 namespace _Strong_order {
    void strong_order();  
    template <class _Ty1, class _Ty2>
    concept _Has_ADL = requires(_Ty1& _Left, _Ty2& _Right) {
        static_cast<strong_ordering>(  strong_order(_Left, _Right));
    };

    template <class _Ty1, class _Ty2>
    concept _Can_compare_three_way = requires(_Ty1& _Left, _Ty2& _Right) {
        static_cast<strong_ordering>(compare_three_way{}(_Left, _Right));
    };

    class _Cpo {
    private:
        enum class _St { _None, _Adl, _Floating, _Three };

        template <class _Ty1, class _Ty2>
         static constexpr _Choice_t<_St> _Choose() noexcept {
            if constexpr (!same_as<decay_t<_Ty1>, decay_t<_Ty2>>) {
                return {_St::_None};
            } else if constexpr (_Has_ADL<_Ty1, _Ty2>) {
                return {_St::_Adl, noexcept(static_cast<strong_ordering>(
                                         strong_order(::std:: declval<_Ty1&>(), ::std:: declval<_Ty2&>())))};
            } else if constexpr (floating_point<decay_t<_Ty1>>) {
                return {_St::_Floating, true};
            } else if constexpr (_Can_compare_three_way<_Ty1, _Ty2>) {
                return {_St::_Three, noexcept(static_cast<strong_ordering>(
                                         compare_three_way{}(::std:: declval<_Ty1&>(), ::std:: declval<_Ty2&>())))};
            } else {
                return {_St::_None};
            }
        }

        template <class _Ty1, class _Ty2>
        static constexpr _Choice_t<_St> _Choice = _Choose<_Ty1, _Ty2>();

    public:
                 template <class _Ty1, class _Ty2>
            requires (_Choice<_Ty1&, _Ty2&>._Strategy != _St::_None)
         constexpr strong_ordering operator()(_Ty1&& _Left, _Ty2&& _Right) const
            noexcept(_Choice<_Ty1&, _Ty2&>._No_throw) {
                         constexpr _St _Strat = _Choice<_Ty1&, _Ty2&>._Strategy;
            if constexpr (_Strat == _St::_Adl) {
                return static_cast<strong_ordering>(  strong_order(_Left, _Right));
            } else if constexpr (_Strat == _St::_Floating) {
                using _Floating_type = decay_t<_Ty1>;
                using _Traits        = _Floating_type_traits<_Floating_type>;
                using _Uint_type     = typename _Traits::_Uint_type;
                using _Sint_type     = make_signed_t<_Uint_type>;

                const auto _Left_uint  = ::std:: bit_cast<_Uint_type>(_Left);
                const auto _Right_uint = ::std:: bit_cast<_Uint_type>(_Right);

                                 if (_Left_uint == _Right_uint) {
                    return strong_ordering::equal;
                }

                                 const _Uint_type _Left_shifted_sign  = _Left_uint & _Traits::_Shifted_sign_mask;
                const _Uint_type _Right_shifted_sign = _Right_uint & _Traits::_Shifted_sign_mask;

                                                                   const _Uint_type _Left_sign  = _Left_shifted_sign >> _Traits::_Sign_shift;
                const _Uint_type _Right_sign = _Right_shifted_sign >> _Traits::_Sign_shift;

                const _Uint_type _Left_xor  = _Left_shifted_sign - _Left_sign;
                const _Uint_type _Right_xor = _Right_shifted_sign - _Right_sign;

                const _Uint_type _Left_ones_complement_uint  = _Left_uint ^ _Left_xor;
                const _Uint_type _Right_ones_complement_uint = _Right_uint ^ _Right_xor;

                const auto _Left_ones_complement  = static_cast<_Sint_type>(_Left_ones_complement_uint);
                const auto _Right_ones_complement = static_cast<_Sint_type>(_Right_ones_complement_uint);

                                 return _Left_ones_complement <=> _Right_ones_complement;
            } else if constexpr (_Strat == _St::_Three) {
                return static_cast<strong_ordering>(compare_three_way{}(_Left, _Right));
            } else {
                static_assert(_Always_false<_Ty1>, "should be unreachable");
            }
        }
    };
}  
namespace _Cpos {
    inline constexpr _Strong_order::_Cpo strong_order;
}
using namespace _Cpos;

 namespace _Weak_order {
    void weak_order();  
    template <class _Ty1, class _Ty2>
    concept _Has_ADL = requires(_Ty1& _Left, _Ty2& _Right) {
        static_cast<weak_ordering>(  weak_order(_Left, _Right));
    };

    template <class _Ty1, class _Ty2>
    concept _Can_compare_three_way = requires(_Ty1& _Left, _Ty2& _Right) {
        static_cast<weak_ordering>(compare_three_way{}(_Left, _Right));
    };

         void strong_order();  
    class _Cpo {
    private:
        enum class _St { _None, _Adl, _Floating, _Three, _Strong };

        template <class _Ty1, class _Ty2>
         static constexpr _Choice_t<_St> _Choose() noexcept {
            if constexpr (!same_as<decay_t<_Ty1>, decay_t<_Ty2>>) {
                return {_St::_None};
            } else if constexpr (_Has_ADL<_Ty1, _Ty2>) {
                return {_St::_Adl, noexcept(static_cast<weak_ordering>(
                                         weak_order(::std:: declval<_Ty1&>(), ::std:: declval<_Ty2&>())))};
            } else if constexpr (floating_point<decay_t<_Ty1>>) {
                return {_St::_Floating, true};
            } else if constexpr (_Can_compare_three_way<_Ty1, _Ty2>) {
                return {_St::_Three, noexcept(static_cast<weak_ordering>(
                                         compare_three_way{}(::std:: declval<_Ty1&>(), ::std:: declval<_Ty2&>())))};
            } else if constexpr (_Strong_order::_Has_ADL<_Ty1, _Ty2>) {
                return {_St::_Strong, noexcept(static_cast<weak_ordering>(static_cast<strong_ordering>(
                                            strong_order(
                                              ::std:: declval<_Ty1&>(), ::std:: declval<_Ty2&>()))))};
            } else {
                return {_St::_None};
            }
        }

        template <class _Ty1, class _Ty2>
        static constexpr _Choice_t<_St> _Choice = _Choose<_Ty1, _Ty2>();

    public:
                 template <class _Ty1, class _Ty2>
            requires (_Choice<_Ty1&, _Ty2&>._Strategy != _St::_None)
         constexpr weak_ordering operator()(_Ty1&& _Left, _Ty2&& _Right) const
            noexcept(_Choice<_Ty1&, _Ty2&>._No_throw) {
                         constexpr _St _Strat = _Choice<_Ty1&, _Ty2&>._Strategy;
            if constexpr (_Strat == _St::_Adl) {
                return static_cast<weak_ordering>(  weak_order(_Left, _Right));
            } else if constexpr (_Strat == _St::_Floating) {
                using _Floating_type = decay_t<_Ty1>;
                using _Traits        = _Floating_type_traits<_Floating_type>;
                using _Uint_type     = typename _Traits::_Uint_type;
                using _Sint_type     = make_signed_t<_Uint_type>;

                auto _Left_uint  = ::std:: bit_cast<_Uint_type>(_Left);
                auto _Right_uint = ::std:: bit_cast<_Uint_type>(_Right);

                                 if (_Left_uint == _Right_uint) {
                    return weak_ordering::equivalent;
                }

                                 const _Uint_type _Left_shifted_sign  = _Left_uint & _Traits::_Shifted_sign_mask;
                const _Uint_type _Right_shifted_sign = _Right_uint & _Traits::_Shifted_sign_mask;

                                                  constexpr _Uint_type _Infinity_plus_one = _Traits::_Shifted_exponent_mask + 1;

                const _Uint_type _Left_magnitude  = _Left_uint & ~_Traits::_Shifted_sign_mask;
                const _Uint_type _Right_magnitude = _Right_uint & ~_Traits::_Shifted_sign_mask;

                if (_Left_magnitude > _Infinity_plus_one) {
                    _Left_uint = _Left_shifted_sign | _Infinity_plus_one;
                }

                if (_Right_magnitude > _Infinity_plus_one) {
                    _Right_uint = _Right_shifted_sign | _Infinity_plus_one;
                }

                                                                   const _Uint_type _Left_sign  = _Left_shifted_sign >> _Traits::_Sign_shift;
                const _Uint_type _Right_sign = _Right_shifted_sign >> _Traits::_Sign_shift;

                const _Uint_type _Left_xor  = _Left_shifted_sign - _Left_sign;
                const _Uint_type _Right_xor = _Right_shifted_sign - _Right_sign;

                const _Uint_type _Left_twos_complement_uint  = (_Left_uint ^ _Left_xor) + _Left_sign;
                const _Uint_type _Right_twos_complement_uint = (_Right_uint ^ _Right_xor) + _Right_sign;

                const auto _Left_twos_complement  = static_cast<_Sint_type>(_Left_twos_complement_uint);
                const auto _Right_twos_complement = static_cast<_Sint_type>(_Right_twos_complement_uint);

                                 return static_cast<weak_ordering>(_Left_twos_complement <=> _Right_twos_complement);
            } else if constexpr (_Strat == _St::_Three) {
                return static_cast<weak_ordering>(compare_three_way{}(_Left, _Right));
            } else if constexpr (_Strat == _St::_Strong) {
                return static_cast<weak_ordering>(
                    static_cast<strong_ordering>(  strong_order(_Left, _Right)));
            } else {
                static_assert(_Always_false<_Ty1>, "should be unreachable");
            }
        }
    };
}  
namespace _Cpos {
    inline constexpr _Weak_order::_Cpo weak_order;
}
using namespace _Cpos;

 namespace _Partial_order {
    void partial_order();  
    template <class _Ty1, class _Ty2>
    concept _Has_ADL = requires(_Ty1& _Left, _Ty2& _Right) {
        static_cast<partial_ordering>(  partial_order(_Left, _Right));
    };

    template <class _Ty1, class _Ty2>
    concept _Can_compare_three_way = requires(_Ty1& _Left, _Ty2& _Right) {
        static_cast<partial_ordering>(compare_three_way{}(_Left, _Right));
    };

              void weak_order();      void strong_order();  
    class _Cpo {
    private:
        enum class _St { _None, _Adl, _Three, _Weak, _Strong };

        template <class _Ty1, class _Ty2>
         static constexpr _Choice_t<_St> _Choose() noexcept {
            if constexpr (!same_as<decay_t<_Ty1>, decay_t<_Ty2>>) {
                return {_St::_None};
            } else if constexpr (_Has_ADL<_Ty1, _Ty2>) {
                return {_St::_Adl, noexcept(static_cast<partial_ordering>(
                                         partial_order(::std:: declval<_Ty1&>(), ::std:: declval<_Ty2&>())))};
            } else if constexpr (_Can_compare_three_way<_Ty1, _Ty2>) {
                return {_St::_Three, noexcept(static_cast<partial_ordering>(
                                         compare_three_way{}(::std:: declval<_Ty1&>(), ::std:: declval<_Ty2&>())))};
            } else if constexpr (_Weak_order::_Has_ADL<_Ty1, _Ty2>) {
                return {_St::_Weak,
                    noexcept(static_cast<partial_ordering>(static_cast<weak_ordering>(
                          weak_order(::std:: declval<_Ty1&>(), ::std:: declval<_Ty2&>()))))};
            } else if constexpr (_Strong_order::_Has_ADL<_Ty1, _Ty2>) {
                return {_St::_Strong, noexcept(static_cast<partial_ordering>(static_cast<strong_ordering>(
                                            strong_order(
                                              ::std:: declval<_Ty1&>(), ::std:: declval<_Ty2&>()))))};
            } else {
                return {_St::_None};
            }
        }

        template <class _Ty1, class _Ty2>
        static constexpr _Choice_t<_St> _Choice = _Choose<_Ty1, _Ty2>();

    public:
                 template <class _Ty1, class _Ty2>
            requires (_Choice<_Ty1&, _Ty2&>._Strategy != _St::_None)
         constexpr partial_ordering operator()(_Ty1&& _Left, _Ty2&& _Right) const
            noexcept(_Choice<_Ty1&, _Ty2&>._No_throw) {
                         constexpr _St _Strat = _Choice<_Ty1&, _Ty2&>._Strategy;
            if constexpr (_Strat == _St::_Adl) {
                return static_cast<partial_ordering>(  partial_order(_Left, _Right));
            } else if constexpr (_Strat == _St::_Three) {
                return static_cast<partial_ordering>(compare_three_way{}(_Left, _Right));
            } else if constexpr (_Strat == _St::_Weak) {
                return static_cast<partial_ordering>(
                    static_cast<weak_ordering>(  weak_order(_Left, _Right)));
            } else if constexpr (_Strat == _St::_Strong) {
                return static_cast<partial_ordering>(
                    static_cast<strong_ordering>(  strong_order(_Left, _Right)));
            } else {
                static_assert(_Always_false<_Ty1>, "should be unreachable");
            }
        }
    };
}  
namespace _Cpos {
    inline constexpr _Partial_order::_Cpo partial_order;
}
using namespace _Cpos;

 template <class _Ty1, class _Ty2>
concept _Can_fallback_eq_lt = requires(_Ty1& _Left, _Ty2& _Right) {
    { _Left == _Right } -> _Implicitly_convertible_to<bool>;
    { _Left <  _Right } -> _Implicitly_convertible_to<bool>;
};
 
 namespace _Compare_strong_order_fallback {
    template <class _Ty1, class _Ty2>
    concept _Can_strong_order = requires(_Ty1& _Left, _Ty2& _Right) {
        ::std:: strong_order(_Left, _Right);
    };

    class _Cpo {
    private:
        enum class _St { _None, _Strong, _Fallback };

        template <class _Ty1, class _Ty2>
         static constexpr _Choice_t<_St> _Choose() noexcept {
            if constexpr (!same_as<decay_t<_Ty1>, decay_t<_Ty2>>) {
                return {_St::_None};
            } else if constexpr (_Can_strong_order<_Ty1, _Ty2>) {
                return {_St::_Strong, noexcept(::std:: strong_order(::std:: declval<_Ty1&>(), ::std:: declval<_Ty2&>()))};
            } else if constexpr (_Can_fallback_eq_lt<_Ty1, _Ty2>) {
                return {_St::_Fallback,
                    noexcept(::std:: declval<_Ty1&>() == ::std:: declval<_Ty2&>()
                                 ? strong_ordering::equal
                                 : ::std:: declval<_Ty1&>() < ::std:: declval<_Ty2&>() ? strong_ordering::less
                                                                                 : strong_ordering::greater)};
            } else {
                return {_St::_None};
            }
        }

        template <class _Ty1, class _Ty2>
        static constexpr _Choice_t<_St> _Choice = _Choose<_Ty1, _Ty2>();

    public:
                 template <class _Ty1, class _Ty2>
            requires (_Choice<_Ty1&, _Ty2&>._Strategy != _St::_None)
         constexpr strong_ordering operator()(_Ty1&& _Left, _Ty2&& _Right) const
            noexcept(_Choice<_Ty1&, _Ty2&>._No_throw) {
                         constexpr _St _Strat = _Choice<_Ty1&, _Ty2&>._Strategy;
            if constexpr (_Strat == _St::_Strong) {
                return ::std:: strong_order(_Left, _Right);
            } else if constexpr (_Strat == _St::_Fallback) {
                return _Left == _Right ? strong_ordering::equal
                                       : _Left < _Right ? strong_ordering::less : strong_ordering::greater;
            } else {
                static_assert(_Always_false<_Ty1>, "should be unreachable");
            }
        }
    };
}  
namespace _Cpos {
    inline constexpr _Compare_strong_order_fallback::_Cpo compare_strong_order_fallback;
}
using namespace _Cpos;

 namespace _Compare_weak_order_fallback {
    template <class _Ty1, class _Ty2>
    concept _Can_weak_order = requires(_Ty1& _Left, _Ty2& _Right) {
        ::std:: weak_order(_Left, _Right);
    };

    class _Cpo {
    private:
        enum class _St { _None, _Weak, _Fallback };

        template <class _Ty1, class _Ty2>
         static constexpr _Choice_t<_St> _Choose() noexcept {
            if constexpr (!same_as<decay_t<_Ty1>, decay_t<_Ty2>>) {
                return {_St::_None};
            } else if constexpr (_Can_weak_order<_Ty1, _Ty2>) {
                return {_St::_Weak, noexcept(::std:: weak_order(::std:: declval<_Ty1&>(), ::std:: declval<_Ty2&>()))};
            } else if constexpr (_Can_fallback_eq_lt<_Ty1, _Ty2>) {
                return {_St::_Fallback,
                    noexcept(::std:: declval<_Ty1&>() == ::std:: declval<_Ty2&>()
                                 ? weak_ordering::equivalent
                                 : ::std:: declval<_Ty1&>() < ::std:: declval<_Ty2&>() ? weak_ordering::less
                                                                                 : weak_ordering::greater)};
            } else {
                return {_St::_None};
            }
        }

        template <class _Ty1, class _Ty2>
        static constexpr _Choice_t<_St> _Choice = _Choose<_Ty1, _Ty2>();

    public:
                 template <class _Ty1, class _Ty2>
            requires (_Choice<_Ty1&, _Ty2&>._Strategy != _St::_None)
         constexpr weak_ordering operator()(_Ty1&& _Left, _Ty2&& _Right) const
            noexcept(_Choice<_Ty1&, _Ty2&>._No_throw) {
                         constexpr _St _Strat = _Choice<_Ty1&, _Ty2&>._Strategy;
            if constexpr (_Strat == _St::_Weak) {
                return ::std:: weak_order(_Left, _Right);
            } else if constexpr (_Strat == _St::_Fallback) {
                return _Left == _Right ? weak_ordering::equivalent
                                       : _Left < _Right ? weak_ordering::less : weak_ordering::greater;
            } else {
                static_assert(_Always_false<_Ty1>, "should be unreachable");
            }
        }
    };
}  
namespace _Cpos {
    inline constexpr _Compare_weak_order_fallback::_Cpo compare_weak_order_fallback;
}
using namespace _Cpos;

 namespace _Compare_partial_order_fallback {
    template <class _Ty1, class _Ty2>
    concept _Can_partial_order = requires(_Ty1& _Left, _Ty2& _Right) {
        ::std:: partial_order(_Left, _Right);
    };

         template <class _Ty1, class _Ty2>
    concept _Can_fallback_eq_lt_twice = requires(_Ty1& _Left, _Ty2& _Right) {
        { _Left  == _Right } -> _Implicitly_convertible_to<bool>;
        { _Left  <  _Right } -> _Implicitly_convertible_to<bool>;
        { _Right <  _Left  } -> _Implicitly_convertible_to<bool>;
    };
     
    class _Cpo {
    private:
        enum class _St { _None, _Partial, _Fallback };

        template <class _Ty1, class _Ty2>
         static constexpr _Choice_t<_St> _Choose() noexcept {
            if constexpr (!same_as<decay_t<_Ty1>, decay_t<_Ty2>>) {
                return {_St::_None};
            } else if constexpr (_Can_partial_order<_Ty1, _Ty2>) {
                return {_St::_Partial, noexcept(::std:: partial_order(::std:: declval<_Ty1&>(), ::std:: declval<_Ty2&>()))};
            } else if constexpr (_Can_fallback_eq_lt_twice<_Ty1, _Ty2>) {
                return {_St::_Fallback,
                    noexcept(::std:: declval<_Ty1&>() == ::std:: declval<_Ty2&>()
                                 ? partial_ordering::equivalent
                                 : ::std:: declval<_Ty1&>() < ::std:: declval<_Ty2&>()
                                       ? partial_ordering::less
                                       : ::std:: declval<_Ty2&>() < ::std:: declval<_Ty1&>() ? partial_ordering::greater
                                                                                       : partial_ordering::unordered)};
            } else {
                return {_St::_None};
            }
        }

        template <class _Ty1, class _Ty2>
        static constexpr _Choice_t<_St> _Choice = _Choose<_Ty1, _Ty2>();

    public:
                 template <class _Ty1, class _Ty2>
            requires (_Choice<_Ty1&, _Ty2&>._Strategy != _St::_None)
         constexpr partial_ordering operator()(_Ty1&& _Left, _Ty2&& _Right) const
            noexcept(_Choice<_Ty1&, _Ty2&>._No_throw) {
                         constexpr _St _Strat = _Choice<_Ty1&, _Ty2&>._Strategy;
            if constexpr (_Strat == _St::_Partial) {
                return ::std:: partial_order(_Left, _Right);
            } else if constexpr (_Strat == _St::_Fallback) {
                return _Left == _Right
                           ? partial_ordering::equivalent
                           : _Left < _Right ? partial_ordering::less
                                            : _Right < _Left ? partial_ordering::greater : partial_ordering::unordered;
            } else {
                static_assert(_Always_false<_Ty1>, "should be unreachable");
            }
        }
    };
}  
namespace _Cpos {
    inline constexpr _Compare_partial_order_fallback::_Cpo compare_partial_order_fallback;
}
using namespace _Cpos;

}






namespace std {
 template <class _Ty, class _Pr>
 constexpr const _Ty&(max)(const _Ty& _Left, const _Ty& _Right, _Pr _Pred) noexcept(
    noexcept(_Pred(_Left, _Right)))   {
         return _Pred(_Left, _Right) ? _Right : _Left;
}

template <class _Ty>
   constexpr const _Ty&(max)(
    const _Ty& _Left, const _Ty& _Right) noexcept(noexcept(_Left < _Right))   {
         return _Left < _Right ? _Right : _Left;
}

template <class _Ty, class _Pr>
 constexpr _Ty(max)(initializer_list<_Ty>, _Pr);  
template <class _Ty>
 constexpr _Ty(max)(initializer_list<_Ty>);  
 template <class _Ty, class _Pr>
 constexpr const _Ty&(min)(const _Ty& _Left, const _Ty& _Right, _Pr _Pred) noexcept(
    noexcept(_Pred(_Right, _Left)))   {
         return _Pred(_Right, _Left) ? _Right : _Left;
}

template <class _Ty>
   constexpr const _Ty&(min)(
    const _Ty& _Left, const _Ty& _Right) noexcept(noexcept(_Right < _Left))   {
         return _Right < _Left ? _Right : _Left;
}

template <class _Ty, class _Pr>
 constexpr _Ty(min)(initializer_list<_Ty>, _Pr);  
template <class _Ty>
 constexpr _Ty(min)(initializer_list<_Ty>);  
 template <class _FwdIt1, class _FwdIt2>
constexpr void iter_swap(_FwdIt1 _Left, _FwdIt2 _Right) {      swap(*_Left, *_Right);
}

 template <class _Ty, size_t _Size, enable_if_t<_Is_swappable<_Ty>::value, int> _Enabled>
constexpr void swap(_Ty (&_Left)[_Size], _Ty (&_Right)[_Size]) noexcept(_Is_nothrow_swappable<_Ty>::value) {
    if (&_Left != &_Right) {
        _Ty* _First1 = _Left;
        _Ty* _Last1  = _First1 + _Size;
        _Ty* _First2 = _Right;
        for (; _First1 != _Last1; ++_First1, ++_First2) {
            ::std:: iter_swap(_First1, _First2);
        }
    }
}

template <class _Ty, enable_if_t<is_move_constructible_v<_Ty> && is_move_assignable_v<_Ty>, int> _Enabled>
constexpr void swap(_Ty& _Left, _Ty& _Right) noexcept(
    is_nothrow_move_constructible_v<_Ty>&& is_nothrow_move_assignable_v<_Ty>) {
    _Ty _Tmp = ::std:: move(_Left);
    _Left    = ::std:: move(_Right);
    _Right   = ::std:: move(_Tmp);
}

 template <class _Ty>
constexpr void _Swap_adl(_Ty& _Left, _Ty& _Right) noexcept(_Is_nothrow_swappable<_Ty>::value) {
    swap(_Left, _Right);
}

 struct piecewise_construct_t {      explicit piecewise_construct_t() = default;
};

inline constexpr piecewise_construct_t piecewise_construct{};

 template <class...>
class tuple;

template <size_t _Index, class... _Types>
 constexpr auto&& _Tuple_get(tuple<_Types...>&& _Tuple) noexcept;

template <class _Ty1, class _Ty2>
struct pair {      using first_type  = _Ty1;
    using second_type = _Ty2;

    template <class _Uty1 = _Ty1, class _Uty2 = _Ty2,
        enable_if_t<conjunction_v<is_default_constructible<_Uty1>, is_default_constructible<_Uty2>>, int> = 0>
    constexpr explicit(
        !conjunction_v<_Is_implicitly_default_constructible<_Uty1>, _Is_implicitly_default_constructible<_Uty2>>)
        pair() noexcept(
            is_nothrow_default_constructible_v<_Uty1>&& is_nothrow_default_constructible_v<_Uty2>)          : first(), second() {}

    template <class _Uty1 = _Ty1, class _Uty2 = _Ty2,
        enable_if_t<conjunction_v<is_copy_constructible<_Uty1>, is_copy_constructible<_Uty2>>, int> = 0>
    constexpr explicit(!conjunction_v<is_convertible<const _Uty1&, _Uty1>, is_convertible<const _Uty2&, _Uty2>>)
        pair(const _Ty1& _Val1, const _Ty2& _Val2) noexcept(
            is_nothrow_copy_constructible_v<_Uty1>&& is_nothrow_copy_constructible_v<_Uty2>)          : first(_Val1), second(_Val2) {}

    template <class _Other1, class _Other2,
        enable_if_t<conjunction_v<is_constructible<_Ty1, _Other1>, is_constructible<_Ty2, _Other2>>, int> = 0>
    constexpr explicit(!conjunction_v<is_convertible<_Other1, _Ty1>, is_convertible<_Other2, _Ty2>>)
        pair(_Other1&& _Val1, _Other2&& _Val2) noexcept(
            is_nothrow_constructible_v<_Ty1, _Other1>&& is_nothrow_constructible_v<_Ty2, _Other2>)          : first(::std:: forward<_Other1>(_Val1)), second(::std:: forward<_Other2>(_Val2)) {}

    pair(const pair&) = default;
    pair(pair&&)      = default;

    template <class _Other1, class _Other2,
        enable_if_t<conjunction_v<is_constructible<_Ty1, const _Other1&>, is_constructible<_Ty2, const _Other2&>>,
            int> = 0>
    constexpr explicit(!conjunction_v<is_convertible<const _Other1&, _Ty1>, is_convertible<const _Other2&, _Ty2>>)
        pair(const pair<_Other1, _Other2>& _Right) noexcept(is_nothrow_constructible_v<_Ty1, const _Other1&>&&
                is_nothrow_constructible_v<_Ty2, const _Other2&>)          : first(_Right.first), second(_Right.second) {}

    template <class _Other1, class _Other2,
        enable_if_t<conjunction_v<is_constructible<_Ty1, _Other1>, is_constructible<_Ty2, _Other2>>, int> = 0>
    constexpr explicit(!conjunction_v<is_convertible<_Other1, _Ty1>, is_convertible<_Other2, _Ty2>>)
        pair(pair<_Other1, _Other2>&& _Right) noexcept(
            is_nothrow_constructible_v<_Ty1, _Other1>&& is_nothrow_constructible_v<_Ty2, _Other2>)          : first(::std:: forward<_Other1>(_Right.first)), second(::std:: forward<_Other2>(_Right.second)) {}

    template <class _Tuple1, class _Tuple2, size_t... _Indexes1, size_t... _Indexes2>
    constexpr pair(_Tuple1& _Val1, _Tuple2& _Val2, index_sequence<_Indexes1...>, index_sequence<_Indexes2...>)
        : first(_Tuple_get<_Indexes1>(::std:: move(_Val1))...), second(_Tuple_get<_Indexes2>(::std:: move(_Val2))...) {}

    template <class... _Types1, class... _Types2>
    constexpr pair(piecewise_construct_t, tuple<_Types1...> _Val1, tuple<_Types2...> _Val2)
        : pair(_Val1, _Val2, index_sequence_for<_Types1...>{}, index_sequence_for<_Types2...>{}) {}

    pair& operator=(const volatile pair&) = delete;

    template <class _Myself = pair,
        enable_if_t<conjunction_v<_Is_copy_assignable_no_precondition_check<typename _Myself::first_type>,
                        _Is_copy_assignable_no_precondition_check<typename _Myself::second_type>>,
            int>            = 0>
    constexpr pair& operator=(_Identity_t<const _Myself&> _Right) noexcept(
        conjunction_v<is_nothrow_copy_assignable<_Ty1>, is_nothrow_copy_assignable<_Ty2>>)   {
        first  = _Right.first;
        second = _Right.second;
        return *this;
    }

    template <class _Myself = pair,
        enable_if_t<conjunction_v<_Is_move_assignable_no_precondition_check<typename _Myself::first_type>,
                        _Is_move_assignable_no_precondition_check<typename _Myself::second_type>>,
            int>            = 0>
    constexpr pair& operator=(_Identity_t<_Myself&&> _Right) noexcept(
        conjunction_v<is_nothrow_move_assignable<_Ty1>, is_nothrow_move_assignable<_Ty2>>)   {
        first  = ::std:: forward<_Ty1>(_Right.first);
        second = ::std:: forward<_Ty2>(_Right.second);
        return *this;
    }

    template <class _Other1, class _Other2,
        enable_if_t<conjunction_v<negation<is_same<pair, pair<_Other1, _Other2>>>, is_assignable<_Ty1&, const _Other1&>,
                        is_assignable<_Ty2&, const _Other2&>>,
            int> = 0>
    constexpr pair& operator=(const pair<_Other1, _Other2>& _Right) noexcept(
        is_nothrow_assignable_v<_Ty1&, const _Other1&>&&
            is_nothrow_assignable_v<_Ty2&, const _Other2&>)   {
        first  = _Right.first;
        second = _Right.second;
        return *this;
    }

    template <class _Other1, class _Other2,
        enable_if_t<conjunction_v<negation<is_same<pair, pair<_Other1, _Other2>>>, is_assignable<_Ty1&, _Other1>,
                        is_assignable<_Ty2&, _Other2>>,
            int> = 0>
    constexpr pair& operator=(pair<_Other1, _Other2>&& _Right) noexcept(
        is_nothrow_assignable_v<_Ty1&, _Other1>&& is_nothrow_assignable_v<_Ty2&, _Other2>)   {
        first  = ::std:: forward<_Other1>(_Right.first);
        second = ::std:: forward<_Other2>(_Right.second);
        return *this;
    }

    constexpr void swap(pair& _Right) noexcept(
        _Is_nothrow_swappable<_Ty1>::value&& _Is_nothrow_swappable<_Ty2>::value) {
        if (this != ::std:: addressof(_Right)) {
            _Swap_adl(first, _Right.first);
            _Swap_adl(second, _Right.second);
        }
    }

    _Ty1 first;      _Ty2 second;  };

template <class _Ty1, class _Ty2>
pair(_Ty1, _Ty2) -> pair<_Ty1, _Ty2>;

template <class _Ty1, class _Ty2, enable_if_t<_Is_swappable<_Ty1>::value && _Is_swappable<_Ty2>::value, int> = 0>
constexpr void swap(pair<_Ty1, _Ty2>& _Left, pair<_Ty1, _Ty2>& _Right) noexcept(noexcept(_Left.swap(_Right))) {
    _Left.swap(_Right);
}

template <class _Ty1, class _Ty2>
 constexpr bool operator==(const pair<_Ty1, _Ty2>& _Left, const pair<_Ty1, _Ty2>& _Right) {
    return _Left.first == _Right.first && _Left.second == _Right.second;
}

template <class _Ty1, class _Ty2>
 constexpr bool operator!=(const pair<_Ty1, _Ty2>& _Left, const pair<_Ty1, _Ty2>& _Right) {
    return !(_Left == _Right);
}

template <class _Ty1, class _Ty2>
 constexpr bool operator<(const pair<_Ty1, _Ty2>& _Left, const pair<_Ty1, _Ty2>& _Right) {
    return _Left.first < _Right.first || (!(_Right.first < _Left.first) && _Left.second < _Right.second);
}

template <class _Ty1, class _Ty2>
 constexpr bool operator>(const pair<_Ty1, _Ty2>& _Left, const pair<_Ty1, _Ty2>& _Right) {
    return _Right < _Left;
}

template <class _Ty1, class _Ty2>
 constexpr bool operator<=(const pair<_Ty1, _Ty2>& _Left, const pair<_Ty1, _Ty2>& _Right) {
    return !(_Right < _Left);
}

template <class _Ty1, class _Ty2>
 constexpr bool operator>=(const pair<_Ty1, _Ty2>& _Left, const pair<_Ty1, _Ty2>& _Right) {
    return !(_Left < _Right);
}

 template <class _Ty>
struct _Unrefwrap_helper {      using type = _Ty;
};

template <class _Ty>
struct _Unrefwrap_helper<reference_wrapper<_Ty>> {      using type = _Ty&;
};

 template <class _Ty>
using _Unrefwrap_t = typename _Unrefwrap_helper<decay_t<_Ty>>::type;

 template <class _Ty1, class _Ty2>
 constexpr pair<_Unrefwrap_t<_Ty1>, _Unrefwrap_t<_Ty2>> make_pair(_Ty1&& _Val1, _Ty2&& _Val2) noexcept(
    is_nothrow_constructible_v<_Unrefwrap_t<_Ty1>, _Ty1>&&
        is_nothrow_constructible_v<_Unrefwrap_t<_Ty2>, _Ty2>)   {
         using _Mypair = pair<_Unrefwrap_t<_Ty1>, _Unrefwrap_t<_Ty2>>;
    return _Mypair(::std:: forward<_Ty1>(_Val1), ::std:: forward<_Ty2>(_Val2));
}

namespace [[deprecated("warning STL4027: The namespace std::rel_ops and its contents are deprecated in C++20. Their use is superseded by C++20\'s <=> operator and automatic rewrites of relational expressions. You can define _SILENCE_CXX20_REL_OPS_DEPRECATION_WARNING or _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] rel_ops {
    template <class _Ty>
    [[deprecated("warning STL4027: The namespace std::rel_ops and its contents are deprecated in C++20. Their use is superseded by C++20\'s <=> operator and automatic rewrites of relational expressions. You can define _SILENCE_CXX20_REL_OPS_DEPRECATION_WARNING or _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]]  bool operator!=(const _Ty& _Left, const _Ty& _Right) {
        return !(_Left == _Right);
    }

    template <class _Ty>
    [[deprecated("warning STL4027: The namespace std::rel_ops and its contents are deprecated in C++20. Their use is superseded by C++20\'s <=> operator and automatic rewrites of relational expressions. You can define _SILENCE_CXX20_REL_OPS_DEPRECATION_WARNING or _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]]  bool operator>(const _Ty& _Left, const _Ty& _Right) {
        return _Right < _Left;
    }

    template <class _Ty>
    [[deprecated("warning STL4027: The namespace std::rel_ops and its contents are deprecated in C++20. Their use is superseded by C++20\'s <=> operator and automatic rewrites of relational expressions. You can define _SILENCE_CXX20_REL_OPS_DEPRECATION_WARNING or _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]]  bool operator<=(const _Ty& _Left, const _Ty& _Right) {
        return !(_Right < _Left);
    }

    template <class _Ty>
    [[deprecated("warning STL4027: The namespace std::rel_ops and its contents are deprecated in C++20. Their use is superseded by C++20\'s <=> operator and automatic rewrites of relational expressions. You can define _SILENCE_CXX20_REL_OPS_DEPRECATION_WARNING or _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]]  bool operator>=(const _Ty& _Left, const _Ty& _Right) {
        return !(_Left < _Right);
    }
}  
 template <class _Tuple>
struct tuple_size;

template <class _Tuple, class = void>
struct _Tuple_size_sfinae {};  
template <class _Tuple>
struct _Tuple_size_sfinae<_Tuple, void_t<decltype(tuple_size<_Tuple>::value)>>
    : integral_constant<size_t, tuple_size<_Tuple>::value> {};  
template <class _Tuple>
struct tuple_size<const _Tuple> : _Tuple_size_sfinae<_Tuple> {};  
template <class _Tuple>
struct [[deprecated("warning STL4030: Some operations on volatile-qualified types in the STL are deprecated in C++20. You can define _SILENCE_CXX20_VOLATILE_DEPRECATION_WARNING or _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] tuple_size<volatile _Tuple> : _Tuple_size_sfinae<_Tuple> {};  
template <class _Tuple>
struct [[deprecated("warning STL4030: Some operations on volatile-qualified types in the STL are deprecated in C++20. You can define _SILENCE_CXX20_VOLATILE_DEPRECATION_WARNING or _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] tuple_size<const volatile _Tuple> : _Tuple_size_sfinae<_Tuple> {};  
template <class _Ty>
inline constexpr size_t tuple_size_v = tuple_size<_Ty>::value;

template <size_t _Index, class _Tuple>
struct tuple_element;

template <size_t _Index, class _Tuple>
struct  tuple_element<_Index, const _Tuple> : tuple_element<_Index, _Tuple> {
    using _Mybase = tuple_element<_Index, _Tuple>;
    using type    = add_const_t<typename _Mybase::type>;
};

template <size_t _Index, class _Tuple>
struct [[deprecated("warning STL4030: Some operations on volatile-qualified types in the STL are deprecated in C++20. You can define _SILENCE_CXX20_VOLATILE_DEPRECATION_WARNING or _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]]  tuple_element<_Index, volatile _Tuple>
    : tuple_element<_Index, _Tuple> {
    using _Mybase = tuple_element<_Index, _Tuple>;
    using type    = add_volatile_t<typename _Mybase::type>;
};

template <size_t _Index, class _Tuple>
struct [[deprecated("warning STL4030: Some operations on volatile-qualified types in the STL are deprecated in C++20. You can define _SILENCE_CXX20_VOLATILE_DEPRECATION_WARNING or _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]]  tuple_element<_Index, const volatile _Tuple>
    : tuple_element<_Index, _Tuple> {
    using _Mybase = tuple_element<_Index, _Tuple>;
    using type    = add_cv_t<typename _Mybase::type>;
};

template <size_t _Index, class _Tuple>
using tuple_element_t = typename tuple_element<_Index, _Tuple>::type;

 template <class _Ty, size_t _Size>
class array;

template <class _Ty, size_t _Size>
struct tuple_size<array<_Ty, _Size>> : integral_constant<size_t, _Size> {};  
template <size_t _Idx, class _Ty, size_t _Size>
struct  tuple_element<_Idx, array<_Ty, _Size>> {
    static_assert(_Idx < _Size, "array index out of bounds");

    using type = _Ty;
};

 template <class... _Types>
struct tuple_size<tuple<_Types...>> : integral_constant<size_t, sizeof...(_Types)> {};  
template <size_t _Index>
struct  tuple_element<_Index, tuple<>> {      static_assert(_Always_false<integral_constant<size_t, _Index>>, "tuple index out of bounds");
};

template <class _This, class... _Rest>
struct  tuple_element<0, tuple<_This, _Rest...>> {      using type = _This;
         using _Ttype = tuple<_This, _Rest...>;
};

template <size_t _Index, class _This, class... _Rest>
struct  tuple_element<_Index, tuple<_This, _Rest...>>
    : tuple_element<_Index - 1, tuple<_Rest...>> {};  
 template <class _Ty1, class _Ty2>
struct tuple_size<pair<_Ty1, _Ty2>> : integral_constant<size_t, 2> {};  
template <size_t _Idx, class _Ty1, class _Ty2>
struct  tuple_element<_Idx, pair<_Ty1, _Ty2>> {
    static_assert(_Idx < 2, "pair index out of bounds");

    using type = conditional_t<_Idx == 0, _Ty1, _Ty2>;
};

template <class _Ret, class _Pair>
constexpr _Ret _Pair_get(_Pair& _Pr, integral_constant<size_t, 0>) noexcept {      return _Pr.first;
}

template <class _Ret, class _Pair>
constexpr _Ret _Pair_get(_Pair& _Pr, integral_constant<size_t, 1>) noexcept {      return _Pr.second;
}

template <size_t _Idx, class _Ty1, class _Ty2>
 constexpr tuple_element_t<_Idx, pair<_Ty1, _Ty2>>& get(
    pair<_Ty1, _Ty2>& _Pr) noexcept {      using _Rtype = tuple_element_t<_Idx, pair<_Ty1, _Ty2>>&;
    return _Pair_get<_Rtype>(_Pr, integral_constant<size_t, _Idx>{});
}

template <class _Ty1, class _Ty2>
 constexpr _Ty1& get(pair<_Ty1, _Ty2>& _Pr) noexcept {      return ::std:: get<0>(_Pr);
}

template <class _Ty2, class _Ty1>
 constexpr _Ty2& get(pair<_Ty1, _Ty2>& _Pr) noexcept {      return ::std:: get<1>(_Pr);
}

template <size_t _Idx, class _Ty1, class _Ty2>
 constexpr const tuple_element_t<_Idx, pair<_Ty1, _Ty2>>& get(
    const pair<_Ty1, _Ty2>& _Pr) noexcept {      using _Ctype = const tuple_element_t<_Idx, pair<_Ty1, _Ty2>>&;
    return _Pair_get<_Ctype>(_Pr, integral_constant<size_t, _Idx>{});
}

template <class _Ty1, class _Ty2>
 constexpr const _Ty1& get(
    const pair<_Ty1, _Ty2>& _Pr) noexcept {      return ::std:: get<0>(_Pr);
}

template <class _Ty2, class _Ty1>
 constexpr const _Ty2& get(
    const pair<_Ty1, _Ty2>& _Pr) noexcept {      return ::std:: get<1>(_Pr);
}

template <size_t _Idx, class _Ty1, class _Ty2>
 constexpr tuple_element_t<_Idx, pair<_Ty1, _Ty2>>&& get(
    pair<_Ty1, _Ty2>&& _Pr) noexcept {      using _RRtype = tuple_element_t<_Idx, pair<_Ty1, _Ty2>>&&;
    return ::std:: forward<_RRtype>(::std:: get<_Idx>(_Pr));
}

template <class _Ty1, class _Ty2>
 constexpr _Ty1&& get(pair<_Ty1, _Ty2>&& _Pr) noexcept {      return ::std:: get<0>(::std:: move(_Pr));
}

template <class _Ty2, class _Ty1>
 constexpr _Ty2&& get(pair<_Ty1, _Ty2>&& _Pr) noexcept {      return ::std:: get<1>(::std:: move(_Pr));
}

template <size_t _Idx, class _Ty1, class _Ty2>
 constexpr const tuple_element_t<_Idx, pair<_Ty1, _Ty2>>&& get(
    const pair<_Ty1, _Ty2>&& _Pr) noexcept {      using _RRtype = const tuple_element_t<_Idx, pair<_Ty1, _Ty2>>&&;
    return ::std:: forward<_RRtype>(::std:: get<_Idx>(_Pr));
}

template <class _Ty1, class _Ty2>
 constexpr const _Ty1&& get(
    const pair<_Ty1, _Ty2>&& _Pr) noexcept {      return ::std:: get<0>(::std:: move(_Pr));
}

template <class _Ty2, class _Ty1>
 constexpr const _Ty2&& get(
    const pair<_Ty1, _Ty2>&& _Pr) noexcept {      return ::std:: get<1>(::std:: move(_Pr));
}

 template <class _Ty, class _Other = _Ty>
constexpr _Ty exchange(_Ty& _Val, _Other&& _New_val) noexcept(
    conjunction_v<is_nothrow_move_constructible<_Ty>, is_nothrow_assignable<_Ty&, _Other>>)   {
         _Ty _Old_val = static_cast<_Ty&&>(_Val);
    _Val         = static_cast<_Other&&>(_New_val);
    return _Old_val;
}

 template <class _Ty>
 constexpr add_const_t<_Ty>& as_const(_Ty& _Val) noexcept {      return _Val;
}

template <class _Ty>
void as_const(const _Ty&&) = delete;

 struct in_place_t {      explicit in_place_t() = default;
};
inline constexpr in_place_t in_place{};

template <class>
struct in_place_type_t {      explicit in_place_type_t() = default;
};
template <class _Ty>
inline constexpr in_place_type_t<_Ty> in_place_type{};

template <size_t>
struct in_place_index_t {      explicit in_place_index_t() = default;
};
template <size_t _Idx>
inline constexpr in_place_index_t<_Idx> in_place_index{};

template <class _Ty>
inline constexpr bool _Is_standard_integer = is_integral_v<_Ty>
    && !_Is_any_of_v<remove_cv_t<_Ty>, bool, char,
        wchar_t,
        char8_t,
        char16_t, char32_t>;

 template <class _Ty1, class _Ty2>
 constexpr bool cmp_equal(const _Ty1 _Left, const _Ty2 _Right) noexcept {
    static_assert(_Is_standard_integer<_Ty1> && _Is_standard_integer<_Ty2>,
        "The integer comparison functions only accept standard and extended integer types.");
    if constexpr (is_signed_v<_Ty1> == is_signed_v<_Ty2>) {
        return _Left == _Right;
    } else if constexpr (is_signed_v<_Ty2>) {
        return _Left == static_cast<make_unsigned_t<_Ty2>>(_Right) && _Right >= 0;
    } else {
        return static_cast<make_unsigned_t<_Ty1>>(_Left) == _Right && _Left >= 0;
    }
}

 template <class _Ty1, class _Ty2>
 constexpr bool cmp_not_equal(const _Ty1 _Left, const _Ty2 _Right) noexcept {
    return !::std:: cmp_equal(_Left, _Right);
}

 template <class _Ty1, class _Ty2>
 constexpr bool cmp_less(const _Ty1 _Left, const _Ty2 _Right) noexcept {
    static_assert(_Is_standard_integer<_Ty1> && _Is_standard_integer<_Ty2>,
        "The integer comparison functions only accept standard and extended integer types.");
    if constexpr (is_signed_v<_Ty1> == is_signed_v<_Ty2>) {
        return _Left < _Right;
    } else if constexpr (is_signed_v<_Ty2>) {
        return _Right > 0 && _Left < static_cast<make_unsigned_t<_Ty2>>(_Right);
    } else {
        return _Left < 0 || static_cast<make_unsigned_t<_Ty1>>(_Left) < _Right;
    }
}

 template <class _Ty1, class _Ty2>
 constexpr bool cmp_greater(const _Ty1 _Left, const _Ty2 _Right) noexcept {
    return ::std:: cmp_less(_Right, _Left);
}

 template <class _Ty1, class _Ty2>
 constexpr bool cmp_less_equal(const _Ty1 _Left, const _Ty2 _Right) noexcept {
    return !::std:: cmp_less(_Right, _Left);
}

 template <class _Ty1, class _Ty2>
 constexpr bool cmp_greater_equal(const _Ty1 _Left, const _Ty2 _Right) noexcept {
    return !::std:: cmp_less(_Left, _Right);
}

 template <class _Ty>
 constexpr _Ty _Min_limit() noexcept {      static_assert(_Is_standard_integer<_Ty>);      if constexpr (is_signed_v<_Ty>) {
        constexpr auto _Unsigned_max = static_cast<make_unsigned_t<_Ty>>(-1);
        return static_cast<_Ty>((_Unsigned_max >> 1) + 1);      } else {
        return 0;
    }
}

template <class _Ty>
 constexpr _Ty _Max_limit() noexcept {      static_assert(_Is_standard_integer<_Ty>);      if constexpr (is_signed_v<_Ty>) {
        constexpr auto _Unsigned_max = static_cast<make_unsigned_t<_Ty>>(-1);
        return static_cast<_Ty>(_Unsigned_max >> 1);
    } else {
        return static_cast<_Ty>(-1);
    }
}

template <class _Rx, class _Ty>
 constexpr bool in_range(const _Ty _Value) noexcept {
    static_assert(_Is_standard_integer<_Rx> && _Is_standard_integer<_Ty>,
        "The integer comparison functions only accept standard and extended integer types.");

    constexpr auto _Ty_min = _Min_limit<_Ty>();
    constexpr auto _Rx_min = _Min_limit<_Rx>();

    if constexpr (::std:: cmp_less(_Ty_min, _Rx_min)) {
        if (_Value < _Ty{_Rx_min}) {
            return false;
        }
    }

    constexpr auto _Ty_max = _Max_limit<_Ty>();
    constexpr auto _Rx_max = _Max_limit<_Rx>();

    if constexpr (::std:: cmp_greater(_Ty_max, _Rx_max)) {
        if (_Value > _Ty{_Rx_max}) {
            return false;
        }
    }

    return true;
}


}







extern "C" {
       __declspec(noalias) void __cdecl __std_reverse_trivially_swappable_1(void* _First, void* _Last) noexcept;
__declspec(noalias) void __cdecl __std_reverse_trivially_swappable_2(void* _First, void* _Last) noexcept;
__declspec(noalias) void __cdecl __std_reverse_trivially_swappable_4(void* _First, void* _Last) noexcept;
__declspec(noalias) void __cdecl __std_reverse_trivially_swappable_8(void* _First, void* _Last) noexcept;
__declspec(noalias) void __cdecl __std_swap_ranges_trivially_swappable_noalias(
    void* _First1, void* _Last1, void* _First2) noexcept;
}

namespace std {

 template <class _To, class _From,
    enable_if_t<conjunction_v<bool_constant<sizeof(_To) == sizeof(_From)>, is_trivially_copyable<_To>,
                    is_trivially_copyable<_From>>,
        int> = 0>
 constexpr _To _Bit_cast(const _From& _Val) noexcept {
    return __builtin_bit_cast(_To, _Val);
}

 template <class _Ty>
struct _Get_first_parameter;

template <template <class, class...> class _Ty, class _First, class... _Rest>
struct _Get_first_parameter<_Ty<_First, _Rest...>> {      using type = _First;
};

 template <class _Newfirst, class _Ty>
struct _Replace_first_parameter;

template <class _Newfirst, template <class, class...> class _Ty, class _First, class... _Rest>
struct _Replace_first_parameter<_Newfirst, _Ty<_First, _Rest...>> {      using type = _Ty<_Newfirst, _Rest...>;
};

 template <class _Ty, class = void>
struct _Get_element_type {
    using type = typename _Get_first_parameter<_Ty>::type;
};

template <class _Ty>
struct _Get_element_type<_Ty, void_t<typename _Ty::element_type>> {
    using type = typename _Ty::element_type;
};

 template <class _Ty, class = void>
struct _Get_ptr_difference_type {
    using type = ptrdiff_t;
};

template <class _Ty>
struct _Get_ptr_difference_type<_Ty, void_t<typename _Ty::difference_type>> {
    using type = typename _Ty::difference_type;
};

 template <class _Ty, class _Other, class = void>
struct _Get_rebind_alias {
    using type = typename _Replace_first_parameter<_Other, _Ty>::type;
};

template <class _Ty, class _Other>
struct _Get_rebind_alias<_Ty, _Other, void_t<typename _Ty::template rebind<_Other>>> {
    using type = typename _Ty::template rebind<_Other>;
};

 template <class _Iter>
 void* _Voidify_iter(_Iter _It) noexcept {
    if constexpr (is_pointer_v<_Iter>) {
        return const_cast<void*>(static_cast<const volatile void*>(_It));
    } else
    {
        return const_cast<void*>(static_cast<const volatile void*>(::std:: addressof(*_It)));
    }
}

 template <class _Ty, class... _Types>
void _Construct_in_place(_Ty& _Obj, _Types&&... _Args) noexcept(is_nothrow_constructible_v<_Ty, _Types...>) {
    ::new (_Voidify_iter(::std:: addressof(_Obj))) _Ty(::std:: forward<_Types>(_Args)...);
}

 template <class _Ty>
void _Default_construct_in_place(_Ty& _Obj) noexcept(is_nothrow_default_constructible_v<_Ty>) {
    ::new (_Voidify_iter(::std:: addressof(_Obj))) _Ty;
}

 template <class _Ty>
struct pointer_traits {
    using pointer         = _Ty;
    using element_type    = typename _Get_element_type<_Ty>::type;
    using difference_type = typename _Get_ptr_difference_type<_Ty>::type;

    template <class _Other>
    using rebind = typename _Get_rebind_alias<_Ty, _Other>::type;

    using _Reftype = conditional_t<is_void_v<element_type>, char, element_type>&;

     static pointer pointer_to(_Reftype _Val) noexcept(noexcept(_Ty::pointer_to(_Val)))   {
        return _Ty::pointer_to(_Val);
    }
};

template <class _Ty>
struct pointer_traits<_Ty*> {
    using pointer         = _Ty*;
    using element_type    = _Ty;
    using difference_type = ptrdiff_t;

    template <class _Other>
    using rebind = _Other*;

    using _Reftype = conditional_t<is_void_v<_Ty>, char, _Ty>&;

     static constexpr pointer pointer_to(_Reftype _Val) noexcept {
        return ::std:: addressof(_Val);
    }
};

 template <class _Ty, class = void>
inline constexpr bool _Has_to_address_v = false;  
template <class _Ty>
inline constexpr bool
    _Has_to_address_v<_Ty, void_t<decltype(pointer_traits<_Ty>::to_address(::std:: declval<const _Ty&>()))>> = true;

template <class _Ty>
 constexpr _Ty* to_address(_Ty* const _Val) noexcept {
    static_assert(!is_function_v<_Ty>,
        "N4810 20.10.4 [pointer.conversion]/2: The program is ill-formed if T is a function type.");
    return _Val;
}

template <class _Ptr>
 constexpr auto to_address(const _Ptr& _Val) noexcept {
    if constexpr (_Has_to_address_v<_Ptr>) {
        return pointer_traits<_Ptr>::to_address(_Val);
    } else {
        return ::std:: to_address(_Val.operator->());      }
}

 struct identity {
    template <class _Ty>
     constexpr _Ty&& operator()(_Ty&& _Left) const noexcept {
        return ::std:: forward<_Ty>(_Left);
    }

    using is_transparent = int;
};

  template <class _Fx>
struct _Ref_fn {      template <class... _Args>
    constexpr decltype(auto) operator()(_Args&&... _Vals) {          if constexpr (is_member_pointer_v<_Fx>) {
            return ::std:: invoke(_Fn, ::std:: forward<_Args>(_Vals)...);
        } else
        {
            return _Fn(::std:: forward<_Args>(_Vals)...);
        }
    }

    _Fx& _Fn;
};

template <class _Fn>
inline constexpr bool _Pass_functor_by_value_v = conjunction_v<bool_constant<sizeof(_Fn) <= sizeof(void*)>,
    is_trivially_copy_constructible<_Fn>, is_trivially_destructible<_Fn>>;

template <class _Fn, enable_if_t<_Pass_functor_by_value_v<_Fn>, int> = 0>  constexpr _Fn _Pass_fn(_Fn _Val) {      return _Val;
}

template <class _Fn, enable_if_t<!_Pass_functor_by_value_v<_Fn>, int> = 0>
constexpr _Ref_fn<_Fn> _Pass_fn(_Fn& _Val) {      return {_Val};
}

 struct _Unused_parameter {      constexpr _Unused_parameter() noexcept = default;
    template <class _Ty>
    constexpr _Unused_parameter(_Ty&&) noexcept {}
};

 using _Any_tag = _Unused_parameter;  
 template <class _Ty>
using _Algorithm_int_t = conditional_t<is_integral_v<_Ty>, _Ty, ptrdiff_t>;

  struct input_iterator_tag {};

struct output_iterator_tag {};

struct forward_iterator_tag : input_iterator_tag {};

struct bidirectional_iterator_tag : forward_iterator_tag {};

struct random_access_iterator_tag : bidirectional_iterator_tag {};

struct contiguous_iterator_tag : random_access_iterator_tag {};

 template <class _Ty>
using _With_reference = _Ty&;

  template <class _Ty>
concept _Can_reference = requires { typename _With_reference<_Ty>; };

 template <class _Ty>
concept _Dereferenceable = requires(_Ty& __t) {
    { *__t } -> _Can_reference;
};
 
 template <class _Ty>
concept _Has_member_iterator_concept = requires {
    typename _Ty::iterator_concept;
};

 template <class _Ty>
concept _Has_member_iterator_category = requires {
    typename _Ty::iterator_category;
};

 template <class _Ty>
concept _Has_member_value_type = requires {
    typename _Ty::value_type;
};

 template <class _Ty>
concept _Has_member_element_type = requires {
    typename _Ty::element_type;
};

 template <class _Ty>
concept _Has_member_difference_type = requires {
    typename _Ty::difference_type;
};

 template <class _Ty>
concept _Has_member_pointer = requires {
    typename _Ty::pointer;
};

 template <class _Ty>
concept _Has_member_reference = requires {
    typename _Ty::reference;
};

 template <class>
struct incrementable_traits {};

 template <class _Ty>
    requires is_object_v<_Ty>
struct incrementable_traits<_Ty*> {
    using difference_type = ptrdiff_t;
};
 
template <class _Ty>
struct incrementable_traits<const _Ty> : incrementable_traits<_Ty> {};

template <_Has_member_difference_type _Ty>
struct incrementable_traits<_Ty> {
    using difference_type = typename _Ty::difference_type;
};

 template <class _Ty>
concept _Can_difference = requires(const _Ty& __a, const _Ty& __b) {
    { __a - __b } -> integral;
};

template <class _Ty>
    requires (!_Has_member_difference_type<_Ty> && _Can_difference<_Ty>)
struct incrementable_traits<_Ty> {
    using difference_type = make_signed_t<decltype(::std:: declval<_Ty>() - ::std:: declval<_Ty>())>;
};
 
 template <class _Ty>
concept _Is_from_primary = _Same_impl<typename _Ty::_From_primary, _Ty>;

template <class>
struct iterator_traits;

template <class _Ty>
using iter_difference_t = typename conditional_t<_Is_from_primary<iterator_traits<remove_cvref_t<_Ty>>>,
    incrementable_traits<remove_cvref_t<_Ty>>, iterator_traits<remove_cvref_t<_Ty>>>::difference_type;

 template <class>
struct _Cond_value_type {};

 template <class _Ty>
    requires is_object_v<_Ty>
struct _Cond_value_type<_Ty> {
    using value_type = remove_cv_t<_Ty>;
};
 
template <class>
struct indirectly_readable_traits {};

template <class _Ty>
struct indirectly_readable_traits<_Ty*> : _Cond_value_type<_Ty> {};

 template <class _Ty>
    requires is_array_v<_Ty>
struct indirectly_readable_traits<_Ty> {
    using value_type = remove_cv_t<remove_extent_t<_Ty>>;
};
 
template <class _Ty>
struct indirectly_readable_traits<const _Ty> : indirectly_readable_traits<_Ty> {};

template <_Has_member_value_type _Ty>
struct indirectly_readable_traits<_Ty> : _Cond_value_type<typename _Ty::value_type> {};

template <_Has_member_element_type _Ty>
struct indirectly_readable_traits<_Ty> : _Cond_value_type<typename _Ty::element_type> {};

 template <_Has_member_value_type _Ty>
    requires _Has_member_element_type<_Ty>
        && same_as<remove_cv_t<typename _Ty::value_type>, remove_cv_t<typename _Ty::element_type>>
struct indirectly_readable_traits<_Ty> : _Cond_value_type<typename _Ty::value_type> {};
 
 template <class _Ty>
using iter_value_t = typename conditional_t<_Is_from_primary<iterator_traits<remove_cvref_t<_Ty>>>,
    indirectly_readable_traits<remove_cvref_t<_Ty>>, iterator_traits<remove_cvref_t<_Ty>>>::value_type;

 template <_Dereferenceable _Ty>
using iter_reference_t = decltype(*::std:: declval<_Ty&>());

 template <class>
struct _Iterator_traits_base {};

 template <class _It>
concept _Has_iter_types = _Has_member_difference_type<_It> && _Has_member_value_type<_It> && _Has_member_reference<_It>
    && _Has_member_iterator_category<_It>;
 
template <bool _Has_member_typedef>
struct _Old_iter_traits_pointer {
    template <class _It>
    using _Apply = typename _It::pointer;
};

template <>
struct _Old_iter_traits_pointer<false> {
    template <class>
    using _Apply = void;
};

template <_Has_iter_types _It>
struct _Iterator_traits_base<_It> {
    using iterator_category = typename _It::iterator_category;
    using difference_type   = typename _It::difference_type;
    using value_type        = typename _It::value_type;
    using pointer           = typename _Old_iter_traits_pointer<_Has_member_pointer<_It>>::template _Apply<_It>;
    using reference         = typename _It::reference;
};

template <bool _Has_member_typedef>
struct _Iter_traits_difference {
    template <class _It>
    using _Apply = typename incrementable_traits<_It>::difference_type;
};

template <>
struct _Iter_traits_difference<false> {
    template <class>
    using _Apply = void;
};

 template <class _It>
concept _Cpp17_iterator =
    requires(_It __i) {
        { *__i } -> _Can_reference;
        { ++__i } -> same_as<_It&>;
        { *__i++ } -> _Can_reference;
    }
    && copyable<_It>;

template <class _It>
concept _Cpp17_input_iterator = _Cpp17_iterator<_It>
    && equality_comparable<_It>
    && _Has_member_difference_type<incrementable_traits<_It>>
    && _Has_member_value_type<indirectly_readable_traits<_It>>
    && requires(_It __i) {
        typename common_reference_t<iter_reference_t<_It>&&, typename indirectly_readable_traits<_It>::value_type&>;
        typename common_reference_t<decltype(*__i++)&&, typename indirectly_readable_traits<_It>::value_type&>;
        requires signed_integral<typename incrementable_traits<_It>::difference_type>;
    };

template <class _It>
    requires (!_Has_iter_types<_It> && _Cpp17_iterator<_It> && !_Cpp17_input_iterator<_It>
                 && (!requires { typename _It::iterator_category; }
            || derived_from<typename _It::iterator_category, output_iterator_tag>))
struct _Iterator_traits_base<_It> {
    using iterator_category = output_iterator_tag;
    using difference_type =
        typename _Iter_traits_difference<_Has_member_difference_type<incrementable_traits<_It>>>::template _Apply<_It>;
    using value_type = void;
    using pointer    = void;
    using reference  = void;
};
 
enum class _Itraits_pointer_strategy { _Use_void, _Use_member, _Use_decltype };

template <_Itraits_pointer_strategy>
struct _Iter_traits_pointer;

template <>
struct _Iter_traits_pointer<_Itraits_pointer_strategy::_Use_void> {
    template <class>
    using _Apply = void;
};

template <>
struct _Iter_traits_pointer<_Itraits_pointer_strategy::_Use_member> {
    template <class _It>
    using _Apply = typename _It::pointer;
};

template <>
struct _Iter_traits_pointer<_Itraits_pointer_strategy::_Use_decltype> {
    template <class _It>
    using _Apply = decltype(::std:: declval<_It&>().operator->());
};

template <class _Ty>
concept _Has_member_arrow = requires(_Ty&& __t) {
    static_cast<_Ty&&>(__t).operator->();
};

template <bool _Has_member_typedef>
struct _Iter_traits_reference {
    template <class _It>
    using _Apply = typename _It::reference;
};

template <>
struct _Iter_traits_reference<false> {
    template <class _It>
    using _Apply = iter_reference_t<_It>;
};

template <bool _Is_random>
struct _Iter_traits_category4 {
    using type = random_access_iterator_tag;
};

template <>
struct _Iter_traits_category4<false> {
    using type = bidirectional_iterator_tag;
};

 template <class _It>
concept _Cpp17_random_delta = totally_ordered<_It>
    && requires(_It __i, typename incrementable_traits<_It>::difference_type __n) {
        { __i += __n } -> same_as<_It&>;
        { __i -= __n } -> same_as<_It&>;
        { __i +  __n } -> same_as<_It>;
        { __n +  __i } -> same_as<_It>;
        { __i -  __n } -> same_as<_It>;
        { __i -  __i } -> same_as<decltype(__n)>;
        {  __i[__n]  } -> convertible_to<iter_reference_t<_It>>;
    };
 
template <bool _Is_bidi>
struct _Iter_traits_category3 {
    template <class _It>
    using _Apply = typename _Iter_traits_category4<_Cpp17_random_delta<_It>>::type;
};

template <>
struct _Iter_traits_category3<false> {
    template <class>
    using _Apply = forward_iterator_tag;
};

 template <class _It>
concept _Cpp17_bidi_delta = requires(_It __i) {
    { --__i } -> same_as<_It&>;
    { __i-- } -> convertible_to<const _It&>;
    requires same_as<decltype(*__i--), iter_reference_t<_It>>;
};
 
template <bool _Is_forward>
struct _Iter_traits_category2 {
    template <class _It>
    using _Apply = typename _Iter_traits_category3<_Cpp17_bidi_delta<_It>>::template _Apply<_It>;
};

template <>
struct _Iter_traits_category2<false> {
    template <class>
    using _Apply = input_iterator_tag;
};

 template <class _It>
concept _Cpp17_forward_delta = constructible_from<_It> && is_lvalue_reference_v<iter_reference_t<_It>>
    && same_as<remove_cvref_t<iter_reference_t<_It>>, typename indirectly_readable_traits<_It>::value_type>
    && requires(_It __i) {
        { __i++ } -> convertible_to<const _It&>;
        requires same_as<decltype(*__i++), iter_reference_t<_It>>;
    };
 
template <bool _Has_member_typedef>
struct _Iter_traits_category {
    template <class _It>
    using _Apply = typename _It::iterator_category;
};

template <>
struct _Iter_traits_category<false> {
    template <class _It>
    using _Apply = typename _Iter_traits_category2<_Cpp17_forward_delta<_It>>::template _Apply<_It>;
};

 template <class _It>
    requires (!_Has_iter_types<_It> && _Cpp17_input_iterator<_It>)
struct _Iterator_traits_base<_It> {
    using iterator_category = typename _Iter_traits_category<_Has_member_iterator_category<_It>>::template _Apply<_It>;
    using difference_type   = typename incrementable_traits<_It>::difference_type;
    using value_type        = typename indirectly_readable_traits<_It>::value_type;
    using pointer           = typename _Iter_traits_pointer<(
        _Has_member_pointer<_It> ? _Itraits_pointer_strategy::_Use_member
                                 : _Has_member_arrow<_It&> ? _Itraits_pointer_strategy::_Use_decltype
                                                       : _Itraits_pointer_strategy::_Use_void)>::template _Apply<_It>;
    using reference         = typename _Iter_traits_reference<_Has_member_reference<_It>>::template _Apply<_It>;
};
 
 template <class _Ty>
struct iterator_traits : _Iterator_traits_base<_Ty> {
    using _From_primary = iterator_traits;
};

 template <class _Ty>
    requires is_object_v<_Ty>
struct iterator_traits<_Ty*> {
    using iterator_concept  = contiguous_iterator_tag;
    using iterator_category = random_access_iterator_tag;
    using value_type        = remove_cv_t<_Ty>;
    using difference_type   = ptrdiff_t;
    using pointer           = _Ty*;
    using reference         = _Ty&;
};
 
 namespace ranges {
    namespace _Iter_move {
        void iter_move();  
                 template <class _Ty>
        concept _Has_ADL = _Has_class_or_enum_type<_Ty> && requires(_Ty&& __t) {
            iter_move(static_cast<_Ty&&>(__t));
        };

        template <class _Ty>
        concept _Can_deref = requires(_Ty&& __t) {
            *static_cast<_Ty&&>(__t);
        };

        class _Cpo {
        private:
            enum class _St { _None, _Custom, _Fallback };

            template <class _Ty>
             static constexpr _Choice_t<_St> _Choose() noexcept {
                if constexpr (_Has_ADL<_Ty>) {
                    return {_St::_Custom, noexcept(iter_move(::std:: declval<_Ty>()))};
                } else if constexpr (_Can_deref<_Ty>) {
                    return {_St::_Fallback, noexcept(*::std:: declval<_Ty>())};
                } else {
                    return {_St::_None};
                }
            }

            template <class _Ty>
            static constexpr _Choice_t<_St> _Choice = _Choose<_Ty>();

        public:
            template <class _Ty>
                requires (_Choice<_Ty>._Strategy != _St::_None)
             constexpr decltype(auto) operator()(_Ty&& _Val) const noexcept(_Choice<_Ty>._No_throw) {
                constexpr _St _Strat = _Choice<_Ty>._Strategy;

                if constexpr (_Strat == _St::_Custom) {
                    return iter_move(static_cast<_Ty&&>(_Val));
                } else if constexpr (_Strat == _St::_Fallback) {
                    using _Ref = decltype(*static_cast<_Ty&&>(_Val));
                    if constexpr (is_lvalue_reference_v<_Ref>) {
                        return ::std:: move(*static_cast<_Ty&&>(_Val));
                    } else {
                        return *static_cast<_Ty&&>(_Val);
                    }
                } else {
                    static_assert(_Always_false<_Ty>, "should be unreachable");
                }
            }
        };
             }  
    namespace _Cpos {
        inline constexpr _Iter_move::_Cpo iter_move;
    }
    using namespace _Cpos;
}  
 
  template <class _Ty>
    requires _Dereferenceable<_Ty> && requires(_Ty& __t) {
        { ::std::ranges:: iter_move(__t) } -> _Can_reference;
    }
using iter_rvalue_reference_t = decltype(::std::ranges:: iter_move(::std:: declval<_Ty&>()));

 template <class _It>
concept _Indirectly_readable_impl = requires(const _It __i) {
    typename iter_value_t<_It>;
    typename iter_reference_t<_It>;
    typename iter_rvalue_reference_t<_It>;
    { *__i } -> same_as<iter_reference_t<_It>>;
    { ::std::ranges:: iter_move(__i) } -> same_as<iter_rvalue_reference_t<_It>>;
} && common_reference_with<iter_reference_t<_It>&&, iter_value_t<_It>&>
  && common_reference_with<iter_reference_t<_It>&&, iter_rvalue_reference_t<_It>&&>
  && common_reference_with<iter_rvalue_reference_t<_It>&&, const iter_value_t<_It>&>;

template <class _It>
concept indirectly_readable = _Indirectly_readable_impl<remove_cvref_t<_It>>;
 
 template <indirectly_readable _Ty>
using iter_common_reference_t = common_reference_t<iter_reference_t<_Ty>, iter_value_t<_Ty>&>;

 template <class _It, class _Ty>
concept indirectly_writable = requires(_It&& __i, _Ty&& __t) {
    *__i                                                                = static_cast<_Ty&&>(__t);
    *static_cast<_It&&>(__i)                                            = static_cast<_Ty&&>(__t);
    const_cast<const iter_reference_t<_It>&&>(*__i)                     = static_cast<_Ty&&>(__t);
    const_cast<const iter_reference_t<_It>&&>(*static_cast<_It&&>(__i)) = static_cast<_Ty&&>(__t);
};

  template <class _Ty>
concept _Integer_like = _Is_nonbool_integral<_Ty>;

 template <class _Ty>
concept _Signed_integer_like = _Integer_like<_Ty> && static_cast<_Ty>(-1) < static_cast<_Ty>(0);
 
 template <class _Ty>
using _Make_unsigned_like_t = make_unsigned_t<_Ty>;

 template <class _Ty>
using _Make_signed_like_t = make_signed_t<_Ty>;

  template <class _Ty>
concept weakly_incrementable = default_initializable<_Ty> && movable<_Ty> && requires(_Ty __i) {
    typename iter_difference_t<_Ty>;
    requires _Signed_integer_like<iter_difference_t<_Ty>>;
    { ++__i } -> same_as<_Ty&>;
    __i++;
};

 template <class _Ty>
concept incrementable = regular<_Ty> && weakly_incrementable<_Ty> && requires(_Ty __t) {
    { __t++ } -> same_as<_Ty>;
};

 template <class _It>
concept input_or_output_iterator = requires(_It __i) {
    { *__i } -> _Can_reference;
    requires weakly_incrementable<_It>;
};

 template <class _Se, class _It>
concept sentinel_for = semiregular<_Se>
    && input_or_output_iterator<_It>
    && _Weakly_equality_comparable_with<_Se, _It>;
 
 template <class _Se, class _It>
inline constexpr bool disable_sized_sentinel_for = false;

  template <class _Se, class _It>
concept sized_sentinel_for = sentinel_for<_Se, _It>
    && !disable_sized_sentinel_for<remove_cv_t<_Se>, remove_cv_t<_It>>
    && requires(const _It& __i, const _Se& __s) {
        { __s - __i } -> same_as<iter_difference_t<_It>>;
        { __i - __s } -> same_as<iter_difference_t<_It>>;
    };
 
 template <bool _Iterator_category_present>
struct _Iter_concept_impl2 {
    template <class _It, class _Traits>
    using _Apply = typename _Traits::iterator_category;
};
template <>
struct _Iter_concept_impl2<false> {
         template <class _It, class _Traits>
        requires _Is_from_primary<iterator_traits<_It>>
    using _Apply = random_access_iterator_tag;
     };

template <bool _Iterator_concept_present>
struct _Iter_concept_impl1 {
    template <class _It, class _Traits>
    using _Apply = typename _Traits::iterator_concept;
};
template <>
struct _Iter_concept_impl1<false> {
    template <class _It, class _Traits>
    using _Apply = typename _Iter_concept_impl2<_Has_member_iterator_category<_Traits>>::template _Apply<_It, _Traits>;
};

template <class _It, class _Traits = conditional_t<_Is_from_primary<iterator_traits<_It>>, _It, iterator_traits<_It>>>
using _Iter_concept =
    typename _Iter_concept_impl1<_Has_member_iterator_concept<_Traits>>::template _Apply<_It, _Traits>;

  template <class _It>
concept input_iterator = input_or_output_iterator<_It> && indirectly_readable<_It>
    && requires { typename _Iter_concept<_It>; }
    && derived_from<_Iter_concept<_It>, input_iterator_tag>;

 template <class _It, class _Ty>
concept output_iterator = input_or_output_iterator<_It> && indirectly_writable<_It, _Ty>
    && requires(_It __i, _Ty&& __t) {
        *__i++ = static_cast<_Ty&&>(__t);
    };

 template <class _It>
concept forward_iterator = input_iterator<_It> && derived_from<_Iter_concept<_It>, forward_iterator_tag>
    && incrementable<_It> && sentinel_for<_It, _It>;

 template <class _It>
concept bidirectional_iterator = forward_iterator<_It> && derived_from<_Iter_concept<_It>, bidirectional_iterator_tag>
    && requires(_It __i) {
        { --__i } -> same_as<_It&>;
        { __i-- } -> same_as<_It>;
    };

 template <class _It>
concept random_access_iterator = bidirectional_iterator<_It>
    && derived_from<_Iter_concept<_It>, random_access_iterator_tag> && totally_ordered<_It>
    && sized_sentinel_for<_It, _It> && requires(_It __i, const _It __j, const iter_difference_t<_It> __n) {
        { __i += __n } -> same_as<_It&>;
        { __j + __n } -> same_as<_It>;
        { __n + __j } -> same_as<_It>;
        { __i -= __n } -> same_as<_It&>;
        { __j - __n } -> same_as<_It>;
        { __j[__n] } -> same_as<iter_reference_t<_It>>;
    };

 template <class _It>
concept contiguous_iterator = random_access_iterator<_It>
    && derived_from<_Iter_concept<_It>, contiguous_iterator_tag>
    && is_lvalue_reference_v<iter_reference_t<_It>>
    && same_as<iter_value_t<_It>, remove_cvref_t<iter_reference_t<_It>>>
    && requires(const _It& __i) {
        { ::std:: to_address(__i) } -> same_as<add_pointer_t<iter_reference_t<_It>>>;
    };

 template <class _Fn, class _It>
concept indirectly_unary_invocable = indirectly_readable<_It>
    && copy_constructible<_Fn>
    && invocable<_Fn&, iter_value_t<_It>&>
    && invocable<_Fn&, iter_reference_t<_It>>
    && invocable<_Fn&, iter_common_reference_t<_It>>
    && common_reference_with<
        invoke_result_t<_Fn&, iter_value_t<_It>&>,
        invoke_result_t<_Fn&, iter_reference_t<_It>>>;

 template <class _Fn, class _It>
concept indirectly_regular_unary_invocable = indirectly_readable<_It>
    && copy_constructible<_Fn>
    && regular_invocable<_Fn&, iter_value_t<_It>&>
    && regular_invocable<_Fn&, iter_reference_t<_It>>
    && regular_invocable<_Fn&, iter_common_reference_t<_It>>
    && common_reference_with<
        invoke_result_t<_Fn&, iter_value_t<_It>&>,
        invoke_result_t<_Fn&, iter_reference_t<_It>>>;

 template <class _Fn, class _It>
concept indirect_unary_predicate = indirectly_readable<_It>
    && copy_constructible<_Fn>
    && predicate<_Fn&, iter_value_t<_It>&>
    && predicate<_Fn&, iter_reference_t<_It>>
    && predicate<_Fn&, iter_common_reference_t<_It>>;

 template <class _Fn, class _It1, class _It2>
concept indirect_binary_predicate = indirectly_readable<_It1>
    && indirectly_readable<_It2>
    && copy_constructible<_Fn>
    && predicate<_Fn&, iter_value_t<_It1>&, iter_value_t<_It2>&>
    && predicate<_Fn&, iter_value_t<_It1>&, iter_reference_t<_It2>>
    && predicate<_Fn&, iter_reference_t<_It1>, iter_value_t<_It2>&>
    && predicate<_Fn&, iter_reference_t<_It1>, iter_reference_t<_It2>>
    && predicate<_Fn&, iter_common_reference_t<_It1>, iter_common_reference_t<_It2>>;

 template <class _Fn, class _It1, class _It2 = _It1>
concept indirect_equivalence_relation = indirectly_readable<_It1>
    && indirectly_readable<_It2>
    && copy_constructible<_Fn>
    && equivalence_relation<_Fn&, iter_value_t<_It1>&, iter_value_t<_It2>&>
    && equivalence_relation<_Fn&, iter_value_t<_It1>&, iter_reference_t<_It2>>
    && equivalence_relation<_Fn&, iter_reference_t<_It1>, iter_value_t<_It2>&>
    && equivalence_relation<_Fn&, iter_reference_t<_It1>, iter_reference_t<_It2>>
    && equivalence_relation<_Fn&, iter_common_reference_t<_It1>, iter_common_reference_t<_It2>>;

 template <class _Fn, class _It1, class _It2 = _It1>
concept indirect_strict_weak_order = indirectly_readable<_It1>
    && indirectly_readable<_It2>
    && copy_constructible<_Fn>
    && strict_weak_order<_Fn&, iter_value_t<_It1>&, iter_value_t<_It2>&>
    && strict_weak_order<_Fn&, iter_value_t<_It1>&, iter_reference_t<_It2>>
    && strict_weak_order<_Fn&, iter_reference_t<_It1>, iter_value_t<_It2>&>
    && strict_weak_order<_Fn&, iter_reference_t<_It1>, iter_reference_t<_It2>>
    && strict_weak_order<_Fn&, iter_common_reference_t<_It1>, iter_common_reference_t<_It2>>;

 template <class _Fn, class... _Its>
    requires (indirectly_readable<_Its> && ...)
        && invocable<_Fn, iter_reference_t<_Its>...>
using indirect_result_t = invoke_result_t<_Fn, iter_reference_t<_Its>...>;
 
 
template <indirectly_readable _It, indirectly_regular_unary_invocable<_It> _Proj>
struct projected {
    using value_type = remove_cvref_t<indirect_result_t<_Proj&, _It>>;
    indirect_result_t<_Proj&, _It> operator*() const;
};


template <weakly_incrementable _It, class _Proj>
struct incrementable_traits<projected<_It, _Proj>> {
    using difference_type = iter_difference_t<_It>;
};

  template <class _In, class _Out>
concept indirectly_movable = indirectly_readable<_In> && indirectly_writable<_Out, iter_rvalue_reference_t<_In>>;

 template <class _In, class _Out>
concept indirectly_movable_storable = indirectly_movable<_In, _Out>
    && indirectly_writable<_Out, iter_value_t<_In>>
    && movable<iter_value_t<_In>>
    && constructible_from<iter_value_t<_In>, iter_rvalue_reference_t<_In>>
    && assignable_from<iter_value_t<_In>&, iter_rvalue_reference_t<_In>>;

 template <class _In, class _Out>
concept indirectly_copyable = indirectly_readable<_In> && indirectly_writable<_Out, iter_reference_t<_In>>;

 template <class _In, class _Out>
concept indirectly_copyable_storable = indirectly_copyable<_In, _Out>
    && indirectly_writable<_Out, iter_value_t<_In>&>
    && indirectly_writable<_Out, const iter_value_t<_In>&>
    && indirectly_writable<_Out, iter_value_t<_In>&&>
    && indirectly_writable<_Out, const iter_value_t<_In>&&>
    && copyable<iter_value_t<_In>>
    && constructible_from<iter_value_t<_In>, iter_reference_t<_In>>
    && assignable_from<iter_value_t<_In>&, iter_reference_t<_In>>;
 
 namespace ranges {
    namespace _Iter_swap {
        template <class _Ty1, class _Ty2>
        void iter_swap(_Ty1, _Ty2) = delete;

                 template <class _Ty1, class _Ty2>
        concept _Has_ADL = (_Has_class_or_enum_type<_Ty1> || _Has_class_or_enum_type<_Ty2>)
            && requires(_Ty1&& __t1, _Ty2&& __t2) {
                iter_swap(static_cast<_Ty1&&>(__t1), static_cast<_Ty2&&>(__t2));
            };

        template <class _Ty1, class _Ty2>
        concept _Can_swap_references = indirectly_readable<remove_reference_t<_Ty1>>
            && indirectly_readable<remove_reference_t<_Ty2>>
            && swappable_with<iter_reference_t<_Ty1>, iter_reference_t<_Ty2>>;

        template <class _Ty1, class _Ty2>
        concept _Symmetric_indirectly_movable_storable =
               indirectly_movable_storable<remove_reference_t<_Ty1>, remove_reference_t<_Ty2>>
            && indirectly_movable_storable<remove_reference_t<_Ty2>, remove_reference_t<_Ty1>>;
         
        template <class _Xty, class _Yty>
         constexpr iter_value_t<remove_reference_t<_Xty>> _Iter_exchange_move(_Xty&& _XVal,
            _Yty&& _YVal) noexcept(noexcept(iter_value_t<remove_reference_t<_Xty>>(::std::ranges:: iter_move(_XVal)))) {
            iter_value_t<remove_reference_t<_Xty>> _Tmp(::std::ranges:: iter_move(_XVal));
            *_XVal = ::std::ranges:: iter_move(_YVal);
            return _Tmp;
        }

        class _Cpo {
        private:
            enum class _St { _None, _Custom, _Swap, _Exchange };

            template <class _Ty1, class _Ty2>
             static constexpr _Choice_t<_St> _Choose() noexcept {
                if constexpr (_Has_ADL<_Ty1, _Ty2>) {
                    return {_St::_Custom, noexcept(iter_swap(::std:: declval<_Ty1>(), ::std:: declval<_Ty2>()))};
                } else if constexpr (_Can_swap_references<_Ty1, _Ty2>) {
                    return {_St::_Swap, noexcept(::std::ranges:: swap(*::std:: declval<_Ty1>(), *::std:: declval<_Ty2>()))};
                } else if constexpr (_Symmetric_indirectly_movable_storable<_Ty1, _Ty2>) {
                    constexpr auto _Nothrow = noexcept(
                        *::std:: declval<_Ty1>() = _Iter_exchange_move(::std:: declval<_Ty2>(), ::std:: declval<_Ty1>()));
                    return {_St::_Exchange, _Nothrow};
                } else {
                    return {_St::_None};
                }
            }

            template <class _Ty1, class _Ty2>
            static constexpr _Choice_t<_St> _Choice = _Choose<_Ty1, _Ty2>();

        public:
                         template <class _Ty1, class _Ty2>
                requires (_Choice<_Ty1, _Ty2>._Strategy != _St::_None)
            constexpr void operator()(_Ty1&& _Val1, _Ty2&& _Val2) const noexcept(_Choice<_Ty1, _Ty2>._No_throw) {
                constexpr _St _Strat = _Choice<_Ty1, _Ty2>._Strategy;

                if constexpr (_Strat == _St::_Custom) {
                    iter_swap(static_cast<_Ty1&&>(_Val1), static_cast<_Ty2&&>(_Val2));
                } else if constexpr (_Strat == _St::_Swap) {
                    ::std::ranges:: swap(*static_cast<_Ty1&&>(_Val1), *static_cast<_Ty2&&>(_Val2));
                } else if constexpr (_Strat == _St::_Exchange) {
                    *static_cast<_Ty1&&>(_Val1) =
                        _Iter_exchange_move(static_cast<_Ty2&&>(_Val2), static_cast<_Ty1&&>(_Val1));
                } else {
                    static_assert(_Always_false<_Ty1>, "should be unreachable");
                }
            }
                     };
    }  
    namespace _Cpos {
        inline constexpr _Iter_swap::_Cpo iter_swap;
    }
    using namespace _Cpos;
}  
  template <class _It1, class _It2 = _It1>
concept indirectly_swappable = indirectly_readable<_It1> && indirectly_readable<_It2>
    && requires(const _It1 __i1, const _It2 __i2) {
        ::std::ranges:: iter_swap(__i1, __i1);
        ::std::ranges:: iter_swap(__i2, __i2);
        ::std::ranges:: iter_swap(__i1, __i2);
        ::std::ranges:: iter_swap(__i2, __i1);
    };

 template <class _It1, class _It2, class _Rel, class _Proj1 = identity, class _Proj2 = identity>
concept indirectly_comparable =
    indirect_binary_predicate<_Rel,
        projected<_It1, _Proj1>,
        projected<_It2, _Proj2>>;

 template <class _It>
concept permutable = forward_iterator<_It>
    && indirectly_movable_storable<_It, _It>
    && indirectly_swappable<_It, _It>;

 namespace ranges { struct less; }
template <class _It1, class _It2, class _Out, class _Pr = ranges::less, class _Pj1 = identity, class _Pj2 = identity>
concept mergeable = input_iterator<_It1> && input_iterator<_It2>
    && weakly_incrementable<_Out>
    && indirectly_copyable<_It1, _Out>
    && indirectly_copyable<_It2, _Out>
    && indirect_strict_weak_order<_Pr, projected<_It1, _Pj1>, projected<_It2, _Pj2>>;

 template <class _It, class _Pr = ranges::less, class _Proj = identity>
concept sortable = permutable<_It> && indirect_strict_weak_order<_Pr, projected<_It, _Proj>>;
 
 template <class _Iter>
using _Iter_ref_t = iter_reference_t<_Iter>;

 template <class _Iter>
using _Iter_value_t = iter_value_t<_Iter>;

 template <class _Iter>
using _Iter_diff_t = iter_difference_t<_Iter>;


 template <class... _Iters>
using _Common_diff_t = common_type_t<_Iter_diff_t<_Iters>...>;

 template <class _Iter>
using _Iter_cat_t = typename iterator_traits<_Iter>::iterator_category;

 template <class _Ty, class = void>
inline constexpr bool _Is_iterator_v = false;

template <class _Ty>
inline constexpr bool _Is_iterator_v<_Ty, void_t<_Iter_cat_t<_Ty>>> = true;

 template <class _Ty>
struct _Is_iterator : bool_constant<_Is_iterator_v<_Ty>> {};

 template <class _Iter>
inline constexpr bool _Is_input_iter_v = is_convertible_v<_Iter_cat_t<_Iter>, input_iterator_tag>;

 template <class _Iter>
inline constexpr bool _Is_fwd_iter_v = is_convertible_v<_Iter_cat_t<_Iter>, forward_iterator_tag>;

 template <class _Iter>
inline constexpr bool _Is_bidi_iter_v = is_convertible_v<_Iter_cat_t<_Iter>, bidirectional_iterator_tag>;

 template <class _Iter>
inline constexpr bool _Is_random_iter_v = is_convertible_v<_Iter_cat_t<_Iter>, random_access_iterator_tag>;

 template <class, class = void>
struct _Is_checked_helper {};  
 
template <class _Iter, class = void>
inline constexpr bool _Allow_inheriting_unwrap_v = true;

template <class _Iter>
inline constexpr bool _Allow_inheriting_unwrap_v<_Iter, void_t<typename _Iter::_Prevent_inheriting_unwrap>> =
    is_same_v<_Iter, typename _Iter::_Prevent_inheriting_unwrap>;

template <class _Iter, class _Sentinel = _Iter, class = void>
inline constexpr bool _Range_verifiable_v = false;

template <class _Iter, class _Sentinel>
inline constexpr bool _Range_verifiable_v<_Iter, _Sentinel,
    void_t<decltype(_Verify_range(::std:: declval<const _Iter&>(), ::std:: declval<const _Sentinel&>()))>> =
    _Allow_inheriting_unwrap_v<_Iter>;

template <class _Iter, class _Sentinel>
constexpr void _Adl_verify_range(const _Iter& _First, const _Sentinel& _Last) {
         if constexpr (_Range_verifiable_v<_Iter, _Sentinel>) {
        _Verify_range(_First, _Last);
    }
}

 template <class _Iter, class = void>
inline constexpr bool _Unwrappable_v = false;

template <class _Iter>
inline constexpr bool _Unwrappable_v<_Iter,
    void_t<decltype(::std:: declval<_Remove_cvref_t<_Iter>&>()._Seek_to(::std:: declval<_Iter>()._Unwrapped()))>> =
    _Allow_inheriting_unwrap_v<_Remove_cvref_t<_Iter>>;

template <class _Iter>
 constexpr decltype(auto) _Get_unwrapped(_Iter&& _It) {
         if constexpr (is_pointer_v<decay_t<_Iter>>) {          return _It + 0;
    } else if constexpr (_Unwrappable_v<_Iter>) {
        return static_cast<_Iter&&>(_It)._Unwrapped();
    } else {
        return static_cast<_Iter&&>(_It);
    }
}

template <class _Iter>
using _Unwrapped_t = _Remove_cvref_t<decltype(_Get_unwrapped(::std:: declval<_Iter>()))>;

 template <class _Iter, class = bool>
inline constexpr bool _Do_unwrap_when_unverified_v = false;

template <class _Iter>
inline constexpr bool
    _Do_unwrap_when_unverified_v<_Iter, decltype(static_cast<bool>(_Iter::_Unwrap_when_unverified))> =
        static_cast<bool>(_Iter::_Unwrap_when_unverified);

template <class _Iter>
inline constexpr bool _Unwrappable_for_unverified_v =
    _Unwrappable_v<_Iter>&& _Do_unwrap_when_unverified_v<_Remove_cvref_t<_Iter>>;

template <class _Iter>
 constexpr decltype(auto) _Get_unwrapped_unverified(_Iter&& _It) {
         if constexpr (is_pointer_v<decay_t<_Iter>>) {          return _It + 0;
    } else if constexpr (_Unwrappable_for_unverified_v<_Iter>) {
        return static_cast<_Iter&&>(_It)._Unwrapped();
    } else {
        return static_cast<_Iter&&>(_It);
    }
}

template <class _Iter>
using _Unwrapped_unverified_t = _Remove_cvref_t<decltype(_Get_unwrapped_unverified(::std:: declval<_Iter>()))>;

 struct _Distance_unknown {
    constexpr _Distance_unknown operator-() const noexcept {
        return {};
    }
};

template <class _Diff>
inline constexpr auto _Max_possible_v = _Diff{static_cast<make_unsigned_t<_Diff>>(-1) >> 1};

template <class _Diff>
inline constexpr auto _Min_possible_v = _Diff{-_Max_possible_v<_Diff> - 1};

template <class _Iter, class = void>
inline constexpr bool _Offset_verifiable_v = false;

template <class _Iter>
inline constexpr bool
    _Offset_verifiable_v<_Iter, void_t<decltype(::std:: declval<const _Iter&>()._Verify_offset(_Iter_diff_t<_Iter>{}))>> =
        true;

template <class _Iter>
inline constexpr bool _Unwrappable_for_offset_v =
    _Unwrappable_v<_Iter>&& _Offset_verifiable_v<_Remove_cvref_t<_Iter>>;

template <class _Iter, class _Diff>
 constexpr decltype(auto) _Get_unwrapped_n(_Iter&& _It, const _Diff _Off) {
    if constexpr (is_pointer_v<decay_t<_Iter>>) {
        return _It + 0;
    } else if constexpr (_Unwrappable_for_offset_v<_Iter> && is_integral_v<_Diff>) {
                 using _IDiff     = _Iter_diff_t<_Remove_cvref_t<_Iter>>;
        using _CDiff     = common_type_t<_Diff, _IDiff>;
        const auto _COff = static_cast<_CDiff>(_Off);

        ;
        (void) _COff;

        _It._Verify_offset(static_cast<_IDiff>(_Off));
        return static_cast<_Iter&&>(_It)._Unwrapped();
    } else if constexpr (_Unwrappable_for_unverified_v<_Iter>) {
                 return static_cast<_Iter&&>(_It)._Unwrapped();
    } else {
                 return static_cast<_Iter&&>(_It);
    }
}

 template <class _Iter, class _UIter, class = void>
inline constexpr bool _Wrapped_seekable_v = false;

template <class _Iter, class _UIter>
inline constexpr bool
    _Wrapped_seekable_v<_Iter, _UIter, void_t<decltype(::std:: declval<_Iter&>()._Seek_to(::std:: declval<_UIter>()))>> =
        true;

template <class _Iter, class _UIter>
constexpr void _Seek_wrapped(_Iter& _It, _UIter&& _UIt) {
    if constexpr (_Wrapped_seekable_v<_Iter, _UIter>) {
        _It._Seek_to(::std:: forward<_UIter>(_UIt));
    } else {
        _It = ::std:: forward<_UIter>(_UIt);
    }
}

 template <class _Ty, class = void>
struct _Is_allocator : false_type {};  
template <class _Ty>
struct _Is_allocator<_Ty, void_t<typename _Ty::value_type, decltype(::std:: declval<_Ty&>().deallocate(
                                                               ::std:: declval<_Ty&>().allocate(size_t{1}), size_t{1}))>>
    : true_type {};  
 template <class _Iter>
using _Guide_key_t = remove_const_t<typename iterator_traits<_Iter>::value_type::first_type>;

template <class _Iter>
using _Guide_val_t = typename iterator_traits<_Iter>::value_type::second_type;

template <class _Iter>
using _Guide_pair_t = pair<add_const_t<typename iterator_traits<_Iter>::value_type::first_type>,
    typename iterator_traits<_Iter>::value_type::second_type>;

 template <class _Ty>
struct is_execution_policy : false_type {};

template <class _Ty>
inline constexpr bool is_execution_policy_v = is_execution_policy<_Ty>::value;

   template <class _ExPo>
using _Enable_if_execution_policy_t = typename remove_reference_t<_ExPo>::_Standard_execution_policy;



 template <class _Checked, class _Iter>
 constexpr auto _Idl_distance(const _Iter& _First, const _Iter& _Last) {
         if constexpr (_Is_random_iter_v<_Iter>) {
        return static_cast<_Iter_diff_t<_Checked>>(_Last - _First);
    } else {
        return _Distance_unknown{};
    }
}

 template <class _Elem, bool _Is_enum = is_enum_v<_Elem>>
struct _Unwrap_enum {      using type = underlying_type_t<_Elem>;
};

template <class _Elem>
struct _Unwrap_enum<_Elem, false> {      using type = _Elem;
};

template <class _Elem>
using _Unwrap_enum_t = typename _Unwrap_enum<_Elem>::type;

 


  template <class _InIt, class _Diff>
constexpr void advance(_InIt& _Where, _Diff _Off) {      if constexpr (_Is_random_iter_v<_InIt>) {
        _Where += _Off;
    } else {
        if constexpr (is_signed_v<_Diff> && !_Is_bidi_iter_v<_InIt>) {
            ;
        }

        decltype(auto) _UWhere      = _Get_unwrapped_n(::std:: move(_Where), _Off);
        constexpr bool _Need_rewrap = !is_reference_v<decltype(_Get_unwrapped_n(::std:: move(_Where), _Off))>;

        if constexpr (is_signed_v<_Diff> && _Is_bidi_iter_v<_InIt>) {
            for (; _Off < 0; ++_Off) {
                --_UWhere;
            }
        }

        for (; 0 < _Off; --_Off) {
            ++_UWhere;
        }

        if constexpr (_Need_rewrap) {
            _Seek_wrapped(_Where, ::std:: move(_UWhere));
        }
    }
}

 template <class _InIt>
 constexpr _Iter_diff_t<_InIt> distance(_InIt _First, _InIt _Last) {
    if constexpr (_Is_random_iter_v<_InIt>) {
        return _Last - _First;      } else {
        _Adl_verify_range(_First, _Last);
        auto _UFirst             = _Get_unwrapped(_First);
        const auto _ULast        = _Get_unwrapped(_Last);
        _Iter_diff_t<_InIt> _Off = 0;
        for (; _UFirst != _ULast; ++_UFirst) {
            ++_Off;
        }

        return _Off;
    }
}

 template <class _InIt>
constexpr _InIt _Next_iter(_InIt _First) {      return ++_First;
}

 template <class _InIt>
 constexpr _InIt next(_InIt _First, _Iter_diff_t<_InIt> _Off = 1) {      static_assert(_Is_input_iter_v<_InIt>, "next requires input iterator");

    ::std:: advance(_First, _Off);
    return _First;
}

 template <class _BidIt>
constexpr _BidIt _Prev_iter(_BidIt _First) {      return --_First;
}

 template <class _BidIt>
 constexpr _BidIt prev(_BidIt _First, _Iter_diff_t<_BidIt> _Off = 1) {      static_assert(_Is_bidi_iter_v<_BidIt>, "prev requires bidirectional iterator");

    ::std:: advance(_First, -_Off);
    return _First;
}

 
template <class _BidIt>
class reverse_iterator {
public:
    using iterator_type = _BidIt;

    using iterator_concept =
        conditional_t<random_access_iterator<_BidIt>, random_access_iterator_tag, bidirectional_iterator_tag>;
    using iterator_category = conditional_t<derived_from<_Iter_cat_t<_BidIt>, random_access_iterator_tag>,
        random_access_iterator_tag, _Iter_cat_t<_BidIt>>;
    using value_type      = _Iter_value_t<_BidIt>;
    using difference_type = _Iter_diff_t<_BidIt>;
    using pointer         = typename iterator_traits<_BidIt>::pointer;
    using reference       = _Iter_ref_t<_BidIt>;

    template <class>
    friend class reverse_iterator;

    constexpr reverse_iterator() = default;

    constexpr explicit reverse_iterator(_BidIt _Right) noexcept(
        is_nothrow_move_constructible_v<_BidIt>)          : current(::std:: move(_Right)) {}

         template <class _Other>
        requires (!is_same_v<_Other, _BidIt>) && convertible_to<const _Other&, _BidIt>
    constexpr reverse_iterator(const reverse_iterator<_Other>& _Right) noexcept(
        is_nothrow_constructible_v<_BidIt, const _Other&>)          : current(_Right.current) {}

    template <class _Other>
        requires (!is_same_v<_Other, _BidIt>) && convertible_to<const _Other&, _BidIt>
            && assignable_from<_BidIt&, const _Other&>
    constexpr reverse_iterator& operator=(const reverse_iterator<_Other>& _Right) {
        current = _Right.current;
        return *this;
    }
     
     constexpr _BidIt base() const {
        return current;
    }

     constexpr reference operator*() const {
        _BidIt _Tmp = current;
        return *--_Tmp;
    }

          constexpr pointer operator->() const
        requires (is_pointer_v<_BidIt> || requires(const _BidIt __i) { __i.operator->(); }) {
        _BidIt _Tmp = current;
        --_Tmp;
        if constexpr (is_pointer_v<_BidIt>) {
            return _Tmp;
        } else {
            return _Tmp.operator->();
        }
    }
     
    constexpr reverse_iterator& operator++() {
        --current;
        return *this;
    }

    constexpr reverse_iterator operator++(int) {
        reverse_iterator _Tmp = *this;
        --current;
        return _Tmp;
    }

    constexpr reverse_iterator& operator--() {
        ++current;
        return *this;
    }

    constexpr reverse_iterator operator--(int) {
        reverse_iterator _Tmp = *this;
        ++current;
        return _Tmp;
    }

     constexpr reverse_iterator operator+(const difference_type _Off) const {
        return reverse_iterator(current - _Off);
    }

    constexpr reverse_iterator& operator+=(const difference_type _Off) {
        current -= _Off;
        return *this;
    }

     constexpr reverse_iterator operator-(const difference_type _Off) const {
        return reverse_iterator(current + _Off);
    }

    constexpr reverse_iterator& operator-=(const difference_type _Off) {
        current += _Off;
        return *this;
    }

     constexpr reference operator[](const difference_type _Off) const {
        return current[static_cast<difference_type>(-_Off - 1)];
    }

     friend constexpr iter_rvalue_reference_t<_BidIt> iter_move(const reverse_iterator& _It) noexcept(
        is_nothrow_copy_constructible_v<_BidIt>&& noexcept(::std::ranges:: iter_move(--::std:: declval<_BidIt&>()))) {
        auto _Tmp = _It.current;
        --_Tmp;
        return ::std::ranges:: iter_move(_Tmp);
    }

    template <indirectly_swappable<_BidIt> _BidIt2>
    friend constexpr void iter_swap(const reverse_iterator& _Left, const reverse_iterator<_BidIt2>& _Right) noexcept(
        is_nothrow_copy_constructible_v<_BidIt>&& is_nothrow_copy_constructible_v<_BidIt2>&& noexcept(
            ::std::ranges:: iter_swap(--::std:: declval<_BidIt&>(), --::std:: declval<_BidIt2&>()))) {
        auto _LTmp = _Left.current;
        auto _RTmp = _Right.base();
        --_LTmp;
        --_RTmp;
        ::std::ranges:: iter_swap(_LTmp, _RTmp);
    }

    using _Prevent_inheriting_unwrap = reverse_iterator;

    template <class _BidIt2, enable_if_t<_Range_verifiable_v<_BidIt, _BidIt2>, int> = 0>
    friend constexpr void _Verify_range(const reverse_iterator& _First, const reverse_iterator<_BidIt2>& _Last) {
        _Verify_range(_Last._Get_current(), _First.current);      }

    template <class _BidIt2 = _BidIt, enable_if_t<_Offset_verifiable_v<_BidIt2>, int> = 0>
    constexpr void _Verify_offset(const difference_type _Off) const {
        do {                                                                    if (_Off != _Min_possible_v<difference_type>) {           } else {                                                                do {                                             ;                   ::_invalid_parameter_noinfo_noreturn();     } while (false);                                        }                                                                                                                                       ;                                        } while (false);
        current._Verify_offset(-_Off);
    }

    template <class _BidIt2 = _BidIt, enable_if_t<_Unwrappable_v<const _BidIt2&>, int> = 0>
     constexpr reverse_iterator<_Unwrapped_t<const _BidIt2&>> _Unwrapped() const {
        return static_cast<reverse_iterator<_Unwrapped_t<const _BidIt2&>>>(current._Unwrapped());
    }

    static constexpr bool _Unwrap_when_unverified = _Do_unwrap_when_unverified_v<_BidIt>;

    template <class _Src, enable_if_t<_Wrapped_seekable_v<_BidIt, const _Src&>, int> = 0>
    constexpr void _Seek_to(const reverse_iterator<_Src>& _It) {
        current._Seek_to(_It.current);
    }

     constexpr const _BidIt& _Get_current() const noexcept {
        return current;
    }

protected:
    _BidIt current{};
};

template <class _BidIt1, class _BidIt2>
 constexpr bool operator==(const reverse_iterator<_BidIt1>& _Left, const reverse_iterator<_BidIt2>& _Right)
         requires requires {
        { _Left._Get_current() == _Right._Get_current() } -> _Implicitly_convertible_to<bool>;
    }
 { return _Left._Get_current() == _Right._Get_current(); }

template <class _BidIt1, class _BidIt2>
 constexpr bool operator!=(const reverse_iterator<_BidIt1>& _Left, const reverse_iterator<_BidIt2>& _Right)
         requires requires {
        { _Left._Get_current() != _Right._Get_current() } -> _Implicitly_convertible_to<bool>;
    }
 { return _Left._Get_current() != _Right._Get_current(); }

template <class _BidIt1, class _BidIt2>
 constexpr bool operator<(const reverse_iterator<_BidIt1>& _Left, const reverse_iterator<_BidIt2>& _Right)
         requires requires {
        { _Left._Get_current() > _Right._Get_current() } -> _Implicitly_convertible_to<bool>;
    }
 { return _Left._Get_current() > _Right._Get_current(); }

template <class _BidIt1, class _BidIt2>
 constexpr bool operator>(const reverse_iterator<_BidIt1>& _Left, const reverse_iterator<_BidIt2>& _Right)
         requires requires {
        { _Left._Get_current() < _Right._Get_current() } -> _Implicitly_convertible_to<bool>;
    }
 { return _Left._Get_current() < _Right._Get_current(); }

template <class _BidIt1, class _BidIt2>
 constexpr bool operator<=(const reverse_iterator<_BidIt1>& _Left, const reverse_iterator<_BidIt2>& _Right)
         requires requires {
        { _Left._Get_current() >= _Right._Get_current() } -> _Implicitly_convertible_to<bool>;
    }
 { return _Left._Get_current() >= _Right._Get_current(); }

template <class _BidIt1, class _BidIt2>
 constexpr bool operator>=(const reverse_iterator<_BidIt1>& _Left, const reverse_iterator<_BidIt2>& _Right)
         requires requires {
        { _Left._Get_current() <= _Right._Get_current() } -> _Implicitly_convertible_to<bool>;
    }
 { return _Left._Get_current() <= _Right._Get_current(); }

template <class _BidIt1, three_way_comparable_with<_BidIt1> _BidIt2>
 constexpr compare_three_way_result_t<_BidIt1, _BidIt2> operator<=>(
    const reverse_iterator<_BidIt1>& _Left, const reverse_iterator<_BidIt2>& _Right) {
    return _Right._Get_current() <=> _Left._Get_current();
}

template <class _BidIt1, class _BidIt2>
 constexpr auto operator-(const reverse_iterator<_BidIt1>& _Left, const reverse_iterator<_BidIt2>& _Right)
    -> decltype(_Right._Get_current() - _Left._Get_current()) {
    return _Right._Get_current() - _Left._Get_current();
}

template <class _BidIt>
 constexpr reverse_iterator<_BidIt> operator+(
    typename reverse_iterator<_BidIt>::difference_type _Off, const reverse_iterator<_BidIt>& _Right) {
    return _Right + _Off;
}

 template <class _BidIt>
 constexpr reverse_iterator<_BidIt> make_reverse_iterator(_BidIt _Iter) noexcept(
    is_nothrow_move_constructible_v<_BidIt>)   {
    return reverse_iterator<_BidIt>(::std:: move(_Iter));
}

 template <class _BidIt1, class _BidIt2>
    requires (!sized_sentinel_for<_BidIt1, _BidIt2>)
inline constexpr bool disable_sized_sentinel_for<reverse_iterator<_BidIt1>, reverse_iterator<_BidIt2>> = true;
 
 template <class _Container>
 constexpr auto begin(_Container& _Cont) -> decltype(_Cont.begin()) {
    return _Cont.begin();
}

template <class _Container>
 constexpr auto begin(const _Container& _Cont) -> decltype(_Cont.begin()) {
    return _Cont.begin();
}

template <class _Container>
 constexpr auto end(_Container& _Cont) -> decltype(_Cont.end()) {
    return _Cont.end();
}

template <class _Container>
 constexpr auto end(const _Container& _Cont) -> decltype(_Cont.end()) {
    return _Cont.end();
}

template <class _Ty, size_t _Size>
 constexpr _Ty* begin(_Ty (&_Array)[_Size]) noexcept {
    return _Array;
}

template <class _Ty, size_t _Size>
 constexpr _Ty* end(_Ty (&_Array)[_Size]) noexcept {
    return _Array + _Size;
}

 template <class _Container>
 constexpr auto cbegin(const _Container& _Cont) noexcept(noexcept(::std:: begin(_Cont)))
    -> decltype(::std:: begin(_Cont)) {
    return ::std:: begin(_Cont);
}

template <class _Container>
 constexpr auto cend(const _Container& _Cont) noexcept(noexcept(::std:: end(_Cont)))
    -> decltype(::std:: end(_Cont)) {
    return ::std:: end(_Cont);
}

 template <class _Container>
 constexpr auto rbegin(_Container& _Cont) -> decltype(_Cont.rbegin()) {
    return _Cont.rbegin();
}

template <class _Container>
 constexpr auto rbegin(const _Container& _Cont) -> decltype(_Cont.rbegin()) {
    return _Cont.rbegin();
}

template <class _Container>
 constexpr auto rend(_Container& _Cont) -> decltype(_Cont.rend()) {
    return _Cont.rend();
}

template <class _Container>
 constexpr auto rend(const _Container& _Cont) -> decltype(_Cont.rend()) {
    return _Cont.rend();
}

template <class _Ty, size_t _Size>
 constexpr reverse_iterator<_Ty*> rbegin(_Ty (&_Array)[_Size]) {
    return reverse_iterator<_Ty*>(_Array + _Size);
}

template <class _Ty, size_t _Size>
 constexpr reverse_iterator<_Ty*> rend(_Ty (&_Array)[_Size]) {
    return reverse_iterator<_Ty*>(_Array);
}

template <class _Elem>
 constexpr reverse_iterator<const _Elem*> rbegin(initializer_list<_Elem> _Ilist) {
    return reverse_iterator<const _Elem*>(_Ilist.end());
}

template <class _Elem>
 constexpr reverse_iterator<const _Elem*> rend(initializer_list<_Elem> _Ilist) {
    return reverse_iterator<const _Elem*>(_Ilist.begin());
}

 template <class _Container>
 constexpr auto crbegin(const _Container& _Cont) -> decltype(::std:: rbegin(_Cont)) {
    return ::std:: rbegin(_Cont);
}

template <class _Container>
 constexpr auto crend(const _Container& _Cont) -> decltype(::std:: rend(_Cont)) {
    return ::std:: rend(_Cont);
}

template <class _Container>
 constexpr auto size(const _Container& _Cont) -> decltype(_Cont.size()) {
    return _Cont.size();
}

template <class _Ty, size_t _Size>
 constexpr size_t size(const _Ty (&)[_Size]) noexcept {
    return _Size;
}

 template <class _Container>
 constexpr auto ssize(const _Container& _Cont)
    -> common_type_t<ptrdiff_t, make_signed_t<decltype(_Cont.size())>> {
    using _Common = common_type_t<ptrdiff_t, make_signed_t<decltype(_Cont.size())>>;
    return static_cast<_Common>(_Cont.size());
}

template <class _Ty, ptrdiff_t _Size>
 constexpr ptrdiff_t ssize(const _Ty (&)[_Size]) noexcept {
    return _Size;
}

template <class _Container>
 constexpr auto empty(const _Container& _Cont) -> decltype(_Cont.empty()) {
    return _Cont.empty();
}

template <class _Ty, size_t _Size>
 constexpr bool empty(const _Ty (&)[_Size]) noexcept {
    return false;
}

template <class _Elem>
 constexpr bool empty(initializer_list<_Elem> _Ilist) noexcept {
    return _Ilist.size() == 0;
}

template <class _Container>
 constexpr auto data(_Container& _Cont) -> decltype(_Cont.data()) {
    return _Cont.data();
}

template <class _Container>
 constexpr auto data(const _Container& _Cont) -> decltype(_Cont.data()) {
    return _Cont.data();
}

template <class _Ty, size_t _Size>
 constexpr _Ty* data(_Ty (&_Array)[_Size]) noexcept {
    return _Array;
}

template <class _Elem>
 constexpr const _Elem* data(initializer_list<_Elem> _Ilist) noexcept {
    return _Ilist.begin();
}

 template <class _Ty>
 _Ty _Fake_decay_copy(_Ty) noexcept;
    
 template <class _Ty1, class _Ty2>
concept _Not_same_as = !same_as<remove_cvref_t<_Ty1>, remove_cvref_t<_Ty2>>;

namespace ranges {
         template <class>
    inline constexpr bool _Has_complete_elements = false;

         template <class _Ty>
        requires requires(_Ty& __t) { sizeof(__t[0]); }
    inline constexpr bool _Has_complete_elements<_Ty> = true;
     
         template <class>
    inline constexpr bool enable_borrowed_range = false;

    template <class _Rng>
    concept _Should_range_access = is_lvalue_reference_v<_Rng> || enable_borrowed_range<remove_cvref_t<_Rng>>;

         namespace _Begin {
        template <class _Ty>
        void begin(_Ty&) = delete;
        template <class _Ty>
        void begin(const _Ty&) = delete;

                 template <class _Ty>
        concept _Has_member = requires(_Ty __t) {
            { _Fake_decay_copy(__t.begin()) } -> input_or_output_iterator;
        };

        template <class _Ty>
        concept _Has_ADL = _Has_class_or_enum_type<_Ty> && requires(_Ty __t) {
            { _Fake_decay_copy(begin(__t)) } -> input_or_output_iterator;
        };
         
        class _Cpo {
        private:
            enum class _St { _None, _Array, _Member, _Non_member };

            template <class _Ty>
             static constexpr _Choice_t<_St> _Choose() noexcept {
                ;
                if constexpr (is_array_v<remove_reference_t<_Ty>>) {
                    static_assert(_Has_complete_elements<_Ty>,
                        "The range access customization point objects std::ranges::begin, std::ranges::end, std::ranges::rbegin, std::ranges::rend, and std::ranges::data do not accept arrays with incomplete element types.");
                    return {_St::_Array, true};
                } else if constexpr (_Has_member<_Ty>) {
                    return {_St::_Member, noexcept(_Fake_decay_copy(::std:: declval<_Ty>().begin()))};
                } else if constexpr (_Has_ADL<_Ty>) {
                    return {_St::_Non_member, noexcept(_Fake_decay_copy(begin(::std:: declval<_Ty>())))};
                } else {
                    return {_St::_None};
                }
            }

            template <class _Ty>
            static constexpr _Choice_t<_St> _Choice = _Choose<_Ty>();

        public:
                         template <_Should_range_access _Ty>
                requires (_Choice<_Ty&>._Strategy != _St::_None)
             constexpr auto operator()(_Ty&& _Val) const noexcept(_Choice<_Ty&>._No_throw) {
                constexpr _St _Strat = _Choice<_Ty&>._Strategy;

                if constexpr (_Strat == _St::_Array) {
                    return _Val;
                } else if constexpr (_Strat == _St::_Member) {
                    return _Val.begin();
                } else if constexpr (_Strat == _St::_Non_member) {
                    return begin(_Val);
                } else {
                    static_assert(_Always_false<_Ty>, "Should be unreachable");
                }
            }
                     };
    }  
    namespace _Cpos {
        inline constexpr _Begin::_Cpo begin;
    }
    using namespace _Cpos;

         template <class _Ty>
    using iterator_t = decltype(::std::ranges:: begin(::std:: declval<_Ty&>()));

         namespace _Unchecked_begin {
                 template <class _Ty>
        concept _Has_member = requires(_Ty& __t) {
            { __t._Unchecked_begin() } -> input_or_output_iterator;
        };

        template <class _Ty>
        concept _Can_begin = requires(_Ty& __t) {
            _Get_unwrapped(::std::ranges:: begin(__t));
        };
         
        class _Cpo {
        private:
            enum class _St { _None, _Member, _Unwrap };

            template <class _Ty>
             static constexpr _Choice_t<_St> _Choose() noexcept {
                ;
                if constexpr (_Has_member<_Ty>) {
                    ;
                    return {_St::_Member, noexcept(::std:: declval<_Ty>()._Unchecked_begin())};
                } else if constexpr (_Can_begin<_Ty>) {
                    return {_St::_Unwrap, noexcept(_Get_unwrapped(::std::ranges:: begin(::std:: declval<_Ty>())))};
                } else {
                    return {_St::_None};
                }
            }

            template <class _Ty>
            static constexpr _Choice_t<_St> _Choice = _Choose<_Ty>();

        public:
                         template <_Should_range_access _Ty>
                requires (_Choice<_Ty&>._Strategy != _St::_None)
             constexpr auto operator()(_Ty&& _Val) const noexcept(_Choice<_Ty&>._No_throw) {
                constexpr _St _Strat = _Choice<_Ty&>._Strategy;

                if constexpr (_Strat == _St::_Member) {
                    return _Val._Unchecked_begin();
                } else if constexpr (_Strat == _St::_Unwrap) {
                    return _Get_unwrapped(::std::ranges:: begin(_Val));
                } else {
                    static_assert(_Always_false<_Ty>, "Should be unreachable");
                }
            }
                     };
    }  
    namespace _Cpos {
        inline constexpr _Unchecked_begin::_Cpo _Ubegin;
    }
    using namespace _Cpos;

         namespace _End {
        template <class _Ty>
        void end(_Ty&) = delete;
        template <class _Ty>
        void end(const _Ty&) = delete;

                 template <class _Ty>
        concept _Has_member = requires(_Ty __t) {
            { _Fake_decay_copy(__t.end()) } -> sentinel_for<iterator_t<_Ty>>;
        };

        template <class _Ty>
        concept _Has_ADL = _Has_class_or_enum_type<_Ty> && requires(_Ty __t) {
            { _Fake_decay_copy(end(__t)) } -> sentinel_for<iterator_t<_Ty>>;
        };
         
        class _Cpo {
        private:
            enum class _St { _None, _Array, _Member, _Non_member };

            template <class _Ty>
             static constexpr _Choice_t<_St> _Choose() noexcept {
                ;
                using _UnRef = remove_reference_t<_Ty>;

                if constexpr (is_array_v<_UnRef>) {
                    static_assert(_Has_complete_elements<_UnRef>,
                        "The range access customization point objects std::ranges::begin, std::ranges::end, std::ranges::rbegin, std::ranges::rend, and std::ranges::data do not accept arrays with incomplete element types.");
                    if constexpr (extent_v<_UnRef> != 0) {
                        return {_St::_Array, true};
                    } else {
                        return {_St::_None};
                    }
                } else if constexpr (_Has_member<_Ty>) {
                    return {_St::_Member, noexcept(_Fake_decay_copy(::std:: declval<_Ty>().end()))};
                } else if constexpr (_Has_ADL<_Ty>) {
                    return {_St::_Non_member, noexcept(_Fake_decay_copy(end(::std:: declval<_Ty>())))};
                } else {
                    return {_St::_None};
                }
            }

            template <class _Ty>
            static constexpr _Choice_t<_St> _Choice = _Choose<_Ty>();

        public:
                         template <_Should_range_access _Ty>
                requires (_Choice<_Ty&>._Strategy != _St::_None)
             constexpr auto operator()(_Ty&& _Val) const noexcept(_Choice<_Ty&>._No_throw) {
                constexpr _St _Strat = _Choice<_Ty&>._Strategy;

                if constexpr (_Strat == _St::_Array) {
                                         return _Val + extent_v<remove_reference_t<_Ty&>>;
                } else if constexpr (_Strat == _St::_Member) {
                    return _Val.end();
                } else if constexpr (_Strat == _St::_Non_member) {
                    return end(_Val);
                } else {
                    static_assert(_Always_false<_Ty>, "should be unreachable");
                }
            }
                     };
    }  
    namespace _Cpos {
        inline constexpr _End::_Cpo end;
    }
    using namespace _Cpos;

         namespace _Unchecked_end {
                 template <class _Ty>
        concept _Has_member = _Unchecked_begin::_Has_member<_Ty> && requires(_Ty& __t) {
            __t._Unchecked_begin();              { __t._Unchecked_end() } -> sentinel_for<decltype(__t._Unchecked_begin())>;
        };

        template <class _Ty>
        concept _Can_end = requires(_Ty& __t) {
            _Get_unwrapped(::std::ranges:: end(__t));
        };
         
        class _Cpo {
        private:
            enum class _St { _None, _Member, _Unwrap };

            template <class _Ty>
             static constexpr _Choice_t<_St> _Choose() noexcept {
                ;
                if constexpr (_Has_member<_Ty>) {
                    ;
                    return {_St::_Member, noexcept(::std:: declval<_Ty>()._Unchecked_end())};
                } else if constexpr (_Can_end<_Ty>) {
                    return {_St::_Unwrap, noexcept(_Get_unwrapped(::std::ranges:: end(::std:: declval<_Ty>())))};
                } else {
                    return {_St::_None};
                }
            }

            template <class _Ty>
            static constexpr _Choice_t<_St> _Choice = _Choose<_Ty>();

        public:
                         template <_Should_range_access _Ty>
                requires (_Choice<_Ty&>._Strategy != _St::_None)
             constexpr auto operator()(_Ty&& _Val) const noexcept(_Choice<_Ty&>._No_throw) {
                constexpr _St _Strat = _Choice<_Ty&>._Strategy;

                if constexpr (_Strat == _St::_Member) {
                    return _Val._Unchecked_end();
                } else if constexpr (_Strat == _St::_Unwrap) {
                    return _Get_unwrapped(::std::ranges:: end(_Val));
                } else {
                    static_assert(_Always_false<_Ty>, "Should be unreachable");
                }
            }
                     };
    }  
    namespace _Cpos {
        inline constexpr _Unchecked_end::_Cpo _Uend;
    }
    using namespace _Cpos;

         template <class _Rng>
    concept range = requires(_Rng& __r) {
        ::std::ranges:: begin(__r);
        ::std::ranges:: end(__r);
    };

              template <class _Rng>
    concept borrowed_range = range<_Rng> && _Should_range_access<_Rng>;
     
         template <range _Rng>
    using sentinel_t = decltype(::std::ranges:: end(::std:: declval<_Rng&>()));

         template <range _Rng>
    using range_difference_t = iter_difference_t<iterator_t<_Rng>>;

         template <range _Rng>
    using range_value_t = iter_value_t<iterator_t<_Rng>>;

         template <range _Rng>
    using range_reference_t = iter_reference_t<iterator_t<_Rng>>;

         template <range _Rng>
    using range_rvalue_reference_t = iter_rvalue_reference_t<iterator_t<_Rng>>;

         struct _Cbegin_fn {
                 template <class _Ty, class _CTy = _Const_thru_ref<_Ty>>
         constexpr auto operator()(_Ty&& _Val) const
            noexcept(noexcept(::std::ranges:: begin(static_cast<_CTy&&>(_Val))))
            requires requires { ::std::ranges:: begin(static_cast<_CTy&&>(_Val)); } {
            return ::std::ranges:: begin(static_cast<_CTy&&>(_Val));
        }
             };

    namespace _Cpos {
        inline constexpr _Cbegin_fn cbegin;
    }
    using namespace _Cpos;

         struct _Cend_fn {
                 template <class _Ty, class _CTy = _Const_thru_ref<_Ty>>
         constexpr auto operator()(_Ty&& _Val) const
            noexcept(noexcept(::std::ranges:: end(static_cast<_CTy&&>(_Val))))
            requires requires { ::std::ranges:: end(static_cast<_CTy&&>(_Val)); } {
            return ::std::ranges:: end(static_cast<_CTy&&>(_Val));
        }
             };

    namespace _Cpos {
        inline constexpr _Cend_fn cend;
    }
    using namespace _Cpos;

         namespace _Rbegin {
        template <class _Ty>
        void rbegin(_Ty&) = delete;
        template <class _Ty>
        void rbegin(const _Ty&) = delete;

                 template <class _Ty>
        concept _Has_member = requires(_Ty __t) {
            { _Fake_decay_copy(__t.rbegin()) } -> input_or_output_iterator;
        };

        template <class _Ty>
        concept _Has_ADL = _Has_class_or_enum_type<_Ty> && requires(_Ty __t) {
            { _Fake_decay_copy(rbegin(__t)) } -> input_or_output_iterator;
        };

        template <class _Ty>
        concept _Can_make_reverse = requires(_Ty __t) {
            { ::std::ranges:: begin(__t) } -> bidirectional_iterator;
            { ::std::ranges:: end(__t) } -> same_as<decltype(::std::ranges:: begin(__t))>;
        };
         
        class _Cpo {
        private:
            enum class _St { _None, _Member, _Non_member, _Make_reverse };

            template <class _Ty>
             static constexpr _Choice_t<_St> _Choose() noexcept {
                ;
                if constexpr (_Has_member<_Ty>) {
                    return {_St::_Member, noexcept(_Fake_decay_copy(::std:: declval<_Ty>().rbegin()))};
                } else if constexpr (_Has_ADL<_Ty>) {
                    return {_St::_Non_member, noexcept(_Fake_decay_copy(rbegin(::std:: declval<_Ty>())))};
                } else if constexpr (_Can_make_reverse<_Ty>) {
                    return {_St::_Make_reverse, noexcept(::std:: make_reverse_iterator(::std::ranges:: end(::std:: declval<_Ty>())))};
                } else {
                    return {_St::_None};
                }
            }

            template <class _Ty>
            static constexpr _Choice_t<_St> _Choice = _Choose<_Ty>();

        public:
                         template <_Should_range_access _Ty>
                requires (_Choice<_Ty&>._Strategy != _St::_None)
             constexpr auto operator()(_Ty&& _Val) const noexcept(_Choice<_Ty&>._No_throw) {
                constexpr _St _Strat = _Choice<_Ty&>._Strategy;

                if constexpr (_Strat == _St::_Member) {
                    return _Val.rbegin();
                } else if constexpr (_Strat == _St::_Non_member) {
                    return rbegin(_Val);
                } else if constexpr (_Strat == _St::_Make_reverse) {
                    return ::std:: make_reverse_iterator(::std::ranges:: end(_Val));
                } else {
                    static_assert(_Always_false<_Ty>, "should be unreachable");
                }
            }
                     };
    }  
    namespace _Cpos {
        inline constexpr _Rbegin::_Cpo rbegin;
    }
    using namespace _Cpos;

         namespace _Rend {
        template <class _Ty>
        void rend(_Ty&) = delete;
        template <class _Ty>
        void rend(const _Ty&) = delete;

                 template <class _Ty>
        concept _Has_member = requires(_Ty __t) {
            { _Fake_decay_copy(__t.rend()) } -> sentinel_for<decltype(::std::ranges:: rbegin(__t))>;
        };

        template <class _Ty>
        concept _Has_ADL = _Has_class_or_enum_type<_Ty> && requires(_Ty __t) {
            { _Fake_decay_copy(rend(__t)) } -> sentinel_for<decltype(::std::ranges:: rbegin(__t))>;
        };

        template <class _Ty>
        concept _Can_make_reverse = requires(_Ty __t) {
            { ::std::ranges:: begin(__t) } -> bidirectional_iterator;
            { ::std::ranges:: end(__t) } -> same_as<decltype(::std::ranges:: begin(__t))>;
        };
         
        class _Cpo {
        private:
            enum class _St { _None, _Member, _Non_member, _Make_reverse };

            template <class _Ty>
             static constexpr _Choice_t<_St> _Choose() noexcept {
                ;
                if constexpr (_Has_member<_Ty>) {
                    return {_St::_Member, noexcept(_Fake_decay_copy(::std:: declval<_Ty>().rend()))};
                } else if constexpr (_Has_ADL<_Ty>) {
                    return {_St::_Non_member, noexcept(_Fake_decay_copy(rend(::std:: declval<_Ty>())))};
                } else if constexpr (_Can_make_reverse<_Ty>) {
                    return {
                        _St::_Make_reverse, noexcept(::std:: make_reverse_iterator(::std::ranges:: begin(::std:: declval<_Ty>())))};
                } else {
                    return {_St::_None};
                }
            }

            template <class _Ty>
            static constexpr _Choice_t<_St> _Choice = _Choose<_Ty>();

        public:
                         template <_Should_range_access _Ty>
                requires (_Choice<_Ty&>._Strategy != _St::_None)
             constexpr auto operator()(_Ty&& _Val) const noexcept(_Choice<_Ty&>._No_throw) {
                constexpr _St _Strat = _Choice<_Ty&>._Strategy;

                if constexpr (_Strat == _St::_Member) {
                    return _Val.rend();
                } else if constexpr (_Strat == _St::_Non_member) {
                    return rend(_Val);
                } else if constexpr (_Strat == _St::_Make_reverse) {
                    return ::std:: make_reverse_iterator(::std::ranges:: begin(_Val));
                } else {
                    static_assert(_Always_false<_Ty>, "should be unreachable");
                }
            }
                     };
    }  
    namespace _Cpos {
        inline constexpr _Rend::_Cpo rend;
    }
    using namespace _Cpos;

         struct _Crbegin_fn {
                 template <class _Ty, class _CTy = _Const_thru_ref<_Ty>>
         constexpr auto operator()(_Ty&& _Val) const
            noexcept(noexcept(::std::ranges:: rbegin(static_cast<_CTy&&>(_Val))))
            requires requires { ::std::ranges:: rbegin(static_cast<_CTy&&>(_Val)); } {
            return ::std::ranges:: rbegin(static_cast<_CTy&&>(_Val));
        }
             };

    namespace _Cpos {
        inline constexpr _Crbegin_fn crbegin;
    }
    using namespace _Cpos;

         struct _Crend_fn {
                 template <class _Ty, class _CTy = _Const_thru_ref<_Ty>>
         constexpr auto operator()(_Ty&& _Val) const
            noexcept(noexcept(::std::ranges:: rend(static_cast<_CTy&&>(_Val))))
            requires requires { ::std::ranges:: rend(static_cast<_CTy&&>(_Val)); } {
            return ::std::ranges:: rend(static_cast<_CTy&&>(_Val));
        }
             };

    namespace _Cpos {
        inline constexpr _Crend_fn crend;
    }
    using namespace _Cpos;

         template <class>
    inline constexpr bool disable_sized_range = false;

         namespace _Size {
        template <class _Ty>
        void size(_Ty&) = delete;
        template <class _Ty>
        void size(const _Ty&) = delete;

                 template <class _Ty, class _UnCV>
        concept _Has_member = !disable_sized_range<_UnCV> && requires(_Ty __t) {
            { _Fake_decay_copy(__t.size()) } -> _Integer_like;
        };

        template <class _Ty, class _UnCV>
        concept _Has_ADL = _Has_class_or_enum_type<_Ty> && !disable_sized_range<_UnCV> && requires(_Ty __t) {
            { _Fake_decay_copy(size(__t)) } -> _Integer_like;
        };

        template <class _Ty>
        concept _Can_difference = requires(_Ty __t) {
            { ::std::ranges:: begin(__t) } -> forward_iterator;
            { ::std::ranges:: end(__t) } -> sized_sentinel_for<decltype(::std::ranges:: begin(__t))>;
        };
         
        class _Cpo {
        private:
            enum class _St { _None, _Array, _Member, _Non_member, _Subtract };

            template <class _Ty>
             static constexpr _Choice_t<_St> _Choose() noexcept {
                ;
                using _UnCV = remove_cvref_t<_Ty>;

                if constexpr (is_array_v<_UnCV>) {
                    if constexpr (extent_v<_UnCV> != 0) {
                        return {_St::_Array, true};
                    } else {
                        return {_St::_None};
                    }
                } else if constexpr (_Has_member<_Ty, _UnCV>) {
                    return {_St::_Member, noexcept(_Fake_decay_copy(::std:: declval<_Ty>().size()))};
                } else if constexpr (_Has_ADL<_Ty, _UnCV>) {
                    return {_St::_Non_member, noexcept(_Fake_decay_copy(size(::std:: declval<_Ty>())))};
                } else if constexpr (_Can_difference<_Ty>) {
                    return {_St::_Subtract,
                        noexcept(::std::ranges:: end(::std:: declval<_Ty>()) - ::std::ranges:: begin(::std:: declval<_Ty>()))};
                } else {
                    return {_St::_None};
                }
            }

            template <class _Ty>
            static constexpr _Choice_t<_St> _Choice = _Choose<_Ty>();

        public:
                         template <class _Ty>
                requires (_Choice<_Ty&>._Strategy != _St::_None)
             constexpr auto operator()(_Ty&& _Val) const noexcept(_Choice<_Ty&>._No_throw) {
                constexpr _St _Strat = _Choice<_Ty&>._Strategy;

                if constexpr (_Strat == _St::_Array) {
                                         return extent_v<remove_cvref_t<_Ty&>>;
                } else if constexpr (_Strat == _St::_Member) {
                    return _Val.size();
                } else if constexpr (_Strat == _St::_Non_member) {
                    return size(_Val);
                } else if constexpr (_Strat == _St::_Subtract) {
                    const auto _Delta = ::std::ranges:: end(_Val) - ::std::ranges:: begin(_Val);
                    return static_cast<_Make_unsigned_like_t<remove_cv_t<decltype(_Delta)>>>(_Delta);
                } else {
                    static_assert(_Always_false<_Ty>, "should be unreachable");
                }
            }
                     };
    }  
    namespace _Cpos {
        inline constexpr _Size::_Cpo size;
    }
    using namespace _Cpos;

         namespace _Empty {
                 template <class _Ty>
        concept _Has_member = requires(_Ty __t) {
            static_cast<bool>(__t.empty());
        };

        template <class _Ty>
        concept _Has_size = requires(_Ty __t) {
            ::std::ranges:: size(__t);
        };

        template <class _Ty>
        concept _Can_begin_end = requires(_Ty __t) {
            { ::std::ranges:: begin(__t) } -> forward_iterator;
            ::std::ranges:: end(__t);
        };
         
        class _Cpo {
        private:
            enum class _St { _None, _Member, _Size, _Compare };

            template <class _Ty>
             static constexpr _Choice_t<_St> _Choose() noexcept {
                ;
                if constexpr (is_unbounded_array_v<remove_reference_t<_Ty>>) {
                    return {_St::_None};
                } else if constexpr (_Has_member<_Ty>) {
                    return {_St::_Member, noexcept(static_cast<bool>(::std:: declval<_Ty>().empty()))};
                } else if constexpr (_Has_size<_Ty>) {
                    return {_St::_Size, noexcept(::std::ranges:: size(::std:: declval<_Ty>()))};
                } else if constexpr (_Can_begin_end<_Ty>) {
                    constexpr auto _Nothrow = noexcept(
                        static_cast<bool>(::std::ranges:: begin(::std:: declval<_Ty>()) == ::std::ranges:: end(::std:: declval<_Ty>())));
                    return {_St::_Compare, _Nothrow};
                } else {
                    return {_St::_None};
                }
            }

            template <class _Ty>
            static constexpr _Choice_t<_St> _Choice = _Choose<_Ty>();

        public:
                         template <class _Ty>
                requires (_Choice<_Ty&>._Strategy != _St::_None)
             constexpr bool operator()(_Ty&& _Val) const noexcept(_Choice<_Ty&>._No_throw) {
                constexpr _St _Strat = _Choice<_Ty&>._Strategy;

                if constexpr (_Strat == _St::_Member) {
                    return static_cast<bool>(_Val.empty());
                } else if constexpr (_Strat == _St::_Size) {
                    return ::std::ranges:: size(_Val) == 0;
                } else if constexpr (_Strat == _St::_Compare) {
                    return static_cast<bool>(::std::ranges:: begin(_Val) == ::std::ranges:: end(_Val));
                } else {
                    static_assert(_Always_false<_Ty>, "should be unreachable");
                }
            }
                     };
    }  
    namespace _Cpos {
        inline constexpr _Empty::_Cpo empty;
    }
    using namespace _Cpos;

         namespace _Data {
                 template <class _Ty>
        concept _Points_to_object = is_pointer_v<_Ty> && is_object_v<remove_pointer_t<_Ty>>;

        template <class _Ty>
        concept _Has_member = requires(_Ty __t) {
            { _Fake_decay_copy(__t.data()) } -> _Points_to_object;
        };

        template <class _Ty>
        concept _Has_contiguous_iterator = requires(_Ty __t) {
            { ::std::ranges:: begin(__t) } -> contiguous_iterator;
        };
         
        class _Cpo {
        private:
            enum class _St { _None, _Member, _Address };

            template <class _Ty>
             static constexpr _Choice_t<_St> _Choose() noexcept {
                ;
                if constexpr (_Has_member<_Ty>) {
                    return {_St::_Member, noexcept(::std:: declval<_Ty>().data())};
                } else if constexpr (_Has_contiguous_iterator<_Ty>) {
                    return {_St::_Address, noexcept(::std:: to_address(::std::ranges:: begin(::std:: declval<_Ty>())))};
                } else {
                    return {_St::_None};
                }
            }

            template <class _Ty>
            static constexpr _Choice_t<_St> _Choice = _Choose<_Ty>();

        public:
                         template <_Should_range_access _Ty>
                requires (_Choice<_Ty&>._Strategy != _St::_None)
             constexpr auto operator()(_Ty&& _Val) const noexcept(_Choice<_Ty&>._No_throw) {
                constexpr _St _Strat = _Choice<_Ty&>._Strategy;

                if constexpr (_Strat == _St::_Member) {
                    return _Val.data();
                } else if constexpr (_Strat == _St::_Address) {
                    return ::std:: to_address(::std::ranges:: begin(_Val));
                } else {
                    static_assert(_Always_false<_Ty>, "should be unreachable");
                }
            }
                     };
    }  
    namespace _Cpos {
        inline constexpr _Data::_Cpo data;
    }
    using namespace _Cpos;

         struct _Cdata_fn {
                 template <class _Ty, class _CTy = _Const_thru_ref<_Ty>>
         constexpr auto operator()(_Ty&& _Val) const
            noexcept(noexcept(::std::ranges:: data(static_cast<_CTy&&>(_Val))))
            requires requires { ::std::ranges:: data(static_cast<_CTy&&>(_Val)); } {
            return ::std::ranges:: data(static_cast<_CTy&&>(_Val));
        }
             };

    namespace _Cpos {
        inline constexpr _Cdata_fn cdata;
    }
    using namespace _Cpos;

              template <class _Rng>
    concept sized_range = range<_Rng> && requires(_Rng& __r) {
        ::std::ranges:: size(__r);
    };
     
         template <sized_range _Rng>
    using range_size_t = decltype(::std::ranges:: size(::std:: declval<_Rng&>()));

         struct view_base {};

         template <class _Ty>
    inline constexpr bool enable_view = derived_from<_Ty, view_base>;

              template <class _Ty>
    concept view = range<_Ty> && movable<_Ty> && default_initializable<_Ty> && enable_view<_Ty>;

         template <class _Rng, class _Ty>
    concept output_range = range<_Rng> && output_iterator<iterator_t<_Rng>, _Ty>;

         template <class _Rng>
    concept input_range = range<_Rng> && input_iterator<iterator_t<_Rng>>;

         template <class _Rng>
    concept forward_range = range<_Rng> && forward_iterator<iterator_t<_Rng>>;

         template <class _Rng>
    concept bidirectional_range = range<_Rng> && bidirectional_iterator<iterator_t<_Rng>>;

         template <class _Rng>
    concept random_access_range = range<_Rng> && random_access_iterator<iterator_t<_Rng>>;

         template <class _Rng>
    concept contiguous_range = range<_Rng> && contiguous_iterator<iterator_t<_Rng>> && requires(_Rng& __r) {
        { ::std::ranges:: data(__r) } -> same_as<add_pointer_t<range_reference_t<_Rng>>>;
    };
     
         class _Not_quite_object {
    public:
                                             
        struct _Construct_tag {
            explicit _Construct_tag() = default;
        };

        _Not_quite_object() = delete;

        constexpr explicit _Not_quite_object(_Construct_tag) noexcept {}

        _Not_quite_object(const _Not_quite_object&) = delete;
        _Not_quite_object& operator=(const _Not_quite_object&) = delete;

        void operator&() const = delete;

    protected:
        ~_Not_quite_object() = default;
    };

         class _Advance_fn : private _Not_quite_object {
    public:
        using _Not_quite_object::_Not_quite_object;

        template <input_or_output_iterator _It>
        constexpr void operator()(_It& _Where, iter_difference_t<_It> _Off) const {
            if constexpr (random_access_iterator<_It>) {
                _Where += _Off;
            } else {
                if constexpr (!bidirectional_iterator<_It>) {
                    ;
                }

                decltype(auto) _UWhere      = _Get_unwrapped_n(::std:: move(_Where), _Off);
                constexpr bool _Need_rewrap = !is_reference_v<decltype(_Get_unwrapped_n(::std:: move(_Where), _Off))>;

                if constexpr (bidirectional_iterator<_It>) {
                    for (; _Off < 0; ++_Off) {
                        --_UWhere;
                    }
                }

                for (; _Off > 0; --_Off) {
                    ++_UWhere;
                }

                if constexpr (_Need_rewrap) {
                    _Seek_wrapped(_Where, ::std:: move(_UWhere));
                }
            }
        }

        template <input_or_output_iterator _It, sentinel_for<_It> _Se>
        constexpr void operator()(_It& _Where, _Se _Last) const {
            if constexpr (assignable_from<_It&, _Se>) {
                _Where = static_cast<_Se&&>(_Last);
            } else if constexpr (sized_sentinel_for<_Se, _It>) {
                (*this)(_Where, _Last - _Where);
            } else {
                _Adl_verify_range(_Where, _Last);

                decltype(auto) _UWhere      = _Get_unwrapped(static_cast<_It&&>(_Where));
                constexpr bool _Need_rewrap = !is_reference_v<decltype(_Get_unwrapped(static_cast<_It&&>(_Where)))>;
                decltype(auto) _ULast       = _Get_unwrapped(static_cast<_Se&&>(_Last));

                while (_UWhere != _ULast) {
                    ++_UWhere;
                }

                if constexpr (_Need_rewrap) {
                    _Seek_wrapped(_Where, ::std:: move(_UWhere));
                }
            }
        }

        template <input_or_output_iterator _It, sentinel_for<_It> _Se>
        constexpr iter_difference_t<_It> operator()(_It& _Where, iter_difference_t<_It> _Off, _Se _Last) const {
            if constexpr (sized_sentinel_for<_Se, _It>) {
                const iter_difference_t<_It> _Delta = _Last - _Where;
                if ((_Off < 0 && _Off <= _Delta) || (_Off > 0 && _Off >= _Delta)) {
                    if constexpr (assignable_from<_It&, _Se>) {
                        _Where = static_cast<_Se&&>(_Last);
                    } else {
                        (*this)(_Where, _Delta);
                    }
                    return _Off - _Delta;
                }

                (*this)(_Where, _Off);
                return 0;
            } else {
                                 if constexpr (bidirectional_iterator<_It>) {
                    for (; _Off < 0 && _Where != _Last; ++_Off) {
                        --_Where;
                    }
                } else {
                    ;
                }

                for (; _Off > 0 && _Where != _Last; --_Off) {
                    ++_Where;
                }

                return _Off;
            }
        }
    };

    inline constexpr _Advance_fn advance{_Not_quite_object::_Construct_tag{}};

         class _Distance_fn : private _Not_quite_object {
    public:
        using _Not_quite_object::_Not_quite_object;

        template <input_or_output_iterator _It, sentinel_for<_It> _Se>
         constexpr iter_difference_t<_It> operator()(_It _First, _Se _Last) const
            noexcept(_Nothrow_distance<_It, _Se>)   {
            if constexpr (sized_sentinel_for<_Se, _It>) {
                return _Last - _First;
            } else {
                _Adl_verify_range(_First, _Last);
                return _Distance_unchecked(_Get_unwrapped(::std:: move(_First)), _Get_unwrapped(::std:: move(_Last)));
            }
        }

        template <range _Rng>
         constexpr range_difference_t<_Rng> operator()(_Rng&& _Range) const
            noexcept(_Nothrow_size<_Rng>)   {
            if constexpr (sized_range<_Rng>) {
                return static_cast<range_difference_t<_Rng>>(::std::ranges:: size(_Range));
            } else {
                return _Distance_unchecked(_Ubegin(_Range), _Uend(_Range));
            }
        }

    private:
        template <class _It, class _Se>
         static constexpr iter_difference_t<_It> _Distance_unchecked(_It _First, const _Se _Last) noexcept(
            _Nothrow_distance<_It, _Se>) {
            ;
            ;

            iter_difference_t<_It> _Count = 0;
            for (; _First != _Last; ++_First) {
                ++_Count;
            }

            return _Count;
        }

        template <class _It, class _Se>
        static constexpr bool _Nothrow_distance = noexcept(
            noexcept(++::std:: declval<_Unwrapped_t<_It>&>() != ::std:: declval<const _Unwrapped_t<_Se>&>()));
        template <class _It, sized_sentinel_for<_It> _Se>
        static constexpr bool _Nothrow_distance<_It, _Se> = noexcept(
            noexcept(::std:: declval<_Se&>() - ::std:: declval<_It&>()));

        template <class _Rng>
        static constexpr bool _Nothrow_size = _Nothrow_distance<iterator_t<_Rng>, sentinel_t<_Rng>>;
        template <sized_range _Rng>
        static constexpr bool _Nothrow_size<_Rng> = noexcept(::std::ranges:: size(::std:: declval<_Rng&>()));
    };

    inline constexpr _Distance_fn distance{_Not_quite_object::_Construct_tag{}};

         class _Ssize_fn {
    public:
                 template <class _Rng>
         constexpr auto operator()(_Rng&& _Range) const requires requires { ::std::ranges:: size(_Range); } {
            using _Sty = _Make_signed_like_t<decltype(::std::ranges:: size(_Range))>;
            using _Ty  = common_type_t<conditional_t<is_integral_v<_Sty>, ptrdiff_t, _Sty>, _Sty>;
            return static_cast<_Ty>(::std::ranges:: size(_Range));
        }
             };

    namespace _Cpos {
        inline constexpr _Ssize_fn ssize;
    }
    using namespace _Cpos;

         class _Next_fn : private _Not_quite_object {
    public:
        using _Not_quite_object::_Not_quite_object;

        template <input_or_output_iterator _It>
         constexpr _It operator()(_It _Where) const {
            ++_Where;
            return _Where;
        }

        template <input_or_output_iterator _It>
         constexpr _It operator()(_It _Where, const iter_difference_t<_It> _Off) const {
            ::std::ranges:: advance(_Where, _Off);
            return _Where;
        }

        template <input_or_output_iterator _It, sentinel_for<_It> _Se>
         constexpr _It operator()(_It _Where, _Se _Last) const {
            ::std::ranges:: advance(_Where, static_cast<_Se&&>(_Last));
            return _Where;
        }

        template <input_or_output_iterator _It, sentinel_for<_It> _Se>
         constexpr _It operator()(_It _Where, const iter_difference_t<_It> _Off, _Se _Last) const {
            ::std::ranges:: advance(_Where, _Off, static_cast<_Se&&>(_Last));
            return _Where;
        }
    };

    inline constexpr _Next_fn next{_Not_quite_object::_Construct_tag{}};

         class _Prev_fn : private _Not_quite_object {
    public:
        using _Not_quite_object::_Not_quite_object;

        template <bidirectional_iterator _It>
         constexpr _It operator()(_It _Where) const {
            --_Where;
            return _Where;
        }

        template <bidirectional_iterator _It>
         constexpr _It operator()(_It _Where, const iter_difference_t<_It> _Off) const {
            ;
            ::std::ranges:: advance(_Where, -_Off);
            return _Where;
        }

        template <bidirectional_iterator _It>
         constexpr _It operator()(_It _Where, const iter_difference_t<_It> _Off, _It _Last) const {
            ;
            ::std::ranges:: advance(_Where, -_Off, static_cast<_It&&>(_Last));
            return _Where;
        }
    };

    inline constexpr _Prev_fn prev{_Not_quite_object::_Construct_tag{}};

         template <forward_iterator _It, sentinel_for<_It> _Se>
     constexpr _It _Find_last_iterator(
        const _It& _First, const _Se& _Last, const iter_difference_t<_It> _Count) {
                 ;
        if constexpr (is_same_v<_It, _Se>) {
            return _Last;
        } else {
            return ::std::ranges:: next(_First, _Count);
        }
    }

         struct equal_to {
                 template <class _Ty1, class _Ty2>
            requires equality_comparable_with<_Ty1, _Ty2>           constexpr bool operator()(_Ty1&& _Left, _Ty2&& _Right) const noexcept(noexcept(
            static_cast<bool>(static_cast<_Ty1&&>(_Left) == static_cast<_Ty2&&>(_Right))))   {
            return static_cast<bool>(static_cast<_Ty1&&>(_Left) == static_cast<_Ty2&&>(_Right));
        }
         
        using is_transparent = int;
    };

         struct less {
                 template <class _Ty1, class _Ty2>
            requires totally_ordered_with<_Ty1, _Ty2>           constexpr bool operator()(_Ty1&& _Left, _Ty2&& _Right) const noexcept(noexcept(
            static_cast<bool>(static_cast<_Ty1&&>(_Left) < static_cast<_Ty2&&>(_Right))))   {
            return static_cast<bool>(static_cast<_Ty1&&>(_Left) < static_cast<_Ty2&&>(_Right));
        }
         
        using is_transparent = int;
    };

              template <class _Rng>
    concept common_range = range<_Rng>
        && same_as<iterator_t<_Rng>, sentinel_t<_Rng>>;

         template <class _Ty>
    concept _Can_empty = requires(_Ty __t) { ::std::ranges:: empty(__t); };

    template <class _Derived>
        requires is_class_v<_Derived> && same_as<_Derived, remove_cv_t<_Derived>>
    class view_interface : public view_base {
    private:
         constexpr _Derived& _Cast() noexcept {
            static_assert(derived_from<_Derived, view_interface>,
                "view_interface's template argument D must derive from view_interface<D> (N4849 [view.interface]/2).");
            static_assert(view<_Derived>,
                "view_interface's template argument must model the view concept (N4849 [view.interface]/2).");
            return static_cast<_Derived&>(*this);
        }

         constexpr const _Derived& _Cast() const noexcept {
            static_assert(derived_from<_Derived, view_interface>,
                "view_interface's template argument D must derive from view_interface<D> (N4849 [view.interface]/2).");
            static_assert(view<_Derived>,
                "view_interface's template argument must model the view concept (N4849 [view.interface]/2).");
            return static_cast<const _Derived&>(*this);
        }

    public:
         constexpr bool empty() requires forward_range<_Derived>
        {
            auto& _Self = _Cast();
            return ::std::ranges:: begin(_Self) == ::std::ranges:: end(_Self);
        }

         constexpr bool empty() const requires forward_range<const _Derived>
        {
            auto& _Self = _Cast();
            return ::std::ranges:: begin(_Self) == ::std::ranges:: end(_Self);
        }

        constexpr explicit operator bool() requires _Can_empty<_Derived>
        {
            return !::std::ranges:: empty(_Cast());
        }

        constexpr explicit operator bool() const requires _Can_empty<const _Derived>
        {
            return !::std::ranges:: empty(_Cast());
        }

         constexpr auto data() requires contiguous_iterator<iterator_t<_Derived>>
        {
            return ::std:: to_address(::std::ranges:: begin(_Cast()));
        }

         constexpr auto data() const
            requires range<const _Derived> && contiguous_iterator<iterator_t<const _Derived>>
        {
            return ::std:: to_address(::std::ranges:: begin(_Cast()));
        }

         constexpr auto size()
            requires forward_range<_Derived> && sized_sentinel_for<sentinel_t<_Derived>, iterator_t<_Derived>>
        {
            auto& _Self = _Cast();
            return ::std::ranges:: end(_Self) - ::std::ranges:: begin(_Self);
        }

         constexpr auto size() const requires forward_range<const _Derived>
            && sized_sentinel_for<sentinel_t<const _Derived>, iterator_t<const _Derived>>
        {
            auto& _Self = _Cast();
            return ::std::ranges:: end(_Self) - ::std::ranges:: begin(_Self);
        }

         constexpr decltype(auto) front() requires forward_range<_Derived>
        {
            auto& _Self = _Cast();
            return *::std::ranges:: begin(_Self);
        }

         constexpr decltype(auto) front() const requires forward_range<const _Derived>
        {
            auto& _Self = _Cast();
            return *::std::ranges:: begin(_Self);
        }

         constexpr decltype(auto) back() requires bidirectional_range<_Derived> && common_range<_Derived>
        {
            auto& _Self = _Cast();
            auto _Last = ::std::ranges:: end(_Self);
            return *--_Last;
        }

         constexpr decltype(auto) back() const
            requires bidirectional_range<const _Derived> && common_range<const _Derived>
        {
            auto& _Self = _Cast();
            auto _Last = ::std::ranges:: end(_Self);
            return *--_Last;
        }

        template <random_access_range _Rng = _Derived>
         constexpr decltype(auto) operator[](const range_difference_t<_Rng> _Idx) {
            auto& _Self = _Cast();
            return ::std::ranges:: begin(_Self)[_Idx];
        }

        template <random_access_range _Rng = const _Derived>
         constexpr decltype(auto) operator[](const range_difference_t<_Rng> _Idx) const {
            auto& _Self = _Cast();
            return ::std::ranges:: begin(_Self)[_Idx];
        }
    };

         enum class subrange_kind : bool { unsized, sized };
     }  
  template <size_t _Index, class... _Types>
 constexpr tuple_element_t<_Index, tuple<_Types...>>& get(tuple<_Types...>& _Tuple) noexcept;
template <size_t _Index, class... _Types>
 constexpr const tuple_element_t<_Index, tuple<_Types...>>& get(const tuple<_Types...>& _Tuple) noexcept;
template <size_t _Index, class... _Types>
 constexpr tuple_element_t<_Index, tuple<_Types...>>&& get(tuple<_Types...>&& _Tuple) noexcept;
template <size_t _Index, class... _Types>
 constexpr const tuple_element_t<_Index, tuple<_Types...>>&& get(const tuple<_Types...>&& _Tuple) noexcept;

namespace ranges {
              template <class _From, class _To>
    concept _Convertible_to_non_slicing = convertible_to<_From, _To>
        && !(is_pointer_v<decay_t<_From>>
            && is_pointer_v<decay_t<_To>>
            && _Not_same_as<remove_pointer_t<decay_t<_From>>, remove_pointer_t<decay_t<_To>>>);

    template <class _Ty>
    concept _Pair_like = !is_reference_v<_Ty> && requires(_Ty __t) {
        typename tuple_size<_Ty>::type;
        requires derived_from<tuple_size<_Ty>, integral_constant<size_t, 2>>;
        typename tuple_element_t<0, remove_const_t<_Ty>>;
        typename tuple_element_t<1, remove_const_t<_Ty>>;
        { ::std:: get<0>(__t) } -> convertible_to<const tuple_element_t<0, _Ty>&>;
        { ::std:: get<1>(__t) } -> convertible_to<const tuple_element_t<1, _Ty>&>;
    };

    template <class _Ty, class _First, class _Second>
    concept _Pair_like_convertible_from = !range<_Ty> && _Pair_like<_Ty>
        && constructible_from<_Ty, _First, _Second>
        && _Convertible_to_non_slicing<_First, tuple_element_t<0, _Ty>>
        && convertible_to<_Second, tuple_element_t<1, _Ty>>;

    template <input_or_output_iterator _It, sentinel_for<_It> _Se = _It,
        subrange_kind _Ki = sized_sentinel_for<_Se, _It> ? subrange_kind::sized : subrange_kind::unsized>
        requires (_Ki == subrange_kind::sized || !sized_sentinel_for<_Se, _It>)
    class subrange;
     
    template <class _It, class _Se, subrange_kind _Ki,
        bool _Store = _Ki == subrange_kind::sized && !sized_sentinel_for<_Se, _It>>
    class _Subrange_base : public view_interface<subrange<_It, _Se, _Ki>> {      protected:
        using _Size_type                  = _Make_unsigned_like_t<iter_difference_t<_It>>;
        static constexpr bool _Store_size = true;

        _Size_type _Size = 0;

    public:
        _Subrange_base() = default;
        constexpr explicit _Subrange_base(const _Size_type& _Size_) noexcept : _Size(_Size_) {}
    };

    template <class _It, class _Se, subrange_kind _Ki>
    class _Subrange_base<_It, _Se, _Ki, false> : public view_interface<subrange<_It, _Se, _Ki>> {
    protected:
        using _Size_type                  = _Make_unsigned_like_t<iter_difference_t<_It>>;
        static constexpr bool _Store_size = false;

    public:
        _Subrange_base() = default;
        constexpr explicit _Subrange_base(const _Size_type&) noexcept {}
    };

         template <input_or_output_iterator _It, sentinel_for<_It> _Se, subrange_kind _Ki>
        requires (_Ki == subrange_kind::sized || !sized_sentinel_for<_Se, _It>)
    class subrange : public _Subrange_base<_It, _Se, _Ki> {
    private:
        using _Mybase = _Subrange_base<_It, _Se, _Ki>;
        using typename _Mybase::_Size_type;
        using _Mybase::_Store_size;

                   _It _First{};
          _Se _Last{};
         
        template <class _Rng>
        constexpr subrange(true_type, _Rng&& _Val) : subrange{::std:: forward<_Rng>(_Val), ::std::ranges:: size(_Val)} {
                         ;
        }

        template <class _Rng>
        constexpr subrange(false_type, _Rng&& _Val) : subrange{::std::ranges:: begin(_Val), ::std::ranges:: end(_Val)} {
                         ;
        }

    public:
        subrange() = default;

        template <_Convertible_to_non_slicing<_It> _It2>
        constexpr subrange(_It2 _First_, _Se _Last_) requires (!_Store_size)
            : _First(::std:: move(_First_)), _Last(::std:: move(_Last_)) {}

        template <_Convertible_to_non_slicing<_It> _It2>
        constexpr subrange(_It2 _First_, _Se _Last_, const _Size_type _Size_) requires (_Ki == subrange_kind::sized)
            : _Mybase(_Size_), _First(::std:: move(_First_)), _Last(::std:: move(_Last_)) {
            if constexpr (sized_sentinel_for<_Se, _It>) {
                ;
            }
        }

        template <_Not_same_as<subrange> _Rng>
            requires borrowed_range<_Rng>
                && _Convertible_to_non_slicing<iterator_t<_Rng>, _It>
                && convertible_to<sentinel_t<_Rng>, _Se>
        constexpr subrange(_Rng&& _Val) requires (!_Store_size || sized_range<_Rng>)
            : subrange{bool_constant<_Store_size>{}, ::std:: forward<_Rng>(_Val)} {}

        template <borrowed_range _Rng>
            requires _Convertible_to_non_slicing<iterator_t<_Rng>, _It> && convertible_to<sentinel_t<_Rng>, _Se>
        constexpr subrange(_Rng&& _Val, const _Size_type _Count) requires (_Ki == subrange_kind::sized)
            : subrange{::std::ranges:: begin(_Val), ::std::ranges:: end(_Val), _Count} {}

        template <_Not_same_as<subrange> _Pair_like>
            requires _Pair_like_convertible_from<_Pair_like, const _It&, const _Se&>
        constexpr operator _Pair_like() const {
            return _Pair_like(_First, _Last);
        }

         constexpr _It begin() const requires copyable<_It> {
            return _First;
        }
         constexpr _It begin() requires (!copyable<_It>) {
            return ::std:: move(_First);
        }

         constexpr _Se end() const {
            return _Last;
        }

         constexpr bool empty() const {
            return _First == _Last;
        }

         constexpr _Size_type size() const requires (_Ki == subrange_kind::sized) {
            if constexpr (_Store_size) {
                return this->_Size;
            } else {
                return static_cast<_Size_type>(_Last - _First);
            }
        }

         constexpr subrange next() const & requires forward_iterator<_It> {
            auto _Tmp = *this;
            if (_Tmp._First != _Tmp._Last) {
                ++_Tmp._First;
                if constexpr (_Store_size) {
                    --_Tmp._Size;
                }
            }
            return _Tmp;
        }
         constexpr subrange next(const iter_difference_t<_It> _Count) const & requires forward_iterator<_It> {
            auto _Tmp = *this;
            _Tmp.advance(_Count);
            return _Tmp;
        }

         constexpr subrange next() && {
            if (_First != _Last) {
                ++_First;
                if constexpr (_Store_size) {
                    --this->_Size;
                }
            }
            return ::std:: move(*this);
        }
         constexpr subrange next(const iter_difference_t<_It> _Count) && {
            advance(_Count);
            return ::std:: move(*this);
        }

         constexpr subrange prev() const requires bidirectional_iterator<_It> {
            auto _Tmp = *this;
            --_Tmp._First;
            if constexpr (_Store_size) {
                ++_Tmp._Size;
            }
            return _Tmp;
        }
         constexpr subrange prev(const iter_difference_t<_It> _Count) const
            requires bidirectional_iterator<_It> {
            auto _Tmp = *this;
            _Tmp.advance(-_Count);
            return _Tmp;
        }

        constexpr subrange& advance(const iter_difference_t<_It> _Count) {
                         if constexpr (bidirectional_iterator<_It>) {
                if (_Count < 0) {
                    ::std::ranges:: advance(_First, _Count);
                    if constexpr (_Store_size) {
                        this->_Size += static_cast<_Size_type>(-_Count);
                    }
                    return *this;
                }
            }

            const auto _Remainder = ::std::ranges:: advance(_First, _Count, _Last);
            if constexpr (_Store_size) {
                this->_Size -= static_cast<_Size_type>(_Count - _Remainder);
            }
            return *this;
        }
    };
     
    template <input_or_output_iterator _It, sentinel_for<_It> _Se>
    subrange(_It, _Se) -> subrange<_It, _Se>;

    template <input_or_output_iterator _It, sentinel_for<_It> _Se>
    subrange(_It, _Se, _Make_unsigned_like_t<iter_difference_t<_It>>) -> subrange<_It, _Se, subrange_kind::sized>;

    template <borrowed_range _Rng>
    subrange(_Rng &&) -> subrange<iterator_t<_Rng>, sentinel_t<_Rng>,
        (sized_range<_Rng> || sized_sentinel_for<sentinel_t<_Rng>, iterator_t<_Rng>>) ? subrange_kind::sized
                                                                                      : subrange_kind::unsized>;

    template <borrowed_range _Rng>
    subrange(_Rng&&, _Make_unsigned_like_t<range_difference_t<_Rng>>)
        -> subrange<iterator_t<_Rng>, sentinel_t<_Rng>, subrange_kind::sized>;

    template <class _It, class _Se, subrange_kind _Ki>
    inline constexpr bool enable_borrowed_range<subrange<_It, _Se, _Ki>> = true;

         template <size_t _Idx, class _It, class _Se, subrange_kind _Ki>
        requires (_Idx < 2)
     constexpr auto get(const subrange<_It, _Se, _Ki>& _Val) {
        if constexpr (_Idx == 0) {
            return _Val.begin();
        } else {
            return _Val.end();
        }
    }

    template <size_t _Idx, class _It, class _Se, subrange_kind _Ki>
        requires (_Idx < 2)
     constexpr auto get(subrange<_It, _Se, _Ki>&& _Val) {
        if constexpr (_Idx == 0) {
            return _Val.begin();
        } else {
            return _Val.end();
        }
    }
     }  
using ranges::get;

template <class _It, class _Se, ranges::subrange_kind _Ki>
struct tuple_size<ranges::subrange<_It, _Se, _Ki>> : integral_constant<size_t, 2> {};

template <class _It, class _Se, ranges::subrange_kind _Ki>
struct tuple_element<0, ranges::subrange<_It, _Se, _Ki>> {
    using type = _It;
};

template <class _It, class _Se, ranges::subrange_kind _Ki>
struct tuple_element<1, ranges::subrange<_It, _Se, _Ki>> {
    using type = _Se;
};

template <class _It, class _Se, ranges::subrange_kind _Ki>
struct tuple_element<0, const ranges::subrange<_It, _Se, _Ki>> {
    using type = _It;
};

template <class _It, class _Se, ranges::subrange_kind _Ki>
struct tuple_element<1, const ranges::subrange<_It, _Se, _Ki>> {
    using type = _Se;
};

namespace ranges {
         struct dangling {
        constexpr dangling() noexcept = default;
        template <class... _Args>
        constexpr dangling(_Args&&...) noexcept {}
    };

         template <range _Rng>
    using borrowed_iterator_t = conditional_t<borrowed_range<_Rng>, iterator_t<_Rng>, dangling>;

         template <range _Rng>
    using borrowed_subrange_t = conditional_t<borrowed_range<_Rng>, subrange<iterator_t<_Rng>>, dangling>;
}  
struct _Container_proxy;
struct _Iterator_base12;

 struct _Default_sentinel {};  
 template <semiregular>
class move_sentinel;

template <class _Iter>
class move_iterator {
public:
    using iterator_type = _Iter;
    using iterator_concept  = input_iterator_tag;
    using iterator_category = conditional_t<derived_from<_Iter_cat_t<_Iter>, random_access_iterator_tag>,
        random_access_iterator_tag, _Iter_cat_t<_Iter>>;
    using value_type      = _Iter_value_t<_Iter>;
    using difference_type = _Iter_diff_t<_Iter>;
    using pointer         = _Iter;
    using reference = iter_rvalue_reference_t<_Iter>;

    constexpr move_iterator() = default;

    constexpr explicit move_iterator(_Iter _Right) noexcept(is_nothrow_move_constructible_v<_Iter>)          : _Current(::std:: move(_Right)) {}

         template <class _Other>
        requires (!is_same_v<_Other, _Iter>) && convertible_to<const _Other&, _Iter>
    constexpr move_iterator(const move_iterator<_Other>& _Right) noexcept(
        is_nothrow_constructible_v<_Iter, const _Other&>)          : _Current(_Right.base()) {}

    template <class _Other>
        requires (!is_same_v<_Other, _Iter>) && convertible_to<const _Other&, _Iter>
            && assignable_from<_Iter&, const _Other&>
    constexpr move_iterator& operator=(const move_iterator<_Other>& _Right) noexcept(
        is_nothrow_assignable_v<_Iter&, const _Other&>)   {
        _Current = _Right.base();
        return *this;
    }
     
     constexpr const iterator_type& base() const& noexcept   {          return _Current;
    }
     constexpr iterator_type base() && noexcept(is_nothrow_move_constructible_v<_Iter>)   {
        return ::std:: move(_Current);
    }

     constexpr reference operator*() const {
        return ::std::ranges:: iter_move(_Current);
    }

     [[deprecated("warning STL4031: std::move_iterator::operator->() is deprecated in C++20. You can define _SILENCE_CXX20_MOVE_ITERATOR_ARROW_DEPRECATION_WARNING or _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] constexpr pointer operator->() const {
        return _Current;
    }

    constexpr move_iterator& operator++() {
        ++_Current;
        return *this;
    }

    constexpr auto operator++(int) {
        if constexpr (forward_iterator<_Iter>) {
            move_iterator _Tmp = *this;
            ++_Current;
            return _Tmp;
        } else {
            ++_Current;
        }
    }

    constexpr move_iterator& operator--() {
        --_Current;
        return *this;
    }

    constexpr move_iterator operator--(int) {
        move_iterator _Tmp = *this;
        --_Current;
        return _Tmp;
    }

    template <class _Iter2 = _Iter>
     auto operator==(_Default_sentinel _Sentinel) const noexcept
        -> decltype(::std:: declval<const _Iter2&>() == _Sentinel) {
        return _Current == _Sentinel;
    }

    template <class _Iter2 = _Iter>
     auto operator!=(_Default_sentinel _Sentinel) const noexcept
        -> decltype(::std:: declval<const _Iter2&>() != _Sentinel) {
        return _Current != _Sentinel;
    }

     constexpr move_iterator operator+(const difference_type _Off) const {
        return move_iterator(_Current + _Off);
    }

    constexpr move_iterator& operator+=(const difference_type _Off) {
        _Current += _Off;
        return *this;
    }

     constexpr move_iterator operator-(const difference_type _Off) const {
        return move_iterator(_Current - _Off);
    }

    constexpr move_iterator& operator-=(const difference_type _Off) {
        _Current -= _Off;
        return *this;
    }

     constexpr reference operator[](const difference_type _Off) const {
        return ::std::ranges:: iter_move(_Current + _Off);
    }

    template <sentinel_for<_Iter> _Sent>
     friend constexpr bool operator==(const move_iterator& _Left, const move_sentinel<_Sent>& _Right) {
        return _Left._Current == _Right._Get_last();
    }

    template <sized_sentinel_for<_Iter> _Sent>
     friend constexpr difference_type operator-(
        const move_sentinel<_Sent>& _Left, const move_iterator& _Right) {
        return _Left._Get_last() - _Right._Current;
    }

    template <sized_sentinel_for<_Iter> _Sent>
     friend constexpr difference_type operator-(
        const move_iterator& _Left, const move_sentinel<_Sent>& _Right) {
        return _Left._Current - _Right._Get_last();
    }

     friend constexpr reference iter_move(const move_iterator& _It)
        noexcept(noexcept(::std::ranges:: iter_move(_It._Current)))
    {
        return ::std::ranges:: iter_move(_It._Current);
    }

    template <indirectly_swappable<_Iter> _Iter2>
    friend constexpr void iter_swap(const move_iterator& _Left, const move_iterator<_Iter2>& _Right)
        noexcept(noexcept(::std::ranges:: iter_swap(_Left._Current, _Right.base())))
    {
        ::std::ranges:: iter_swap(_Left._Current, _Right.base());
    }

    template <class _Iter2, enable_if_t<_Range_verifiable_v<_Iter, _Iter2>, int> = 0>
    friend constexpr void _Verify_range(const move_iterator& _First, const move_iterator<_Iter2>& _Last) {
        _Verify_range(_First._Current, _Last.base());
    }
    template <sentinel_for<_Iter> _Sent, enable_if_t<_Range_verifiable_v<_Iter, _Sent>, int> = 0>
    friend constexpr void _Verify_range(const move_iterator& _First, const move_sentinel<_Sent>& _Last) {
        _Verify_range(_First._Current, _Last._Get_last());
    }

    using _Prevent_inheriting_unwrap = move_iterator;

    template <class _Iter2 = iterator_type, enable_if_t<_Offset_verifiable_v<_Iter2>, int> = 0>
    constexpr void _Verify_offset(const difference_type _Off) const {
        _Current._Verify_offset(_Off);
    }

    template <class _Iter2 = iterator_type, enable_if_t<_Unwrappable_v<const _Iter2&>, int> = 0>
     constexpr move_iterator<_Unwrapped_t<const _Iter2&>> _Unwrapped() const& {
        return static_cast<move_iterator<_Unwrapped_t<const _Iter2&>>>(_Current._Unwrapped());
    }
    template <class _Iter2 = iterator_type, enable_if_t<_Unwrappable_v<_Iter2>, int> = 0>
     constexpr move_iterator<_Unwrapped_t<_Iter2>> _Unwrapped() && {
        return static_cast<move_iterator<_Unwrapped_t<_Iter2>>>(::std:: move(_Current)._Unwrapped());
    }

    static constexpr bool _Unwrap_when_unverified = _Do_unwrap_when_unverified_v<iterator_type>;

    template <class _Src, enable_if_t<_Wrapped_seekable_v<iterator_type, const _Src&>, int> = 0>
    constexpr void _Seek_to(const move_iterator<_Src>& _It) {
        _Current._Seek_to(_It.base());
    }
    template <class _Src, enable_if_t<_Wrapped_seekable_v<iterator_type, _Src>, int> = 0>
    constexpr void _Seek_to(move_iterator<_Src>&& _It) {
        _Current._Seek_to(::std:: move(_It).base());
    }

private:
    iterator_type _Current{};
};

template <class _Iter1, class _Iter2>
 constexpr bool operator==(const move_iterator<_Iter1>& _Left, const move_iterator<_Iter2>& _Right)
         requires requires {
        { _Left.base() == _Right.base() } -> _Implicitly_convertible_to<bool>;
    }
 { return _Left.base() == _Right.base(); }


template <class _Iter1, class _Iter2>
 constexpr bool operator<(const move_iterator<_Iter1>& _Left, const move_iterator<_Iter2>& _Right)
         requires requires {
        { _Left.base() < _Right.base() } -> _Implicitly_convertible_to<bool>;
    }
 { return _Left.base() < _Right.base(); }

template <class _Iter1, class _Iter2>
 constexpr bool operator>(const move_iterator<_Iter1>& _Left, const move_iterator<_Iter2>& _Right)
         requires requires { _Right < _Left; }
 { return _Right < _Left; }

template <class _Iter1, class _Iter2>
 constexpr bool operator<=(const move_iterator<_Iter1>& _Left, const move_iterator<_Iter2>& _Right)
         requires requires { _Right < _Left; }
 { return !(_Right < _Left); }

template <class _Iter1, class _Iter2>
 constexpr bool operator>=(const move_iterator<_Iter1>& _Left, const move_iterator<_Iter2>& _Right)
         requires requires { _Left < _Right; }
 { return !(_Left < _Right); }

template <class _Iter1, three_way_comparable_with<_Iter1> _Iter2>
 constexpr compare_three_way_result_t<_Iter1, _Iter2> operator<=>(
    const move_iterator<_Iter1>& _Left, const move_iterator<_Iter2>& _Right) {
    return _Left.base() <=> _Right.base();
}

template <class _Iter1, class _Iter2>
 constexpr auto operator-(const move_iterator<_Iter1>& _Left, const move_iterator<_Iter2>& _Right)
    -> decltype(_Left.base() - _Right.base()) {
    return _Left.base() - _Right.base();
}

template <class _Iter>
 constexpr move_iterator<_Iter> operator+(
    typename move_iterator<_Iter>::difference_type _Off, const move_iterator<_Iter>& _Right)
         requires requires {
        { _Right.base() + _Off } -> same_as<_Iter>;      }
 { return move_iterator<_Iter>{_Right.base() + _Off}; }

 template <class _Iter>
 constexpr move_iterator<_Iter> make_move_iterator(_Iter _It) {      return move_iterator<_Iter>(::std:: move(_It));
}

 struct default_sentinel_t {};

 inline constexpr default_sentinel_t default_sentinel{};

 struct unreachable_sentinel_t;
namespace _Unreachable_sentinel_detail {
    struct _Base {
        template <weakly_incrementable _Winc>
         friend constexpr bool operator==(const unreachable_sentinel_t&, const _Winc&) noexcept {
            return false;
        }
    };
}  struct unreachable_sentinel_t : _Unreachable_sentinel_detail::_Base {};  
 inline constexpr unreachable_sentinel_t unreachable_sentinel{};

 template <class _Source, class _Dest>
struct _Ptr_cat_helper {
    using _USource                        = _Unwrap_enum_t<_Source>;
    using _UDest                          = _Unwrap_enum_t<_Dest>;
    static constexpr bool _Really_trivial = conjunction_v<
        bool_constant<sizeof(_USource) == sizeof(_UDest) && is_same_v<bool, _USource> == is_same_v<bool, _UDest>>,
        is_integral<_USource>, is_integral<_UDest>>;
    static constexpr bool _Trivially_copyable = _Really_trivial;
};

template <class _Elem>
struct _Ptr_cat_helper<_Elem, _Elem> {      static constexpr bool _Really_trivial     = is_trivial_v<_Elem>;
    static constexpr bool _Trivially_copyable = is_trivially_copyable_v<_Elem>;
};

template <class _Anything>
struct _Ptr_cat_helper<_Anything*, const _Anything*> {
         static constexpr bool _Really_trivial     = true;
    static constexpr bool _Trivially_copyable = true;
};

template <class _Anything>
struct _Ptr_cat_helper<_Anything*, volatile _Anything*> {
         static constexpr bool _Really_trivial     = true;
    static constexpr bool _Trivially_copyable = true;
};

template <class _Anything>
struct _Ptr_cat_helper<_Anything*, const volatile _Anything*> {
         static constexpr bool _Really_trivial     = true;
    static constexpr bool _Trivially_copyable = true;
};

struct _False_copy_cat {
    static constexpr bool _Really_trivial     = false;
    static constexpr bool _Trivially_copyable = false;
};

template <class _Source, class _Dest>
struct _Ptr_copy_cat : _False_copy_cat {};  
template <class _Source, class _Dest>
struct _Ptr_copy_cat<_Source*, _Dest*>
    : conditional_t<is_trivially_assignable_v<_Dest&, _Source&>,
          _Ptr_cat_helper<remove_cv_t<_Source>, remove_cv_t<_Dest>>, _False_copy_cat> {};

template <class _Source, class _Dest>
struct _Ptr_copy_cat<move_iterator<_Source*>, _Dest*> : _Ptr_copy_cat<_Source*, _Dest*> {};

template <class _Source, class _Dest>
struct _Ptr_move_cat : _False_copy_cat {};  
template <class _Source, class _Dest>
struct _Ptr_move_cat<_Source*, _Dest*>
    : conditional_t<is_trivially_assignable_v<_Dest&, _Source>,
          _Ptr_cat_helper<remove_cv_t<_Source>, remove_cv_t<_Dest>>, _False_copy_cat> {};

template <class _Source, class _Dest>
struct _Ptr_move_cat<move_iterator<_Source*>, _Dest*> : _Ptr_move_cat<_Source*, _Dest*> {};

template <class _InIt, class _OutIt>
_OutIt _Copy_memmove(_InIt _First, _InIt _Last, _OutIt _Dest) {
    const char* const _First_ch = const_cast<const char*>(reinterpret_cast<const volatile char*>(_First));
    const char* const _Last_ch  = const_cast<const char*>(reinterpret_cast<const volatile char*>(_Last));
    char* const _Dest_ch        = const_cast<char*>(reinterpret_cast<volatile char*>(_Dest));
    const auto _Count           = static_cast<size_t>(_Last_ch - _First_ch);
    :: memmove(_Dest_ch, _First_ch, _Count);
    return reinterpret_cast<_OutIt>(_Dest_ch + _Count);
}

template <class _InIt, class _OutIt>
_OutIt _Copy_memmove(move_iterator<_InIt> _First, move_iterator<_InIt> _Last, _OutIt _Dest) {
    return _Copy_memmove(_First.base(), _Last.base(), _Dest);
}

template <class _InIt, class _OutIt>
_OutIt _Copy_memcpy_common(_InIt _IFirst, _InIt _ILast, _OutIt _OFirst, _OutIt _OLast) noexcept {
    const auto _IFirst_ch = const_cast<const char*>(reinterpret_cast<const volatile char*>(_IFirst));
    const auto _ILast_ch  = const_cast<const char*>(reinterpret_cast<const volatile char*>(_ILast));
    const auto _OFirst_ch = const_cast<char*>(reinterpret_cast<volatile char*>(_OFirst));
    const auto _OLast_ch  = const_cast<const char*>(reinterpret_cast<const volatile char*>(_OLast));
    const auto _Count     = static_cast<size_t>((::std:: min)(_ILast_ch - _IFirst_ch, _OLast_ch - _OFirst_ch));
    :: memcpy(_OFirst_ch, _IFirst_ch, _Count);
    return reinterpret_cast<_OutIt>(_OFirst_ch + _Count);
}

 template <class _It, bool _RequiresMutable = false>
inline constexpr bool _Is_vb_iterator = false;

template <class _InIt, class _OutIt>
constexpr _OutIt _Copy_unchecked(_InIt _First, _InIt _Last, _OutIt _Dest) {
              if constexpr (_Ptr_copy_cat<_InIt, _OutIt>::_Trivially_copyable) {
        if (!::std:: is_constant_evaluated())
        {
            return _Copy_memmove(_First, _Last, _Dest);
        }
    }

    for (; _First != _Last; ++_Dest, (void) ++_First) {
        *_Dest = *_First;
    }

    return _Dest;
}

template <class _InIt, class _OutIt>
constexpr _OutIt copy(_InIt _First, _InIt _Last, _OutIt _Dest) {      _Adl_verify_range(_First, _Last);
    const auto _UFirst = _Get_unwrapped(_First);
    const auto _ULast  = _Get_unwrapped(_Last);
    const auto _UDest  = _Get_unwrapped_n(_Dest, _Idl_distance<_InIt>(_UFirst, _ULast));
    _Seek_wrapped(_Dest, _Copy_unchecked(_UFirst, _ULast, _UDest));
    return _Dest;
}

template <class _ExPo, class _FwdIt1, class _FwdIt2, _Enable_if_execution_policy_t<_ExPo> = 0>
_FwdIt2 copy(_ExPo&&, _FwdIt1 _First, _FwdIt1 _Last, _FwdIt2 _Dest) noexcept   {
              static_assert(_Is_fwd_iter_v<_Iter>, "Parallel algorithms require forward iterators or stronger.");
    static_assert(_Is_fwd_iter_v<_Iter>, "Parallel algorithms require forward iterators or stronger.");
    return ::std:: copy(_First, _Last, _Dest);
}

 template <class _InIt, class _Diff, class _OutIt>
constexpr _OutIt copy_n(_InIt _First, _Diff _Count_raw, _OutIt _Dest) {
         _Algorithm_int_t<_Diff> _Count = _Count_raw;
    if (0 < _Count) {
        auto _UFirst = _Get_unwrapped_n(_First, _Count);
        auto _UDest  = _Get_unwrapped_n(_Dest, _Count);
        if constexpr (_Ptr_copy_cat<decltype(_UFirst), decltype(_UDest)>::_Trivially_copyable) {
            if (!::std:: is_constant_evaluated())
            {
                _UDest = _Copy_memmove(_UFirst, _UFirst + _Count, _UDest);
                _Seek_wrapped(_Dest, _UDest);
                return _Dest;
            }
        }

        for (;;) {
            *_UDest = *_UFirst;
            ++_UDest;
            --_Count;
            if (_Count == 0) {                                                  break;
            }

            ++_UFirst;
        }

        _Seek_wrapped(_Dest, _UDest);
    }

    return _Dest;
}


template <class _ExPo, class _FwdIt1, class _Diff, class _FwdIt2, _Enable_if_execution_policy_t<_ExPo> = 0>
_FwdIt2 copy_n(_ExPo&&, _FwdIt1 _First, _Diff _Count_raw, _FwdIt2 _Dest) noexcept   {
              static_assert(_Is_fwd_iter_v<_Iter>, "Parallel algorithms require forward iterators or stronger.");
    static_assert(_Is_fwd_iter_v<_Iter>, "Parallel algorithms require forward iterators or stronger.");
    return ::std:: copy_n(_First, _Count_raw, _Dest);
}

 template <class _BidIt1, class _BidIt2>
_BidIt2 _Copy_backward_memmove(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest) {
         const char* const _First_ch = const_cast<const char*>(reinterpret_cast<const volatile char*>(_First));
    const char* const _Last_ch  = const_cast<const char*>(reinterpret_cast<const volatile char*>(_Last));
    char* const _Dest_ch        = const_cast<char*>(reinterpret_cast<volatile char*>(_Dest));
    const auto _Count           = static_cast<size_t>(_Last_ch - _First_ch);
    return static_cast<_BidIt2>(:: memmove(_Dest_ch - _Count, _First_ch, _Count));
}

template <class _BidIt1, class _BidIt2>
_BidIt2 _Copy_backward_memmove(move_iterator<_BidIt1> _First, move_iterator<_BidIt1> _Last, _BidIt2 _Dest) {
    return _Copy_backward_memmove(_First.base(), _Last.base(), _Dest);
}

template <class _BidIt1, class _BidIt2>
 constexpr _BidIt2 _Copy_backward_unchecked(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest) {
         if constexpr (_Ptr_copy_cat<_BidIt1, _BidIt2>::_Trivially_copyable) {
        if (!::std:: is_constant_evaluated())
        {
            return _Copy_backward_memmove(_First, _Last, _Dest);
        }
    }

    while (_First != _Last) {
        *--_Dest = *--_Last;
    }

    return _Dest;
}

template <class _BidIt1, class _BidIt2>
constexpr _BidIt2 copy_backward(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest) {
         _Adl_verify_range(_First, _Last);
    const auto _UFirst = _Get_unwrapped(_First);
    const auto _ULast  = _Get_unwrapped(_Last);
    const auto _UDest  = _Get_unwrapped_n(_Dest, -_Idl_distance<_BidIt1>(_UFirst, _ULast));
    _Seek_wrapped(_Dest, _Copy_backward_unchecked(_UFirst, _ULast, _UDest));
    return _Dest;
}

template <class _ExPo, class _BidIt1, class _BidIt2, _Enable_if_execution_policy_t<_ExPo> = 0>
_BidIt2 copy_backward(_ExPo&&, _BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest) noexcept   {
              return ::std:: copy_backward(_First, _Last, _Dest);
}

 template <class _InIt, class _OutIt>
constexpr _OutIt _Move_unchecked(_InIt _First, _InIt _Last, _OutIt _Dest) {
              if constexpr (_Ptr_move_cat<_InIt, _OutIt>::_Trivially_copyable) {
        if (!::std:: is_constant_evaluated())
        {
            return _Copy_memmove(_First, _Last, _Dest);
        }
    }

    for (; _First != _Last; ++_Dest, (void) ++_First) {
        *_Dest = ::std:: move(*_First);
    }

    return _Dest;
}

template <class _InIt, class _OutIt>
constexpr _OutIt move(_InIt _First, _InIt _Last, _OutIt _Dest) {
         _Adl_verify_range(_First, _Last);
    const auto _UFirst = _Get_unwrapped(_First);
    const auto _ULast  = _Get_unwrapped(_Last);
    const auto _UDest  = _Get_unwrapped_n(_Dest, _Idl_distance<_InIt>(_UFirst, _ULast));
    _Seek_wrapped(_Dest, _Move_unchecked(_UFirst, _ULast, _UDest));
    return _Dest;
}

template <class _ExPo, class _FwdIt1, class _FwdIt2, _Enable_if_execution_policy_t<_ExPo> = 0>
_FwdIt2 move(_ExPo&&, _FwdIt1 _First, _FwdIt1 _Last, _FwdIt2 _Dest) noexcept   {
              static_assert(_Is_fwd_iter_v<_Iter>, "Parallel algorithms require forward iterators or stronger.");
    static_assert(_Is_fwd_iter_v<_Iter>, "Parallel algorithms require forward iterators or stronger.");
    return ::std:: move(_First, _Last, _Dest);
}

 template <class _BidIt1, class _BidIt2>
constexpr _BidIt2 _Move_backward_unchecked(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest) {
              if constexpr (_Ptr_move_cat<_BidIt1, _BidIt2>::_Trivially_copyable) {
        if (!::std:: is_constant_evaluated())
        {
            return _Copy_backward_memmove(_First, _Last, _Dest);
        }
    }

    while (_First != _Last) {
        *--_Dest = ::std:: move(*--_Last);
    }

    return _Dest;
}

template <class _BidIt1, class _BidIt2>
constexpr _BidIt2 move_backward(_BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest) {
         _Adl_verify_range(_First, _Last);
    const auto _UFirst = _Get_unwrapped(_First);
    const auto _ULast  = _Get_unwrapped(_Last);
    const auto _UDest  = _Get_unwrapped_n(_Dest, -_Idl_distance<_BidIt1>(_UFirst, _ULast));
    _Seek_wrapped(_Dest, _Move_backward_unchecked(_UFirst, _ULast, _UDest));
    return _Dest;
}

template <class _ExPo, class _BidIt1, class _BidIt2, _Enable_if_execution_policy_t<_ExPo> = 0>
_BidIt2 move_backward(_ExPo&&, _BidIt1 _First, _BidIt1 _Last, _BidIt2 _Dest) noexcept   {
              return ::std:: move_backward(_First, _Last, _Dest);
}

 template <class _Ty>
struct _Is_character : false_type {};  
template <>
struct _Is_character<char> : true_type {};  
template <>
struct _Is_character<signed char> : true_type {};  
template <>
struct _Is_character<unsigned char> : true_type {};  
template <>
struct _Is_character<char8_t> : true_type {};  
template <class _Ty>
struct _Is_character_or_byte_or_bool : _Is_character<_Ty>::type {};

template <>
struct _Is_character_or_byte_or_bool<byte> : true_type {};

template <>
struct _Is_character_or_byte_or_bool<bool> : true_type {};

 template <class _FwdIt, class _Ty, bool = is_pointer_v<_FwdIt>>
inline constexpr bool _Fill_memset_is_safe = conjunction_v<is_scalar<_Ty>,
    _Is_character_or_byte_or_bool<_Unwrap_enum_t<remove_reference_t<_Iter_ref_t<_FwdIt>>>>,
    is_assignable<_Iter_ref_t<_FwdIt>, const _Ty&>>;

template <class _FwdIt, class _Ty>
inline constexpr bool _Fill_memset_is_safe<_FwdIt, _Ty, false> = false;

template <class _FwdIt, class _Ty, bool = is_pointer_v<_FwdIt>>
inline constexpr bool _Fill_zero_memset_is_safe =
    conjunction_v<is_scalar<_Ty>, is_scalar<_Iter_value_t<_FwdIt>>, negation<is_member_pointer<_Iter_value_t<_FwdIt>>>,
        negation<is_volatile<remove_reference_t<_Iter_ref_t<_FwdIt>>>>, is_assignable<_Iter_ref_t<_FwdIt>, const _Ty&>>;

template <class _FwdIt, class _Ty>
inline constexpr bool _Fill_zero_memset_is_safe<_FwdIt, _Ty, false> = false;

template <class _DestTy, class _Ty>
void _Fill_memset(_DestTy* const _Dest, const _Ty _Val, const size_t _Count) {
    _DestTy _Dest_val = _Val;      :: memset(_Dest, static_cast<unsigned char>(_Dest_val), _Count);
}

template <class _DestTy>
void _Fill_zero_memset(_DestTy* const _Dest, const size_t _Count) {
    :: memset(_Dest, 0, _Count * sizeof(_DestTy));
}

template <class _Ty>
 bool _Is_all_bits_zero(const _Ty& _Val) {
         ;
    constexpr _Ty _Zero{};
    return :: memcmp(&_Val, &_Zero, sizeof(_Ty)) == 0;
}

template <class _FwdIt, class _Ty>
constexpr void fill(const _FwdIt _First, const _FwdIt _Last, const _Ty& _Val) {
         _Adl_verify_range(_First, _Last);
    if constexpr (_Is_vb_iterator<_FwdIt, true>) {
        _Fill_vbool(_First, _Last, _Val);
    } else {
        auto _UFirst      = _Get_unwrapped(_First);
        const auto _ULast = _Get_unwrapped(_Last);
        if (!::std:: is_constant_evaluated())
        {
            if constexpr (_Fill_memset_is_safe<decltype(_UFirst), _Ty>) {
                _Fill_memset(_UFirst, _Val, static_cast<size_t>(_ULast - _UFirst));
                return;
            } else if constexpr (_Fill_zero_memset_is_safe<decltype(_UFirst), _Ty>) {
                if (_Is_all_bits_zero(_Val)) {
                    _Fill_zero_memset(_UFirst, static_cast<size_t>(_ULast - _UFirst));
                    return;
                }
            }
        }

        for (; _UFirst != _ULast; ++_UFirst) {
            *_UFirst = _Val;
        }
    }
}

template <class _ExPo, class _FwdIt, class _Ty, _Enable_if_execution_policy_t<_ExPo> = 0>
void fill(_ExPo&&, _FwdIt _First, _FwdIt _Last, const _Ty& _Val) noexcept   {
              static_assert(_Is_fwd_iter_v<_Iter>, "Parallel algorithms require forward iterators or stronger.");
    return ::std:: fill(_First, _Last, _Val);
}

 template <class _OutIt, class _Diff, class _Ty>
constexpr _OutIt fill_n(_OutIt _Dest, const _Diff _Count_raw, const _Ty& _Val) {
         _Algorithm_int_t<_Diff> _Count = _Count_raw;
    if (0 < _Count) {
        if constexpr (_Is_vb_iterator<_OutIt, true>) {
            const auto _Last = _Dest + static_cast<typename _OutIt::difference_type>(_Count);
            _Fill_vbool(_Dest, _Last, _Val);
            return _Last;
        } else {
            auto _UDest = _Get_unwrapped_n(_Dest, _Count);
            if (!::std:: is_constant_evaluated())
            {
                if constexpr (_Fill_memset_is_safe<decltype(_UDest), _Ty>) {
                    _Fill_memset(_UDest, _Val, static_cast<size_t>(_Count));
                    _Seek_wrapped(_Dest, _UDest + _Count);
                    return _Dest;
                } else if constexpr (_Fill_zero_memset_is_safe<decltype(_UDest), _Ty>) {
                    if (_Is_all_bits_zero(_Val)) {
                        _Fill_zero_memset(_UDest, static_cast<size_t>(_Count));
                        _Seek_wrapped(_Dest, _UDest + _Count);
                        return _Dest;
                    }
                }
            }

            for (; 0 < _Count; --_Count, (void) ++_UDest) {
                *_UDest = _Val;
            }

            _Seek_wrapped(_Dest, _UDest);
        }
    }
    return _Dest;
}


template <class _ExPo, class _FwdIt, class _Diff, class _Ty, _Enable_if_execution_policy_t<_ExPo> = 0>
_FwdIt fill_n(_ExPo&&, _FwdIt _Dest, _Diff _Count_raw, const _Ty& _Val) noexcept   {
              static_assert(_Is_fwd_iter_v<_Iter>, "Parallel algorithms require forward iterators or stronger.");
    return ::std:: fill_n(_Dest, _Count_raw, _Val);
}

 
  
     template <class _Elem1, class _Elem2,
    bool = sizeof(_Elem1) == sizeof(_Elem2)             && is_integral_v<_Elem1> && !is_volatile_v<_Elem1>             && is_integral_v<_Elem2> && !is_volatile_v<_Elem2>>
inline constexpr bool _Can_memcmp_elements =
    is_same_v<_Elem1, bool> || is_same_v<_Elem2, bool> || static_cast<_Elem1>(-1) == static_cast<_Elem2>(-1);

   template <>
inline constexpr bool _Can_memcmp_elements<byte, byte, false> = true;

   template <class _Ty1, class _Ty2>
inline constexpr bool _Can_memcmp_elements<_Ty1*, _Ty2*, false> = is_same_v<remove_cv_t<_Ty1>, remove_cv_t<_Ty2>>;

template <class _Elem1, class _Elem2>
inline constexpr bool _Can_memcmp_elements<_Elem1, _Elem2, false> = false;

    template <class _Elem1, class _Elem2, class _Pr>
inline constexpr bool _Pred_is_consistent_with_memcmp = false;

  template <class _Elem>
inline constexpr bool _Pred_is_consistent_with_memcmp<_Elem, _Elem, equal_to<_Elem>> = true;

 template <class _Elem1, class _Elem2>
inline constexpr bool _Pred_is_consistent_with_memcmp<_Elem1, _Elem2, equal_to<>> = true;

 template <class _Elem1, class _Elem2>
inline constexpr bool _Pred_is_consistent_with_memcmp<_Elem1, _Elem2, ::std::ranges:: equal_to> = true;

   template <class _Elem1, class _Elem2, class _Pr>
inline constexpr bool _Can_memcmp_elements_with_pred = _Can_memcmp_elements<_Elem1, _Elem2>      && _Pred_is_consistent_with_memcmp<_Elem1, _Elem2, _Pr>;

  
 template <class _Iter1, class _Iter2>
inline constexpr bool _Iterators_are_contiguous = contiguous_iterator<_Iter1>      && contiguous_iterator<_Iter2>;

   template <class _Iter1, class _Iter2, class _Pr>
inline constexpr bool _Equal_memcmp_is_safe_helper = _Iterators_are_contiguous<_Iter1, _Iter2>      && _Can_memcmp_elements_with_pred<remove_const_t<remove_reference_t<_Iter_ref_t<_Iter1>>>,
        remove_const_t<remove_reference_t<_Iter_ref_t<_Iter2>>>, _Pr>;

template <class _Iter1, class _Iter2, class _Pr>
inline constexpr bool _Equal_memcmp_is_safe =
    _Equal_memcmp_is_safe_helper<remove_const_t<_Iter1>, remove_const_t<_Iter2>, _Pr>;

template <class _InIt1, class _InIt2, class _Pr>
 constexpr bool equal(const _InIt1 _First1, const _InIt1 _Last1, const _InIt2 _First2, _Pr _Pred) {
         _Adl_verify_range(_First1, _Last1);
    auto _UFirst1      = _Get_unwrapped(_First1);
    const auto _ULast1 = _Get_unwrapped(_Last1);
    auto _UFirst2      = _Get_unwrapped_n(_First2, _Idl_distance<_InIt1>(_UFirst1, _ULast1));
    if constexpr (_Equal_memcmp_is_safe<decltype(_UFirst1), decltype(_UFirst2), _Pr>) {
        if (!::std:: is_constant_evaluated())
        {
            const auto _First1_ch = reinterpret_cast<const char*>(_UFirst1);
            const auto _First2_ch = reinterpret_cast<const char*>(_UFirst2);
            const auto _Count     = static_cast<size_t>(reinterpret_cast<const char*>(_ULast1) - _First1_ch);
            return :: memcmp(_First1_ch, _First2_ch, _Count) == 0;
        }
    }

    for (; _UFirst1 != _ULast1; ++_UFirst1, (void) ++_UFirst2) {
        if (!_Pred(*_UFirst1, *_UFirst2)) {
            return false;
        }
    }

    return true;
}

template <class _ExPo, class _FwdIt1, class _FwdIt2, class _Pr, _Enable_if_execution_policy_t<_ExPo> = 0>
 bool equal(_ExPo&& _Exec, const _FwdIt1 _First1, const _FwdIt1 _Last1, const _FwdIt2 _First2,
    _Pr _Pred) noexcept;  
template <class _InIt1, class _InIt2>
 constexpr bool equal(const _InIt1 _First1, const _InIt1 _Last1, const _InIt2 _First2) {
         return ::std:: equal(_First1, _Last1, _First2, equal_to<>{});
}

template <class _ExPo, class _FwdIt1, class _FwdIt2, _Enable_if_execution_policy_t<_ExPo> = 0>
 bool equal(_ExPo&& _Exec, const _FwdIt1 _First1, const _FwdIt1 _Last1, const _FwdIt2 _First2) noexcept
  {
         return ::std:: equal(::std:: forward<_ExPo>(_Exec), _First1, _Last1, _First2, equal_to{});
}

template <class _InIt1, class _InIt2, class _Pr>
 constexpr bool equal(
    const _InIt1 _First1, const _InIt1 _Last1, const _InIt2 _First2, const _InIt2 _Last2, _Pr _Pred) {
         _Adl_verify_range(_First1, _Last1);
    _Adl_verify_range(_First2, _Last2);
    auto _UFirst1      = _Get_unwrapped(_First1);
    const auto _ULast1 = _Get_unwrapped(_Last1);
    auto _UFirst2      = _Get_unwrapped(_First2);
    const auto _ULast2 = _Get_unwrapped(_Last2);
    if constexpr (_Is_random_iter_v<_InIt1> && _Is_random_iter_v<_InIt2>) {
        if (_ULast1 - _UFirst1 != _ULast2 - _UFirst2) {
            return false;
        }

        return ::std:: equal(_UFirst1, _ULast1, _UFirst2, _Pass_fn(_Pred));
    } else {
        for (;;) {
            if (_UFirst1 == _ULast1) {
                return _UFirst2 == _ULast2;
            }

            if (_UFirst2 == _ULast2) {
                return false;
            }

            if (!_Pred(*_UFirst1, *_UFirst2)) {
                return false;
            }

            ++_UFirst1;
            ++_UFirst2;
        }
    }
}

template <class _ExPo, class _FwdIt1, class _FwdIt2, class _Pr, _Enable_if_execution_policy_t<_ExPo> = 0>
 bool equal(_ExPo&& _Exec, const _FwdIt1 _First1, const _FwdIt1 _Last1, const _FwdIt2 _First2,
    const _FwdIt2 _Last2, _Pr _Pred) noexcept;  
template <class _InIt1, class _InIt2>
 constexpr bool equal(
    const _InIt1 _First1, const _InIt1 _Last1, const _InIt2 _First2, const _InIt2 _Last2) {
         return ::std:: equal(_First1, _Last1, _First2, _Last2, equal_to<>{});
}

template <class _ExPo, class _FwdIt1, class _FwdIt2, _Enable_if_execution_policy_t<_ExPo> = 0>
 bool equal(_ExPo&& _Exec, const _FwdIt1 _First1, const _FwdIt1 _Last1, const _FwdIt2 _First2,
    const _FwdIt2 _Last2) noexcept   {
         return ::std:: equal(::std:: forward<_ExPo>(_Exec), _First1, _Last1, _First2, _Last2, equal_to{});
}

 template <class _Elem1, class _Elem2, class _FTy>
struct _Lex_compare_check_element_types_helper
    : bool_constant<
          conjunction_v<_Is_character<_Elem1>, _Is_character<_Elem2>, _Is_character<_FTy>, is_unsigned<_FTy>>> {
     };

template <class _Elem1, class _Elem2>
struct _Lex_compare_check_element_types_helper<_Elem1, _Elem2, void>
    : bool_constant<
          conjunction_v<_Is_character<_Elem1>, _Is_character<_Elem2>, is_unsigned<_Elem1>, is_unsigned<_Elem2>>> {
     };

template <>
struct _Lex_compare_check_element_types_helper<byte, byte, byte> : true_type {
     };

template <>
struct _Lex_compare_check_element_types_helper<byte, byte, void> : true_type {
     };

template <class _Memcmp_pr>
struct _Lex_compare_optimize {
    explicit _Lex_compare_optimize() = default;
};  
template <class _Memcmp_pr, class _Obj1, class _Obj2, class _FTy>
using _Lex_compare_check_element_types = _Lex_compare_optimize<conditional_t<
    _Lex_compare_check_element_types_helper<remove_const_t<_Obj1>, remove_const_t<_Obj2>, _FTy>::value, _Memcmp_pr,
    void>>;  
template <class _InIt1, class _InIt2, class _Pr>
constexpr auto _Lex_compare_memcmp_classify(const _InIt1&, const _InIt2&, const _Pr&) {
         return _Lex_compare_optimize<void>{};
}

template <class _Obj1, class _Obj2, class _FTy>
constexpr auto _Lex_compare_memcmp_classify(_Obj1* const&, _Obj2* const&, const less<_FTy>&) {
         return _Lex_compare_check_element_types<less<int>, _Obj1, _Obj2, _FTy>{};
}

template <class _Obj1, class _Obj2, class _FTy>
constexpr auto _Lex_compare_memcmp_classify(_Obj1* const&, _Obj2* const&, const greater<_FTy>&) {
         return _Lex_compare_check_element_types<greater<int>, _Obj1, _Obj2, _FTy>{};
}

template <class _InIt1, class _InIt2, class _Pr>
 constexpr bool _Lex_compare_unchecked(
    _InIt1 _First1, _InIt1 _Last1, _InIt2 _First2, _InIt2 _Last2, _Pr _Pred, _Lex_compare_optimize<void>) {
         for (; _First1 != _Last1 && _First2 != _Last2; ++_First1, (void) ++_First2) {          if (static_cast<bool>(_Pred(*_First1, *_First2))) {
            return true;
        } else if (_Pred(*_First2, *_First1)) {
            return false;
        }
    }

    return _First1 == _Last1 && _First2 != _Last2;
}

template <class _InIt1, class _InIt2, class _Pr, class _Memcmp_pr>
 constexpr bool _Lex_compare_unchecked(
    _InIt1 _First1, _InIt1 _Last1, _InIt2 _First2, _InIt2 _Last2, _Pr _Pred, _Lex_compare_optimize<_Memcmp_pr>) {
         if (::std:: is_constant_evaluated()) {
        return _Lex_compare_unchecked(_First1, _Last1, _First2, _Last2, _Pred, _Lex_compare_optimize<void>{});
    }
    (void) _Pred;
    const auto _Num1 = static_cast<size_t>(_Last1 - _First1);
    const auto _Num2 = static_cast<size_t>(_Last2 - _First2);
    const int _Ans   = :: memcmp(_First1, _First2, _Num1 < _Num2 ? _Num1 : _Num2);
    return _Memcmp_pr{}(_Ans, 0) || (_Ans == 0 && _Num1 < _Num2);
}

template <class _InIt1, class _InIt2, class _Pr>
 constexpr bool lexicographical_compare(
    _InIt1 _First1, _InIt1 _Last1, _InIt2 _First2, _InIt2 _Last2, _Pr _Pred) {
         _Adl_verify_range(_First1, _Last1);
    _Adl_verify_range(_First2, _Last2);
    const auto _UFirst1 = _Get_unwrapped(_First1);
    const auto _ULast1  = _Get_unwrapped(_Last1);
    const auto _UFirst2 = _Get_unwrapped(_First2);
    const auto _ULast2  = _Get_unwrapped(_Last2);
    return _Lex_compare_unchecked(
        _UFirst1, _ULast1, _UFirst2, _ULast2, _Pass_fn(_Pred), _Lex_compare_memcmp_classify(_UFirst1, _UFirst2, _Pred));
}

template <class _InIt1, class _InIt2>
 constexpr bool lexicographical_compare(_InIt1 _First1, _InIt1 _Last1, _InIt2 _First2, _InIt2 _Last2) {
         return ::std:: lexicographical_compare(_First1, _Last1, _First2, _Last2, less<>{});
}

template <class _ExPo, class _FwdIt1, class _FwdIt2, class _Pr, _Enable_if_execution_policy_t<_ExPo> = 0>
 bool lexicographical_compare(
    _ExPo&&, _FwdIt1 _First1, _FwdIt1 _Last1, _FwdIt2 _First2, _FwdIt2 _Last2, _Pr _Pred) noexcept   {
              static_assert(_Is_fwd_iter_v<_Iter>, "Parallel algorithms require forward iterators or stronger.");
    static_assert(_Is_fwd_iter_v<_Iter>, "Parallel algorithms require forward iterators or stronger.");
    return ::std:: lexicographical_compare(_First1, _Last1, _First2, _Last2, _Pass_fn(_Pred));
}

template <class _ExPo, class _FwdIt1, class _FwdIt2, _Enable_if_execution_policy_t<_ExPo> = 0>
 bool lexicographical_compare(
    _ExPo&&, _FwdIt1 _First1, _FwdIt1 _Last1, _FwdIt2 _First2, _FwdIt2 _Last2) noexcept   {
              static_assert(_Is_fwd_iter_v<_Iter>, "Parallel algorithms require forward iterators or stronger.");
    static_assert(_Is_fwd_iter_v<_Iter>, "Parallel algorithms require forward iterators or stronger.");
    return ::std:: lexicographical_compare(_First1, _Last1, _First2, _Last2);
}

 template <class _InIt1, class _InIt2, class _Cmp>
 constexpr auto lexicographical_compare_three_way(
    _InIt1 _First1, _InIt1 _Last1, _InIt2 _First2, _InIt2 _Last2, _Cmp _Comp) -> decltype(_Comp(*_First1, *_First2)) {
    _Adl_verify_range(_First1, _Last1);
    _Adl_verify_range(_First2, _Last2);
    auto _UFirst1      = _Get_unwrapped(_First1);
    const auto _ULast1 = _Get_unwrapped(_Last1);
    auto _UFirst2      = _Get_unwrapped(_First2);
    const auto _ULast2 = _Get_unwrapped(_Last2);
    using _UIt1        = decltype(_UFirst1);
    using _UIt2        = decltype(_UFirst2);
    using _Ty1         = remove_const_t<remove_pointer_t<_UIt1>>;
    using _Ty2         = remove_const_t<remove_pointer_t<_UIt2>>;

    if constexpr (conjunction_v<is_same<_Cmp, compare_three_way>, is_pointer<_UIt1>, is_pointer<_UIt2>,
                      disjunction<
                          conjunction<is_same<_Ty1, byte>, is_same<_Ty2, byte>>,
                          conjunction<_Is_character<_Ty1>, is_unsigned<_Ty1>, _Is_character<_Ty2>,
                              is_unsigned<_Ty2>>>>) {
        if (!::std:: is_constant_evaluated()) {
            const auto _Num1 = static_cast<size_t>(_ULast1 - _UFirst1);
            const auto _Num2 = static_cast<size_t>(_ULast2 - _UFirst2);
            const int _Ans   = :: memcmp(_UFirst1, _UFirst2, (::std:: min)(_Num1, _Num2));
            if (_Ans == 0) {
                return _Num1 <=> _Num2;
            } else {
                return _Ans <=> 0;
            }
        }
    }

    for (;;) {
        if (_UFirst1 == _ULast1) {
            return _UFirst2 == _ULast2 ? strong_ordering::equal : strong_ordering::less;
        }

        if (_UFirst2 == _ULast2) {
            return strong_ordering::greater;
        }

        if (const auto _CmpResult = _Comp(*_UFirst1, *_UFirst2); _CmpResult != 0) {
            return _CmpResult;
        }

        ++_UFirst1;
        ++_UFirst2;
    }
}

template <class _InIt1, class _InIt2>
 constexpr auto lexicographical_compare_three_way(
    _InIt1 _First1, _InIt1 _Last1, _InIt2 _First2, _InIt2 _Last2) {
    return ::std:: lexicographical_compare_three_way(_First1, _Last1, _First2, _Last2, compare_three_way{});
}

 template <class _Ty>
 constexpr bool _Within_limits(const _Ty& _Val, true_type, true_type, _Any_tag) {      return (-128) <= _Val && _Val <= 127;
}

template <class _Ty>
 constexpr bool _Within_limits(const _Ty& _Val, true_type, false_type, true_type) {
         return _Val <= 127 || static_cast<_Ty>((-128)) <= _Val;
}

template <class _Ty>
 constexpr bool _Within_limits(const _Ty& _Val, true_type, false_type, false_type) {
         return _Val <= 127;
}

template <class _Ty>
 constexpr bool _Within_limits(const _Ty& _Val, false_type, true_type, _Any_tag) {
         return 0 <= _Val && _Val <= 0xff;
}

template <class _Ty>
 constexpr bool _Within_limits(const _Ty& _Val, false_type, false_type, _Any_tag) {
         return _Val <= 0xff;
}

template <class _InIt, class _Ty>
 constexpr bool _Within_limits(_InIt, const _Ty& _Val) {      using _Elem = remove_pointer_t<_InIt>;
    return _Within_limits(_Val, bool_constant<is_signed_v<_Elem>>{}, bool_constant<is_signed_v<_Ty>>{},
        bool_constant<-1 == static_cast<_Ty>(-1)>{});
}

template <class _InIt>
 constexpr bool _Within_limits(_InIt, const bool&) {      return true;
}

template <class _InIt, class _Ty>
 constexpr _InIt _Find_unchecked1(_InIt _First, const _InIt _Last, const _Ty& _Val, false_type) {
         for (; _First != _Last; ++_First) {
        if (*_First == _Val) {
            break;
        }
    }

    return _First;
}

template <class _InIt, class _Ty>
 constexpr _InIt _Find_unchecked1(_InIt _First, const _InIt _Last, const _Ty& _Val, true_type) {
         if (!_Within_limits(_First, _Val)) {
        return _Last;
    }

    if (::std:: is_constant_evaluated()) {
        using _Elem = remove_pointer_t<_InIt>;
        return _Find_unchecked1(_First, _Last, static_cast<_Elem>(_Val), false_type{});
    }
    _First =
        static_cast<_InIt>(:: memchr(_First, static_cast<unsigned char>(_Val), static_cast<size_t>(_Last - _First)));
    return _First ? _First : _Last;
}

template <class _InIt, class _Ty>
 constexpr _InIt _Find_unchecked(const _InIt _First, const _InIt _Last, const _Ty& _Val) {
              using _Memchr_opt = bool_constant<
        is_integral_v<_Ty> && _Is_any_of_v<_InIt, char*, signed char*, unsigned char*,              const char*, const signed char*, const unsigned char*>>;

    return _Find_unchecked1(_First, _Last, _Val, _Memchr_opt{});
}

template <class _InIt, class _Ty>
 constexpr _InIt find(_InIt _First, const _InIt _Last, const _Ty& _Val) {      _Adl_verify_range(_First, _Last);
    _Seek_wrapped(_First, _Find_unchecked(_Get_unwrapped(_First), _Get_unwrapped(_Last), _Val));
    return _First;
}

template <class _ExPo, class _FwdIt, class _Ty, _Enable_if_execution_policy_t<_ExPo> = 0>
 _FwdIt find(_ExPo&& _Exec, _FwdIt _First, const _FwdIt _Last, const _Ty& _Val) noexcept;  
 template <class _InIt, class _Ty>
 constexpr _Iter_diff_t<_InIt> count(const _InIt _First, const _InIt _Last, const _Ty& _Val) {
         _Adl_verify_range(_First, _Last);
    auto _UFirst               = _Get_unwrapped(_First);
    const auto _ULast          = _Get_unwrapped(_Last);
    _Iter_diff_t<_InIt> _Count = 0;

    for (; _UFirst != _ULast; ++_UFirst) {
        if (*_UFirst == _Val) {
            ++_Count;
        }
    }

    return _Count;
}

template <class _ExPo, class _FwdIt, class _Ty, _Enable_if_execution_policy_t<_ExPo> = 0>
 _Iter_diff_t<_FwdIt> count(
    _ExPo&& _Exec, const _FwdIt _First, const _FwdIt _Last, const _Ty& _Val) noexcept;  
 template <class _InIt, class _Ty, class _Pr>
 constexpr _InIt _Find_pr(_InIt _First, const _InIt _Last, const _Ty& _Val, _Pr _Pred) {
    for (; _First != _Last; ++_First) {
        if (_Pred(*_First, _Val)) {
            break;
        }
    }

    return _First;
}

template <class _InIt, class _Ty, class _Pr>
 constexpr _Iter_diff_t<_InIt> _Count_pr(_InIt _First, const _InIt _Last, const _Ty& _Val, _Pr _Pred) {
    _Iter_diff_t<_InIt> _Count = 0;

    for (; _First != _Last; ++_First) {
        if (_Pred(*_First, _Val)) {
            ++_Count;
        }
    }

    return _Count;
}


template <class _FwdIt1, class _FwdIt2, class _Pr>
 constexpr bool _Check_match_counts(
    const _FwdIt1 _First1, _FwdIt1 _Last1, const _FwdIt2 _First2, _FwdIt2 _Last2, _Pr _Pred) {
         ;
    ;
    if constexpr (_Is_bidi_iter_v<_FwdIt1> && _Is_bidi_iter_v<_FwdIt2>) {
        do {              --_Last1;
            --_Last2;
        } while (_Pred(*_Last1, *_Last2));
        ++_Last1;
        ++_Last2;
    }
    for (_FwdIt1 _Next1 = _First1; _Next1 != _Last1; ++_Next1) {
        if (_Next1 == _Find_pr(_First1, _Next1, *_Next1, _Pred)) {              _Iter_diff_t<_FwdIt2> _Count2 = _Count_pr(_First2, _Last2, *_Next1, _Pred);
            if (_Count2 == 0) {
                return false;              }

            _FwdIt1 _Skip1                = _Next_iter(_Next1);
            _Iter_diff_t<_FwdIt1> _Count1 = _Count_pr(_Skip1, _Last1, *_Next1, _Pred) + 1;
            if (_Count2 != _Count1) {
                return false;              }
        }
    }

    return true;
}

 template <class _BidIt>
constexpr void reverse(const _BidIt _First, const _BidIt _Last) {      _Adl_verify_range(_First, _Last);
    auto _UFirst = _Get_unwrapped(_First);
    auto _ULast  = _Get_unwrapped(_Last);
    using _Elem = remove_pointer_t<decltype(_UFirst)>;
    constexpr bool _Allow_vectorization =
        conjunction_v<is_pointer<decltype(_UFirst)>, _Is_trivially_swappable<_Elem>, negation<is_volatile<_Elem>>>;
    constexpr size_t _Nx = sizeof(_Elem);

    if constexpr (_Allow_vectorization && _Nx <= 8 && (_Nx & (_Nx - 1)) == 0) {
        if (!::std:: is_constant_evaluated())
        {
            if constexpr (_Nx == 1) {
                __std_reverse_trivially_swappable_1(_UFirst, _ULast);
            } else if constexpr (_Nx == 2) {
                __std_reverse_trivially_swappable_2(_UFirst, _ULast);
            } else if constexpr (_Nx == 4) {
                __std_reverse_trivially_swappable_4(_UFirst, _ULast);
            } else {
                __std_reverse_trivially_swappable_8(_UFirst, _ULast);
            }

            return;
        }
    }

    for (; _UFirst != _ULast && _UFirst != --_ULast; ++_UFirst) {
        ::std:: iter_swap(_UFirst, _ULast);
    }
}

template <class _ExPo, class _BidIt, _Enable_if_execution_policy_t<_ExPo> = 0>
void reverse(_ExPo&&, _BidIt _First, _BidIt _Last) noexcept   {
              return ::std:: reverse(_First, _Last);
}

 template <class _BidIt>
constexpr pair<_BidIt, _BidIt> _Reverse_until_sentinel_unchecked(_BidIt _First, _BidIt _Sentinel, _BidIt _Last) {
         while (_First != _Sentinel && _Last != _Sentinel) {
        ::std:: iter_swap(_First, --_Last);
        ++_First;
    }

    return pair<_BidIt, _BidIt>(_First, _Last);
}

template <class _FwdIt>
constexpr _FwdIt rotate(_FwdIt _First, _FwdIt _Mid, _FwdIt _Last) {
                   _Adl_verify_range(_First, _Mid);
    _Adl_verify_range(_Mid, _Last);
    auto _UFirst      = _Get_unwrapped(_First);
    auto _UMid        = _Get_unwrapped(_Mid);
    const auto _ULast = _Get_unwrapped(_Last);
    if (_UFirst == _UMid) {
        return _Last;
    }

    if (_UMid == _ULast) {
        return _First;
    }

    if constexpr (_Is_random_iter_v<_FwdIt>) {
        ::std:: reverse(_UFirst, _UMid);
        ::std:: reverse(_UMid, _ULast);
        ::std:: reverse(_UFirst, _ULast);
        _Seek_wrapped(_First, _UFirst + (_ULast - _UMid));
    } else if constexpr (_Is_bidi_iter_v<_FwdIt>) {
        ::std:: reverse(_UFirst, _UMid);
        ::std:: reverse(_UMid, _ULast);
        auto _Tmp = _Reverse_until_sentinel_unchecked(_UFirst, _UMid, _ULast);
        ::std:: reverse(_Tmp.first, _Tmp.second);
        _Seek_wrapped(_First, _UMid != _Tmp.first ? _Tmp.first : _Tmp.second);
    } else {
        auto _UNext = _UMid;
        do {              ::std:: iter_swap(_UFirst, _UNext);
            ++_UFirst;
            ++_UNext;
            if (_UFirst == _UMid) {
                _UMid = _UNext;
            }
        } while (_UNext != _ULast);
        _Seek_wrapped(_First, _UFirst);
        while (_UMid != _ULast) {              _UNext = _UMid;
            do {
                ::std:: iter_swap(_UFirst, _UNext);
                ++_UFirst;
                ++_UNext;
                if (_UFirst == _UMid) {
                    _UMid = _UNext;
                }
            } while (_UNext != _ULast);
        }
    }

    return _First;
}

template <class _ExPo, class _FwdIt, _Enable_if_execution_policy_t<_ExPo> = 0>
_FwdIt rotate(_ExPo&&, _FwdIt _First, _FwdIt _Mid, _FwdIt _Last) noexcept   {
              return ::std:: rotate(_First, _Mid, _Last);
}

 template <class _InIt, class _Pr>
 constexpr _InIt find_if(_InIt _First, const _InIt _Last, _Pr _Pred) {      _Adl_verify_range(_First, _Last);
    auto _UFirst      = _Get_unwrapped(_First);
    const auto _ULast = _Get_unwrapped(_Last);
    for (; _UFirst != _ULast; ++_UFirst) {
        if (_Pred(*_UFirst)) {
            break;
        }
    }

    _Seek_wrapped(_First, _UFirst);
    return _First;
}

namespace ranges {
              template <input_iterator _It, sentinel_for<_It> _Se, class _Pj, indirect_unary_predicate<projected<_It, _Pj>> _Pr>
     constexpr _It _Find_if_unchecked(_It _First, const _Se _Last, _Pr _Pred, _Pj _Proj) {
        for (; _First != _Last; ++_First) {
            if (::std:: invoke(_Pred, ::std:: invoke(_Proj, *_First))) {
                break;
            }
        }

        return _First;
    }

    class _Find_if_fn : private _Not_quite_object {
    public:
        using _Not_quite_object::_Not_quite_object;

        template <input_iterator _It, sentinel_for<_It> _Se, class _Pj = identity,
            indirect_unary_predicate<projected<_It, _Pj>> _Pr>
         constexpr _It operator()(_It _First, _Se _Last, _Pr _Pred, _Pj _Proj = {}) const {
            _Adl_verify_range(_First, _Last);
            auto _UResult = ::std::ranges:: _Find_if_unchecked(
                _Get_unwrapped(::std:: move(_First)), _Get_unwrapped(::std:: move(_Last)), _Pass_fn(_Pred), _Pass_fn(_Proj));

            _Seek_wrapped(_First, ::std:: move(_UResult));
            return _First;
        }

        template <input_range _Rng, class _Pj = identity,
            indirect_unary_predicate<projected<iterator_t<_Rng>, _Pj>> _Pr>
         constexpr borrowed_iterator_t<_Rng> operator()(_Rng&& _Range, _Pr _Pred, _Pj _Proj = {}) const {
            auto _First   = ::std::ranges:: begin(_Range);
            auto _UResult = ::std::ranges:: _Find_if_unchecked(
                _Get_unwrapped(::std:: move(_First)), _Uend(_Range), _Pass_fn(_Pred), _Pass_fn(_Proj));

            _Seek_wrapped(_First, ::std:: move(_UResult));
            return _First;
        }
    };

    inline constexpr _Find_if_fn find_if{_Not_quite_object::_Construct_tag{}};

         class _Find_if_not_fn : private _Not_quite_object {
    public:
        using _Not_quite_object::_Not_quite_object;

        template <input_iterator _It, sentinel_for<_It> _Se, class _Pj = identity,
            indirect_unary_predicate<projected<_It, _Pj>> _Pr>
         constexpr _It operator()(_It _First, _Se _Last, _Pr _Pred, _Pj _Proj = {}) const {
            _Adl_verify_range(_First, _Last);

            auto _UResult = _Find_if_not_unchecked(
                _Get_unwrapped(::std:: move(_First)), _Get_unwrapped(::std:: move(_Last)), _Pass_fn(_Pred), _Pass_fn(_Proj));

            _Seek_wrapped(_First, ::std:: move(_UResult));
            return _First;
        }

        template <input_range _Rng, class _Pj = identity,
            indirect_unary_predicate<projected<iterator_t<_Rng>, _Pj>> _Pr>
         constexpr borrowed_iterator_t<_Rng> operator()(_Rng&& _Range, _Pr _Pred, _Pj _Proj = {}) const {
            auto _First = ::std::ranges:: begin(_Range);

            auto _UResult = _Find_if_not_unchecked(
                _Get_unwrapped(::std:: move(_First)), _Uend(_Range), _Pass_fn(_Pred), _Pass_fn(_Proj));

            _Seek_wrapped(_First, ::std:: move(_UResult));
            return _First;
        }

    private:
        template <class _It, class _Se, class _Pj, class _Pr>
         static constexpr _It _Find_if_not_unchecked(_It _First, const _Se _Last, _Pr _Pred, _Pj _Proj) {
            ;
            ;
            ;

            for (; _First != _Last; ++_First) {
                if (!::std:: invoke(_Pred, ::std:: invoke(_Proj, *_First))) {
                    break;
                }
            }

            return _First;
        }
    };

    inline constexpr _Find_if_not_fn find_if_not{_Not_quite_object::_Construct_tag{}};
}  
 template <class _FwdIt, class _Ty, class _Pr>
 constexpr _FwdIt lower_bound(_FwdIt _First, const _FwdIt _Last, const _Ty& _Val, _Pr _Pred) {
         _Adl_verify_range(_First, _Last);
    auto _UFirst                = _Get_unwrapped(_First);
    _Iter_diff_t<_FwdIt> _Count = ::std:: distance(_UFirst, _Get_unwrapped(_Last));

    while (0 < _Count) {          const _Iter_diff_t<_FwdIt> _Count2 = _Count / 2;
        const auto _UMid                   = ::std:: next(_UFirst, _Count2);
        if (_Pred(*_UMid, _Val)) {              _UFirst = _Next_iter(_UMid);
            _Count -= _Count2 + 1;
        } else {
            _Count = _Count2;
        }
    }

    _Seek_wrapped(_First, _UFirst);
    return _First;
}

template <class _FwdIt, class _Ty>
 constexpr _FwdIt lower_bound(_FwdIt _First, _FwdIt _Last, const _Ty& _Val) {
         return ::std:: lower_bound(_First, _Last, _Val, less<>{});
}

 template <class _FwdIt1, class _FwdIt2>
constexpr _FwdIt2 _Swap_ranges_unchecked(_FwdIt1 _First1, const _FwdIt1 _Last1, _FwdIt2 _First2) {
         for (; _First1 != _Last1; ++_First1, (void) ++_First2) {
        ::std:: iter_swap(_First1, _First2);
    }

    return _First2;
}

template <class _Ty, enable_if_t<_Is_trivially_swappable_v<_Ty>, int> = 0>
constexpr _Ty* _Swap_ranges_unchecked(_Ty* _First1, _Ty* const _Last1, _Ty* _First2) {
         if (::std:: is_constant_evaluated()) {
        for (; _First1 != _Last1; ++_First1, (void) ++_First2) {
            ::std:: iter_swap(_First1, _First2);
        }

        return _First2;
    }

    __std_swap_ranges_trivially_swappable_noalias(_First1, _Last1, _First2);
    return _First2 + (_Last1 - _First1);
}

 template <class _Diff, class _Urng>
class _Rng_from_urng {  public:
    using _Ty0 = make_unsigned_t<_Diff>;
    using _Ty1 = typename _Urng::result_type;

    using _Udiff = conditional_t<sizeof(_Ty1) < sizeof(_Ty0), _Ty0, _Ty1>;

    explicit _Rng_from_urng(_Urng& _Func) : _Ref(_Func), _Bits(8 * sizeof(_Udiff)), _Bmask(_Udiff(-1)) {
        for (; (_Urng::max)() - (_Urng::min)() < _Bmask; _Bmask >>= 1) {
            --_Bits;
        }
    }

    _Diff operator()(_Diff _Index) {          for (;;) {              _Udiff _Ret  = 0;              _Udiff _Mask = 0;  
            while (_Mask < _Udiff(_Index - 1)) {                  _Ret <<= _Bits - 1;                  _Ret <<= 1;
                _Ret |= _Get_bits();
                _Mask <<= _Bits - 1;                  _Mask <<= 1;
                _Mask |= _Bmask;
            }

                         if (_Ret / _Index < _Mask / _Index || _Mask % _Index == _Udiff(_Index - 1)) {
                return static_cast<_Diff>(_Ret % _Index);
            }
        }
    }

    _Udiff _Get_all_bits() {
        _Udiff _Ret = 0;

        for (size_t _Num = 0; _Num < 8 * sizeof(_Udiff); _Num += _Bits) {              _Ret <<= _Bits - 1;              _Ret <<= 1;
            _Ret |= _Get_bits();
        }

        return _Ret;
    }

    _Rng_from_urng(const _Rng_from_urng&) = delete;
    _Rng_from_urng& operator=(const _Rng_from_urng&) = delete;

private:
    _Udiff _Get_bits() {          for (;;) {              _Udiff _Val = _Ref() - (_Urng::min)();

            if (_Val <= _Bmask) {
                return _Val;
            }
        }
    }

    _Urng& _Ref;      size_t _Bits;      _Udiff _Bmask;  };

 template <class _Ty, class _Alloc, class = void>
struct _Has_allocator_type : false_type {};  
template <class _Ty, class _Alloc>
struct _Has_allocator_type<_Ty, _Alloc, void_t<typename _Ty::allocator_type>>
    : is_convertible<_Alloc, typename _Ty::allocator_type>::type {};  
 struct allocator_arg_t {      explicit allocator_arg_t() = default;
};

inline constexpr allocator_arg_t allocator_arg{};

[[noreturn]]  void __cdecl _Xbad_alloc();
[[noreturn]]  void __cdecl _Xinvalid_argument(  const char*);
[[noreturn]]  void __cdecl _Xlength_error(  const char*);
[[noreturn]]  void __cdecl _Xout_of_range(  const char*);
[[noreturn]]  void __cdecl _Xoverflow_error(  const char*);
[[noreturn]]  void __cdecl _Xruntime_error(  const char*);

 template <class _Ty, class _Alloc>
struct uses_allocator : _Has_allocator_type<_Ty, _Alloc>::type {
     };

template <class _Ty, class _Alloc>
inline constexpr bool uses_allocator_v = uses_allocator<_Ty, _Alloc>::value;

 template <class _Category, class _Ty, class _Diff = ptrdiff_t, class _Pointer = _Ty*, class _Reference = _Ty&>
struct [[deprecated(                                                                                                             "warning STL4015: The std::iterator class template (used as a base class to provide typedefs) is deprecated in C++17. (The <iterator> header is NOT deprecated.) The C++ Standard has never required user-defined iterators to derive from std::iterator. To fix this warning, stop deriving from std::iterator and start providing publicly accessible typedefs named iterator_category, value_type, difference_type, pointer, and reference. Note that value_type is required to be non-const, even for constant iterators. You can define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] iterator {      using iterator_category = _Category;
    using value_type        = _Ty;
    using difference_type   = _Diff;
    using pointer           = _Pointer;
    using reference         = _Reference;
};

 template <class _Ty, enable_if_t<is_floating_point_v<_Ty>, int> = 0>
 constexpr auto _Float_abs_bits(const _Ty& _Xx) {
    using _Traits    = _Floating_type_traits<_Ty>;
    using _Uint_type = typename _Traits::_Uint_type;
    const auto _Bits = _Bit_cast<_Uint_type>(_Xx);
    return _Bits & ~_Traits::_Shifted_sign_mask;
}

 template <class _Ty, enable_if_t<is_floating_point_v<_Ty>, int> = 0>
 constexpr _Ty _Float_abs(const _Ty _Xx) {      return _Bit_cast<_Ty>(_Float_abs_bits(_Xx));
}

 template <class _Ty, enable_if_t<is_floating_point_v<_Ty>, int> = 0>
 constexpr _Ty _Float_copysign(const _Ty _Magnitude, const _Ty _Sign) {      using _Traits       = _Floating_type_traits<_Ty>;
    using _Uint_type    = typename _Traits::_Uint_type;
    const auto _Signbit = _Bit_cast<_Uint_type>(_Sign) & _Traits::_Shifted_sign_mask;
    return _Bit_cast<_Ty>(_Float_abs_bits(_Magnitude) | _Signbit);
}

 template <class _Ty, enable_if_t<is_floating_point_v<_Ty>, int> = 0>
 constexpr bool _Is_nan(const _Ty _Xx) {      using _Traits = _Floating_type_traits<_Ty>;
    return _Float_abs_bits(_Xx) > _Traits::_Shifted_exponent_mask;
}

     template <class _Ty, enable_if_t<is_floating_point_v<_Ty>, int> = 0>
 constexpr bool _Is_signaling_nan(const _Ty& _Xx) {      using _Traits        = _Floating_type_traits<_Ty>;
    const auto _Abs_bits = _Float_abs_bits(_Xx);
    return _Abs_bits > _Traits::_Shifted_exponent_mask && ((_Abs_bits & _Traits::_Special_nan_mantissa_mask) == 0);
}

 template <class _Ty, enable_if_t<is_floating_point_v<_Ty>, int> = 0>
 constexpr bool _Is_inf(const _Ty _Xx) {      using _Traits = _Floating_type_traits<_Ty>;
    return _Float_abs_bits(_Xx) == _Traits::_Shifted_exponent_mask;
}

 template <class _Ty, enable_if_t<is_floating_point_v<_Ty>, int> = 0>
 constexpr bool _Is_finite(const _Ty _Xx) {      using _Traits = _Floating_type_traits<_Ty>;
    return _Float_abs_bits(_Xx) < _Traits::_Shifted_exponent_mask;
}

 struct _Nontrivial_dummy_type {
    constexpr _Nontrivial_dummy_type() noexcept {
             }
};
;

}




namespace std {
 template <bool _Same, class _Dest, class... _Srcs>
inline constexpr bool _Tuple_conditional_explicit_v0 = false;

template <class... _Dests, class... _Srcs>
inline constexpr bool _Tuple_conditional_explicit_v0<true, tuple<_Dests...>, _Srcs...> =
    !conjunction_v<is_convertible<_Srcs, _Dests>...>;

template <class _Dest, class... _Srcs>
inline constexpr bool _Tuple_conditional_explicit_v =
    _Tuple_conditional_explicit_v0<tuple_size_v<_Dest> == sizeof...(_Srcs), _Dest, _Srcs...>;

 template <bool _Same, class _Dest, class... _Srcs>
inline constexpr bool _Tuple_constructible_v0 = false;

template <class... _Dests, class... _Srcs>
inline constexpr bool _Tuple_constructible_v0<true, tuple<_Dests...>, _Srcs...> =
    conjunction_v<is_constructible<_Dests, _Srcs>...>;

template <class _Dest, class... _Srcs>
inline constexpr bool _Tuple_constructible_v =
    _Tuple_constructible_v0<tuple_size_v<_Dest> == sizeof...(_Srcs), _Dest, _Srcs...>;

template <class _Dest, class... _Srcs>
struct _Tuple_constructible_val : bool_constant<_Tuple_constructible_v<_Dest, _Srcs...>> {};

 template <bool _Same, class _Dest, class... _Srcs>
inline constexpr bool _Tuple_nothrow_constructible_v0 = false;

template <class... _Dests, class... _Srcs>
inline constexpr bool _Tuple_nothrow_constructible_v0<true, tuple<_Dests...>, _Srcs...> =
    conjunction_v<is_nothrow_constructible<_Dests, _Srcs>...>;

template <class _Dest, class... _Srcs>
inline constexpr bool _Tuple_nothrow_constructible_v =
    _Tuple_nothrow_constructible_v0<tuple_size_v<_Dest> == sizeof...(_Srcs), _Dest, _Srcs...>;

 template <bool _Same, class _Dest, class... _Srcs>
inline constexpr bool _Tuple_assignable_v0 = false;

template <class... _Dests, class... _Srcs>
inline constexpr bool _Tuple_assignable_v0<true, tuple<_Dests...>, _Srcs...> =
    conjunction_v<is_assignable<_Dests&, _Srcs>...>;  
template <class _Dest, class... _Srcs>
inline constexpr bool _Tuple_assignable_v =
    _Tuple_assignable_v0<tuple_size_v<_Dest> == sizeof...(_Srcs), _Dest, _Srcs...>;

template <class _Dest, class... _Srcs>
struct _Tuple_assignable_val : bool_constant<_Tuple_assignable_v<_Dest, _Srcs...>> {};

 template <bool _Same, class _Dest, class... _Srcs>
inline constexpr bool _Tuple_nothrow_assignable_v0 = false;

template <class... _Dests, class... _Srcs>
inline constexpr bool _Tuple_nothrow_assignable_v0<true, tuple<_Dests...>, _Srcs...> =
    conjunction_v<is_nothrow_assignable<_Dests&, _Srcs>...>;  
template <class _Dest, class... _Srcs>
inline constexpr bool _Tuple_nothrow_assignable_v =
    _Tuple_nothrow_assignable_v0<tuple_size_v<_Dest> == sizeof...(_Srcs), _Dest, _Srcs...>;

  template <class _Myself, class... _Other>
struct _Tuple_convert_copy_val : true_type {};

template <class _This, class _Uty>
struct _Tuple_convert_copy_val<tuple<_This>, _Uty>
    : bool_constant<!disjunction_v<is_same<_This, _Uty>, is_constructible<_This, const tuple<_Uty>&>,
          is_convertible<const tuple<_Uty>&, _This>>> {};

  template <class _Myself, class... _Other>
struct _Tuple_convert_move_val : true_type {};

template <class _This, class _Uty>
struct _Tuple_convert_move_val<tuple<_This>, _Uty>
    : bool_constant<!disjunction_v<is_same<_This, _Uty>, is_constructible<_This, tuple<_Uty>>,
          is_convertible<tuple<_Uty>, _This>>> {};

  template <class _Myself, class _This2, class... _Rest2>
struct _Tuple_perfect_val : true_type {};

template <class _Myself, class _This2>
struct _Tuple_perfect_val<_Myself, _This2>
    : bool_constant<!is_same_v<_Myself, remove_const_t<remove_reference_t<_This2>>>> {};

 struct _Ignore {      template <class _Ty>
    constexpr const _Ignore& operator=(const _Ty&) const noexcept   {
                 return *this;
    }
};

inline constexpr _Ignore ignore{};

    
 template <class _Ty>
struct _Tuple_val {      constexpr _Tuple_val() : _Val() {}

    template <class _Other>
    constexpr _Tuple_val(_Other&& _Arg) : _Val(::std:: forward<_Other>(_Arg)) {}

    template <class _Alloc, class... _Other, enable_if_t<!uses_allocator_v<_Ty, _Alloc>, int> = 0>
    constexpr _Tuple_val(const _Alloc&, allocator_arg_t, _Other&&... _Arg) : _Val(::std:: forward<_Other>(_Arg)...) {}

    template <class _Alloc, class... _Other,
        enable_if_t<conjunction_v<::std:: uses_allocator<_Ty, _Alloc>,
                        ::std:: is_constructible<_Ty, ::std:: allocator_arg_t, const _Alloc&, _Other...>>,
            int> = 0>
    constexpr _Tuple_val(const _Alloc& _Al, allocator_arg_t, _Other&&... _Arg)
        : _Val(allocator_arg, _Al, ::std:: forward<_Other>(_Arg)...) {}

    template <class _Alloc, class... _Other,
        enable_if_t<conjunction_v<::std:: uses_allocator<_Ty, _Alloc>,
                        ::std:: negation<::std:: is_constructible<_Ty, ::std:: allocator_arg_t, const _Alloc&, _Other...>>>,
            int> = 0>
    constexpr _Tuple_val(const _Alloc& _Al, allocator_arg_t, _Other&&... _Arg)
        : _Val(::std:: forward<_Other>(_Arg)..., _Al) {}

    _Ty _Val;
};

 struct _Exact_args_t {
    explicit _Exact_args_t() = default;
};  
struct _Unpack_tuple_t {
    explicit _Unpack_tuple_t() = default;
};  
struct _Alloc_exact_args_t {
    explicit _Alloc_exact_args_t() = default;
};  
struct _Alloc_unpack_tuple_t {
    explicit _Alloc_unpack_tuple_t() = default;
};  
template <class... _Types>
class tuple;

template <>
class tuple<> {  public:
    constexpr tuple() noexcept = default;  

    constexpr tuple(const tuple&) noexcept   {}  
    template <class _Alloc>
    constexpr tuple(allocator_arg_t, const _Alloc&) noexcept   {}

    template <class _Alloc>
    constexpr tuple(allocator_arg_t, const _Alloc&, const tuple&) noexcept   {}

    template <class _Tag, enable_if_t<is_same_v<_Tag, ::std:: _Exact_args_t>, int> = 0>
    constexpr tuple(_Tag) noexcept   {}

    template <class _Tag, class _Alloc, enable_if_t<is_same_v<_Tag, ::std:: _Alloc_exact_args_t>, int> = 0>
    constexpr tuple(_Tag, const _Alloc&) noexcept   {}

    constexpr tuple& operator=(const tuple&) = default;

    constexpr void swap(tuple&) noexcept {}

    constexpr bool _Equals(const tuple&) const noexcept {
        return true;
    }

    constexpr bool _Less(const tuple&) const noexcept {
        return false;
    }
};

template <class _This, class... _Rest>
class tuple<_This, _Rest...> : private tuple<_Rest...> {  public:
    using _This_type = _This;
    using _Mybase    = tuple<_Rest...>;

    template <class _Tag, class _This2, class... _Rest2, enable_if_t<is_same_v<_Tag, ::std:: _Exact_args_t>, int> = 0>
    constexpr tuple(_Tag, _This2&& _This_arg, _Rest2&&... _Rest_arg)
        : _Mybase(_Exact_args_t{}, ::std:: forward<_Rest2>(_Rest_arg)...), _Myfirst(::std:: forward<_This2>(_This_arg)) {}

    template <class _Tag, class _Tpl, size_t... _Indices, enable_if_t<is_same_v<_Tag, ::std:: _Unpack_tuple_t>, int> = 0>
    constexpr tuple(_Tag, _Tpl&& _Right, index_sequence<_Indices...>);

    template <class _Tag, class _Tpl, enable_if_t<is_same_v<_Tag, ::std:: _Unpack_tuple_t>, int> = 0>
    constexpr tuple(_Tag, _Tpl&& _Right)
        : tuple(_Unpack_tuple_t{}, ::std:: forward<_Tpl>(_Right),
            make_index_sequence<tuple_size_v<remove_reference_t<_Tpl>>>{}) {}

    template <class _Tag, class _Alloc, class _This2, class... _Rest2,
        enable_if_t<is_same_v<_Tag, ::std:: _Alloc_exact_args_t>, int> = 0>
    constexpr tuple(_Tag, const _Alloc& _Al, _This2&& _This_arg, _Rest2&&... _Rest_arg)
        : _Mybase(_Alloc_exact_args_t{}, _Al, ::std:: forward<_Rest2>(_Rest_arg)...),
          _Myfirst(_Al, allocator_arg, ::std:: forward<_This2>(_This_arg)) {}

    template <class _Tag, class _Alloc, class _Tpl, size_t... _Indices,
        enable_if_t<is_same_v<_Tag, ::std:: _Alloc_unpack_tuple_t>, int> = 0>
    constexpr tuple(_Tag, const _Alloc& _Al, _Tpl&& _Right, index_sequence<_Indices...>);

    template <class _Tag, class _Alloc, class _Tpl, enable_if_t<is_same_v<_Tag, ::std:: _Alloc_unpack_tuple_t>, int> = 0>
    constexpr tuple(_Tag, const _Alloc& _Al, _Tpl&& _Right)
        : tuple(_Alloc_unpack_tuple_t{}, _Al, ::std:: forward<_Tpl>(_Right),
            make_index_sequence<tuple_size_v<remove_reference_t<_Tpl>>>{}) {}

    template <class _This2 = _This,
        enable_if_t<conjunction_v<::std:: is_default_constructible<_This2>, ::std:: is_default_constructible<_Rest>...>,
            int>           = 0>
    constexpr explicit(
        !conjunction_v<_Is_implicitly_default_constructible<_This2>, _Is_implicitly_default_constructible<_Rest>...>)
        tuple() noexcept(conjunction_v<is_nothrow_default_constructible<_This2>,
            is_nothrow_default_constructible<_Rest>...>)          : _Mybase(), _Myfirst() {}

    template <class _This2 = _This, enable_if_t<_Tuple_constructible_v<tuple, const _This2&, const _Rest&...>, int> = 0>
    constexpr explicit(_Tuple_conditional_explicit_v<tuple, const _This2&, const _Rest&...>) tuple(
        const _This& _This_arg, const _Rest&... _Rest_arg) noexcept(conjunction_v<is_nothrow_copy_constructible<_This2>,
        is_nothrow_copy_constructible<_Rest>...>)          : tuple(_Exact_args_t{}, _This_arg, _Rest_arg...) {}

    template <class _This2, class... _Rest2,
        enable_if_t<conjunction_v<::std:: _Tuple_perfect_val<tuple, _This2, _Rest2...>,
                        ::std:: _Tuple_constructible_val<tuple, _This2, _Rest2...>>,
            int> = 0>
    constexpr explicit(_Tuple_conditional_explicit_v<tuple, _This2, _Rest2...>) tuple(_This2&& _This_arg,
        _Rest2&&... _Rest_arg) noexcept(_Tuple_nothrow_constructible_v<tuple, _This2, _Rest2...>)          : tuple(_Exact_args_t{}, ::std:: forward<_This2>(_This_arg), ::std:: forward<_Rest2>(_Rest_arg)...) {}

    tuple(const tuple&) = default;
    tuple(tuple&&)      = default;

    template <class... _Other, enable_if_t<conjunction_v<::std:: _Tuple_constructible_val<tuple, const _Other&...>,
                                               ::std:: _Tuple_convert_copy_val<tuple, _Other...>>,
                                   int> = 0>
    constexpr explicit(_Tuple_conditional_explicit_v<tuple, const _Other&...>)
        tuple(const tuple<_Other...>& _Right) noexcept(
            _Tuple_nothrow_constructible_v<tuple, const _Other&...>)          : tuple(_Unpack_tuple_t{}, _Right) {}

    template <class... _Other, enable_if_t<conjunction_v<::std:: _Tuple_constructible_val<tuple, _Other...>,
                                               ::std:: _Tuple_convert_move_val<tuple, _Other...>>,
                                   int> = 0>
    constexpr explicit(_Tuple_conditional_explicit_v<tuple, _Other...>)
        tuple(tuple<_Other...>&& _Right) noexcept(_Tuple_nothrow_constructible_v<tuple, _Other...>)          : tuple(_Unpack_tuple_t{}, ::std:: move(_Right)) {}

    template <class _First, class _Second,
        enable_if_t<_Tuple_constructible_v<tuple, const _First&, const _Second&>, int> = 0>
    constexpr explicit(_Tuple_conditional_explicit_v<tuple, const _First&, const _Second&>)
        tuple(const pair<_First, _Second>& _Right) noexcept(
            _Tuple_nothrow_constructible_v<tuple, const _First&, const _Second&>)          : tuple(_Unpack_tuple_t{}, _Right) {}

    template <class _First, class _Second, enable_if_t<_Tuple_constructible_v<tuple, _First, _Second>, int> = 0>
    constexpr explicit(_Tuple_conditional_explicit_v<tuple, _First, _Second>) tuple(
        pair<_First, _Second>&& _Right) noexcept(_Tuple_nothrow_constructible_v<tuple, _First, _Second>)          : tuple(_Unpack_tuple_t{}, ::std:: move(_Right)) {}

    template <class _Alloc, class _This2 = _This,
        enable_if_t<conjunction_v<::std:: is_default_constructible<_This2>, ::std:: is_default_constructible<_Rest>...>,
            int> = 0>
    constexpr explicit(
        !conjunction_v<_Is_implicitly_default_constructible<_This2>, _Is_implicitly_default_constructible<_Rest>...>)
        tuple(allocator_arg_t, const _Alloc& _Al)
        : _Mybase(allocator_arg, _Al), _Myfirst(_Al, allocator_arg) {}

    template <class _Alloc, class _This2 = _This,
        enable_if_t<_Tuple_constructible_v<tuple, const _This2&, const _Rest&...>, int> = 0>
    constexpr explicit(_Tuple_conditional_explicit_v<tuple, const _This2&, const _Rest&...>)
        tuple(allocator_arg_t, const _Alloc& _Al, const _This& _This_arg, const _Rest&... _Rest_arg)
        : tuple(_Alloc_exact_args_t{}, _Al, _This_arg, _Rest_arg...) {}

    template <class _Alloc, class _This2, class... _Rest2,
        enable_if_t<conjunction_v<::std:: _Tuple_perfect_val<tuple, _This2, _Rest2...>,
                        ::std:: _Tuple_constructible_val<tuple, _This2, _Rest2...>>,
            int> = 0>
    constexpr explicit(_Tuple_conditional_explicit_v<tuple, _This2, _Rest2...>)
        tuple(allocator_arg_t, const _Alloc& _Al, _This2&& _This_arg, _Rest2&&... _Rest_arg)
        : tuple(_Alloc_exact_args_t{}, _Al, ::std:: forward<_This2>(_This_arg), ::std:: forward<_Rest2>(_Rest_arg)...) {}

    template <class _Alloc, class _This2 = _This,
        enable_if_t<_Tuple_constructible_v<tuple, const _This2&, const _Rest&...>, int> = 0>
    constexpr tuple(allocator_arg_t, const _Alloc& _Al, const tuple& _Right)
        : tuple(_Alloc_unpack_tuple_t{}, _Al, _Right) {}

    template <class _Alloc, class _This2 = _This, enable_if_t<_Tuple_constructible_v<tuple, _This2, _Rest...>, int> = 0>
    constexpr tuple(allocator_arg_t, const _Alloc& _Al, tuple&& _Right)
        : tuple(_Alloc_unpack_tuple_t{}, _Al, ::std:: move(_Right)) {}

    template <class _Alloc, class... _Other,
        enable_if_t<conjunction_v<::std:: _Tuple_constructible_val<tuple, const _Other&...>,
                        ::std:: _Tuple_convert_copy_val<tuple, _Other...>>,
            int> = 0>
    constexpr explicit(_Tuple_conditional_explicit_v<tuple, const _Other&...>)
        tuple(allocator_arg_t, const _Alloc& _Al, const tuple<_Other...>& _Right)
        : tuple(_Alloc_unpack_tuple_t{}, _Al, _Right) {}

    template <class _Alloc, class... _Other,
        enable_if_t<conjunction_v<::std:: _Tuple_constructible_val<tuple, _Other...>,
                        ::std:: _Tuple_convert_move_val<tuple, _Other...>>,
            int> = 0>
    constexpr explicit(_Tuple_conditional_explicit_v<tuple, _Other...>)
        tuple(allocator_arg_t, const _Alloc& _Al, tuple<_Other...>&& _Right)
        : tuple(_Alloc_unpack_tuple_t{}, _Al, ::std:: move(_Right)) {}

    template <class _Alloc, class _First, class _Second,
        enable_if_t<_Tuple_constructible_v<tuple, const _First&, const _Second&>, int> = 0>
    constexpr explicit(_Tuple_conditional_explicit_v<tuple, const _First&, const _Second&>)
        tuple(allocator_arg_t, const _Alloc& _Al, const pair<_First, _Second>& _Right)
        : tuple(_Alloc_unpack_tuple_t{}, _Al, _Right) {}

    template <class _Alloc, class _First, class _Second,
        enable_if_t<_Tuple_constructible_v<tuple, _First, _Second>, int> = 0>
    constexpr explicit(_Tuple_conditional_explicit_v<tuple, _First, _Second>)
        tuple(allocator_arg_t, const _Alloc& _Al, pair<_First, _Second>&& _Right)
        : tuple(_Alloc_unpack_tuple_t{}, _Al, ::std:: move(_Right)) {}

    tuple& operator=(const volatile tuple&) = delete;

    template <class _Myself = tuple, class _This2 = _This,
        enable_if_t<conjunction_v<::std:: _Is_copy_assignable_no_precondition_check<_This2>,
                        ::std:: _Is_copy_assignable_no_precondition_check<_Rest>...>,
            int> = 0>
    constexpr tuple& operator=(_Identity_t<const _Myself&> _Right) noexcept(
        conjunction_v<is_nothrow_copy_assignable<_This2>, is_nothrow_copy_assignable<_Rest>...>)   {
        _Myfirst._Val = _Right._Myfirst._Val;
        _Get_rest()   = _Right._Get_rest();
        return *this;
    }

    template <class _Myself = tuple, class _This2 = _This,
        enable_if_t<conjunction_v<::std:: _Is_move_assignable_no_precondition_check<_This2>,
                        ::std:: _Is_move_assignable_no_precondition_check<_Rest>...>,
            int> = 0>
    constexpr tuple& operator=(_Identity_t<_Myself&&> _Right) noexcept(
        conjunction_v<is_nothrow_move_assignable<_This2>, is_nothrow_move_assignable<_Rest>...>) {
        _Myfirst._Val = ::std:: forward<_This>(_Right._Myfirst._Val);
        _Get_rest()   = ::std:: forward<_Mybase>(_Right._Get_rest());
        return *this;
    }

    template <class... _Other, enable_if_t<conjunction_v<::std:: negation<::std:: is_same<tuple, ::std:: tuple<_Other...>>>,
                                               ::std:: _Tuple_assignable_val<tuple, const _Other&...>>,
                                   int> = 0>
    constexpr tuple& operator=(const tuple<_Other...>& _Right) noexcept(
        _Tuple_nothrow_assignable_v<tuple, const _Other&...>)   {
        _Myfirst._Val = _Right._Myfirst._Val;
        _Get_rest()   = _Right._Get_rest();
        return *this;
    }

    template <class... _Other, enable_if_t<conjunction_v<::std:: negation<::std:: is_same<tuple, ::std:: tuple<_Other...>>>,
                                               ::std:: _Tuple_assignable_val<tuple, _Other...>>,
                                   int> = 0>
    constexpr tuple& operator=(tuple<_Other...>&& _Right) noexcept(
        _Tuple_nothrow_assignable_v<tuple, _Other...>)   {
        _Myfirst._Val = ::std:: forward<typename tuple<_Other...>::_This_type>(_Right._Myfirst._Val);
        _Get_rest()   = ::std:: forward<typename tuple<_Other...>::_Mybase>(_Right._Get_rest());
        return *this;
    }

    template <class _First, class _Second,
        enable_if_t<_Tuple_assignable_v<tuple, const _First&, const _Second&>, int> = 0>
    constexpr tuple& operator=(const pair<_First, _Second>& _Right) noexcept(
        _Tuple_nothrow_assignable_v<tuple, const _First&, const _Second&>)   {
        _Myfirst._Val             = _Right.first;
        _Get_rest()._Myfirst._Val = _Right.second;
        return *this;
    }

    template <class _First, class _Second, enable_if_t<_Tuple_assignable_v<tuple, _First, _Second>, int> = 0>
    constexpr tuple& operator=(pair<_First, _Second>&& _Right) noexcept(
        _Tuple_nothrow_assignable_v<tuple, _First, _Second>)   {
        _Myfirst._Val             = ::std:: forward<_First>(_Right.first);
        _Get_rest()._Myfirst._Val = ::std:: forward<_Second>(_Right.second);
        return *this;
    }

    constexpr void swap(tuple& _Right) noexcept(
        conjunction_v<_Is_nothrow_swappable<_This>, _Is_nothrow_swappable<_Rest>...>) {
        _Swap_adl(_Myfirst._Val, _Right._Myfirst._Val);
        _Mybase::swap(_Right._Get_rest());
    }

    constexpr _Mybase& _Get_rest() noexcept {          return *this;
    }

    constexpr const _Mybase& _Get_rest() const noexcept {          return *this;
    }

    template <class... _Other>
    constexpr bool _Equals(const tuple<_Other...>& _Right) const {
        return _Myfirst._Val == _Right._Myfirst._Val && _Mybase::_Equals(_Right._Get_rest());
    }

    template <class... _Other>
    constexpr bool _Less(const tuple<_Other...>& _Right) const {
        return _Myfirst._Val < _Right._Myfirst._Val
               || (!(_Right._Myfirst._Val < _Myfirst._Val) && _Mybase::_Less(_Right._Get_rest()));
    }

    template <size_t _Index, class... _Types>
    friend constexpr tuple_element_t<_Index, tuple<_Types...>>& get(tuple<_Types...>& _Tuple) noexcept;

    template <size_t _Index, class... _Types>
    friend constexpr const tuple_element_t<_Index, tuple<_Types...>>& get(const tuple<_Types...>& _Tuple) noexcept;

    template <size_t _Index, class... _Types>
    friend constexpr tuple_element_t<_Index, tuple<_Types...>>&& get(tuple<_Types...>&& _Tuple) noexcept;

    template <size_t _Index, class... _Types>
    friend constexpr const tuple_element_t<_Index, tuple<_Types...>>&& get(const tuple<_Types...>&& _Tuple) noexcept;

    template <size_t _Index, class... _Types>
    friend constexpr auto&& _Tuple_get(tuple<_Types...>&& _Tuple) noexcept;

    template <class _Ty, class... _Types>
    friend constexpr _Ty& get(tuple<_Types...>& _Tuple) noexcept;

    template <class _Ty, class... _Types>
    friend constexpr const _Ty& get(const tuple<_Types...>& _Tuple) noexcept;

    template <class _Ty, class... _Types>
    friend constexpr _Ty&& get(tuple<_Types...>&& _Tuple) noexcept;

    template <class _Ty, class... _Types>
    friend constexpr const _Ty&& get(const tuple<_Types...>&& _Tuple) noexcept;

    _Tuple_val<_This> _Myfirst;  };

template <class... _Types>
tuple(_Types...) -> tuple<_Types...>;

template <class _Ty1, class _Ty2>
tuple(pair<_Ty1, _Ty2>) -> tuple<_Ty1, _Ty2>;

template <class _Alloc, class... _Types>
tuple(allocator_arg_t, _Alloc, _Types...) -> tuple<_Types...>;

template <class _Alloc, class _Ty1, class _Ty2>
tuple(allocator_arg_t, _Alloc, pair<_Ty1, _Ty2>) -> tuple<_Ty1, _Ty2>;

template <class _Alloc, class... _Types>
tuple(allocator_arg_t, _Alloc, tuple<_Types...>) -> tuple<_Types...>;

 template <class... _Types1, class... _Types2>
 constexpr bool operator==(const tuple<_Types1...>& _Left, const tuple<_Types2...>& _Right) {
    static_assert(sizeof...(_Types1) == sizeof...(_Types2), "cannot compare tuples of different sizes");
    return _Left._Equals(_Right);
}

template <class... _Types1, class... _Types2>
 constexpr bool operator!=(const tuple<_Types1...>& _Left, const tuple<_Types2...>& _Right) {
    return !(_Left == _Right);
}

template <class... _Types1, class... _Types2>
 constexpr bool operator<(const tuple<_Types1...>& _Left, const tuple<_Types2...>& _Right) {
    static_assert(sizeof...(_Types1) == sizeof...(_Types2), "cannot compare tuples of different sizes");
    return _Left._Less(_Right);
}

template <class... _Types1, class... _Types2>
 constexpr bool operator>=(const tuple<_Types1...>& _Left, const tuple<_Types2...>& _Right) {
    return !(_Left < _Right);
}

template <class... _Types1, class... _Types2>
 constexpr bool operator>(const tuple<_Types1...>& _Left, const tuple<_Types2...>& _Right) {
    return _Right < _Left;
}

template <class... _Types1, class... _Types2>
 constexpr bool operator<=(const tuple<_Types1...>& _Left, const tuple<_Types2...>& _Right) {
    return !(_Right < _Left);
}

template <class... _Types, enable_if_t<conjunction_v<::std:: _Is_swappable<_Types>...>, int> = 0>
constexpr void swap(tuple<_Types...>& _Left, tuple<_Types...>& _Right) noexcept(noexcept(_Left.swap(_Right))) {
    return _Left.swap(_Right);
}

 template <class _Ty, class _Tuple>
struct _Tuple_element {};  
template <class _This, class... _Rest>
struct _Tuple_element<_This, tuple<_This, _Rest...>> {      static_assert(!_Is_any_of_v<_This, _Rest...>, "duplicate type T in get<T>(tuple)");
    using _Ttype = tuple<_This, _Rest...>;
};

template <class _Ty, class _This, class... _Rest>
struct _Tuple_element<_Ty, tuple<_This, _Rest...>> {      using _Ttype = typename _Tuple_element<_Ty, tuple<_Rest...>>::_Ttype;
};

 template <size_t _Index, class... _Types>
 constexpr tuple_element_t<_Index, tuple<_Types...>>& get(tuple<_Types...>& _Tuple) noexcept {
    using _Ttype = typename tuple_element<_Index, tuple<_Types...>>::_Ttype;
    return static_cast<_Ttype&>(_Tuple)._Myfirst._Val;
}

template <size_t _Index, class... _Types>
 constexpr const tuple_element_t<_Index, tuple<_Types...>>& get(const tuple<_Types...>& _Tuple) noexcept {
    using _Ttype = typename tuple_element<_Index, tuple<_Types...>>::_Ttype;
    return static_cast<const _Ttype&>(_Tuple)._Myfirst._Val;
}

template <size_t _Index, class... _Types>
 constexpr tuple_element_t<_Index, tuple<_Types...>>&& get(tuple<_Types...>&& _Tuple) noexcept {
    using _Ty    = tuple_element_t<_Index, tuple<_Types...>>;
    using _Ttype = typename tuple_element<_Index, tuple<_Types...>>::_Ttype;
    return static_cast<_Ty&&>(static_cast<_Ttype&>(_Tuple)._Myfirst._Val);
}

template <size_t _Index, class... _Types>
 constexpr const tuple_element_t<_Index, tuple<_Types...>>&& get(const tuple<_Types...>&& _Tuple) noexcept {
    using _Ty    = tuple_element_t<_Index, tuple<_Types...>>;
    using _Ttype = typename tuple_element<_Index, tuple<_Types...>>::_Ttype;
    return static_cast<const _Ty&&>(static_cast<const _Ttype&>(_Tuple)._Myfirst._Val);
}

template <size_t _Index, class... _Types>
 constexpr auto&& _Tuple_get(tuple<_Types...>&& _Tuple) noexcept {
         using _Ty    = tuple_element_t<_Index, tuple<_Types...>>;
    using _Ttype = typename tuple_element<_Index, tuple<_Types...>>::_Ttype;
    return static_cast<_Ty&&>(static_cast<_Ttype&>(_Tuple)._Myfirst._Val);
}

 template <class _Ty, class... _Types>
 constexpr _Ty& get(tuple<_Types...>& _Tuple) noexcept {
    using _Ttype = typename _Tuple_element<_Ty, tuple<_Types...>>::_Ttype;
    return static_cast<_Ttype&>(_Tuple)._Myfirst._Val;
}

template <class _Ty, class... _Types>
 constexpr const _Ty& get(const tuple<_Types...>& _Tuple) noexcept {
    using _Ttype = typename _Tuple_element<_Ty, tuple<_Types...>>::_Ttype;
    return static_cast<const _Ttype&>(_Tuple)._Myfirst._Val;
}

template <class _Ty, class... _Types>
 constexpr _Ty&& get(tuple<_Types...>&& _Tuple) noexcept {
    using _Ttype = typename _Tuple_element<_Ty, tuple<_Types...>>::_Ttype;
    return static_cast<_Ty&&>(static_cast<_Ttype&>(_Tuple)._Myfirst._Val);
}

template <class _Ty, class... _Types>
 constexpr const _Ty&& get(const tuple<_Types...>&& _Tuple) noexcept {
    using _Ttype = typename _Tuple_element<_Ty, tuple<_Types...>>::_Ttype;
    return static_cast<const _Ty&&>(static_cast<const _Ttype&>(_Tuple)._Myfirst._Val);
}

 template <class _This, class... _Rest>
template <class _Tag, class _Tpl, size_t... _Indices, enable_if_t<is_same_v<_Tag, ::std:: _Unpack_tuple_t>, int>>
constexpr tuple<_This, _Rest...>::tuple(_Tag, _Tpl&& _Right, index_sequence<_Indices...>)
    : tuple(_Exact_args_t{}, ::std:: get<_Indices>(::std:: forward<_Tpl>(_Right))...) {}

template <class _This, class... _Rest>
template <class _Tag, class _Alloc, class _Tpl, size_t... _Indices,
    enable_if_t<is_same_v<_Tag, ::std:: _Alloc_unpack_tuple_t>, int>>
constexpr tuple<_This, _Rest...>::tuple(_Tag, const _Alloc& _Al, _Tpl&& _Right, index_sequence<_Indices...>)
    : tuple(_Alloc_exact_args_t{}, _Al, ::std:: get<_Indices>(::std:: forward<_Tpl>(_Right))...) {}

 template <class... _Types>
 constexpr tuple<_Unrefwrap_t<_Types>...> make_tuple(_Types&&... _Args) {      using _Ttype = tuple<_Unrefwrap_t<_Types>...>;
    return _Ttype(::std:: forward<_Types>(_Args)...);
}

 template <class... _Types>
 constexpr tuple<_Types&...> tie(_Types&... _Args) noexcept {      using _Ttype = tuple<_Types&...>;
    return _Ttype(_Args...);
}

 template <class... _Types>
 constexpr tuple<_Types&&...> forward_as_tuple(_Types&&... _Args) noexcept {      return tuple<_Types&&...>(::std:: forward<_Types>(_Args)...);
}

 template <class _Seq_type1, class _Seq_type2>
struct _Cat_sequences;

template <size_t... _Indexes1, size_t... _Indexes2>
struct _Cat_sequences<index_sequence<_Indexes1...>,
    index_sequence<_Indexes2...>> {      using type = index_sequence<_Indexes1..., _Indexes2...>;
};

 template <class _Ty, size_t _Size>
class array;

template <size_t _Idx, class _Ty, size_t _Size>
 constexpr _Ty& get(array<_Ty, _Size>& _Arr) noexcept;

template <size_t _Idx, class _Ty, size_t _Size>
 constexpr const _Ty& get(const array<_Ty, _Size>& _Arr) noexcept;

template <size_t _Idx, class _Ty, size_t _Size>
 constexpr _Ty&& get(array<_Ty, _Size>&& _Arr) noexcept;

template <size_t _Idx, class _Ty, size_t _Size>
 constexpr const _Ty&& get(const array<_Ty, _Size>&& _Arr) noexcept;

 template <class _Ty, class... _For_array>
struct _View_as_tuple {      static_assert(_Always_false<_Ty>, "Unsupported tuple_cat arguments.");
};

template <class... _Types>
struct _View_as_tuple<tuple<_Types...>> {      using type = tuple<_Types...>;
};

template <class _Ty1, class _Ty2>
struct _View_as_tuple<pair<_Ty1, _Ty2>> {      using type = tuple<_Ty1, _Ty2>;
};

template <class _Ty, class... _Types>
struct _View_as_tuple<array<_Ty, 0>, _Types...> {      using type = tuple<_Types...>;
};

template <class _Ty, size_t _Size, class... _Types>
struct _View_as_tuple<array<_Ty, _Size>, _Types...>
    : _View_as_tuple<array<_Ty, _Size - 1>, _Ty, _Types...> {  };

 template <size_t _Nx, class _Ty>
struct _Repeat_for : integral_constant<size_t, _Nx> {};  
 template <class _Ret, class _Kx_arg, class _Ix_arg, size_t _Ix_next, class... _Tuples>
struct _Tuple_cat2 {      static_assert(sizeof...(_Tuples) == 0, "Unsupported tuple_cat arguments.");
    using type        = _Ret;
    using _Kx_arg_seq = _Kx_arg;
    using _Ix_arg_seq = _Ix_arg;
};

template <class... _Types1, class _Kx_arg, size_t... _Ix, size_t _Ix_next, class... _Types2, class... _Rest>
struct _Tuple_cat2<tuple<_Types1...>, _Kx_arg, index_sequence<_Ix...>, _Ix_next, tuple<_Types2...>, _Rest...>
    : _Tuple_cat2<tuple<_Types1..., _Types2...>, typename _Cat_sequences<_Kx_arg, index_sequence_for<_Types2...>>::type,
          index_sequence<_Ix..., _Repeat_for<_Ix_next, _Types2>::value...>, _Ix_next + 1,
          _Rest...> {  };

template <class... _Tuples>
struct _Tuple_cat1 : _Tuple_cat2<tuple<>, index_sequence<>, index_sequence<>, 0,
                         typename _View_as_tuple<decay_t<_Tuples>>::type...> {                                                                                  };

template <class _Ret, size_t... _Kx, size_t... _Ix, class _Ty>
constexpr _Ret _Tuple_cat(index_sequence<_Kx...>, index_sequence<_Ix...>, _Ty&& _Arg) {      return _Ret(::std:: get<_Kx>(::std:: get<_Ix>(::std:: forward<_Ty>(_Arg)))...);
}

template <class... _Tuples>
 constexpr typename _Tuple_cat1<_Tuples...>::type tuple_cat(_Tuples&&... _Tpls) {      using _Cat1 = _Tuple_cat1<_Tuples...>;
    return _Tuple_cat<typename _Cat1::type>(typename _Cat1::_Kx_arg_seq(), typename _Cat1::_Ix_arg_seq(),
        ::std:: forward_as_tuple(::std:: forward<_Tuples>(_Tpls)...));
}

 template <class _Callable, class _Tuple, size_t... _Indices>
constexpr decltype(auto) _Apply_impl(
    _Callable&& _Obj, _Tuple&& _Tpl, index_sequence<_Indices...>) {      return ::std:: invoke(::std:: forward<_Callable>(_Obj), ::std:: get<_Indices>(::std:: forward<_Tuple>(_Tpl))...);
}

template <class _Callable, class _Tuple>
constexpr decltype(auto) apply(_Callable&& _Obj, _Tuple&& _Tpl) {      return _Apply_impl(::std:: forward<_Callable>(_Obj), ::std:: forward<_Tuple>(_Tpl),
        make_index_sequence<tuple_size_v<remove_reference_t<_Tuple>>>{});
}

 template <class _Ty, class _Tuple, size_t... _Indices>
constexpr _Ty _Make_from_tuple_impl(
    _Tuple&& _Tpl, index_sequence<_Indices...>) {      return _Ty(::std:: get<_Indices>(::std:: forward<_Tuple>(_Tpl))...);
}

template <class _Ty, class _Tuple>
 constexpr _Ty make_from_tuple(_Tuple&& _Tpl) {      return _Make_from_tuple_impl<_Ty>(
        ::std:: forward<_Tuple>(_Tpl), make_index_sequence<tuple_size_v<remove_reference_t<_Tuple>>>{});
}

 template <class... _Types, class _Alloc>
struct uses_allocator<tuple<_Types...>, _Alloc> : true_type {};  

}



