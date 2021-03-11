#!/usr/bin/env python3

import argparse
import os

def main():
  parser = argparse.ArgumentParser(description='Hi! This is pdf_to_booklet v1.0.\
                                                 Transforms pdf file to booklet\n(C) derzhavin3016')
  parser.add_argument('in_f', metavar='INPUT', type=str, help='input file in pdf format')
  parser.add_argument('out_f', metavar='OUTPUT', type=str, help='output file in pdf format')  

  args = parser.parse_args()

  os.system('mkdir -p build')

  tex_fname = f'build/{args.out_f}.tex'
  tex_code = '\\documentclass{scrartcl}\n' + \
              '\\usepackage{pdfpages}\n' + \
              '\\begin{document}\n' +  \
              '\\includepdf[pages=-,booklet,turn=false,landscape]\n' + \
              f'{{../{args.in_f}}}\n\\end{{doucument}}\n'


  with open(tex_fname, 'w', encoding='utf-8') as fout:
    fout.write(tex_code)

  os.system('cd build')
  if not os.system(f'pdflatex {args.out_f}.tex;'):
    print('pdflatex error')
    return

  os.system('cd ../')
  os.system(f'mv build/{args.out_f} .; rm -rf build')



if __name__ == '__main__':
  main()