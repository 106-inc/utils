#!/usr/bin/env python3

import argparse
import os

def main():
  parser = argparse.ArgumentParser(description='Hi! This is pdf_to_booklet v1.0.\
                                                 Transforms pdf file to booklet\n(C) derzhavin3016')
  parser.add_argument('in_f', metavar='INPUT', type=str, help='input file in pdf format')
  parser.add_argument('out_f', metavar='OUTPUT', type=str, help='output file in pdf format')  

  args = parser.parse_args()

  os.system('mkdir -p .booklet_build')

  tex_fname = f'build/{args.out_f}.tex'
  tex_code = '\\documentclass{scrartcl}\n' + \
              '\\usepackage{pdfpages}\n' + \
              '\\begin{document}\n' +  \
              '\\includepdf[pages=-,booklet,turn=false,landscape]' + \
              f'{{../{args.in_f}}}\n\\end{{document}}\n'


  with open(tex_fname, 'w', encoding='utf-8') as fout:
    fout.write(tex_code)

  os.system(f'cd .booklet_build; pdflatex {args.out_f}.tex > /dev/null; cd ..')

  os.system(f'mv  .booklet_build/{args.out_f}.pdf .; rm -rf .booklet_build')



if __name__ == '__main__':
  main()
