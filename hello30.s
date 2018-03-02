.text
.globl _start
start = 0
max = 31
ten = 10
_start:
        mov     x19,start
        mov     x22,ten

loop:
       
	adr     x1, msg   	/* message location (memory address) */
	mov     x2, len   	/* message length (bytes) */
        mov     x0, 1
	mov     x8, 64     	/* write is syscall #64 */
	svc     0          	/* invoke syscall */
        adr     x23,msg
        add     x19,x19,1
        udiv    x20,x19,x22
        msub    x21,x22,x20,x19
        cmp     x20,0
        beq     skip
        add     x20,x20,'0'
        strb    w20, [x23,6]
skip:
        add     x21,x21,'0'
        strb    w21, [x23,7]
        cmp     x19,max
        bne     loop
	mov     x0, 0     	/* status -> 0 */
	mov     x8, 93    	/* exit is syscall #93 */
	svc     0          	/* invoke syscall */
 
.data
msg: 	.ascii      "Loop: 0\n\n"
len= 	. - msg

