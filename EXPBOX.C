/* ----------------------------------------------------------------------
.context ExpBox
.category VioUtil
void far ExpBox ( BYTE *cb, int x1, int y1, int x2, int y2, char *name )

Description: 
     Create a named bounded area on the screen that appears to grow from
a small box to a big one.

Parameter     Description
-------------------------------------------------------------------------
cb            a pointer to a two byte character attribute
              that defines the character to fill the
              screen area with.
x1            upper left column of box
y1            upper left row of box
x2            lower right column of box
y2            lower right row of box
name          a pointer to a 0 terminated character string

Returns: 
     nothing

Comments: 

References: 

See Also: box, boxerase
.ref box, boxerase

Development History: 
  Date         Programmer          Description of modification   
  06/16/1989   Paul Montgomery     Initial development           
-------------------------------------------------------------------- */

#define INCL_SUB
#include <os2.h>

#include "box.h"

#define LEVELS  4

void far ExpBox ( BYTE *cb, int x1, int y1, int x2, int y2, char *name )
   {

   int i;
   int k;
   int j;


   // calculate size increments of successive boxes
   // ( width of box ) / ( number of boxes we will draw / 2 )
   // ( height of box ) / ( number of boxes we will draw / 2 )

   i = ( x2 - x1 ) / ( LEVELS * 2 );
   k = ( y2 - y1 ) / ( LEVELS * 2 );

   // draw LEVELS number of boxes from the inside out
   for ( j = LEVELS ; j > 0 ; j -- )
      {
      box ( cb,
            x1 + ( i * j),
            y1 + ( k * j ),
            x2 - ( i * j),
            y2 - ( k * j ),
            name );

      }

   // draw final box of proper size
   box ( cb, x1, y1, x2, y2, name );

   }


