import argparse
import csv


def csv_to_tex(filename):

    max_col = 0
    body = ''

    with open(filename, 'r', encoding='utf-8') as fin:
        
        txt_lst = csv.reader(fin)

        for string in txt_lst:

            length = len(string)

            max_col = length if length > max_col else max_col

            for idx, col in enumerate(string, 1):
                body += str(col)
                body += ' & ' if idx != length else ' \\\\'

            body += '\n'

    columns = ' '.join('| 1' for i in range(max_col))
    columns += ' | '

    header = f'\\begin{{tabular}}{{{columns}}}\n'
    footer = '\\end{tabular}'

    return header + body + footer


def main():
    parser = argparse.ArgumentParser(description='Hi')
    parser.add_argument('in_f', metavar='INPUT', type=str, help='input file in csv format')
    parser.add_argument('out_f', metavar='OUTPUT', type=str, help='output file in tex format')

    args = parser.parse_args()

    file_in = args.in_f
    file_out = args.out_f
 
    txt = csv_to_tex(file_in)

    with open(file_out, 'w', encoding='utf-8') as fout:
        fout.write(txt)


if __name__ == '__main__':
    main()
