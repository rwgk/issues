# https://github.com/pybind/pybind11/pull/4216
# https://github.com/pytorch/pytorch/issues/83101

rm -rf main_issue_descr_complx main_issue_descr_complx.o main_issue_descr_simple main_issue_descr_simple.o __pycache__ qvenv

python3 -m venv qvenv
. qvenv/bin/activate
python3 -m pip install torch torchvision
./build.sh
./main_issue_descr_simple
