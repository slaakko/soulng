 
  
 
  
   
                                           
                                                 
           
     
                                                                                                                   
  
    
                                                                                              
                     
  

    
 

 





  

 


 

      
   
    
  
 
  
 
  
   
   
 

   
 
  

 
  
 
  

 


 



 
   
 





 
    

  
 


 



 
               

 

 

    

 








 



  
 

 
    
 
 
  
 
 

 
 
 

 
  
   
 




   
   

   

   
 

 

   
    
  
 

 
 
    
  
 
 
 
 




 

  
 
 
  
 
  
  

   
 
 
  
 
   
 
 
  
  
 

 

  

  



 


  



 
 
 
 
    
 
  
 
 
 


 


  
 
 
 

 
    
 
  
 
 
 


 


  
 
 
 

   

   
   
 
  
 
 
 
  
 
 
 

 
 
  
 
 
  
 
 
 


 


  
 
 
 

  
 
 
 
    



     









    



   

    
      
   




 



























 

 
 


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


 
  

  


      
 
 
















































































 



 


 




 





  

  
 
  
 
 

                         
  
      

  





  
 
 
 
 
 
 
 
    
 
  

 
 

 

  

  
   
 
 
 
  
 
 
 
 
 
 
 
 
 
  
 

  
 
 


 
 

 





 
 










  
 
 
 

 



























 
 
 


 
 






  


