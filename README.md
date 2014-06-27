qexpat - q / kdb+ interface for expat xml parser
======

Build:
======

install expat (probably it is already installed. at least on Mac is installed by the OS)

mac: gcc -dynamiclib -undefined dynamic_lookup -m32 -lexpat -o expat.so expat.c
linux: gcc -shared -m32 -lexpat -o expat.so expat.c
for 64bit use -m64

Install:
======

- copy expat.so in the right location for your kdb+ setup ($QHOME/<l32|l64|m32|m64>/).
- copy expat.q in a directory searchable by q (i use $QHOME/c)

Usage:
======

- \l <install dir for expat.q>/expat.q
- xmlparse "<tag/>
- xmlparse ("<tag attr1=\"1234\">";"text";"</tag>")
- xmlparse read0 `:a_file.xml