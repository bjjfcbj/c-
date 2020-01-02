

#================================================================
#   Copyright (C) 2019 D. All rights reserved.
#
#   文件名称：makefile
#   创 建 者：D
#   创建日期：2019年10月06日
#   描    述：
#
#================================================================

FLAG:=pat$(N).out
MAKE:=make all
cc:=clang++-8
SRC:=$(wildcard ./*.cc)
WORK:=$(patsubst ./%.cc, ./%.out, $(SRC))

run:
	$(MAKE)&&./$(FLAG)

all:$(WORK)

%.out:%.cc
	$(cc) -g $< -o $@

.PHONY: clean all run

clean:
	-rm *.out

