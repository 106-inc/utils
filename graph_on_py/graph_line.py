from logging import error
import pandas as pd
import plotly.graph_objects as go
import plotly.express as px
import statsmodels.api as sm


lab_name = "lab_5_1_2.xlsx"
list_name = "Лист4"

x_name = "1 - cos(teta)"
y_name = "1/N(\\teta)"

x_err_name = "\sigma_{1 - cos(\\teta)}"
y_err_name = "\sigma_{1/N(\\teta}"


data = pd.read_excel(lab_name, sheet_name=list_name)

x_data = data[x_name]
y_data = data[y_name]

x_err = data[x_err_name]
y_err = data[y_err_name]


fig = px.scatter(x=x_data, y=y_data, error_x=x_err,
                 error_y=y_err, trendline="ols", title='Compton Effect')

fig.update_xaxes(title_text="1 - cos(teta)")
fig.update_yaxes(title_text="1/N(teta)")

fig.show()
