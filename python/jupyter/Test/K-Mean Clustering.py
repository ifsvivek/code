# Converted from K-Mean Clustering.ipynb

# MARKDOWN CELL:
# ## Program 2: K - Means Clustering
# K-Means is an unsupervised machine learning algorithm that clusters data together based on similarity metrics like Euclidean Distance.
# K-Means works like this :
# 1. First determines the number of groups/clusters (called as K),
# 2. Then it randomly chooses initial K centroids from data points,
# 3. Next it assigns data points to the cluster of nearest centroid
# 3. Then it updates centroids in each iteration until clusters converge.
# 
# The K in K-Means comes from the number of clusters that need to be set prior to starting the iteration process.
# We can choose the best value of K using The Elbow Method.
# The best value of K is one that results in groups with minimum variance within a single cluster.
# This measure is called Within Cluster Sum of Squares, or WCSS for short. The smaller the WCSS is, the closer our points are, therefore we have a more well-formed cluster.
# 
# ### Data Set: wine_clustering.csv
# These data are the results of a chemical analysis of wines grown in the same region in Italy but derived from three different cultivars. The analysis determined the quantities of 13 constituents found in each of the three types of wines.
# 
# The attributes are:
# 
# - Alcohol
# - Malic acid
# - Ash
# - Alcalinity of ash
# - Magnesium
# - Total phenols
# - Flavanoids
# - Nonflavanoid phenols
# - Proanthocyanins
# - Color intensity
# - Hue
# - OD280/OD315 of diluted wines
# - Proline
# %%
# Import required libraries and read data into a dataframe
import pandas as pd
df = pd.read_csv('wine-clustering.csv')
df.head()

# %%
# Do some data exploration
df.describe().T


# %%
df.info()

# %%
# Visual data exploration to identify correlation among columns of data
import seaborn as sns
import matplotlib.pyplot as plt
sns.pairplot(df)

# %%
#Import algorithms from sklearn
from sklearn.cluster import KMeans

#the columns we will use for clustering are only two - the OD280 and Alcohol content of wines
selected_features = df[['OD280', 'Alcohol']]

# The random_state needs to be the same number to get reproducible results
kmeans_obj = KMeans(n_clusters=3, random_state=42)

# Fit the Kmeans algorithm on selected columns
kmeans_obj.fit(selected_features)
# Predict the cluster labels for data
y_kmeans = kmeans_obj.fit_predict(selected_features)

#Print the predicted labels
print(y_kmeans)

# %%
# Printing the cluster centers
centers = kmeans_obj.cluster_centers_
print(centers)

# %%
#Visualize the Groups created

sns.scatterplot(x = selected_features['OD280'], y = selected_features['Alcohol'], hue=kmeans_obj.labels_)
#Visualize the cluster centroids
plt.scatter(kmeans_obj.cluster_centers_[:, 0], kmeans_obj.cluster_centers_[:, 1], s=200, c='red')

