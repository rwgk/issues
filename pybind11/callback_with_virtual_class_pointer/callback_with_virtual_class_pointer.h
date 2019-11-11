#ifndef CALLBACK_WITH_VIRTUAL_CLASS_POINTER_H_
#define CALLBACK_WITH_VIRTUAL_CLASS_POINTER_H_

#include <functional>
#include <iostream>
#include <memory>

namespace callback_with_virtual_class_pointer {

class VirtualBase {
 public:
  virtual ~VirtualBase() = default;
  virtual int GetSomething() const = 0;
};

class VirtualDerived : public VirtualBase {
 public:
  virtual int GetSomething() const { return 20; }
};

inline int UseCallback(std::function<int(std::shared_ptr<VirtualBase>)> cb) {
  std::shared_ptr<VirtualBase> vb(
      static_cast<VirtualBase*>(new VirtualDerived));
  std::cout << "BEFORE cb(vb)" << std::endl;
  int res = cb(vb);
  std::cout << "AFTER cb(vb)" << std::endl;
  return res;
}

inline int CppCallback(std::shared_ptr<VirtualBase> vb) {
  return vb->GetSomething() + 5;
}

inline int UseCppCallback() {
  return UseCallback(CppCallback);
}

}  // namespace callback_with_virtual_class_pointer

#endif  // CALLBACK_WITH_VIRTUAL_CLASS_POINTER_H_
