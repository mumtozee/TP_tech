import sys

code = """#ifndef INDEX_H
#define INDEX_H

bool index_f();

#endif // end INDEX_H
"""
output_file = sys.argv[1]
f = open(output_file, "w+")
f.write(code)
f.close()
