 
  
 
  
 
  
   
                                           
                                                 
           
     
                                                                                                                   
  
    
                                                                                              
                     
  

    
 

 





  

 


 

      
   
    
  
 
  
 
  
   
   
 

   
 
  

 
  
 
  

 


 



 
   
 





 
    

  
 


 



 
               

 

 

    

 








 



  
 

 
    
 
 
  
 
 

 
 
 

 
  
   
 




   
   

   

   
 

 

   
    
  
 

 
 
    
  
 
 
 
 




 

  
 
 
  
 
  
  

   
 
 
  
 
   
 
 
  
  
 

 

  

  



 


  



 
 
 
 
    
 
  
 
 
 


 


  
 
 
 

 
    
 
  
 
 
 


 


  
 
 
 

   

   
   
 
  
 
 
 
  
 
 
 

 
 
  
 
 
  
 
 
 


 


  
 
 
 

  
 
 
 
    



     









    



   

    
      
   




 



























 

 
 


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

    __declspec(deprecated("This function or variable may be unsafe. Consider using wcscat_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl wcscat(  wchar_t *_Destination,                                                                             wchar_t const* _Source);

 
 int __cdecl wcscmp(
      wchar_t const* _String1,
      wchar_t const* _String2
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl wcscpy_s(wchar_t (&_Destination)[_Size],   wchar_t const* _Source) throw()                 {                                                                                                                    return wcscpy_s(_Destination, _Size, _Source);                                                                       }                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using wcscpy_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl wcscpy(  wchar_t *_Destination,                                          wchar_t const* _Source);

 
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

__declspec(deprecated("This function or variable may be unsafe. Consider using wcsncat_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl wcsncat(  wchar_t *_Destination,      wchar_t const* _Source,                         size_t _Count);

 
 int __cdecl wcsncmp(
      wchar_t const* _String1,
      wchar_t const* _String2,
                            size_t         _MaxCount
    );

extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl wcsncpy_s(wchar_t (&_Destination)[_Size],   wchar_t const* _Source,                      size_t _Count) throw()                 {                                                                                                                                    return wcsncpy_s(_Destination, _Size, _Source, _Count);                                                                               }                                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using wcsncpy_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl wcsncpy(    wchar_t *_Destination,               wchar_t const* _Source,                                  size_t _Count);

 
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

__declspec(deprecated("This function or variable may be unsafe. Consider using _wcsnset_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _wcsnset(  wchar_t *_String,                            wchar_t _Value,                            size_t _MaxCount);

 wchar_t* __cdecl _wcsrev(
      wchar_t* _String
    );

  errno_t __cdecl _wcsset_s(
      wchar_t* _Destination,
                                 size_t   _SizeInWords,
                                 wchar_t  _Value
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl _wcsset_s(  wchar_t (&_String)[_Size],          wchar_t _Value) throw()                 {                                                                                                                    return _wcsset_s(_String, _Size, _Value);                                                                       }                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _wcsset_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _wcsset(  wchar_t *_String,                       wchar_t _Value);

  errno_t __cdecl _wcslwr_s(
      wchar_t* _String,
                                 size_t   _SizeInWords
    );

extern "C++"                                                                                      {                                                                                                     template <size_t _Size>                                                                           inline                                                                                            errno_t __cdecl _wcslwr_s(  wchar_t (&_String)[_Size]) throw()                  {                                                                                                     return _wcslwr_s(_String, _Size);                                                                }                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _wcslwr_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _wcslwr(  wchar_t *_String);


 errno_t __cdecl _wcslwr_s_l(
      wchar_t*  _String,
                                 size_t    _SizeInWords,
                             _locale_t _Locale
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl _wcslwr_s_l(  wchar_t (&_String)[_Size],      _locale_t _Locale) throw()                 {                                                                                                                    return _wcslwr_s_l(_String, _Size, _Locale);                                                                       }                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _wcslwr_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _wcslwr_l(  wchar_t *_String,                   _locale_t _Locale);


 errno_t __cdecl _wcsupr_s(
      wchar_t* _String,
                          size_t   _Size
    );

extern "C++"                                                                                      {                                                                                                     template <size_t _Size>                                                                           inline                                                                                            errno_t __cdecl _wcsupr_s(  wchar_t (&_String)[_Size]) throw()                  {                                                                                                     return _wcsupr_s(_String, _Size);                                                                }                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _wcsupr_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _wcsupr(  wchar_t *_String);


 errno_t __cdecl _wcsupr_s_l(
      wchar_t*  _String,
                          size_t    _Size,
                      _locale_t _Locale
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl _wcsupr_s_l(  wchar_t (&_String)[_Size],      _locale_t _Locale) throw()                 {                                                                                                                    return _wcsupr_s_l(_String, _Size, _Locale);                                                                       }                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _wcsupr_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _wcsupr_l(  wchar_t *_String,                   _locale_t _Locale);

 

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


    __declspec(deprecated("This function or variable may be unsafe. Consider using strcat_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl strcat(  char *_Destination,                                                                             char const* _Source);


 
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

__declspec(deprecated("This function or variable may be unsafe. Consider using strcpy_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl strcpy(  char *_Destination,                                          char const* _Source);

 
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

__declspec(deprecated("This function or variable may be unsafe. Consider using _strlwr_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _strlwr(  char *_String);


 errno_t __cdecl _strlwr_s_l(
      char*     _String,
                          size_t    _Size,
                      _locale_t _Locale
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl _strlwr_s_l(  char (&_String)[_Size],      _locale_t _Locale) throw()                 {                                                                                                                    return _strlwr_s_l(_String, _Size, _Locale);                                                                       }                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _strlwr_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _strlwr_l(  char *_String,                   _locale_t _Locale);

extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl strncat_s(              char (&_Destination)[_Size],   char const* _Source,                      size_t _Count) throw()                 {                                                                                                                                    return strncat_s(_Destination, _Size, _Source, _Count);                                                                               }                                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using strncat_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl strncat(  char *_Destination,      char const* _Source,                         size_t _Count);

 
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

__declspec(deprecated("This function or variable may be unsafe. Consider using strncpy_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl strncpy(    char *_Destination,               char const* _Source,                                  size_t _Count);

 


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

__declspec(deprecated("This function or variable may be unsafe. Consider using _strnset_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _strnset(  char *_Destination,                         int _Value,                         size_t _Count);

 
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

__declspec(deprecated("This function or variable may be unsafe. Consider using _strset_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _strset(  char *_Destination,         int _Value);

 
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

__declspec(deprecated("This function or variable may be unsafe. Consider using _strupr_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _strupr(  char *_String);


 errno_t __cdecl _strupr_s_l(
      char*     _String,
                          size_t    _Size,
                      _locale_t _Locale
    );

extern "C++"                                                                                                     {                                                                                                                    template <size_t _Size>                                                                                          inline                                                                                                           errno_t __cdecl _strupr_s_l(  char (&_String)[_Size],      _locale_t _Locale) throw()                 {                                                                                                                    return _strupr_s_l(_String, _Size, _Locale);                                                                       }                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _strupr_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _strupr_l(  char *_String,                   _locale_t _Locale);

 

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



 
  
 
  

 

       


extern "C" {

 


 






 






 



unsigned char _BitScanForward(unsigned long * _Index, unsigned long _Mask);
unsigned char _BitScanForward64(unsigned long * _Index, unsigned __int64 _Mask);

unsigned char _BitScanReverse(unsigned long * _Index, unsigned long _Mask);
unsigned char _BitScanReverse64(unsigned long * _Index, unsigned __int64 _Mask);

unsigned char _bittest(long const *, long);


long _InterlockedAnd(long volatile * _Value, long _Mask);
short _InterlockedAnd16(short volatile * _Value, short _Mask);



__int64 _InterlockedAnd64(__int64 volatile * _Value, __int64 _Mask);
__int64 _interlockedand64(__int64 volatile * _Value, __int64 _Mask);



char _InterlockedAnd8(char volatile * _Value, char _Mask);






long  _InterlockedCompareExchange(long volatile * _Destination, long _Exchange, long _Comparand);

short _InterlockedCompareExchange16(short volatile * _Destination, short _Exchange, short _Comparand);



__int64 _InterlockedCompareExchange64(__int64 volatile * _Destination, __int64 _Exchange, __int64 _Comparand);



char _InterlockedCompareExchange8(char volatile * _Destination, char _Exchange, char _Comparand);






unsigned char _InterlockedCompareExchange128(__int64 volatile * _Destination, __int64 _ExchangeHigh, __int64 _ExchangeLow, __int64 * _ComparandResult);



long  _InterlockedDecrement(long volatile * _Addend);

short _InterlockedDecrement16(short volatile * _Addend);
__int64 _InterlockedDecrement64(__int64 volatile * _Addend);
__int64 _interlockeddecrement64(__int64 volatile * _Addend);
long  _InterlockedExchange(long volatile * _Target, long _Value);

short _InterlockedExchange16(short volatile * _Target, short _Value);



__int64 _InterlockedExchange64(__int64 volatile * _Target, __int64 _Value);
__int64 _interlockedexchange64(__int64 volatile * _Target, __int64 _Value);



char _InterlockedExchange8(char volatile * _Target, char _Value);



long  _InterlockedExchangeAdd(long volatile * _Addend, long _Value);
short _InterlockedExchangeAdd16(short volatile * _Addend, short _Value);



__int64 _InterlockedExchangeAdd64(__int64 volatile * _Addend, __int64 _Value);
__int64 _interlockedexchangeadd64(__int64 volatile * _Addend, __int64 _Value);



char _InterlockedExchangeAdd8(char volatile * _Addend, char _Value);









long  _InterlockedIncrement(long volatile * _Addend);

short _InterlockedIncrement16(short volatile * _Addend);
__int64 _InterlockedIncrement64(__int64 volatile * _Addend);
__int64 _interlockedincrement64(__int64 volatile * _Addend);

long _InterlockedOr(long volatile * _Value, long _Mask);
short _InterlockedOr16(short volatile * _Value, short _Mask);



__int64 _InterlockedOr64(__int64 volatile * _Value, __int64 _Mask);
__int64 _interlockedor64(__int64 volatile * _Value, __int64 _Mask);



char _InterlockedOr8(char volatile * _Value, char _Mask);






long _InterlockedXor(long volatile * _Value, long _Mask);
short _InterlockedXor16(short volatile * _Value, short _Mask);



__int64 _InterlockedXor64(__int64 volatile * _Value, __int64 _Mask);
__int64 _interlockedxor64(__int64 volatile * _Value, __int64 _Mask);



char _InterlockedXor8(char volatile * _Value, char _Mask);






void _ReadWriteBarrier(void);
__int16 __iso_volatile_load16(const volatile __int16 *);
__int32 __iso_volatile_load32(const volatile __int32 *);
__int64 __iso_volatile_load64(const volatile __int64 *);
__int8 __iso_volatile_load8(const volatile __int8 *);
void __iso_volatile_store16(volatile __int16 *, __int16);
void __iso_volatile_store32(volatile __int32 *, __int32);
void __iso_volatile_store64(volatile __int64 *, __int64);
void __iso_volatile_store8(volatile __int8 *, __int8);


unsigned char _interlockedbittestandset(long volatile *, long);



void _mm_pause(void);
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
int _cvt_ftoi_sat (float a);
unsigned _cvt_ftoui_sat (float a);
long long _cvt_ftoll_sat (float a);
unsigned long long _cvt_ftoull_sat (float a);
int _cvt_ftoi_sent (float a);
unsigned _cvt_ftoui_sent (float a);
long long _cvt_ftoll_sent (float a);
unsigned long long _cvt_ftoull_sent (float a);
int _cvt_dtoi_sat (double a);
unsigned _cvt_dtoui_sat (double a);
long long _cvt_dtoll_sat (double a);
unsigned long long _cvt_dtoull_sat (double a);
int _cvt_dtoi_sent (double a);
unsigned _cvt_dtoui_sent (double a);
long long _cvt_dtoll_sent (double a);
unsigned long long _cvt_dtoull_sent (double a);
constexpr void * __cdecl __builtin_assume_aligned(const void *, size_t, ...) noexcept;

 

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

    __declspec(deprecated("This function or variable may be unsafe. Consider using _itow_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _itow(                     int _Value,     wchar_t *_Buffer,                      int _Radix);

     
    
     errno_t __cdecl _ltow_s(
                                  long     _Value,
          wchar_t* _Buffer,
                                  size_t   _BufferCount,
                                  int      _Radix
        );

    extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl _ltow_s(  long _Value, wchar_t (&_Buffer)[_Size],   int _Radix) throw()                 {                                                                                                                                    return _ltow_s(_Value, _Buffer, _Size, _Radix);                                                                               }                                                                                                                            }

    __declspec(deprecated("This function or variable may be unsafe. Consider using _ltow_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _ltow(                     long _Value,     wchar_t *_Buffer,                      int _Radix);

    
     errno_t __cdecl _ultow_s(
                                  unsigned long _Value,
          wchar_t*      _Buffer,
                                  size_t        _BufferCount,
                                  int           _Radix
        );

    extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl _ultow_s(  unsigned long _Value, wchar_t (&_Buffer)[_Size],   int _Radix) throw()                 {                                                                                                                                    return _ultow_s(_Value, _Buffer, _Size, _Radix);                                                                               }                                                                                                                            }

    __declspec(deprecated("This function or variable may be unsafe. Consider using _ultow_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t* __cdecl _ultow(                     unsigned long _Value,     wchar_t *_Buffer,                      int _Radix);

     
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

__declspec(deprecated("This function or variable may be unsafe. Consider using _wmakepath_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  void __cdecl _wmakepath(    wchar_t *_Buffer,                wchar_t const* _Drive,                wchar_t const* _Dir,                wchar_t const* _Filename,                wchar_t const* _Ext);

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

        __declspec(deprecated("This function or variable may be unsafe. Consider using _wsearchenv_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  void __cdecl _wsearchenv(                   wchar_t const* _Filename,                    wchar_t const* _VarName,     wchar_t *_ResultPath);

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



 __declspec(deprecated("This function or variable may be unsafe. Consider using _get_pgmptr instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char**    __cdecl __p__pgmptr (void);
__declspec(deprecated("This function or variable may be unsafe. Consider using _get_wpgmptr instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  wchar_t** __cdecl __p__wpgmptr(void);
__declspec(deprecated("This function or variable may be unsafe. Consider using _get_fmode instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  int*      __cdecl __p__fmode  (void);


 
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

__declspec(deprecated("This function or variable may be unsafe. Consider using _itoa_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _itoa(                     int _Value,     char *_Buffer,                      int _Radix);

 

 errno_t __cdecl _ltoa_s(
                              long   _Value,
      char*  _Buffer,
                              size_t _BufferCount,
                              int    _Radix
    );

extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl _ltoa_s(  long _Value, char (&_Buffer)[_Size],   int _Radix) throw()                 {                                                                                                                                    return _ltoa_s(_Value, _Buffer, _Size, _Radix);                                                                               }                                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _ltoa_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _ltoa(                     long _Value,     char *_Buffer,                      int _Radix);

 

 errno_t __cdecl _ultoa_s(
                              unsigned long _Value,
      char*         _Buffer,
                              size_t        _BufferCount,
                              int           _Radix
    );

extern "C++"                                                                                                                     {                                                                                                                                    template <size_t _Size>                                                                                                          inline                                                                                                                           errno_t __cdecl _ultoa_s(  unsigned long _Value, char (&_Buffer)[_Size],   int _Radix) throw()                 {                                                                                                                                    return _ultoa_s(_Value, _Buffer, _Size, _Radix);                                                                               }                                                                                                                            }

__declspec(deprecated("This function or variable may be unsafe. Consider using _ultoa_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _ultoa(                     unsigned long _Value,     char *_Buffer,                      int _Radix);

 

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

__declspec(deprecated("This function or variable may be unsafe. Consider using mbstowcs_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  size_t __cdecl mbstowcs(  wchar_t *_Dest,                           char const* _Source,                             size_t _MaxCount);


 errno_t __cdecl _mbstowcs_s_l(
                                                      size_t*     _PtNumOfCharConverted,
      wchar_t*    _DstBuf,
                                                           size_t      _SizeInWords,
                                     char const* _SrcBuf,
                                                           size_t      _MaxCount,
                                                       _locale_t   _Locale
    );

extern "C++"                                                                                                                                                      {                                                                                                                                                                     template <size_t _Size>                                                                                                                                           inline                                                                                                                                                            errno_t __cdecl _mbstowcs_s_l(  size_t* _PtNumOfCharConverted,    wchar_t (&_Dest)[_Size],      char const* _Source,        size_t _MaxCount,    _locale_t _Locale) throw()                  {                                                                                                                                                                     return _mbstowcs_s_l(_PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount, _Locale);                                                                                                }                                                                                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _mbstowcs_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  size_t __cdecl _mbstowcs_l(  wchar_t *_Dest,                       char const* _Source,                         size_t _MaxCount,                     _locale_t _Locale);




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

__declspec(deprecated("This function or variable may be unsafe. Consider using wcstombs_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  size_t __cdecl wcstombs(  char *_Dest,                           wchar_t const* _Source,                             size_t _MaxCount);


 errno_t __cdecl _wcstombs_s_l(
                                                               size_t*        _PtNumOfCharConverted,
      char*          _Dst,
                                                                    size_t         _DstSizeInBytes,
                                                                  wchar_t const* _Src,
                                                                    size_t         _MaxCountInBytes,
                                                                _locale_t      _Locale
    );

extern "C++"                                                                                                                                                      {                                                                                                                                                                     template <size_t _Size>                                                                                                                                           inline                                                                                                                                                            errno_t __cdecl _wcstombs_s_l(                size_t* _PtNumOfCharConverted,   char (&_Dest)[_Size],                    wchar_t const* _Source,                      size_t _MaxCount,                  _locale_t _Locale) throw()                  {                                                                                                                                                                     return _wcstombs_s_l(_PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount, _Locale);                                                                                                }                                                                                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _wcstombs_s_l instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  size_t __cdecl _wcstombs_l(  char *_Dest,                       wchar_t const* _Source,                         size_t _MaxCount,                     _locale_t _Locale);



       


 
 
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

__declspec(deprecated("This function or variable may be unsafe. Consider using _makepath_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  void __cdecl _makepath(    char *_Buffer,                char const* _Drive,                char const* _Dir,                char const* _Filename,                char const* _Ext);

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

    __declspec(deprecated("This function or variable may be unsafe. Consider using _searchenv_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  void __cdecl _searchenv(                   char const* _Filename,                    char const* _VarName,     char *_Buffer);

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

 template <class _Ty1, class _Ty2>
struct is_layout_compatible : bool_constant<__is_layout_compatible(_Ty1, _Ty2)> {};

template <class _Ty1, class _Ty2>
inline constexpr bool is_layout_compatible_v = __is_layout_compatible(_Ty1, _Ty2);

 template <class _Base, class _Derived>
struct is_pointer_interconvertible_base_of : bool_constant<__is_pointer_interconvertible_base_of(_Base, _Derived)> {};

template <class _Base, class _Derived>
inline constexpr bool is_pointer_interconvertible_base_of_v = __is_pointer_interconvertible_base_of(_Base, _Derived);

 template <class _ClassTy, class _MemberTy>
 constexpr bool is_pointer_interconvertible_with_class(_MemberTy _ClassTy::*_Pm) noexcept {
    return __is_pointer_interconvertible_with_class(_ClassTy, _Pm);
}

 template <class _ClassTy1, class _ClassTy2, class _MemberTy1, class _MemberTy2>
 constexpr bool is_corresponding_member(_MemberTy1 _ClassTy1::*_Pm1, _MemberTy2 _ClassTy2::*_Pm2) noexcept {
    return __is_corresponding_member(_ClassTy1, _ClassTy2, _Pm1, _Pm2);
}

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

 enum class memory_order : int {
    relaxed,
    consume,
    acquire,
    release,
    acq_rel,
    seq_cst,

         memory_order_relaxed = relaxed,
    memory_order_consume = consume,
    memory_order_acquire = acquire,
    memory_order_release = release,
    memory_order_acq_rel = acq_rel,
    memory_order_seq_cst = seq_cst
};
inline constexpr memory_order memory_order_relaxed = memory_order::relaxed;
inline constexpr memory_order memory_order_consume = memory_order::consume;
inline constexpr memory_order memory_order_acquire = memory_order::acquire;
inline constexpr memory_order memory_order_release = memory_order::release;
inline constexpr memory_order memory_order_acq_rel = memory_order::acq_rel;
inline constexpr memory_order memory_order_seq_cst = memory_order::seq_cst;

using _Atomic_counter_t = unsigned long;

 template <class _Integral, class _Ty>
 volatile _Integral* _Atomic_address_as(_Ty& _Source) noexcept {
         static_assert(is_integral_v<_Integral>, "Tried to reinterpret memory as non-integral");
    return &reinterpret_cast<volatile _Integral&>(_Source);
}

template <class _Integral, class _Ty>
 const volatile _Integral* _Atomic_address_as(const _Ty& _Source) noexcept {
         static_assert(is_integral_v<_Integral>, "Tried to reinterpret memory as non-integral");
    return &reinterpret_cast<const volatile _Integral&>(_Source);
}

}


 
  
 
  

 
  
 
  



inline constexpr unsigned long long _Atomic_wait_no_deadline = 0xFFFF'FFFF'FFFF'FFFF;
inline constexpr unsigned long _Atomic_wait_no_timeout       = 0xFFFF'FFFF;  
extern "C" {
enum class __std_atomic_api_level : unsigned long {
    __not_set,
    __detecting,
    __has_srwlock,
    __has_wait_on_address,
};

    __std_atomic_api_level __stdcall __std_atomic_set_api_level(__std_atomic_api_level _Requested_api_level) noexcept;

    int __stdcall __std_atomic_wait_direct(
    const void* _Storage, void* _Comparand, size_t _Size, unsigned long _Remaining_timeout) noexcept;
void __stdcall __std_atomic_notify_one_direct(const void* _Storage) noexcept;
void __stdcall __std_atomic_notify_all_direct(const void* _Storage) noexcept;

   using _Atomic_wait_indirect_equal_callback_t = bool(__stdcall*)(
    const void* _Storage, void* _Comparand, size_t _Size, void* _Param) noexcept;

int __stdcall __std_atomic_wait_indirect(const void* _Storage, void* _Comparand, size_t _Size, void* _Param,
    _Atomic_wait_indirect_equal_callback_t _Are_equal, unsigned long _Remaining_timeout) noexcept;
void __stdcall __std_atomic_notify_one_indirect(const void* _Storage) noexcept;
void __stdcall __std_atomic_notify_all_indirect(const void* _Storage) noexcept;

   unsigned long long __stdcall __std_atomic_wait_get_deadline(unsigned long long _Timeout) noexcept;
unsigned long __stdcall __std_atomic_wait_get_remaining_timeout(unsigned long long _Deadline) noexcept;

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

__declspec(deprecated("This function or variable may be unsafe. Consider using _wstrdate_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))      wchar_t* __cdecl _wstrdate(  wchar_t *_Buffer);


 errno_t __cdecl _wstrtime_s(
       wchar_t* _Buffer,
                                                                                size_t   _SizeInWords
    );

extern "C++"                                                                                      {                                                                                                     template <size_t _Size>                                                                           inline                                                                                            errno_t __cdecl _wstrtime_s(  wchar_t (&_Buffer)[_Size]) throw()                  {                                                                                                     return _wstrtime_s(_Buffer, _Size);                                                                }                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _wstrtime_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))      wchar_t* __cdecl _wstrtime(  wchar_t *_Buffer);



     
         
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



 



        __declspec(deprecated("This function or variable may be unsafe. Consider using _get_daylight instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 int* __cdecl __daylight(void);


   __declspec(deprecated("This function or variable may be unsafe. Consider using _get_dstbias instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 long* __cdecl __dstbias(void);


   __declspec(deprecated("This function or variable may be unsafe. Consider using _get_timezone instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
 long* __cdecl __timezone(void);


     __declspec(deprecated("This function or variable may be unsafe. Consider using _get_tzname instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))
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

__declspec(deprecated("This function or variable may be unsafe. Consider using _strdate_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))    char* __cdecl _strdate(  char *_Buffer);


 errno_t __cdecl _strtime_s(
       char*  _Buffer,
                                                                              size_t _SizeInBytes
    );

extern "C++"                                                                                      {                                                                                                     template <size_t _Size>                                                                           inline                                                                                            errno_t __cdecl _strtime_s(  char (&_Buffer)[_Size]) throw()                  {                                                                                                     return _strtime_s(_Buffer, _Size);                                                                }                                                                                             }

__declspec(deprecated("This function or variable may be unsafe. Consider using _strtime_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details."))  char* __cdecl _strtime(  char *_Buffer);

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




namespace std {
using :: clock_t;
using :: size_t;
using :: time_t;
using :: tm;
using :: asctime;
using :: clock;
using :: ctime;
using :: difftime;
using :: gmtime;
using :: localtime;
using :: mktime;
using :: strftime;
using :: time;
using :: timespec;
using :: timespec_get;
}






extern "C" {

struct xtime {      __time64_t sec;
    long nsec;
};

 int __cdecl xtime_get(xtime*, int);

 long __cdecl _Xtime_diff_to_millis(const xtime*);
 long __cdecl _Xtime_diff_to_millis2(const xtime*, const xtime*);
 long long __cdecl _Xtime_get_ticks();

 long long __cdecl _Query_perf_counter();
 long long __cdecl _Query_perf_frequency();

}



 



extern "C" {
using _Thrd_id_t = unsigned int;
struct _Thrd_t {      void* _Hnd;      _Thrd_id_t _Id;
};

 
using _Mtx_t = struct _Mtx_internal_imp_t*;

using _Cnd_t = struct _Cnd_internal_imp_t*;

enum { _Thrd_success, _Thrd_nomem, _Thrd_timedout, _Thrd_busy, _Thrd_error };

  int __cdecl _Thrd_detach(_Thrd_t);
 int __cdecl _Thrd_join(_Thrd_t, int*);
 void __cdecl _Thrd_sleep(const xtime*);
 void __cdecl _Thrd_yield();
 unsigned int __cdecl _Thrd_hardware_concurrency();
 _Thrd_id_t __cdecl _Thrd_id();

 enum {      _Mtx_plain     = 0x01,
    _Mtx_try       = 0x02,
    _Mtx_timed     = 0x04,
    _Mtx_recursive = 0x100
};

 int __cdecl _Mtx_init(_Mtx_t*, int);
 void __cdecl _Mtx_destroy(_Mtx_t);
 void __cdecl _Mtx_init_in_situ(_Mtx_t, int);
 void __cdecl _Mtx_destroy_in_situ(_Mtx_t);
 int __cdecl _Mtx_current_owns(_Mtx_t);
 int __cdecl _Mtx_lock(_Mtx_t);
 int __cdecl _Mtx_trylock(_Mtx_t);
 int __cdecl _Mtx_timedlock(_Mtx_t, const xtime*);
 int __cdecl _Mtx_unlock(_Mtx_t);  
 void* __cdecl _Mtx_getconcrtcs(_Mtx_t);
 void __cdecl _Mtx_clear_owner(_Mtx_t);
 void __cdecl _Mtx_reset_owner(_Mtx_t);

  using _Smtx_t = void*;
void __cdecl _Smtx_lock_exclusive(_Smtx_t*);
void __cdecl _Smtx_lock_shared(_Smtx_t*);
int __cdecl _Smtx_try_lock_exclusive(_Smtx_t*);
int __cdecl _Smtx_try_lock_shared(_Smtx_t*);
void __cdecl _Smtx_unlock_exclusive(_Smtx_t*);
void __cdecl _Smtx_unlock_shared(_Smtx_t*);

  int __cdecl _Cnd_init(_Cnd_t*);
 void __cdecl _Cnd_destroy(_Cnd_t);
 void __cdecl _Cnd_init_in_situ(_Cnd_t);
 void __cdecl _Cnd_destroy_in_situ(_Cnd_t);
 int __cdecl _Cnd_wait(_Cnd_t, _Mtx_t);   int __cdecl _Cnd_timedwait(_Cnd_t, _Mtx_t, const xtime*);
 int __cdecl _Cnd_broadcast(_Cnd_t);   int __cdecl _Cnd_signal(_Cnd_t);   void __cdecl _Cnd_register_at_thread_exit(_Cnd_t, _Mtx_t, int*);
 void __cdecl _Cnd_unregister_at_thread_exit(_Mtx_t);
 void __cdecl _Cnd_do_broadcast_at_thread_exit();
}

namespace std {
enum {      _DEVICE_OR_RESOURCE_BUSY,
    _INVALID_ARGUMENT,
    _NO_SUCH_PROCESS,
    _NOT_ENOUGH_MEMORY,
    _OPERATION_NOT_PERMITTED,
    _RESOURCE_DEADLOCK_WOULD_OCCUR,
    _RESOURCE_UNAVAILABLE_TRY_AGAIN
};

[[noreturn]]  void __cdecl _Throw_C_error(int _Code);
[[noreturn]]  void __cdecl _Throw_Cpp_error(int _Code);

inline int _Check_C_return(int _Res) {      if (_Res != _Thrd_success) {
        _Throw_C_error(_Res);
    }

    return _Res;
}
}


 




 

      extern "C"  unsigned char __stdcall __std_atomic_compare_exchange_128(
      long long* _Destination,   long long _ExchangeHigh,   long long _ExchangeLow,
      long long* _ComparandResult) noexcept;
extern "C"  char __stdcall __std_atomic_has_cmpxchg16b() noexcept;

  

 
 
extern "C" {
_Smtx_t* __stdcall __std_atomic_get_mutex(const void* _Key) noexcept;
}
   
namespace std {
 struct _Form_mask_t {};
inline constexpr _Form_mask_t _Form_mask{};

template <class _Ty>
struct _Storage_for {
         alignas(_Ty) unsigned char _Storage[sizeof(_Ty)];

    _Storage_for()                    = default;
    _Storage_for(const _Storage_for&) = delete;
    _Storage_for& operator=(const _Storage_for&) = delete;

    explicit _Storage_for(_Form_mask_t) noexcept {
        :: memset(_Storage, 0xff, sizeof(_Ty));
        __builtin_zero_non_value_bits(_Ptr());
    }

     _Ty& _Ref() noexcept {
        return reinterpret_cast<_Ty&>(_Storage);
    }

     _Ty* _Ptr() noexcept {
        return reinterpret_cast<_Ty*>(&_Storage);
    }
};

template <class _Ty>
inline constexpr bool _Might_have_non_value_bits =
    !has_unique_object_representations_v<_Ty> && !is_floating_point_v<_Ty>;

 extern "C" inline void atomic_thread_fence(const memory_order _Order) noexcept {
    if (_Order == memory_order_relaxed) {
        return;
    }

                     __pragma(warning(disable : 4996)) _ReadWriteBarrier() __pragma(warning(pop));
    if (_Order == memory_order_seq_cst) {
        volatile long _Guard;  
                                                                      (void) _InterlockedIncrement(&_Guard);
                         __pragma(warning(disable : 4996)) _ReadWriteBarrier() __pragma(warning(pop));
    }
}

extern "C" inline void atomic_signal_fence(const memory_order _Order) noexcept {
    if (_Order != memory_order_relaxed) {
                         __pragma(warning(disable : 4996)) _ReadWriteBarrier() __pragma(warning(pop));
    }
}

 template <class _Ty>
_Ty kill_dependency(_Ty _Arg) noexcept {      return _Arg;
}

 inline void _Check_memory_order(const memory_order _Order) noexcept {
         if (static_cast<unsigned int>(_Order) > static_cast<unsigned int>(memory_order_seq_cst)) {
        ;
    }
}

 inline void _Check_store_memory_order(const memory_order _Order) noexcept {
    switch (_Order) {
    case memory_order_relaxed:
    case memory_order_release:
    case memory_order_seq_cst:
                 break;
    case memory_order_consume:
    case memory_order_acquire:
    case memory_order_acq_rel:
    default:
        ;
        break;
    }
}

 inline void _Check_load_memory_order(const memory_order _Order) noexcept {
    switch (_Order) {
    case memory_order_relaxed:
    case memory_order_consume:
    case memory_order_acquire:
    case memory_order_seq_cst:
                 break;
    case memory_order_release:
    case memory_order_acq_rel:
    default:
        ;
        break;
    }
}

  inline memory_order _Combine_cas_memory_orders(
    const memory_order _Success, const memory_order _Failure) noexcept {
                                                      static constexpr memory_order _Combined_memory_orders[6][6] = {         {memory_order_relaxed, memory_order_consume, memory_order_acquire, memory_order_release, memory_order_acq_rel,
            memory_order_seq_cst},
        {memory_order_consume, memory_order_consume, memory_order_acquire, memory_order_acq_rel, memory_order_acq_rel,
            memory_order_seq_cst},
        {memory_order_acquire, memory_order_acquire, memory_order_acquire, memory_order_acq_rel, memory_order_acq_rel,
            memory_order_seq_cst},
        {memory_order_release, memory_order_acq_rel, memory_order_acq_rel, memory_order_release, memory_order_acq_rel,
            memory_order_seq_cst},
        {memory_order_acq_rel, memory_order_acq_rel, memory_order_acq_rel, memory_order_acq_rel, memory_order_acq_rel,
            memory_order_seq_cst},
        {memory_order_seq_cst, memory_order_seq_cst, memory_order_seq_cst, memory_order_seq_cst, memory_order_seq_cst,
            memory_order_seq_cst}};

    _Check_memory_order(_Success);
    _Check_load_memory_order(_Failure);
    return _Combined_memory_orders[static_cast<int>(_Success)][static_cast<int>(_Failure)];
}

 template <class _Integral, class _Ty>
 _Integral _Atomic_reinterpret_as(const _Ty& _Source) noexcept {
         static_assert(is_integral_v<_Integral>, "Tried to reinterpret memory as non-integral");
    if constexpr (is_integral_v<_Ty> && sizeof(_Integral) == sizeof(_Ty)) {
        return static_cast<_Integral>(_Source);
    } else if constexpr (is_pointer_v<_Ty> && sizeof(_Integral) == sizeof(_Ty)) {
        return reinterpret_cast<_Integral>(_Source);
    } else {
        _Integral _Result{};          :: memcpy(&_Result, ::std:: addressof(_Source), sizeof(_Source));
        return _Result;
    }
}

 inline void _Load_barrier(const memory_order _Order) noexcept {      switch (_Order) {
    case memory_order_relaxed:
                 break;
    default:
    case memory_order_release:
    case memory_order_acq_rel:
        ;
             case memory_order_consume:
    case memory_order_acquire:
    case memory_order_seq_cst:
                         __pragma(warning(disable : 4996)) _ReadWriteBarrier() __pragma(warning(pop));
        break;
    }
}

template <class _Ty>
struct _Atomic_padded {
    alignas(sizeof(_Ty)) mutable _Ty _Value;  };


template <class _Ty>
struct _Atomic_storage_types {
    using _TStorage = _Atomic_padded<_Ty>;
    using _Spinlock = long;
};

template <class _Ty>
struct _Atomic_storage_types<_Ty&> {
    using _TStorage = _Ty&;
    using _Spinlock = _Smtx_t*;  };

 template <class _Ty, size_t = sizeof(remove_reference_t<_Ty>)>
struct _Atomic_storage;

template <class _Ty, class _Value_type>
void _Atomic_wait_direct(
    const _Atomic_storage<_Ty>* const _This, _Value_type _Expected_bytes, const memory_order _Order) noexcept {
    const auto _Storage_ptr = ::std:: addressof(_This->_Storage);
    for (;;) {
        const _Value_type _Observed_bytes = _Atomic_reinterpret_as<_Value_type>(_This->load(_Order));
        if (_Expected_bytes != _Observed_bytes) {
            using _TVal = remove_reference_t<_Ty>;
            if constexpr (_Might_have_non_value_bits<_TVal>) {
                _Storage_for<_TVal> _Mask{_Form_mask};
                const _Value_type _Mask_val = _Atomic_reinterpret_as<_Value_type>(_Mask._Ref());

                if (((_Expected_bytes ^ _Observed_bytes) & _Mask_val) == 0) {
                    _Expected_bytes = _Observed_bytes;
                    continue;
                }
            }

            return;
        }

        __std_atomic_wait_direct(_Storage_ptr, &_Expected_bytes, sizeof(_Value_type), _Atomic_wait_no_timeout);
    }
}

inline void _Atomic_lock_acquire(long& _Spinlock) noexcept {
                   int _Current_backoff   = 1;
    const int _Max_backoff = 64;
    while (_InterlockedExchange(&_Spinlock, 1) != 0) {
        while (__iso_volatile_load32(&reinterpret_cast<int&>(_Spinlock)) != 0) {
            for (int _Count_down = _Current_backoff; _Count_down != 0; --_Count_down) {
                _mm_pause();
            }
            _Current_backoff = _Current_backoff < _Max_backoff ? _Current_backoff << 1 : _Max_backoff;
        }
    }
}

inline void _Atomic_lock_release(long& _Spinlock) noexcept {
    _InterlockedExchange(&_Spinlock, 0);  }

inline void _Atomic_lock_acquire(_Smtx_t* _Spinlock) noexcept {
    _Smtx_lock_exclusive(_Spinlock);
}

inline void _Atomic_lock_release(_Smtx_t* _Spinlock) noexcept {
    _Smtx_unlock_exclusive(_Spinlock);
}

template <class _Spinlock_t>
class  _Atomic_lock_guard {
public:
    explicit _Atomic_lock_guard(_Spinlock_t& _Spinlock_) noexcept : _Spinlock(_Spinlock_) {
        _Atomic_lock_acquire(_Spinlock);
    }

    ~_Atomic_lock_guard() {
        _Atomic_lock_release(_Spinlock);
    }

    _Atomic_lock_guard(const _Atomic_lock_guard&) = delete;
    _Atomic_lock_guard& operator=(const _Atomic_lock_guard&) = delete;

private:
    _Spinlock_t& _Spinlock;
};

template <class _Spinlock_t>
bool __stdcall _Atomic_wait_compare_non_lock_free(
    const void* _Storage, void* _Comparand, size_t _Size, void* _Spinlock_raw) noexcept {
    _Spinlock_t& _Spinlock = *static_cast<_Spinlock_t*>(_Spinlock_raw);
    _Atomic_lock_acquire(_Spinlock);
    const auto _Cmp_result = :: memcmp(_Storage, _Comparand, _Size);
    _Atomic_lock_release(_Spinlock);
    return _Cmp_result == 0;
}

inline bool __stdcall _Atomic_wait_compare_16_bytes(const void* _Storage, void* _Comparand, size_t, void*) noexcept {
    const auto _Dest              = static_cast<long long*>(const_cast<void*>(_Storage));
    const auto _Cmp               = static_cast<const long long*>(_Comparand);
    alignas(16) long long _Tmp[2] = {_Cmp[0], _Cmp[1]};
    return __std_atomic_compare_exchange_128(_Dest, _Tmp[1], _Tmp[0], _Tmp) != 0;
}

template <class _Ty, size_t  >
struct _Atomic_storage {
          
    using _TVal  = remove_reference_t<_Ty>;
    using _Guard = _Atomic_lock_guard<typename _Atomic_storage_types<_Ty>::_Spinlock>;

    _Atomic_storage() = default;

      constexpr _Atomic_storage(conditional_t<is_reference_v<_Ty>, _Ty, const _TVal> _Value) noexcept
        : _Storage(_Value) {
             }

    void store(const _TVal _Value, const memory_order _Order = memory_order_seq_cst) noexcept {
                 _Check_store_memory_order(_Order);
        _Guard _Lock{_Spinlock};
        _Storage = _Value;
    }

     _TVal load(const memory_order _Order = memory_order_seq_cst) const noexcept {
                 _Check_load_memory_order(_Order);
        _Guard _Lock{_Spinlock};
        _TVal _Local(_Storage);
        return _Local;
    }

    _TVal exchange(const _TVal _Value, const memory_order _Order = memory_order_seq_cst) noexcept {
                 _Check_memory_order(_Order);
        _Guard _Lock{_Spinlock};
        _TVal _Result(_Storage);
        _Storage = _Value;
        return _Result;
    }

    bool compare_exchange_strong(_TVal& _Expected, const _TVal _Desired,
        const memory_order _Order = memory_order_seq_cst) noexcept {          _Check_memory_order(_Order);
        const auto _Storage_ptr  = ::std:: addressof(_Storage);
        const auto _Expected_ptr = ::std:: addressof(_Expected);
        bool _Result;
        __builtin_zero_non_value_bits(_Expected_ptr);
        _Guard _Lock{_Spinlock};
        if constexpr (_Might_have_non_value_bits<_TVal>) {
            _Storage_for<_TVal> _Local;
            const auto _Local_ptr = _Local._Ptr();
            :: memcpy(_Local_ptr, _Storage_ptr, sizeof(_TVal));
            __builtin_zero_non_value_bits(_Local_ptr);
            _Result = :: memcmp(_Local_ptr, _Expected_ptr, sizeof(_TVal)) == 0;
        } else {
            _Result = :: memcmp(_Storage_ptr, _Expected_ptr, sizeof(_TVal)) == 0;
        }
        if (_Result) {
            :: memcpy(_Storage_ptr, ::std:: addressof(_Desired), sizeof(_TVal));
        } else {
            :: memcpy(_Expected_ptr, _Storage_ptr, sizeof(_TVal));
        }

        return _Result;
    }

    void wait(_TVal _Expected, memory_order = memory_order_seq_cst) const noexcept {
        const auto _Storage_ptr  = ::std:: addressof(_Storage);
        const auto _Expected_ptr = ::std:: addressof(_Expected);
        for (;;) {
            {
                _Guard _Lock{_Spinlock};
                if (:: memcmp(_Storage_ptr, _Expected_ptr, sizeof(_TVal)) != 0) {
                                         if constexpr (_Might_have_non_value_bits<_TVal>) {
                        _Storage_for<_TVal> _Local;
                        const auto _Local_ptr = _Local._Ptr();
                        :: memcpy(_Local_ptr, _Storage_ptr, sizeof(_TVal));
                        __builtin_zero_non_value_bits(_Local_ptr);
                        __builtin_zero_non_value_bits(_Expected_ptr);
                        if (:: memcmp(_Local_ptr, _Expected_ptr, sizeof(_TVal)) == 0) {
                                                                                      :: memcpy(_Expected_ptr, _Storage_ptr, sizeof(_TVal));
                        } else {
                                                         return;
                        }
                    } else
                    {
                        return;
                    }
                }
            }  
            __std_atomic_wait_indirect(_Storage_ptr, _Expected_ptr, sizeof(_TVal), &_Spinlock,
                &_Atomic_wait_compare_non_lock_free<decltype(_Spinlock)>, _Atomic_wait_no_timeout);
        }
    }

    void notify_one() noexcept {
        __std_atomic_notify_one_indirect(::std:: addressof(_Storage));
    }

    void notify_all() noexcept {
        __std_atomic_notify_all_indirect(::std:: addressof(_Storage));
    }

protected:
    void _Init_spinlock_for_ref() noexcept {
        _Spinlock = __std_atomic_get_mutex(::std:: addressof(_Storage));
    }

private:
         mutable typename _Atomic_storage_types<_Ty>::_Spinlock _Spinlock{};

public:
    _Ty _Storage{};

};

template <class _Ty>
struct _Atomic_storage<_Ty, 1> {  
    using _TVal = remove_reference_t<_Ty>;

    _Atomic_storage() = default;

      constexpr _Atomic_storage(conditional_t<is_reference_v<_Ty>, _Ty, const _TVal> _Value) noexcept
        : _Storage{_Value} {
             }

    void store(const _TVal _Value) noexcept {          const auto _Mem      = _Atomic_address_as<char>(_Storage);
        const char _As_bytes = _Atomic_reinterpret_as<char>(_Value);
        (void) _InterlockedExchange8(_Mem, _As_bytes);
    }

    void store(const _TVal _Value, const memory_order _Order) noexcept {          const auto _Mem      = _Atomic_address_as<char>(_Storage);
        const char _As_bytes = _Atomic_reinterpret_as<char>(_Value);
        switch (_Order) {
        case memory_order_relaxed:
            __iso_volatile_store8(_Mem, _As_bytes);
            return;
        case memory_order_release:
                             __pragma(warning(disable : 4996)) _ReadWriteBarrier() __pragma(warning(pop));
            __iso_volatile_store8(_Mem, _As_bytes);
            return;
        default:
        case memory_order_consume:
        case memory_order_acquire:
        case memory_order_acq_rel:
            ;
                     case memory_order_seq_cst:
            store(_Value);
            return;
        }
    }

     _TVal load() const noexcept {          const auto _Mem = _Atomic_address_as<char>(_Storage);
        char _As_bytes  = __iso_volatile_load8(_Mem);
                         __pragma(warning(disable : 4996)) _ReadWriteBarrier() __pragma(warning(pop));
        return reinterpret_cast<_TVal&>(_As_bytes);
    }

     _TVal load(const memory_order _Order) const noexcept {          const auto _Mem = _Atomic_address_as<char>(_Storage);
        char _As_bytes  = __iso_volatile_load8(_Mem);
        _Load_barrier(_Order);
        return reinterpret_cast<_TVal&>(_As_bytes);
    }

    _TVal exchange(const _TVal _Value, const memory_order _Order = memory_order_seq_cst) noexcept {
                 char _As_bytes;
        _Check_memory_order(_Order);                                       _As_bytes = _InterlockedExchange8(_Atomic_address_as<char>(_Storage)_Atomic_reinterpret_as<char>(_Value));
        return reinterpret_cast<_TVal&>(_As_bytes);
    }

    bool compare_exchange_strong(_TVal& _Expected, const _TVal _Desired,
        const memory_order _Order = memory_order_seq_cst) noexcept {          char _Expected_bytes = _Atomic_reinterpret_as<char>(_Expected);          char _Prev_bytes;

        if constexpr (_Might_have_non_value_bits<_TVal>) {
            _Storage_for<_TVal> _Mask{_Form_mask};
            const char _Mask_val = _Atomic_reinterpret_as<char>(_Mask._Ref());

            for (;;) {
                _Check_memory_order(_Order);                                       _Prev_bytes = _InterlockedCompareExchange8(_Atomic_address_as<char>(_Storage)_Atomic_reinterpret_as<char>(_Desired)_Expected_bytes);
                if (_Prev_bytes == _Expected_bytes) {
                    return true;
                }

                if ((_Prev_bytes ^ _Expected_bytes) & _Mask_val) {
                    reinterpret_cast<char&>(_Expected) = _Prev_bytes;
                    return false;
                }
                _Expected_bytes = (_Expected_bytes & _Mask_val) | (_Prev_bytes & ~_Mask_val);
            }
        }
        _Check_memory_order(_Order);                                       _Prev_bytes = _InterlockedCompareExchange8(_Atomic_address_as<char>(_Storage)_Atomic_reinterpret_as<char>(_Desired)_Expected_bytes);
        if (_Prev_bytes == _Expected_bytes) {
            return true;
        }

        reinterpret_cast<char&>(_Expected) = _Prev_bytes;
        return false;
    }

    void wait(const _TVal _Expected, const memory_order _Order = memory_order_seq_cst) const noexcept {
        _Atomic_wait_direct(this, _Atomic_reinterpret_as<char>(_Expected), _Order);
    }

    void notify_one() noexcept {
        __std_atomic_notify_one_direct(::std:: addressof(_Storage));
    }

    void notify_all() noexcept {
        __std_atomic_notify_all_direct(::std:: addressof(_Storage));
    }

    typename _Atomic_storage_types<_Ty>::_TStorage _Storage;
};

template <class _Ty>
struct _Atomic_storage<_Ty, 2> {  
    using _TVal = remove_reference_t<_Ty>;

    _Atomic_storage() = default;

      constexpr _Atomic_storage(conditional_t<is_reference_v<_Ty>, _Ty, const _TVal> _Value) noexcept
        : _Storage{_Value} {
             }

    void store(const _TVal _Value) noexcept {          const auto _Mem       = _Atomic_address_as<short>(_Storage);
        const short _As_bytes = _Atomic_reinterpret_as<short>(_Value);
        (void) _InterlockedExchange16(_Mem, _As_bytes);
    }

    void store(const _TVal _Value, const memory_order _Order) noexcept {          const auto _Mem       = _Atomic_address_as<short>(_Storage);
        const short _As_bytes = _Atomic_reinterpret_as<short>(_Value);
        switch (_Order) {
        case memory_order_relaxed:
            __iso_volatile_store16(_Mem, _As_bytes);
            return;
        case memory_order_release:
                             __pragma(warning(disable : 4996)) _ReadWriteBarrier() __pragma(warning(pop));
            __iso_volatile_store16(_Mem, _As_bytes);
            return;
        default:
        case memory_order_consume:
        case memory_order_acquire:
        case memory_order_acq_rel:
            ;
                     case memory_order_seq_cst:
            store(_Value);
            return;
        }
    }

     _TVal load() const noexcept {          const auto _Mem = _Atomic_address_as<short>(_Storage);
        short _As_bytes = __iso_volatile_load16(_Mem);
                         __pragma(warning(disable : 4996)) _ReadWriteBarrier() __pragma(warning(pop));
        return reinterpret_cast<_TVal&>(_As_bytes);
    }

     _TVal load(const memory_order _Order) const noexcept {          const auto _Mem = _Atomic_address_as<short>(_Storage);
        short _As_bytes = __iso_volatile_load16(_Mem);
        _Load_barrier(_Order);
        return reinterpret_cast<_TVal&>(_As_bytes);
    }

    _TVal exchange(const _TVal _Value, const memory_order _Order = memory_order_seq_cst) noexcept {
                 short _As_bytes;
        _Check_memory_order(_Order);                                       _As_bytes = _InterlockedExchange16(_Atomic_address_as<short>(_Storage)_Atomic_reinterpret_as<short>(_Value));
        return reinterpret_cast<_TVal&>(_As_bytes);
    }

    bool compare_exchange_strong(_TVal& _Expected, const _TVal _Desired,
        const memory_order _Order = memory_order_seq_cst) noexcept {          short _Expected_bytes = _Atomic_reinterpret_as<short>(_Expected);          short _Prev_bytes;
        if constexpr (_Might_have_non_value_bits<_Ty>) {
            _Storage_for<_TVal> _Mask{_Form_mask};
            const short _Mask_val = _Atomic_reinterpret_as<short>(_Mask._Ref());

            for (;;) {
                _Check_memory_order(_Order);                                       _Prev_bytes = _InterlockedCompareExchange16(_Atomic_address_as<short>(_Storage)_Atomic_reinterpret_as<short>(_Desired)_Expected_bytes);
                if (_Prev_bytes == _Expected_bytes) {
                    return true;
                }

                if ((_Prev_bytes ^ _Expected_bytes) & _Mask_val) {
                    :: memcpy(::std:: addressof(_Expected), &_Prev_bytes, sizeof(_TVal));
                    return false;
                }
                _Expected_bytes = (_Expected_bytes & _Mask_val) | (_Prev_bytes & ~_Mask_val);
            }
        }
        _Check_memory_order(_Order);                                       _Prev_bytes = _InterlockedCompareExchange16(_Atomic_address_as<short>(_Storage)_Atomic_reinterpret_as<short>(_Desired)_Expected_bytes);
        if (_Prev_bytes == _Expected_bytes) {
            return true;
        }

        :: memcpy(::std:: addressof(_Expected), &_Prev_bytes, sizeof(_Ty));
        return false;
    }

    void wait(const _TVal _Expected, const memory_order _Order = memory_order_seq_cst) const noexcept {
        _Atomic_wait_direct(this, _Atomic_reinterpret_as<short>(_Expected), _Order);
    }

    void notify_one() noexcept {
        __std_atomic_notify_one_direct(::std:: addressof(_Storage));
    }

    void notify_all() noexcept {
        __std_atomic_notify_all_direct(::std:: addressof(_Storage));
    }

    typename _Atomic_storage_types<_Ty>::_TStorage _Storage;
};

template <class _Ty>
struct _Atomic_storage<_Ty, 4> {  
    using _TVal = remove_reference_t<_Ty>;

    _Atomic_storage() = default;

      constexpr _Atomic_storage(conditional_t<is_reference_v<_Ty>, _Ty, const _TVal> _Value) noexcept
        : _Storage{_Value} {
             }

    void store(const _TVal _Value) noexcept {          (void) _InterlockedExchange(_Atomic_address_as<long>(_Storage), _Atomic_reinterpret_as<long>(_Value));
    }

    void store(const _TVal _Value, const memory_order _Order) noexcept {          const auto _Mem     = _Atomic_address_as<int>(_Storage);
        const int _As_bytes = _Atomic_reinterpret_as<int>(_Value);
        switch (_Order) {
        case memory_order_relaxed:
            __iso_volatile_store32(_Mem, _As_bytes);
            return;
        case memory_order_release:
                             __pragma(warning(disable : 4996)) _ReadWriteBarrier() __pragma(warning(pop));
            __iso_volatile_store32(_Mem, _As_bytes);
            return;
        default:
        case memory_order_consume:
        case memory_order_acquire:
        case memory_order_acq_rel:
            ;
                     case memory_order_seq_cst:
            store(_Value);
            return;
        }
    }

     _TVal load() const noexcept {          const auto _Mem = _Atomic_address_as<int>(_Storage);
        auto _As_bytes  = __iso_volatile_load32(_Mem);
                         __pragma(warning(disable : 4996)) _ReadWriteBarrier() __pragma(warning(pop));
        return reinterpret_cast<_TVal&>(_As_bytes);
    }

     _TVal load(const memory_order _Order) const noexcept {          const auto _Mem = _Atomic_address_as<int>(_Storage);
        auto _As_bytes  = __iso_volatile_load32(_Mem);
        _Load_barrier(_Order);
        return reinterpret_cast<_TVal&>(_As_bytes);
    }

    _TVal exchange(const _TVal _Value, const memory_order _Order = memory_order_seq_cst) noexcept {
                 long _As_bytes;
        _Check_memory_order(_Order);                                       _As_bytes = _InterlockedExchange(_Atomic_address_as<long>(_Storage)_Atomic_reinterpret_as<long>(_Value));
        return reinterpret_cast<_TVal&>(_As_bytes);
    }

    bool compare_exchange_strong(_TVal& _Expected, const _TVal _Desired,
        const memory_order _Order = memory_order_seq_cst) noexcept {          long _Expected_bytes = _Atomic_reinterpret_as<long>(_Expected);          long _Prev_bytes;
        if constexpr (_Might_have_non_value_bits<_TVal>) {
            _Storage_for<_TVal> _Mask{_Form_mask};
            const long _Mask_val = _Atomic_reinterpret_as<long>(_Mask);

            for (;;) {
                _Check_memory_order(_Order);                                       _Prev_bytes = _InterlockedCompareExchange(_Atomic_address_as<long>(_Storage)_Atomic_reinterpret_as<long>(_Desired)_Expected_bytes);
                if (_Prev_bytes == _Expected_bytes) {
                    return true;
                }

                if ((_Prev_bytes ^ _Expected_bytes) & _Mask_val) {
                    :: memcpy(::std:: addressof(_Expected), &_Prev_bytes, sizeof(_TVal));
                    return false;
                }
                _Expected_bytes = (_Expected_bytes & _Mask_val) | (_Prev_bytes & ~_Mask_val);
            }
        }
        _Check_memory_order(_Order);                                       _Prev_bytes = _InterlockedCompareExchange(_Atomic_address_as<long>(_Storage)_Atomic_reinterpret_as<long>(_Desired)_Expected_bytes);
        if (_Prev_bytes == _Expected_bytes) {
            return true;
        }

        :: memcpy(::std:: addressof(_Expected), &_Prev_bytes, sizeof(_TVal));
        return false;
    }

    void wait(const _TVal _Expected, const memory_order _Order = memory_order_seq_cst) const noexcept {
        _Atomic_wait_direct(this, _Atomic_reinterpret_as<long>(_Expected), _Order);
    }

    void notify_one() noexcept {
        __std_atomic_notify_one_direct(::std:: addressof(_Storage));
    }

    void notify_all() noexcept {
        __std_atomic_notify_all_direct(::std:: addressof(_Storage));
    }

    typename _Atomic_storage_types<_Ty>::_TStorage _Storage;
};

template <class _Ty>
struct _Atomic_storage<_Ty, 8> {  
    using _TVal = remove_reference_t<_Ty>;

    _Atomic_storage() = default;

      constexpr _Atomic_storage(conditional_t<is_reference_v<_Ty>, _Ty, const _TVal> _Value) noexcept
        : _Storage{_Value} {
             }

    void store(const _TVal _Value) noexcept {          const auto _Mem           = _Atomic_address_as<long long>(_Storage);
        const long long _As_bytes = _Atomic_reinterpret_as<long long>(_Value);
        (void) _InterlockedExchange64(_Mem, _As_bytes);
    }

    void store(const _TVal _Value, const memory_order _Order) noexcept {          const auto _Mem           = _Atomic_address_as<long long>(_Storage);
        const long long _As_bytes = _Atomic_reinterpret_as<long long>(_Value);
        switch (_Order) {
        case memory_order_relaxed:
            __iso_volatile_store64(_Mem, _As_bytes);
            return;
        case memory_order_release:
                             __pragma(warning(disable : 4996)) _ReadWriteBarrier() __pragma(warning(pop));
            __iso_volatile_store64(_Mem, _As_bytes);
            return;
        default:
        case memory_order_consume:
        case memory_order_acquire:
        case memory_order_acq_rel:
            ;
                     case memory_order_seq_cst:
            store(_Value);
            return;
        }
    }

     _TVal load() const noexcept {          const auto _Mem = _Atomic_address_as<long long>(_Storage);
        long long _As_bytes;
        _As_bytes = __iso_volatile_load64(_Mem);
                         __pragma(warning(disable : 4996)) _ReadWriteBarrier() __pragma(warning(pop));
        return reinterpret_cast<_TVal&>(_As_bytes);
    }

     _TVal load(const memory_order _Order) const noexcept {          const auto _Mem = _Atomic_address_as<long long>(_Storage);
        long long _As_bytes = __iso_volatile_load64(_Mem);
        _Load_barrier(_Order);
        return reinterpret_cast<_TVal&>(_As_bytes);
    }

    _TVal exchange(const _TVal _Value, const memory_order _Order = memory_order_seq_cst) noexcept {
                 long long _As_bytes;
        _Check_memory_order(_Order);                                       _As_bytes = _InterlockedExchange64(_Atomic_address_as<long long>(_Storage)_Atomic_reinterpret_as<long long>(_Value));
        return reinterpret_cast<_TVal&>(_As_bytes);
    }

    bool compare_exchange_strong(_TVal& _Expected, const _TVal _Desired,
        const memory_order _Order = memory_order_seq_cst) noexcept {          long long _Expected_bytes = _Atomic_reinterpret_as<long long>(_Expected);          long long _Prev_bytes;

        if constexpr (_Might_have_non_value_bits<_TVal>) {
            _Storage_for<_TVal> _Mask{_Form_mask};
            const long long _Mask_val = _Atomic_reinterpret_as<long long>(_Mask);

            for (;;) {
                _Check_memory_order(_Order);                                       _Prev_bytes = _InterlockedCompareExchange64(_Atomic_address_as<long long>(_Storage)_Atomic_reinterpret_as<long long>(_Desired)_Expected_bytes);
                if (_Prev_bytes == _Expected_bytes) {
                    return true;
                }

                if ((_Prev_bytes ^ _Expected_bytes) & _Mask_val) {
                    :: memcpy(::std:: addressof(_Expected), &_Prev_bytes, sizeof(_TVal));
                    return false;
                }
                _Expected_bytes = (_Expected_bytes & _Mask_val) | (_Prev_bytes & ~_Mask_val);
            }
        }
        _Check_memory_order(_Order);                                       _Prev_bytes = _InterlockedCompareExchange64(_Atomic_address_as<long long>(_Storage)_Atomic_reinterpret_as<long long>(_Desired)_Expected_bytes);
        if (_Prev_bytes == _Expected_bytes) {
            return true;
        }

        :: memcpy(::std:: addressof(_Expected), &_Prev_bytes, sizeof(_TVal));
        return false;
    }

    void wait(const _TVal _Expected, const memory_order _Order = memory_order_seq_cst) const noexcept {
        _Atomic_wait_direct(this, _Atomic_reinterpret_as<long long>(_Expected), _Order);
    }

    void notify_one() noexcept {
        __std_atomic_notify_one_direct(::std:: addressof(_Storage));
    }

    void notify_all() noexcept {
        __std_atomic_notify_all_direct(::std:: addressof(_Storage));
    }

    typename _Atomic_storage_types<_Ty>::_TStorage _Storage;
};

template <class _Ty>
struct _Atomic_storage<_Ty&, 16> {           using _TVal = remove_reference_t<_Ty&>;

    _Atomic_storage() = default;

      constexpr _Atomic_storage(conditional_t<is_reference_v<_Ty&>, _Ty&, const _TVal> _Value) noexcept
        : _Storage{_Value} {}  
    void store(const _TVal _Value) noexcept {          (void) exchange(_Value);
    }

    void store(const _TVal _Value, const memory_order _Order) noexcept {          _Check_store_memory_order(_Order);
        (void) exchange(_Value, _Order);
    }

     _TVal load() const noexcept {          long long* const _Storage_ptr = const_cast<long long*>(_Atomic_address_as<const long long>(_Storage));
        _Int128 _Result{};          (void) __std_atomic_compare_exchange_128(_Storage_ptr, 0, 0, &_Result._Low);
        return reinterpret_cast<_TVal&>(_Result);
    }

     _TVal load(const memory_order _Order) const noexcept {          _Check_load_memory_order(_Order);
        return load();
    }

    _TVal exchange(const _TVal _Value) noexcept {          _TVal _Result{_Value};
        while (!compare_exchange_strong(_Result, _Value)) {          }

        return _Result;
    }

    _TVal exchange(const _TVal _Value, const memory_order _Order) noexcept {          _TVal _Result{_Value};
        while (!compare_exchange_strong(_Result, _Value, _Order)) {          }

        return _Result;
    }

    bool compare_exchange_strong(_TVal& _Expected, const _TVal _Desired,
        const memory_order _Order = memory_order_seq_cst) noexcept {          _Int128 _Desired_bytes{};
        :: memcpy(&_Desired_bytes, ::std:: addressof(_Desired), sizeof(_TVal));
        _Int128 _Expected_temp{};
        :: memcpy(&_Expected_temp, ::std:: addressof(_Expected), sizeof(_TVal));
        unsigned char _Result;
        if constexpr (_Might_have_non_value_bits<_TVal>) {
            _Int128 _Expected_originally{};
            :: memcpy(&_Expected_originally, ::std:: addressof(_Expected), sizeof(_TVal));

            _Storage_for<_TVal> _Mask{_Form_mask};
            _Int128 _Mask_val{};
            :: memcpy(&_Mask_val, _Mask._Ptr(), sizeof(_TVal));
            for (;;) {
                (void) _Order;
                _Result = __std_atomic_compare_exchange_128(&reinterpret_cast<long long&>(_Storage), _Desired_bytes._High,
                    _Desired_bytes._Low, &_Expected_temp._Low);
                if (_Result) {
                    return true;
                }

                if (((_Expected_temp._Low ^ _Expected_originally._Low) & _Mask_val._Low) != 0
                    || ((_Expected_temp._High ^ _Expected_originally._High) & _Mask_val._High) != 0) {
                    :: memcpy(::std:: addressof(_Expected), &_Expected_temp, sizeof(_TVal));
                    return false;
                }

                _Expected_temp._Low =
                    (_Expected_originally._Low & _Mask_val._Low) | (_Expected_temp._Low & ~_Mask_val._Low);
                _Expected_temp._High =
                    (_Expected_originally._High & _Mask_val._High) | (_Expected_temp._High & ~_Mask_val._High);
            }
        }
        (void) _Order;
        _Result = __std_atomic_compare_exchange_128(
            &reinterpret_cast<long long&>(_Storage), _Desired_bytes._High, _Desired_bytes._Low, &_Expected_temp._Low);
        if (_Result == 0) {
            :: memcpy(::std:: addressof(_Expected), &_Expected_temp, sizeof(_TVal));
        }

        return _Result != 0;
    }

    void wait(_TVal _Expected, memory_order _Order = memory_order_seq_cst) const noexcept {
        const auto _Storage_ptr  = ::std:: addressof(_Storage);
        const auto _Expected_ptr = ::std:: addressof(_Expected);
        _Int128 _Expected_bytes  = reinterpret_cast<const _Int128&>(_Expected);

        for (;;) {
            const _TVal _Observed   = load(_Order);
            _Int128 _Observed_bytes = reinterpret_cast<const _Int128&>(_Observed);
            if (_Observed_bytes._Low != _Expected_bytes._Low || _Observed_bytes._High != _Expected_bytes._High) {
                if constexpr (_Might_have_non_value_bits<_TVal>) {
                    _Storage_for<_TVal> _Mask{_Form_mask};
                    const _Int128 _Mask_val = reinterpret_cast<const _Int128&>(_Mask._Ref());

                    if (((_Expected_bytes._Low ^ _Observed_bytes._Low) & _Mask_val._Low) == 0
                        && ((_Expected_bytes._High ^ _Observed_bytes._High) & _Mask_val._High) == 0) {
                        _Expected_bytes = _Observed_bytes;
                        continue;
                    }
                }

                return;
            }

            __std_atomic_wait_indirect(_Storage_ptr, _Expected_ptr, sizeof(_TVal), nullptr,
                &_Atomic_wait_compare_16_bytes, _Atomic_wait_no_timeout);
        }
    }

    void notify_one() noexcept {
        __std_atomic_notify_one_indirect(::std:: addressof(_Storage));
    }

    void notify_all() noexcept {
        __std_atomic_notify_all_indirect(::std:: addressof(_Storage));
    }

    struct _Int128 {
        alignas(16) long long _Low;
        long long _High;
    };

    typename _Atomic_storage_types<_Ty&>::_TStorage _Storage;
};

 template <class _Ty, size_t = sizeof(_Ty)>
struct _Atomic_integral;  
template <class _Ty>
struct _Atomic_integral<_Ty, 1> : _Atomic_storage<_Ty> {      using _Base = _Atomic_storage<_Ty>;
    using typename _Base::_TVal;

    using _Base::_Base;

    _TVal fetch_add(const _TVal _Operand, const memory_order _Order = memory_order_seq_cst) noexcept {
        char _Result;
        _Check_memory_order(_Order);                                       _Result = _InterlockedExchangeAdd8(_Atomic_address_as<char>(this->_Storage)static_cast<char>(_Operand));
        return static_cast<_TVal>(_Result);
    }

    _TVal fetch_and(const _TVal _Operand, const memory_order _Order = memory_order_seq_cst) noexcept {
        char _Result;
        _Check_memory_order(_Order);                                       _Result = _InterlockedAnd8(_Atomic_address_as<char>(this->_Storage)static_cast<char>(_Operand));
        return static_cast<_TVal>(_Result);
    }

    _TVal fetch_or(const _TVal _Operand, const memory_order _Order = memory_order_seq_cst) noexcept {
        char _Result;
        _Check_memory_order(_Order);                                       _Result = _InterlockedOr8(_Atomic_address_as<char>(this->_Storage)static_cast<char>(_Operand));
        return static_cast<_TVal>(_Result);
    }

    _TVal fetch_xor(const _TVal _Operand, const memory_order _Order = memory_order_seq_cst) noexcept {
        char _Result;
        _Check_memory_order(_Order);                                       _Result = _InterlockedXor8(_Atomic_address_as<char>(this->_Storage)static_cast<char>(_Operand));
        return static_cast<_TVal>(_Result);
    }

    _TVal operator++(int) noexcept {
        return static_cast<_TVal>(_InterlockedExchangeAdd8(_Atomic_address_as<char>(this->_Storage), 1));
    }

    _TVal operator++() noexcept {
        unsigned char _Before =
            static_cast<unsigned char>(_InterlockedExchangeAdd8(_Atomic_address_as<char>(this->_Storage), 1));
        ++_Before;
        return static_cast<_TVal>(_Before);
    }

    _TVal operator--(int) noexcept {
        return static_cast<_TVal>(_InterlockedExchangeAdd8(_Atomic_address_as<char>(this->_Storage), -1));
    }

    _TVal operator--() noexcept {
        unsigned char _Before =
            static_cast<unsigned char>(_InterlockedExchangeAdd8(_Atomic_address_as<char>(this->_Storage), -1));
        --_Before;
        return static_cast<_TVal>(_Before);
    }
};

template <class _Ty>
struct _Atomic_integral<_Ty, 2> : _Atomic_storage<_Ty> {      using _Base = _Atomic_storage<_Ty>;
    using typename _Base::_TVal;

    using _Base::_Base;

    _TVal fetch_add(const _TVal _Operand, const memory_order _Order = memory_order_seq_cst) noexcept {
        short _Result;
        _Check_memory_order(_Order);                                       _Result = _InterlockedExchangeAdd16(_Atomic_address_as<short>(this->_Storage)static_cast<short>(_Operand));
        return static_cast<_TVal>(_Result);
    }

    _TVal fetch_and(const _TVal _Operand, const memory_order _Order = memory_order_seq_cst) noexcept {
        short _Result;
        _Check_memory_order(_Order);                                       _Result = _InterlockedAnd16(_Atomic_address_as<short>(this->_Storage)static_cast<short>(_Operand));
        return static_cast<_TVal>(_Result);
    }

    _TVal fetch_or(const _TVal _Operand, const memory_order _Order = memory_order_seq_cst) noexcept {
        short _Result;
        _Check_memory_order(_Order);                                       _Result = _InterlockedOr16(_Atomic_address_as<short>(this->_Storage)static_cast<short>(_Operand));
        return static_cast<_TVal>(_Result);
    }

    _TVal fetch_xor(const _TVal _Operand, const memory_order _Order = memory_order_seq_cst) noexcept {
        short _Result;
        _Check_memory_order(_Order);                                       _Result = _InterlockedXor16(_Atomic_address_as<short>(this->_Storage)static_cast<short>(_Operand));
        return static_cast<_TVal>(_Result);
    }

    _TVal operator++(int) noexcept {
        unsigned short _After =
            static_cast<unsigned short>(_InterlockedIncrement16(_Atomic_address_as<short>(this->_Storage)));
        --_After;
        return static_cast<_TVal>(_After);
    }

    _TVal operator++() noexcept {
        return static_cast<_TVal>(_InterlockedIncrement16(_Atomic_address_as<short>(this->_Storage)));
    }

    _TVal operator--(int) noexcept {
        unsigned short _After =
            static_cast<unsigned short>(_InterlockedDecrement16(_Atomic_address_as<short>(this->_Storage)));
        ++_After;
        return static_cast<_TVal>(_After);
    }

    _TVal operator--() noexcept {
        return static_cast<_TVal>(_InterlockedDecrement16(_Atomic_address_as<short>(this->_Storage)));
    }
};

template <class _Ty>
struct _Atomic_integral<_Ty, 4> : _Atomic_storage<_Ty> {      using _Base = _Atomic_storage<_Ty>;
    using typename _Base::_TVal;

    using _Base::_Base;

    _TVal fetch_add(const _TVal _Operand, const memory_order _Order = memory_order_seq_cst) noexcept {
        long _Result;
        _Check_memory_order(_Order);                                       _Result = _InterlockedExchangeAdd(_Atomic_address_as<long>(this->_Storage)static_cast<long>(_Operand));
        return static_cast<_TVal>(_Result);
    }

    _TVal fetch_and(const _TVal _Operand, const memory_order _Order = memory_order_seq_cst) noexcept {
        long _Result;
        _Check_memory_order(_Order);                                       _Result = _InterlockedAnd(_Atomic_address_as<long>(this->_Storage)static_cast<long>(_Operand));
        return static_cast<_TVal>(_Result);
    }

    _TVal fetch_or(const _TVal _Operand, const memory_order _Order = memory_order_seq_cst) noexcept {
        long _Result;
        _Check_memory_order(_Order);                                       _Result = _InterlockedOr(_Atomic_address_as<long>(this->_Storage)static_cast<long>(_Operand));
        return static_cast<_TVal>(_Result);
    }

    _TVal fetch_xor(const _TVal _Operand, const memory_order _Order = memory_order_seq_cst) noexcept {
        long _Result;
        _Check_memory_order(_Order);                                       _Result = _InterlockedXor(_Atomic_address_as<long>(this->_Storage)static_cast<long>(_Operand));
        return static_cast<_TVal>(_Result);
    }

    _TVal operator++(int) noexcept {
        unsigned long _After =
            static_cast<unsigned long>(_InterlockedIncrement(_Atomic_address_as<long>(this->_Storage)));
        --_After;
        return static_cast<_TVal>(_After);
    }

    _TVal operator++() noexcept {
        return static_cast<_TVal>(_InterlockedIncrement(_Atomic_address_as<long>(this->_Storage)));
    }

    _TVal operator--(int) noexcept {
        unsigned long _After =
            static_cast<unsigned long>(_InterlockedDecrement(_Atomic_address_as<long>(this->_Storage)));
        ++_After;
        return static_cast<_TVal>(_After);
    }

    _TVal operator--() noexcept {
        return static_cast<_TVal>(_InterlockedDecrement(_Atomic_address_as<long>(this->_Storage)));
    }
};

template <class _Ty>
struct _Atomic_integral<_Ty, 8> : _Atomic_storage<_Ty> {      using _Base = _Atomic_storage<_Ty>;
    using typename _Base::_TVal;

    using _Base::_Base;

    _TVal fetch_add(const _TVal _Operand, const memory_order _Order = memory_order_seq_cst) noexcept {
        long long _Result;
        _Check_memory_order(_Order);                                       _Result = _InterlockedExchangeAdd64(_Atomic_address_as<long long>(this->_Storage)static_cast<long long>(_Operand));
        return static_cast<_TVal>(_Result);
    }

    _TVal fetch_and(const _TVal _Operand, const memory_order _Order = memory_order_seq_cst) noexcept {
        long long _Result;
        _Check_memory_order(_Order);                                       _Result = _InterlockedAnd64(_Atomic_address_as<long long>(this->_Storage)static_cast<long long>(_Operand));
        return static_cast<_TVal>(_Result);
    }

    _TVal fetch_or(const _TVal _Operand, const memory_order _Order = memory_order_seq_cst) noexcept {
        long long _Result;
        _Check_memory_order(_Order);                                       _Result = _InterlockedOr64(_Atomic_address_as<long long>(this->_Storage)static_cast<long long>(_Operand));
        return static_cast<_TVal>(_Result);
    }

    _TVal fetch_xor(const _TVal _Operand, const memory_order _Order = memory_order_seq_cst) noexcept {
        long long _Result;
        _Check_memory_order(_Order);                                       _Result = _InterlockedXor64(_Atomic_address_as<long long>(this->_Storage)static_cast<long long>(_Operand));
        return static_cast<_TVal>(_Result);
    }

    _TVal operator++(int) noexcept {
        unsigned long long _After =
            static_cast<unsigned long long>(_InterlockedIncrement64(_Atomic_address_as<long long>(this->_Storage)));
        --_After;
        return static_cast<_TVal>(_After);
    }

    _TVal operator++() noexcept {
        return static_cast<_TVal>(_InterlockedIncrement64(_Atomic_address_as<long long>(this->_Storage)));
    }

    _TVal operator--(int) noexcept {
        unsigned long long _After =
            static_cast<unsigned long long>(_InterlockedDecrement64(_Atomic_address_as<long long>(this->_Storage)));
        ++_After;
        return static_cast<_TVal>(_After);
    }

    _TVal operator--() noexcept {
        return static_cast<_TVal>(_InterlockedDecrement64(_Atomic_address_as<long long>(this->_Storage)));
    }
};

template <size_t _TypeSize>
inline constexpr bool _Is_always_lock_free = _TypeSize <= 8 && (_TypeSize & (_TypeSize - 1)) == 0;

template <class _Ty, bool _Is_lock_free = _Is_always_lock_free<sizeof(_Ty)>>
inline constexpr bool _Deprecate_non_lock_free_volatile = true;

template <class _Ty>
[[deprecated("warning STL4030: Some operations on volatile-qualified types in the STL are deprecated in C++20. You can define _SILENCE_CXX20_VOLATILE_DEPRECATION_WARNING or _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] inline constexpr bool _Deprecate_non_lock_free_volatile<_Ty, false> = true;

 template <class _Ty>
struct _Atomic_integral_facade : _Atomic_integral<_Ty> {
         using _Base           = _Atomic_integral<_Ty>;
    using difference_type = _Ty;

    using _Base::_Base;

     
                   using _Base::fetch_add;
    _Ty fetch_add(const _Ty _Operand) volatile noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_add(_Operand);
    }

    _Ty fetch_add(const _Ty _Operand, const memory_order _Order) volatile noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_add(_Operand, _Order);
    }

     static _Ty _Negate(const _Ty _Value) noexcept {          return static_cast<_Ty>(0U - static_cast<make_unsigned_t<_Ty>>(_Value));
    }

    _Ty fetch_sub(const _Ty _Operand) noexcept {
        return fetch_add(_Negate(_Operand));
    }

    _Ty fetch_sub(const _Ty _Operand) volatile noexcept {
        return fetch_add(_Negate(_Operand));
    }

    _Ty fetch_sub(const _Ty _Operand, const memory_order _Order) noexcept {
        return fetch_add(_Negate(_Operand), _Order);
    }

    _Ty fetch_sub(const _Ty _Operand, const memory_order _Order) volatile noexcept {
        return fetch_add(_Negate(_Operand), _Order);
    }

    using _Base::fetch_and;
    _Ty fetch_and(const _Ty _Operand) volatile noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_and(_Operand);
    }

    _Ty fetch_and(const _Ty _Operand, const memory_order _Order) volatile noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_and(_Operand, _Order);
    }

    using _Base::fetch_or;
    _Ty fetch_or(const _Ty _Operand) volatile noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_or(_Operand);
    }

    _Ty fetch_or(const _Ty _Operand, const memory_order _Order) volatile noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_or(_Operand, _Order);
    }

    using _Base::fetch_xor;
    _Ty fetch_xor(const _Ty _Operand) volatile noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_xor(_Operand);
    }

    _Ty fetch_xor(const _Ty _Operand, const memory_order _Order) volatile noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_xor(_Operand, _Order);
    }

    using _Base::operator++;
    _Ty operator++(int) volatile noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::operator++(0);
    }

    _Ty operator++() volatile noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::operator++();
    }

    using _Base::operator--;
    _Ty operator--(int) volatile noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::operator--(0);
    }

    _Ty operator--() volatile noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::operator--();
    }

    _Ty operator+=(const _Ty _Operand) noexcept {
        return static_cast<_Ty>(this->_Base::fetch_add(_Operand) + _Operand);
    }

    _Ty operator+=(const _Ty _Operand) volatile noexcept {
        return static_cast<_Ty>(const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_add(_Operand) + _Operand);
    }

    _Ty operator-=(const _Ty _Operand) noexcept {
        return static_cast<_Ty>(fetch_sub(_Operand) - _Operand);
    }

    _Ty operator-=(const _Ty _Operand) volatile noexcept {
        return static_cast<_Ty>(const_cast<_Atomic_integral_facade*>(this)->fetch_sub(_Operand) - _Operand);
    }

    _Ty operator&=(const _Ty _Operand) noexcept {
        return static_cast<_Ty>(this->_Base::fetch_and(_Operand) & _Operand);
    }

    _Ty operator&=(const _Ty _Operand) volatile noexcept {
        return static_cast<_Ty>(const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_and(_Operand) & _Operand);
    }

    _Ty operator|=(const _Ty _Operand) noexcept {
        return static_cast<_Ty>(this->_Base::fetch_or(_Operand) | _Operand);
    }

    _Ty operator|=(const _Ty _Operand) volatile noexcept {
        return static_cast<_Ty>(const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_or(_Operand) | _Operand);
    }

    _Ty operator^=(const _Ty _Operand) noexcept {
        return static_cast<_Ty>(this->_Base::fetch_xor(_Operand) ^ _Operand);
    }

    _Ty operator^=(const _Ty _Operand) volatile noexcept {
        return static_cast<_Ty>(const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_xor(_Operand) ^ _Operand);
    }
};

 template <class _Ty>
struct _Atomic_integral_facade<_Ty&> : _Atomic_integral<_Ty&> {
         using _Base           = _Atomic_integral<_Ty&>;
    using difference_type = _Ty;

    using _Base::_Base;

     static _Ty _Negate(const _Ty _Value) noexcept {          return static_cast<_Ty>(0U - static_cast<make_unsigned_t<_Ty>>(_Value));
    }

    _Ty fetch_add(const _Ty _Operand) const noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_add(_Operand);
    }

    _Ty fetch_add(const _Ty _Operand, const memory_order _Order) const noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_add(_Operand, _Order);
    }

    _Ty fetch_sub(const _Ty _Operand) const noexcept {
        return fetch_add(_Negate(_Operand));
    }

    _Ty fetch_sub(const _Ty _Operand, const memory_order _Order) const noexcept {
        return fetch_add(_Negate(_Operand), _Order);
    }

    _Ty operator++(int) const noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::operator++(0);
    }

    _Ty operator++() const noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::operator++();
    }

    _Ty operator--(int) const noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::operator--(0);
    }

    _Ty operator--() const noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::operator--();
    }

    _Ty operator+=(const _Ty _Operand) const noexcept {
        return static_cast<_Ty>(fetch_add(_Operand) + _Operand);
    }

    _Ty operator-=(const _Ty _Operand) const noexcept {
        return static_cast<_Ty>(fetch_sub(_Operand) - _Operand);
    }

    _Ty fetch_and(const _Ty _Operand) const noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_and(_Operand);
    }

    _Ty fetch_and(const _Ty _Operand, const memory_order _Order) const noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_and(_Operand, _Order);
    }

    _Ty fetch_or(const _Ty _Operand) const noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_or(_Operand);
    }

    _Ty fetch_or(const _Ty _Operand, const memory_order _Order) const noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_or(_Operand, _Order);
    }

    _Ty fetch_xor(const _Ty _Operand) const noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_xor(_Operand);
    }

    _Ty fetch_xor(const _Ty _Operand, const memory_order _Order) const noexcept {
        return const_cast<_Atomic_integral_facade*>(this)->_Base::fetch_xor(_Operand, _Order);
    }

    _Ty operator&=(const _Ty _Operand) const noexcept {
        return static_cast<_Ty>(fetch_and(_Operand) & _Operand);
    }

    _Ty operator|=(const _Ty _Operand) const noexcept {
        return static_cast<_Ty>(fetch_or(_Operand) | _Operand);
    }

    _Ty operator^=(const _Ty _Operand) const noexcept {
        return static_cast<_Ty>(fetch_xor(_Operand) ^ _Operand);
    }
};

template <class _Ty>
struct _Atomic_floating : _Atomic_storage<_Ty> {
         using _Base           = _Atomic_storage<_Ty>;
    using difference_type = _Ty;

    using _Base::_Base;

    _Ty fetch_add(const _Ty _Operand, const memory_order _Order = memory_order_seq_cst) noexcept {
        _Ty _Temp{this->load(memory_order_relaxed)};
        while (!this->compare_exchange_strong(_Temp, _Temp + _Operand, _Order)) {          }

        return _Temp;
    }

     
                   _Ty fetch_add(const _Ty _Operand, const memory_order _Order = memory_order_seq_cst) volatile noexcept {
        return const_cast<_Atomic_floating*>(this)->fetch_add(_Operand, _Order);
    }

    _Ty fetch_sub(const _Ty _Operand, const memory_order _Order = memory_order_seq_cst) noexcept {
        _Ty _Temp{this->load(memory_order_relaxed)};
        while (!this->compare_exchange_strong(_Temp, _Temp - _Operand, _Order)) {          }

        return _Temp;
    }

    _Ty fetch_sub(const _Ty _Operand, const memory_order _Order = memory_order_seq_cst) volatile noexcept {
        return const_cast<_Atomic_floating*>(this)->fetch_sub(_Operand, _Order);
    }

    _Ty operator+=(const _Ty _Operand) noexcept {
        return fetch_add(_Operand) + _Operand;
    }

    _Ty operator+=(const _Ty _Operand) volatile noexcept {
        return const_cast<_Atomic_floating*>(this)->fetch_add(_Operand) + _Operand;
    }

    _Ty operator-=(const _Ty _Operand) noexcept {
        return fetch_sub(_Operand) - _Operand;
    }

    _Ty operator-=(const _Ty _Operand) volatile noexcept {
        return const_cast<_Atomic_floating*>(this)->fetch_sub(_Operand) - _Operand;
    }
};

template <class _Ty>
struct _Atomic_floating<_Ty&> : _Atomic_storage<_Ty&> {
         using _Base           = _Atomic_storage<_Ty&>;
    using difference_type = _Ty;

    using _Base::_Base;

    _Ty fetch_add(const _Ty _Operand, const memory_order _Order = memory_order_seq_cst) const noexcept {
        _Ty _Temp{this->load(memory_order_relaxed)};
        while (!const_cast<_Atomic_floating*>(this)->_Base::compare_exchange_strong(
            _Temp, _Temp + _Operand, _Order)) {          }

        return _Temp;
    }

    _Ty fetch_sub(const _Ty _Operand, const memory_order _Order = memory_order_seq_cst) const noexcept {
        _Ty _Temp{this->load(memory_order_relaxed)};
        while (!const_cast<_Atomic_floating*>(this)->_Base::compare_exchange_strong(
            _Temp, _Temp - _Operand, _Order)) {          }

        return _Temp;
    }

    _Ty operator+=(const _Ty _Operand) const noexcept {
        return fetch_add(_Operand) + _Operand;
    }

    _Ty operator-=(const _Ty _Operand) const noexcept {
        return fetch_sub(_Operand) - _Operand;
    }
};

 template <class _Ty>
struct _Atomic_pointer : _Atomic_storage<_Ty> {
    using _Base           = _Atomic_storage<_Ty>;
    using difference_type = ptrdiff_t;

    using _Base::_Base;

    _Ty fetch_add(const ptrdiff_t _Diff, const memory_order _Order = memory_order_seq_cst) noexcept {
        const ptrdiff_t _Shift_bytes =
            static_cast<ptrdiff_t>(static_cast<size_t>(_Diff) * sizeof(remove_pointer_t<_Ty>));
        ptrdiff_t _Result;
        _Check_memory_order(_Order);                                       _Result = _InterlockedExchangeAdd64(_Atomic_address_as<long long>(this->_Storage)_Shift_bytes);
        return reinterpret_cast<_Ty>(_Result);
    }

     
    _Ty fetch_add(const ptrdiff_t _Diff) volatile noexcept {
        return const_cast<_Atomic_pointer*>(this)->fetch_add(_Diff);
    }

    _Ty fetch_add(const ptrdiff_t _Diff, const memory_order _Order) volatile noexcept {
        return const_cast<_Atomic_pointer*>(this)->fetch_add(_Diff, _Order);
    }

    _Ty fetch_sub(const ptrdiff_t _Diff) volatile noexcept {
        return fetch_add(static_cast<ptrdiff_t>(0 - static_cast<size_t>(_Diff)));
    }

    _Ty fetch_sub(const ptrdiff_t _Diff) noexcept {
        return fetch_add(static_cast<ptrdiff_t>(0 - static_cast<size_t>(_Diff)));
    }

    _Ty fetch_sub(const ptrdiff_t _Diff, const memory_order _Order) volatile noexcept {
        return fetch_add(static_cast<ptrdiff_t>(0 - static_cast<size_t>(_Diff)), _Order);
    }

    _Ty fetch_sub(const ptrdiff_t _Diff, const memory_order _Order) noexcept {
        return fetch_add(static_cast<ptrdiff_t>(0 - static_cast<size_t>(_Diff)), _Order);
    }

    _Ty operator++(int) volatile noexcept {
        return fetch_add(1);
    }

    _Ty operator++(int) noexcept {
        return fetch_add(1);
    }

    _Ty operator++() volatile noexcept {
        return fetch_add(1) + 1;
    }

    _Ty operator++() noexcept {
        return fetch_add(1) + 1;
    }

    _Ty operator--(int) volatile noexcept {
        return fetch_add(-1);
    }

    _Ty operator--(int) noexcept {
        return fetch_add(-1);
    }

    _Ty operator--() volatile noexcept {
        return fetch_add(-1) - 1;
    }

    _Ty operator--() noexcept {
        return fetch_add(-1) - 1;
    }

    _Ty operator+=(const ptrdiff_t _Diff) volatile noexcept {
        return fetch_add(_Diff) + _Diff;
    }

    _Ty operator+=(const ptrdiff_t _Diff) noexcept {
        return fetch_add(_Diff) + _Diff;
    }

    _Ty operator-=(const ptrdiff_t _Diff) volatile noexcept {
        return fetch_add(static_cast<ptrdiff_t>(0 - static_cast<size_t>(_Diff))) - _Diff;
    }

    _Ty operator-=(const ptrdiff_t _Diff) noexcept {
        return fetch_add(static_cast<ptrdiff_t>(0 - static_cast<size_t>(_Diff))) - _Diff;
    }
};


 template <class _Ty>
struct _Atomic_pointer<_Ty&> : _Atomic_storage<_Ty&> {
    using _Base           = _Atomic_storage<_Ty&>;
    using difference_type = ptrdiff_t;

    using _Base::_Base;

    _Ty fetch_add(const ptrdiff_t _Diff, const memory_order _Order = memory_order_seq_cst) const noexcept {
        const ptrdiff_t _Shift_bytes =
            static_cast<ptrdiff_t>(static_cast<size_t>(_Diff) * sizeof(remove_pointer_t<_Ty>));
        ptrdiff_t _Result;
        _Check_memory_order(_Order);                                       _Result = _InterlockedExchangeAdd64(_Atomic_address_as<long long>(this->_Storage)_Shift_bytes);
        return reinterpret_cast<_Ty>(_Result);
    }

    _Ty fetch_sub(const ptrdiff_t _Diff) const noexcept {
        return fetch_add(static_cast<ptrdiff_t>(0 - static_cast<size_t>(_Diff)));
    }

    _Ty fetch_sub(const ptrdiff_t _Diff, const memory_order _Order) const noexcept {
        return fetch_add(static_cast<ptrdiff_t>(0 - static_cast<size_t>(_Diff)), _Order);
    }

    _Ty operator++(int) const noexcept {
        return fetch_add(1);
    }

    _Ty operator++() const noexcept {
        return fetch_add(1) + 1;
    }

    _Ty operator--(int) const noexcept {
        return fetch_add(-1);
    }

    _Ty operator--() const noexcept {
        return fetch_add(-1) - 1;
    }

    _Ty operator+=(const ptrdiff_t _Diff) const noexcept {
        return fetch_add(_Diff) + _Diff;
    }

    _Ty operator-=(const ptrdiff_t _Diff) const noexcept {
        return fetch_add(static_cast<ptrdiff_t>(0 - static_cast<size_t>(_Diff))) - _Diff;
    }
};


 
template <class _TVal, class _Ty = _TVal>
using _Choose_atomic_base2_t =
    typename _Select<is_integral_v<_TVal> && !is_same_v<bool, _TVal>>::template _Apply<_Atomic_integral_facade<_Ty>,
        typename _Select<is_pointer_v<_TVal> && is_object_v<remove_pointer_t<_TVal>>>::template _Apply<
            _Atomic_pointer<_Ty>, _Atomic_storage<_Ty>>>;

template <class _TVal, class _Ty = _TVal>
using _Choose_atomic_base_t = typename _Select<is_floating_point_v<_TVal>>::template _Apply<_Atomic_floating<_Ty>,
    _Choose_atomic_base2_t<_TVal, _Ty>>;

template <class _Ty>
struct atomic : _Choose_atomic_base_t<_Ty> {  private:
    using _Base = _Choose_atomic_base_t<_Ty>;

public:
         static_assert(is_trivially_copyable_v<_Ty> && is_copy_constructible_v<_Ty> && is_move_constructible_v<_Ty>
        && is_copy_assignable_v<_Ty> && is_move_assignable_v<_Ty>,
        "atomic<T> requires T to be trivially copyable, copy constructible, move constructible, copy assignable, and move assignable.");
     
    using value_type = _Ty;

    using _Base::_Base;

    constexpr atomic() noexcept(is_nothrow_default_constructible_v<_Ty>) : _Base() {}

    atomic(const atomic&) = delete;
    atomic& operator=(const atomic&) = delete;

    static constexpr bool is_always_lock_free = _Is_always_lock_free<sizeof(_Ty)>;

     bool is_lock_free() const volatile noexcept {
        constexpr bool _Result = sizeof(_Ty) <= 8 && (sizeof(_Ty) & sizeof(_Ty) - 1) == 0;
        return _Result;
    }


     bool is_lock_free() const noexcept {
        return static_cast<const volatile atomic*>(this)->is_lock_free();
    }

    _Ty operator=(const _Ty _Value) volatile noexcept {
        static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
        this->store(_Value);
        return _Value;
    }

    _Ty operator=(const _Ty _Value) noexcept {
        this->store(_Value);
        return _Value;
    }

                             using _Base::store;
    void store(const _Ty _Value) volatile noexcept {
        static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
        const_cast<atomic*>(this)->_Base::store(_Value);
    }

    void store(const _Ty _Value, const memory_order _Order) volatile noexcept {
        static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
        const_cast<atomic*>(this)->_Base::store(_Value, _Order);
    }

    using _Base::load;
     _Ty load() const volatile noexcept {
        static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
        return const_cast<const atomic*>(this)->_Base::load();
    }

     _Ty load(const memory_order _Order) const volatile noexcept {
        static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
        return const_cast<const atomic*>(this)->_Base::load(_Order);
    }

    using _Base::exchange;
    _Ty exchange(const _Ty _Value) volatile noexcept {
        static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
        return const_cast<atomic*>(this)->_Base::exchange(_Value);
    }

    _Ty exchange(const _Ty _Value, const memory_order _Order) volatile noexcept {
        static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
        return const_cast<atomic*>(this)->_Base::exchange(_Value, _Order);
    }

    using _Base::compare_exchange_strong;
    bool compare_exchange_strong(_Ty& _Expected, const _Ty _Desired) volatile noexcept {
        static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
        return const_cast<atomic*>(this)->_Base::compare_exchange_strong(_Expected, _Desired);
    }

    bool compare_exchange_strong(_Ty& _Expected, const _Ty _Desired, const memory_order _Order) volatile noexcept {
        static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
        return const_cast<atomic*>(this)->_Base::compare_exchange_strong(_Expected, _Desired, _Order);
    }

    bool compare_exchange_strong(_Ty& _Expected, const _Ty _Desired, const memory_order _Success,
        const memory_order _Failure) volatile noexcept {
        static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
        return this->compare_exchange_strong(_Expected, _Desired, _Combine_cas_memory_orders(_Success, _Failure));
    }

    bool compare_exchange_strong(
        _Ty& _Expected, const _Ty _Desired, const memory_order _Success, const memory_order _Failure) noexcept {
        return this->compare_exchange_strong(_Expected, _Desired, _Combine_cas_memory_orders(_Success, _Failure));
    }

    bool compare_exchange_weak(_Ty& _Expected, const _Ty _Desired) volatile noexcept {
                 static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
        return this->compare_exchange_strong(_Expected, _Desired);
    }

    bool compare_exchange_weak(_Ty& _Expected, const _Ty _Desired) noexcept {
        return this->compare_exchange_strong(_Expected, _Desired);
    }

    bool compare_exchange_weak(_Ty& _Expected, const _Ty _Desired, const memory_order _Order) volatile noexcept {
        static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
        return this->compare_exchange_strong(_Expected, _Desired, _Order);
    }

    bool compare_exchange_weak(_Ty& _Expected, const _Ty _Desired, const memory_order _Order) noexcept {
        return this->compare_exchange_strong(_Expected, _Desired, _Order);
    }

    bool compare_exchange_weak(_Ty& _Expected, const _Ty _Desired, const memory_order _Success,
        const memory_order _Failure) volatile noexcept {
        static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
        return this->compare_exchange_strong(_Expected, _Desired, _Combine_cas_memory_orders(_Success, _Failure));
    }

    bool compare_exchange_weak(
        _Ty& _Expected, const _Ty _Desired, const memory_order _Success, const memory_order _Failure) noexcept {
        return this->compare_exchange_strong(_Expected, _Desired, _Combine_cas_memory_orders(_Success, _Failure));
    }

    using _Base::wait;
    void wait(const _Ty _Expected, const memory_order _Order = memory_order_seq_cst) const volatile noexcept {
        const_cast<const atomic*>(this)->_Base::wait(_Expected, _Order);
    }

    using _Base::notify_one;
    void notify_one() volatile noexcept {
        const_cast<atomic*>(this)->_Base::notify_one();
    }

    using _Base::notify_all;
    void notify_all() volatile noexcept {
        const_cast<atomic*>(this)->_Base::notify_all();
    }

    operator _Ty() const volatile noexcept {
        static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
        return this->load();
    }

    operator _Ty() const noexcept {
        return this->load();
    }
};

template <class _Ty>
atomic(_Ty) -> atomic<_Ty>;

template <class _Ty>
struct atomic_ref : _Choose_atomic_base_t<_Ty, _Ty&> {  private:
    using _Base = _Choose_atomic_base_t<_Ty, _Ty&>;

public:
    static_assert(is_trivially_copyable_v<_Ty>, "atomic_ref<T> requires T to be trivially copyable.");

    using value_type = _Ty;

    explicit atomic_ref(_Ty& _Value) noexcept   : _Base(_Value) {
        if constexpr (_Is_potentially_lock_free) {
            _Check_alignment(_Value);
        } else {
            this->_Init_spinlock_for_ref();
        }
    }

    atomic_ref(const atomic_ref&) noexcept = default;

    atomic_ref& operator=(const atomic_ref&) = delete;

    static constexpr bool is_always_lock_free = _Is_always_lock_free<sizeof(_Ty)>;

    static constexpr bool _Is_potentially_lock_free =
        sizeof(_Ty) <= 2 * sizeof(void*) && (sizeof(_Ty) & (sizeof(_Ty) - 1)) == 0;

    static constexpr size_t required_alignment = _Is_potentially_lock_free ? sizeof(_Ty) : alignof(_Ty);

     bool is_lock_free() const noexcept {
        if constexpr (is_always_lock_free) {
            return true;
        } else {
            return __std_atomic_has_cmpxchg16b() != 0;
        }
    }

    void store(const _Ty _Value) const noexcept {
        const_cast<atomic_ref*>(this)->_Base::store(_Value);
    }

    void store(const _Ty _Value, const memory_order _Order) const noexcept {
        const_cast<atomic_ref*>(this)->_Base::store(_Value, _Order);
    }

    _Ty operator=(const _Ty _Value) const noexcept {
        store(_Value);
        return _Value;
    }

    _Ty exchange(const _Ty _Value) const noexcept {
        return const_cast<atomic_ref*>(this)->_Base::exchange(_Value);
    }

    _Ty exchange(const _Ty _Value, const memory_order _Order) const noexcept {
        return const_cast<atomic_ref*>(this)->_Base::exchange(_Value, _Order);
    }

    bool compare_exchange_strong(_Ty& _Expected, const _Ty _Desired) const noexcept {
        return const_cast<atomic_ref*>(this)->_Base::compare_exchange_strong(_Expected, _Desired);
    }

    bool compare_exchange_strong(_Ty& _Expected, const _Ty _Desired, const memory_order _Order) const noexcept {
        return const_cast<atomic_ref*>(this)->_Base::compare_exchange_strong(_Expected, _Desired, _Order);
    }

    bool compare_exchange_strong(
        _Ty& _Expected, const _Ty _Desired, const memory_order _Success, const memory_order _Failure) const noexcept {
        return compare_exchange_strong(_Expected, _Desired, _Combine_cas_memory_orders(_Success, _Failure));
    }

    bool compare_exchange_weak(_Ty& _Expected, const _Ty _Desired) const noexcept {
        return compare_exchange_strong(_Expected, _Desired);
    }

    bool compare_exchange_weak(_Ty& _Expected, const _Ty _Desired, const memory_order _Order) const noexcept {
        return compare_exchange_strong(_Expected, _Desired, _Order);
    }

    bool compare_exchange_weak(
        _Ty& _Expected, const _Ty _Desired, const memory_order _Success, const memory_order _Failure) const noexcept {
        return compare_exchange_strong(_Expected, _Desired, _Combine_cas_memory_orders(_Success, _Failure));
    }

    operator _Ty() const noexcept {
        return this->load();
    }

    void notify_one() const noexcept {
        const_cast<atomic_ref*>(this)->_Base::notify_one();
    }

    void notify_all() const noexcept {
        const_cast<atomic_ref*>(this)->_Base::notify_all();
    }

private:
    static void _Check_alignment([[maybe_unused]] const _Ty& _Value) {
        ;
    }
};

 template <class _Ty>
 bool atomic_is_lock_free(const volatile atomic<_Ty>* _Mem) noexcept {
    return _Mem->is_lock_free();
}

template <class _Ty>
 bool atomic_is_lock_free(const atomic<_Ty>* _Mem) noexcept {
    return _Mem->is_lock_free();
}

template <class _Ty>
void atomic_store(volatile atomic<_Ty>* const _Mem, const _Identity_t<_Ty> _Value) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    _Mem->store(_Value);
}

template <class _Ty>
void atomic_store(atomic<_Ty>* const _Mem, const _Identity_t<_Ty> _Value) noexcept {
    _Mem->store(_Value);
}

template <class _Ty>
void atomic_store_explicit(
    volatile atomic<_Ty>* const _Mem, const _Identity_t<_Ty> _Value, const memory_order _Order) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    _Mem->store(_Value, _Order);
}

template <class _Ty>
void atomic_store_explicit(atomic<_Ty>* const _Mem, const _Identity_t<_Ty> _Value, const memory_order _Order) noexcept {
    _Mem->store(_Value, _Order);
}

template <class _Ty>
[[deprecated("warning STL4028: std::atomic_init() overloads are deprecated in C++20. The constructors of std::atomic provide equivalent functionality. You can define _SILENCE_CXX20_ATOMIC_INIT_DEPRECATION_WARNING or _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] void atomic_init(
    volatile atomic<_Ty>* const _Mem, const typename atomic<_Ty>::value_type _Value) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    ::std:: atomic_store_explicit(_Mem, _Value, memory_order_relaxed);
}

template <class _Ty>
[[deprecated("warning STL4028: std::atomic_init() overloads are deprecated in C++20. The constructors of std::atomic provide equivalent functionality. You can define _SILENCE_CXX20_ATOMIC_INIT_DEPRECATION_WARNING or _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS to acknowledge that you have received this warning.")]] void atomic_init(
    atomic<_Ty>* const _Mem, const typename atomic<_Ty>::value_type _Value) noexcept {
    ::std:: atomic_store_explicit(_Mem, _Value, memory_order_relaxed);
}

template <class _Ty>
 _Ty atomic_load(const volatile atomic<_Ty>* const _Mem) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    return _Mem->load();
}

template <class _Ty>
 _Ty atomic_load(const atomic<_Ty>* const _Mem) noexcept {
    return _Mem->load();
}

template <class _Ty>
 _Ty atomic_load_explicit(const volatile atomic<_Ty>* const _Mem, const memory_order _Order) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    return _Mem->load(_Order);
}

template <class _Ty>
 _Ty atomic_load_explicit(const atomic<_Ty>* const _Mem, const memory_order _Order) noexcept {
    return _Mem->load(_Order);
}

template <class _Ty>
_Ty atomic_exchange(volatile atomic<_Ty>* const _Mem, const _Identity_t<_Ty> _Value) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    return _Mem->exchange(_Value);
}

template <class _Ty>
_Ty atomic_exchange(atomic<_Ty>* const _Mem, const _Identity_t<_Ty> _Value) noexcept {
    return _Mem->exchange(_Value);
}

template <class _Ty>
_Ty atomic_exchange_explicit(
    volatile atomic<_Ty>* const _Mem, const _Identity_t<_Ty> _Value, const memory_order _Order) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    return _Mem->exchange(_Value, _Order);
}

template <class _Ty>
_Ty atomic_exchange_explicit(
    atomic<_Ty>* const _Mem, const _Identity_t<_Ty> _Value, const memory_order _Order) noexcept {
    return _Mem->exchange(_Value, _Order);
}

template <class _Ty>
bool atomic_compare_exchange_strong(
    volatile atomic<_Ty>* const _Mem, _Identity_t<_Ty>* const _Expected, const _Identity_t<_Ty> _Desired) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    return _Mem->compare_exchange_strong(*_Expected, _Desired);
}

template <class _Ty>
bool atomic_compare_exchange_strong(
    atomic<_Ty>* const _Mem, _Identity_t<_Ty>* const _Expected, const _Identity_t<_Ty> _Desired) noexcept {
    return _Mem->compare_exchange_strong(*_Expected, _Desired);
}

template <class _Ty>
bool atomic_compare_exchange_strong_explicit(volatile atomic<_Ty>* const _Mem, _Identity_t<_Ty>* const _Expected,
    const _Identity_t<_Ty> _Desired, const memory_order _Success, const memory_order _Failure) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    return _Mem->compare_exchange_strong(*_Expected, _Desired, _Combine_cas_memory_orders(_Success, _Failure));
}

template <class _Ty>
bool atomic_compare_exchange_strong_explicit(atomic<_Ty>* const _Mem, _Identity_t<_Ty>* const _Expected,
    const _Identity_t<_Ty> _Desired, const memory_order _Success, const memory_order _Failure) noexcept {
    return _Mem->compare_exchange_strong(*_Expected, _Desired, _Combine_cas_memory_orders(_Success, _Failure));
}

template <class _Ty>
bool atomic_compare_exchange_weak(
    volatile atomic<_Ty>* const _Mem, _Identity_t<_Ty>* const _Expected, const _Identity_t<_Ty> _Desired) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    return _Mem->compare_exchange_strong(*_Expected, _Desired);
}

template <class _Ty>
bool atomic_compare_exchange_weak(
    atomic<_Ty>* const _Mem, _Identity_t<_Ty>* const _Expected, const _Identity_t<_Ty> _Desired) noexcept {
    return _Mem->compare_exchange_strong(*_Expected, _Desired);
}

template <class _Ty>
bool atomic_compare_exchange_weak_explicit(volatile atomic<_Ty>* const _Mem, _Identity_t<_Ty>* const _Expected,
    const _Identity_t<_Ty> _Desired, const memory_order _Success, const memory_order _Failure) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    return _Mem->compare_exchange_strong(*_Expected, _Desired, _Combine_cas_memory_orders(_Success, _Failure));
}

template <class _Ty>
bool atomic_compare_exchange_weak_explicit(atomic<_Ty>* const _Mem, _Identity_t<_Ty>* const _Expected,
    const _Identity_t<_Ty> _Desired, const memory_order _Success, const memory_order _Failure) noexcept {
    return _Mem->compare_exchange_strong(*_Expected, _Desired, _Combine_cas_memory_orders(_Success, _Failure));
}

template <class _Ty>
_Ty atomic_fetch_add(volatile atomic<_Ty>* _Mem, const typename atomic<_Ty>::difference_type _Value) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    return _Mem->fetch_add(_Value);
}

template <class _Ty>
_Ty atomic_fetch_add(atomic<_Ty>* _Mem, const typename atomic<_Ty>::difference_type _Value) noexcept {
    return _Mem->fetch_add(_Value);
}

template <class _Ty>
_Ty atomic_fetch_add_explicit(volatile atomic<_Ty>* _Mem, const typename atomic<_Ty>::difference_type _Value,
    const memory_order _Order) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    return _Mem->fetch_add(_Value, _Order);
}

template <class _Ty>
_Ty atomic_fetch_add_explicit(
    atomic<_Ty>* _Mem, const typename atomic<_Ty>::difference_type _Value, const memory_order _Order) noexcept {
    return _Mem->fetch_add(_Value, _Order);
}

template <class _Ty>
_Ty atomic_fetch_sub(volatile atomic<_Ty>* _Mem, const typename atomic<_Ty>::difference_type _Value) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    return _Mem->fetch_sub(_Value);
}

template <class _Ty>
_Ty atomic_fetch_sub(atomic<_Ty>* _Mem, const typename atomic<_Ty>::difference_type _Value) noexcept {
    return _Mem->fetch_sub(_Value);
}

template <class _Ty>
_Ty atomic_fetch_sub_explicit(volatile atomic<_Ty>* _Mem, const typename atomic<_Ty>::difference_type _Value,
    const memory_order _Order) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    return _Mem->fetch_sub(_Value, _Order);
}

template <class _Ty>
_Ty atomic_fetch_sub_explicit(
    atomic<_Ty>* _Mem, const typename atomic<_Ty>::difference_type _Value, const memory_order _Order) noexcept {
    return _Mem->fetch_sub(_Value, _Order);
}

template <class _Ty>
_Ty atomic_fetch_and(volatile atomic<_Ty>* _Mem, const typename atomic<_Ty>::value_type _Value) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    return _Mem->fetch_and(_Value);
}

template <class _Ty>
_Ty atomic_fetch_and(atomic<_Ty>* _Mem, const typename atomic<_Ty>::value_type _Value) noexcept {
    return _Mem->fetch_and(_Value);
}

template <class _Ty>
_Ty atomic_fetch_and_explicit(
    volatile atomic<_Ty>* _Mem, const typename atomic<_Ty>::value_type _Value, const memory_order _Order) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    return _Mem->fetch_and(_Value, _Order);
}

template <class _Ty>
_Ty atomic_fetch_and_explicit(
    atomic<_Ty>* _Mem, const typename atomic<_Ty>::value_type _Value, const memory_order _Order) noexcept {
    return _Mem->fetch_and(_Value, _Order);
}

template <class _Ty>
_Ty atomic_fetch_or(volatile atomic<_Ty>* _Mem, const typename atomic<_Ty>::value_type _Value) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    return _Mem->fetch_or(_Value);
}

template <class _Ty>
_Ty atomic_fetch_or(atomic<_Ty>* _Mem, const typename atomic<_Ty>::value_type _Value) noexcept {
    return _Mem->fetch_or(_Value);
}

template <class _Ty>
_Ty atomic_fetch_or_explicit(
    volatile atomic<_Ty>* _Mem, const typename atomic<_Ty>::value_type _Value, const memory_order _Order) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    return _Mem->fetch_or(_Value, _Order);
}

template <class _Ty>
_Ty atomic_fetch_or_explicit(
    atomic<_Ty>* _Mem, const typename atomic<_Ty>::value_type _Value, const memory_order _Order) noexcept {
    return _Mem->fetch_or(_Value, _Order);
}

template <class _Ty>
_Ty atomic_fetch_xor(volatile atomic<_Ty>* _Mem, const typename atomic<_Ty>::value_type _Value) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    return _Mem->fetch_xor(_Value);
}

template <class _Ty>
_Ty atomic_fetch_xor(atomic<_Ty>* _Mem, const typename atomic<_Ty>::value_type _Value) noexcept {
    return _Mem->fetch_xor(_Value);
}

template <class _Ty>
_Ty atomic_fetch_xor_explicit(
    volatile atomic<_Ty>* _Mem, const typename atomic<_Ty>::value_type _Value, const memory_order _Order) noexcept {
    static_assert(_Deprecate_non_lock_free_volatile<_Ty>, "Never fails");
    return _Mem->fetch_xor(_Value, _Order);
}

template <class _Ty>
_Ty atomic_fetch_xor_explicit(
    atomic<_Ty>* _Mem, const typename atomic<_Ty>::value_type _Value, const memory_order _Order) noexcept {
    return _Mem->fetch_xor(_Value, _Order);
}

template <class _Ty>
void atomic_wait(const volatile atomic<_Ty>* const _Mem, const typename atomic<_Ty>::value_type _Expected) noexcept
  {
    _Mem->wait(_Expected);
}

template <class _Ty>
void atomic_wait(const atomic<_Ty>* const _Mem, const typename atomic<_Ty>::value_type _Expected) noexcept
  {
    _Mem->wait(_Expected);
}

template <class _Ty>
void atomic_wait_explicit(const volatile atomic<_Ty>* const _Mem, const typename atomic<_Ty>::value_type _Expected,
    const memory_order _Order) noexcept   {
    _Mem->wait(_Expected, _Order);
}

template <class _Ty>
void atomic_wait_explicit(const atomic<_Ty>* const _Mem, const typename atomic<_Ty>::value_type _Expected,
    const memory_order _Order) noexcept   {
    _Mem->wait(_Expected, _Order);
}

template <class _Ty>
void atomic_notify_one(volatile atomic<_Ty>* const _Mem) noexcept   {
    _Mem->notify_one();
}

template <class _Ty>
void atomic_notify_one(atomic<_Ty>* const _Mem) noexcept   {
    _Mem->notify_one();
}

template <class _Ty>
void atomic_notify_all(volatile atomic<_Ty>* const _Mem) noexcept   {
    _Mem->notify_all();
}

template <class _Ty>
void atomic_notify_all(atomic<_Ty>* const _Mem) noexcept   {
    _Mem->notify_all();
}

 using atomic_bool = atomic<bool>;

using atomic_char   = atomic<char>;
using atomic_schar  = atomic<signed char>;
using atomic_uchar  = atomic<unsigned char>;
using atomic_short  = atomic<short>;
using atomic_ushort = atomic<unsigned short>;
using atomic_int    = atomic<int>;
using atomic_uint   = atomic<unsigned int>;
using atomic_long   = atomic<long>;
using atomic_ulong  = atomic<unsigned long>;
using atomic_llong  = atomic<long long>;
using atomic_ullong = atomic<unsigned long long>;

using atomic_char8_t = atomic<char8_t>;
using atomic_char16_t = atomic<char16_t>;
using atomic_char32_t = atomic<char32_t>;
using atomic_wchar_t  = atomic<wchar_t>;

using atomic_int8_t   = atomic<int8_t>;
using atomic_uint8_t  = atomic<uint8_t>;
using atomic_int16_t  = atomic<int16_t>;
using atomic_uint16_t = atomic<uint16_t>;
using atomic_int32_t  = atomic<int32_t>;
using atomic_uint32_t = atomic<uint32_t>;
using atomic_int64_t  = atomic<int64_t>;
using atomic_uint64_t = atomic<uint64_t>;

using atomic_int_least8_t   = atomic<int_least8_t>;
using atomic_uint_least8_t  = atomic<uint_least8_t>;
using atomic_int_least16_t  = atomic<int_least16_t>;
using atomic_uint_least16_t = atomic<uint_least16_t>;
using atomic_int_least32_t  = atomic<int_least32_t>;
using atomic_uint_least32_t = atomic<uint_least32_t>;
using atomic_int_least64_t  = atomic<int_least64_t>;
using atomic_uint_least64_t = atomic<uint_least64_t>;

using atomic_int_fast8_t   = atomic<int_fast8_t>;
using atomic_uint_fast8_t  = atomic<uint_fast8_t>;
using atomic_int_fast16_t  = atomic<int_fast16_t>;
using atomic_uint_fast16_t = atomic<uint_fast16_t>;
using atomic_int_fast32_t  = atomic<int_fast32_t>;
using atomic_uint_fast32_t = atomic<uint_fast32_t>;
using atomic_int_fast64_t  = atomic<int_fast64_t>;
using atomic_uint_fast64_t = atomic<uint_fast64_t>;

using atomic_intptr_t  = atomic<intptr_t>;
using atomic_uintptr_t = atomic<uintptr_t>;
using atomic_size_t    = atomic<size_t>;
using atomic_ptrdiff_t = atomic<ptrdiff_t>;
using atomic_intmax_t  = atomic<intmax_t>;
using atomic_uintmax_t = atomic<uintmax_t>;

  using atomic_signed_lock_free   = atomic_intptr_t;
using atomic_unsigned_lock_free = atomic_uintptr_t;

 struct atomic_flag {       bool test(const memory_order _Order = memory_order_seq_cst) const noexcept {
        return _Storage.load(_Order) != 0;
    }

     bool test(const memory_order _Order = memory_order_seq_cst) const volatile noexcept {
        return _Storage.load(_Order) != 0;
    }

    bool test_and_set(const memory_order _Order = memory_order_seq_cst) noexcept {
        return _Storage.exchange(true, _Order) != 0;
    }

    bool test_and_set(const memory_order _Order = memory_order_seq_cst) volatile noexcept {
        return _Storage.exchange(true, _Order) != 0;
    }

    void clear(const memory_order _Order = memory_order_seq_cst) noexcept {
        _Storage.store(false, _Order);
    }

    void clear(const memory_order _Order = memory_order_seq_cst) volatile noexcept {
        _Storage.store(false, _Order);
    }

    constexpr atomic_flag() noexcept = default;

    void wait(const bool _Expected, const memory_order _Order = memory_order_seq_cst) const noexcept {
        _Storage.wait(static_cast<decltype(_Storage)::value_type>(_Expected), _Order);
    }

    void wait(const bool _Expected, const memory_order _Order = memory_order_seq_cst) const volatile noexcept {
        _Storage.wait(static_cast<decltype(_Storage)::value_type>(_Expected), _Order);
    }

    void notify_one() noexcept {
        _Storage.notify_one();
    }

    void notify_one() volatile noexcept {
        _Storage.notify_one();
    }

    void notify_all() noexcept {
        _Storage.notify_all();
    }

    void notify_all() volatile noexcept {
        _Storage.notify_all();
    }

    atomic<long> _Storage;
};


  inline bool atomic_flag_test(const volatile atomic_flag* const _Flag) noexcept {
    return _Flag->test();
}

 inline bool atomic_flag_test(const atomic_flag* const _Flag) noexcept {
    return _Flag->test();
}

 inline bool atomic_flag_test_explicit(
    const volatile atomic_flag* const _Flag, const memory_order _Order) noexcept {
    return _Flag->test(_Order);
}

 inline bool atomic_flag_test_explicit(const atomic_flag* const _Flag, const memory_order _Order) noexcept {
    return _Flag->test(_Order);
}

inline bool atomic_flag_test_and_set(atomic_flag* const _Flag) noexcept {
    return _Flag->test_and_set();
}

inline bool atomic_flag_test_and_set(volatile atomic_flag* const _Flag) noexcept {
    return _Flag->test_and_set();
}

inline bool atomic_flag_test_and_set_explicit(atomic_flag* const _Flag, const memory_order _Order) noexcept {
    return _Flag->test_and_set(_Order);
}

inline bool atomic_flag_test_and_set_explicit(volatile atomic_flag* const _Flag, const memory_order _Order) noexcept {
    return _Flag->test_and_set(_Order);
}

inline void atomic_flag_clear(atomic_flag* const _Flag) noexcept {
    _Flag->clear();
}

inline void atomic_flag_clear(volatile atomic_flag* const _Flag) noexcept {
    _Flag->clear();
}

inline void atomic_flag_clear_explicit(atomic_flag* const _Flag, const memory_order _Order) noexcept {
    _Flag->clear(_Order);
}

inline void atomic_flag_clear_explicit(volatile atomic_flag* const _Flag, const memory_order _Order) noexcept {
    _Flag->clear(_Order);
}

inline void atomic_flag_wait(const volatile atomic_flag* const _Flag, const bool _Expected) noexcept {
    return _Flag->wait(_Expected);
}

inline void atomic_flag_wait(const atomic_flag* const _Flag, const bool _Expected) noexcept {
    return _Flag->wait(_Expected);
}

inline void atomic_flag_wait_explicit(
    const volatile atomic_flag* const _Flag, const bool _Expected, const memory_order _Order) noexcept {
    return _Flag->wait(_Expected, _Order);
}

inline void atomic_flag_wait_explicit(
    const atomic_flag* const _Flag, const bool _Expected, const memory_order _Order) noexcept {
    return _Flag->wait(_Expected, _Order);
}

inline void atomic_flag_notify_one(volatile atomic_flag* const _Flag) noexcept {
    return _Flag->notify_one();
}

inline void atomic_flag_notify_one(atomic_flag* const _Flag) noexcept {
    return _Flag->notify_one();
}

inline void atomic_flag_notify_all(volatile atomic_flag* const _Flag) noexcept {
    return _Flag->notify_all();
}

inline void atomic_flag_notify_all(atomic_flag* const _Flag) noexcept {
    return _Flag->notify_all();
}

template <class _Ty>
class _Locked_pointer {
public:
    static_assert(alignof(_Ty) >= (1 << 2), "2 low order bits are needed by _Locked_pointer");
    static constexpr uintptr_t _Lock_mask                = 3;
    static constexpr uintptr_t _Not_locked               = 0;
    static constexpr uintptr_t _Locked_notify_not_needed = 1;
    static constexpr uintptr_t _Locked_notify_needed     = 2;
    static constexpr uintptr_t _Ptr_value_mask           = ~_Lock_mask;

    constexpr _Locked_pointer() noexcept : _Storage{} {}
    explicit _Locked_pointer(_Ty* const _Ptr) noexcept : _Storage{reinterpret_cast<uintptr_t>(_Ptr)} {}

    _Locked_pointer(const _Locked_pointer&) = delete;
    _Locked_pointer& operator=(const _Locked_pointer&) = delete;

     _Ty* _Lock_and_load() noexcept {
        uintptr_t _Rep = _Storage.load(memory_order_relaxed);
        for (;;) {
            switch (_Rep & _Lock_mask) {
            case _Not_locked:                  if (_Storage.compare_exchange_weak(_Rep, _Rep | _Locked_notify_not_needed)) {
                    return reinterpret_cast<_Ty*>(_Rep);
                }
                _mm_pause();
                break;

            case _Locked_notify_not_needed:                  if (!_Storage.compare_exchange_weak(_Rep, (_Rep & _Ptr_value_mask) | _Locked_notify_needed)) {
                                         _mm_pause();
                    break;
                }
                _Rep = (_Rep & _Ptr_value_mask) | _Locked_notify_needed;
                [[fallthrough]];

            case _Locked_notify_needed:                  _Storage.wait(_Rep, memory_order_relaxed);
                _Rep = _Storage.load(memory_order_relaxed);
                break;

            default:                  :: abort();
            }
        }
    }

    void _Store_and_unlock(_Ty* const _Value) noexcept {
        const auto _Rep = _Storage.exchange(reinterpret_cast<uintptr_t>(_Value));
        if ((_Rep & _Lock_mask) == _Locked_notify_needed) {
                         _Storage.notify_all();
        }
    }

     _Ty* _Unsafe_load_relaxed() const noexcept {
        return reinterpret_cast<_Ty*>(_Storage.load(memory_order_relaxed));
    }

private:
    atomic<uintptr_t> _Storage;
};

}





 
  



namespace std {

class latch {
public:
     static constexpr ptrdiff_t(max)() noexcept {
        return (1ULL << (sizeof(ptrdiff_t) * 8 - 1)) - 1;
    }

    constexpr explicit latch(const ptrdiff_t _Expected) noexcept   : _Counter{_Expected} {
        do {                                                                    if (_Expected >= 0) {           } else {                                                                do {                                             ;                   ::_invalid_parameter_noinfo_noreturn();     } while (false);                                        }                                                                                                                                       ;                                        } while (false);
    }

    latch(const latch&) = delete;
    latch& operator=(const latch&) = delete;

    void count_down(const ptrdiff_t _Update = 1) noexcept   {
        do {                                                                    if (_Update >= 0) {           } else {                                                                do {                                             ;                   ::_invalid_parameter_noinfo_noreturn();     } while (false);                                        }                                                                                                                                       ;                                        } while (false);
                 const ptrdiff_t _Current = _Counter.fetch_sub(_Update) - _Update;
        if (_Current == 0) {
            _Counter.notify_all();
        } else {
            do {                                                                    if (_Current >= 0) {           } else {                                                                do {                                             ;                   ::_invalid_parameter_noinfo_noreturn();     } while (false);                                        }                                                                                                                                       ;                                        } while (false);
        }
    }

     bool try_wait() const noexcept {
                 return _Counter.load() == 0;
    }

    void wait() const noexcept   {
        for (;;) {
                         const ptrdiff_t _Current = _Counter.load();
            if (_Current == 0) {
                return;
            } else {
                do {                                                                    if (_Current > 0) {           } else {                                                                do {                                             ;                   ::_invalid_parameter_noinfo_noreturn();     } while (false);                                        }                                                                                                                                       ;                                        } while (false);
            }
            _Counter.wait(_Current, memory_order_relaxed);
        }
    }

    void arrive_and_wait(const ptrdiff_t _Update = 1) noexcept   {
        do {                                                                    if (_Update >= 0) {           } else {                                                                do {                                             ;                   ::_invalid_parameter_noinfo_noreturn();     } while (false);                                        }                                                                                                                                       ;                                        } while (false);
                 const ptrdiff_t _Current = _Counter.fetch_sub(_Update) - _Update;
        if (_Current == 0) {
            _Counter.notify_all();
        } else {
            do {                                                                    if (_Current > 0) {           } else {                                                                do {                                             ;                   ::_invalid_parameter_noinfo_noreturn();     } while (false);                                        }                                                                                                                                       ;                                        } while (false);
            _Counter.wait(_Current, memory_order_relaxed);
            wait();
        }
    }

private:
    atomic<ptrdiff_t> _Counter;
};

}




