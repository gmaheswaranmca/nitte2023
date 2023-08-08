import pymysql 

con = pymysql.connect(host = "localhost",
                     port=3306,
                     database="ars_app",
                     user = "root",
                     password="")
cur = con.cursor()
sql_stmt = """INSERT INTO flight(flight_number, airline_name, 
source, destination, travel_date, seats_capacity,
ticket_fare) VALUES('AIR102','Air Inidia','Bangalore','Nitte',
'2023-08-10',175,12500);
"""  
cur.execute(sql_stmt)   
con.commit()
print("Flight is added successfully")                 
con.close()                    