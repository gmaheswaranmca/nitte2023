import pymysql

con = pymysql.connect(host = "localhost",
                     port = 3306,
                     database="ars_app",
                     user="root",
                     password="")
print("Database is connected")
con.close()