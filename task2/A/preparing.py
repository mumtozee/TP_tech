import sys

code = """#ifndef INDEX_H
#define INDEX_H

template<class T>
bool index_f(T args) {
    return args == 0;
}

#endif // end INDEX_H
"""
output_file = sys.argv[1]
f = open(output_file, "w+")
f.write(code)
f.close()
