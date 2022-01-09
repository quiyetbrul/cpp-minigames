At first, I wanted to write a recursive Makefile so that I can create subdirectories within my src/

Setting this up turns to be cumbersome and might introduce some problem and slowness regarding build times <https://web.archive.org/web/20150319074420/http://aegis.sourceforge.net/auug97.pdf>


cmake -S . -B build  
cd build; make

OR

make -C build

./build/minigames
