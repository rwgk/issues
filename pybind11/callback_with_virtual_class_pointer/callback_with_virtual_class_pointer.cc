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

  py::class_<VirtualBase,
             std::shared_ptr<VirtualBase>,
             PyVirtualBase>(m, "VirtualBase")
      .def(py::init<>())
      .def("GetSomething", &VirtualBase::GetSomething)
  ;

  py::class_<VirtualDerived,
             std::shared_ptr<VirtualDerived>,
             VirtualBase>(m, "VirtualDerived")
      .def(py::init<>())
  ;

  m.def("UseCallback", &UseCallback);
  m.def("UseCppCallback", &UseCppCallback);

  m.def("MakeVirtualDerivedAsBaseUniquePtr",
        &MakeVirtualDerivedAsBaseUniquePtr
        //,py::return_value_policy::take_ownership
        //,py::return_value_policy::copy
        //,py::return_value_policy::move
        //,py::return_value_policy::reference
        //,py::return_value_policy::reference_internal
        //,py::return_value_policy::automatic
        //,py::return_value_policy::automatic_reference
       );
  m.def("MakeVirtualDerivedAsBaseSharedPtr",
        &MakeVirtualDerivedAsBaseSharedPtr);
}

}  // namespace callback_with_virtual_class_pointer
