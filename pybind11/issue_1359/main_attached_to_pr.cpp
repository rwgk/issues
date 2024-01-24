#include <pybind11/embed.h>

#include <iostream>

using std::cout;

namespace py = pybind11;

struct Base
{
    void save() {}
    void draw() {}
};

int main()
{
    py::initialize_interpreter();

    py::module_ abc = py::module_::import("abc");
    py::object abc_meta = abc.attr("ABCMeta");
    py::object abstract = abc.attr("abstractmethod");

    py::module_ mod = py::module_::create_extension_module("example", nullptr, new py::module_::module_def);
#if 0
    py::class_<Base> base(mod, "Base", py::metaclass(abc_meta));
#elif 0
    py::class_<Base> base(mod, "Base", py::metaclass(abc_meta), py::dynamic_attr());
#else
    py::class_<Base> base(mod, "Base", py::metaclass((PyObject *) &PyType_Type));
#endif
    base.def("draw", &Base::draw, "Abstract method that subclasses must define");
    base.attr("draw") = abstract(base.attr("draw"));
    base.def("save", &Base::save, "Save into file");

    return 0;
}
