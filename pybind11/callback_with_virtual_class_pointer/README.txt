$ g++ -O0 -g -shared -std=c++11 -fPIC -I/usr/include/python2.7 -I$HOME/clone/pybind11/include callback_with_virtual_class_pointer.cc -o callback_with_virtual_class_pointer.so
$ python callback_with_virtual_class_pointer_main.py
BEFORE cb(vb)
AFTER cb(vb)
25
BEFORE cb(vb)
<class 'callback_with_virtual_class_pointer.VirtualBase'>
20
AFTER cb(vb)
Segmentation fault


$ gdb python
GNU gdb (GDB) 8.3-gg3
(gdb) run callback_with_virtual_class_pointer_main.py
Starting program: /usr/bin/python callback_with_virtual_class_pointer_main.py
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".
BEFORE cb(vb)
AFTER cb(vb)
25
BEFORE cb(vb)
<class 'callback_with_virtual_class_pointer.VirtualBase'>
20
AFTER cb(vb)

Program received signal SIGSEGV, Segmentation fault.
0x00005555558fa010 in ?? ()
(gdb) where
#0  0x00005555558fa010 in ?? ()
#1  0x00007ffff6b4e9e6 in std::_Sp_counted_ptr<callback_with_virtual_class_pointer::VirtualBase*, (__gnu_cxx::_Lock_policy)2>::_M_dispose (this=0x5555559296f0)
    at /usr/include/c++/8/bits/shared_ptr_base.h:377
#2  0x00007ffff6b39bc0 in std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release (this=0x5555559296f0) at /usr/include/c++/8/bits/shared_ptr_base.h:155
#3  0x00007ffff6b355ff in std::__shared_count<(__gnu_cxx::_Lock_policy)2>::~__shared_count (this=0x7fffffffca08, __in_chrg=<optimized out>)
    at /usr/include/c++/8/bits/shared_ptr_base.h:728
#4  0x00007ffff6b31d7a in std::__shared_ptr<callback_with_virtual_class_pointer::VirtualBase, (__gnu_cxx::_Lock_policy)2>::~__shared_ptr (this=0x7fffffffca00, 
    __in_chrg=<optimized out>) at /usr/include/c++/8/bits/shared_ptr_base.h:1167
#5  0x00007ffff6b31d96 in std::shared_ptr<callback_with_virtual_class_pointer::VirtualBase>::~shared_ptr (this=0x7fffffffca00, __in_chrg=<optimized out>)
    at /usr/include/c++/8/bits/shared_ptr.h:103
#6  0x00007ffff6b31ec7 in callback_with_virtual_class_pointer::UseCallback(std::function<int (std::shared_ptr<callback_with_virtual_class_pointer::VirtualBase>)>) (cb=...)
    at callback_with_virtual_class_pointer.h:23
#7  0x00007ffff6b48c71 in pybind11::detail::argument_loader<std::function<int (std::shared_ptr<callback_with_virtual_class_pointer::VirtualBase>)> >::call_impl<int, int (*&)(std::function<int (std::shared_ptr<callback_with_virtual_class_pointer::VirtualBase>)>), 0ul, pybind11::detail::void_type>(int (*&)(std::function<int (std::shared_ptr<callback_with_virtual_class_pointer::VirtualBase>)>), pybind11::detail::index_sequence<0ul>, pybind11::detail::void_type&&) (this=0x7fffffffcb00, 
    f=@0x55555596ac98: 0x7ffff6b31dfc <callback_with_virtual_class_pointer::UseCallback(std::function<int (std::shared_ptr<callback_with_virtual_class_pointer::VirtualBase>)>)>) at /usr/local/google/home/rwgk/clone/pybind11/include/pybind11/cast.h:1960
#8  0x00007ffff6b44923 in pybind11::detail::argument_loader<std::function<int (std::shared_ptr<callback_with_virtual_class_pointer::VirtualBase>)> >::call<int, pybind11::detail::void_type, int (*&)(std::function<int (std::shared_ptr<callback_with_virtual_class_pointer::VirtualBase>)>)>(int (*&)(std::function<int (std::shared_ptr<callback_with_virtual_class_pointer::VirtualBase>)>)) && (this=0x7fffffffcb00, 
    f=@0x55555596ac98: 0x7ffff6b31dfc <callback_with_virtual_class_pointer::UseCallback(std::function<int (std::shared_ptr<callback_with_virtual_class_pointer::VirtualBase>)>)>) at /usr/local/google/home/rwgk/clone/pybind11/include/pybind11/cast.h:1937
#9  0x00007ffff6b3f8bd in pybind11::cpp_function::initialize<int (*&)(std::function<int (std::shared_ptr<callback_with_virtual_class_pointer::VirtualBase>)>), int, std::function<int (std::shared_ptr<callback_with_virtual_class_pointer::VirtualBase>)>, pybind11::name, pybind11::scope, pybind11::sibling>(int (*&)(std::function<int (std::shared_ptr<callback_with_virtual_class_pointer::VirtualBase>)>), int (*)(std::function<int (std::shared_ptr<callback_with_virtual_class_pointer::VirtualBase>)>), pybind11::name const&, pybind11::scope const&, pybind11::sibling const&)::{lambda(pybind11::detail::function_call&)#3}::operator()(pybind11::detail::function_call&) const (this=0x0, call=...)
    at /usr/local/google/home/rwgk/clone/pybind11/include/pybind11/pybind11.h:159
#10 0x00007ffff6b3fa78 in pybind11::cpp_function::initialize<int (*&)(std::function<int (std::shared_ptr<callback_with_virtual_class_pointer::VirtualBase>)>), int, std::function<int (std::shared_ptr<callback_with_virtual_class_pointer::VirtualBase>)>, pybind11::name, pybind11::scope, pybind11::sibling>(int (*&)(std::function<int (std::shared_ptr<callback_with_virtual_class_pointer::VirtualBase>)>), int (*)(std::function<int (std::shared_ptr<callback_with_virtual_class_pointer::VirtualBase>)>), pybind11::name const&, pybind11::scope const&, pybind11::sibling const&)::{lambda(pybind11::detail::function_call&)#3}::_FUN(pybind11::detail::function_call&) ()
    at /usr/local/google/home/rwgk/clone/pybind11/include/pybind11/pybind11.h:137
#11 0x00007ffff6b2f4e3 in pybind11::cpp_function::dispatcher (self=0x7ffff7ea91e0, args_in=0x7ffff7ea6050, kwargs_in=0x0)
    at /usr/local/google/home/rwgk/clone/pybind11/include/pybind11/pybind11.h:624
#12 0x000055555564315a in PyEval_EvalFrameEx ()
#13 0x0000555555640bf6 in PyEval_EvalCodeEx ()
#14 0x0000555555648e16 in PyEval_EvalFrameEx ()
#15 0x0000555555640bf6 in PyEval_EvalCodeEx ()
#16 0x0000555555640586 in PyEval_EvalCode ()
#17 0x000055555567276f in ?? ()
#18 0x000055555566d770 in PyRun_FileExFlags ()
#19 0x000055555566d11a in PyRun_SimpleFileExFlags ()
#20 0x000055555560e938 in Py_Main ()
#21 0x00007ffff6e7652b in __libc_start_main (main=0x55555560e360 <main>, argc=2, argv=0x7fffffffd788, init=<optimized out>, fini=<optimized out>, rtld_fini=<optimized out>, 
    stack_end=0x7fffffffd778) at ../csu/libc-start.c:308
#22 0x000055555560e29a in _start ()
(gdb) quit
A debugging session is active.

        Inferior 1 [process 236895] will be killed.

Quit anyway? (y or n) y
