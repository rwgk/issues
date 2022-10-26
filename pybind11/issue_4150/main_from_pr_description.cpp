#include <pybind11/embed.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

int main() {
// 	py::scoped_interpreter guard {};
	py::initialize_interpreter();

        {
	    auto mod_py = py::module::import( "ruptures" );
        }

	py::finalize_interpreter();
	return EXIT_SUCCESS;
}
