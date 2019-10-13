

#================================================================
#   Copyright (C) 2019 D. All rights reserved.
#
#   文件名称：makefile
#   创 建 者：D
#   创建日期：2019年10月06日
#   描    述：
#
#================================================================

cc:=clang++
SRC:=$(wildcard ./*.cc)
WORK:=$(patsubst ./%.cc, ./%.out, $(SRC))

all:$(WORK)

%.out:%.cc
	$(cc) -g $< -o $@

.PHONY: clean all

clean:
	-rm *.out

