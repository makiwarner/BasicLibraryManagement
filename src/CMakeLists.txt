add_executable(library_management_system
    Main.cpp
    Library.cpp
    Book.cpp
    Magazine.cpp
    LibraryItem.cpp
)

#because we have this, when we build with CMake, a library_management_system file will be generated in build/bin folder