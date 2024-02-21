 AREA SASTRA,CODE,READONLY
 MOV r0,#0X40000000;source address
 mov r1,#3
 mov r2,r1
register
L2 ldr r3,[r0],#4
   add r4,r0,r1,LSL#2
   str r3,[r4]
   subs r2,#1
   BNE L2
l   B l
   end