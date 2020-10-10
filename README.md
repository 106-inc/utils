# Utils
Some helpful utilities.

This repository created by Tako-San, AD6 and Uslsteen. 

Management recommendations:
* One project - one branch.
* If you work on some feature - also create branch.
* Remember, ```master``` only for **RELEASE** versions. 

## csv_to_tex
Converter from table in ```CSV``` format to ```tex``` code.
Usage:
```bash
$ python3 table_rdr.py source_file.csv dest_file.tex
```
Usage by using bash-script ```ctx.sh```
* Change script file rights:
  ```bash
  $ sudo chmod +x ctx.sh
  ```
* Run:
  ```bash
  $ ./ctx.sh source_file.csv dest_file.tex
  ```

## graph_on_py
Directory for graphics builder on Python.

### graph_2_y_axs 
Graph builder with two y-axes on one plane.
