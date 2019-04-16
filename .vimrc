" configuração .vimrc
execute pathogen#infect()
set nocompatible
set magic
set path+=**
set wildmenu
command! MakeTags !ctags -R .

"######### ajustes para navegar ###########    

let g:netrw_banner=0        "desativar banner irritante
let g:netrw_browse_split=4  "abrir na janela anterior
let g:netrw_altv=1          "divisão aberta à direita
let g:netrw_liststyle=3     "visão de árvore
let g:netrw_list_hide=netrw_gitignore#Hide()
let g:netrw_list_hide.=',\(^\|\s\s)\zs\.\S\+'

"######### ajustes para navegar ###########    

"######### esqueletos prontos ###########    

nnoremap \html :-1read $HOME/.vim/.esqueletos/.esqueleto.html<CR>5jwf>a

"######### esqueletos prontos ###########    

set shell=sh "nerdtree-git-plugin
"NERDTree automaticamente quando o vim é inicializado
autocmd VimEnter * NERDTree
autocmd BufEnter * NERDTreeMirror
set updatetime=100
set title "Mostra o nome do arquivo na parte superior do prompt
syntax enable "habilita cores a syntax hightligth
set number       "mostra numeração de linhas
set relativenumber "mostra a relação de números conforme a posição do cursor
set ruler
set backspace=indent,eol,start "Faz o backspace funcionar
set showmode "mostra o modo em que estamos
set showcmd  "mostra no status os comandos inseridos
set wildmode=list:longest,full "tab com complemento de palavras automático
set showmatch "mostra os caracteres abertos '(', '{' e '['quando são fechados
" quando sao fechados.
"setlocal textwidth=78 "largura do texto
"set linebreak
"set wrap     "quebra de linha
set ts=4     "tamanho das tabulações
set hls      "destaca com cores os termos procurados
set incsearch "habilita a busca incremental
set ai       "auto identação
set aw       "salvamento automático - veja :help aw
set ignorecase "faz o vim ignorar maiúsculas e minúsculas nas buscas
set smartcase  "Se começar uma busca em maiúsculo ele habilita o case
set ic        "ignora maiúscula e minúsculas em uma busca
set scs       "ao fazer uma busca com maiúsculos considerar case sensitive
set backup
set backupext=.backup
set backupdir=~/.backup,./
"set cul        "abreviação de cursor line (destaca linha atual)
"set ve=all     "permite mover o cursor para áreas onde não há texto
"set ttyfast    "Envia mais caracteres ao terminal, melhorando o redraw de janelas. 
"set columns=75 "Determina a largura da janela.
"set colorcolumn=75 "Determina a largura da janela.
set mousemodel=popup "exibe o conteúdo de folders e sugestões spell

" barra de status gitgutter
if exists('&signcolumn')  " Vim 7.4.2201
  set signcolumn=yes
else
  let g:gitgutter_sign_column_always = 1
endif

"############## compilando em gcc ########

map <F7> :w <CR> :!gcc % -o %< && ./%< <CR>

"############## compilando em gcc ########

"############## PowerLine #################

let g:airline_theme='badwolf'

"############## PowerLine #################

" barra de status
set statusline=%F%m%r%h%w\ [Formato=%{&ff}]\ [Tipo=%Y]\ [Ascii=\%03.3b]\ [Hex=\%02.2B]\ [Posicao=%04l,%04v][%p%%]\ [Tamanho=%L\ linhas]
set laststatus=2

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

"O present.vim é um plugin vim que transforma sua marcação em slides apresentáveis.
au FileType rst let b:presenting_slide_separator = '\v(^|\n)\~{4,}'

" Este pacote vim adiciona realce de sintaxe, recuo e autocompletar para a linguagem de folha de estilo dinâmica LESS.
nnoremap <Leader>m :w <BAR> !lessc % > %:t:r.css<CR><space>


"##################### HTML #####################################

"Os mapeamentos abaixo são úteis para quem escreve códigos HTML, permitem inserir caracteres reservados do HTML usando uma barra invertida para proteger os mesmos, o Vim substituirá os “barra alguma coisa” pelo caractere correspondente.

inoremap \&amp; &amp;amp;
inoremap \&lt; &amp;lt;
inoremap \&gt; &amp;gt;
inoremap \. &amp;middot;

"##################### HTML #####################################

"##################### CSS E FERAMENTAS #########################

" Autocompletar CSS nativamente 'Ctrl' + 'x' and 'Ctrl' + 'o' e 'Ctrl' + 'n' puxa tag de outro arquivo aberto.
filetype plugin on
set omnifunc=syntaxcomplete#complete
imap <c-k> <c-x><c-o>

"Para destacar elementos CSS, este plugin conta com css.vim que vem junto com o Vim. Infelizmente, o suporte para CSS3 é apenas rudimentar. Para evitar problemas de destaque, eu recomendo instalar o plugin vim-css3-syntax.
au BufRead,BufNewFile *.scss set filetype=scss.css
autocmd FileType scss set iskeyword+=-

"Algumas propriedades não são realçadas corretamente por padrão. Esta é uma limitação de Mecanismo de prioridade de destaque do Vim.
augroup VimCSS3Syntax
      autocmd!

      autocmd FileType css setlocal iskeyword+=-
    augroup END
"##################### CSS E FERAMENTAS #########################

" script que fecha caracteres '(', '{' e '['
inoremap ( ()<esc>:call BC_AddChar(")")<cr>i
inoremap { {}<esc>:call BC_AddChar("}")<cr>i
inoremap [ []<esc>:call BC_AddChar("]")<cr>i

inoremap <C-j> <esc>:call search(BC_GetChar(), "W")<cr>a

function! BC_AddChar(schar)
    if exists("b:robstack")
        let b:robstack = b:robstack . a:schar
    else
        let b:robstack = a:schar
    endif
endfunction

function! BC_Char()
    let l:char = b:robstack[strlen(b:robstack) - 1]
    let b:robstack = strpart(b:robstack, 0, strlen(b:robstack) - 1)
    return l:char
endfunction

function! InsertPathFile()
	normal(1G)
	call append(1, "// " . expand("%:p"))
	normal($)
endfun
map <F3> :call InsertPathFile()<cr>

" Cria um cabeçalho para programar em c
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
function! InsertHeadPy()
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

" quando abre o arquivo coloca o cursor no ultimo ponto em q se encontrava antes de sair
autocmd bufreadpost *
    \ if line("'\"") > 0 && line("'\"") <= line("$") |
    \   exe "normal g `\"" |
    \ endif

"Fechamento automático de Tags HTML
imap ><Tab> ><Esc>mt?<\w<Cr>:let @/=""<Cr>lyiw`ta</><Esc>P`tli

" salva com F9
map <F8> :w<cr>

" F10 - sai do Vim
map <F9> <Esc>:q<cr>

" permite recarregar o vim para que as modificacoes no .vimrc sejam ativadas
nmap <F12> :<C-u>source $HOME/.vimrc <BAR> echo "Vimrc recarregado!"<CR>

"Repetições de Repeat.vim. de uma forma que os plugins podem tocar nele.
silent! call repeat#set("\<Plug>MyWonderfulMap", v:count)
