/* 
   This is a 'hello world' program in x86_64 assembler using the 
   GNU assembler (gas) syntax. Note that this program runs in 64-bit
   mode.

   CTyler, Seneca College, 2014-01-20
   Licensed under GNU GPL v2+
*/
.text
.globl  _start


start = 0			/* starting value for the loop index*/
max = 31			/* loop stops when index equals max*/
ten = 10			/* tens digit */

_start:

        mov     $start,%r15	/* r15 will act as the index*/
        mov     $ten,%r14	/* set index start at 10 */

loop:

        mov     $len,%rdx	
        mov     $msg,%rsi	
        
        mov     $1,%rax		/* put 1 into rax */

        syscall

        inc     %r15		
        mov     $start,%rdx	/* put value start in rdx start at 0*/		
        mov     %r15,%rax	/* put data in r15 to rax*/
        div     %r14		/* rax/%r14 (%r14=10)*/

        mov     $num,%r12	/* move value of num to r12*/
        mov     %rax,%r13	/* move value of rax (quotient) to r13 */
        cmp     $0,%r13	/* if quotient is 0 */
        je      skip		/* jump to skip */
        add     $'0',%r13	/* add '0'+r13*/
        mov     %r13b,(%r12)    /* move data from r13b to address pointed to by r12*/ 

skip:
        inc     %r12		
        mov     %rdx,%r13	
        add     $'0',%r13
        mov     %r13b,(%r12)

        cmp     $max,%r15	/* compare max to %r15 to see if we've reached 31*/
        jne     loop		/* jump back to loop if we aren't done*/

        mov     $0,%rdi		/* exit status */
        mov     $60,%rax	/* syscall sys_exit */
        syscall

.section .data
        msg: .ascii  "Loop:  0\n"
        len = . - msg
        num = msg + 6
































     
