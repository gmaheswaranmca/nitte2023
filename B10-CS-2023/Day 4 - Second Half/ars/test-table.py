import pymysql

con = pymysql.connect(host = "localhost",
                     port = 3306,
                     database="ars_app",
                     user="root",
                     password="")
cur = con.cursor()
sql = """INSERT INTO flight(flight_number, airline_name,
    source, destination, travel_date,
    seats_capacity, ticket_fare) VALUES(%s, %s,
    %s, %s, %s,
    %s, %s)
"""
params = ("AIR101", "Air India",
    "Nitte","Bangalore","2023-08-09",
    175, 8300)
cur.execute(sql, params)
con.commit()
print("Flight is added successfully.")
con.close()
