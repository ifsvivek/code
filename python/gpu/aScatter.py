import torch
import torch.nn as nn
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np

# Define the neural network architecture
class Net(nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        self.fc1 = nn.Linear(2, 10)
        self.fc2 = nn.Linear(10, 1)

    def forward(self, x):
        x = torch.relu(self.fc1(x))
        x = torch.sigmoid(self.fc2(x))
        return x

# Instantiate the neural network and define the loss function and optimizer
net = Net()
criterion = nn.BCELoss()
optimizer = torch.optim.SGD(net.parameters(), lr=0.1)

# Define the training data
X = torch.tensor([[0, 0], [0, 1], [1, 0], [1, 1]], dtype=torch.float32)
y = torch.tensor([[0], [1], [1], [0]], dtype=torch.float32)

# Define a function to update the scatter plot with the latest predictions
def update(i):
    optimizer.zero_grad()
    outputs = net(X)
    loss = criterion(outputs, y)
    loss.backward()
    optimizer.step()

    Z = net(torch.tensor(np.c_[xx.ravel(), yy.ravel()], dtype=torch.float32)).detach().numpy().reshape(xx.shape)
    scatter.set_array(Z.ravel())
    colors = plt.cm.RdBu_r(y.squeeze())
    scatter.set_color(colors)

    return scatter,

# Create a scatter plot with a color gradient based on the predicted class probabilities
x_min, x_max = -0.5, 1.5
y_min, y_max = -0.5, 1.5
xx, yy = np.meshgrid(np.linspace(x_min, x_max, 100), np.linspace(y_min, y_max, 100))
Z = net(torch.tensor(np.c_[xx.ravel(), yy.ravel()], dtype=torch.float32)).detach().numpy().reshape(xx.shape)
fig, ax = plt.subplots()
scatter = ax.scatter(xx, yy, c=Z, cmap=plt.cm.RdBu, edgecolors='k')
colors = plt.cm.RdBu_r(y.squeeze())
scatter = ax.scatter(X[:, 0], X[:, 1], c=colors, cmap=plt.cm.RdBu_r, edgecolors='k', linewidth=1)
ax.set_xlim(xx.min(), xx.max())
ax.set_ylim(yy.min(), yy.max())
ax.set_xlabel("X1")
ax.set_ylabel("X2")
ax.colorbar()

# Animate the scatter plot with updates from training
ani = animation.FuncAnimation(fig, update, frames=10000, interval=100)
plt.show()
