# Converted from crank.ipynb

# %%
import numpy as np
import pandas as pd
import seaborn as sb
import matplotlib.pyplot as plt

from sklearn.metrics import mean_absolute_error as mae
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, LabelEncoder
from sklearn.linear_model import LinearRegression
from xgboost import XGBRegressor
from sklearn.ensemble import RandomForestRegressor, AdaBoostRegressor

import warnings
warnings.filterwarnings('ignore')



# %%
df = pd.read_csv('tips.csv')
df.head()

# %%

df.shape


# %%
df.info()


# %%
df.describe().T

# %%
df.isnull().sum()


# %%
plt.subplots(figsize=(15,8))

for i, col in enumerate(['total_bill', 'tip']):
  plt.subplot(2,3, i + 1)
  sb.distplot(df[col])
plt.tight_layout()
plt.show()


# %%
plt.subplots(figsize=(15,8))

for i, col in enumerate(['total_bill', 'tip']):
  plt.subplot(2,3, i + 1)
  sb.boxplot(df[col])
plt.tight_layout()
plt.show()


# %%
df.shape, df[(df['total_bill']<45) & (df['tip']<7)].shape


# %%
df = df[(df['total_bill']<45) & (df['tip']<7)]


# %%
feat = df.loc[:, 'sex':'size'].columns

plt.subplots(figsize=(15, 8))
for i, col in enumerate(feat):
    plt.subplot(2, 3, i + 1)
    sb.countplot(data=df, x=col)
plt.tight_layout()
plt.show()

# %%
plt.scatter(df['total_bill'], df['tip'])
plt.title('Total Bill v/s Total Tip')
plt.xlabel('Total Bill')
plt.ylabel('Total Tip')
plt.show()


# %%
df.groupby(['size']).mean()


# %%
df.groupby(['time']).mean()


# %%
df.groupby(['day']).mean()


# %%
le = LabelEncoder()

for col in df.columns:
  if df[col].dtype == object:
	  df[col] = le.fit_transform(df[col])

df.head()


# %%
plt.figure(figsize=(7,7))
sb.heatmap(df.corr() > 0.7, annot = True, cbar = False)
plt.show()


# %%
features = df.drop('tip', axis=1)
target = df['tip']

X_train, X_val, Y_train, Y_val = train_test_split(features, target, test_size=0.2, random_state=22)
X_train.shape, X_val.shape


# %%
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_val = scaler.transform(X_val)


# %%
models = [LinearRegression(), XGBRegressor(), RandomForestRegressor(), AdaBoostRegressor()]

for i in range(4):
  models[i].fit(X_train, Y_train)

  print(f'{models[i]} : ')
  pred_train = models[i].predict(X_train)
  print('Training Accuracy : ', mae(Y_train, pred_train))

  pred_val = models[i].predict(X_val)
  print('Validation Accuracy : ', mae(Y_val, pred_val))
  print()


