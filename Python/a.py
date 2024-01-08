import pandas as pd
import numpy as np

"""
# Create a sample DataFrame
data = {'Column1': [1, 2, 3, 4, None],
        'Column2': [5, 6, None, 8, None]}

df = pd.DataFrame(data)

# Check if any values in 'Column1' or 'Column2' are NaN
result = df[['Column1', 'Column2']].isna().all()

print(result)
print('X')

result = df[['Column1', 'Column2']].isna().all(axis=1).sum()
print(result)

tmp = df

#print(df.iloc[4]['Column1'])
#print(df.at[1,'Column1'])

# for i in range(len(tmp)):
#     print(tmp.loc[i,'Column1'])

print(df['Column1'])
"""

# inputSize = 2
# hiddenLayers = 2
# nodesPerLayer = [2,1]
# outputSize = 1
# weights = []
# biases = []
# tmp = inputSize
# for i in range(hiddenLayers):
#     biases.append(np.zeros(1, nodesPerLayer[i]))
#     weights.append(np.random.randn(tmp, nodesPerLayer[i]))
#     tmp = nodesPerLayer[i]

# print(weights)
# print(biases)


def single_layer_forward_propagation(self, prev_a, curr_w, curr_b, func="relu"):
    curr_z = np.dot(curr_w, prev_a) + curr_b
    if func == "relu":
        activation_func = relu
    elif func == "sigmoid":
        activation_func = sigmoid
    else:
        raise Exception('Non-supported activation function')
    return activation_func(curr_z), curr_z