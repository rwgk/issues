rwgk.c.googlers.com:~/clone/issues/pybind11/pytorch_83101 $ bash README.txt
Collecting torch
  Using cached torch-1.12.1-cp310-cp310-manylinux1_x86_64.whl (776.3 MB)
Collecting torchvision
  Using cached torchvision-0.13.1-cp310-cp310-manylinux1_x86_64.whl (19.1 MB)
Collecting typing-extensions
  Using cached typing_extensions-4.4.0-py3-none-any.whl (26 kB)
Collecting pillow!=8.3.*,>=5.3.0
  Using cached Pillow-9.2.0-cp310-cp310-manylinux_2_28_x86_64.whl (3.2 MB)
Collecting numpy
  Using cached numpy-1.23.4-cp310-cp310-manylinux_2_17_x86_64.manylinux2014_x86_64.whl (17.1 MB)
Collecting requests
  Using cached requests-2.28.1-py3-none-any.whl (62 kB)
Collecting charset-normalizer<3,>=2
  Using cached charset_normalizer-2.1.1-py3-none-any.whl (39 kB)
Collecting idna<4,>=2.5
  Using cached idna-3.4-py3-none-any.whl (61 kB)
Collecting urllib3<1.27,>=1.21.1
  Using cached urllib3-1.26.12-py2.py3-none-any.whl (140 kB)
Collecting certifi>=2017.4.17
  Using cached certifi-2022.9.24-py3-none-any.whl (161 kB)
Installing collected packages: urllib3, typing-extensions, pillow, numpy, idna, charset-normalizer, certifi, torch, requests, torchvision
Successfully installed certifi-2022.9.24 charset-normalizer-2.1.1 idna-3.4 numpy-1.23.4 pillow-9.2.0 requests-2.28.1 torch-1.12.1 torchvision-0.13.1 typing-extensions-4.4.0 urllib3-1.26.12
+ clang++ -o main_issue_descr_complx.o -c -std=c++17 -O0 -g -Wall -Wextra -Wconversion -Wcast-qual -Wdeprecated -Wnon-virtual-dtor -Wunused-result -I/usr/local/google/home/rwgk/forked/pybind11/include -I/usr/include/python3.10 main_issue_descr.cpp
main_issue_descr.cpp:20:14: warning: unused parameter 'pArgc' [-Wunused-parameter]
int main(int pArgc, const char *const *pArgv) {
             ^
main_issue_descr.cpp:20:40: warning: unused parameter 'pArgv' [-Wunused-parameter]
int main(int pArgc, const char *const *pArgv) {
                                       ^
2 warnings generated.
+ clang++ -o main_issue_descr_complx -rdynamic -O0 -g main_issue_descr_complx.o -lpython3.10 -lpthread -ldl -lutil
+ clang++ -o main_issue_descr_simple.o -c -std=c++17 -O0 -g -Wall -Wextra -Wconversion -Wcast-qual -Wdeprecated -Wnon-virtual-dtor -Wunused-result -I/usr/local/google/home/rwgk/forked/pybind11/include -I/usr/include/python3.10 -DPYBIND11_SIMPLE_GIL_MANAGEMENT main_issue_descr.cpp
main_issue_descr.cpp:20:14: warning: unused parameter 'pArgc' [-Wunused-parameter]
int main(int pArgc, const char *const *pArgv) {
             ^
main_issue_descr.cpp:20:40: warning: unused parameter 'pArgv' [-Wunused-parameter]
int main(int pArgc, const char *const *pArgv) {
                                       ^
2 warnings generated.
+ clang++ -o main_issue_descr_simple -rdynamic -O0 -g main_issue_descr_simple.o -lpython3.10 -lpthread -ldl -lutil
Do start
tensor([[53., 58.],
        [73., 70.]])
tensor([[53., 58.],
        [73., 70.]])
tensor([[53., 58.],
        [73., 70.]])
tensor([[53., 58.],
        [73., 70.]])
tensor([[53., 58.],
        [73., 70.]])
Do stop
Do start
^C^Z
[1]+  Stopped                 bash README.txt
rwgk.c.googlers.com:~/clone/issues/pybind11/pytorch_83101 $ kill %1
[1]+  Terminated              bash README.txt
rwgk.c.googlers.com:~/clone/issues/pybind11/pytorch_83101 $ clang++ --version
Debian clang version 14.0.6-2
Target: x86_64-pc-linux-gnu
Thread model: posix
InstalledDir: /usr/bin
rwgk.c.googlers.com:~/clone/issues/pybind11/pytorch_83101 $ python3 --version
Python 3.10.7
