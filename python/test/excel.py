import pandas as pd

# Define column names
column_names = ["SLNO", "OrderID", "CustomerID", "Gender", "Age", "OrderDate", "RequiredDate", "ShippedDate", "Online Platform", "Shipped City", "Days to Delivery", "Product Category", "Size", "Qty", "Price/Qty", "Total Price"]

# Read the text file
df = pd.read_csv('excel.txt', sep='\s+', names=column_names)

# Write to an Excel file
df.to_excel('output.xlsx', index=False)
