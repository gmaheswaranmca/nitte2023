import pymysql

class FlightManagement:
    def DbConnect(self):
        con = pymysql.connect(host = "localhost",
                            port = 3306,
                            database="ars_app",
                             user="root",
                            password="")
        return con
    def AddFlight(self):
        flight_number = input("Enter flight number:")
        airline_name = input("Enter airline name:")
        source = input("Enter source:")
        destination = input("Enter destination:")
        travel_date = input("Enter travel date (yyyy-mm-dd):")
        seats_capacity = int(input("Enter seats capacity:"))
        ticket_fare = float(input("Enter ticket fare:"))

        con = self.DbConnect()
        cur = con.cursor()
        sql = """INSERT INTO flight(flight_number, airline_name,
            source, destination, travel_date,
            seats_capacity, ticket_fare) VALUES(%s, %s,
            %s, %s, %s,
            %s, %s)
        """
        params = (flight_number, airline_name,
            source, destination, travel_date,
            seats_capacity, ticket_fare)
        cur.execute(sql, params)
        con.commit()
        print("Flight is added successfully.")
    def UpdatePrice(self):
        flight_number = input("Enter flight number:")
        con = self.DbConnect()
        cur = con.cursor()
        sql = """SELECT * FROM flight WHERE flight_number=%s"""
        params = (flight_number,)#tuple
        cur.execute(sql, params)
        flight = cur.fetchone()

        print(f"""Flight Number:{flight[1]}
        Airline Name: {flight[2]}
        Source-Destination: {flight[3]}-{flight[4]}
        Ticket Fare: {flight[7]}
        """)

        new_ticket_fare = float(input("Enter new ticket fare:"))
        sql = "UPDATE flight SET ticket_fare=%s WHERE flight_number=%s"
        params = (new_ticket_fare, flight_number)
        cur.execute(sql, params)
        con.commit()
        print("Price has updated successfully")
        con.close()

    def DeleteByNumber(self):
        flight_number = input("Enter flight number:")
        con = self.DbConnect()
        cur = con.cursor()
        sql = """SELECT * FROM flight WHERE flight_number=%s"""
        params = (flight_number,)
        cur.execute(sql, params)
        flight = cur.fetchone()

        print(f"""Flight Number:{flight[1]}
        Airline Name: {flight[2]}
        Source-Destination: {flight[3]}-{flight[4]}
        Ticket Fare: {flight[7]}
        """)

        confirm = input("Are you sure to delete(y/n)?")
        if(confirm == "y"):
            sql = "DELETE FROM flight WHERE flight_number=%s"
            params = (flight_number,)
            cur.execute(sql, params)
            con.commit()
            print("Flight has deleted successfully")
        con.close()
    def ListAllFlights(self):
        con = self.DbConnect()
        cur = con.cursor()
        sql = """SELECT * FROM flight"""
        params = ()
        cur.execute(sql, params)
        flights = cur.fetchmany()
        print("Flight#(Airline Name)\tSource-Destination\tTravel Date\tSeats\tFare")
        #print(flights)
        for e in flights:
            print(f"""{e[1]}({e[2]})\t{e[3]}-{e[4]}\t{e[5]}\t{e[6]}\t{e[7]}""")
        con.close()

app = FlightManagement()
#app.AddFlight()
#app.UpdatePrice()
#app.DeleteByNumber()
app.ListAllFlights()
        