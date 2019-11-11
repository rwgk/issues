"""Example for b/142566039."""

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import sys

# mut = module under test
import callback_with_virtual_class_pointer as mut


def main(args):
  assert len(args) == 1

  res = mut.UseCppCallback()
  print(res)

  def PyCallback(vb):
    print(type(vb))
    res = vb.GetSomething()
    print(res)
    return res + 3
  res = mut.UseCallback(PyCallback)
  print(res)

  print('Done.')


if __name__ == '__main__':
  main(sys.argv)
