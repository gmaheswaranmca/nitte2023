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


app = FlightManagement()
app.AddFlight()
        