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

    py::module abc = py::module::import("abc");
    py::object abc_meta = abc.attr("ABCMeta");
    py::object abstract = abc.attr("abstractmethod");

    py::module mod{"example"};
#if 0
    py::class_<Base> base(mod, "Base", py::metaclass(abc_meta));
#else
    py::class_<Base> base(mod, "Base", py::metaclass(abc_meta), py::dynamic_attr());
#endif
    base.def("draw", &Base::draw, "Abstract method that subclasses must define");
    base.attr("draw") = abstract(base.attr("draw"));
    base.def("save", &Base::save, "Save into file");

    return 0;
}
