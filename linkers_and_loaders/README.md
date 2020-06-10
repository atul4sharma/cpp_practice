# Linking process
## Library hierarchy in Linux
* static
    * static linking
* shared
    * dynamic linking
    * dynamic loading

#
`The utilities mentioned are specific to linux environment`


## readelf utility options
> -S --section-headers   Display the sections' header
>
> -d --dynamic           Display the dynamic section (if present)
>
> --dyn-syms             Display the dynamic symbol table
>
> -s --syms              Display the symbol table
>

## symbol tables
* .symtab and .dynsym (link in the [Resources](#resources))

### Checking the opened files by a particular process
> lsof -p <pid>
>
![lsof output](img/lsof_output.jpg?raw=true "lsof_output")

# Look for these and update
> $origin with rpath -> Updated the makefile in dynamic_linking (solution link in the [Resources](#resources))
>
> LD_DEBUG=libs 

# Resources
- [How does the compilation/linking process work](https://stackoverflow.com/questions/6264249/how-does-the-compilation-linking-process-work)
- [Anatomy of Linux dynamic libraries](https://developer.ibm.com/tutorials/l-dynamic-libraries/)
- [gcc debug symbols (-g flag) vs linker's -rdynamic option](https://stackoverflow.com/questions/8623884/gcc-debug-symbols-g-flag-vs-linkers-rdynamic-option/8624223#8624223)
- [Inside ELF Symbol Tables](https://blogs.oracle.com/solaris/inside-elf-symbol-tables-v2)
- [How to make backtrace()/backtrace_symbols() print the function names?](https://stackoverflow.com/questions/6934659/how-to-make-backtrace-backtrace-symbols-print-the-function-names)
- [difference between dynamic loading and dynamic linking?](https://stackoverflow.com/questions/10052464/difference-between-dynamic-loading-and-dynamic-linking)
- [rpath=\$$ORIGIN](https://stackoverflow.com/a/6352405/8604161)
---
- [ld.so(8) - Linux man page](https://linux.die.net/man/8/ld.so)
- [VDSO](https://www.man7.org/linux/man-pages/man7/vdso.7.html)
- [vDSO wikipedia](https://en.wikipedia.org/wiki/VDSO)
---
- [CppCon 2018: Matt Godbolt The Bits Between the Bits: How We Get to main()](https://www.youtube.com/watch?v=dOfucXtyEsU)


