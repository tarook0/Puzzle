project('9-puzzle', 'cpp',
    default_options: ['default_library=static'])

glew_dep = dependency('glew')

if host_machine.system() == 'linux'
    sfml_dep = dependency('sfml-all')
elif host_machine.system() == 'windows'
    glm_dep = dependency('glm')
    cmake = import('cmake')
    compiler = meson.get_compiler('cpp')
    
    if target_machine.cpu_family() == 'x86'
        sfml_dep = dependency('sfml_win32')
    elif target_machine.cpu_family() == 'x86_64'
        sfml_dep = dependency('sfml_win64')
    endif
endif
src_assembler = run_command('srcAssembler.py')
sources = src_assembler.stdout().strip().split('\n')


if host_machine.system() == 'windows'
executable('graphics-project', sources,
    win_subsystem: 'windows',
    override_options: ['cpp_std=c++17'],
    include_directories: ['include'],
    dependencies: [sfml_dep, glew_dep, glm_dep])
elif host_machine.system() == 'linux'
executable('graphics-project', sources,
    override_options: ['cpp_std=c++17'],
    include_directories: ['include'],
    dependencies: [sfml_dep, glew_dep],
    )
endif
