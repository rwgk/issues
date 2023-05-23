// https://github.com/python/cpython/pull/103912#issuecomment-1559558193

#include <pybind11/embed.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_EMBEDDED_MODULE(mi_debugging, m) {
    struct Base1 {};
    struct Base2 {};
    struct Base12 : Base1, Base2 {};

    py::class_<Base1> b1(m, "Base1");
    py::class_<Base2> b2(m, "Base2");
    py::class_<Base12, Base1, Base2>(m, "Base12");
}

int main() {
    py::initialize_interpreter();

    py::module_::import("mi_debugging");

    py::finalize_interpreter();

    return 0;
}
