import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    database='test01',
    user="root",
    password="1234",
    auth_plugin='mysql_native_password'
)

