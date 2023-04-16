import torch
import torch.nn as nn
import matplotlib.pyplot as plt
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

# Train the neural network
for epoch in range(10000):
    optimizer.zero_grad()
    outputs = net(X)
    loss = criterion(outputs, y)
    loss.backward()
    optimizer.step()

# Visualize the decision boundary
x_min, x_max = -0.5, 1.5
y_min, y_max = -0.5, 1.5
xx, yy = np.meshgrid(np.linspace(x_min, x_max, 100), np.linspace(y_min, y_max, 100))
Z = net(torch.tensor(np.c_[xx.ravel(), yy.ravel()], dtype=torch.float32)).detach().numpy().reshape(xx.shape)
plt.contourf(xx, yy, Z, cmap=plt.cm.RdBu)
plt.scatter(X[:, 0], X[:, 1], c=y.squeeze(), cmap=plt.cm.RdBu_r, edgecolors='k')
plt.xlabel("X1")
plt.ylabel("X2")
plt.show()
