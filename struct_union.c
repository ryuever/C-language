//=============================================== file = struct_union.c =========
//=  A tutorial program of compound types (struct, union) in C language         =
//===============================================================================
//=  Notes:                                                                     =
//=    1) To make it easier to read, I make the definition of structure         =
//=       just in front of a block where it is first referred to.               =
//=-----------------------------------------------------------------------------=
//= Example :                                                                   =
//=                                                                             =
//=-----------------------------------------------------------------------------=
//= Example output                                                              =
//=-----------------------------------------------------------------------------=
//=  Build: gcc -g struct_union.c                                               =
//=-----------------------------------------------------------------------------=
//=  Author: Liu Youchao                                                        =
//=-----------------------------------------------------------------------------=
//=  History:                                                                   =
//===============================================================================
//----- Include files -----------------------------------------------------------
#include <stdio.h>         // Needed for printf()
#include <stdlib.h>    
#include <string.h>        // Needed for strcpy() 
#include <stddef.h>        // Needed for offsetof()

//----- Defines -----------------------------------------------------------------
#define PSIZE 128
#define PLEN        (PSIZE - sizeof(struct people_hdr))   // normal data len 
#define dtom(x)     ((struct people *) ((long)(x) & ~(PSIZE-1)))

typedef struct people_hdr{
  int age;
  char name[19];
  int id;
} people_hdr;                     // You can refer to variable people_hdr later.

struct people{
  people_hdr phdr;
#define p_age phdr.age
  char profile[100];
} pl;                             // declare and define a structure variable pl 

struct name {
   int a;
   float b;
   char c[30];
};

int main(){
//===============================================================================
//             Initialization and accessing structure field
// Pay attention to the difference between struct variable and struct pointer
// when accessing a field of structure.
// variable : dot operator.    emp1.doj.date
// pointer  : dot operator  or right-arrow operator
//===============================================================================
  printf("==================================================================\n");
  printf("initialization and accessing of struct field through dot operator.\n");
  printf("==================================================================\n");
  struct init_stru{
    int id;
    char name[19];
  } liu = {1,"David"  };

  printf("The name is %s.\n",liu.name);

  // embedded struct. doj is a must, because struct date just like int. should 
  // be provided a variable name.
  struct employee{
    char name[20];
    struct date{
      int date;
      int month;
      int year;
    } doj;           
  }emp1 = {"peter",{20,8,2014}};
  printf("The date when it is hired is %d/%d/%d.\n",
         emp1.doj.date,emp1.doj.month,emp1.doj.year);
  printf("==================================================================\n");  
  printf("Access structure field through rightarrow operator.\n");
  printf("==================================================================\n");
  typedef struct Rectangle{
    struct Rectangle *binson[2];
    int center[2];
    int length[2];    
  } Rectangle;
 
  Rectangle world = {{NULL,NULL},{1,2},{3,4}};

  /* Rectangle *pp = {{NULL,NULL},{1,2},{5,6}};   // braces around scalar initializer */
  Rectangle *pp = &world;
  Rectangle world2 = {{&world,NULL},{7,8},{9,10}};
  printf("The center of world is (%d,%d).\n",pp->center[1],world.center[0]);
  printf("The nested center value of world2 is (%d,%d).\n",
         world2.binson[0]->center[0],world2.binson[0]->center[1]);

  struct people tt = {{23,"liu", 3},"love"};
  int age = tt.p_age;
  printf("Dot operator to access nested field age :%d\n",age);
  printf("\n");

  printf("=====================================================================\n");
  printf("Assignment to structure field.\n");
  printf("=====================================================================\n");
  printf("original value : %d.\n",liu.id);
  liu.id = 23;
  printf("After change   : %d.\n",liu.id);

  struct people t = {{23,"liu", 3},"love"};
  pl.profile[0] = 'y';

  struct people_hdr *phdr = &t.phdr;
  printf("Original       : nested field age is %d.\n",phdr->age);
  //  phdr->age = 40;
  (* phdr).age = 40;
  // p_age = 40;         
  printf("After change   : nested field age is %d.\n",phdr->age);
  
//===============================================================================
//                           Sizeof structure
// The return value type is long unsigned. %zu as format specifier. An 
// alternative is %lu. 
// Note : For this part. It will invovle "Data Structure alignment". Inserting 
//        some meaningless bytes to make the data to be read at a memory offset 
//        which is some multiple of 4 or 8.
// The aggregate size of a structure in C can be greater than the sum of the sizes 
// For detail of sizeof function, please refer to function.c
//===============================================================================
  printf("==================================================================\n");
  printf("calculate size of a structure.\n");
  printf("==================================================================\n");

  /* struct init_stru{ */
  /*   int id; */
  /*   char name[19]; */
  /* } liu = {1,"David"  }; */

  printf("The length of struct people_hdr is %zu.\n", 
         sizeof(struct people_hdr));  // 28 > 4 + 19 + 4
  printf("The length of struct init_stru is %zu.\n", 
         sizeof(liu));                // 24 > 4 + 19
  printf("The length of primitive type int : %zu.\n",
         sizeof(int));                // 4     
  printf("The length of sizeof function's return value : %zu.\n",
         sizeof(sizeof(int)));        // 8 is the length corresponding to %zu
  printf("The length of struct people %zu.\n",sizeof(pl));           // 128
  printf("The length of struct people_hdr %zu.\n",sizeof(t.phdr));   // 28
  printf("\n");

//===============================================================================
//                              union
// 1) : Same memory location can be used to store multiple types of data. So the 
//      element are all started from offset 0;
// 2) : The memory occupied by a union will be large enough to hold the largest 
//      member of the union.
// 3) : It is not allowed to access more than 1 member at a time. So the first 
//      group  of data.i and data.f is corrupted. Because the same memory is 
//      assigned by the last statment strycpy
// 4) : You can use any built-in or user defined data types inside a union.
//=============================================================================== 
  printf("==================================================================\n");
  printf("The sizeof union or an element of union.\n");
  printf("==================================================================\n");
  union Data{
    int i;
    float f;
    char  str[20];
  };
  union Data data;        
  printf("Memory size occupied by data : %zu\n", sizeof(data));         // 20
  printf("Memory size occupied by element : %zu\n", sizeof(data.i));    // 4
  printf("offset of second element f is %zu\n",offsetof(union Data,f)); // 0 
  printf("\n");

  printf("==================================================================\n");
  printf("Accessing Union Members.\n");
  printf("==================================================================\n");
  data.i = 10;
  data.f = 220.5;
  strcpy( data.str, "C Programming");
  
  printf( "data.i : %d\n", data.i);      // 1917853763
  printf( "data.f : %f\n", data.f);      // 4122360580327794860452759994368.000000
  printf( "data.str : %s\n", data.str);  // C Programming

  data.i = 10;
  printf( "data.i : %d\n", data.i);      // 10
  data.f = 220.5;
  printf( "data.f : %f\n", data.f);      // 220.500000
  strcpy( data.str, "C Programming");
  printf( "data.str : %s\n", data.str);  // C Programming

//===============================================================================
// Note : Members inside a union share the same memory, The size of union is    =
//        the size of biggest member in union.                                  =
//                                                                              =
// take file mbuf.h in 4.4BSD_Lite as an example.                               =
//------------------------------------------------------mbuf.h------------------=
// struct mbuf {                                                                =
//   struct    m_hdr m_hdr;                                                     =
//     union {                                                                  =
//       struct {                                                               =
//         struct    pkthdr MH_pkthdr;     /* M_PKTHDR set */                   =
//         union {                                                              =
//           struct    m_ext MH_ext;     /* M_EXT set */                        =
//           char    MH_databuf[MHLEN];                                         =
//         } MH_dat;                                                            =
//       } MH;                                                                  =
//       char   M_databuf[MLEN];           /* !M_PKTHDR, !M_EXT */              =
//     } M_dat;                                                                 =
// };                                                                           =
//===============================================================================
  struct people *p;
  p = dtom(phdr);

  long int temp = (long)phdr & ~127;
  return 0;
}
