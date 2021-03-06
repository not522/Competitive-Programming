import argparse
import os
import pyperclip


library_path = os.getenv('LIB_PATH').split(':')[-1]


def comment_out(file_name):
    l = len(file_name) + 4
    res = ''
    res += '/' + '*' * l + '/\n'
    res += '/* {} */\n'.format(file_name)
    res += '/' + '*' * l + '/\n'
    return res


def getHeader(file, headers):
    output = ''
    first = True
    for i, raw_line in enumerate(open(file)):
        line = raw_line.strip()
        if file[-3:] == 'hpp' and not file[-11:] == 'license.hpp' and i == 0:
            assert line == '#pragma once'
            continue
        if line == '' or line[0] != '#' or line[-1] != '"':
            if first:
                if output != '':
                    output += '\n'
                if file[-11:] == 'license.hpp':
                    pass
                elif file[-3:] == 'hpp':
                    output += comment_out(file.split('/include/')[1])
                else:
                    output += comment_out('main.cpp')
                first = False
            output += raw_line
            continue
        header = line.split('"')[1]
        if header not in headers:
            headers.append(header)
            output += getHeader(library_path + header, headers)
    return output


parser = argparse.ArgumentParser(description='include local library')
parser.add_argument('file', help='source file')
parser.add_argument("-p", help="print out for standard output",
                    action="store_true")
args = parser.parse_args()

headers = []
if args.p:
    print(getHeader(args.file, headers), end='')
else:
    pyperclip.copy(getHeader(args.file, headers))
