          global    _main
          extern    _puts

          section   .text
_main:    push      rbx
          lea       rdi, [rel message]
          call      _puts
          pop       rbx
          ret

          section   .data
message:  db        "Hola, mundo", 0
