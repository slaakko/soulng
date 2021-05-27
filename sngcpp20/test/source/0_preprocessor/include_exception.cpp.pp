 
  
 
  
 
  
   
                                           
                                                 
           
     
                                                                                               
  
    
                                                                                              
                     
  

    
 

 





  

 


 

      
   
    
  
 
  
 
  
   
   
 

   
 
  

 
  
 
  

 


 



 
   
 





 
    

  
 


 



 
               

 

 

    

 








 



  
 

 
    
 
 
  
 
 

 
 
 

 
  
   
 




   
   

   

   
 

 

   
    
  
 

 
 
    
  
 
 
 
 




 

  
 
 
  
 
  
  

   
 
 
  
 
   
 
 
  
  
 

 

  

  



 


  



 
 
 
 
    
 
  
 
 
 


 


  
 
 
 

 
    
 
  
 
 
 


 


  
 
 
 

   

   
   
 
  
 
 
 
  
 
 
 

 
 
  
 
 
  
 
 
 


 


  
 
 
 

  
 
 
 
    



     









    



   

    
      
   




 



























 

 
 


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






namespace std {

 int __cdecl uncaught_exceptions() noexcept;

}


       
               


         extern "C" {



 


 
typedef struct _heapinfo
{
    int* _pentry;
    size_t _size;
    int _useflag;
} _HEAPINFO;




   
void* __cdecl _alloca(  size_t _Size);




     intptr_t __cdecl _get_heap_handle(void);

     
     int __cdecl _heapmin(void);

         int __cdecl _heapwalk(  _HEAPINFO* _EntryInfo);

           int __cdecl _heapchk(void);

     int __cdecl _resetstkoflw(void);



    static_assert((sizeof(unsigned int) <= 16), "sizeof(unsigned  int)  <=  _ALLOCA_S_MARKER_SIZE");


                                    
    __inline void* _MarkAllocaS(   void* _Ptr, unsigned int _Marker)
    {
        if (_Ptr)
        {
            *((unsigned int*)_Ptr) = _Marker;
            _Ptr = (char*)_Ptr + 16;
        }
        return _Ptr;
    }

    __inline size_t _MallocaComputeSize(size_t _Size)
    {
        size_t _MarkedSize = _Size + 16;
        return _MarkedSize > _Size ? _MarkedSize : 0;
    }












    __inline void __cdecl _freea(    void* _Memory)
    {
        unsigned int _Marker;
        if (_Memory)
        {
            _Memory = (char*)_Memory - 16;
            _Marker = *(unsigned int*)_Memory;
            if (_Marker == 0xDDDD)
            {
                free(_Memory);
            }
            else if (_Marker != 0xCCCC)
            {
                ((void)0);
            }
        }
    }







}                             

       
       
                 
       



         extern "C" {

  typedef void (__cdecl* terminate_handler )(void);
typedef void (__cdecl* terminate_function)(void);



     __declspec(noreturn) void __cdecl abort();
     __declspec(noreturn) void __cdecl terminate() throw();


         terminate_handler __cdecl set_terminate(
              terminate_handler _NewTerminateHandler
            ) throw();

         terminate_handler __cdecl _get_terminate();



}                             





         extern "C" {

  typedef void (__cdecl* unexpected_handler )(void);
typedef void (__cdecl* unexpected_function)(void);


struct _EXCEPTION_POINTERS;


     __declspec(noreturn) void __cdecl unexpected() noexcept(false);


         unexpected_handler __cdecl set_unexpected(
              unexpected_handler _NewUnexpectedHandler
            ) noexcept;

         unexpected_handler __cdecl _get_unexpected() noexcept;

        typedef void (__cdecl* _se_translator_function)(unsigned int, struct _EXCEPTION_POINTERS*);

         _se_translator_function __cdecl _set_se_translator(
              _se_translator_function _NewSETranslator
            );


    class type_info;

     int __cdecl _is_exception_typeof(
          type_info const&     _Type,
          _EXCEPTION_POINTERS* _ExceptionPtr
        );

     bool __cdecl __uncaught_exception();
     int  __cdecl __uncaught_exceptions();


}                             







         extern "C" {

struct __std_exception_data
{
    char const* _What;
    bool        _DoFree;
};

 void __cdecl __std_exception_copy(
       __std_exception_data const* _From,
      __std_exception_data*       _To
    );

 void __cdecl __std_exception_destroy(
      __std_exception_data* _Data
    );

}                             



namespace std {

class exception
{
public:

    exception() noexcept
        : _Data()
    {
    }

    explicit exception(char const* const _Message) noexcept
        : _Data()
    {
        __std_exception_data _InitData = { _Message, true };
        __std_exception_copy(&_InitData, &_Data);
    }

    exception(char const* const _Message, int) noexcept
        : _Data()
    {
        _Data._What = _Message;
    }

    exception(exception const& _Other) noexcept
        : _Data()
    {
        __std_exception_copy(&_Other._Data, &_Data);
    }

    exception& operator=(exception const& _Other) noexcept
    {
        if (this == &_Other)
        {
            return *this;
        }

        __std_exception_destroy(&_Data);
        __std_exception_copy(&_Other._Data, &_Data);
        return *this;
    }

    virtual ~exception() noexcept
    {
        __std_exception_destroy(&_Data);
    }

     virtual char const* what() const
    {
        return _Data._What ? _Data._What : "Unknown exception";
    }

private:

    __std_exception_data _Data;
};

class bad_exception
    : public exception
{
public:

    bad_exception() noexcept
        : exception("bad exception", 1)
    {
    }
};

class bad_alloc
    : public exception
{
public:

    bad_alloc() noexcept
        : exception("bad allocation", 1)
    {
    }

private:

    friend class bad_array_new_length;

    bad_alloc(char const* const _Message) noexcept
        : exception(_Message, 1)
    {
    }
};

class bad_array_new_length
    : public bad_alloc
{
public:

    bad_array_new_length() noexcept
        : bad_alloc("bad array new length")
    {
    }
};


}  


namespace std {

using ::terminate;

using ::set_terminate;
using ::terminate_handler;

 inline terminate_handler __cdecl get_terminate() noexcept {      return _get_terminate();
}


}


 void __cdecl __ExceptionPtrCreate(  void*) noexcept;
 void __cdecl __ExceptionPtrDestroy(  void*) noexcept;
 void __cdecl __ExceptionPtrCopy(  void*,   const void*) noexcept;
 void __cdecl __ExceptionPtrAssign(  void*,   const void*) noexcept;
 bool __cdecl __ExceptionPtrCompare(  const void*,   const void*) noexcept;
 bool __cdecl __ExceptionPtrToBool(  const void*) noexcept;
 void __cdecl __ExceptionPtrSwap(  void*,   void*) noexcept;
 void __cdecl __ExceptionPtrCurrentException(void*) noexcept;
[[noreturn]]  void __cdecl __ExceptionPtrRethrow(  const void*);
 void __cdecl __ExceptionPtrCopyException(
      void*,   const void*,   const void*) noexcept;

namespace std {

class exception_ptr {
public:
    exception_ptr() noexcept {
        __ExceptionPtrCreate(this);
    }

    exception_ptr(nullptr_t) noexcept {
        __ExceptionPtrCreate(this);
    }

    ~exception_ptr() noexcept {
        __ExceptionPtrDestroy(this);
    }

    exception_ptr(const exception_ptr& _Rhs) noexcept {
        __ExceptionPtrCopy(this, &_Rhs);
    }

    exception_ptr& operator=(const exception_ptr& _Rhs) noexcept {
        __ExceptionPtrAssign(this, &_Rhs);
        return *this;
    }

    exception_ptr& operator=(nullptr_t) noexcept {
        exception_ptr _Ptr;
        __ExceptionPtrAssign(this, &_Ptr);
        return *this;
    }

    explicit operator bool() const noexcept {
        return __ExceptionPtrToBool(this);
    }

    static exception_ptr _Current_exception() noexcept {
        exception_ptr _Retval;
        __ExceptionPtrCurrentException(&_Retval);
        return _Retval;
    }

    static exception_ptr _Copy_exception(  void* _Except,   const void* _Ptr) {
        exception_ptr _Retval;
        if (!_Ptr) {
                         return _Retval;
        }
        __ExceptionPtrCopyException(&_Retval, _Except, _Ptr);
        return _Retval;
    }

    friend void swap(exception_ptr& _Lhs, exception_ptr& _Rhs) noexcept {
        __ExceptionPtrSwap(&_Lhs, &_Rhs);
    }

     friend bool operator==(const exception_ptr& _Lhs, const exception_ptr& _Rhs) noexcept {
        return __ExceptionPtrCompare(&_Lhs, &_Rhs);
    }

     friend bool operator==(nullptr_t, const exception_ptr& _Rhs) noexcept {
        return !_Rhs;
    }

     friend bool operator==(const exception_ptr& _Lhs, nullptr_t) noexcept {
        return !_Lhs;
    }

     friend bool operator!=(const exception_ptr& _Lhs, const exception_ptr& _Rhs) noexcept {
        return !(_Lhs == _Rhs);
    }

     friend bool operator!=(nullptr_t _Lhs, const exception_ptr& _Rhs) noexcept {
        return !(_Lhs == _Rhs);
    }

     friend bool operator!=(const exception_ptr& _Lhs, nullptr_t _Rhs) noexcept {
        return !(_Lhs == _Rhs);
    }

private:
    void* _Data1;
    void* _Data2;
};

 inline exception_ptr current_exception() noexcept {
    return exception_ptr::_Current_exception();
}

[[noreturn]] inline void rethrow_exception(  exception_ptr _Ptr) {
    __ExceptionPtrRethrow(&_Ptr);
}

template <class _Ex>
void* __GetExceptionInfo(_Ex);

template <class _Ex>
 exception_ptr make_exception_ptr(_Ex _Except) noexcept {
    return exception_ptr::_Copy_exception(::std:: addressof(_Except), __GetExceptionInfo(_Except));
}

 [[noreturn]] inline void _Throw_bad_array_new_length() {
    throw bad_array_new_length{};
}

 class nested_exception {  public:
    nested_exception() noexcept : _Exc(::std:: current_exception()) {}

    nested_exception(const nested_exception&) noexcept = default;
    nested_exception& operator=(const nested_exception&) noexcept = default;
    virtual ~nested_exception() noexcept {}

    [[noreturn]] void rethrow_nested() const {          if (_Exc) {
            ::std:: rethrow_exception(_Exc);
        } else {
            ::std:: terminate();
        }
    }

     exception_ptr nested_ptr() const noexcept {          return _Exc;
    }

private:
    exception_ptr _Exc;
};

 template <class _Ty, class _Uty>
struct _With_nested : _Uty, nested_exception {      explicit _With_nested(_Ty&& _Arg)
        : _Uty(::std:: forward<_Ty>(_Arg)), nested_exception() {}  };

template <class _Ty>
[[noreturn]] void throw_with_nested(_Ty&& _Arg) {      using _Uty = decay_t<_Ty>;

    if constexpr (is_class_v<_Uty> && !is_base_of_v<nested_exception, _Uty> && !is_final_v<_Uty>) {
                 using _Glued = _With_nested<_Ty, _Uty>;
        throw _Glued(::std:: forward<_Ty>(_Arg));
    } else {
                 throw ::std:: forward<_Ty>(_Arg);
    }
}

 template <class _Ty>
void _Rethrow_if_nested(const _Ty* _Ptr, true_type) {      const auto _Nested = dynamic_cast<const nested_exception*>(_Ptr);

    if (_Nested) {
        _Nested->rethrow_nested();
    }
}

template <class _Ty>
void _Rethrow_if_nested(const _Ty*, false_type) {}  
template <class _Ty>
void rethrow_if_nested(const _Ty& _Arg) {      bool_constant<
        is_polymorphic_v<_Ty> && (!is_base_of_v<nested_exception, _Ty> || is_convertible_v<_Ty*, nested_exception*>)>
        _Tag;

    _Rethrow_if_nested(::std:: addressof(_Arg), _Tag);
}

}




