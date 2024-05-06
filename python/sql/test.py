import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    database="test01",
    user="root",
    password="1234",
    auth_plugin="mysql_native_password",
)


# code to create a table with the name "customers" and the columns "name" and "address":

mycursor = mydb.cursor()

# mycursor.execute("CREATE TABLE customers (name VARCHAR(255), address VARCHAR(255))")

# code to check if a table exists, and if not, create it:

mycursor.execute("SHOW TABLES")

for x in mycursor:
    print(x)
