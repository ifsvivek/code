import torch
import torch.nn as nn

# Define the neural network architecture
class Net(nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        self.fc1 = nn.Linear(2, 1)

    def forward(self, x):
        x = torch.sigmoid(self.fc1(x))
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
    if epoch % 1000 == 999:
        print(f"Epoch {epoch+1}, loss: {loss.item():.4f}")

# Test the neural network
with torch.no_grad():
    outputs = net(X)
    predicted = outputs.round()
    print("Predicted:", predicted.flatten())
    print("Actual:   ", y.flatten())

    