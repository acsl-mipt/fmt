project('fmt', 'cpp', version : '4.1.0', default_options : ['cpp_std=c++11'])

check_code = '''
int main(int argc, char** argv)
{
    (void)argv;
#ifndef open
    return ((int*)(&${SYMBOL}))[argc];
#else
    (void)argc;
    return 0;
#endif
}
'''

cc = meson.get_compiler('cpp')

if target_machine.system() == 'windows'
  inc_prefix = '#include "io.h"\n'
else
  inc_prefix = '#include "fnctl.h"\n'
endif

have_popen = cc.compiles(inc_prefix + check_code)

headers = [
  'fmt/container.h',
  'fmt/format.h',
  'fmt/ostream.h',
  'fmt/printf.h',
  'fmt/string.h',
  'fmt/time.h',
]

src = [
  'fmt/format.cc',
  'fmt/ostream.cc',
  'fmt/printf.cc',
]

if have_popen
  headers += 'fmt/posix.h'
  src += 'fmt/posix.cc'
endif

inc = include_directories('.')

fmt_lib = static_library('fmt',
  sources : headers + src,
)

fmt_dep = declare_dependency(
  link_with : fmt_lib,
  include_directories : inc,
  version : '4.1.0'
)
