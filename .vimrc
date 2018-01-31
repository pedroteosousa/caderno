set ai si noet ts=4 sw=4 sta sm nu rnu
inoremap <NL> <ESC>o
nnoremap <NL> o
inoremap <C-up> <C-o>:m-2<CR>
inoremap <C-down> <C-o>:m+1<CR>
nnoremap <C-up> :m-2<CR>
nnoremap <C-down> :m+1<CR>
vnoremap <C-up> :m-2<CR>gv                                                  
vnoremap <C-down> :m'>+1<CR>gv

" easier control of split windows
nnoremap <C-J> <C-W><C-J>
nnoremap <C-K> <C-W><C-K>
nnoremap <C-L> <C-W><C-L>
nnoremap <C-H> <C-W><C-H>

" syntax highlighting and color scheme
syntax on
colors evening
highlight Normal ctermbg=none "No background
highlight nonText ctermbg=none


autocmd BufNewFile *.cpp :0r ~/.vim/cpp.skel
autocmd BufNewFile *.cpp +13
autocmd BufNewFile Makefile :0r ~/.vim/Makefile.skel

set columns=10

filetype indent on
