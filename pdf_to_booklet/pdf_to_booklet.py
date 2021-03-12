#!/usr/bin/env python3

import argparse
import os


def main():
  parser = argparse.ArgumentParser(description='Hi! This is pdf_to_booklet v1.0.\
                                                 Transforms pdf file to booklet\n(C) derzhavin3016')
  parser.add_argument('in_f', metavar='INPUT', type=str, help='input file in pdf format. Created pdf will be at the same path')
  parser.add_argument('-q', '--quiet', help='turn on quiet mode (no output)', action='store_true')

  args = parser.parse_args()
    
  build_dir = '.booklet_build'
  
  res = args.in_f.rfind('/') 
  if res != -1:
    build_dir = args.in_f[:res + 1] + build_dir
  os.system(f'mkdir -p {build_dir}')
  
  tex_fname = f'{build_dir}/{args.in_f[res + 1:]}.tex'
  tex_code = '\\documentclass{scrartcl}\n' + \
              '\\usepackage{pdfpages}\n' + \
              '\\begin{document}\n' +  \
              '\\includepdf[pages=-,booklet,turn=false,landscape]' + \
              f'{{../{args.in_f[res + 1:]}}}\n\\end{{document}}\n'


  with open(tex_fname, 'w', encoding='utf-8') as fout:
    fout.write(tex_code) 
  
  re_mv = '> /dev/null' if args.quiet else ' '  
  os.system(f'cd {build_dir}; pdflatex {args.in_f[res + 1:]}.tex {re_mv}; cd ..')

  os.system(f'cd {build_dir}; mv {args.in_f[res + 1:]}.pdf ..;')
  os.system(f'rm -rf {build_dir}')



if __name__ == '__main__':
  main()
