import pymysql
from .flight import Flight
class FlightService:
    def DbConnect(self):
        con = pymysql.connect(host = "localhost",
                     port=3306,
                     database="ars_app",
                     user = "root",
                     password="")
        return con
    def AddFlight(self, flight):
        #run insert for flight object
        con = self.DbConnect()
        sql_stmt = """INSERT INTO flight(flight_number, 
            airline_name, source, destination, 
            travel_date, seats_capacity, ticket_fare) VALUES
            (%s,%s,%s,%s,
             %s,%s,%s)
        """
        params = (flight.flight_number, flight.airline_name,
            flight.source, flight.destination, 
            flight.travel_date, flight.seats_capacity,
            flight.ticket_fare)
        cur = con.cursor()
        cur.execute(sql_stmt, params)
        con.commit()
        con.close()
    def UpdatePrice(self, flight):
        #update flight ticket price 
        pass 
    def DeleteById(self, id):
        #delete one flight by id
        pass 
    def FindById(self, id):
        #query by id
        pass 
    def FindAll(self):
        #query all flights
        pass 