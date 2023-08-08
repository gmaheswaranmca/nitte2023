import pymysql 

con = pymysql.connect(host = "localhost",
                     port=3306,
                     database="ars_app",
                     user = "root",
                     password="")
cur = con.cursor()
sql_stmt = """SELECT * FROM flight
"""  
cur.execute(sql_stmt)  
flights = cur.fetchall()
print(flights)
con.commit()                 
con.close()                    