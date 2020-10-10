# Utils
Some helpful utilities.

This repository created by Tako-San, AD6 and Uslsteen. 

Management recommendations:
* One project - one branch.
* If you work on some feature - also create branch.
* Remember, ```master``` only for **RELEASE** versions. 

## csv_to_tex
Converter from table in ```CSV``` format to ```tex``` code.

**Usage**:
* Change script file rights:
  ```bash
  $ sudo chmod +x csv_to_tex.py
  ```
* Run:
  ```bash
  $ ./ctx.sh [OPTIONS] source_file.csv dest_file.tex
  ```
**Availible options**: 
* ```-h```, ```--help``` - show help message and exit.
* ```-d DELIM```, ```--delim DELIM``` - use ```DELIM``` as column delimeter.

## graph_on_py
Directory for graphics builder on Python.

### graph_2_y_axs 
Graph builder with two y-axes on one plane.
