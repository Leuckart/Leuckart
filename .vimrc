
autocmd BufNewFile *.c,*.h,*.cpp,*.java,*.go,*.sh exec ":call SetTitle()" 

func SetTitle() 
	if &filetype == 'sh'
		call setline(1,"\##################################################") 
		call append(line("."), "\# File Name:  ".expand("%")) 
		call append(line(".")+1, "\# Author:  Leuckart")
		call append(line(".")+2, "\# Time:    ".strftime("%Y-%m-%d   %H:%M")) 
		call append(line(".")+3, "\##################################################") 
		call append(line(".")+4, "\#!/bin/bash") 
		call append(line(".")+5, "")
	else
		call setline(1, "/**************************************************") 
		call append(line("."), "	> File Name:  ".expand("%"))
		call append(line(".")+1, "	> Author:     Leuckart")
		call append(line(".")+2, "	> Time:       ".strftime("%Y-%m-%d %H:%M"))
		call append(line(".")+3, "**************************************************/") 
		call append(line(".")+4, "")
	endif
	autocmd BufNewFile * normal G
endfunc 

