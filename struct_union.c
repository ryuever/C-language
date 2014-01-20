//=============================================== file = struct_union.c =====
//=  A tutorial program of compound types (struct, union) in C language     =
//===========================================================================
//=  Notes:                                                                 =
//=    1) .......                                                           =
//=-------------------------------------------------------------------------=
//= Example :                                                               =
//=                                                                         =
//=-------------------------------------------------------------------------=
//= Example output                                                          =
//=-------------------------------------------------------------------------=
//=  Build: gcc -g struct_union.c                                           =
//=-------------------------------------------------------------------------=
//=  Author: Liu Youchao                                                    =
//=-------------------------------------------------------------------------=
//=  History:                                                               =
//===========================================================================
//----- Include files -------------------------------------------------------
#include <stdio.h>         // Needed for printf()
#include <stdlib.h>    

//----- Defines -------------------------------------------------------------
#define PSIZE 128
#define	PLEN		(PSIZE - sizeof(struct people_hdr))	/* normal data len */
#define dtom(x)     ((struct people *) ((long)(x) & ~(PSIZE-1)))

typedef struct people_hdr{
  int age;
  char name[19];
  int id;
} people_hdr;                     // You can refer to variable people_hdr later.

struct people{
  people_hdr phdr;
  char profile[100];
} pl;                             // declare and define a structure variable pl 

struct name {
   int a;
   float b;
   char c[30];
};

int main(){
//==============================================================================
//             Initialization and accessing structure field
// Pay attention to the difference between struct variable and struct pointer
// when accessing a field of structure.
// variable : dot operator.    emp1.doj.date
// pointer  : dot operator  or right-arrow operator
//            (* )
//==============================================================================
  printf("=====================================================================\n");
  printf("initialization and accessing of structure field through dot operator.\n");
  printf("=====================================================================\n");
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
  
  printf("=====================================================================\n");
  printf("Access structure field through rightarrow operator.\n");
  printf("=====================================================================\n");
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
  int age = tt.phdr.age;
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
  phdr->age = 40;
  printf("After change   : nested field age is %d.\n",phdr->age);
  
//==============================================================================
//                           Sizeof structure
// The return value type is long unsigned. %zu as format specifier. An 
// alternative is %lu. 
// Note : For this part. It will invovle "Data Structure alignment". Inserting 
//        some meaningless bytes to make the data to be read at a memory offset 
//        which is some multiple of 4 or 8.
// The aggregate size of a structure in C can be greater than the sum of the sizes 
// For detail of sizeof function, please refer to function.c
//==============================================================================
  printf("=====================================================================\n");
  printf("calculate size of a structure.\n");
  printf("=====================================================================\n");

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

  struct people *p;
  p = dtom(phdr);

  long int temp = (long)phdr & ~127;
  return 0;
}
