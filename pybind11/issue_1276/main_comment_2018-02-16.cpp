// COPIED FROM https://github.com/pybind/pybind11/issues/1276#issuecomment-366261431

#include <pybind11/pybind11.h>
#include <pybind11/embed.h>

#include <iostream>
#include <thread>

static void thread()
{
  pybind11::gil_scoped_acquire acquire;
  {
    // Call some Python code
    // ...
    // Python code calls a 3rd party library which does this
    PyGILState_STATE state = PyGILState_Ensure();
    std::cout << "Calling 3rd party library" << std::endl;
    PyGILState_Release(state);
  }
}

static const char thread_code[] =
"import threading\n"
"import testmod\n"
"t = threading.Thread(target=testmod.func)\n"
"t.start()\n"
"t.join()\n";

PYBIND11_EMBEDDED_MODULE(testmod, m)
{
  m.def("func", thread, pybind11::call_guard<pybind11::gil_scoped_release>());
}

int main()
{
  pybind11::scoped_interpreter interp;
  pybind11::gil_scoped_release release;

  {
    pybind11::gil_scoped_acquire acquire;
    pybind11::exec(thread_code);
  }

  return 0;
}
