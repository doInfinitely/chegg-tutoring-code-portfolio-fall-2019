section   .text
global    _main
path:   db  "/Users/Chei/Documents/quicksort_x86/animal.txt",0
string: db  "hello",0
.len:   equ $ - string

_main:

; open the file
    mov   rax,  0x200000005            ; open(
    mov   rdi,  path  ; Path
    mov   rsi,  0     ; Mode = 0
    mov   rdx,  2     ; Read/Write flag
    sub   rsp,  4       ; Reserved space for system call
    syscall
