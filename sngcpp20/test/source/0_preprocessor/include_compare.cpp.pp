 
  
 
  
   
                                           
                                                 
           
     
                                                                                               
  
    
                                                                                              
                     
  

    
 

 





  

 


 

      
   
    
  
 
  
 
  
   
   
 

   
 
  

 
  
 
  

 


 



 
   
 





 
    

  
 


 



 
               

 

 

    

 








 



  
 

 
    
 
 
  
 
 

 
 
 

 
  
   
 




   
   

   

   
 

 

   
    
  
 

 
 
    
  
 
 
 
 




 

  
 
 
  
 
  
  

   
 
 
  
 
   
 
 
  
  
 

 

  

  



 


  



 
 
 
 
    
 
  
 
 
 


 


  
 
 
 

 
    
 
  
 
 
 


 


  
 
 
 

   

   
   
 
  
 
 
 
  
 
 
 

 
 
  
 
 
  
 
 
 


 


  
 
 
 

  
 
 
 
    



     









    



   

    
      
   




 



























 

 
 


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




