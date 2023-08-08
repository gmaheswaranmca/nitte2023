import pymysql

con = pymysql.connect(host = "localhost",
                     port = 3306,
                     database="ars_app",
                     user="root",
                     password="")
cur = con.cursor()
sql = """SELECT * FROM flight"""
params = ()
cur.execute(sql, params)
flights = cur.fetchall()
print(flights)
con.close()
