/* ----------------------------------------------------------------------
.context BoxErase
.category VioUtil
void far BoxErase ( PBYTE cb, int x1, int y1, int x2, int y2 )

Description: 
     Erase an area of the screen as defined by the x and y parameters.
X1, Y1 = top left corner of box.  X2, Y2 = bottom right corner of box.

Parameter     Description
-------------------------------------------------------------------------
cb            a 32 bit pointer to a two byte character attribute
              that defines the character to fill the screen area with.

x1            upper left column of box

y1            upper left row of box

x2            lower right column of box

y2            lower right row of box


Returns: 

Comments: 

References: 

See Also: box, ExpBox
.ref box, ExpBox

Development History: 
  Date         Programmer          Description of modification   
  06/16/1989   Paul Montgomery     Initial development           
-------------------------------------------------------------------- */

#define INCL_SUB
#include <os2.h>

void far BoxErase ( PBYTE cb, int x1, int y1, int x2, int y2 )
   {
   VioScrollDn ( y1, x1, y2, x2, y2-y1+1,cb,0 );
   }


