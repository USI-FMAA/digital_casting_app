#include <pybind11/pybind11.h>
#include <boost/python.hpp>
namespace py = pybind11;

py::module_ calc = py::module_::import("add");
py::object result = calc.attr("add")(1, 2);
int n = result.cast<int>();
assert(n == 3);