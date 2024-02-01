import pandas as pd
import plotly.express as px
import numpy as np
import plotly.graph_objects as go
import matplotlib.pyplot as plt
import plotly.io as pio

df = pd.read_csv('results.csv')
array = []

for i in range(df.shape[0]):w
  array.append(i+1)

fig = go.Figure()
fig.add_trace(go.Scatter(x=array, y=df['treap_insert'],
                    mode='lines+markers',
                    name='Treap'))
fig.add_trace(go.Scatter(x=array, y=df['avl_insert'],
                    mode='lines+markers',
                    name='AVL'))
fig.add_trace(go.Scatter(x=array, y=df['bst_insert'],
                    mode='lines+markers', name='BST'))

fig.update_layout(
    xaxis_title="Iteração",
    yaxis_title="Tempo (ms)",
    plot_bgcolor='white',
    yaxis=dict(
        gridcolor='lightgray',
        gridwidth=1,
        zerolinecolor='lightgray',
        zerolinewidth=1,
    ),
    xaxis=dict(
        gridcolor='lightgray',
        gridwidth=1,
        zerolinecolor='lightgray',
        zerolinewidth=1,
    ),
    font=dict(
        size=30,
    ),
    legend=dict(
        x=0.1,
        y=0.9,
        bgcolor='rgba(255, 255, 255, 0)',
        bordercolor='rgba(255, 255, 255, 0)',
        orientation='h'
    )
)

fig.show() # Tempo de inserção

fig = go.Figure()
fig.add_trace(go.Scatter(x=array, y=df['treap_search_after_insertion'],
                    mode='lines+markers',
                    name='Treap'))
fig.add_trace(go.Scatter(x=array, y=df['avl_search_after_insertion'],
                    mode='lines+markers',
                    name='AVL'))
fig.add_trace(go.Scatter(x=array, y=df['bst_search_after_insertion'],
                    mode='lines+markers', name='BST'))

fig.update_layout(
    xaxis_title="Iteração",
    yaxis_title="Tempo (ms)",
    plot_bgcolor='white',
    yaxis=dict(
        gridcolor='lightgray',
        gridwidth=1,
        zerolinecolor='lightgray',
        zerolinewidth=1,
    ),
    xaxis=dict(
        gridcolor='lightgray',
        gridwidth=1,
        zerolinecolor='lightgray',
        zerolinewidth=1,
    ),
    font=dict(
        size=30,
    ),
    legend=dict(
        x=0.1,
        y=0.9,
        bgcolor='rgba(255, 255, 255, 0)',
        bordercolor='rgba(255, 255, 255, 0)',
        orientation='h'
    )
)

fig.show() # Tempo de busca após inserção

fig = go.Figure()
fig.add_trace(go.Scatter(x=array, y=df['treap_search_after_removal'],
                    mode='lines+markers',
                    name='Treap'))
fig.add_trace(go.Scatter(x=array, y=df['avl_search_after_removal'],
                    mode='lines+markers',
                    name='AVL'))
fig.add_trace(go.Scatter(x=array, y=df['bst_search_after_removal'],
                    mode='lines+markers', name='BST'))

fig.update_layout(
    xaxis_title="Iteração",
    yaxis_title="Tempo (ms)",
    plot_bgcolor='white',
    yaxis=dict(
        gridcolor='lightgray',
        gridwidth=1,
        zerolinecolor='lightgray',
        zerolinewidth=1,
    ),
    xaxis=dict(
        gridcolor='lightgray',
        gridwidth=1,
        zerolinecolor='lightgray',
        zerolinewidth=1,
    ),
    font=dict(
        size=30,
    ),
    legend=dict(
        x=0.1,
        y=0.9,
        bgcolor='rgba(255, 255, 255, 0)',
        bordercolor='rgba(255, 255, 255, 0)',
        orientation='h'
    )
)


fig.show() # Tempos de busca após remoção

fig = go.Figure()
fig.add_trace(go.Scatter(x=array, y=df['treap_search'],
                    mode='lines+markers',
                    name='Treap'))
fig.add_trace(go.Scatter(x=array, y=df['avl_search'],
                    mode='lines+markers',
                    name='AVL'))
fig.add_trace(go.Scatter(x=array, y=df['bst_search'],
                    mode='lines+markers', name='BST'))

fig.update_layout(
    xaxis_title="Iteração",
    yaxis_title="Tempo (ms)",
    plot_bgcolor='white',
    yaxis=dict(
        gridcolor='lightgray',
        gridwidth=1,
        zerolinecolor='lightgray',
        zerolinewidth=1,
    ),
    xaxis=dict(
        gridcolor='lightgray',
        gridwidth=1,
        zerolinecolor='lightgray',
        zerolinewidth=1,
    ),
    font=dict(
        size=30,
    ),
    legend=dict(
        x=0.1,
        y=0.9,
        bgcolor='rgba(255, 255, 255, 0)',
        bordercolor='rgba(255, 255, 255, 0)',
        orientation='h'
    )
)

fig.show() # Tempo de busca

fig = go.Figure()
fig.add_trace(go.Scatter(x=array, y=df['treap_remove'],
                    mode='lines+markers',
                    name='Treap'))
fig.add_trace(go.Scatter(x=array, y=df['avl_remove'],
                    mode='lines+markers',
                    name='AVL'))
fig.add_trace(go.Scatter(x=array, y=df['bst_remove'],
                    mode='lines+markers', name='BST'))

fig.update_layout(
    xaxis_title="Iteração",
    yaxis_title="Tempo (ms)",
    plot_bgcolor='white',
    yaxis=dict(
        gridcolor='lightgray',
        gridwidth=1,
        zerolinecolor='lightgray',
        zerolinewidth=1,
    ),
    xaxis=dict(
        gridcolor='lightgray',
        gridwidth=1,
        zerolinecolor='lightgray',
        zerolinewidth=1,
    ),
    font=dict(
        size=30,
    ),
    legend=dict(
        x=0.1,
        y=0.9,
        bgcolor='rgba(255, 255, 255, 0)',
        bordercolor='rgba(255, 255, 255, 0)',
        orientation='h'
    )
)

fig.show() # Tempo de remoção

w=0.2
oper = ["Inserção", "Busca Após Inserção", "Busca Após Remoção", "Remoção"]
treap = [df['treap_insert'].sum(), df['treap_search_after_removal'].sum(),df['treap_search'].sum(), df['treap_search_after_insertion'].sum(), df['treap_remove'].sum()]
avl = [df['avl_insert'].sum(), df['avl_search_after_removal'].sum(), df['avl_search'].sum(), df['avl_search_after_insertion'].sum(), df['avl_remove'].sum()]
bst = [df['bst_insert'].sum(), df['bst_search_after_removal'].sum(), df['bst_search'].sum(), df['bst_search_after_insertion'].sum(), df['bst_remove'].sum()]


import plotly.graph_objects as go
animals=["Inserção", "Busca Após Inserção", "Busca Após Remoção", "Remoção"]

fig = go.Figure(data=[
    go.Bar(name='Treap', x=animals, y=[df['treap_insert'].sum(),df['treap_search_after_removal'].sum(), df['treap_search'].sum(), df['treap_search_after_insertion'].sum(),df['treap_remove'].sum()]),
    go.Bar(name='AVL', x=animals, y=[df['avl_insert'].sum(),df['avl_search_after_removal'].sum(),df['avl_search'].sum(),df['avl_search_after_insertion'].sum(),df['avl_remove'].sum()]),
    go.Bar(name='BST', x=animals, y=[df['bst_insert'].sum(),df['bst_search_after_removal'].sum(),df['bst_search'].sum(), df['bst_search_after_insertion'].sum(),df['bst_remove'].sum()])
])
# Change the bar mode
fig.update_layout(
  barmode='group',
  plot_bgcolor='white',
  yaxis=dict(
      type='log',
      title='Tempo (ms) em escala logarítmica',
      gridcolor='lightgray',
      gridwidth=1,
      zerolinecolor='lightgray',
      zerolinewidth=1,
  ),
  xaxis=dict(
      gridcolor='lightgray',
      gridwidth=1,
      zerolinecolor='lightgray',
      zerolinewidth=1,
  ),
  font=dict(
        size=30,
    ),
    legend=dict(
        x=0.1,
        y=1,
        bgcolor='rgba(255, 255, 255, 0)',
        bordercolor='rgba(255, 255, 255, 0)',
        orientation='h'
    )
)
fig.show() # Tempo para cada operação

animals=["Treap", "AVL", "Binary Search Tree"]
fig = go.Figure(data=[
    go.Bar(name='Inserção', x=animals, y=[df['treap_insert'].sum(),df['avl_insert'].sum(),df['bst_insert'].sum()]),
    go.Bar(name='Busca Após Inserç.', x=animals,y=[df['treap_search_after_insertion'].sum(),df['avl_search_after_insertion'].sum(),df['bst_search_after_insertion'].sum()]),
    go.Bar(name='Busca Após Remoç.', x=animals, y=[df['treap_search_after_removal'].sum(),df['avl_search_after_removal'].sum(),df['bst_search_after_removal'].sum()]),
    go.Bar(name='Remoção', x=animals, y=[df['treap_remove'].sum(),df['avl_remove'].sum(),df['bst_remove'].sum()]),
    go.Bar(name='Busca', x=animals, y=[df['treap_search'].sum(),df['avl_search'].sum(),df['bst_search'].sum()]),
])
fig.update_layout(
    barmode='relative',
    font=dict(
        size=30,
    ),
    legend=dict(
        x=0.1,
        y=1.2,
        bgcolor='rgba(255, 255, 255, 0)',
        bordercolor='rgba(255, 255, 255, 0)',
        orientation='h'
    )
)
fig.show() # Tempo total