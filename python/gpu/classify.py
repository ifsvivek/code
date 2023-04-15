import torch
import torch.nn as nn
import torch.optim as optim
import matplotlib.pyplot as plt

# Generate random points and labels
num_samples = 1000
features = torch.randn(num_samples, 2)
labels = ((features[:, 0] - features[:, 1]).sign() + 1) / 2

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
optimizer = optim.SGD(net.parameters(), lr=0.1)

# Train the neural network
for epoch in range(50):
    optimizer.zero_grad()
    outputs = net(features)
    loss = criterion(outputs.squeeze(), labels)
    loss.backward()
    optimizer.step()

# Plot the predicted labels for a grid of points
x_min, x_max = features[:, 0].min() - 1, features[:, 0].max() + 1
y_min, y_max = features[:, 1].min() - 1, features[:, 1].max() + 1
xx, yy = torch.meshgrid(torch.linspace(x_min, x_max, 100),
                         torch.linspace(y_min, y_max, 100))
Z = net(torch.cat((xx.reshape(-1, 1), yy.reshape(-1, 1)), dim=1)).detach().reshape(xx.shape)
plt.contourf(xx, yy, Z, cmap=plt.cm.Spectral)
plt.scatter(features[:, 0], features[:, 1], c=labels, cmap=plt.cm.Spectral)
plt.show()
