/* ----------------------------------------------------------------------
.context pop
.category VioUtil
void far pop ( PUCHAR pch )

Description: 
     This routine allows a process to alert the user of an event.  The
VioPopUp call into OS/2 is used as the mechanism to the user.

Parameter     Description
-------------------------------------------------------------------------
pch           a 32 bit pointer to a zero terminated charater string

Returns: 
     nothing

Comments: 

References: 

See Also: box
.ref box

Development History: 
  Date         Programmer          Description of modification   
  06/16/1989   Paul Montgomery     Initial development           
-------------------------------------------------------------------- */

#define INCL_DOS
#define INCL_SUB
#include <os2.h>
#include <string.h>

#include "box.h"

void far pop ( PUCHAR pch )
   {
   USHORT     pwait;
   KBDKEYINFO KeyInfo;
   BYTE       bBlank[2];
   int        a1;
   int        b1;
   int        a2;
   int        b2;
   USHORT     len;
   int        col;

   for (len=0; pch[len] != 0; len++);

   pwait = VP_WAIT | VP_OPAQUE;
   a1 = (80 - (len + 12)) / 2;
   a2 = a1 + (len + 12);
   b1 = 3;
   b2 = 16;

   VioPopUp ( &pwait, 0 );

   bBlank[0] = 0x20;                      /* space character       */
   bBlank[1] = 0x02;                      /* green attribute (EGA) */
//   Exp_Box ( &bBlank, a1,b1,a2,b2, "POPUP" );
   box ( &bBlank, a1,b1,a2,b2, "POPUP" );

   col = ( a2 - a1 ) / 2;
   VioSetCurPos(b1 + ((b2-b1)/2),                      /* cursor row    */
       col - ( len / 2 ) + a1 ,
       0);
   VioWrtTTY ( "\x01b[32;40;m",9 ,0);
   VioWrtTTY ( pch, len, 0 );

   VioSetCurPos(b2-2,                         /* cursor row    */
       col - ( 3 ) + a1 ,
       0);
   VioWrtTTY ( "Any Key" ,7,0 );

   VioSetCurPos(b2-1,                         /* cursor row    */
       col - ( 4 ) + a1 ,
       0);
   VioWrtTTY ( "To Resume" ,9,0 );
   VioWrtTTY ( "\x01b[37;40;m",9 ,0);

   KbdCharIn(&KeyInfo, IO_WAIT, 0);

   VioEndPopUp ( 0 );
   }
