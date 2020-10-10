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

            body += '\n\\hline\n'

    columns = ' '.join('| c' for i in range(max_col))
    columns += ' | '

    header = f'\\begin{{tabular}}{{{columns}}}\n\\hline\n'
    footer = '\\end{tabular}\n'

    return header + body + footer


def main():
    parser = argparse.ArgumentParser(description='Hi! This is table_rdr v 1.0\n\
                                                  (c) Tako-San && derzhavin3016\n\
                                                  Transform csv table to LaTeX code\n\n')
    parser.add_argument('in_f', metavar='INPUT', type=str, help='input file in csv format')
    parser.add_argument('out_f', metavar='OUTPUT', type=str, help='output file in tex format')

    args = parser.parse_args()
 
    txt = csv_to_tex(args.in_f)

    with open(args.out_f, 'w', encoding='utf-8') as fout:
        fout.write(txt)


if __name__ == '__main__':
    main()
