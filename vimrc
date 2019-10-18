
"**************************************************************************************
" 自动折行
set wrap

"折叠
set foldmethod=syntax
set foldlevelstart=99
nnoremap <space> @=((foldclosed(line('.'))<0)?'zc':'zo')<CR>

"背景颜色
"set background=light
set t_Co=256

set number
"模式
"let g:solarized_termtrans=1
colorscheme desert

" 不要使用vi的键盘模式，而是vim自己的
set nocompatible

" history文件中需要记录的行数
set history=100

" 在处理未保存或只读文件的时候，弹出确认
set confirm

" 与windows共享剪贴板
set clipboard+=unnamed

" 侦测文件类型
filetype on

" 载入文件类型插件
filetype plugin on

" 为特定文件类型载入相关缩进文件
filetype indent on

" 保存全局变量
set viminfo+=!


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" 文件设置
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" 不要备份文件（根据自己需要取舍）
set nobackup

" 不要生成swap文件，当buffer被丢弃的时候隐藏它
setlocal noswapfile
set bufhidden=hide

" 字符间插入的像素行数目
set linespace=0

" 增强模式中的命令行自动完成操作
set wildmenu

" 在状态行上显示光标所在位置的行号和列号
"set ruler
"set rulerformat=%20(%2*%<%f%=\ %m%r\ %3l\ %c\ %p%%%)

" 命令行（在状态行下）的高度，默认为1，这里是2
set cmdheight=2

" 使回格键（backspace）正常处理indent, eol, start等
set backspace=2

" 允许backspace和光标键跨越行边界
set whichwrap+=<,>,h,l

" 可以在buffer的任何地方使用鼠标（类似office中在工作区双击鼠标定位）
set mouse=a
set selection=exclusive
set selectmode=mouse,key


" 通过使用: commands命令，告诉我们文件的哪一行被改变过
set report=0

" 不让vim发出讨厌的滴滴声
set noerrorbells

" 在被分割的窗口间显示空白，便于阅读
set fillchars=vert:\ ,stl:\ ,stlnc:\

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" 搜索和匹配
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" 高亮显示匹配的括号
set showmatch

" 匹配括号高亮的时间（单位是十分之一秒）
set matchtime=5

" 在搜索的时候忽略大小写
set ignorecase

" 不要高亮被搜索的句子（phrases）
set nohlsearch

" 在搜索时，输入的词句的逐字符高亮（类似firefox的搜索）
set incsearch

" 输入:set list命令是应该显示些啥？
set listchars=tab:\|\ ,trail:.,extends:>,precedes:<,eol:$

" 光标移动到buffer的顶部和底部时保持3行距离
set scrolloff=5

" 不要闪烁
set novisualbell

" 我的状态行显示的内容（包括文件类型和解码）
"set statusline=%F%m%r%h%w\[POS=%l,%v][%p%%]\%{strftime(\"%d/%m/%y\ -\ %H:%M\")}


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" 文本格式和排版
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set encoding=utf-8
set langmenu=zh_CN.UTF-8
set fileencodings=ucs-bom,utf-8,cp936,gb18030,gb2312,big5,euc-jp,euc-kr,latin1
" 自动格式化
"set formatoptions=tcrqn

" 继承前一行的缩进方式，特别适用于多行注释
set autoindent

" 为C程序提供自动缩进
"set smartindent

" 制表符为4
set tabstop=4
set shiftwidth=4

"设置为双字宽显示，否则无法完整显示如:☆
set ambiwidth=double

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" CTags的设定
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" 按照名称排序
let Tlist_Sort_Type = "name"

" 在右侧显示窗口
let Tlist_Use_Right_Window = 1

" 压缩方式
let Tlist_Compart_Format = 1

" 如果只有一个buffer，kill窗口也kill掉buffer
let Tlist_Exist_OnlyWindow = 1

" 不要关闭其他文件的tags
let Tlist_File_Fold_Auto_Close = 0

" 不要显示折叠树
let Tlist_Enable_Fold_Column = 0


"*********************************************************************
"*********************************************************************
call plug#begin('~/.vim/plugged')

" Make sure you use single quotes
" Plug 'junegunn/seoul256.vim'
"Plug 'junegunn/vim-easy-align'

" On-demand loading
Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }
Plug 'tpope/vim-fireplace', { 'for': 'clojure' }
Plug 'vim-airline/vim-airline-themes'
Plug 'vim-airline/vim-airline'
Plug 'Valloric/YouCompleteMe'
Plug 'Chiel92/vim-autoformat'
Plug 'wakatime/vim-wakatime'
" Using git URL
Plug 'https://github.com/majutsushi/tagbar.git'
Plug 'https://github.com/vim-syntastic/syntastic.git'
Plug 'https://github.com/jiangmiao/auto-pairs.git'

" Plugin options
"Plug 'nsf/gocode', { 'tag': 'go.weekly.2012-03-13', 'rtp': 'vim' }

" Plugin outside ~/.vim/plugged with post-update hook
"Plug 'junegunn/fzf', { 'dir': '~/.fzf', 'do': 'yes \| ./install' }

" Unmanaged plugin (manually installed and updated)
"Plug '~/my-prototype-plugin'

call plug#end()

"********************************************************************
"*********************tagbar*****************************************
nmap <F8> :TagbarToggle<CR>


"********************************************************************
"*********************auto-format************************************
nmap <F10> :Autoformat<CR>
:inoremap <F10> <Esc>:Autoformat<CR>a
let g:formatdef_harttle = '"astyle -A1 -C -f -k3 -xb -xy "'
let g:formatters_cs=['harttle']


"********************************************************************
"*********************nerdtree***************************************
"显示增强
let NERDChristmasTree=1
"自动调整焦点
let NERDTreeAutoCenter=1
"鼠标模式:目录单击,文件双击
"let NERDTreeMouseMode=2
""打开文件后自动关闭
let NERDTreeQuitOnOpen=0
"显示文件
"let NERDTreeShowFiles=1
""显示隐藏文件
let NERDTreeShowHidden=0
"高亮显示当前文件或目录
"let NERDTreeHightCursorline=1
""显示行号
let NERDTreeShowLineNumbers=1
"窗口位置
"let NERDTreeWinPos='left'
""窗口宽度
let NERDTreeWinSize=31
"不显示'Bookmarks' label 'Press ? for help'
"let NERDTreeMinimalUI=1
""快捷键
nnoremap <silent> <F2> :NERDTreeToggle<CR>
"当打开vim且没有文件时自动打开NERDTree
"autocmd vimenter * if !argc() | NERDTree | endif
""只剩 NERDTree时自动关闭
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTreeType") && b:NERDTreeType == "primary") | q | endif

" 设置当文件被改动时自动载入
" " set autoread

"********************************************************************
"********************airline*****************************************
set laststatus=2
let g:airline#extensions#tabline#enabled = 1
let g:airline_theme='dark'
let g:airline_powerline_fonts = 1

let g:airline_section_b = '%{getcwd()}'
"let g:airline_section_z = '%04c:%04l'
let g:airline#extensions#default#layout = [
			\ [ 'a', 'b'],
			\ [ 'x', 'y']
			\ ]
"let g:airline#extensions#syntastic#enabled = 1
"let g:airline#extensions#tagbar#enabled = 1
"let g:airline#extensions#ycm#enabled = 1

let g:airline#extensions#tabline#buffer_idx_mode = 1
nmap <leader>1 <Plug>AirlineSelectTab1
nmap <leader>2 <Plug>AirlineSelectTab2
nmap <leader>3 <Plug>AirlineSelectTab3
nmap <leader>4 <Plug>AirlineSelectTab4
nmap <leader>5 <Plug>AirlineSelectTab5
nmap <leader>6 <Plug>AirlineSelectTab6
nmap <leader>7 <Plug>AirlineSelectTab7
nmap <leader>8 <Plug>AirlineSelectTab8
nmap <leader>9 <Plug>AirlineSelectTab9


"function! AccentDemo()
"		let keys = ['W','e','l','c','o','m','e','!']
"		for k in keys
"				call airline#parts#define_text(k, k)
"		endfor
"		call airline#parts#define_accent('W', 'red')
"		call airline#parts#define_accent('e', 'green')
"		call airline#parts#define_accent('l', 'blue')
"		call airline#parts#define_accent('c', 'yellow')
"		call airline#parts#define_accent('o', 'orange')
"		call airline#parts#define_accent('m', 'purple')
"		call airline#parts#define_accent('e', 'bold')
"		call airline#parts#define_accent('!', 'italic')
"		let g:airline_section_a = airline#section#create(keys)
"endfunction
"autocmd VimEnter * call AccentDemo()

"******************************************************************
"********************syntastic*************************************
nmap <F12> :w <CR>
:inoremap <F12> <Esc>:w<CR>a
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 1
let g:syntastic_cpp_include_dirs = ['/usr/include/']
let g:syntastic_cpp_remove_include_errors = 1
let g:syntastic_cpp_check_header = 1
let g:syntastic_cpp_cflags = '-std=c++11 -w'
"let g:syntastic_cpp_compiler_options = '-std=c++11 -stdlib=libstdc++'
"set error or warning signs
let g:syntastic_error_symbol ='E' "'✗'
let g:syntastic_warning_symbol = 'W' "'⚠'
"whether to show balloons
let g:syntastic_enable_balloons = 1

"******************************************************************
"*****************************youcme*******************************
let g:ycm_global_ycm_extra_conf='~/.vim/plugged/YouCompleteMe/third_party/ycmd/.ycm_extra_conf.py'
set completeopt=longest,menu    "让Vim的补全菜单行为与一般IDE一致(参考VimTip1228)
autocmd InsertLeave * if pumvisible() == 0|pclose|endif "离开插入模式后自动关闭预览窗口
let g:ycm_confirm_extra_conf=0 "关闭加载.ycm_extra_conf.py提示
let g:ycm_collect_identifiers_from_tags_files=1 " 开启 YCM 基于标签引擎
let g:ycm_min_num_of_chars_for_completion=2 " 从第2个键入字符就开始罗列匹配项
let g:ycm_cache_omnifunc=0  " 禁止缓存匹配项,每次都重新生成匹配项
let g:ycm_seed_identifiers_with_syntax=1    " 语法关键字补全
let g:ycm_key_invoke_completion='<F5>'
let g:ycm_show_diagnostics_ui = 0

"******************************************************************
"*****************************settitle*******************************
" 当新建 .h .c .hpp .cpp .mk .sh等文件时自动调用SetTitle 函数
autocmd BufNewFile *.[ch],*.hpp,*.cc,makefile,*.mk,*.sh exec ":call SetTitle()"
" 加入注释
func SetComment()
	call setline(1,"/*================================================================")
	call append(line("."),   "*   Copyright (C) ".strftime("%Y")." D. All rights reserved.")
	call append(line(".")+1, "*   ")
	call append(line(".")+2, "*   文件名称：".expand("%:t"))
	call append(line(".")+3, "*   创 建 者：D")
	call append(line(".")+4, "*   创建日期：".strftime("%Y年%m月%d日"))
	call append(line(".")+5, "*   描    述：")
	call append(line(".")+6, "*")
	call append(line(".")+7, "================================================================*/")
	call append(line(".")+8, "")
	call append(line(".")+9, "#include <bits/stdc++.h>")
	call append(line(".")+10, "")
endfunc

" 加入shell,Makefile注释
func SetComment_sh()
	call setline(3, "#================================================================")
	call setline(4, "#   Copyright (C) ".strftime("%Y")." D. All rights reserved.")
	call setline(5, "#   ")
	call setline(6, "#   文件名称：".expand("%:t"))
	call setline(7, "#   创 建 者：D")
	call setline(8, "#   创建日期：".strftime("%Y年%m月%d日"))
	call setline(9, "#   描    述：")
	call setline(10, "#")
	call setline(11, "#================================================================")
endfunc

" 定义函数SetTitle，自动插入文件头
func SetTitle()
	if &filetype == 'make'
		call setline(1,"")
		call setline(2,"")
		call SetComment_sh()
	elseif &filetype == 'sh'
		call setline(1,"#!/system/bin/sh")
		call setline(2,"")
		call SetComment_sh()

	else
		call SetComment()
		if expand("%:e") == 'hpp'
			call append(line(".")+10, "#ifndef _".toupper(expand("%:t:r"))."_H")
			call append(line(".")+11, "#define _".toupper(expand("%:t:r"))."_H")
			call append(line(".")+12, "#ifdef __cplusplus")
			call append(line(".")+13, "extern \"C\"")
			call append(line(".")+14, "{")
			call append(line(".")+15, "#endif")
			call append(line(".")+16, "")
			call append(line(".")+17, "#ifdef __cplusplus")
			call append(line(".")+18, "}")
			call append(line(".")+19, "#endif")
			call append(line(".")+20, "#endif //".toupper(expand("%:t:r"))."_H")

		elseif expand("%:e") == 'h'
			call append(line(".")+10, "#pragma once")

		elseif &filetype == 'c'
			call append(line(".")+10,"#include \"".expand("%:t:r").".h\"")

		elseif &filetype == 'cc'
			call append(line(".")+10, "#include \"".expand("%:t:r").".h\"")

		endif

	endif
endfunc
