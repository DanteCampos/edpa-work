import pandas as pd
import plotly.express as px
import numpy as np
import plotly.graph_objects as go
import matplotlib.pyplot as plt


df = pd.read_csv('results.csv')
array = []

for i in range(df.shape[0]):
  array.append(i+1)

iteracoes_x = array
insert_y0 = df['treap_insert']
insert_y1 = df['avl_insert']
insert_y2 = df['bst_insert']

fig = go.Figure()
fig.add_trace(go.Scatter(x=iteracoes_x, y=insert_y0,
                    mode='lines+markers',
                    name='Treap'))
fig.add_trace(go.Scatter(x=iteracoes_x, y=insert_y1,
                    mode='lines+markers',
                    name='AVL'))
fig.add_trace(go.Scatter(x=iteracoes_x, y=insert_y2,
                    mode='lines+markers', name='Binary Search Tree'))

fig.update_layout(
    title={
        'text': "Tempo de Inserção",
        'y':0.9,
        'x':0.5,
        'xanchor': 'center',
        'yanchor': 'top'},
    xaxis_title="Iteração",
    yaxis_title="Tempo (ms)")

fig.show()

# ~~~~~~~~~~~~~~


iteracoes_x = array
insert_y0 = df['treap_search_after_insertion']
insert_y1 = df['avl_search_after_insertion']
insert_y2 = df['bst_search_after_insertion']

fig = go.Figure()
fig.add_trace(go.Scatter(x=iteracoes_x, y=insert_y0,
                    mode='lines+markers',
                    name='Treap'))
fig.add_trace(go.Scatter(x=iteracoes_x, y=insert_y1,
                    mode='lines+markers',
                    name='AVL'))
fig.add_trace(go.Scatter(x=iteracoes_x, y=insert_y2,
                    mode='lines+markers', name='Binary Search Tree'))

fig.update_layout(
    title={
        'text': "Tempo de Busca Após Inserç.",
        'y':0.9,
        'x':0.5,
        'xanchor': 'center',
        'yanchor': 'top'},
    xaxis_title="Iteração",
    yaxis_title="Tempo (ms)")

fig.show()

# ~~~~~~~~~~~~~~


iteracoes_x = array
insert_y0 = df['treap_search_after_removal']
insert_y1 = df['avl_search_after_removal']
insert_y2 = df['bst_search_after_removal']

fig = go.Figure()
fig.add_trace(go.Scatter(x=iteracoes_x, y=insert_y0,
                    mode='lines+markers',
                    name='Treap'))
fig.add_trace(go.Scatter(x=iteracoes_x, y=insert_y1,
                    mode='lines+markers',
                    name='AVL'))
fig.add_trace(go.Scatter(x=iteracoes_x, y=insert_y2,
                    mode='lines+markers', name='Binary Search Tree'))

fig.update_layout(
    title={
        'text': "Tempo de Busca Após Remoç.",
        'y':0.9,
        'x':0.5,
        'xanchor': 'center',
        'yanchor': 'top'},
    xaxis_title="Iteração",
    yaxis_title="Tempo (ms)")


fig.show()

# ~~~~~~~~~~~~~~


iteracoes_x = array
insert_y0 = df['treap_remove']
insert_y1 = df['avl_remove']
insert_y2 = df['bst_remove']

fig = go.Figure()
fig.add_trace(go.Scatter(x=iteracoes_x, y=insert_y0,
                    mode='lines+markers',
                    name='Treap'))
fig.add_trace(go.Scatter(x=iteracoes_x, y=insert_y1,
                    mode='lines+markers',
                    name='AVL'))
fig.add_trace(go.Scatter(x=iteracoes_x, y=insert_y2,
                    mode='lines+markers', name='Binary Search Tree'))

fig.update_layout(
    title={
        'text': "Tempo de Remoção",
        'y':0.9,
        'x':0.5,
        'xanchor': 'center',
        'yanchor': 'top'},
    xaxis_title="Iteração",
    yaxis_title="Tempo (ms)")

fig.show()

# ~~~~~~~~~~~~~~

def sum_frame_by_column(frame, new_col_name, list_of_cols_to_sum):
    frame[new_col_name] = frame[list_of_cols_to_sum].astype(float).mean(axis=1)
    return(frame)

def std_frame_by_column(frame, new_col_name, list_of_cols_to_sum):
    frame[new_col_name] = frame[list_of_cols_to_sum].astype(float).std(axis=1)
    return(frame)



sum_frame_by_column(df,'mean_treap',['treap_insert','treap_search_after_insertion','treap_search_after_removal', 'treap_remove'])
sum_frame_by_column(df,'mean_avl',['avl_insert','avl_search_after_insertion','avl_search_after_removal', 'avl_remove'])
sum_frame_by_column(df,'mean_bst',['bst_insert','bst_search_after_insertion','bst_search_after_removal', 'bst_remove'])

iteracoes_x = array
insert_y0 = df['mean_treap']
insert_y1 = df['mean_avl']
insert_y2 = df['mean_bst']

fig = go.Figure()
fig.add_trace(go.Scatter(x=iteracoes_x, y=insert_y0,
                    mode='lines+markers',
                    name='Média Treap'))
fig.add_trace(go.Scatter(x=iteracoes_x, y=insert_y1,
                    mode='lines+markers',
                    name='Média AVL'))
fig.add_trace(go.Scatter(x=iteracoes_x, y=insert_y2,
                    mode='lines+markers', name='Média Binary Search Tree'))

fig.update_layout(
    title={
        'text': "Tempo Médio das Operações",
        'y':0.9,
        'x':0.5,
        'xanchor': 'center',
        'yanchor': 'top'},
    xaxis_title="Iteração",
    yaxis_title="Tempo (ms)")

fig.show()

# ~~~~~~~~~~~~~~



std_frame_by_column(df,'mean_treap',['treap_insert','treap_search_after_insertion','treap_search_after_removal', 'treap_remove'])
std_frame_by_column(df,'mean_avl',['avl_insert','avl_search_after_insertion','avl_search_after_removal', 'avl_remove'])
std_frame_by_column(df,'mean_bst',['bst_insert','bst_search_after_insertion','bst_search_after_removal', 'bst_remove'])

iteracoes_x = array
insert_y0 = df['mean_treap']
insert_y1 = df['mean_avl']
insert_y2 = df['mean_bst']

fig = go.Figure()
fig.add_trace(go.Scatter(x=iteracoes_x, y=insert_y0,
                    mode='lines+markers',
                    name='Desv. Padrão Treap'))
fig.add_trace(go.Scatter(x=iteracoes_x, y=insert_y1,
                    mode='lines+markers',
                    name='Desv. Padrão AVL'))
fig.add_trace(go.Scatter(x=iteracoes_x, y=insert_y2,
                    mode='lines+markers', name='Desv. Padrão BST'))

fig.update_layout(
    title={
        'text': "Desvio Padrão dos Tempos de Operaç.",
        'y':0.9,
        'x':0.5,
        'xanchor': 'center',
        'yanchor': 'top'},
    xaxis_title="Iteração",
    yaxis_title="Tempo (ms)")

fig.show()


# ~~~~~~~~~~~~~~

w=0.2
oper = ["Inserção", "Busca Após Inserç.", "Busca Após Remoç.", "Remoção"]
treap = [df['treap_insert'].sum(), df['treap_search_after_removal'].sum(), df['treap_search_after_insertion'].sum(), df['treap_remove'].sum()]
avl = [df['avl_insert'].sum(), df['avl_search_after_removal'].sum(), df['avl_search_after_insertion'].sum(), df['avl_remove'].sum()]
bst = [df['bst_insert'].sum(), df['bst_search_after_removal'].sum(), df['bst_search_after_insertion'].sum(), df['bst_remove'].sum()]


import plotly.graph_objects as go
animals=["Inserção", "Busca Após Inserç.", "Busca Após Remoç.", "Remoção"]

fig = go.Figure(data=[
    go.Bar(name='Treap', x=animals, y=[df['treap_insert'].sum(),df['treap_search_after_removal'].sum(),df['treap_search_after_insertion'].sum(),df['treap_remove'].sum()]),
    go.Bar(name='AVL', x=animals, y=[df['avl_insert'].sum(),df['avl_search_after_removal'].sum(),df['avl_search_after_insertion'].sum(),df['avl_remove'].sum()]),
    go.Bar(name='Binary Search Tree', x=animals, y=[df['bst_insert'].sum(),df['bst_search_after_removal'].sum(),df['bst_search_after_insertion'].sum(),df['bst_remove'].sum()])
])
# Change the bar mode
fig.update_layout(title={
        'text': "Tempo (ms) decorrido em cada operação",
        'y':0.9,
        'x':0.5,
        'xanchor': 'center',
        'yanchor': 'top'},barmode='group')
fig.show()

animals=["Treap", "AVL", "Binary Search Tree"]
fig = go.Figure(data=[
    go.Bar(name='Inserção', x=animals, y=[df['treap_insert'].sum(),df['avl_insert'].sum(),df['bst_insert'].sum()]),
    go.Bar(name='Busca Após Inserç.', x=animals,y=[df['treap_search_after_insertion'].sum(),df['avl_search_after_insertion'].sum(),df['bst_search_after_insertion'].sum()]),
    go.Bar(name='Busca Após Remoç.', x=animals, y=[df['treap_search_after_removal'].sum(),df['avl_search_after_removal'].sum(),df['bst_search_after_removal'].sum()]),
    go.Bar(name='Remoção', x=animals, y=[df['treap_remove'].sum(),df['avl_remove'].sum(),df['bst_remove'].sum()])
])
fig.update_layout(title={
        'text': "Tempo (ms) decorrido em cada operação no geral",
        'y':0.9,
        'x':0.5,
        'xanchor': 'center',
        'yanchor': 'top'},barmode='relative')
fig.show()

