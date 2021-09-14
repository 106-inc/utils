import pandas as pd

import plotly.graph_objects as go
from plotly.subplots import make_subplots

lab_name = ""
list_name = 'Лист2'

fst_y_data = 'L'
snd_y_data = 'r_L'

x_data = 'x'

data = pd.read_excel(lab_name, sheet_name=list_name)

err_1 = 3

# Create figure with secondary y-axis
fig = make_subplots(specs=[[{"secondary_y": True}]])

fig.add_trace(go.Scatter(
    x=data[x_data], y=data[snd_y_data],
    name=snd_y_data,
    error_y=dict(
        type='percent',
        value=err_1
    ),
    error_x=dict(
        type='constant',
        value=0.005,
        color='purple'
    ) ,
    marker=dict(color='purple', size=8)
))

fig.add_trace(go.Scatter(
    x=data[x_data], y=data[fst_y_data],
    name=fst_y_data,
    error_y=dict(
        type='percent',
        value=err_1
    ),
    error_x=dict(
        type='constant',
        value=0.005,
        color='red'
    ),
    marker=dict(color='red', size=8)
),secondary_y=True)



# Add figure title
fig.update_layout(
    title_text="Double Y Axis Example"
)

# Set x-axis title
fig.update_xaxes(title_text="x")

# Set y-axes titles
fig.update_yaxes(title_text="r_L, Om", secondary_y=False)
fig.update_yaxes(title_text="L, H", secondary_y=True)

fig.show()