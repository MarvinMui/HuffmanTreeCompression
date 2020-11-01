TEST_EXPECTED=output15a.b
TEST_ACTUAL=15sa.b
SRC_C=huffman.c
SRC_H=huffman.h
TEST_C=pa2.c
CC=gcc
CFLAGS=-O3 -std=c99 -Wall -Wshadow -Wvla -pedantic
CFLAGS_GCOV=$(CFLAGS) -fprofile-arcs -ftest-coverage
SHELL=/bin/bash
TEST_EXE=pa2

$(TEST_EXE): $(SRC_C) $(TEST_C) $(SRC_H)
	$(CC) -o $(TEST_EXE) $(SRC_C) $(TEST_C) $(CFLAGS)

test: hufftests nonhufftests testdiff 

testv: debug vtest1 vtest2 vtest3 vtest4 vtest5

EXT=tree

testdiff: testdiff1 testdiff2 testdiff3 testdiff4 testdiff5 testdiff7 testdiff8 testdiff9 testdiff10 testdiff11 testdiff13 testdiff14 testdiff15 testdiff16 testdiff17 testdiff19 testdiff20 testdiff21 testdiff22 testdiff23 testdiff25 testdiff26 testdiff27 testdiff28 testdiff29 testdiff31 testdiff32 testdiff33 testdiff34 testdiff35 testdiff37 testdiff38 testdiff39 testdiff40 testdiff41 testdiff43 testdiff44 testdiff45 testdiff46 testdiff47 testdiff49 testdiff50 testdiff51 testdiff52 testdiff53 testdiff55 testdiff56 testdiff57 testdiff58 testdiff59 

testdiff1:
	@if diff -a $(GDIR).tree tree/$(G)_huff.tree &> /dev/null ; then echo -e "\x1b[32mTest1: G-tree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest1: G-tree Failed :(\x1b[0m" ; fi

testdiff2:
	@if diff -a $(LDIR).tree tree/$(L)_huff.tree &> /dev/null ; then echo -e "\x1b[32mTest2: L-tree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest2: L-tree Failed :(\x1b[0m" ; fi

testdiff3:
	@if diff -a $(SDIR).tree tree/$(S)_huff.tree &> /dev/null ; then echo -e "\x1b[32mTest3: S-tree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest3: S-tree Failed :(\x1b[0m" ; fi

testdiff4:
	@if diff -a $(WDIR).tree tree/$(W)_huff.tree &> /dev/null ; then echo -e "\x1b[32mTest4: W-tree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest4: W-tree Failed :(\x1b[0m" ; fi

testdiff5:
	@if diff -a $(BDIR).tree tree/$(B)_huff.tree &> /dev/null ; then echo -e "\x1b[32mTest5: B-tree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest5: B-tree Failed :(\x1b[0m" ; fi

testdiff6:
	@if diff -a $(EDIR).tree tree/$(E)_huff.tree &> /dev/null ; then echo -e "\x1b[32mTest6: E-tree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest6: E-tree Failed :(\x1b[0m" ; fi

testdiff7:
	@if diff -a $(GDIR).ori decoded/$(G) &> /dev/null ; then echo -e "\x1b[32mTest7: G-ori Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest7: G-ori Failed :(\x1b[0m" ; fi

testdiff8:
	@if diff -a $(LDIR).ori decoded/$(L) &> /dev/null ; then echo -e "\x1b[32mTest8: L-ori Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest8: L-ori Failed :(\x1b[0m" ; fi

testdiff9:
	@if diff -a $(SDIR).ori decoded/$(S) &> /dev/null ; then echo -e "\x1b[32mTest9: S-ori Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest9: S-ori Failed :(\x1b[0m" ; fi

testdiff10:
	@if diff -a $(WDIR).ori decoded/$(W) &> /dev/null ; then echo -e "\x1b[32mTest10: W-ori Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest10: W-ori Failed :(\x1b[0m" ; fi

testdiff11:
	@if diff -a $(BDIR).ori decoded/$(B) &> /dev/null ; then echo -e "\x1b[32mTest11: B-ori Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest11: B-ori Failed :(\x1b[0m" ; fi

testdiff12:
	@if diff -a $(EDIR).ori decoded/$(E) &> /dev/null ; then echo -e "\x1b[32mTest12: E-ori Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest12: E-ori Failed :(\x1b[0m" ; fi

testdiff13:
	@if diff -a $(GDIR).count count/$(G).count &> /dev/null ; then echo -e "\x1b[32mTest13: G-count Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest13: G-count Failed :(\x1b[0m" ; fi

testdiff14:
	@if diff -a $(LDIR).count count/$(L).count &> /dev/null ; then echo -e "\x1b[32mTest14: L-count Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest14: L-count Failed :(\x1b[0m" ; fi

testdiff15:
	@if diff -a $(SDIR).count count/$(S).count &> /dev/null ; then echo -e "\x1b[32mTest15: S-count Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest15: S-count Failed :(\x1b[0m" ; fi

testdiff16:
	@if diff -a $(WDIR).count count/$(W).count &> /dev/null ; then echo -e "\x1b[32mTest16: W-count Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest16: W-count Failed :(\x1b[0m" ; fi

testdiff17:
	@if diff -a $(BDIR).count count/$(B).count &> /dev/null ; then echo -e "\x1b[32mTest17: B-count Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest17: B-count Failed :(\x1b[0m" ; fi

testdiff18:
	@if diff -a $(EDIR).count count/$(E).count &> /dev/null ; then echo -e "\x1b[32mTest18: E-count Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest18: E-count Failed :(\x1b[0m" ; fi

testdiff19:
	@if diff -a $(GDIR).htree tree/$(G)_huff.tree &> /dev/null ; then echo -e "\x1b[32mTest19: G-htree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest19: G-htree Failed :(\x1b[0m" ; fi

testdiff20:
	@if diff -a $(LDIR).htree tree/$(L)_huff.tree &> /dev/null ; then echo -e "\x1b[32mTest20: L-htree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest20: L-htree Failed :(\x1b[0m" ; fi

testdiff21:
	@if diff -a $(SDIR).htree tree/$(S)_huff.tree &> /dev/null ; then echo -e "\x1b[32mTest21: S-htree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest21: S-htree Failed :(\x1b[0m" ; fi

testdiff22:
	@if diff -a $(WDIR).htree tree/$(W)_huff.tree &> /dev/null ; then echo -e "\x1b[32mTest22: W-htree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest22: W-htree Failed :(\x1b[0m" ; fi

testdiff23:
	@if diff -a $(BDIR).htree tree/$(B)_huff.tree &> /dev/null ; then echo -e "\x1b[32mTest23: B-htree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest23: B-htree Failed :(\x1b[0m" ; fi

testdiff24:
	@if diff -a $(EDIR).htree tree/$(E)_huff.tree &> /dev/null ; then echo -e "\x1b[32mTest24: E-htree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest24: E-htree Failed :(\x1b[0m" ; fi

testdiff25:
	@if diff -a $(GDIR).eval eval/$(G)_huff.eval &> /dev/null ; then echo -e "\x1b[32mTest25: G-eval Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest25: G-eval Failed :(\x1b[0m" ; fi

testdiff26:
	@if diff -a $(LDIR).eval eval/$(L)_huff.eval &> /dev/null ; then echo -e "\x1b[32mTest26: L-eval Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest26: L-eval Failed :(\x1b[0m" ; fi

testdiff27:
	@if diff -a $(SDIR).eval eval/$(S)_huff.eval &> /dev/null ; then echo -e "\x1b[32mTest27: S-eval Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest27: S-eval Failed :(\x1b[0m" ; fi

testdiff28:
	@if diff -a $(WDIR).eval eval/$(W)_huff.eval &> /dev/null ; then echo -e "\x1b[32mTest28: W-eval Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest28: W-eval Failed :(\x1b[0m" ; fi

testdiff29:
	@if diff -a $(BDIR).eval eval/$(B)_huff.eval &> /dev/null ; then echo -e "\x1b[32mTest29: B-eval Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest29: B-eval Failed :(\x1b[0m" ; fi

testdiff30:
	@if diff -a $(EDIR).eval eval/$(E)_huff.eval &> /dev/null ; then echo -e "\x1b[32mTest30: E-eval Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest30: E-eval Failed :(\x1b[0m" ; fi

testdiff31:
	@if diff -a $(GNDIR).tree tree/$(G)_nonhuff.tree &> /dev/null ; then echo -e "\x1b[32mTest31: G nonhuff-tree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest31: G nonhuff-tree Failed :(\x1b[0m" ; fi

testdiff32:
	@if diff -a $(LNDIR).tree tree/$(L)_nonhuff.tree &> /dev/null ; then echo -e "\x1b[32mTest32: L nonhuff-tree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest32: L nonhuff-tree Failed :(\x1b[0m" ; fi

testdiff33:
	@if diff -a $(SNDIR).tree tree/$(S)_nonhuff.tree &> /dev/null ; then echo -e "\x1b[32mTest33: S nonhuff-tree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest33: S nonhuff-tree Failed :(\x1b[0m" ; fi

testdiff34:
	@if diff -a $(WNDIR).tree tree/$(W)_nonhuff.tree &> /dev/null ; then echo -e "\x1b[32mTest34: W nonhuff-tree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest34: W nonhuff-tree Failed :(\x1b[0m" ; fi

testdiff35:
	@if diff -a $(BNDIR).tree tree/$(B)_nonhuff.tree &> /dev/null ; then echo -e "\x1b[32mTest35: B nonhuff-tree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest35: B nonhuff-tree Failed :(\x1b[0m" ; fi

testdiff36:
	@if diff -a $(ENDIR).tree tree/$(E)_nonhuff.tree &> /dev/null ; then echo -e "\x1b[32mTest36: E nonhuff-tree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest36: E nonhuff-tree Failed :(\x1b[0m" ; fi

testdiff37:
	@if diff -a $(GNDIR).ori decoded/$(G) &> /dev/null ; then echo -e "\x1b[32mTest37: G nonhuff-ori Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest37: G nonhuff-ori Failed :(\x1b[0m" ; fi

testdiff38:
	@if diff -a $(LNDIR).ori decoded/$(L) &> /dev/null ; then echo -e "\x1b[32mTest38: L nonhuff-ori Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest38: L nonhuff-ori Failed :(\x1b[0m" ; fi

testdiff39:
	@if diff -a $(SNDIR).ori decoded/$(S) &> /dev/null ; then echo -e "\x1b[32mTest39: S nonhuff-ori Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest39: S nonhuff-ori Failed :(\x1b[0m" ; fi

testdiff40:
	@if diff -a $(WNDIR).ori decoded/$(W) &> /dev/null ; then echo -e "\x1b[32mTest40: W nonhuff-ori Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest40: W nonhuff-ori Failed :(\x1b[0m" ; fi

testdiff41:
	@if diff -a $(BNDIR).ori decoded/$(B) &> /dev/null ; then echo -e "\x1b[32mTest41: B nonhuff-ori Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest41: B nonhuff-ori Failed :(\x1b[0m" ; fi

testdiff42:
	@if diff -a $(ENDIR).ori decoded/$(E) &> /dev/null ; then echo -e "\x1b[32mTest42: E nonhuff-ori Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest42: E nonhuff-ori Failed :(\x1b[0m" ; fi

testdiff43:
	@if diff -a $(GNDIR).count count/$(G).count &> /dev/null ; then echo -e "\x1b[32mTest43: G nonhuff-count Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest43: G nonhuff-count Failed :(\x1b[0m" ; fi

testdiff44:
	@if diff -a $(LNDIR).count count/$(L).count &> /dev/null ; then echo -e "\x1b[32mTest44: L nonhuff-count Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest44: L nonhuff-count Failed :(\x1b[0m" ; fi

testdiff45:
	@if diff -a $(SNDIR).count count/$(S).count &> /dev/null ; then echo -e "\x1b[32mTest45: S nonhuff-count Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest45: S nonhuff-count Failed :(\x1b[0m" ; fi

testdiff46:
	@if diff -a $(WNDIR).count count/$(W).count &> /dev/null ; then echo -e "\x1b[32mTest46: W nonhuff-count Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest46: W nonhuff-count Failed :(\x1b[0m" ; fi

testdiff47:
	@if diff -a $(BNDIR).count count/$(B).count &> /dev/null ; then echo -e "\x1b[32mTest47: B nonhuff-count Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest47: B nonhuff-count Failed :(\x1b[0m" ; fi

testdiff48:
	@if diff -a $(ENDIR).count count/$(E).count &> /dev/null ; then echo -e "\x1b[32mTest48: E nonhuff-count Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest48: E nonhuff-count Failed :(\x1b[0m" ; fi

testdiff49:
	@if diff -a $(GNDIR).htree tree/$(G)_huff.tree &> /dev/null ; then echo -e "\x1b[32mTest49: G nonhuff-htree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest49: G nonhuff-htree Failed :(\x1b[0m" ; fi

testdiff50:
	@if diff -a $(LNDIR).htree tree/$(L)_huff.tree &> /dev/null ; then echo -e "\x1b[32mTest50: L nonhuff-htree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest50: L nonhuff-htree Failed :(\x1b[0m" ; fi

testdiff51:
	@if diff -a $(SNDIR).htree tree/$(S)_huff.tree &> /dev/null ; then echo -e "\x1b[32mTest51: S nonhuff-htree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest51: S nonhuff-htree Failed :(\x1b[0m" ; fi

testdiff52:
	@if diff -a $(WNDIR).htree tree/$(W)_huff.tree &> /dev/null ; then echo -e "\x1b[32mTest52: W nonhuff-htree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest52: W nonhuff-htree Failed :(\x1b[0m" ; fi

testdiff53:
	@if diff -a $(BNDIR).htree tree/$(B)_huff.tree &> /dev/null ; then echo -e "\x1b[32mTest53: B nonhuff-htree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest53: B nonhuff-htree Failed :(\x1b[0m" ; fi

testdiff54:
	@if diff -a $(ENDIR).htree tree/$(E)_huff.tree &> /dev/null ; then echo -e "\x1b[32mTest54: E nonhuff-htree Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest54: E nonhuff-htree Failed :(\x1b[0m" ; fi

testdiff55:
	@if diff -a $(GNDIR).eval eval/$(G)_nonhuff.eval &> /dev/null ; then echo -e "\x1b[32mTest55: G nonhuff-eval Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest55: G nonhuff-eval Failed :(\x1b[0m" ; fi

testdiff56:
	@if diff -a $(LNDIR).eval eval/$(L)_nonhuff.eval &> /dev/null ; then echo -e "\x1b[32mTest56: L nonhuff-eval Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest56: L nonhuff-eval Failed :(\x1b[0m" ; fi

testdiff57:
	@if diff -a $(SNDIR).eval eval/$(S)_nonhuff.eval &> /dev/null ; then echo -e "\x1b[32mTest57: S nonhuff-eval Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest57: S nonhuff-eval Failed :(\x1b[0m" ; fi

testdiff58:
	@if diff -a $(WNDIR).eval eval/$(W)_nonhuff.eval &> /dev/null ; then echo -e "\x1b[32mTest58: W nonhuff-eval Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest58: W nonhuff-eval Failed :(\x1b[0m" ; fi

testdiff59:
	@if diff -a $(BNDIR).eval eval/$(B)_nonhuff.eval &> /dev/null ; then echo -e "\x1b[32mTest59: B nonhuff-eval Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest59: B nonhuff-eval Failed :(\x1b[0m" ; fi

testdiff60:
	@if diff -a $(ENDIR).eval eval/$(E)_nonhuff.eval &> /dev/null ; then echo -e "\x1b[32mTest60: E nonhuff-eval Passed :)\x1b[0m" ; else echo -e "\x1b[31mTest60: E nonhuff-eval Failed :(\x1b[0m" ; fi

G=gophers
L=lorum
S=stone
W=woods
B=binary1
E=empty

GDIR=tests/$(G)_huff/$(G)_huff_test
LDIR=tests/$(L)_huff/$(L)_huff_test
SDIR=tests/$(S)_huff/$(S)_huff_test
WDIR=tests/$(W)_huff/$(W)_huff_test
BDIR=tests/$(B)_huff/$(B)_huff_test
EDIR=tests/$(E)_huff/$(E)_huff_test

GNDIR=tests/$(G)_huff/$(G)_nonhuff_test
LNDIR=tests/$(L)_huff/$(L)_nonhuff_test
SNDIR=tests/$(S)_huff/$(S)_nonhuff_test
WNDIR=tests/$(W)_huff/$(W)_nonhuff_test
BNDIR=tests/$(B)_huff/$(B)_nonhuff_test
ENDIR=tests/$(E)_huff/$(E)_nonhuff_test

hufftests: test1 test2 test3 test4 test5 test11

nonhufftests: test6 test7 test8 test9 test10 test12

valtests: vtest1 vtest2 vtest3 vtest4 vtest5 vtest6

test0:
	valgrind ./$(TEST_EXE)

vtest1:
	valgrind --leak-check=full ./$(TEST_EXE) encoded/$(G)_huff.hbt $(GDIR).tree $(GDIR).ori $(GDIR).count $(GDIR).htree $(GDIR).eval  

vtest2:
	valgrind ./$(TEST_EXE) encoded/$(L)_huff.hbt $(LDIR).tree $(LDIR).ori $(LDIR).count $(LDIR).htree $(LDIR).eval  --leak-check=full

vtest3:
	valgrind ./$(TEST_EXE) encoded/$(S)_huff.hbt $(SDIR).tree $(SDIR).ori $(SDIR).count $(SDIR).htree $(SDIR).eval --leak-check=full

vtest4:
	valgrind ./$(TEST_EXE) encoded/$(W)_huff.hbt $(WDIR).tree $(WDIR).ori $(WDIR).count $(WDIR).htree $(WDIR).eval --leak-check=full

vtest5:
	valgrind ./$(TEST_EXE) encoded/$(B)_huff.hbt $(BDIR).tree $(BDIR).ori $(BDIR).count $(BDIR).htree $(BDIR).eval --leak-check=full

vtest6:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_EXE) encoded/$(E)_huff.hbt $(EDIR).tree $(EDIR).ori $(EDIR).count $(EDIR).htree $(EDIR).eval 

test1:
	./$(TEST_EXE) encoded/$(G)_huff.hbt $(GDIR).tree $(GDIR).ori $(GDIR).count $(GDIR).htree $(GDIR).eval 

test2:
	./$(TEST_EXE) encoded/$(L)_huff.hbt $(LDIR).tree $(LDIR).ori $(LDIR).count $(LDIR).htree $(LDIR).eval 

test3:
	./$(TEST_EXE) encoded/$(S)_huff.hbt $(SDIR).tree $(SDIR).ori $(SDIR).count $(SDIR).htree $(SDIR).eval 

test4:
	./$(TEST_EXE) encoded/$(W)_huff.hbt $(WDIR).tree $(WDIR).ori $(WDIR).count $(WDIR).htree $(WDIR).eval 

test5:
	./$(TEST_EXE) encoded/$(B)_huff.hbt $(BDIR).tree $(BDIR).ori $(BDIR).count $(BDIR).htree $(BDIR).eval 

test6:
	./$(TEST_EXE) encoded/$(G)_nonhuff.hbt $(GNDIR).tree $(GNDIR).ori $(GNDIR).count $(GNDIR).htree $(GNDIR).eval 

test7:
	./$(TEST_EXE) encoded/$(L)_nonhuff.hbt $(LNDIR).tree $(LNDIR).ori $(LNDIR).count $(LNDIR).htree $(LNDIR).eval 

test8:
	./$(TEST_EXE) encoded/$(S)_nonhuff.hbt $(SNDIR).tree $(SNDIR).ori $(SNDIR).count $(SNDIR).htree $(SNDIR).eval 

test9:
	./$(TEST_EXE) encoded/$(W)_nonhuff.hbt $(WNDIR).tree $(WNDIR).ori $(WNDIR).count $(WNDIR).htree $(WNDIR).eval 

test10:
	./$(TEST_EXE) encoded/$(B)_nonhuff.hbt $(BNDIR).tree $(BNDIR).ori $(BNDIR).count $(BNDIR).htree $(BNDIR).eval 

test11:
	./$(TEST_EXE) encoded/$(E)_huff.hbt $(EDIR).tree $(EDIR).ori $(EDIR).count $(EDIR).htree $(EDIR).eval 

test12:
	./$(TEST_EXE) encoded/$(E)_nonhuff.hbt $(ENDIR).tree $(ENDIR).ori $(ENDIR).count $(ENDIR).htree $(ENDIR).eval 

debug: $(SRC_C) $(TEST_C)
	$(CC) -DDEBUG -o $(TEST_EXE) $(SRC_C) $(TEST_C) $(CFLAGS) 

clean: 
	rm -f $(TEST_EXE) *.c.gcov *.gcda *.gcno *.swp

.PHONY: submit test pretest coverage
