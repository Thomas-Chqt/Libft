Libft
===

Libft is a C library containing common utility functions, data structures, and algorithms used in all my C projects at 42 Tokyo. It is the first project of the common core.

Most of the functions in this library are the same as the standard C library, such as `ft_memcpy` or `ft_strlcpy`, but there are also some original functions like `ft_split`.

To see the code that I pushed to the school repo, please look at the 42-Repo branch.

This branch consists of the original mandatory part of the Libft, plus many functions that I created during my journey at 42 Tokyo. The most important are all the data structure-related functions (starting with `arr_` for array, `lst_` for linked list, `dic_` for hash map, and `btr_` for binary tree), `ft_printf`, and `get_next_line`.

Learning
---

Writing this library was a good way to improve my interface designing skills. In order to be able to use those functions in all my projects, I needed robust and reusable code with an easy-to-use interface. That's why all my data structures and algorithms are designed with void pointers so they can be used with any types, plus some specializations for the common types. Due to the large number of functions in the library, I also had to respect some naming conventions. For example, `arr_qcksort` sorts a type-erased array using the quicksort algorithm, and `lst_qcksort` sorts a type-erased linked list.

Challenges
---

The mandatory part of the Libft was not very challenging since I had already implemented almost all the functions during the piscine, but designing data structures in plain C was a bit difficult, especially with respect to the coding norme of 42.

Build
---

The Libft was not really meant to be used by anyone other than me, so it has never been tested on Windows or Linux. CMake is used to build the library.

```sh
mkdir build
cd build
cmake ..
cmake --build .
```

To link the library to an existing CMake project, just use `add_subdirectory` and `target_link_libraries`.
