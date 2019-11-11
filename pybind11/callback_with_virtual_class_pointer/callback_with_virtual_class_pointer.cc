#include "pybind11/functional.h"
#include "pybind11/pybind11.h"

#include "callback_with_virtual_class_pointer.h"

namespace callback_with_virtual_class_pointer {

class PyVirtualBase : public VirtualBase {
 public:
  using VirtualBase::VirtualBase;

  int GetSomething() const override {
    PYBIND11_OVERLOAD_PURE(
        int,          // Return type.
        VirtualBase,  // Parent class.
        GetSomething  // Name of function in C++ (must match Python name).
    );
  }
};

PYBIND11_MODULE(callback_with_virtual_class_pointer, m) {
  namespace py = pybind11;

  py::class_<VirtualBase, PyVirtualBase>(m, "VirtualBase")
      .def(py::init<>())
      .def("GetSomething", &VirtualBase::GetSomething)
  ;

#ifdef NOT_NEEDED_TO_REPRODUCE_ISSUE
  py::class_<VirtualDerived, VirtualBase>(m, "VirtualDerived")
      .def(py::init<>())
  ;
#endif

  m.def("UseCallback", &UseCallback);
  m.def("UseCppCallback", &UseCppCallback);
}

}  // namespace callback_with_virtual_class_pointer
