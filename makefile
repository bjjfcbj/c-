#================================================================
#   Copyright (C) 2019 D. All rights reserved.
#
#   文件名称：makefile
#   创 建 者：D
#   创建日期：2019年10月18日
#   描    述：
#
#================================================================

command:=git

.PHONY: all

all:
	cd pat&&make clean&&cd ..&&$(command) add .&&$(command) commit -m ..&&$(command) push
