/* ./build.sh

   ./initialize_finalize_loop
   top -p `pgrep initialize_fina` -b      # NO leaking with Python 3.10.7
   # Output in top_no_wrap_class.txt

   ./initialize_finalize_loop wrap_class
   top -p `pgrep initialize_fina` -b      # Leaking even with Pytyhon 3.10.7
   # Output in top_wrap_class.txt
 */

#include <pybind11/embed.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

int main(int argc, char *[]) {
    bool wrap_class = (argc > 1);
    while (true) {
        py::initialize_interpreter();
        {
            auto imom = py::reinterpret_steal<py::object>(PyModule_New("in_memory_only_module"));
            if (!imom) {
                throw py::error_already_set();
            }
            if (wrap_class) {
                struct empty {};
                py::class_<empty>(imom, "empty");
            }
        }
        py::finalize_interpreter();
    }
    return 0;
}
