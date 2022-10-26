#include <pybind11/embed.h>
#include <pybind11/pybind11.h>

#include <iostream>
#include <thread>

void Do() {
    std::cout << "Do start" << std::endl;
    pybind11::gil_scoped_acquire acquire;
    auto testModule = pybind11::module::import("demo");
    auto testMethod = testModule.attr("test");
    testMethod();
    std::cout << "Do stop" << std::endl;
  }

void run() {
  for (std::size_t index = 0, end = 5; index < end; ++index) Do();
}

int main(int pArgc, const char *const *pArgv) {
  pybind11::initialize_interpreter(false);
  // https://github.com/pybind/pybind11/issues/2197
  pybind11::module::import("threading");

  auto thread = std::thread(&run);

  {
    pybind11::gil_scoped_release release;
    thread.join();
    std::cout << "joined" << std::endl;
  }
}
