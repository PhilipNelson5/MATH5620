import os
import ycm_core

flags = [
'-Wall',
'-Wextra',
'-Werror',
'-Wno-long-long',
'-Wno-variadic-macros',
'-fexceptions',
'-DNDEBUG',
'-DUSE_CLANG_COMPLETER',
'-std=c++17',
'-x',
'c++'
]

def FlagsForFile( filename, **kwargs ):
  return {
    'flags' : flags
  }
