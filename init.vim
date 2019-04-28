call plug#begin()

" Estética - principal
Plug 'dracula/vim', { 'commit': '147f389f4275cec4ef43ebc25e2011c57b45cc00' }
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
" Airline
let g:airline_powerline_fonts = 1
let g:airline_section_z = ' %{strftime("%-I:%M %p")}'
let g:airline_section_warning = ''
"let g:airline#extensions#tabline#enabled = 1
Plug 'ryanoasis/vim-devicons'
set guifont=DroidSansMono\ Nerd\ Font\ 11
Plug 'junegunn/goyo.vim'
Plug 'junegunn/limelight.vim'
Plug 'junegunn/seoul256.vim'
Plug 'junegunn/vim-journal'
Plug 'junegunn/rainbow_parentheses.vim'
Plug 'nightsense/forgotten'
Plug 'zaki/zazen'

" Estética - adicinal
Plug 'nightsense/nemo'
Plug 'yuttie/hydrangea-vim'
Plug 'chriskempson/tomorrow-theme', { 'rtp': 'vim' }
Plug 'rhysd/vim-color-spring-night'

" Funcionalidades
Plug 'tpope/vim-fugitive'
Plug 'tpope/vim-sensible'
Plug 'tpope/vim-surround'
Plug 'majutsushi/tagbar'
" TagBar
let g:tagbar_width = 30
let g:tagbar_iconchars = ['↠', '↡']
Plug 'scrooloose/nerdtree'
Plug 'scrooloose/nerdcommenter'
" NERDTree
let NERDTreeShowHidden=1
let g:NERDTreeDirArrowExpandable = '↠'
let g:NERDTreeDirArrowCollapsible = '↡'
"NERDTree automaticamente quando o vim é inicializado
autocmd VimEnter * NERDTree
autocmd BufEnter * NERDTreeMirror
Plug 'Shougo/deoplete.nvim', { 'do': ':UpdateRemotePlugins' }
Plug 'zchee/deoplete-jedi'
" Deoplete
let g:deoplete#enable_at_startup = 1
" Disable documentation window
set completeopt-=preview
Plug 'ervandew/supertab'
" Supertab
let g:SuperTabDefaultCompletionType = "<C-n>"
Plug 'jiangmiao/auto-pairs'
Plug 'junegunn/vim-easy-align'
" EasyAlign
xmap ga <Plug>(EasyAlign)
nmap ga <Plug>(EasyAlign)<Paste>
Plug 'alvan/vim-closetag'
Plug 'tpope/vim-abolish'
Plug 'Yggdroot/indentLine'
" indentLine
let g:indentLine_char = '▏'
let g:indentLine_color_gui = '#363949'
Plug 'morhetz/gruvbox'
Plug 'terryma/vim-multiple-cursors'
Plug 'sheerun/vim-polyglot'
Plug 'chrisbra/Colorizer'
Plug 'heavenshell/vim-pydocstring'
Plug 'vim-scripts/loremipsum'
Plug 'junegunn/fzf', { 'dir': '~/.fzf', 'do': './install --all' }
Plug 'junegunn/fzf.vim'
" fzf-vim
let g:fzf_action = {
  \ 'ctrl-t': 'tab split',
  \ 'ctrl-s': 'split',
  \ 'ctrl-v': 'vsplit' }
let g:fzf_colors =
\ { 'fg':      ['fg', 'Normal'],
  \ 'bg':      ['bg', 'Normal'],
  \ 'hl':      ['fg', 'Comment'],
  \ 'fg+':     ['fg', 'CursorLine', 'CursorColumn', 'Normal'],
  \ 'bg+':     ['bg', 'CursorLine', 'CursorColumn'],
  \ 'hl+':     ['fg', 'Statement'],
  \ 'info':    ['fg', 'Type'],
  \ 'border':  ['fg', 'Ignore'],
  \ 'prompt':  ['fg', 'Character'],
  \ 'pointer': ['fg', 'Exception'],
  \ 'marker':  ['fg', 'Keyword'],
  \ 'spinner': ['fg', 'Label'],
  \ 'header':  ['fg', 'Comment'] }
Plug 'roxma/nvim-completion-manager'
Plug 'w0rp/ale'
Plug 'cohama/lexima.vim'
Plug 'SirVer/ultisnips'
Plug 'honza/vim-snippets'
Plug 'honza/vim-snippets'
" Ultisnips
let g:UltiSnipsExpandTrigger="<C-Space>"
let g:UltiSnipsJumpForwardTrigger="<Tab>"
let g:UltiSnipsJumpBackwardTrigger="<C-x>"
Plug 'metakirby5/codi.vim'
Plug 'dkarter/bullets.vim'
call plug#end()

let g:python_host_prog  = expand('~/.config/nvim/env/bin/python')
let g:python3_host_prog  = expand('~/.config/nvim/env/bin/python3')
let g:ruby_host_prog  = '/usr/bin/ruby'

""" Coloring
syntax on
color dracula
highlight Pmenu guibg=white guifg=black gui=bold
highlight Comment gui=bold
highlight Normal gui=none
highlight NonText guibg=none

" Fundo Opaco (Comentário para usar o perfil do terminal)
set termguicolors

" Outras configurações
filetype plugin indent on
set tabstop=4 softtabstop=4 shiftwidth=4 expandtab smarttab autoindent
set incsearch ignorecase smartcase hlsearch
set ruler laststatus=2 showcmd showmode
set list listchars=trail:»,tab:»-
set fillchars+=vert:\ 
set wrap breakindent
set number
set title
set hidden
set relativenumber
set mouse=a
set magic
set path+=**
set wildmenu
set aw       "salvamento automático - veja :help aw
set ic        "ignora maiúscula e minúsculas em uma busca
set scs       "ao fazer uma busca com maiúsculos considerar case sensitive"
command! MakeTags !ctags -R .
set inccommand=split
set clipboard+=unnamedplus


let mapleader="\<space>"

nnoremap <leader>; A;<esc>
nnoremap <leader>sv :source $MYVIMRC<cr>
nnoremap <c-p> :Files<cr>
nnoremap <c-f> :Ag<space>

let g:UltiSnipsEditSplit="vertical"
let g:UltiSnipsSnippetsDir = '~/.config/nvim/UltiSnips'

"Deixar o cursor centralizado
set scrolloff=1000
if !exists('*VCenterCursor')
  augroup VCenterCursor
  au!
  au OptionSet *,*.*
    \ if and( expand("<amatch>")=='scrolloff' ,
    \         exists('#VCenterCursor#WinEnter,WinNew,VimResized') )|
    \   au! VCenterCursor WinEnter,WinNew,VimResized|
    \ endif
augroup END
function VCenterCursor()
  if !exists('#VCenterCursor#WinEnter,WinNew,VimResized')
    let s:default_scrolloff=&scrolloff
    let &scrolloff=winheight(win_getid())/2
    au VCenterCursor WinEnter,WinNew,VimResized *,*.*
      \ let &scrolloff=winheight(win_getid())/2
  else
    au! VCenterCursor WinEnter,WinNew,VimResized
    let &scrolloff=s:default_scrolloff
  endif
 endfunction
endif

nnoremap <leader>zz :call VCenterCursor()<CR>

function! InsertPathFile()
   normal(1G)
   call append(1, "// " . expand("%:p"))
   normal($)
endfun
map <F3> :call InsertPathFile()<cr>

"Cria um cabeçalho para programar em c
function! InsertHeadclang()
   normal(1G)
   call append(0, "// " . expand("%:p"))
   call append(1, "// Criado em:" . strftime("%a %d/%b/%Y hs %H:%M"))
   call append(2, "/* Propósito:  */")
   call append(3, "// Cadeira:")
   call append(4, "// Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)")
   normal($)
endfun
map <F4> :call InsertHeadclang()<cr>

" Cria um cabeçalho para scripts bash
function! InsertHeadBash()
   normal(1G)
   call append(0, "#!/bin/bash")
   call append(1, "#  " . expand("%:p"))
   call append(2, "# Criado em:" . strftime("%a %d/%b/%Y hs %H:%M"))
   call append(3, "# Propósito: ")
   call append(4, "# Cadeira:")
   call append(5, "# Autor: Bruno César Angst; (bruno.angst@rede.ulbra.br)")
   normal($)
endfun
map <F5> :call InsertHeadBash()<cr>

" cria um cabecalho para os python scripts
function! InsertHeadPy()"
   normal(1G)
   call append(0, "#!/usr/bin/env python")
   call append(1, "#  " . expand("%:p"))
   call append(2, "# Criado em: " . strftime("%a %d/%b/%Y hs %H:%M"))
   call append(3, "# Propósito: ")
   call append(4, "# Cadeira:")
   call append(5, "# Autor: Bruno César Angst (bruno.angst@rede.ulbra.br)")
   normal($)
endfun
map <F6> :call InsertHeadPy()<cr>

"salva com F8
map <F8> <Esc>:w<cr>

" F9 - sai do Vim
map <F9> <Esc>:q<cr>

