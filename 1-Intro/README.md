Preprocessing phase:

```sh
$ clang -E hello.c -o hello.i
```

Compilation phase:

```sh
$ clang -S hello.i -o hello.s

$ cat hello.s
_main:                                  ; @main
        .cfi_startproc
; %bb.0:
        sub     sp, sp, #32
        .cfi_def_cfa_offset 32
        stp     x29, x30, [sp, #16]             ; 16-byte Folded Spill
        add     x29, sp, #16
        .cfi_def_cfa w29, 16
        .cfi_offset w30, -8
        .cfi_offset w29, -16
        mov     w8, #0
        str     w8, [sp, #8]                    ; 4-byte Folded Spill
        stur    wzr, [x29, #-4]
        adrp    x0, l_.str@PAGE
        add     x0, x0, l_.str@PAGEOFF
        bl      _printf
        ldr     w0, [sp, #8]                    ; 4-byte Folded Reload
        ldp     x29, x30, [sp, #16]             ; 16-byte Folded Reload
        add     sp, sp, #32
        ret
        .cfi_endproc
                                        ; -- End function
        .section        __TEXT,__cstring,cstring_literals
```

Assembly phase:

```sh
$ clang -c hello.s -o hello.o
```

Linking phase:

```sh
$ clang hello.o -o hello
$ ./hello
hello, world
```