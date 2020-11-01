TEST_EXPECTED=output15a.b
TEST_ACTUAL=15sa.b
SRC_C=huffman.c
SRC_H=huffman.h
TEST_C=pa2.c
CC=gcc
CFLAGS=-g -std=c99 -Wall -Wshadow -Wvla -pedantic
CFLAGS_GCOV=$(CFLAGS) -fprofile-arcs -ftest-coverage
SHELL=/bin/bash
TEST_EXE=pa2

$(TEST_EXE): $(SRC_C) $(TEST_C) $(SRC_H)
	$(CC) -o $(TEST_EXE) $(SRC_C) $(TEST_C) $(CFLAGS)

test: debug hufftests nonhufftests testdiff 

testv: debug vtest1 vtest2 vtest3 vtest4 vtest5

EXT=tree

testdiff: testdiff1 testdiff2 testdiff3 testdiff4 testdiff5 testdiff6 testdiff7 testdiff8 testdiff9 testdiff10 testdiff11 testdiff12 testdiff13 testdiff14 testdiff15 testdiff16 testdiff17 testdiff18 testdiff19 testdiff20

testdiff1:  
	@if diff -a $(GDIR).$(EXT) $(EXT)/$(G)_huff.$(EXT) &> /dev/null ; then \
		echo -e "\x1b[32mTest1 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest1 Failed :(\x1b[0m" ; \
	fi

testdiff2:  
	@if diff -a $(LDIR).$(EXT) $(EXT)/$(L)_huff.$(EXT) &> /dev/null ; then \
		echo -e "\x1b[32mTest2 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest2 Failed :(\x1b[0m" ; \
	fi

testdiff3:  
	@if diff -a $(SDIR).$(EXT) $(EXT)/$(S)_huff.$(EXT) &> /dev/null ; then \
		echo -e "\x1b[32mTest3 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest3 Failed :(\x1b[0m" ; \
	fi

testdiff4:  
	@if diff -a $(WDIR).$(EXT) $(EXT)/$(W)_huff.$(EXT) &> /dev/null ; then \
		echo -e "\x1b[32mTest4 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest4 Failed :(\x1b[0m" ; \
	fi

testdiff5:  
	@if diff -a $(BDIR).$(EXT) $(EXT)/$(B)_huff.$(EXT) &> /dev/null ; then \
		echo -e "\x1b[32mTest5 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest5 Failed :(\x1b[0m" ; \
	fi

testdiff6:  
	@if diff -a $(GDIR).ori decoded/$(G) &> /dev/null ; then \
		echo -e "\x1b[32mTest6 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest6 Failed :(\x1b[0m" ; \
	fi

testdiff7:  
	@if diff -a $(LDIR).ori decoded/$(L) &> /dev/null ; then \
		echo -e "\x1b[32mTest7 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest7 Failed :(\x1b[0m" ; \
	fi

testdiff8:  
	@if diff -a $(SDIR).ori decoded/$(S) &> /dev/null ; then \
		echo -e "\x1b[32mTest8 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest8 Failed :(\x1b[0m" ; \
	fi

testdiff9:  
	@if diff -a $(WDIR).ori decoded/$(W) &> /dev/null ; then \
		echo -e "\x1b[32mTest9 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest9 Failed :(\x1b[0m" ; \
	fi

testdiff10:  
	@if diff -a $(BDIR).ori decoded/$(B) &> /dev/null ; then \
		echo -e "\x1b[32mTest10 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest10 Failed :(\x1b[0m" ; \
	fi

testdiff11:  
	@if diff -a $(GNDIR).$(EXT) $(EXT)/$(G)_nonhuff.$(EXT) &> /dev/null ; then \
		echo -e "\x1b[32mTest11 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest11 Failed :(\x1b[0m" ; \
	fi

testdiff12:  
	@if diff -a $(LNDIR).$(EXT) $(EXT)/$(L)_nonhuff.$(EXT) &> /dev/null ; then \
		echo -e "\x1b[32mTest12 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest12 Failed :(\x1b[0m" ; \
	fi

testdiff13:  
	@if diff -a $(SNDIR).$(EXT) $(EXT)/$(S)_nonhuff.$(EXT) &> /dev/null ; then \
		echo -e "\x1b[32mTest13 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest13 Failed :(\x1b[0m" ; \
	fi

testdiff14:  
	@if diff -a $(WNDIR).$(EXT) $(EXT)/$(W)_nonhuff.$(EXT) &> /dev/null ; then \
		echo -e "\x1b[32mTest14 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest14 Failed :(\x1b[0m" ; \
	fi

testdiff15:  
	@if diff -a $(BNDIR).$(EXT) $(EXT)/$(B)_nonhuff.$(EXT) &> /dev/null ; then \
		echo -e "\x1b[32mTest15 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest15 Failed :(\x1b[0m" ; \
	fi

testdiff16:  
	@if diff -a $(GNDIR).ori decoded/$(G) &> /dev/null ; then \
		echo -e "\x1b[32mTest16 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest16 Failed :(\x1b[0m" ; \
	fi

testdiff17:  
	@if diff -a $(LNDIR).ori decoded/$(L) &> /dev/null ; then \
		echo -e "\x1b[32mTest17 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest17 Failed :(\x1b[0m" ; \
	fi

testdiff18:  
	@if diff -a $(SNDIR).ori decoded/$(S) &> /dev/null ; then \
		echo -e "\x1b[32mTest18 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest18 Failed :(\x1b[0m" ; \
	fi

testdiff19:  
	@if diff -a $(WNDIR).ori decoded/$(W) &> /dev/null ; then \
		echo -e "\x1b[32mTest19 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest19 Failed :(\x1b[0m" ; \
	fi

testdiff20:  
	@if diff -a $(BNDIR).ori decoded/$(B) &> /dev/null ; then \
		echo -e "\x1b[32mTest20 Passed :)\x1b[0m" ; \
	else \
		echo -e "\x1b[31mTest20 Failed :(\x1b[0m" ; \
	fi

G=gophers
L=lorum
S=stone
W=woods
B=binary1

GDIR=tests/$(G)_huff/$(G)_huff_test
LDIR=tests/$(L)_huff/$(L)_huff_test
SDIR=tests/$(S)_huff/$(S)_huff_test
WDIR=tests/$(W)_huff/$(W)_huff_test
BDIR=tests/$(B)_huff/$(B)_huff_test

GNDIR=tests/$(G)_huff/$(G)_nonhuff_test
LNDIR=tests/$(L)_huff/$(L)_nonhuff_test
SNDIR=tests/$(S)_huff/$(S)_nonhuff_test
WNDIR=tests/$(W)_huff/$(W)_nonhuff_test
BNDIR=tests/$(B)_huff/$(B)_nonhuff_test

hufftests: test1 test2 test3 test4 test4

nonhufftests: test6 test7 test8 test9 test10

valtests: vtest1 vtest2 vtest3 vtest4

test0:
	valgrind ./$(TEST_EXE)

vtest1:
	valgrind ./$(TEST_EXE) encoded/$(G)_huff.hbt $(GDIR).tree $(GDIR).ori $(GDIR).count $(GDIR).htree $(GDIR).eval m

vtest2:
	valgrind ./$(TEST_EXE) encoded/$(L)_huff.hbt $(LDIR).tree $(LDIR).ori $(LDIR).count $(LDIR).htree $(LDIR).eval b

vtest3:
	valgrind ./$(TEST_EXE) encoded/$(S)_huff.hbt $(SDIR).tree $(SDIR).ori $(SDIR).count $(SDIR).htree $(SDIR).eval g

vtest4:
	valgrind ./$(TEST_EXE) encoded/$(W)_huff.hbt $(WDIR).tree $(WDIR).ori $(WDIR).count $(WDIR).htree $(WDIR).eval r

vtest5:
	valgrind ./$(TEST_EXE) encoded/$(B)_huff.hbt $(BDIR).tree $(BDIR).ori $(BDIR).count $(BDIR).htree $(BDIR).eval c

test1:
	./$(TEST_EXE) encoded/$(G)_huff.hbt $(GDIR).tree $(GDIR).ori $(GDIR).count $(GDIR).htree $(GDIR).eval m

test2:
	./$(TEST_EXE) encoded/$(L)_huff.hbt $(LDIR).tree $(LDIR).ori $(LDIR).count $(LDIR).htree $(LDIR).eval b

test3:
	./$(TEST_EXE) encoded/$(S)_huff.hbt $(SDIR).tree $(SDIR).ori $(SDIR).count $(SDIR).htree $(SDIR).eval g

test4:
	./$(TEST_EXE) encoded/$(W)_huff.hbt $(WDIR).tree $(WDIR).ori $(WDIR).count $(WDIR).htree $(WDIR).eval r

test5:
	./$(TEST_EXE) encoded/$(B)_huff.hbt $(BDIR).tree $(BDIR).ori $(BDIR).count $(BDIR).htree $(BDIR).eval c

test6:
	./$(TEST_EXE) encoded/$(G)_nonhuff.hbt $(GNDIR).tree $(GNDIR).ori $(GNDIR).count $(GNDIR).htree $(GNDIR).eval m

test7:
	./$(TEST_EXE) encoded/$(L)_nonhuff.hbt $(LNDIR).tree $(LNDIR).ori $(LNDIR).count $(LNDIR).htree $(LNDIR).eval b

test8:
	./$(TEST_EXE) encoded/$(S)_nonhuff.hbt $(SNDIR).tree $(SNDIR).ori $(SNDIR).count $(SNDIR).htree $(SNDIR).eval g

test9:
	./$(TEST_EXE) encoded/$(W)_nonhuff.hbt $(WNDIR).tree $(WNDIR).ori $(WNDIR).count $(WNDIR).htree $(WNDIR).eval r

test10:
	./$(TEST_EXE) encoded/$(B)_nonhuff.hbt $(BNDIR).tree $(BNDIR).ori $(BNDIR).count $(BNDIR).htree $(BNDIR).eval c


debug: $(SRC_C) $(TEST_C)
	$(CC) -DDEBUG -o $(TEST_EXE) $(SRC_C) $(TEST_C) $(CFLAGS)

clean: 
	rm -f $(TEST_EXE) *.c.gcov *.gcda *.gcno *.swp

.PHONY: submit test pretest coverage
