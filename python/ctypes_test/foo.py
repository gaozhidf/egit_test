from ctypes import cdll
lib = cdll.LoadLibrary('./libfoo.so')


class Foo(object):
    def print_itself(self):
        num = 3
        lib.test_what(num)
        print num
        print "hello python"

        instr = b'uvwxyz'
        outstr = b'abcd'
        lib.mytest(instr,4,outstr)
        print outstr



f = Foo()
f.print_itself()  # and you will see "Hello" on the screen
