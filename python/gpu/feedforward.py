import torch
import torch.nn as nn
import torch.optim as optim
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt

# Load the Iris dataset
iris = load_iris()
X = iris.data
y = iris.target

# Split the dataset into train and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Convert the data to PyTorch tensors
X_train = torch.from_numpy(X_train).float()
X_test = torch.from_numpy(X_test).float()
y_train = torch.from_numpy(y_train).long()
y_test = torch.from_numpy(y_test).long()

# Define the neural network model
class Net(nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        self.fc1 = nn.Linear(4, 10)
        self.fc2 = nn.Linear(10, 3)

    def forward(self, x):
        x = torch.relu(self.fc1(x))
        x = self.fc2(x)
        return x

# Create an instance of the model
net = Net()

# Define the loss function and optimizer
criterion = nn.CrossEntropyLoss()
optimizer = optim.Adam(net.parameters(), lr=0.01)

# Train the model
train_losses = []
train_accs = []
test_accs = []
for epoch in range(100):
    # Zero the gradients
    optimizer.zero_grad()

    # Forward pass
    outputs = net(X_train)
    loss = criterion(outputs, y_train)

    # Backward pass and optimization
    loss.backward()
    optimizer.step()

    # Compute training accuracy
    _, predicted = torch.max(outputs.data, 1)
    train_acc = (predicted == y_train).sum().item() / y_train.size(0)

    # Compute test accuracy
    with torch.no_grad():
        outputs = net(X_test)
        _, predicted = torch.max(outputs.data, 1)
        test_acc = (predicted == y_test).sum().item() / y_test.size(0)

    # Save the loss and accuracy values for plotting
    train_losses.append(loss.item())
    train_accs.append(train_acc)
    test_accs.append(test_acc)

    # Print the epoch and loss
    print(f"Epoch {epoch+1:03d}: loss={loss.item():.4f}, train_acc={train_acc:.4f}, test_acc={test_acc:.4f}")

# Plot the training loss and accuracy curves
fig, ax = plt.subplots(1, 2, figsize=(12, 4))
ax[0].plot(train_losses)
ax[0].set_xlabel("Epoch")
ax[0].set_ylabel("Loss")
ax[0].set_title("Training Loss")
ax[1].plot(train_accs, label="Train")
ax[1].plot(test_accs, label="Test")
ax[1].set_xlabel("Epoch")
ax[1].set_ylabel("Accuracy")
ax[1].set_title("Training and Test Accuracy")
ax[1].legend()
plt.show()
